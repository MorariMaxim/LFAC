#ifndef GENERALNODE_H
#define GENERALNODE_H
#include "commonIncludes.h"
#include "symbolTable.h"
#include <thread>
#include <chrono>
class Vector
{
public:
    std::vector<void *> pointers;

    void add_element(void *ptr);
};

void print_reduction(string str);
void print_token(string str, Colours color = Colours::DEFAULTCOL);

using u32 = unsigned int;

struct Position
{
    u32 row = 0, col = 0;
};

class Span
{
public:
    Position start, end;

    Span();

    void set_span(Span *other);
    void set_span_start(Span *other);
    void set_span_end(Span *other);
    void span_end();
    void set_lines(Span *r1, Span *r2);
    string span_to_string();
    void print_span();

    virtual ~Span();
};

class RawNode : public Span
{
public:
    string content;
    RawNode();
    RawNode(string s);
    void print();
    virtual ~RawNode();
};
class ValueNode;

class FunctionDetails : public RawNode
{
public:
    string name;
    string signature;
    vector<Symbol *> *parameters;
    TypeNode *return_type;
    FunctionDetails(string name, TypeNode *ret_type, Vector *pars);
    ~FunctionDetails();
    Symbol *hasParemeter(string name);
    void check_return_type();
    void print_parameters();
    void setSignature();

    operator Span *()
    {
        return span;
    }

    Span *span = new Span();
};

enum OperTypes
{
    NONOPERATOR,
    SUB,
    ADD,
    MUL,
    DIV,
    NEG,
    LNOT,
    LOR,
    LAND,
    EQ,
    NEQ,
    LE,
    LEQ,
    GE,
    GEQ
};
class TypeNode;
class ValueNode : public Span
{
public:
    TypeNode *type;
    ValueNode(){};
    virtual ~ValueNode(){};

    virtual bool add(ValueNode *other) { return false; };
    virtual bool sub(ValueNode *other) { return false; };
    virtual bool mul(ValueNode *other) { return false; };
    virtual bool div(ValueNode *other) { return false; };

    virtual bool eq(ValueNode *other) { semantic_error("unimplemented"); return false; };
    virtual bool neq(ValueNode *other) { return ! this->eq(other);  };
    virtual bool le(ValueNode *other) { semantic_error("unimplemented"); return false; };
    virtual bool leq(ValueNode *other) { return this->eq(other) || this->le(other); };
    virtual bool ge(ValueNode *other) { return  ! this->leq(other); };
    virtual bool geq(ValueNode *other) { return  ! this->le(other); };

    virtual bool neg() { return false; };
    virtual bool lnot() { return false; };

    virtual void print() { cout << this->to_string() << endl; };

    virtual string to_string()
    {
        semantic_error("uninitialized variable");
        return "";
    };

    virtual void copy_to(ValueNode *&other)
    {
        auto o = (ValueNode *)(other);
        o = new ValueNode();
        o->type = this->type;
        other = o;
    };

    virtual ValueNode *at(ArrayIndexing *arindex, int start_index) { return nullptr; };

    virtual AssignResult assign(ValueNode *vn) { return AssignResult::OTHERAR; };
};

class IntValue : public ValueNode
{
public:
    int value;
    IntValue(string number);
    virtual bool add(ValueNode *other) override;
    virtual bool sub(ValueNode *other) override;
    virtual bool mul(ValueNode *other) override;
    virtual bool div(ValueNode *other) override;

    virtual bool neg() override;
    virtual bool lnot() override;

    virtual bool eq(ValueNode *other) override; 
    virtual bool le(ValueNode *other) override; 

    void print() override;
    string to_string() override;

    virtual void copy_to(ValueNode *&other) override;
    virtual ValueNode *at(ArrayIndexing *arindex, int start_index) override;

    AssignResult assign(ValueNode *val) override;
};
class FloatValue : public ValueNode
{
public:
    float value;
    FloatValue(string number);
    virtual bool add(ValueNode *other) override;
    virtual bool sub(ValueNode *other) override;
    virtual bool mul(ValueNode *other) override;
    virtual bool div(ValueNode *other) override;

    virtual bool neg() override;
    virtual bool lnot() override;

    virtual bool eq(ValueNode *other) override; 
    virtual bool le(ValueNode *other) override; 

    void print() override;
    string to_string() override;

    virtual void copy_to(ValueNode *&other) override;
    virtual ValueNode *at(ArrayIndexing *arindex, int start_index) override;

    AssignResult assign(ValueNode *val) override;
};

class BoolValue : public ValueNode
{
public:
    bool value;
    BoolValue(string Wahrheit);
    virtual bool add(ValueNode *other) override;
    virtual bool sub(ValueNode *other) override;
    virtual bool mul(ValueNode *other) override;
    virtual bool div(ValueNode *other) override;
    bool lor(ValueNode *other);
    bool land(ValueNode *other);
    virtual bool neg() override;
    virtual bool lnot() override;

    void print() override;
    string to_string() override;

    virtual void copy_to(ValueNode *&other) override;
    virtual ValueNode *at(ArrayIndexing *arindex, int start_index) override;

    AssignResult assign(ValueNode *val) override;
};

class StringValue : public ValueNode
{
public:
    string value;
    StringValue(string strlit);
    virtual bool add(ValueNode *other) override;
    virtual bool sub(ValueNode *other) override;
    virtual bool mul(ValueNode *other) override;
    virtual bool div(ValueNode *other) override;

    virtual bool neg() override;
    virtual bool lnot() override;

    void print() override;
    string to_string() override;

    virtual void copy_to(ValueNode *&other) override;
    virtual ValueNode *at(ArrayIndexing *arindex, int start_index) override;

    AssignResult assign(ValueNode *val) override;
};

class CharValue : public ValueNode
{
public:
    char value;
    CharValue(string character);
    CharValue(char character);
    virtual bool add(ValueNode *other) override;
    virtual bool sub(ValueNode *other) override;
    virtual bool mul(ValueNode *other) override;
    virtual bool div(ValueNode *other) override;

    virtual bool neg() override;
    virtual bool lnot() override;

    void print() override;
    string to_string() override;

    virtual void copy_to(ValueNode *&other) override;
    virtual ValueNode *at(ArrayIndexing *arindex, int start_index) override;

    AssignResult assign(ValueNode *val) override;
};

class FunctionCall : public ValueNode
{
public:
    FunctionDetails *function_name;
    vector<ValueNode *> *args;
    ValueNode *value;
    bool checkCall();
    FunctionCall(RawNode *scope, Vector *rest);

    bool add(ValueNode *other) { return true; };
    bool sub(ValueNode *other) { return true; };
    bool mul(ValueNode *other) { return true; };
    bool div(ValueNode *other) { return true; };

    bool NEG() { return true; };
    bool neg() { return true; };

    void print()
    {
        if (value)
            value->print();
        else
        {
            printf("unimplemented in functioncall\n");
        }
    };

    void copy_to(ValueNode *&other)
    {
        if (value)
        {
            value->copy_to(other);
        }
        else
        {
            auto o = (ValueNode *)(other);
            o = new ValueNode();
            o->type = this->type;
            other = o;
        };
    };
};
class ClassType;
class ClassObject : public ValueNode
{
public:
    unordered_map<string, Symbol *> fields;
    ClassObject(ClassType *ct);

    string to_string() override;
};

class ArrayIndexing
{
public:
    Symbol *array;
    vector<ValueNode *> *indexes = new vector<ValueNode *>();
    ArrayIndexing(RawNode *ar);
    ArrayIndexing();
    void add_index(Expression *val);
    bool check_indexes();
};

class ArrayValue : public ValueNode
{
public:
    vector<ValueNode *> elements;
    ArrayValue(ArrayType *at);
    ArrayValue();

    ArrayValue(Vector *init);
    bool add_element(ValueNode *val);
    bool mul(ValueNode *other) override;
    AssignResult assign(ValueNode *vn) override;
    ValueNode *at(ArrayIndexing *arindex, int start_index) override;
    string to_string() override;
    void copy_to(ValueNode *&other) override;
};
class TypeNode : public RawNode
{
public:
    bool is_const = 0;
    types type;
    TypeNode(types t) { type = t; };
    TypeNode(string str);

    virtual string to_string() { return types_2_str(type); };
    virtual void copy_to(TypeNode *&other)
    {
        auto o = (TypeNode *)(other);
        o = new TypeNode(types::OTHER);
        o->type = this->type;
        other = o;
    };
    virtual ~TypeNode();

    virtual ValueNode *get_associated_value() { return new ValueNode(); };

    virtual bool is_equal(TypeNode *other) { return false; };
};

class FloatType : public TypeNode
{
public:
    FloatType();

    string to_string() override;
    ValueNode *get_associated_value() override;

    void copy_to(TypeNode *&other) override;
    bool is_equal(TypeNode *other) override;
};
class IntType : public TypeNode
{
public:
    IntType();

    string to_string() override;
    ValueNode *get_associated_value() override;

    void copy_to(TypeNode *&other) override;
    bool is_equal(TypeNode *other) override;
};
class StringType : public TypeNode
{
public:
    StringType();
    string to_string() override;
    ValueNode *get_associated_value() override;

    void copy_to(TypeNode *&other) override;
    bool is_equal(TypeNode *other) override;
};
class BoolType : public TypeNode
{
public:
    BoolType();

    string to_string() override;
    ValueNode *get_associated_value() override;

    void copy_to(TypeNode *&other) override;
    bool is_equal(TypeNode *other) override;
};
class CharType : public TypeNode
{
public:
    CharType();

    string to_string() override;
    ValueNode *get_associated_value() override;

    void copy_to(TypeNode *&other) override;
    bool is_equal(TypeNode *other) override;
};
class ArrayType : public TypeNode
{
public:
    int size;
    TypeNode *element_type;

    ArrayType(TypeNode *et);
    ArrayType();
    ArrayType(TypeNode *type, ArrayIndexing *arindex);
    ~ArrayType();

    bool is_equal(TypeNode *other) override;
    string to_string() override;
    ValueNode *get_associated_value() override;

    void copy_to(TypeNode *&other) override;
};

struct TypeNodeIsConst
{
    TypeNode *tn;
    bool is_const;
};

class ClassType : public TypeNode
{
public:
    SymbolTable *clas;
    ClassType(SymbolTable *ct);
    ClassType(RawNode *id);

    bool is_equal(TypeNode *other) override;
    string to_string() override;
};
struct TempSymbol
{
    TypeNode *type;
    ValueNode *value;
};

class Expression : public Span
{
public:
    Expression *left = nullptr, *right = nullptr;
    OperTypes oper;
    bool symbol_type; // 1 for symbol; 0 for temp object
    union
    {
        Symbol *sym = nullptr;
        TempSymbol *temp;
    };

    Expression(OperTypes op, Expression *left, Expression *right);
    Expression(ValueNode *vn);
    Expression(Symbol *sym);
    Expression(RawNode *id);
    virtual ~Expression();

    TypeNode *type();

    ValueNode *get_leaf_value(); // only if leaf node
    TypeNode *get_leaf_type();
    string get_leaf_id();
    static bool are_types_equal(TypeNode *t1, TypeNode *t2);

    ValueNode *eval_wrapper();
    ValueNode *eval();
    ValueNode *eval_binary_operator();
    ValueNode *eval_unary_operator();
};

#endif
