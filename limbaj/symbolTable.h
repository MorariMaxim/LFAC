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
    ValueNode *value = nullptr;

    Symbol(string name, TypeNode *tv, Expression *init);
    Symbol(string name, TypeNode *tv, bool is_const, bool is_init);
    Symbol();
    Symbol(Symbol *other); 
    ~Symbol();

    void print();
    string to_string();

    ValueNode *at(ArrayIndexing *indexing);
    AssignResult assign(ValueNode *val);
    AssignResult assign(ArrayIndexing *indexing, ValueNode *val);


    Span * span = nullptr;
    void set_span(Span* other);
    void set_span(Span* start,Span * end);
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

    SymbolTable *add_class(RawNode *gn);

    SymbolTable *getParent();
    string getFullPath();
    void printTable();
    void printTable(string path);
    string to_string(int depth = 0);
    Symbol *is_symbol_defined_in_path(string name);
    Symbol *isLocallyDefined(string name);
    FunctionDetails *isFuncDefined(string name);
    SymbolTable *isClassDefined(string name);

    Symbol *is_user_symbol_defined(RawNode *id);
    Symbol *check_member_access(RawNode *id, RawNode *member_id);

    int declare_symbol(TypeNode *tn, RawNode * id, Expression *value);     
    Symbol *declare_array_symbol(RawNode * id, TypeNode *type, ArrayIndexing *indexing, Expression *init);
    Symbol *declare_user_symbol(RawNode *classId, RawNode *symbolName);
    Symbol *declare_user_symbol(RawNode *classId, RawNode *symbolName, Vector *init);

    SymbolTable *addFunction(FunctionDetails *newScope); 

    void setAsFunction(FunctionDetails *funcNode);

    bool insert_symbol(Symbol *sym);
    bool insert_symbol(SymbolTable *st);

    ValueNode *symbol_indexing(RawNode *id, ArrayIndexing *indexing);

    bool assign(RawNode *id, Expression *val, ArrayIndexing *indexing); 
    bool assign(Symbol *sym, Expression *expr, ArrayIndexing *indexing);

    bool check_assign_result(AssignResult res, Symbol *id, ValueNode *rval);

    Span * span = nullptr;

    void set_span(Span* other);
};

#endif