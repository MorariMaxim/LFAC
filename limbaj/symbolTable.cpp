#include "symbolTable.h"
#include "generalNode.h"

#define indent(x)                   \
    {                               \
        for (int i = 0; i < x; i++) \
            printf("  ");           \
    }

void printType(types type)
{
    switch (type)
    {
    case FLOAT:
        printf("float");
        break;
    case CHAR:
        printf("CHAR");
        break;
    case STRING:
        printf("STRING");
        break;
    case INT:
        printf("INT");
        break;
    default:
        printf("OTHER");
        break;
    }
}
string getTypeAsStr(types type)
{
    switch (type)
    {
    case FLOAT:
        return "float";
        break;
    case CHAR:
        return "char";
        break;
    case STRING:
        return "string";
        break;
    case INT:
        return "int";
        break;
    case VOID:
        return "void";
        break;
    default:
        return "OTHER";
        break;
    }
}

Symbol::Symbol(bool isConst_, types type_, string name_, ExpressionNode *value_)
{
    isConst = isConst_;
    type = type_;
    name = name_;
    value = value_;
}

void Symbol::setTo(bool isConst_, types type_, string name_, ExpressionNode *value_)
{
    isConst = isConst_;
    type = type_;
    name = name_;
    value = value_;
}

Symbol::Symbol()
{
    isConst = 0;
    type = FLOAT;
    name = "";
    value = nullptr;
}

Symbol::~Symbol()
{
    delete value;
}

void Symbol::printSymbol()
{
    if (this->type == USER_TYPE)
    {
        if (classType)
        {
            printf("%s %s", classType->name.c_str(),name.c_str());
        }
    }
    else if (type == types::ARRAY)
    {
        ArrayType *temp = dynamic_cast<ArrayType *>(typen);
        if (!temp)
        {
            printf("dynamic cast failed\n");
            return;
        }

        printf(" %s[%d]", this->name.c_str(), temp->size);

        while (temp->dimension != 1)
        {
            temp = dynamic_cast<ArrayType *>((*temp->elements)[0]);
            if (!temp)
            {
                printf("dynamic cast failed\n");
                return;
            }

            printf("[%d]", temp->size);
        }
        printf("\n");
    }
    else
    {
        printf("%s %s\n",getTypeAsStr(type).c_str(),name.c_str());
        
    }
}

string Symbol::getSymbolAsString()
{
    char buffer[200] = "";
    snprintf(buffer, 100, "%s %s", getTypeAsStr(this->type).c_str(), this->name.c_str());
    return buffer;
}

symbolTalbeNode::symbolTalbeNode(string name) : name(name)
{
    visibility = currentVisibility;
}

string symbolTalbeNode::getFullPath()
{
    string fullPath = this->name;

    symbolTalbeNode *temp = parent;
    while (temp != nullptr)
    {
        fullPath += temp->name;
        temp = temp->parent;
    }
    return fullPath;
}

void symbolTalbeNode::printTable(int depth)
{
    indent(depth);
    if (funcNode)
        printf("%s\n", funcNode->signature.c_str());
    else
        printf("%s\n", this->name.c_str());
    for (auto &child : classes)
    {
        child.second->printTable(depth + 1);
    }
    for (auto &child : functions)
    {
        child.second->printTable(depth + 1);
    }
    for (auto &child : other)
    {
        child.second->printTable(depth + 1);
    }
    for (auto &symbol : symbols)
    {
        indent(depth + 1);

        symbol.second->printSymbol();
    }
}

Symbol *symbolTalbeNode::isSymbolDefinedInPath(string name)
{
    auto it = symbols.find(name);
    if (it != symbols.end())
        return it->second;
    if (funcNode)
    {

        auto res = funcNode->hasParemeter(name);
        if (res)
            return res;
    }

    if (parent != nullptr)
    {

        auto res = parent->isSymbolDefinedInPath(name);
        return res;
    }
    return nullptr;
}

int symbolTalbeNode::defineSymbol(bool isConst_, types type_, string name_, ExpressionNode *value_)
{
    auto it = symbols.find(name_);

    if (it != symbols.end())
        return false;

    Symbol *symbol = new Symbol(isConst_, type_, name_, value_);
    checkInsertion(symbols.emplace(symbol->name, symbol));
    return true;
}

symbolTalbeNode *symbolTalbeNode::isClassDefined(string name)
{
    if (type == CLASS_SCOPE && this->name == name)
        return this;

    for (auto clas : classes)
    {
        if (clas.second->name == name)
            return clas.second;
    }

    if (parent)
    {
        return parent->isClassDefined(name);
    }

    return nullptr;
}

symbolTalbeNode *symbolTalbeNode::getParent()
{
    return parent;
}

symbolTalbeNode *symbolTalbeNode::newClass(generalNode *gn)
{
    symbolTalbeNode *newClassSope = new symbolTalbeNode(gn->content);
    newClassSope->type = CLASS_SCOPE;
    newClassSope->parent = this;
    checkInsertion(classes.emplace(newClassSope->name, newClassSope));
    return newClassSope;
}

symbolTalbeNode *symbolTalbeNode::addScope(string name)
{
    symbolTalbeNode *newScope = new symbolTalbeNode(name);
    newScope->parent = this;
    checkInsertion(other.emplace(newScope->name, newScope));

    return newScope;
}

Symbol *symbolTalbeNode::define_user_symbol(generalNode *classId, generalNode *symbolName)
{
    Symbol *sym = new Symbol();

    auto cl = isClassDefined(classId->content);
    if (!cl)
    {
        printf("%s isn't a user defined type\n", classId->content.c_str());
        return nullptr;
    }
    sym->type = USER_TYPE;
    sym->classType = cl;
    sym->name = symbolName->content;

    if (isLocallyDefined(sym->name))
    {
        printf(" symbol (%s) is already defined\n", sym->name.c_str());
    }
    symbols.emplace(sym->name, sym);
    return sym;
}

Symbol *symbolTalbeNode::define_user_symbol(generalNode *classId, generalNode *symbolName, myVectorClass *init)
{
    Symbol *sym = define_user_symbol(classId, symbolName);
    if (!sym)
        return nullptr;

    int size = init->pointers.size();

    if (size & 1)
    {
        printf("invalid initialization seuqence, odd size\n");
        return nullptr;
    }

    for (int i = 0; i < size / 2; i++)
    {
        auto id = (generalNode *)(init->pointers[i]);
        auto val = (TypeNode *)(init->pointers[i + 1]);

        auto field =  sym->classType->isLocallyDefined(id->content);

        if(!field) {
            printf("no %s field\n",id->content.c_str());
            return nullptr;
        }

        //to do: check the types

        field->typen = val;
    }

    return sym;
}

Symbol *symbolTalbeNode::is_user_symbol_defined(generalNode *id)
{
    auto sym = isSymbolDefinedInPath(id->content);

    if (!sym)
    {
        printf("%s is not defined \n", id->content.c_str());
        return nullptr;
    }

    if (sym->type != USER_TYPE || sym->classType == nullptr)
    {
        printf("%s's type is not a class \n", id->content.c_str());
        return nullptr;
    }
    return sym;
}

void symbolTalbeNode::setAsFunction(functionNode *funcNode)
{
    name = funcNode->name;
    this->funcNode = funcNode;
    type = FUNC_SCOPE;
}

Symbol *symbolTalbeNode::create_temp_symbol(ExpressionNode *value)
{
    Symbol *temp_symbol = new Symbol(0, types::OTHER, "", value);

    temp_symbols.insert(temp_symbol);

    return temp_symbol;
}

functionNode *symbolTalbeNode::isFuncDefined(string name)
{
    // printf("in %s scope, looking for %s\n",this->name.c_str(),name.c_str());
    if (funcNode)
    {
        if (funcNode->name == name)
            return funcNode;
    }
    for (auto &scope : functions)
    {
        // printf("scope child %s scope\n",scope->name.c_str());
        if (scope.second->funcNode != nullptr && scope.second->funcNode->name == name)
        {
            return scope.second->funcNode;
        }
    }
    if (parent != nullptr)
    {
        return parent->isFuncDefined(name);
    }

    return nullptr;
}

symbolTalbeNode *symbolTalbeNode::addFunction(functionNode *newFunc)
{
    symbolTalbeNode *newScope = new symbolTalbeNode(newFunc->name);
    newScope->parent = this;
    int debug = 0;
    if (debug)
        printf("trying to insert %s\n", newFunc->name.c_str());
    checkInsertion(functions.emplace(newScope->name, newScope));

    newScope->setAsFunction(newFunc);
    newFunc->setSignature();

    return newScope;
}

symbolTalbeNode *symbolTalbeNode::addFunction(string name)
{
    return nullptr;
}

int symbolTalbeNode::defineSymbol(Symbol *symbol)
{
    auto it = symbols.find(symbol->name);

    if (it != symbols.end())
        return false;

    printf("Trying to insert %s\n", symbol->name.c_str());
    checkInsertion(symbols.emplace(symbol->name, symbol));
    return true;
}

int symbolTalbeNode::define_array_symbol(string name, ArrayType *at)
{
    if (isLocallyDefined(name))
        return false;

    Symbol *as = new Symbol(0, types::ARRAY, name, nullptr);
    as->typen = at;

    printf("Trying to insert %s\n", name.c_str());
    checkInsertion(symbols.emplace(name, as));
    return true;
}

int symbolTalbeNode::defineSymbol(string name_, Symbol *symbol)
{
    auto it = symbols.find(name_);

    if (it != symbols.end())
        return false;

    symbol->name = name_;
    printf("Trying to insert %s\n", name_.c_str());
    checkInsertion(symbols.emplace(name_, symbol));
    return true;
}

Symbol *symbolTalbeNode::isLocallyDefined(string name)
{
    auto it = symbols.find(name);

    if (it != symbols.end())
        return it->second;

    return nullptr;
}

int symbolTalbeNode::check_member_access(generalNode *id, generalNode *member_id)
{
    Symbol *sym = is_user_symbol_defined(id);

    if (!sym)
        return -1;

    auto clas = sym->classType;
    /*
    if (clas == nullptr)
    {
        printf("%s class is not defined \n", sym->classType->name.c_str());
        return -1;
    }*/

    if (!clas->isLocallyDefined(member_id->content))
    {
        printf("no %s member\n", member_id->content.c_str());
        return -1;
    }
    printf("correct member access\n");
    return 1;
}
