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
class GeneralInfo
{
public:
    int row, col;
    string content;
    GeneralInfo();
    GeneralInfo(string s);
    GeneralInfo(string str, int row, int col);
    void print();
    virtual ~GeneralInfo();
};
class ValueNode;

class FunctionDetails : public GeneralInfo
{
public:
    string name;
    string signature;
    vector<Symbol *> *parameters;
    TypeNode *return_type;
    FunctionDetails(string name, TypeNode *ret_type, Vector *pars);
    ~FunctionDetails();
    Symbol *hasParemeter(string name);
    void set_gReturnType();
    void print_parameters();
    void setSignature();
};

enum OperTypes
{
    NONOPERATOR,
    SUB,
    ADD,
    MUL,
    DIV,
    NEG,
    LNOT
};
class TypeNode;
class ValueNode
{
public:
    TypeNode *type;
    ValueNode(){};
    virtual ~ValueNode(){};

    virtual bool add(ValueNode *other) { return false; };
    virtual bool sub(ValueNode *other) { return false; };
    virtual bool mul(ValueNode *other) { return false; };
    virtual bool div(ValueNode *other) { return false; };

    virtual bool neg() { return false; };
    virtual bool lnot() { return false; };

    virtual void print() { cout << this->to_string() << endl; };

    virtual string to_string() { return "ValueNode"; };

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
    FunctionCall(GeneralInfo *scope, Vector *rest);

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
    ArrayIndexing(GeneralInfo *ar);
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
class TypeNode : public GeneralInfo
{
public:
    bool is_const = 0;
    types type;
    TypeNode(types t) { type = t; };
    TypeNode(string str);

    virtual string to_string() { return "unspecialized type"; };
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
    FloatType() : TypeNode(FLOAT){};
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
};
class BoolType : public TypeNode
{
public:
};
class CharType : public TypeNode
{
public:
    CharType() : TypeNode(FLOAT){};
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
    ClassType(GeneralInfo *id);

    bool is_equal(TypeNode *other) override;
    string to_string() override;
};
struct TempSymbol
{
    TypeNode *type;
    ValueNode *value;
};

class Expression : public GeneralInfo
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
    Expression(string identifier);
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
