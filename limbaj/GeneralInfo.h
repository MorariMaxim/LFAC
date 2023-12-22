#ifndef GENERALNODE_H
#define GENERALNODE_H
#include "commonIncludes.h"
#include "symbolTable.h"
#include <thread>
#include <chrono>
void printx(string str);

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

class TypeAndValue : public GeneralInfo
{
public:
    int is_const = 0;
    types type;
    TypeAndValue(types t) { type = t; };
    TypeAndValue(string str);
    virtual ~TypeAndValue();

    virtual bool add(TypeAndValue *other) { return false; };
    virtual bool sub(TypeAndValue *other) { return false; };
    virtual bool mul(TypeAndValue *other) { return false; };
    virtual bool div(TypeAndValue *other) { return false; };

    virtual bool UMINUSOPER() { return false; };
    virtual bool neg() { return false; };

    virtual void print() { printf("unimplemented\n"); };

    virtual void copy_to(TypeAndValue *&other)
    {
        {
            auto o = (TypeAndValue *)(other);
            o = new TypeAndValue(this->type);
            o->type = this->type;
            other = o;
        };
    };
};

class FloatType : public TypeAndValue
{
public:
    float val;

    FloatType() : TypeAndValue(FLOAT){};
};
class IntType : public TypeAndValue
{
public:
    int value;
    IntType(string s);

    bool add(TypeAndValue *other) override;
    bool mul(TypeAndValue *other) override;
    bool div(TypeAndValue *other) override;
    bool sub(TypeAndValue *other) override;
    bool neg() override;
    bool UMINUSOPER() override;
    void print() override;
    void copy_to(TypeAndValue *&other);
};
class StringType : public TypeAndValue
{
public:
};
class BoolType : public TypeAndValue
{
public:
};
class CharType : public TypeAndValue
{
public:
    CharType() : TypeAndValue(FLOAT){};
};
class ArrayType : public TypeAndValue
{
public:
    int size;
    int dimension;
    types el_type;

    vector<TypeAndValue *> *elements;

    ArrayType(string str, int iteration);
    ~ArrayType();

    void buildFromStack(int it);
    static ArrayType *arrayBuiltFromStack;
};

struct TypeNodeIsConst
{
    TypeAndValue *tn;
    bool is_const;
};

class ClassType : public TypeAndValue
{
public:
    SymbolTable *clas;
    unordered_map<string, TypeNodeIsConst> fields;

    ClassType(SymbolTable *ct);
};

class FunctionDetails : public GeneralInfo
{
public:
    string name;
    string signature;
    vector<Symbol *> *parameters;
    TypeAndValue *return_type;
    FunctionDetails(string name, TypeAndValue *ret_type, Vector *pars);
    ~FunctionDetails();
    Symbol *hasParemeter(string name);
    void set_gReturnType();
    void print_parameters();
    void setSignature();
};

class FunctionCall : public TypeAndValue
{
public:
    FunctionDetails *function_name;
    vector<TypeAndValue *> *args;
    TypeAndValue *value;
    bool checkCall();
    FunctionCall(GeneralInfo *scope, Vector *rest);

    bool add(TypeAndValue *other) { return true; };
    bool sub(TypeAndValue *other) { return true; };
    bool mul(TypeAndValue *other) { return true; };
    bool div(TypeAndValue *other) { return true; };

    bool UMINUSOPER() { return true; };
    bool neg() { return true; };

    void print() { if(value) value->print(); else {printf("unimplemented in functioncall\n");} };

    void copy_to(TypeAndValue *&other)
    {   
        if(value) {
            value->copy_to(other);
        }
        else {
            auto o = (TypeAndValue *)(other);
            o = new TypeAndValue(this->type);
            o->type = this->type;
            other = o;
        };
    };
};

class ArrayIndexing : public TypeAndValue
{
public:
    vector<TypeAndValue *> *indexes;
    void add_index(Expression *val);
    ArrayType *array;

    bool check_indexes();
    ArrayIndexing(GeneralInfo *ar);
};
enum OperTypes
{
    SUB,
    ADD,
    MUL,
    DIV,
    UMINUSOPER,
    NEG
};

class Expression : public GeneralInfo
{
public:
    Expression *left = nullptr, *right = nullptr;
    OperTypes oper;
    TypeAndValue *type_node = nullptr;

    Expression(OperTypes op, Expression *left, Expression *right, string cont);
    Expression(TypeAndValue *type_node);
    Expression(string cont);

    static bool are_types_equal(TypeAndValue *t1, TypeAndValue *t2);

    virtual ~Expression();

    TypeAndValue *type_of();

    TypeAndValue *eval();

    TypeAndValue *eval_wrapper();

    TypeAndValue *eval_binary_operator();
    TypeAndValue *eval_unary_operator();
};

class Vector
{
public:
    std::vector<void *> pointers;

    void add_pointer(void *ptr);
};

#endif
