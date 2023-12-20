%{
#include <iostream>
#include <vector>
#include "generalNode.h"
#include "symbolTable.h"

extern FILE* yyin;
extern char* yytext;  
extern int yylex();
symbolTalbeNode * rootSymbolTable ;
symbolTalbeNode * currentSymbolTable;
int row, col;
void yyerror(const char * s);
vector<int> arrayStack;
types arrayType;
class generalNode; 
types returnType;

#define checkSymbol(x) {if ( currentSymbolTable->is_symbol_defined_in_path(x->content)==nullptr) printf("\nsymbol not defined %s at %d:%d\n",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->is_symbol_defined_in_path(x->content)}
#define checkRetType(x) {if (x->type != returnType){printf("incorrect return type");} else printf("correct return type");}
#define checkVoidReturn() {if (returnType != VOID) printf("incorrect return type"); else printf("correct return type");}
#define backtrackScope() {currentSymbolTable = currentSymbolTable->getParent();}
string join_buffer;
//#define join_helper(arg, ...) { join_buffer+=arg; if(__VA_ARGS__ != -1) join_helper(__VA_ARGS__); }
//#define join(arg, ...) {if(__VA_ARGS__ != -1)  join_helper(__VA_ARGS__);  printf("%s\n",join_buffer.c_str());} 
%}

%union {
    class generalNode* node; 
    class TypeNode* TypeNode;
    class ExpressionNode* exprnode;
    class Symbol * parameterNode;
    class functionNode* funcNode;
    class parameterList* parListNode;
    class functionCall* funcCall;
    class rvalueNode * rvalNode;
    class rValueNodes * rvaluesNode;
    class arrayIndexing * arrayIndexingNode;
    class symbolTalbeNode* classNode; 
    class myVectorClass* container;
    class IntType * int_type_node;
}



%token<node>  BGIN END ASSIGN ID IF ELSE WHILE FOR  CONST RARROW FN RETURN CLASS EVAL
%token<int_type_node> INT_NR
%token<TypeNode> TYPE 

%type<TypeNode> const_type member_access
%type<node>     class_declaration declaration IF_S IF_B statement statements IF_ELSE_S IF_ELSE_B assignment lval ISCONST ARRAY decls_funcs eval_expression
%type<exprnode> expr init
%type<parameterNode> parameter 
%type<parListNode> parameter_List
%type<funcNode> function_s function 
%type<funcCall> function_call 
%type<rvalNode> rval
%type<rvaluesNode> rvalues 
%type <arrayIndexingNode> array_indexing
%type <classNode> class_b class_s
%type <container> id_parameters field_val
%start progr


%left '+' '-'
%left '*' '/'



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
        | function_call ';'  {printx("statement -> functionCall\n");}
        | array_indexing ';' {printx("statement -> array_indexing\n");$1->checkIndexes();}
        | class_b {printx("statement -> class_b\n");}
        | eval_expression ';' {printx("statement -> eval_expression\n");} 
        ;

// need to refactor code
const_type: ISCONST TYPE {$$ = $2; $$->is_const = 1;}
        | TYPE 
init: '=' expr ';'  {$$ = $2;}
        | ';' {$$ = nullptr;}

declaration:
           const_type ID init   { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->define_symbol($1,$2->content,$3);  $$ = new generalNode(""); delete $1; delete $2; delete $3;}                                            
        | ARRAY  ';'  { printx("\ndecl -> array\n");printf("array name : %s\n",$1->content.c_str());ArrayType * at = new ArrayType("",0);currentSymbolTable->define_array_symbol($1->content,at); $$ = $1;}
        | class_declaration ';' {printx("\n declaration -> class_declaration \n");}
        ;
class_declaration: 
         ID ID  {printx("\n dclass_Declaration -> uninitialized \n");currentSymbolTable->define_user_symbol($1,$2);}
        
        | ID ID '(' field_val ')' {printx("\n dclass_Declaration -> initialized\n");currentSymbolTable->define_user_symbol($1,$2,$4);}
        
field_val: ID ':' expr {printx("\nfield_Val -> ID : expr\n"); $$ = new myVectorClass(); $$->add_pointer($1);$$->add_pointer($3);}
        | field_val ',' ID ':' expr {printx("\nfield_Val -> field_val , ID : expr\n"); $$ = $1; $$->add_pointer($3);$$->add_pointer($5);}



ARRAY: const_type ID '[' INT_NR ']' { printx("\narray -> type id [ INT_NR ]\n"); $$ = $2; /*arrayType=$1->type; arrayStack.push_back($4->value);*/}
        | ARRAY '[' INT_NR ']' { printx("\narray -> array [ INT_NR ]\n"); $$ = $1;arrayStack.push_back($3->value);}

array_indexing: ID '[' rval ']' {printx("array_indexing -> ID '[' rval ']'");$$  = new arrayIndexing($1); $$->addRvalue($3); }
        | array_indexing '[' rval ']' {printx("array_indexing -> array_indexing '[' INT_NR ']'"); $$ = $1; $$->addRvalue($3);}
        ;

function: function_s statements RETURN rval '}' { printx("\nfunction -> function_s statements return rval}\n"); 
                                                backtrackScope();$$ = $1; checkRetType($4);}
        | function_s statements '}' { printx("\nfunction -> function_s statements }\n");  backtrackScope();
                                        $$ = $1; checkVoidReturn();}
        | function_s '}' { printx("\nfunction -> function_s }\n");  backtrackScope();
                                        $$ = $1; checkVoidReturn();}                                        
        | FN ID '(' ')' RARROW const_type  { printx("\nfunctions_s -> FN ID ( ) RARROW const_type ;\n");$$ = new functionNode($2->content,$6->type,nullptr);}
        | FN ID '(' parameter_List ')' RARROW const_type 
         { printx("\nfunctions_s -> FN ID ( list ) RARROW const_type ;\n");$$ = new functionNode($2->content,$7->type,$4->parameters);}
        ;

function_s:
          FN ID '(' ')' RARROW const_type '{' { printx("\nfunctions_s -> fn id ( ) -> type {\n");$$ = new functionNode($2->content,$6->type,nullptr);
                                        currentSymbolTable = currentSymbolTable->addFunction($$); returnType = $6->type;
                                         }

        | FN ID '(' parameter_List ')' RARROW const_type '{' { printx("\nfunctions_s -> fn id ( list ) -> type {\n");  $$ = new functionNode($2->content,$7->type,$4->parameters);
                                        currentSymbolTable=  currentSymbolTable->addFunction($$);returnType = $7->type;
                                        }
        ;
function_call : ID '.' id_parameters {printx("functioncall -> ID . id_parameters\n"); $$ = new functionCall($1,$3);
                                bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
        |       id_parameters  {printx("functioncall -> id_parameters\n"); $$ = new functionCall(nullptr,$1); 

                                bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
id_parameters: ID '(' rvalues ')' {printx("id_parameters -> id ( rvalues )\n");$$ = new myVectorClass(); $$->add_pointer($1);$$->add_pointer($3); } 
        |   ID '(' ')'  {printx("id_parameters -> id ()\n");$$ = new myVectorClass(); $$->add_pointer($1);}
        ;

rvalues: rval {printx("rvalues -> rval\n");$$ = new rValueNodes(); $$->addRvalue($1); }
        | rvalues ',' rval {printx("rvalues -> rvalues , rval\n");$1->addRvalue($3);$$=$1;}
        ;

parameter_List: parameter_List ','  parameter {printx("parameter list -> parameter llist , parameter\n"); $$ = $1; $$->addParameter($3);}
        | parameter {printx("parameter list -> parameter\n");$$ = new parameterList();$$->addParameter($1);}
        ;

parameter: const_type ID { printx("\nparamter -> type id"); $$ = new Symbol(0,$1->type,$2->content,nullptr);}
        ;

expr:     expr '+' expr { printx("\nexpr -> expr + expr\n");$$ = new ExpressionNode(OperTypes::ADD,$1,$3, $1->content +"+" + $3->content);  } 
        | expr '-' expr { printx("\nexpr -> expr - expr\n");$$ = new ExpressionNode(OperTypes::SUB,$1,$3, $1->content +"-" + $3->content);  } 
        | expr '/' expr { printx("\nexpr -> expr / expr\n");$$ = new ExpressionNode(OperTypes::DIV,$1,$3, $1->content +"/" + $3->content);  } 
        | expr '*' expr { printx("\nexpr -> expr * expr\n");$$ = new ExpressionNode(OperTypes::MUL,$1,$3, $1->content +"*" + $3->content);  } 
        | ID {printf("\nexpr -> ID\n");$$ = new ExpressionNode($1->content); delete $1;}; 
        | INT_NR {printf("\nexpr -> INT_NR\n");$$ = new ExpressionNode($1); };  
        | member_access {printf("\nexpr -> member_access\n");$$ = new ExpressionNode($1); };  
        
        ;

assignment: lval '=' rval  { $$ = new generalNode($1->content +"=" + $3->content); delete $1; delete $3;}
        ;

lval: ID        {printx("lval -> id\n"); checkSymbol($1);  }
 
rval:   
         expr    {printx("\nrval -> expression\n"); Symbol* _res = currentSymbolTable->create_temp_symbol($1);
                 $$ = new IntType($1->content);}
        ;
ISCONST : CONST {printx("isconst -> const\n");$$ = $1;} 
        ;

IF_S:   IF '(' expr ')' '{'  { printx("\nIF_S -> IF ( expr ) {\n");$$ = new generalNode("IF_S"); delete $1;string expr = "if("; expr+=$3->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}    
    ;

IF_B:   IF_S statements '}' { printx("\nIF_B -> IF_S statements }\n");$$ = new generalNode("IF_B"); backtrackScope();}
    ;        

IF_ELSE_S:  IF_S statements '}' ELSE '{'  { printx("\nIF_ELSE_S -> IF_S statements } ELSE {\n");$$ = new generalNode("IF_ELSE_S"); delete $1; delete $4;string elsescope = "else(" + currentSymbolTable->name+")"; backtrackScope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}    
    ;

IF_ELSE_B: IF_ELSE_S statements '}' { printx("\nIF_ELSE_B -> IF_ESLE_S statements }\n");$$ = new generalNode("IF_ELSE_B"); backtrackScope();}
    ;

class_s: CLASS ID '{' {printx("\nclassb_S-> class id { \n");$$ = currentSymbolTable = currentSymbolTable->newClass($2);}
        ;
decls_funcs: function {printx("\ndecls_funcs -> funcs\n");}
        | declaration  {printx("\ndecls_funcs -> decls\n"); }
        | decls_funcs declaration ';' {printx("\ndecls_funcs -> decls_funcs declaration\n");  }
        | decls_funcs function {printx("\ndecls_funcs -> decls_funcs function\n");  }

class_b:  class_s decls_funcs '}' {printx("\nclassb -> class_S decls_funcs } \n"); backtrackScope();}
        | class_s '}' {printx("\nclassb -> class_S } \n");backtrackScope();}
        ;

member_access: ID '.' ID {printx("\nmember_access -> ID . ID \n"); $$ = currentSymbolTable->check_member_access($1,$3);}

eval_expression : EVAL '(' expr ')'  {printx("\nevalexpr -> eval ( expr ) \n"); $3->eval_wrapper(); }

%%
 
void yyerror(const char * s){
    printf("\nerror: %s at lin/column:%d/%d\n", s, row,col);
}
 
int main(int argc, char** argv){
 
        col = row = 1; 
        rootSymbolTable = new symbolTalbeNode("global");
        currentSymbolTable = rootSymbolTable;
        yyin = fopen(argv[1], "r");    
        yyparse(); 

        rootSymbolTable->printTable(0);
}

