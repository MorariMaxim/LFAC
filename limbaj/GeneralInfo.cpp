#include "GeneralInfo.h"
#include <stdio.h>
#include <format>
using namespace std;
Span::Span()
{
    start.col = gCol;
    start.row = gRow;
}

void Span::set_span(Span *other)
{
    start = other->start;
    end = other->end;
}

void Span::set_span_start(Span *other)
{
    start = other->start;
}

void Span::set_span_end(Span *other)
{
    end = other->end;
    if (end.row == 0)
        end = other->start;
}

void Span::span_end()
{
    end.col = gCol;
    end.row = gRow;
}

void Span::set_lines(Span *r1, Span *r2)
{
    start.row = r1->start.row;
    start.col = 1;
    end.row = r2->start.row;
    end.col = 1;
}

string Span::span_to_string()
{
    char buffer[100] = "";
    sprintf(buffer, "%u:%u", start.row, start.col);
    if (end.row != 0)
        sprintf(buffer + strlen(buffer), "-%u:%u", end.row, end.col);

    return buffer;
}

void Span::print_span()
{
    cout << span_to_string() << endl;
}

Span::~Span()
{
}
int debug_count = 0;

#define unequal_types_error(t1, t2) semantic_error("different types.. %s vs %s", t1->to_string().c_str(), t2->to_string().c_str())

void symbol_not_declared(string s)
{
    semantic_error("%s is not declared\n", s.c_str());
}

inline types str_2_type(string str)
{

    if (str.compare("float") == 0)
    {
        return types::FLOAT;
    }
    else if (str.compare("string") == 0)
    {
        return types::STRING;
    }
    else if (str.compare("int") == 0)
    {
        return types::INT;
    }
    else if (str.compare("char") == 0)
    {
        return types::CHAR;
    }
    else if (str.compare("void") == 0)
    {
        return types::VOID;
    }
    return types::OTHER;
}

static int debug = 0;
TypeNode::TypeNode(string str)
{
    int debug = 0;
    this->type = str_2_type(str);
    if (debug)
        printf("\nconstructing TypeNode (%s)\n", str.c_str());
}

TypeNode::~TypeNode()
{
    if (debug)
        printf("destructing  TypeNode (%s) \n", content.c_str());
    string s = "1";
}

RawNode::RawNode()
{
    content = "";
}

RawNode::RawNode(string s)
{
    content = s;
}

void RawNode::print()
{
    printf("%s", content.c_str());
}

RawNode::~RawNode()
{
    if (debug)
        printf("destructing  RawNode (%s)\n", content.c_str());
}
string col_2_ansi(Colours col)
{

    switch (col)
    {
    case IDCOL:
        return "51";
    case TYPECOL:
        return "21";
    case CFCOL:
        return "127";
    case VALCOL:
        return "82";
    default:
        return "8";
        break;
    }
}
void print_reduction(string str)
{

    static int debug = 0, delay = 0;
    if (debug)
    {
        printf("\033[38;5;31m\n%s\n\033[0m", str.c_str());
        fflush(stdin);
    }
    if (delay)
        this_thread::sleep_for(std::chrono::milliseconds(100));
}
void print_token(string str, Colours col)
{
    static int debug = 0, delay = 0;
    if (debug)
    {
        printf("\033[38;5;%sm%s\033[0m", col_2_ansi(col).c_str(), str.c_str());
        fflush(stdin);
    }
    if (delay)
        this_thread::sleep_for(std::chrono::milliseconds(100));
}
bool Expression::are_types_equal(TypeNode *t1, TypeNode *t2)
{
    if (!t1 || !t2)
    {
        debug_print("one is null\n");
        return false;
    }
    if (!t1->is_equal(t2))
    {
        unequal_types_error(t1, t2);
        return false;
    }
    return true;
}

string Expression::get_leaf_id()
{
    if (oper == OperTypes::NONOPERATOR)
    {
        if (symbol_type)
        {
            if (sym)
                return sym->name;
        }
        else
            return "temp val";
    }
    return "?";
}

#define check_children_for_nullptr()     \
    {                                    \
        if (!left)                       \
        {                                \
            printf("left child null\n"); \
            return nullptr;              \
        }                                \
        if (!right)                      \
        {                                \
            return nullptr;              \
            printf("left child null\n"); \
        }                                \
    }

ValueNode *Expression::eval_binary_operator()
{
    debug_print("eval binary");
    auto t1 = left->eval();
    auto t2 = right->eval();

    if (!t1 || !t2)
    {
        debug_print("one is null");
        return nullptr;
    }
    if (!t1->type->is_equal(t2->type))
    {
        semantic_error("different types: at (%s) %s vs at (%s) %s", left->span_to_string().c_str(), t1->type->to_string().c_str(), right->span_to_string().c_str(), t2->type->to_string().c_str());

        return nullptr;
    }
    switch (oper)
    {
    case OperTypes::LOR:
    {
        debug_print("|| ");
        auto t1_ = dynamic_cast<BoolValue *>(t1);
        if (!t1_)
        {
            semantic_error("doesn't support LOR: at (%s) ", left->span_to_string().c_str());
            return nullptr;
        }
        t1_->lor(t2);
        break;
    }
    case OperTypes::EQ:
    {
        BoolValue *temp = new BoolValue("false");
        temp->value = t1->eq(t2);
        delete t1;
        delete t2;
        return temp;
    }
    case OperTypes::NEQ:
    {
        BoolValue *temp = new BoolValue("false");
        temp->value = t1->neq(t2);
        delete t1;
        delete t2;
        return temp;
    }
    case OperTypes::LE:
    {
        BoolValue *temp = new BoolValue("false");
        temp->value = t1->le(t2);
        delete t1;
        delete t2;
        return temp;
    }
    case OperTypes::LEQ:
    {
        BoolValue *temp = new BoolValue("false");
        temp->value = t1->leq(t2);
        delete t1;
        delete t2;
        return temp;
    }
    case OperTypes::GE:
    {
        BoolValue *temp = new BoolValue("false");
        temp->value = t1->ge(t2);
        delete t1;
        delete t2;
        return temp;
    }
    case OperTypes::GEQ:
    {
        BoolValue *temp = new BoolValue("false");
        temp->value = t1->geq(t2);
        delete t1;
        delete t2;
        return temp;
    }
    case OperTypes::LAND:
    {
        debug_print("|| ");
        auto t1_ = dynamic_cast<BoolValue *>(t1);
        if (!t1_)
        {
            semantic_error("doesn't support LOR: at (%s) ", left->span_to_string().c_str());
            return nullptr;
        }
        t1_->land(t2);
        break;
    }
    case OperTypes::SUB:
    {
        debug_print("sub ");
        t1->sub(t2);
        break;
    }
    case OperTypes::ADD:
    {
        debug_print("add ");
        t1->add(t2);
        break;
    }
    case OperTypes::MUL:
    {
        debug_print("mul ");
        t1->mul(t2);
        break;
    }
    case OperTypes::DIV:
    {
        debug_print("div ");
        t1->div(t2);
        break;
    }
    case OperTypes::NEG:
    {
        debug_print("neg");
        t1->neg();
        break;
    }
    default:
        return nullptr;
    }

    debug_print("return ");
    return t1;
}
ValueNode *Expression::eval_wrapper(bool mode)
{
    debug_print("going to eval expression");

    auto t = eval();
    debug_print("out");

    if (t)
    {
        if (mode)
            printf("value of (%s) = %s\n", expr_to_string().c_str(), t->to_string().c_str());
        else
            printf("type  of (%s) = %s\n", expr_to_string().c_str(), t->type->to_string().c_str());
    }
    else
    {
        semantic_error("coulnd't evaluate expression");
    }
    return t;
}
ValueNode *Expression::eval_unary_operator()
{
    debug_print("eval unary");
    auto t1 = left->eval();
    if (!t1)
        return nullptr;
    switch (oper)
    {
    case OperTypes::LNOT:
    {
        debug_print("! ");
        auto t1_ = dynamic_cast<BoolValue *>(t1);
        if (!t1_)
        {
            semantic_error("doesn't support LOR: at (%s) ", left->span_to_string().c_str());
            return nullptr;
        }
        t1_->lnot();
        break;
    }
    case OperTypes::NEG:
    {
        t1->neg();
        break;
    }
    default:
        return nullptr;
    }

    return t1;
}
ValueNode *Expression::eval()
{
    debug_print("eval call");

    if (oper == NONOPERATOR)
    {
        auto temp = get_leaf_value();
        if (!temp)
        {
            string error_span = span_to_string();
            if (symbol_type && sym && sym->span)
                error_span = sym->span->span_to_string();
            semantic_error("at (%s) value of %s is unitialized!", error_span.c_str(), get_leaf_id().c_str());
            return nullptr;
        }
        debug_print("leaf node");

        ValueNode *temp2;
        temp->copy_to(temp2);
        return temp2;
    }

    if (oper == OperTypes::SUB || oper == OperTypes::ADD || oper == OperTypes::MUL || oper == OperTypes::DIV || oper == OperTypes::LAND || oper == OperTypes::LOR || oper == OperTypes::EQ || oper == OperTypes::NEQ || oper == OperTypes::LE || oper == OperTypes::LEQ || oper == OperTypes::GE || oper == OperTypes::GEQ)
        return eval_binary_operator();

    if (oper == OperTypes::LNOT || oper == OperTypes::NEG)
        return eval_unary_operator();

    return nullptr;
}

Expression::Expression(OperTypes op, Expression *left, Expression *right)
{
    set_span_start(left);
    if (right)
        set_span_end(right);
    else
        set_span_end(left);

    this->oper = op;
    this->left = left;
    this->right = right;
    vector<int> v;
}

Expression::Expression(ValueNode *vn)
{
    if (!vn)
    {
        debug_print("vn is nullptr");
        return;
    }
    set_span(vn);
    oper = OperTypes::NONOPERATOR;
    symbol_type = false;
    temp = new TempSymbol();
    temp->value = vn;
    temp->type = vn->type;
}
Expression::Expression(Symbol *sym)
{
    if (!sym)
    {
        semantic_error("error during run time, being passed a nullptr symbol");

        return;
    }
    symbol_type = true;
    this->sym = sym;
    oper = OperTypes::NONOPERATOR;
    if (sym->span)
        set_span(sym->span);
}

Expression::Expression(RawNode *id)
{
    sym = currentSymbolTable->is_symbol_defined_in_path(id->content);
    oper = OperTypes::NONOPERATOR;
    symbol_type = true;

    if (!sym)
    {
        semantic_error("%s not declared\n", id->content.c_str());
    }
    set_span(id);
}

Expression::~Expression()
{
    delete right;
    delete left;

    if (!symbol_type && oper == OperTypes::NONOPERATOR)
    {
        if (temp)
        {
            delete temp->type;
            delete temp->value;
        }
    }
}
string OperTypes_2_string(OperTypes type)
{

    switch (type)
    {
    case OperTypes::ADD:
        return "+";
    case OperTypes::SUB:
        return "-";
    case OperTypes::DIV:
        return "/";
    case OperTypes::MUL:
        return "*";
    case OperTypes::EQ:
        return "==";
    case OperTypes::NEQ:
        return "!=";
    case OperTypes::LAND:
        return "&&";
    case OperTypes::LNOT:
        return "!";
    case OperTypes::LE:
        return "<";
    case OperTypes::LEQ:
        return "<=";
    case OperTypes::GE:
        return ">";
    case OperTypes::GEQ:
        return ">=";
    case OperTypes::LOR:
        return "||";
    case OperTypes::NEG:
        return "-";
    default:
        return "";
    }
}

string Expression::expr_to_string()
{
    if (left && right)
    {
        string lstr = left->expr_to_string();
        string rstr = right->expr_to_string();

        if (parenthesized)
            return "( " + lstr + " " + OperTypes_2_string(oper) + " " + rstr + " )";
        return lstr + " " + OperTypes_2_string(oper) + " " + rstr;
    }
    if (left)
    {
        string lstr = left->expr_to_string();

        if (parenthesized)
            return "( " + OperTypes_2_string(oper) + " " + lstr + " )";
        return OperTypes_2_string(oper) + " " + lstr;
    }
    auto leaf = get_leaf_value();
    if (leaf)
        return leaf->to_string();

    return "";
}

TypeNode *Expression::get_leaf_type()
{
    if (oper == OperTypes::NONOPERATOR)
    {
        if (symbol_type)
            return sym->type;
        else
            return temp->type;
    }
    return nullptr;
}
TypeNode *Expression::type()
{
    auto type = get_leaf_type();
    if (type)
        return type;
    else
    {
        if (oper == OperTypes::LNOT || oper == OperTypes::NEG)
        {
            return left->type();
        }
        auto t1 = left->type();

        auto t2 = right->type();

        if (!are_types_equal(t1, t2))
            return nullptr;

        return t1;
    }
}
ValueNode *Expression::get_leaf_value()
{
    if (oper == OperTypes::NONOPERATOR)
    {
        if (symbol_type && sym)
            return sym->value;
        else if (temp)
            return temp->value;
        debug_print("returning nullptr as leaf\n");
        return nullptr;
    }

    return nullptr;
}
FunctionDetails::FunctionDetails(string name, TypeNode *ret_type, Vector *pars) : RawNode("")
{
    debug_print("func name = %s\n", name.c_str());
    parameters = new vector<Symbol *>();
    fflush(stdout);
    if (pars)
    {
        auto ptrs = pars->pointers;
        int size = ptrs.size();
        for (int i = 0; i < size; i++)
        {
            fflush(stdout);
            parameters->push_back((Symbol *)(ptrs[i]));
        }
    }

    return_type = ret_type;

    if (!ret_type)
    {
        return_type = new TypeNode(types::VOID);
    }

    this->name = name;

    debug_print("return ttype is : ");
    debug_print("%s", return_type->to_string().c_str());
}

FunctionDetails::~FunctionDetails()
{
    if (parameters == nullptr)
        return;
    for (auto &par : *parameters)
    {
        delete par;
    }
    delete parameters;
}

Symbol *FunctionDetails::hasParemeter(string name)
{
    if (!parameters)
        return nullptr;
    for (auto &par : *parameters)
    {
        if (par->name == name)
            return par;
    }
    return nullptr;
}

void FunctionDetails::check_return_type()
{
    if (!gReturnExpr)
    {
        if (return_type->type == types::VOID)
            return;
        semantic_error("at line %d.. expected a return value as return type is not void", start.row);
        return;
    }
    auto val = gReturnExpr->eval();
    delete gReturnExpr;
    gReturnExpr = nullptr;
    auto type = val->type;

    if (!Expression::are_types_equal(type, return_type))
    {
        semantic_error("at line %d..mismatchd return types: %s vs %s", gTempSpan.start.row, type->to_string().c_str(), return_type->to_string().c_str());
    }
}

void FunctionDetails::print_parameters()
{
    if (parameters == nullptr)
        return;

    for (auto par : *parameters)
    {
        par->print();
    }
}

void FunctionDetails::setSignature()
{

    string temp = "fn " + name + "(";
    if (parameters && parameters->size())
    {
        for (auto par : *parameters)
        {
            temp += par->to_string() + ", ";
        }
        temp.erase(temp.size() - 2, 2);
    }
    temp += ") -> ";
    temp += types_2_str(this->return_type->type);
    signature = temp;
    // printf("%s\n", signature.c_str());
}

bool FunctionCall::checkCall()
{
    if (function_name == nullptr)
    {
        debug_print("name == nulptr\n");
        return false;
    }

    auto parameters = function_name->parameters;

    if (((parameters == nullptr) && (args->size() != 0)) ||
        ((parameters != nullptr) && (args->size() != parameters->size())))
    {
        semantic_error("not enoough parameters\n");
        return false;
    }

    int size = args->size();
    for (int i = 0; i < size; i++)
    {
        if ((*args)[i] == nullptr)
        {
            semantic_error("%dth. arg is nullptr\n", i + 1);
            return false;
        }
        if (!Expression::are_types_equal((*args)[i]->type, (*parameters)[i]->type))
        {
            semantic_error("args[%d].type (%s) != pars[%d].type (%s)\n", i, types_2_str((*args)[i]->type->type).c_str(), i, types_2_str((*parameters)[i]->type->type).c_str());
            return false;
        }
    }
    return true;
}

FunctionCall::FunctionCall(RawNode *scope_id, Vector *fnname_parameters) : ValueNode()
{
    SymbolTable *scope = currentSymbolTable;

    if (scope_id)
    {
        Symbol *sym = nullptr;
        sym = scope->is_user_symbol_defined(scope_id);

        if (!sym)
        {
            semantic_error("variable %s not decalred\n", scope_id->content.c_str());
            return;
        }
        else
        {
            auto clas = dynamic_cast<ClassType *>(sym->type);
            if (!clas)
            {
                semantic_error("cannot treat %s's type as class type\n", sym->name.c_str());
            }
            scope = clas->clas;
        }
    }

    if (!fnname_parameters)
    {
        semantic_error("for some reason fnname_parameters is null");
        return;
    }

    RawNode *fn_name = (RawNode *)(fnname_parameters->pointers[0]);

    if (!fn_name)
        semantic_error("funcname is nullptr\n");

    auto funcnode = scope->isFuncDefined(fn_name->content);

    if (funcnode == nullptr)
    {
        semantic_error("found no such '%s' function\n", fn_name->content.c_str());
        return;
    }
    else
        debug_print("found such function\n");

    if (funcnode->return_type)
    {
        funcnode->return_type->copy_to(this->type);
    }

    function_name = funcnode;

    args = new vector<ValueNode *>();

    if (fnname_parameters->pointers.size() > 1)
    {
        auto pointers = ((Vector *)fnname_parameters->pointers[1])->pointers;
        auto it = pointers.begin();
        for (; it != pointers.end(); it++)
        {
            auto expr = (Expression *)(*it);
            if (!expr)
                semantic_error("expr is nullptr\n");

            args->push_back(expr->eval());
        }
    }

    value = funcnode->return_type->get_associated_value();
}
void ArrayIndexing::add_index(Expression *rval)
{
    auto res = rval->eval();
    if (res)
    {
        indexes->push_back(res);
    }
    else
    {
        semantic_error("expression resulted in nullptr\n");
    }
}

#define checkSymbol(x)                                                            \
    {                                                                             \
        if (currentSymbolTable->is_symbol_defined_in_path(x->content) == nullptr) \
            printf("\nsymbol not defined %s\n", x->content.c_str());              \
    }
#define getSymbol(x) currentSymbolTable->is_symbol_defined_in_path(x->content)

ArrayIndexing::ArrayIndexing(RawNode *arr)
{
    checkSymbol(arr);
    auto sym = getSymbol(arr);

    if (sym == nullptr)
    {
        array = nullptr;
        return;
    }

    auto convert = dynamic_cast<ArrayType *>(sym->type);
    if (!convert)
    {
        semantic_error("%s is not an ArrayType\n", arr->content.c_str());
        array = nullptr;
    }
    else
        array = sym;

    indexes = new vector<ValueNode *>();
}
ArrayIndexing::ArrayIndexing()
{
    array = nullptr;
}

bool ArrayIndexing::check_indexes()
{

    if (!indexes || !array)
    {
        semantic_error("no indexes or no array\n");
        return true;
    }

    debug_print("indexes : ");
    for (auto v : *indexes)
    {
        v->print();
    }
    debug_print("\n");

    ArrayType *current_dimension = dynamic_cast<ArrayType *>(array->type);

    for (auto &val : *indexes)
    {
        if (!current_dimension)
        {
            semantic_error("error converting to arraytype, probably more indexations than array dimensions");
            return false;
        }

        auto index = dynamic_cast<IntValue *>(val);
        if (!index || index->value < 0)
        {
            semantic_error("index is not usize");
            return false;
        }

        if (current_dimension->size <= index->value)
        {
            semantic_error("index exceeds size of array");
            return false;
        }

        current_dimension = dynamic_cast<ArrayType *>(current_dimension->element_type);
    }
    return true;
}

void Vector::add_element(void *ptr)
{
    pointers.push_back(ptr);
}

ArrayType::ArrayType(TypeNode *et) : TypeNode(types::ARRAY)
{
    element_type = et;
}

ArrayType::ArrayType() : TypeNode(types::ARRAY)
{
}

ArrayType::ArrayType(TypeNode *type, ArrayIndexing *arindex) : TypeNode(types::ARRAY)
{
    if (!arindex || !type || !arindex->indexes || arindex->indexes->size() == 0)
    {
        semantic_error("a paramenter null in ArrayType constructor");
        return;
    }
    int dimensions = arindex->indexes->size();
    auto indexes = arindex->indexes;

    ArrayType *current = this;
    int i = 0;
    for (; i < dimensions; i++)
    {
        auto vn = (*indexes)[i];
        auto iv = dynamic_cast<IntValue *>(vn);
        if (!iv || iv->value < 0)
        {
            semantic_error("index not a usize ");
        }
        auto val = iv->value;

        current->size = val;
        if (i < dimensions - 1)
        {
            auto el = new ArrayType();
            current->element_type = el;
            current = el;
        }
        else
        {
            current->element_type = type;
        }
    }
}

ArrayType::~ArrayType()
{
    delete element_type;
}

ValueNode *ArrayType::get_associated_value()
{
    return new ArrayValue(this);
}

void ArrayType::copy_to(TypeNode *&other)
{
    auto o = (ArrayType *)(other);
    o = new ArrayType();
    element_type->copy_to(o->element_type);
    o->size = size;
    other = o;
};

bool ArrayType::is_equal(TypeNode *other)
{
    auto ar = dynamic_cast<ArrayType *>(other);
    if (!ar)
        return false;

    return (ar->size == this->size) && (element_type->is_equal(ar->element_type));
}

string ArrayType::to_string()
{
    string indexing = "";
    ArrayType *temp = this;

    while (1)
    {

        indexing += "[" + std::to_string(temp->size) + "]";

        auto convert = dynamic_cast<ArrayType *>(temp->element_type);

        if (!convert)
            break;
        else
            temp = convert;
    }

    return temp->element_type->to_string() + indexing;
}

IntType::IntType() : TypeNode(INT)
{
    type = INT;
}

string IntType::to_string()
{
    return "int";
}

ValueNode *IntType::get_associated_value()
{
    return new IntValue("0");
}

void IntType::copy_to(TypeNode *&other)
{
    auto o = (IntType *)(other);
    o = new IntType();
    o->type = this->type;
    other = o;
}
bool IntType::is_equal(TypeNode *other)
{
    return dynamic_cast<IntType *>(other) != nullptr;
};

IntValue::IntValue(string number)
{
    type = new IntType();
    value = atoi(number.c_str());
    debug_print("new int with value = %d\n", value);
}

bool IntValue::add(ValueNode *other)
{
    auto t2 = dynamic_cast<IntValue *>(other);
    this->value += t2->value;
    return true;
}

bool IntValue::mul(ValueNode *other)
{
    auto t2 = dynamic_cast<IntValue *>(other);
    this->value *= t2->value;
    return true;
}

bool IntValue::div(ValueNode *other)
{
    auto t2 = dynamic_cast<IntValue *>(other);
    if (t2->value != 0)
    {
        this->value /= t2->value;
    }

    return true;
}
bool IntValue::sub(ValueNode *other)
{
    auto t2 = dynamic_cast<IntValue *>(other);
    this->value -= t2->value;
    return true;
}
bool IntValue::neg()
{
    value *= -1;
    return false;
}
bool IntValue::lnot()
{
    value *= -1;
    return false;
}
bool IntValue::eq(ValueNode *other)
{
    auto t2 = dynamic_cast<IntValue *>(other);
    return this->value == t2->value;
}
bool IntValue::le(ValueNode *other)
{
    auto t2 = dynamic_cast<IntValue *>(other);
    return this->value < t2->value;
}
void IntValue::copy_to(ValueNode *&other)
{
    auto o = (IntValue *)(other);
    o = new IntValue("0");
    o->value = this->value;
    other = o;
}
ValueNode *IntValue::at(ArrayIndexing *ai, int start_index)
{
    if (!ai)
        return nullptr;
    int indx_size = ai->indexes->size();
    if (indx_size == start_index)
        return this;

    semantic_error("not an array\n");
    return nullptr;
}
AssignResult IntValue::assign(ValueNode *val)
{
    auto convert = dynamic_cast<IntValue *>(val);

    if (!convert)
        return AssignResult::DIFTYPE;

    this->value = convert->value;

    return AssignResult::OK;
}
void IntValue::print()
{
    printf("int(%d)\n", value);
}

string IntValue::to_string()
{
    return std::to_string(value);
}

// FLOAT IMPLEMENTATION

bool FloatValue::eq(ValueNode *other)
{
    auto t2 = dynamic_cast<FloatValue *>(other);
    return this->value == t2->value;
}
bool FloatValue::le(ValueNode *other)
{
    auto t2 = dynamic_cast<FloatValue *>(other);
    return this->value < t2->value;
}

FloatType::FloatType() : TypeNode(FLOAT)
{
    type = FLOAT;
}

string FloatType::to_string()
{
    return "float";
}

ValueNode *FloatType::get_associated_value()
{
    return new FloatValue("0");
}

void FloatType::copy_to(TypeNode *&other)
{
    auto o = (FloatType *)(other);
    o = new FloatType();
    o->type = this->type;
    other = o;
}
bool FloatType::is_equal(TypeNode *other)
{
    return dynamic_cast<FloatType *>(other) != nullptr;
};

FloatValue::FloatValue(string number)
{
    type = new FloatType();
    value = atof(number.c_str());
    debug_print("new float with value = %f\n", value);
}

bool FloatValue::add(ValueNode *other)
{
    auto t2 = dynamic_cast<FloatValue *>(other);
    this->value += t2->value;
    return true;
}

bool FloatValue::mul(ValueNode *other)
{
    auto t2 = dynamic_cast<FloatValue *>(other);
    this->value *= t2->value;
    return true;
}

bool FloatValue::div(ValueNode *other)
{
    auto t2 = dynamic_cast<FloatValue *>(other);
    if (t2->value != 0)
    {
        this->value /= t2->value;
    }

    return true;
}
bool FloatValue::sub(ValueNode *other)
{
    auto t2 = dynamic_cast<FloatValue *>(other);
    this->value -= t2->value;
    return true;
}
bool FloatValue::neg()
{
    value *= -1;
    return false;
}
bool FloatValue::lnot()
{
    value *= -1;
    return false;
}
void FloatValue::copy_to(ValueNode *&other)
{
    auto o = (FloatValue *)(other);
    o = new FloatValue("0");
    o->value = this->value;
    other = o;
}
ValueNode *FloatValue::at(ArrayIndexing *ai, int start_index)
{
    if (!ai)
        return nullptr;
    int indx_size = ai->indexes->size();
    if (indx_size == start_index)
        return this;

    semantic_error("not an array\n");
    return nullptr;
}
AssignResult FloatValue::assign(ValueNode *val)
{
    auto convert = dynamic_cast<FloatValue *>(val);

    if (!convert)
        return AssignResult::DIFTYPE;

    this->value = convert->value;

    return AssignResult::OK;
}
void FloatValue::print()
{
    printf("float(%f)\n", value);
}

string FloatValue::to_string()
{
    return std::to_string(value);
}

// BOOL IMPLEMENTATION

BoolType::BoolType() : TypeNode(BOOL)
{
    type = BOOL;
}

string BoolType::to_string()
{
    return "bool";
}

ValueNode *BoolType::get_associated_value()
{
    return new BoolValue("false");
}

void BoolType::copy_to(TypeNode *&other)
{
    auto o = (BoolType *)(other);
    o = new BoolType();
    o->type = this->type;
    other = o;
}
bool BoolType::is_equal(TypeNode *other)
{
    return dynamic_cast<BoolType *>(other) != nullptr;
};

BoolValue::BoolValue(string number)
{
    type = new BoolType();
    value = (number == "true") ? true : false;

    debug_print("new bool with value = %s\n", value ? "true" : "false");
}

bool BoolValue::add(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    return (this->value + t2->value) > 0;
}

bool BoolValue::mul(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    this->value &= t2->value;
    return true;
}

bool BoolValue::div(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    if (t2->value != 0)
    {
        this->value /= t2->value;
    }
    return true;
}
bool BoolValue::lor(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    this->value = this->value || t2->value;
    return true;
}
bool BoolValue::sub(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    this->value -= t2->value;
    return true;
}
bool BoolValue::land(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    this->value = this->value && t2->value;
    return true;
}
bool BoolValue::neg()
{
    value = !value;
    return true;
}
bool BoolValue::lnot()
{
    value = !value;
    return true;
}
bool BoolValue::eq(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    return this->value == t2->value;
}
bool BoolValue::le(ValueNode *other)
{
    auto t2 = dynamic_cast<BoolValue *>(other);
    return this->value < t2->value;
}
void BoolValue::copy_to(ValueNode *&other)
{
    auto o = (BoolValue *)(other);
    o = new BoolValue("false");
    o->value = this->value;
    other = o;
}
ValueNode *BoolValue::at(ArrayIndexing *ai, int start_index)
{
    if (!ai)
        return nullptr;
    int indx_size = ai->indexes->size();
    if (indx_size == start_index)
        return this;

    semantic_error("not an array\n");
    return nullptr;
}
AssignResult BoolValue::assign(ValueNode *val)
{
    auto convert = dynamic_cast<BoolValue *>(val);

    if (!convert)
        return AssignResult::DIFTYPE;

    this->value = convert->value;

    return AssignResult::OK;
}
void BoolValue::print()
{
    printf("bool(%d)\n", value);
}

string BoolValue::to_string()
{
    return value ? "true" : "false";
}

// STRING IMPLEMENTATION

StringType::StringType() : TypeNode(STRING)
{
    type = STRING;
}

string StringType::to_string()
{
    return "string";
}

ValueNode *StringType::get_associated_value()
{
    return new StringValue("");
}

void StringType::copy_to(TypeNode *&other)
{
    auto o = (StringType *)(other);
    o = new StringType();
    o->type = this->type;
    other = o;
}
bool StringType::is_equal(TypeNode *other)
{
    return dynamic_cast<StringType *>(other) != nullptr;
};

StringValue::StringValue(string number)
{
    type = new StringType();
    int size = number.size();
    if (size >= 2 && number[0] == '"' && number[size - 1] == '"')
        value = number.substr(1, size - 2);
    else
        value = number;

    debug_print("new string with value = %s\n", value.c_str());
}

bool StringValue::add(ValueNode *other)
{
    auto t2 = dynamic_cast<StringValue *>(other);
    this->value += t2->value;
    return true;
}

bool StringValue::mul(ValueNode *other)
{
    return dynamic_cast<StringValue *>(other) != nullptr;
}

bool StringValue::div(ValueNode *other)
{
    /*if (t2->value != 0)
    {
        this->value /= t2->value;
    }*/
    return dynamic_cast<StringValue *>(other) != nullptr;
}
bool StringValue::sub(ValueNode *other)
{
    return dynamic_cast<StringValue *>(other) != nullptr;
}
bool StringValue::neg()
{
    // value = !value;
    return true;
}
bool StringValue::lnot()
{
    // value = !value;
    return true;
}
bool StringValue::eq(ValueNode *other)
{
    auto t2 = dynamic_cast<StringValue *>(other);
    return this->value == t2->value;
}
bool StringValue::le(ValueNode *other)
{
    auto t2 = dynamic_cast<StringValue *>(other);
    return this->value.compare(t2->value) < 0;
}
void StringValue::copy_to(ValueNode *&other)
{
    auto o = (StringValue *)(other);
    o = new StringValue("");
    o->value = this->value;
    other = o;
}
ValueNode *StringValue::at(ArrayIndexing *ai, int start_index)
{
    if (!ai)
        return nullptr;
    int indx_size = ai->indexes->size();
    if (indx_size == start_index)
        return this;

    auto convert = dynamic_cast<IntValue *>(ai->indexes->at(start_index));

    if (!convert || convert->value < 0 || indx_size != (start_index + 1) || convert->value >= (int)value.size())
    {
        semantic_error("index out of bounds");
        return nullptr;
    }

    return new CharValue(value[convert->value]);
}
AssignResult StringValue::assign(ValueNode *val)
{
    auto convert = dynamic_cast<StringValue *>(val);

    if (!convert)
        return AssignResult::DIFTYPE;

    debug_print("here!!");
    int size = convert->value.size();
    string number = convert->value;
    if (size >= 2 && number[0] == '"' && number[size - 1] == '"')
        value = number.substr(1, size - 2);
    else
        value = number;

    return AssignResult::OK;
}
void StringValue::print()
{
    printf("string(%s)\n", value.c_str());
}

string StringValue::to_string()
{
    return value;
}

// CHAR IMPLEMENTATION

CharType::CharType() : TypeNode(CHAR)
{
    type = CHAR;
}

string CharType::to_string()
{
    return "char";
}

ValueNode *CharType::get_associated_value()
{
    return new CharValue(" ");
}

void CharType::copy_to(TypeNode *&other)
{
    auto o = (CharType *)(other);
    o = new CharType();
    o->type = this->type;
    other = o;
}
bool CharType::is_equal(TypeNode *other)
{
    return dynamic_cast<CharType *>(other) != nullptr;
};

CharValue::CharValue(string number)
{
    type = new CharType();
    if (number.size() > 0)
        value = number[0];
    else
        value = ' ';

    debug_print("new char with value = %c\n", value);
}
CharValue::CharValue(char character)
{
    type = new CharType();
    value = character;
    debug_print("new char with value = %c\n", value);
}
bool CharValue::add(ValueNode *other)
{
    auto t2 = dynamic_cast<CharValue *>(other);
    this->value += t2->value;
    return true;
}

bool CharValue::mul(ValueNode *other)
{
    auto t2 = dynamic_cast<CharValue *>(other);
    this->value *= t2->value;
    return true;
}

bool CharValue::div(ValueNode *other)
{
    auto t2 = dynamic_cast<CharValue *>(other);
    if (t2->value != 0)
    {
        this->value /= t2->value;
    }
    return true;
}
bool CharValue::sub(ValueNode *other)
{
    auto t2 = dynamic_cast<CharValue *>(other);
    this->value -= t2->value;
    return true;
}
bool CharValue::neg()
{
    value *= -1;
    return true;
}
bool CharValue::lnot()
{
    value *= -1;
    return true;
}
bool CharValue::eq(ValueNode *other)
{
    auto t2 = dynamic_cast<CharValue *>(other);
    return this->value == t2->value;
}
bool CharValue::le(ValueNode *other)
{
    auto t2 = dynamic_cast<CharValue *>(other);
    return this->value < t2->value;
}
void CharValue::copy_to(ValueNode *&other)
{
    auto o = (CharValue *)(other);
    o = new CharValue("");
    o->value = this->value;
    other = o;
}
ValueNode *CharValue::at(ArrayIndexing *ai, int start_index)
{
    if (!ai)
        return nullptr;
    int indx_size = ai->indexes->size();
    if (indx_size == start_index)
        return this;

    semantic_error("not an array\n");
    return nullptr;
}
AssignResult CharValue::assign(ValueNode *val)
{
    auto convert = dynamic_cast<CharValue *>(val);

    if (!convert)
        return AssignResult::DIFTYPE;

    this->value = convert->value;

    return AssignResult::OK;
}
void CharValue::print()
{
    printf("char(%c)\n", value);
}

string CharValue::to_string()
{
    string s = "";
    s += value;
    return s;
}

ClassObject::ClassObject(ClassType *ct)
{
    type = ct;

    if (!ct || !ct->clas)
        debug_print("one of three is null\n");

    for (auto &field : ct->clas->symbols)
    {
        debug_print("iteration\n");
        if (!field.second)
            debug_print("field second is nullt\n");
        debug_print("%s; %s\n", field.first.c_str(), field.second->to_string().c_str());
        fields[field.first] = new Symbol(field.second);
    }
}

string ClassObject::to_string()
{
    string res = "(";

    for (auto &field : fields)
    {

        res += field.second->to_string() + "; ";
    }
    res += ")";

    return res;
}

ClassType::ClassType(SymbolTable *ct) : TypeNode(types::USER_TYPE)
{
    clas = ct;
}

ClassType::ClassType(RawNode *id) : TypeNode(types::USER_TYPE)
{
    clas = currentSymbolTable->isClassDefined(id->content);

    if (!clas)
    {
        semantic_error("%s isn't a class type", id->content.c_str());
    }
}

bool ClassType::is_equal(TypeNode *other)
{
    auto cl = dynamic_cast<ClassType *>(other);
    if (!other)
        return false;

    return clas == cl->clas;
}

string ClassType::to_string()
{
    if (clas)
        return clas->name;
    else
        return TypeNode::to_string();
}

ArrayValue::ArrayValue(ArrayType *at)
{
    type = at;

    if (!at)
    {
        semantic_error("arraytyppe is null, cant construct arrayvalue");
        return;
    }

    for (int i = 0; i < at->size; i++)
    {
        elements.push_back(at->element_type->get_associated_value());
    }
}

ArrayValue::ArrayValue()
{
}

string ArrayValue::to_string()
{
    string temp = "[";

    for (auto &el : elements)
    {

        temp += el->to_string() + ",";
    }
    temp.erase(temp.size() - 1);
    return temp + "]";
}

void ArrayValue::copy_to(ValueNode *&other)
{
    auto o = (ArrayValue *)(other);
    o = new ArrayValue();
    o->type = this->type;
    o->elements = this->elements;
    other = o;
};

ArrayValue::ArrayValue(Vector *init)
{
    auto at = new ArrayType(new TypeNode(types::OTHER));
    at->size = 0;
    this->type = at;

    if (!init)
        return;

    for (auto &el : init->pointers)
    {
        if (!el)
            return;
        auto expr = (Expression *)(el);

        auto val = expr->eval();
        if (!val)
            return;
        if (!add_element(val))
            return;
    }

    int size = elements.size();
    at->size = size;
    if (size)
        elements.at(0)->type->copy_to(at->element_type);
}

bool ArrayValue::add_element(ValueNode *val)
{
    if (elements.size() > 0)
    {
        if (!elements.at(0)->type || !val || !val->type)
        {
            debug_print("elements.at(0)->type is nulltpr");
            return false;
        }
        if (!elements.at(0)->type->is_equal(val->type))
        {
            semantic_error("cannot push %s to vector of  %s", val->type->to_string().c_str(), elements.at(0)->type->to_string().c_str());
            return false;
        }
    }
    elements.push_back(val);
    return true;
}

bool ArrayValue::mul(ValueNode *other)
{
    semantic_error("%s * %s is an unsupported binary opration", type->to_string().c_str(), other->type->to_string().c_str());
    return false;
}

AssignResult ArrayValue::assign(ValueNode *val)
{
    auto ar = dynamic_cast<ArrayValue *>(val);
    if (!ar)
        return AssignResult::DIFTYPE;

    if (ar->elements.size() != elements.size())
        return AssignResult::DIFTYPE;

    AssignResult res;

    for (size_t it = 0; it < elements.size(); it++)
    {
        res = elements.at(it)->assign(ar->elements.at(it));
        if (res != AssignResult::OK)
            return res;
    }
    return AssignResult::OK;
}

ValueNode *ArrayValue::at(ArrayIndexing *ai, int start_index)
{
    if (!ai)
        return nullptr;
    int indx_size = ai->indexes->size();
    int els_size = elements.size();
    if (indx_size == start_index)
        return this;

    auto convert = dynamic_cast<IntValue *>(ai->indexes->at(start_index));
    if (!convert || convert->value < 0 || convert->value >= els_size)
    {
        semantic_error("index out of bounds");
        return nullptr;
    }

    return elements[convert->value]->at(ai, start_index + 1);
}
