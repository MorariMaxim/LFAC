#ifndef symbolTable_H
#define symbolTable_H
#include "commonIncludes.h"
#include <unordered_set>
class Symbol
{
public:
    string name;
    bool is_const;
    bool is_init;
    TypeNode *type = nullptr;
    ValueNode* value = nullptr;

    Symbol(string name, TypeNode *tv, Expression *init);
    Symbol(string name, TypeNode *tv, bool is_const, bool is_init);
    Symbol();
    Symbol(Symbol * other);
    void setTo(string name, bool is_const, Expression *init); 
    ~Symbol();

    void print();
    string to_string(); 

    ValueNode * at(ArrayIndexing * indexing);
    AssignResult assign(ValueNode * val);
    AssignResult assign(ArrayIndexing *indexing, ValueNode * val);
};

class SymbolTable
{
public:
    string name;
    visibilityType visibility;
    scopeType type;
    SymbolTable *parent = nullptr;
    FunctionDetails *func_details; // case in which the scope is a function

    vector<SymbolTable *> children;
    SymbolTable *addScope(string name);
    unordered_map<string, Symbol *> symbols;
    unordered_map<string, SymbolTable *> functions;
    unordered_map<string, SymbolTable *> classes;
    unordered_map<string, SymbolTable *> other;

    unordered_set<Symbol *> temp_symbols;

    SymbolTable(string name);

    SymbolTable *add_class(GeneralInfo *gn);

    SymbolTable *getParent();
    string getFullPath();
    void printTable(int depth);
    Symbol *is_symbol_defined_in_path(string name);
    Symbol *isLocallyDefined(string name);
    FunctionDetails *isFuncDefined(string name);
    SymbolTable *isClassDefined(string name);
    
    Symbol *is_user_symbol_defined(GeneralInfo *id);
    Symbol *check_member_access(GeneralInfo *id, GeneralInfo *member_id);

    int define_symbol(TypeNode *tn, string name, Expression *value);
    int define_symbol(string name, Symbol *symbol);
    int define_symbol(Symbol *symbol); 
    Symbol* define_array_symbol(string name, TypeNode * type, ArrayIndexing * indexing, Expression * init); 
    Symbol *define_user_symbol(GeneralInfo *classId, GeneralInfo *symbolName);
    Symbol *define_user_symbol(GeneralInfo *classId, GeneralInfo *symbolName, Vector *init);

    SymbolTable *addFunction(FunctionDetails *newScope);

    SymbolTable *addFunction(string name); 

    void setAsFunction(FunctionDetails *funcNode); 

    bool insert_symbol(Symbol * sym);
    bool insert_symbol(SymbolTable * st);
    
    ValueNode* symbol_indexing(GeneralInfo * id, ArrayIndexing * indexing);
  
    bool assign(GeneralInfo * id, Expression * val, ArrayIndexing * indexing);
    bool assign(GeneralInfo * id, GeneralInfo * member, Expression * val);

    bool check_assign_result(AssignResult res, Symbol * id, ValueNode * rval );
};

#endif