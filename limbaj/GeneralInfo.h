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

class TypeNode : public GeneralInfo
{
public:
    bool is_const = 0;
    types type;
    TypeNode(types t) { type = t; };
    TypeNode(string str);

    virtual string  to_string(){ return "unspecialized type";};
    virtual void copy_to(TypeNode *&other)
    {
        {
            auto o = (TypeNode *)(other);
            o = new TypeNode(types::OTHER);
            o->type = this->type;
            other = o;
        };
    };
    virtual ~TypeNode();
};

class FloatType : public TypeNode
{
public:
    FloatType() : TypeNode(FLOAT){};
};
class IntType : public TypeNode
{
public:
    IntType(string s);
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


    ArrayType(TypeNode * et);
    ~ArrayType();

    /*void buildFromStack(int it);
    static ArrayType *arrayBuiltFromStack;*/
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
};

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
    SUB,
    ADD,
    MUL,
    DIV,
    NEG,
    LNOT,
    NONOPERATOR
};

class ValueNode
{
public:
    TypeNode *type;
    ValueNode();
    virtual ~ValueNode();

    virtual bool add(ValueNode *other) { return false; };
    virtual bool sub(ValueNode *other) { return false; };
    virtual bool mul(ValueNode *other) { return false; };
    virtual bool div(ValueNode *other) { return false; };

    virtual bool neg() { return false; };
    virtual bool lnot() { return false; };

    virtual void print() { printf("unimplemented\n"); };

    virtual void copy_to(ValueNode *&other)
    {
        {
            auto o = (ValueNode *)(other);
            o = new ValueNode();
            o->type = this->type;
            other = o;
        };
    };
};

class IntValue : public ValueNode
{
public:
    int value;
    IntValue();
    virtual bool add(ValueNode *other) ;
    virtual bool sub(ValueNode *other) ;
    virtual bool mul(ValueNode *other) ;
    virtual bool div(ValueNode *other) ;

    virtual bool neg() ;
    virtual bool lnot() ;

    void print() override;

    virtual void copy_to(ValueNode *&other);
};
 
class FunctionCall : public ValueNode
{
public:
    FunctionDetails *function_name;
    vector<ValueNode*> *args;
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
class ClassObject : public ValueNode {
public:    
    unordered_map<string, Symbol*> fields;
    ClassObject(ClassType *ct);
};


class ArrayIndexing
{
public:
    Symbol *array;
    vector<ValueNode *> *indexes;
    ArrayIndexing(GeneralInfo *ar);
    void add_index(Expression *val);
    bool check_indexes();
};

class Expression : public GeneralInfo
{
public:
    Expression *left = nullptr, *right = nullptr;
    OperTypes oper;
    bool symbol_type; // 1 for symbol; 0 for temp object
    union
    {
        Symbol *sym;
        struct
        {
            TypeNode *type;
            ValueNode *value;
        } *temp;
    };

    Expression(OperTypes op, Expression *left, Expression *right);
    Expression(TypeNode *tn, ValueNode *vn);
    Expression(string identifier);
    virtual ~Expression();

    TypeNode *type();
    ValueNode *get_leaf_value(); // only if leaf node
    TypeNode *get_leaf_type();
    static bool are_types_equal(TypeNode *t1, TypeNode *t2);

    ValueNode *eval_wrapper();
    ValueNode *eval();
    ValueNode *eval_binary_operator();
    ValueNode *eval_unary_operator();
 
};



class Vector
{
public:
    std::vector<void *> pointers;

    void add_pointer(void *ptr);
};

#endif
