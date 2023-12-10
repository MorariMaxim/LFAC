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

Symbol::Symbol(bool isConst_, types type_, string name_, expressionNode *value_)
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
    printType(this->type);
    printf(" %s\n", this->name.c_str());
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
    for (auto &symbol : symbols)
    {
        indent(depth + 1);
        symbol.second->printSymbol();
    }
    for (auto &child : functions)
    {
        child.second->printTable(depth + 1);
    }
    for (auto &child : other)
    {
        child.second->printTable(depth + 1);
    }
    for (auto &child : classes)
    {
        child.second->printTable(depth + 1);
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

int symbolTalbeNode::defineSymbol(bool isConst_, types type_, string name_, expressionNode *value_)
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
    if (type == CLASS_SCOPE && this->name == name ) return this;

    for(auto clas : classes)  {
        if(clas.second->name == name) return clas.second;
    }

    if(parent) {
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
    children.push_back(newScope);

    return newScope;
}

void symbolTalbeNode::setAsFunction(functionNode *funcNode)
{
    name = funcNode->name;
    this->funcNode = funcNode;
    type = FUNC_SCOPE;
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
    if (debug) printf("trying to insert %s\n",newFunc->name.c_str());
    checkInsertion(functions.emplace(newScope->name, newScope));
    
    newScope->setAsFunction(newFunc);
    newFunc->setSignature();

    return newScope;
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

arraySymbol::arraySymbol() : Symbol()
{
    array_elements = nullptr;
    float_elements = nullptr;
    int_elements = nullptr;
    char_elements = nullptr;
}

arraySymbol::~arraySymbol()
{
    if (bottom)
    {
        switch (type)
        {
        case FLOAT:
            printf("float\n");
            delete float_elements;
            break;
        case INT:
            printf("int\n");
            delete int_elements;
            break;
        case CHAR:
            printf("char\n");
            delete char_elements;
            break;
        case STRING:
            break;
        default:
            printf("OTHER");
            break;
        }
    }
    else
    {
        for (auto ptr : *array_elements)
        {
            delete ptr;
        }
        delete array_elements;
    }
}

void arraySymbol::printSymbol()
{
    printType(this->type);
    printf(" %s[%d]", this->name.c_str(), this->size);
    arraySymbol *temp = this;

    while (temp->bottom != 1)
    {
        temp = (*temp->array_elements)[0];
        printf("[%d]", temp->size);
    }
    printf("\n");
}

arraySymbol *arraySymbol::arrayBuiltFromStack = nullptr;

arraySymbol *arraySymbol::buildFromStack(int it)
{
    arraySymbol *temp;
    if (it == 0)
    {
        printf("array type = ");
        printType(arrayType);
        printf("\ndimensions : ");
        for (auto &el : arrayStack)
        {
            printf("%d,", el);
        }
        printf("\n");

        arrayBuiltFromStack = new arraySymbol();
        temp = arrayBuiltFromStack;
    }
    else
        temp = new arraySymbol();

    // printf("it = %d\n", it);
    int n = arrayStack.size();
    temp->type = arrayType;
    temp->size = arrayStack[it];
    temp->dimension = n - it;
    if (n == (it + 1))
    {
        temp->bottom = 1;
        switch (arrayType)
        {
        case FLOAT:
            // printf("float\n");
            temp->float_elements = new vector<float>(temp->size, 0.0f);
            break;
        case INT:
            // printf("int\n");
            temp->int_elements = new vector<int>{temp->size, 0};
            break;
        case CHAR:
            // printf("char\n");
            temp->char_elements = new vector<char>(temp->size, 'A');
            break;
        case STRING:
            break;
        default:
            break;
        }
    }
    else
    {
        temp->bottom = 0;
        temp->array_elements = new vector<arraySymbol *>;
        for (int i = 0; i < temp->size; i++)
        {
            temp->array_elements->push_back(buildFromStack(it + 1));
        }
    }
    if (it == 0)
    {
        arrayStack.clear();
    }
    return temp;
}
