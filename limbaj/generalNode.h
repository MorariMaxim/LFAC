#ifndef GENERALNODE_H
#define GENERALNODE_H
#include "commonIncludes.h"
#include "symbolTable.h"
#include <thread>
#include <chrono>
void printx(string str);

class generalNode
{
public:
    int row, col;
    string content;
    generalNode(string str);
    generalNode();
    generalNode(string str, int row, int col);
    void print();
    virtual ~generalNode();
};

class rvalueNode : public generalNode
{
public:
    rvalueNode(string cont);
    rvalueNode(){};
    rvalueNode(string cont, types type);
    types type;
};
class rValueNodes
{
public:
    vector<rvalueNode *> *values;
    void addRvalue(rvalueNode *rval);
    rValueNodes();
};

class arrayIndexing : public rValueNodes
{
public:
    ArrayType *array;

    bool checkIndexes();
    arrayIndexing(generalNode *ar);
};

class value
{
public:
    ~value();
};

class TypeNode : public rvalueNode
{
public:
    int is_const = 0;
    types type;
    TypeNode(string str);
    TypeNode(types t){type = t;};
    virtual ~TypeNode();

    virtual bool add(TypeNode *other) { return false; };
    virtual bool sub(TypeNode *other) { return false; };
    virtual bool mul(TypeNode *other) { return false; };
    virtual bool div(TypeNode *other) { return false; };

    virtual bool uminus() { return false; };
    virtual bool neg() { return false; };

    virtual void print() { printf("unimplemented\n"); };
    virtual void copy_to(TypeNode *&other) { 
    {
        auto o = (TypeNode *)(other);
        o = new TypeNode(this->content);
        o->type = this->type;
        other = o;
    };};
};

class UserDefinedType : TypeNode
{
public:
    symbolTalbeNode *clas;
};
class FloatType : public TypeNode
{
public:
    float val;

    FloatType() : TypeNode(FLOAT){};
};
class IntType : public TypeNode
{
public:
    int value;
    IntType(string s);

    bool add(TypeNode *other) override;
    bool mul(TypeNode *other) override;
    bool div(TypeNode *other) override;
    bool sub(TypeNode *other) override;
    virtual void print() override;
    virtual void copy_to(TypeNode *&other);
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
    int dimension;
    types el_type;

    vector<TypeNode *> *elements;

    ArrayType(string str, int iteration);
    ~ArrayType();

    void buildFromStack(int it);
    static ArrayType *arrayBuiltFromStack;
};

struct TypeNodeIsConst
{
    TypeNode *tn;
    bool is_const;
};
class ClassType : public TypeNode
{
public:
    symbolTalbeNode *clas;
    unordered_map<string, TypeNodeIsConst> fields;

    ClassType(symbolTalbeNode *ct);
};

class functionNode : public generalNode
{
public:
    string name;
    string signature;
    vector<Symbol *> *parameters;
    types returnType;
    functionNode(string name, types retType, vector<Symbol *> *pars);
    ~functionNode();
    Symbol *hasParemeter(string name);
    void printParameters();
    void setSignature();
};

class functionCall
{
public:
    functionNode *functionName;
    vector<rvalueNode *> *args;
    bool checkCall();
    functionCall(generalNode *scope, myVectorClass *rest);
    void setArgs(rValueNodes *rvals);
    void addRvalue(rvalueNode *rval);
};

class parameterList
{

public:
    vector<Symbol *> *parameters;
    parameterList();
    void addParameter(Symbol *parameter);
};
enum OperTypes
{
    SUB,
    ADD,
    MUL,
    DIV,
    UMINUS,
    NEG
};

class ExpressionNode : public generalNode
{
public:
    ExpressionNode *left = nullptr, *right = nullptr;
    OperTypes oper;
    TypeNode *type_node = nullptr;

    ExpressionNode(OperTypes op, ExpressionNode *left, ExpressionNode *right, string cont);
    ExpressionNode(TypeNode *type_node);
    ExpressionNode(string cont);

    static bool compare_types(TypeNode *t1, TypeNode *t2);

    virtual ~ExpressionNode();

    TypeNode *type_of();

    TypeNode *eval();

    TypeNode *eval_wrapper();

    TypeNode *eval_binary_operator();
    TypeNode *eval_unary_operator();
};

class myVectorClass
{
public:
    std::vector<void *> pointers;

    void add_pointer(void *ptr);
};

#endif