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

class rvalueNode : virtual public generalNode
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
    types type;
    TypeNode(string str);
    TypeNode(){};
    virtual ~TypeNode();

    virtual bool add(TypeNode *other){return false;};
    virtual bool sub(TypeNode *other){return false;};
    virtual bool mul(TypeNode *other){return false;};
    virtual bool div(TypeNode *other){return false;};

    virtual bool uminus(){return false;};
    virtual bool neg(){return false;};
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
};
class IntType : public TypeNode
{
public:
    int value;
    IntType(string s);

    bool add(TypeNode* other) override;
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
class ClassType : public TypeNode
{
public:
    symbolTalbeNode *clas;
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
    ExpressionNode *left, *right;
    OperTypes oper;
    TypeNode *type_node = nullptr;

    ExpressionNode(OperTypes op, ExpressionNode *left, ExpressionNode *right, string cont);
    ExpressionNode(TypeNode *type_node, string cont);

    virtual ~ExpressionNode();

    TypeNode *type_of();

    TypeNode *eval();

    TypeNode* eval_binary_operator();
    TypeNode* eval_unary_operator();
};

class myVectorClass
{
public:
    std::vector<void *> pointers;

    void add_pointer(void *ptr);
};

#endif