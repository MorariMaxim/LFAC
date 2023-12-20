#ifndef symbolTable_H
#define symbolTable_H
#include "commonIncludes.h"  
#include <unordered_set>
class Symbol  
{
public:
    string name;    
    TypeNode* typen = nullptr;
    types type;
    symbolTalbeNode * classType = nullptr;
    bool isConst;
    bool isInit;
    ExpressionNode * value;

    Symbol(bool isConst_, types type_,string name_, ExpressionNode* value_);
    void setTo(bool isConst_, types type_,string name_, ExpressionNode* value_);
    Symbol();
    virtual ~Symbol();

    void printSymbol();
    string getSymbolAsString();
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

    unordered_set<Symbol*> temp_symbols;

    symbolTalbeNode(string name);
    
    symbolTalbeNode* newClass(generalNode * gn);

    symbolTalbeNode *getParent();
    string getFullPath();
    void   printTable(int depth);
    Symbol* is_symbol_defined_in_path(string name);
    Symbol* isLocallyDefined(string name);
    functionNode* isFuncDefined(string name);
    symbolTalbeNode * isClassDefined(string name);

    Symbol* is_user_symbol_defined(generalNode * id );
    TypeNode * check_member_access( generalNode * id, generalNode * member_id );

    int define_symbol(TypeNode* tn, string name, ExpressionNode *value);
    int define_symbol(string name, Symbol* symbol);
    int define_symbol(Symbol* symbol);
    int define_array_symbol(string name,ArrayType* at);
    Symbol* create_temp_symbol(ExpressionNode *value_);
    Symbol* define_user_symbol(generalNode * classId, generalNode * symbolName);
    Symbol* define_user_symbol(generalNode * classId, generalNode * symbolName, myVectorClass * init);

    symbolTalbeNode* addFunction(functionNode * newScope);
    
    symbolTalbeNode * addFunction(string name);
    symbolTalbeNode * addClass(string name);

    void setAsFunction(functionNode * funcNode);
};



#endif