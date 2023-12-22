#include "GeneralInfo.h"
#include <stdio.h>
#include <format>
using namespace std;

static int count = 0;

void print_count(string s)
{
    int debug = 1;

    if (debug)
        printf("[%d] %s\n", count++, s.c_str());
    fflush(stdout);
}

void symbol_not_declared(string s)
{
    printf("%s is not declared\n", s.c_str());
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

GeneralInfo::GeneralInfo(string str, int row_, int col_)
{
    this->row = row_;
    this->col = col_;
    content = str;
    if (debug)
        printf("constructing GeneralInfo (%s) at (%d,%d)\n", content.c_str(), row, col);
}

GeneralInfo::GeneralInfo()
{
    content = "";
}

GeneralInfo::GeneralInfo(string s)
{
    content = s;
}

void GeneralInfo::print()
{
    printf("%s", content.c_str());
}

GeneralInfo::~GeneralInfo()
{
    if (debug)
        printf("destructing  GeneralInfo (%s)\n", content.c_str());
}

void printx(string str)
{

    static int debug = 1, delay = 0;
    if (debug)
    {
        printf("%s", str.c_str());
        fflush(stdin);
    }
    if (delay)
        this_thread::sleep_for(std::chrono::milliseconds(100));
}

bool Expression::are_types_equal(TypeNode *t1, TypeNode *t2)
{
    if (!t1 || !t2)
    {
        printf("one is null\n");
        return false;
    }
    if (t1->type != t2->type)
    {
        printf("not equal types\n");

        t1->print();
        t2->print();
        return false;
    }
    if (t1->type == types::USER_TYPE)
    {

        auto clas = dynamic_cast<ClassType *>(t1);

        if (!clas)
        {
            printf("error at dynamic cast \n");
            return false;
        }
        string name1 = clas->clas->name;
        clas = dynamic_cast<ClassType *>(t1);

        if (!clas)
        {
            printf("error at dynamic cast \n");
            return false;
        }
        string name2 = clas->clas->name;

        printf("here 1");
        fflush(stdout);
        if (name1 != name2)
            return false;
    }
    return true;
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
    print_count("eval binary \n");
    auto t1 = left->eval();
    auto t2 = right->eval();

    if (!t1 || !t2)
    {
        print_count("one is null\n");
        return nullptr;
    }

    switch (oper)
    {
    case OperTypes::SUB:
    {
        print_count("sub ");
        t1->sub(t2);
        break;
    }
    case OperTypes::ADD:
    {
        print_count("add ");
        t1->add(t2);
        break;
    }
    case OperTypes::MUL:
    {
        print_count("mul ");
        t1->mul(t2);
        break;
    }
    case OperTypes::DIV:
    {
        print_count("div ");
        t1->div(t2);
        break;
    }
    case OperTypes::NEG:
    {
        print_count("neg");
        t1->neg();
        break;
    }
    case OperTypes::LNOT:
    {
        print_count("!");
        t1->lnot();
        break;
    }
    default:
        return nullptr;
    }

    print_count("return ");
    return t1;
}
ValueNode *Expression::eval_wrapper()
{
    print_count("going to eval expression\n");

    auto t = eval();
    print_count("out\n");

    if (t)
        t->print();
    else
    {
        printf("coulnd't evaluate expression\n");
    }
    return t;
}
ValueNode *Expression::eval_unary_operator()
{
    print_count("eval unary");
    auto t1 = left->eval();
    if (!t1)
        return nullptr;
    switch (oper)
    {
    case OperTypes::LNOT:
    {
        t1->lnot();
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
    print_count("eval call\n");

    if (oper == NONOPERATOR)
    {
        ValueNode *temp1;
        auto temp2 = get_leaf_value();
        temp2->copy_to(temp1);
        print_count("leaf node\n");
        return temp1;
    }

    if (oper == OperTypes::SUB || oper == OperTypes::ADD || oper == OperTypes::MUL || oper == OperTypes::DIV)
        return eval_binary_operator();

    if (oper == OperTypes::LNOT || oper == OperTypes::NEG)
        return eval_unary_operator();

    return nullptr;
}

Expression::Expression(OperTypes op, Expression *left, Expression *right) : GeneralInfo("", -1, -1)
{
    this->oper = op;
    this->left = left;
    this->right = right;
    vector<int> v;
}

Expression::Expression(string cont) : GeneralInfo(cont, -1, -1)
{
    sym = currentSymbolTable->is_symbol_defined_in_path(cont);

    if (!sym)
    {
        notify("%s not declared\n", cont.c_str());
    }
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
        if (symbol_type)
            return sym->value;
        else if (temp)
            return temp->value;
        return nullptr;
    }

    return nullptr;
}
FunctionDetails::FunctionDetails(string name, TypeNode *ret_type, Vector *pars) : GeneralInfo("", -1, -1)
{
    printf("func name = %s\n", name.c_str());
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

    return_type->print();
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

void FunctionDetails::set_gReturnType()
{
    if (gReturnType)
    {

        delete return_type;
        return_type = gReturnType;
    }
}

void FunctionDetails::print_parameters()
{
    if (parameters == nullptr)
        return;

    for (auto par : *parameters)
    {
        par->printSymbol();
    }
}

void FunctionDetails::setSignature()
{

    string temp = "fn " + name + "(";
    if (parameters && parameters->size())
    {
        for (auto par : *parameters)
        {
            temp += par->getSymbolAsString() + ", ";
        }
        temp.erase(temp.size() - 2, 2);
    }
    temp += ") -> ";
    temp += getTypeAsStr(this->return_type->type);
    signature = temp;
    // printf("%s\n", signature.c_str());
}

bool FunctionCall::checkCall()
{
    if (function_name == nullptr)
    {
        printf("name == nulptr\n");
        return false;
    }

    auto parameters = function_name->parameters;

    if (((parameters == nullptr) && (args->size() != 0)) ||
        ((parameters != nullptr) && (args->size() != parameters->size())))
    {
        printf("((parameters == nullptr) && (args->size() != 0)) || ((parameters != nullptr) && (args->size() != parameters->size()))\n");
        return false;
    }

    int size = args->size();
    for (int i = 0; i < size; i++)
    {
        if ((*args)[i] == nullptr)
        {
            printf("%dth. arg is nullptr\n", i + 1);
            return false;
        }
        if (!Expression::are_types_equal((*args)[i]->type, (*parameters)[i]->type))
        {
            printf("args[%d].type (%s) != pars[%d].type (%s)\n", i, getTypeAsStr((*args)[i]->type->type).c_str(), i, getTypeAsStr((*parameters)[i]->type->type).c_str());
            return false;
        }
    }
    return true;
}

FunctionCall::FunctionCall(GeneralInfo *scope_id, Vector *fnname_parameters) : ValueNode()
{
    SymbolTable *scope = currentSymbolTable;

    if (scope_id)
    {
        Symbol *sym = nullptr;
        sym = scope->is_user_symbol_defined(scope_id);

        if (!sym)
        {
            printf("variable %s not decalred\n", scope_id->content.c_str());
            return;
        }
        else
        {
            auto clas = dynamic_cast<ClassType *>(sym->type);
            if (!clas)
            {
                printf("cannot treat %s's type as class type\n", sym->name.c_str());
            }
            scope = clas->clas;
        }
    }

    if (!fnname_parameters)
    {
        printf("for some reason fnname_parameters is null");
        return;
    }

    GeneralInfo *fn_name = (GeneralInfo *)(fnname_parameters->pointers[0]);

    if (!fn_name)
        notify("funcname is nullptr\n");

    auto funcnode = scope->isFuncDefined(fn_name->content);

    if (funcnode == nullptr)
    {
        printf("found no such function\n");
        return;
    }
    else
        printf("found such function\n");

    if (funcnode->return_type)
    {
        this->type = funcnode->return_type;
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
                notify("expr is nullptr\n");

            args->push_back(expr->eval());
        }
    }

    print();
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
        notify("expression resulted in nullptr\n");
    }
}

#define checkSymbol(x)                                                                        \
    {                                                                                         \
        if (currentSymbolTable->is_symbol_defined_in_path(x->content) == nullptr)             \
            printf("\nsymbol not defined %s at %d:%d\n", x->content.c_str(), x->row, x->col); \
    }
#define getSymbol(x) currentSymbolTable->is_symbol_defined_in_path(x->content)

ArrayIndexing::ArrayIndexing(GeneralInfo *arr)
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
        printf("%s is not an ArrayType\n", arr->content.c_str());
        array = nullptr;
    }
    else
        array = sym;

    indexes = new vector<ValueNode *>();
}
bool ArrayIndexing::check_indexes()
{
    if (!indexes || !array)
    {
        notify("no indexes or no array\n");
        return true;
    }

    printf("indexes : ");
    for (auto v : *indexes)
    {
        v->print();
    }
    printf("\n");

    ArrayType *current_dimension = dynamic_cast<ArrayType *>(array->type);

    int index_size = indexes->size();
    int it = 0;

    for (auto &val : *indexes)
    {
        if (!current_dimension)
        {
            notify("error converting to arraytype, probably more indexations than array dimensions");
            return false;
        }

        auto index = dynamic_cast<IntValue *>(val);
        if (!index || index->value < 0)
        {
            notify("index is not usize");
            return false;
        }

        if (current_dimension->size <= index->value)
        {
            notify("index exceeds size of array");
            return false;
        }

        current_dimension = dynamic_cast<ArrayType *>(current_dimension->element_type);
    }
    return true;
}

void Vector::add_pointer(void *ptr)
{
    pointers.push_back(ptr);
}

ArrayType::ArrayType(TypeNode *et) : TypeNode(types::ARRAY)
{
    element_type = et;
}

ArrayType::~ArrayType()
{
    delete element_type;
}

/*
ArrayType *ArrayType::arrayBuiltFromStack = nullptr;
void ArrayType::buildFromStack(int it)
{
    if (it == 0)
    {
        printf("array type = ");
        printType(arrayType->type);
        printf("\ndimensions : ");
        for (auto &el : arrayStack)
        {
            printf("%d,", el);
        }
        printf("\n");
    }

    int n = arrayStack.size();
    this->type = types::ARRAY;
    el_type = types::ARRAY;
    this->size = arrayStack[it];
    this->dimension = n - it;

    if (n == (it + 1))
    {
        types base_type;
        vector<TypeNode *> *bottom_elements;
        switch (arrayType->type) // to do
        {
        case FLOAT:
            // printf("float\n");
            base_type = types::FLOAT;
            bottom_elements = new vector<TypeNode *>(this->size, new FloatType());
            break;
        case INT:
            base_type = types::INT;
            // printf("int\n");
            bottom_elements = new vector<TypeNode *>(this->size, new IntType("0"));
            break;
        case CHAR:
            base_type = types::CHAR;
            // printf("char\n");
            bottom_elements = new vector<TypeNode *>(this->size, new CharType());
            break;
        case STRING:
            break;
        default:
            bottom_elements = new vector<TypeNode *>(this->size, new TypeNode(types::OTHER));
            break;
        }
        elements = bottom_elements;
        el_type = base_type;
    }
    else
    {
        elements = new vector<TypeNode *>(this->size, new ArrayType("", it + 1));
    }
    if (it == 0)
    {
        arrayStack.clear();
    }
}*/

IntType::IntType(string s) : TypeNode(INT)
{
    type = INT;
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
void IntValue::copy_to(ValueNode *&other)
{
    auto o = (IntValue *)(other);
    o = new IntValue();
    o->value = this->value;
    other = o;
}
void IntValue::print()
{
    printf("Integer with value = %d\n", value);
}

ClassObject::ClassObject(ClassType *ct)
{
    type = ct;
    for (auto &field : ct->clas->symbols)
    {
        fields[field.first] = new Symbol(field.second);
    }
}

ClassType::ClassType(SymbolTable *ct) : TypeNode(types::USER_TYPE)
{
    clas = ct;
}
 