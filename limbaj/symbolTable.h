#ifndef symbolTable_H
#define symbolTable_H
#include "commonIncludes.h"  

class Symbol  
{
public:
    string name;    
    types type;
    symbolTalbeNode * classType = nullptr;
    bool isConst;
    bool isInit;
    expressionNode * value;

    Symbol(bool isConst_, types type_,string name_, expressionNode* value_);
    void setTo(bool isConst_, types type_,string name_, expressionNode* value_);
    Symbol();
    virtual ~Symbol();

    virtual void printSymbol();
    virtual string getSymbolAsString();
};
class arraySymbol: public Symbol{
public:
    int size;
    bool bottom;
    int dimension;
    union 
    {
        vector<arraySymbol*> *array_elements;
        vector<float> *float_elements;
        vector<int> *int_elements;
        vector<char> *char_elements;
    };        
    arraySymbol();
    ~arraySymbol();
    void printSymbol();
    static arraySymbol * buildFromStack(int it);
    static arraySymbol * arrayBuiltFromStack;

};


class symbolTalbeNode
{
public:
    string name; 
    visibilityType visibility;
    scopeType type; 
    symbolTalbeNode *parent = nullptr;
    functionNode * funcNode = nullptr;
    vector<symbolTalbeNode*> children;
    symbolTalbeNode *addScope(string name);
    unordered_map<string,Symbol*> symbols;
    unordered_map<string,symbolTalbeNode*> functions;
    unordered_map<string,symbolTalbeNode*> classes;
    unordered_map<string,symbolTalbeNode*> other;

    symbolTalbeNode(string name);
    
    symbolTalbeNode* newClass(generalNode * gn);

    symbolTalbeNode *getParent();
    string getFullPath();
    void   printTable(int depth);
    Symbol* isSymbolDefinedInPath(string name);
    Symbol* isLocallyDefined(string name);
    functionNode* isFuncDefined(string name);
    symbolTalbeNode * isClassDefined(string name);

    int check_member_access( generalNode * id, generalNode * member_id );

    int defineSymbol(bool isConst_, types type_, string name_, expressionNode *value_);
    int defineSymbol(string name, Symbol* symbol);
    int defineSymbol(Symbol* symbol);
    int defineUserSymbol(generalNode * classId, generalNode * symbolName);

    symbolTalbeNode* addFunction(functionNode * newScope);
    
    symbolTalbeNode * addFunction(string name);
    symbolTalbeNode * addClass(string name);

    void setAsFunction(functionNode * funcNode);
};



#endif