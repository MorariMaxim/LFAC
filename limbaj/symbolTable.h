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
    TypeAndValue *type = nullptr;

    Symbol(string name, TypeAndValue *tv, Expression *init);
    Symbol();
    void setTo(string name, bool is_const, Expression *init); 
    ~Symbol();

    void printSymbol();
    string getSymbolAsString();
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

    SymbolTable *newClass(GeneralInfo *gn);

    SymbolTable *getParent();
    string getFullPath();
    void printTable(int depth);
    Symbol *is_symbol_defined_in_path(string name);
    Symbol *isLocallyDefined(string name);
    FunctionDetails *isFuncDefined(string name);
    SymbolTable *isClassDefined(string name);

    Symbol *is_user_symbol_defined(GeneralInfo *id);
    TypeAndValue *check_member_access(GeneralInfo *id, GeneralInfo *member_id);

    int define_symbol(TypeAndValue *tn, string name, Expression *value);
    int define_symbol(string name, Symbol *symbol);
    int define_symbol(Symbol *symbol);
    int define_array_symbol(string name, ArrayType *at);
    Symbol *create_temp_symbol(Expression *value_);
    Symbol *define_user_symbol(GeneralInfo *classId, GeneralInfo *symbolName);
    Symbol *define_user_symbol(GeneralInfo *classId, GeneralInfo *symbolName, Vector *init);

    SymbolTable *addFunction(FunctionDetails *newScope);

    SymbolTable *addFunction(string name);
    SymbolTable *addClass(string name);

    void setAsFunction(FunctionDetails *funcNode);
};

#endif