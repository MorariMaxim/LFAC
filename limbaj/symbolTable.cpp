#include "symbolTable.h"
#include "GeneralInfo.h"

#define symbol_not_declared(s) printf("variable %s not declared\n", s.c_str());

static int debug_count = 0;
void print_count2(string s)
{

    printf("[%d] %s\n", debug_count++, s.c_str());
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

void Symbol::print()
{
    cout << to_string() << endl;
    ;
}

string Symbol::to_string()
{
    string temp = "";

    if (type)
        temp += type->to_string() + " " + name;
    if (value)
        temp += " = " + value->to_string();

    return temp;
}

ValueNode *Symbol::at(ArrayIndexing *indexing)
{
    if (!value)
        return nullptr;

    auto convert = dynamic_cast<ArrayValue *>(value);

    if (!convert)
    {
        printf("symbol %s is not an array", name.c_str());
        return nullptr;
    }

    auto res = convert->at(indexing, 0);

    if (res)
        res->print();
    return res;
}

AssignResult Symbol::assign(ValueNode *val)
{
    if (is_const)
        return AssignResult::ISCONST;

    if (!value)
        value = type->get_associated_value();
    return this->value->assign(val);
}

AssignResult Symbol::assign(ArrayIndexing *indexing, ValueNode *val)
{
    if (is_const)
        return AssignResult::ISCONST;

    if (!value)
        value = type->get_associated_value();

    auto el = value->at(indexing, 0);

    return el->assign(val);
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

        symbol.second->print();
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
    printf("assigning to %s\n", name.c_str());
    if (!tn)
    {
        nullptr_error(" type node was nullptr");
        return 0;
    }
    auto it = symbols.find(name);

    if (it != symbols.end())
    {
        semantic_error("symbol %s already exists", name.c_str());
        return false;
    }

    Symbol *symbol = new Symbol();

    if (value)
    {
        auto res = value->eval();

        if (!res || !Expression::are_types_equal(tn, res->type))
        {
            semantic_error("disonance between type value and initialization value\n");
            return false;
        }
        printf("assigning %s to %s\n", res->to_string().c_str(), name.c_str());
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

    symbol->print();
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

SymbolTable *SymbolTable::add_class(GeneralInfo *gn)
{
    SymbolTable *newClassSope = new SymbolTable(gn->content);
    newClassSope->type = CLASS_SCOPE;
    newClassSope->parent = this;
    auto res = classes.emplace(newClassSope->name, newClassSope);
    if (!res.second)
    {
        semantic_error("class %s already declared ", newClassSope->name.c_str());
        return nullptr;
    }
    return newClassSope;
}

SymbolTable *SymbolTable::addScope(string name)
{
    SymbolTable *newScope = new SymbolTable(name);
    newScope->parent = this;
    if (!insert_symbol(newScope))
        return nullptr;

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
    auto ct = new ClassType(cl);
    sym->type = ct;
    sym->value = new ClassObject(ct);
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

    if (sym->value)
        delete sym->value;

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
        f->type = val->type;
        f->value = val;

        printf("assigned to field %s value %s\n", f->name.c_str(), f->value->to_string().c_str());
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

bool SymbolTable::insert_symbol(Symbol *sym)
{

    auto res = symbols.emplace(sym->name, sym);

    if (!res.second)
    {
        semantic_error("symbol %s already exists", sym->name.c_str());
        return false;
    }
    return true;
}

bool SymbolTable::insert_symbol(SymbolTable *st)
{
    auto res = other.emplace(st->name, st);

    if (!res.second)
    {
        semantic_error("scope %s already exists", st->name.c_str());
        return false;
    }
    return true;
}

ValueNode *SymbolTable::symbol_indexing(GeneralInfo *id, ArrayIndexing *indexing)
{
    auto sym = is_symbol_defined_in_path(id->content);

    if (!sym)
    {
        printf("symbol %s not declared", id->content.c_str());
        return nullptr;
    }

    return sym->at(indexing);
}

bool SymbolTable::assign(GeneralInfo *id, Expression *expr, ArrayIndexing *indexing)
{
    auto sym = is_symbol_defined_in_path(id->content);

    if (!sym)
    {
        symbol_not_declared(id->content);
        return false;
    }

    auto val = expr->eval();

    if (!val)
    {
        printf("couldn't evaluate expression");
        return false;
    }
    AssignResult res;
    if (!indexing)
        res = sym->assign(val);
    else
        res = sym->assign(indexing, val);

    return check_assign_result(res, sym, val);
}

bool SymbolTable::assign(GeneralInfo *id, GeneralInfo *member, Expression *val)
{
    return false;
}

bool SymbolTable::check_assign_result(AssignResult res, Symbol *id, ValueNode *rval)
{
    switch (res)
    {
    case AssignResult::OK:
        return true;
        break;
    case AssignResult::OTHERAR:
        return false;
        break;
    case AssignResult::DIFTYPE:
        semantic_error("couldn't assign %s to %s, different types (%s vs %s)\n", rval->to_string().c_str(), id->name.c_str(), rval->type->to_string().c_str(), id->type->to_string().c_str());
        return false;
        break;
    case AssignResult::ISCONST:
        semantic_error("couldn't assign %s to %s, which is constant \n", rval->to_string().c_str(), id->name.c_str());
        return false;
        break;
    default:
        return false;
        break;
    }
}

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

    functions.emplace(newScope->name, newScope);

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
    if (!insert_symbol(symbol))
        return false;

    return true;
}

Symbol *SymbolTable::define_array_symbol(string name, TypeNode *type, ArrayIndexing *indexing, Expression *init)
{
    auto at = new ArrayType(type, indexing);
    Symbol *sym = new Symbol();
    sym->name = name;
    sym->type = at;
    sym->is_const = type->is_const;
    sym->value = new ArrayValue(at);

    if (init)
    {
        auto val = init->eval();
        if (val)
            sym->value->assign(val);
    }

    insert_symbol(sym);
    return sym;
}

int SymbolTable::define_symbol(string name_, Symbol *symbol)
{
    symbol->name = name_;

    if (!insert_symbol(symbol))
        return false;
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
    auto value = dynamic_cast<ClassObject *>(sym->value);

    if (!value)
    {
        printf("error at dynamic cast\n");
        return nullptr;
    }

    auto fields = &value->fields;
    ;
    auto field = fields->find(member_id->content);

    if (field == fields->end())
    {
        printf("no %s member\n", member_id->content.c_str());
        return nullptr;
    }

    printf("correct member access\n");
    field->second->print();
    return field->second;
}
