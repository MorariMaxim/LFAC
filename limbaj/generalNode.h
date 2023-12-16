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

class typeNode : public generalNode
{
public:
    types type;

    typeNode(string str);
    ~typeNode();
};

class rvalueNode : public generalNode
{
public:
    rvalueNode(string cont);
    rvalueNode(string cont, types type);
    types type;
};
class intValueNode : public rvalueNode
{
public:
    int value;
    intValueNode(string cont);
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
    arraySymbol *array;

    bool checkIndexes();
    arrayIndexing(generalNode *ar);
};

class value
{
public:
    ~value();
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
    functionCall(string funcName);
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
enum operTypes
{
    minus,
    plus,
    product,
    division,
};

class expressionNode : public generalNode
{
public:
    expressionNode *left, *right;
    operTypes oper;
    value *val;

    expressionNode(operTypes op, expressionNode *left, expressionNode *right, string cont);
    expressionNode(value *val, string cont);

    virtual ~expressionNode();
};

class myVectorClass {
public: 
    std::vector<void*> pointers;
    
    void addPointer(void * ptr);
};
#endif
