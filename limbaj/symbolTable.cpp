#include "symbolTable.h"
#include "GeneralInfo.h"

void nullptr_error(string s)
{
    printf("a pointer was null when unexpected; %s\n", s.c_str());
}

#define indent(x)                   \
    {                               \
        for (int i = 0; i < x; i++) \
            printf("  ");           \
    }
string indent_string(int x)
{
    string temp = "";
    for (int i = 0; i < x; i++)
        temp += "  ";
    return temp;
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
string types_2_str(types type)
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

    if (is_const)
        temp += "const ";
    if (type)
        temp += type->to_string() + " ";
    temp += name;
    if (value)
        temp += " = " + value->to_string();
    if (temp == "")
        return "fail";
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

    debug_print("here!\n");
    if (!value)
    {
        debug_print("!value\n");
        value = type->get_associated_value();
    }

    auto res = this->value->assign(val);
    debug_print("got res");
    return res;
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

void Symbol::set_span(Span *other)
{
    span = new Span();
    span->set_span(other);
}

void Symbol::set_span(Span *start, Span *end)
{
    span = new Span();
    span->set_span_start(start);
    span->set_span_end(end);
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

void SymbolTable::printTable()
{
    cout << to_string();
}

string SymbolTable::to_string(int depth)
{
    string table = "";
    table += indent_string(depth);
    if (func_details)
        table += func_details->signature+"\n";
    else if (type == scopeType::CLASS_SCOPE)
        table += "class " + this->name+"\n";
    else
        table += this->name+"\n";

    for (auto &child : classes)
    {
        table += child.second->to_string(depth + 1);
    }
    for (auto &child : functions)
    {
        table += child.second->to_string(depth + 1);
    }
    for (auto &child : other)
    {
        table += child.second->to_string(depth + 1);
    }
    for (auto &symbol : symbols)
    {
        table += indent_string(depth + 1);

        table += symbol.second->to_string()+"\n";
    }
    return table;
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
int SymbolTable::declare_symbol(TypeNode *tn, RawNode *id, Expression *value)
{
    string name = id->content;

    if (!tn)
    {
        nullptr_error(" type node was nullptr");
        return 0;
    }

    Symbol *symbol = new Symbol();
    symbol->type = tn;

    if (value)
    {
        auto res = value->eval();

        if (!res || !Expression::are_types_equal(tn, res->type))
        {
            semantic_error("mismatch between variable type and initialization value type\n");
            return false;
        }
        printf("assigning %s to %s\n", res->to_string().c_str(), name.c_str());
        delete symbol->type;
        symbol->type = res->type;
        symbol->value = res;
        symbol->is_init = true;
    }
    else if (tn->is_const)
    {
        spanned_semantic_error(id, "every constant must be initialized!");
        return false;
    }

    symbol->is_const = tn->is_const;
    symbol->name = name;
    symbol->set_span(id);

    return insert_symbol(symbol);
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

SymbolTable *SymbolTable::add_class(RawNode *gn)
{
    SymbolTable *newClassSope = new SymbolTable(gn->content);
    newClassSope->set_span(gn);
    newClassSope->type = CLASS_SCOPE;
    newClassSope->parent = this;
    auto res = classes.emplace(newClassSope->name, newClassSope);
    if (!res.second)
    {
        if ((*res.first).second->span)
        {
            spanned_semantic_error(gn, "class %s already declared here %s", newClassSope->name.c_str(), (*res.first).second->span->span_to_string().c_str());
        }
        else
        {
            spanned_semantic_error(gn, "class %s already declared", newClassSope->name.c_str());
        }
        return nullptr;
    }
    return newClassSope;
}

SymbolTable *SymbolTable::addScope(string name)
{
    static int for_count = 0;
    static int while_count = 0;
    static int if_count = 0;

    if (name == "for")
        name = name + "()#" + std::to_string(for_count++);
    else if (name == "while")
        name = name + "()#" + std::to_string(while_count++);
    else if (name == "if")
        name = name + "()#" + std::to_string(if_count++);
    else if (name == "else")
        name = name + "()#" + std::to_string(if_count - 1);

    SymbolTable *newScope = new SymbolTable(name);
    newScope->parent = this;
    if (!insert_symbol(newScope))
        return nullptr;

    return newScope;
}

Symbol *SymbolTable::declare_user_symbol(RawNode *classId, RawNode *symbolName)
{
    auto cl = isClassDefined(classId->content);

    debug_print("clas defiend");
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
    sym->name = symbolName->content; // to do, is_const;
    sym->is_init = false;
    sym->set_span(symbolName);
    insert_symbol(sym);

    return sym;
}

Symbol *SymbolTable::declare_user_symbol(RawNode *classId, RawNode *symbolName, Vector *init)
{
    Symbol *sym = declare_user_symbol(classId, symbolName);

    debug_print("declared us\n");
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
    debug_print("here\n");

    auto type = dynamic_cast<ClassType *>(sym->type);

    if (sym->value)
        delete sym->value;

    debug_print("before class object\n");
    auto object = new ClassObject(type);
    debug_print("here\n");
    sym->value = object;

    auto fields = &object->fields;

    auto class_fields = type->clas->symbols;

    for (int i = 0; i < size / 2; i++)
    {
        auto id = (RawNode *)(init->pointers[i * 2]);
        auto expr = (Expression *)(init->pointers[i * 2 + 1]);

        auto field = fields->find(id->content);

        if (field == fields->end())
        {
            spanned_semantic_error(id, "no '%s' field\n", id->content.c_str());
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

Symbol *SymbolTable::is_user_symbol_defined(RawNode *id)
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
        if ((*res.first).second->span)
        {
            spanned_semantic_error(sym->span, "symbol %s already declared here %s", sym->name.c_str(), (*res.first).second->span->span_to_string().c_str());
        }
        else
        {
            spanned_semantic_error(sym->span, "symbol %s already declared", sym->name.c_str());
        }

        return false;
    }

    printf("at %s... inserted %s, name = %s\n", sym->span->span_to_string().c_str(), sym->to_string().c_str(), sym->name.c_str());
    return true;
}

bool SymbolTable::insert_symbol(SymbolTable *st)
{
    auto res = other.emplace(st->name, st);

    if (!res.second)
    {
        if ((*res.first).second->span)
        {
            spanned_semantic_error(st->span, "scope %s already declared at %s", st->name.c_str(), (*res.first).second->span->span_to_string().c_str());
        }
        else
        {
            spanned_semantic_error(st->span, "scope %s already declared ", st->name.c_str());
        }
        return false;
    }
    return true;
}

ValueNode *SymbolTable::symbol_indexing(RawNode *id, ArrayIndexing *indexing)
{
    auto sym = is_symbol_defined_in_path(id->content);

    if (!sym)
    {
        semantic_error("symbol %s not declared", id->content.c_str());
        return nullptr;
    }

    return sym->at(indexing);
}

bool SymbolTable::assign(RawNode *id, Expression *expr, ArrayIndexing *indexing)
{
    auto sym = is_symbol_defined_in_path(id->content);

    if (!sym)
    {
        spanned_semantic_error(id, "symbol %s not declared", id->content.c_str());
        return false;
    }

    return assign(sym, expr, indexing);
}

bool SymbolTable::assign(Symbol *sym, Expression *expr, ArrayIndexing *indexing)
{
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

void SymbolTable::set_span(Span *other)
{
    span = new Span();
    span->set_span(other);
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

    auto res = functions.emplace(newScope->name, newScope);

    if (!res.second && functions[newFunc->name]->func_details->defined)
    {
        if ((*res.first).second->span)
        {
            spanned_semantic_error(newScope->span, "function '%s' already declared at %s", newScope->name.c_str(), (*res.first).second->span->span_to_string().c_str());
        }
        else
        {
            spanned_semantic_error(newScope->span, "function '%s' already declared", newScope->name.c_str());
        }
        return nullptr;
    }

    newScope->setAsFunction(newFunc);
    newFunc->setSignature();

    return newScope;
}

Symbol *SymbolTable::declare_array_symbol(RawNode *id, TypeNode *type, ArrayIndexing *indexing, Expression *init)
{
    string name = id->content;
    auto at = new ArrayType(type, indexing);
    Symbol *sym = new Symbol();
    sym->set_span(id);
    sym->name = name;
    sym->type = at;
    sym->is_const = type->is_const;

    if (init)
    {
        auto val = init->eval();
        if (val)
        {
            if (val->type->is_equal(sym->type))
            {
                sym->value = val;
            }
            else
            {
                semantic_error("cannot initialize %s with %s, dif types (%s vs %s)\n", name.c_str(), val->to_string().c_str(), sym->type->to_string().c_str(), val->type->to_string().c_str());
            }
        }
    }

    insert_symbol(sym);
    return sym;
}

Symbol *SymbolTable::isLocallyDefined(string name)
{
    auto it = symbols.find(name);

    if (it != symbols.end())
        return it->second;

    return nullptr;
}

Symbol *SymbolTable::check_member_access(RawNode *id, RawNode *member_id)
{
    Symbol *sym = is_user_symbol_defined(id);

    if (!sym)
        return nullptr;

    sym->span = new Span();
    sym->span->set_span_start(id);
    sym->span->set_span_end(member_id);
    if (!sym->value)
    {
        spanned_semantic_error(id, "%s is uninitialized", id->content.c_str());
        return nullptr;
    }
    auto value = dynamic_cast<ClassObject *>(sym->value);

    if (!value)
    {
        semantic_error("%s is not an object", id->content.c_str());
        return nullptr;
    }

    auto fields = &value->fields;
    ;
    auto field = fields->find(member_id->content);

    if (field == fields->end())
    {
        spanned_semantic_error(id, "no '%s' member\n", member_id->content.c_str());
        return nullptr;
    }

    printf("correct member access\n");
    field->second->print();
    return field->second;
}
