#include "symbolTable.h"
#include "GeneralInfo.h"

static int count = 0;
void print_count2(string s)
{

    printf("[%d] %s\n", count++, s.c_str());
    fflush(stdout);
}

void nullptr_error(string s)
{
    printf("a pointer was null when unexpected; %s\n", s.c_str());
}

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

Symbol::Symbol(string name, TypeNode *tv, Expression *init)
{
    this->name = name;
    type = tv;
}

Symbol::Symbol(string name, TypeNode *tv, bool is_const, bool is_init)
{
    this->name = name;
    tv->copy_to(type);
    this->is_const = is_const;
    this->is_init = is_init;
}

Symbol::Symbol()
{
}

Symbol::Symbol(Symbol *other)
{
    this->name = other->name;
    other->type->copy_to(type);
    this->is_const = other->is_const;
    this->is_init = other->is_init;
}

Symbol::~Symbol()
{
    delete type;
}

void Symbol::printSymbol()
{

    if (type)
        cout << type->to_string();
    // to do
    /*    if (!type)
        {
            notify("typenode is nullptr");
            return;
        }

        if (this->type->type == USER_TYPE)
        {
            auto clas = dynamic_cast<ClassType *>(this->type);
            if (clas)
            {
                printf("%s %s", clas->clas->name.c_str(), name.c_str());
            }
        }
        else if (type->type == types::ARRAY)
        {
            ArrayType *temp = dynamic_cast<ArrayType *>(type);
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
            printf("%s %s\n", getTypeAsStr(type->type).c_str(), name.c_str());
        }*/
}

string Symbol::getSymbolAsString()
{
    return type->to_string() + name;
}

SymbolTable::SymbolTable(string name) : name(name)
{
    visibility = currentVisibility;
}

string SymbolTable::getFullPath()
{
    string fullPath = this->name;

    SymbolTable *temp = parent;
    while (temp != nullptr)
    {
        fullPath += temp->name;
        temp = temp->parent;
    }
    return fullPath;
}

void SymbolTable::printTable(int depth)
{
    indent(depth);
    if (func_details)
        printf("%s\n", func_details->signature.c_str());
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

Symbol *SymbolTable::is_symbol_defined_in_path(string name)
{
    auto it = symbols.find(name);
    if (it != symbols.end())
        return it->second;
    if (func_details)
    {

        auto res = func_details->hasParemeter(name);
        if (res)
            return res;
    }

    if (parent != nullptr)
    {

        auto res = parent->is_symbol_defined_in_path(name);
        return res;
    }

    return nullptr;
}
int SymbolTable::define_symbol(TypeNode *tn, string name, Expression *value)
{
    if (!tn)
    {
        nullptr_error(" type node was nullptr");
        return 0;
    }
    auto it = symbols.find(name);

    if (it != symbols.end()) {
        notify("symbol %s already exists", name.c_str());
        return false;
    }
        

    Symbol *symbol = new Symbol();

    if (value)
    {
        auto res = value->eval();
        if (!res || !Expression::are_types_equal(tn, res->type))
        {
            notify("disonance between type value and initialization value\n");
            return false;
        }

        symbol->type = res->type;
        symbol->value = res;
        symbol->is_init = true;
    }
    else
    {
        symbol->type = tn;
        symbol->is_init = false;
    }

    symbol->is_const = tn->is_const;
    symbol->name = name;
    
    symbols.emplace(symbol->name, symbol);

    return true;
}

SymbolTable *SymbolTable::isClassDefined(string name)
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

SymbolTable *SymbolTable::getParent()
{
    return parent;
}

SymbolTable *SymbolTable::newClass(GeneralInfo *gn)
{
    SymbolTable *newClassSope = new SymbolTable(gn->content);
    newClassSope->type = CLASS_SCOPE;
    newClassSope->parent = this;
    checkInsertion(classes.emplace(newClassSope->name, newClassSope));
    return newClassSope;
}

SymbolTable *SymbolTable::addScope(string name)
{
    SymbolTable *newScope = new SymbolTable(name);
    newScope->parent = this;
    checkInsertion(other.emplace(newScope->name, newScope));

    return newScope;
}

Symbol *SymbolTable::define_user_symbol(GeneralInfo *classId, GeneralInfo *symbolName)
{
    auto cl = isClassDefined(classId->content);
    if (!cl)
    {
        printf("%s isn't a user defined type\n", classId->content.c_str());
        return nullptr;
    }

    if (isLocallyDefined(symbolName->content))
    {
        printf(" symbol (%s) is already defined\n", symbolName->content.c_str());
    }

    Symbol *sym = new Symbol();
    sym->type = new ClassType(cl);
    sym->name = symbolName->content; // to do, is_const;
    sym->is_init = false;



    symbols.emplace(sym->name, sym);
    return sym;
}

Symbol *SymbolTable::define_user_symbol(GeneralInfo *classId, GeneralInfo *symbolName, Vector *init)
{
    Symbol *sym = define_user_symbol(classId, symbolName);

    if (!init)
        return sym;

    if (!sym)
        return nullptr;

    int size = init->pointers.size();

    if (size & 1)
    {
        printf("invalid initialization seuqence, odd size\n");
        return nullptr;
    }

    auto type = dynamic_cast<ClassType *>(sym->type);

    if(sym->value) delete sym->value;

    auto object = new ClassObject(type);
    sym->value = object;
    
    auto fields = &object->fields;

    auto class_fields = type->clas->symbols;

    for (int i = 0; i < size / 2; i++)
    {
        auto id = (GeneralInfo *)(init->pointers[i * 2]);
        auto expr = (Expression *)(init->pointers[i * 2 + 1]);

        auto field = fields->find(id->content);

        if (field == fields->end())
        {
            printf("no %s field\n", id->content.c_str());
            return nullptr;
        }

        // to do

        auto val = expr->eval();
        if (!val)
        {
            printf("val is null\n");
        }
        if (!class_fields[id->content]->type)
        {
            printf("typen is null\n");
        }

        if (!Expression::are_types_equal(val->type, class_fields[id->content]->type))
        {

            printf("uneuqal types\n");
            return nullptr;
        }

        auto f = (*fields).at(id->content);

        f->value = val;
    }

    return sym;
}

Symbol *SymbolTable::is_user_symbol_defined(GeneralInfo *id)
{
    auto sym = is_symbol_defined_in_path(id->content);

    if (!sym)
    {
        printf("%s is not defined \n", id->content.c_str());
        return nullptr;
    }

    if (sym->type == nullptr || sym->type->type != USER_TYPE)
    {
        printf("%s's type is not a class \n", id->content.c_str());
        return nullptr;
    }
    return sym;
}

void SymbolTable::setAsFunction(FunctionDetails *funcNode)
{
    name = funcNode->name;
    this->func_details = funcNode;
    type = FUNC_SCOPE;
}

/*Symbol *SymbolTable::create_temp_symbol(Expression *value)
{
    Symbol *temp_symbol = new Symbol(0, types::OTHER, "", value);

    temp_symbols.insert(temp_symbol);

    return temp_symbol;
}
*/

FunctionDetails *SymbolTable::isFuncDefined(string name)
{
    if (func_details)
    {
        if (func_details->name == name)
            return func_details;
    }
    for (auto &scope : functions)
    {
        if (scope.second->func_details != nullptr && scope.second->func_details->name == name)
        {
            return scope.second->func_details;
        }
    }
    if (parent != nullptr)
    {
        return parent->isFuncDefined(name);
    }

    return nullptr;
}

SymbolTable *SymbolTable::addFunction(FunctionDetails *newFunc)
{
    SymbolTable *newScope = new SymbolTable(newFunc->name);
    newScope->parent = this;
    int debug = 0;
    if (debug)
        printf("trying to insert %s\n", newFunc->name.c_str());
    checkInsertion(functions.emplace(newScope->name, newScope));

    newScope->setAsFunction(newFunc);
    newFunc->setSignature();

    return newScope;
}

SymbolTable *SymbolTable::addFunction(string name)
{
    return nullptr;
}

int SymbolTable::define_symbol(Symbol *symbol)
{
    auto it = symbols.find(symbol->name);

    if (it != symbols.end())
        return false;

    printf("Trying to insert %s\n", symbol->name.c_str());
    checkInsertion(symbols.emplace(symbol->name, symbol));
    return true;
}

int SymbolTable::define_array_symbol(string name, ArrayType *at)
{
    if (isLocallyDefined(name))
        return false;

    Symbol *as = new Symbol(name, at, nullptr);

    printf("Trying to insert %s\n", name.c_str());
    checkInsertion(symbols.emplace(name, as));
    return true;
}

int SymbolTable::define_symbol(string name_, Symbol *symbol)
{
    auto it = symbols.find(name_);

    if (it != symbols.end())
        return false;

    symbol->name = name_;
    printf("Trying to insert %s\n", name_.c_str());
    checkInsertion(symbols.emplace(name_, symbol));
    return true;
}

Symbol *SymbolTable::isLocallyDefined(string name)
{
    auto it = symbols.find(name);

    if (it != symbols.end())
        return it->second;

    return nullptr;
}

Symbol *SymbolTable::check_member_access(GeneralInfo *id, GeneralInfo *member_id)
{
    Symbol *sym = is_user_symbol_defined(id);

    if (!sym)
        return nullptr;

    auto type = dynamic_cast<ClassType *>(sym->type);

    if (!type)
    {
        printf("error at dynamic cast\n");
        return nullptr;
    }
    auto symbols = &type->clas->symbols;
    auto field = symbols->find(member_id->content);

    if (field == symbols->end())
    {
        printf("no %s member\n", member_id->content.c_str());
        return nullptr;
    }

    printf("correct member access\n");
 

    return field->second;
}
