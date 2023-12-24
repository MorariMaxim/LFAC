%{
#include <iostream>
#include <vector>
#include "GeneralInfo.h"
#include "symbolTable.h"

extern FILE* yyin;
extern char* yytext;  
extern int yylex();
SymbolTable * rootSymbolTable;
SymbolTable * currentSymbolTable;
int row, col;

void yyerror(const char * s);
TypeNode * gReturnType;
Expression* return_expression;

#define checkSymbol(x) {if ( currentSymbolTable->is_symbol_defined_in_path(x->content)==nullptr) printf("symbol not defined %s at %d:%d",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->is_symbol_defined_in_path(x->content)}
#define backtrack_scope() {currentSymbolTable = currentSymbolTable->getParent();}
bool treat_return_statement(Expression * val) {

        bool res = true;
        if(currentSymbolTable->type != scopeType::FUNC_SCOPE) {
                printf("return statement in a non-function block");
                res = false;
                goto return_label;
        }

        if(!val)  {
                if(currentSymbolTable->func_details->return_type->type == types::VOID) {
                        goto return_label;                
                }                
                res = false;
                goto return_label;
        }

        {      
        auto val = return_expression->eval();
        auto type = val->type;
        res = Expression::are_types_equal(type,currentSymbolTable->func_details->return_type);
        if(res) {gReturnType = type; printf("changed global gReturnType");}
        }
        
return_label:        

        if(res) printf("correct return value");
        else printf("the type of the return value doesn't match the expected type");


        return res;
}

%}

%union {
    class GeneralInfo* node; 
    class TypeNode* TypeNode;
    class Expression* exprnode;
    class Symbol * symbol_node;
    class FunctionDetails* funcNode;
    class parameterList* parListNode;
    class FunctionCall* funcCall; 
    class ArrayIndexing * arrayIndexingNode;
    class SymbolTable* classNode; 
    class Vector* container;
    class IntType * int_type;
    class IntValue * int_value;
    class ValueNode * value_node;
    class ArrayValue * array_value_node; 
}



%token<node>  BGIN END ASSIGN ID IF ELSE WHILE FOR  CONST RARROW FN RETURN CLASS EVAL INT_TYPE
%token<int_value> INT_NR
%token<TypeNode> BTYPE 

%type<TypeNode> gtype return_type 
%type<node>     class_declaration declaration IF_S IF_B statement statements IF_ELSE_S IF_ELSE_B assignment ISCONST decls_funcs eval_expression function_body
%type<exprnode> expr init return_value
%type<symbol_node> parameter member_access 
%type<funcNode> func_signature function 
%type<funcCall> function_call  
%type <arrayIndexingNode> array_indexing
%type <classNode> class_b class_s
%type <container> id_parameters field_val exprs param_list arguments object_init expressions
%type <value_node> array_element 
%type <array_value_node>   array_value 
%start progr


%left '+' '-'
%left '*' '/'
%right UMINUS




%%

progr: statements  { print_reduction("syntactically correct program"); }
        |            { print_reduction("empty prog");}
        ;
statements: statement  { $$ = $1; print_reduction("statements -> statement");}
        | statements statement  { $$ = $1; print_reduction("statements -> statements statement");}

statement:
          declaration { print_reduction("stmt -> declaration");}
        | expr ';'  { print_reduction("stmt -> expr");}
        | IF_B { print_reduction("stmt -> IF_B");}
        | IF_ELSE_B { print_reduction("statement -> IF_ELSE_B");}
        | function { print_reduction("statement -> function"); $$ = $1;}
        | assignment ';' {print_reduction("statement -> assignment");} 
        | class_b {print_reduction("statement -> class_b");}
        | eval_expression ';' {print_reduction("statement -> eval_expression");} 
        | return_statement {print_reduction("statement -> return statement");} 
        ;

 

return_statement: RETURN return_value {print_reduction("ret_statement -> return return_value "); return_expression = $2; treat_return_statement($2); ignore_after_return_statement = true;}
return_value: expr ';' {$$ = $1;}
        |       ';'{$$=nullptr;}

gtype: ISCONST BTYPE {$$ = $2; $$->is_const = 1;}
        | BTYPE {$$ = $1;}
        //| ID {$$ = new ClassType($1);} maybe to do

init: '=' expr ';'  {$$ = $2;}
        | ';' {$$ = nullptr;}

declaration:
          gtype ID init   { print_reduction("decl->const type id init;");
                                            currentSymbolTable->define_symbol($1,$2->content,$3);  $$ = new GeneralInfo(""); }
        | gtype ID array_indexing init  { print_reduction("decl -> gtype ID array_indexing init");
                                                currentSymbolTable->define_array_symbol($2->content,$1, $3,$4); $$ = $2;}
        | class_declaration ';' {print_reduction(" declaration -> class_declaration ");}



        ;
class_declaration: 
         ID ID  {print_reduction(" dclass_Declaration -> uninitialized ");currentSymbolTable->define_user_symbol($1,$2);}
        
        | ID ID object_init {print_reduction(" dclass_Declaration -> initialized");currentSymbolTable->define_user_symbol($1,$2,$3);}
        
object_init: '(' ')' {$$ = nullptr;}
        | '(' field_val ')' {$$ = $2;}
field_val: ID ':' expr {print_reduction("field_Val -> ID : expr"); $$ = new Vector(); $$->add_element($1);$$->add_element($3);}
        | field_val ',' ID ':' expr {print_reduction("field_Val -> field_val , ID : expr"); $$ = $1; $$->add_element($3);$$->add_element($5);}


expressions: expr {print_reduction("expressions -> expr"); $$ = new Vector();$$->add_element($1);}
        | expressions ',' expr {print_reduction("expressions -> expressions , expr"); $$ = $1;$$->add_element($3);}

array_value: '[' expressions ']' {print_reduction("array_value ->  [ expressions ] "); $$ = new ArrayValue($2);}



array_indexing: '[' expr ']' {print_reduction("array_indexing -> '[' rval ']'");$$  = new ArrayIndexing(); $$->add_index($2); }
        | array_indexing '[' expr ']' {print_reduction("array_indexing -> array_indexing '[' INT_NR ']'"); $$ = $1; $$->add_index($3);}
        ;
array_element: ID array_indexing {print_reduction("array element") ;$$ = currentSymbolTable->symbol_indexing($1,$2);}

function: func_signature function_body{ print_reduction("function -> func_signature statements return rval}");
                                                backtrack_scope();$$ = $1;$$->set_gReturnType(); } 
                                                                        
function_body: statements '}' {print_reduction(" funcbody -> statements }"); $$ = $1;}
        | '}' {print_reduction(" funcbody -> empty }"); $$ = nullptr;}

func_signature:
         FN ID arguments return_type { print_reduction("functions_s -> fn id arguments -> type {"); $$ = new FunctionDetails($2->content,$4,$3);
                                        currentSymbolTable=  currentSymbolTable->addFunction($$);
                                        }
        ;
return_type: RARROW gtype '{' {print_reduction("return_type -> RARROW gtype {"); $$ = $2; $2->print(); }
        | '{'{print_reduction("return_type - -> empty {"); $$ = nullptr;}

function_call : ID '.' id_parameters {print_reduction("FunctionCall -> ID . id_parameters"); $$ = new FunctionCall($1,$3);
                                bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call");}
        |       id_parameters  {print_reduction("FunctionCall -> id_parameters"); $$ = new FunctionCall(nullptr,$1);

                                bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call");}
id_parameters: ID '(' exprs ')' {print_reduction("id_parameters -> id ( rvalues )");$$ = new Vector(); $$->add_element($1);$$->add_element($3); }
        |   ID '(' ')'  {print_reduction("id_parameters -> id ()");$$ = new Vector(); $$->add_element($1);}
        ;

exprs: expr {print_reduction("exprs -> expr");$$ = new Vector(); $$->add_element($1); }
        | exprs ',' expr {print_reduction("exprs -> exprs , expr");$1->add_element($3);$$=$1;}
        ;
arguments: '(' param_list ')' {print_reduction("arguments -> parameter llist"); $$ = $2;}
        | '(' ')' {print_reduction("arguments -> empty"); $$ = nullptr;}

param_list: param_list ','  parameter {print_reduction("parameter list -> parameter llist , parameter"); $$ = $1; $$->add_element($3);}
        |  parameter {print_reduction("parameter list -> parameter");$$ = new Vector();$$->add_element($1);}
        ;

parameter: gtype ID { print_reduction("paramter -> type id"); $$ = new Symbol($2->content,$1,nullptr);}
        ;

expr:     expr '+' expr { print_reduction("expr -> expr + expr");$$ = new Expression(OperTypes::ADD,$1,$3);} 
        | expr '-' expr { print_reduction("expr -> expr - expr");$$ = new Expression(OperTypes::SUB,$1,$3);} 
        | expr '/' expr { print_reduction("expr -> expr / expr");$$ = new Expression(OperTypes::DIV,$1,$3);} 
        | expr '*' expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::MUL,$1,$3);} 
        //| '-' expr %prec UMINUS  { print_reduction("expr -> ( expr ) ");$$ = $2; $$->neg(); }  to do
        | '(' expr ')' { print_reduction("expr -> ( expr ) ");$$ = $2;}  
        | ID {print_reduction("expr -> ID");$$ = new Expression($1->content); delete $1;}; 
        | INT_NR {print_reduction("expr -> INT_NR");$$ = new Expression($1); };  
        | member_access {print_reduction("expr -> member_access");$$ = new Expression($1); };
        | function_call {print_reduction("epxr - function call ");$$ = new Expression($1);}
        | array_element {print_reduction("epxr - array_element ");$$ = new Expression($1);}
        | array_value {print_reduction("epxr - array_value ");$$ = new Expression($1);}

        ;

assignment: 
          ID '=' expr {print_reduction(" ID = expr"); currentSymbolTable->assign($1, $3, nullptr);}
        | ID array_indexing '=' expr {print_reduction(" ID = expr"); currentSymbolTable->assign($1,$4,$2);}
        
 
        ;


ISCONST : CONST {print_reduction("isconst -> const");$$ = $1;} 
        ;

IF_S:   IF '(' expr ')' '{'  { print_reduction("IF_S -> IF ( expr ) {");$$ = new GeneralInfo("IF_S"); delete $1;string expr = "if("; expr+=$3->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}    
    ;

IF_B:   IF_S statements '}' { print_reduction("IF_B -> IF_S statements }");$$ = new GeneralInfo("IF_B"); backtrack_scope();}
    ;        

IF_ELSE_S:  IF_S statements '}' ELSE '{'  { print_reduction("IF_ELSE_S -> IF_S statements } ELSE {");$$ = new GeneralInfo("IF_ELSE_S"); delete $1; delete $4;string elsescope = "else(" + currentSymbolTable->name+")"; backtrack_scope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}    
    ;

IF_ELSE_B: IF_ELSE_S statements '}' { print_reduction("IF_ELSE_B -> IF_ESLE_S statements }");$$ = new GeneralInfo("IF_ELSE_B"); backtrack_scope();}
    ;

class_s: CLASS ID '{' {print_reduction("classb_S-> class id { ");$$ = currentSymbolTable = currentSymbolTable->add_class($2);}
        ;
decls_funcs: function {print_reduction("decls_funcs -> funcs");}
        | declaration  {print_reduction("decls_funcs -> decls"); }
        | decls_funcs declaration  {print_reduction("decls_funcs -> decls_funcs declaration");  }
        | decls_funcs function {print_reduction("decls_funcs -> decls_funcs function");  }

class_b:  class_s decls_funcs '}' {print_reduction("classb -> class_S decls_funcs } "); backtrack_scope();}
        | class_s '}' {print_reduction("classb -> class_S } ");backtrack_scope();}
        ;

member_access: ID '.' ID {print_reduction("member_access -> ID . ID "); $$ = currentSymbolTable->check_member_access($1,$3);}

eval_expression : EVAL '(' expr ')'  {print_reduction("evalexpr -> eval ( expr ) "); $3->eval_wrapper(); }

%%
 
void yyerror(const char * s){
    printf("error: %s at lin/column:%d/%d", s, row,col);
}
 
int main(int argc, char** argv){
        
        col = row = 1; 
        rootSymbolTable = new SymbolTable("global");
        currentSymbolTable = rootSymbolTable;
        yyin = fopen(argv[1], "r");    
        yyparse(); 

        rootSymbolTable->printTable(0);
}

