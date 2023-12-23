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

#define checkSymbol(x) {if ( currentSymbolTable->is_symbol_defined_in_path(x->content)==nullptr) printf("\nsymbol not defined %s at %d:%d\n",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->is_symbol_defined_in_path(x->content)}
#define backtrack_scope() {currentSymbolTable = currentSymbolTable->getParent();}
bool treat_return_statement(Expression * val) {

        bool res = true;
        if(currentSymbolTable->type != scopeType::FUNC_SCOPE) {
                printf("return statement in a non-function block\n");
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
        if(res) {gReturnType = type; printf("changed global gReturnType\n");}
        }
        
return_label:        

        if(res) printf("correct return value\n");
        else printf("the type of the return value doesn't match the expected type\n");


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
}



%token<node>  BGIN END ASSIGN ID IF ELSE WHILE FOR  CONST RARROW FN RETURN CLASS EVAL INT_TYPE
%token<int_value> INT_NR
%token<TypeNode> BTYPE 

%type<TypeNode> gtype return_type 
%type<node>     class_declaration declaration IF_S IF_B statement statements IF_ELSE_S IF_ELSE_B assignment lval ISCONST decls_funcs eval_expression function_body
%type<exprnode> expr init return_value
%type<symbol_node> parameter member_access
%type<funcNode> func_signature function 
%type<funcCall> function_call  
%type <arrayIndexingNode> array_indexing
%type <classNode> class_b class_s
%type <container> id_parameters field_val exprs param_list arguments object_init
%type <value_node> array_element
%start progr


%left '+' '-'
%left '*' '/'
%right UMINUS




%%

progr: statements  { printx("\nsyntactically correct program\n"); }
        |            { printx("\nempty prog\n");}
        ;
statements: statement  { $$ = $1; printx("\nstatements -> statement\n");}
        | statements statement  { $$ = $1; printx("\nstatements -> statements statement\n");}

statement:
          declaration { printx("\nstmt -> declaration\n");}
        | expr ';'  { printx("\nstmt -> expr\n");}
        | IF_B { printx("\nstmt -> IF_B\n");}
        | IF_ELSE_B { printx("\nstatement -> IF_ELSE_B\n");}
        | function { printx("\nstatement -> function\n"); $$ = $1;}
        | assignment ';' {printx("\nstatement -> assignment\n");}
        | array_indexing ';' {printx("statement -> array_indexing\n");$1->check_indexes();}
        | class_b {printx("statement -> class_b\n");}
        | eval_expression ';' {printx("statement -> eval_expression\n");} 
        | return_statement {printx("statement -> return statement\n");} 
        | array_element {$$ = nullptr;}
        ;

 

return_statement: RETURN return_value {printx("\nret_statement -> return return_value \n"); return_expression = $2; treat_return_statement($2); ignore_after_return_statement = true;}
return_value: expr ';' {$$ = $1;}
        |       ';'{$$=nullptr;}

gtype: ISCONST BTYPE {$$ = $2; $$->is_const = 1;}
        | BTYPE {$$ = $1;}
        //| ID {$$ = new ClassType($1);} maybe to do

init: '=' expr ';'  {$$ = $2;}
        | ';' {$$ = nullptr;}

declaration:
          gtype ID init   { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->define_symbol($1,$2->content,$3);  $$ = new GeneralInfo(""); }
        | gtype ID array_indexing init  { printx("\ndecl -> gtype ID array_indexing init\n");
                                                currentSymbolTable->define_array_symbol($2->content,$1, $3); $$ = $2;}
        | class_declaration ';' {printx("\n declaration -> class_declaration \n");}
        
        ;
class_declaration: 
         ID ID  {printx("\n dclass_Declaration -> uninitialized \n");currentSymbolTable->define_user_symbol($1,$2);}
        
        | ID ID object_init {printx("\n dclass_Declaration -> initialized\n");currentSymbolTable->define_user_symbol($1,$2,$3);}
        
object_init: '(' ')' {$$ = nullptr;}
        | '(' field_val ')' {$$ = $2;}
field_val: ID ':' expr {printx("\nfield_Val -> ID : expr\n"); $$ = new Vector(); $$->add_pointer($1);$$->add_pointer($3);}
        | field_val ',' ID ':' expr {printx("\nfield_Val -> field_val , ID : expr\n"); $$ = $1; $$->add_pointer($3);$$->add_pointer($5);}


array_indexing: '[' expr ']' {printx("array_indexing -> '[' rval ']'");$$  = new ArrayIndexing(); $$->add_index($2); }
        | array_indexing '[' expr ']' {printx("array_indexing -> array_indexing '[' INT_NR ']'"); $$ = $1; $$->add_index($3);}
        ;
array_element: ID array_indexing {printx("array element\n") ;$$ = currentSymbolTable->symbol_indexing($1,$2);}
function: func_signature function_body{ printx("\nfunction -> func_signature statements return rval}\n");
                                                backtrack_scope();$$ = $1;$$->set_gReturnType(); } 
                                                                        
function_body: statements '}' {printx("\n funcbody -> statements }\n"); $$ = $1;}
        | '}' {printx("\n funcbody -> empty }\n"); $$ = nullptr;}

func_signature:
         FN ID arguments return_type { printx("\nfunctions_s -> fn id arguments -> type {\n"); $$ = new FunctionDetails($2->content,$4,$3);
                                        currentSymbolTable=  currentSymbolTable->addFunction($$);
                                        }
        ;
return_type: RARROW gtype '{' {printx("\nreturn_type -> RARROW gtype {\n"); $$ = $2; $2->print(); }
        | '{'{printx("\nreturn_type - -> empty {\n"); $$ = nullptr;}

function_call : ID '.' id_parameters {printx("FunctionCall -> ID . id_parameters\n"); $$ = new FunctionCall($1,$3);
                                bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
        |       id_parameters  {printx("FunctionCall -> id_parameters\n"); $$ = new FunctionCall(nullptr,$1);

                                bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
id_parameters: ID '(' exprs ')' {printx("id_parameters -> id ( rvalues )\n");$$ = new Vector(); $$->add_pointer($1);$$->add_pointer($3); }
        |   ID '(' ')'  {printx("id_parameters -> id ()\n");$$ = new Vector(); $$->add_pointer($1);}
        ;

exprs: expr {printx("exprs -> expr\n");$$ = new Vector(); $$->add_pointer($1); }
        | exprs ',' expr {printx("exprs -> exprs , expr\n");$1->add_pointer($3);$$=$1;}
        ;
arguments: '(' param_list ')' {printx("arguments -> parameter llist\n"); $$ = $2;}
        | '(' ')' {printx("arguments -> empty\n"); $$ = nullptr;}

param_list: param_list ','  parameter {printx("parameter list -> parameter llist , parameter\n"); $$ = $1; $$->add_pointer($3);}
        |  parameter {printx("parameter list -> parameter\n");$$ = new Vector();$$->add_pointer($1);}
        ;

parameter: gtype ID { printx("\nparamter -> type id"); $$ = new Symbol($2->content,$1,nullptr);}
        ;

expr:     expr '+' expr { printx("\nexpr -> expr + expr\n");$$ = new Expression(OperTypes::ADD,$1,$3);  } 
        | expr '-' expr { printx("\nexpr -> expr - expr\n");$$ = new Expression(OperTypes::SUB,$1,$3);  } 
        | expr '/' expr { printx("\nexpr -> expr / expr\n");$$ = new Expression(OperTypes::DIV,$1,$3);  } 
        | expr '*' expr { printx("\nexpr -> expr * expr\n");$$ = new Expression(OperTypes::MUL,$1,$3);  } 
        //| '-' expr %prec UMINUS  { printx("\nexpr -> ( expr ) \n");$$ = $2; $$->neg(); }  to do
        | '(' expr ')' { printx("\nexpr -> ( expr ) \n");$$ = $2;}  
        | ID {printf("\nexpr -> ID\n");$$ = new Expression($1->content); delete $1;}; 
        | INT_NR {printf("\nexpr -> INT_NR\n");$$ = new Expression($1); };  
        | member_access {printf("\nexpr -> member_access\n");$$ = new Expression($1); };
        | function_call {printx("\nepxr - function call \n");$$ = new Expression($1);}
        
        ;

assignment: lval '=' expr  { $$ = new GeneralInfo($1->content +"=" + $3->content); delete $1; delete $3;}
        ;

lval: ID        {printx("lval -> id\n"); checkSymbol($1);  }
 
        ;


ISCONST : CONST {printx("isconst -> const\n");$$ = $1;} 
        ;

IF_S:   IF '(' expr ')' '{'  { printx("\nIF_S -> IF ( expr ) {\n");$$ = new GeneralInfo("IF_S"); delete $1;string expr = "if("; expr+=$3->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}    
    ;

IF_B:   IF_S statements '}' { printx("\nIF_B -> IF_S statements }\n");$$ = new GeneralInfo("IF_B"); backtrack_scope();}
    ;        

IF_ELSE_S:  IF_S statements '}' ELSE '{'  { printx("\nIF_ELSE_S -> IF_S statements } ELSE {\n");$$ = new GeneralInfo("IF_ELSE_S"); delete $1; delete $4;string elsescope = "else(" + currentSymbolTable->name+")"; backtrack_scope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}    
    ;

IF_ELSE_B: IF_ELSE_S statements '}' { printx("\nIF_ELSE_B -> IF_ESLE_S statements }\n");$$ = new GeneralInfo("IF_ELSE_B"); backtrack_scope();}
    ;

class_s: CLASS ID '{' {printx("\nclassb_S-> class id { \n");$$ = currentSymbolTable = currentSymbolTable->add_class($2);}
        ;
decls_funcs: function {printx("\ndecls_funcs -> funcs\n");}
        | declaration  {printx("\ndecls_funcs -> decls\n"); }
        | decls_funcs declaration  {printx("\ndecls_funcs -> decls_funcs declaration\n");  }
        | decls_funcs function {printx("\ndecls_funcs -> decls_funcs function\n");  }

class_b:  class_s decls_funcs '}' {printx("\nclassb -> class_S decls_funcs } \n"); backtrack_scope();}
        | class_s '}' {printx("\nclassb -> class_S } \n");backtrack_scope();}
        ;

member_access: ID '.' ID {printx("\nmember_access -> ID . ID \n"); $$ = currentSymbolTable->check_member_access($1,$3);}

eval_expression : EVAL '(' expr ')'  {printx("\nevalexpr -> eval ( expr ) \n"); $3->eval_wrapper(); }

%%
 
void yyerror(const char * s){
    printf("\nerror: %s at lin/column:%d/%d\n", s, row,col);
}
 
int main(int argc, char** argv){
        
        col = row = 1; 
        rootSymbolTable = new SymbolTable("global");
        currentSymbolTable = rootSymbolTable;
        yyin = fopen(argv[1], "r");    
        yyparse(); 

        rootSymbolTable->printTable(0);
}

