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

#define checkSymbol(x) {if ( currentSymbolTable->isSymbolDefinedInPath(x->content)==nullptr) printf("\nsymbol not defined %s at %d:%d\n",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->isSymbolDefinedInPath(x->content)}
#define checkRetType(x) {if (x->type != returnType){printf("incorrect return type");} else printf("correct return type");}
#define checkVoidReturn() {if (returnType != VOID) printf("incorrect return type"); else printf("correct return type");}
#define backtrackScope() {currentSymbolTable = currentSymbolTable->getParent();}
string join_buffer;
//#define join_helper(arg, ...) { join_buffer+=arg; if(__VA_ARGS__ != -1) join_helper(__VA_ARGS__); }
//#define join(arg, ...) {if(__VA_ARGS__ != -1)  join_helper(__VA_ARGS__);  printf("%s\n",join_buffer.c_str());} 
%}

%union {
    class generalNode* node; 
    class typeNode* typenode;
    class expressionNode* exprnode;
    class Symbol * parameterNode;
    class functionNode* funcNode;
    class parameterList* parListNode;
    class functionCall* funcCall;
    class rvalueNode * rvalNode;
    class rValueNodes * rvaluesNode;
    class arrayIndexing * arrayIndexingNode;
    class symbolTalbeNode* classNode; 
    class myVectorClass* container;
}



%token<node>  BGIN END ASSIGN NR ID IF ELSE WHILE FOR  CONST RARROW FN RETURN CLASS
%token<typenode> TYPE 

%type<node>     declaration IF_S IF_B statement statements IF_ELSE_S IF_ELSE_B assignment lval ISCONST ARRAY decls_funcs member_access
%type<exprnode> expr
%type<parameterNode> parameter 
%type<parListNode> parameter_List
%type<funcNode> function_s function 
%type<funcCall> function_call
%type<rvalNode> rval
%type<rvaluesNode> rvalues 
%type <arrayIndexingNode> array_indexing
%type <classNode> class_b class_s
%start progr


%left '+' '-'
%left '*' '/'



%%

progr: statements  { printx("\nsyntactically correct program\n"); }
        |            { printx("\nempty prog\n");}
        ;
statements: statement ';' { $$ = $1; printx("\nstatement -> statement\n");}
        | statements statement ';' { $$ = $1; printx("\nstatement -> statements statement\n");}

statement:
          declaration { printx("\nstmt -> declaration\n");}
        | expr  { printx("\nstmt -> expr\n");}
        | IF_B { printx("\nstmt -> IF_B\n");}
        | IF_ELSE_B { printx("\nstatement -> IF_ELSE_B\n");}
        | function { printx("\nstatement -> function\n"); $$ = $1;}
        | assignment {printx("\nstatement -> assignment\n");}
        | function_call  {printx("statement -> functionCall\n");}
        | array_indexing  {printx("statement -> array_indexing\n");$1->checkIndexes();}
        | class_b {printx("statement -> class_b\n");}
        | member_access   {printx("statement -> member_access\n");}
        ;
        
//declarations: declaration {printx("decls -> decl\n"); $$=$1;}
//        | declarations declaration {printx("decls -> decls decl\n"); $$ = new generalNode($1->content + " " + $2->content); delete $1; delete $2;}
 

declaration:
          ISCONST TYPE ID '=' expr  { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->defineSymbol(1,$2->type,$3->content,$5);  $$ = new generalNode($1->content + " " + $2->content+ " " + $3->content+ " " + $5->content); delete $1; delete $2;delete $3; delete $5;}
        | ISCONST TYPE ID  { printx("\ndecl->const type id;\n");
                                            currentSymbolTable->defineSymbol(1,$2->type,$3->content,nullptr);  $$ = new generalNode("const " + $1->content + " " + $2->content); delete $1; delete $2;delete $3;}
        | TYPE ID '=' expr  { printx("\ndecl->type id init;\n");
                                            currentSymbolTable->defineSymbol(0,$1->type,$2->content,$4);  $$ = new generalNode($1->content + " " + $2->content+ " = " + $4->content); delete $1; delete $2; delete $4;}
        | TYPE ID  { printx("\ndecl->type id;\n");
                                        currentSymbolTable->defineSymbol(0,$1->type,$2->content,nullptr);  $$ = new generalNode($1->content + " " + $2->content); delete $1; delete $2;}        
        | ARRAY  { printx("\ndecl -> array\n");printf("array name : %s\n",$1->content.c_str());arraySymbol * as = arraySymbol::buildFromStack(0);currentSymbolTable->defineSymbol($1->content,as); $$ = $1;}

        | ID ID  {printx("\ndecl -> ID ID ;\n");currentSymbolTable->defineUserSymbol($1,$2); }
        
        ;
ARRAY: TYPE ID '[' NR ']' { printx("\narray -> type id [ nr ]\n"); $$ = $2; arrayType=$1->type; arrayStack.push_back(atoi($4->content.c_str()));}
        | ARRAY '[' NR ']' { printx("\narray -> array [ nr ]\n"); $$ = $1;arrayStack.push_back(atoi($3->content.c_str()));}

array_indexing: ID '[' rval ']' {printx("array_indexing -> ID '[' rval ']'");$$  = new arrayIndexing($1); $$->addRvalue($3); }
        | array_indexing '[' rval ']' {printx("array_indexing -> array_indexing '[' NR ']'"); $$ = $1; $$->addRvalue($3);}
        ;

//functions: function {printx("funcs -> func\n"); $$ = new generalNode($1->name);}
//        | functions function {printx("funcs -> funcs func\n"); $$ = new generalNode($1->content + " " + $2->content); delete $1; }        

function: function_s statement RETURN rval '}' { printx("\nfunction -> function_s statement return rval}\n"); 
                                                backtrackScope();$$ = $1; checkRetType($4);}
        | function_s statement '}' { printx("\nfunction -> function_s statement }\n");  backtrackScope();
                                        $$ = $1; checkVoidReturn();}
        | function_s '}' { printx("\nfunction -> function_s statement }\n");  backtrackScope();
                                        $$ = $1; checkVoidReturn();}                                        
        | FN ID '(' ')' RARROW TYPE  { printx("\nfunctions_s -> FN ID ( ) RARROW TYPE ;\n");$$ = new functionNode($2->content,$6->type,nullptr);}
        | FN ID '(' parameter_List ')' RARROW TYPE 
         { printx("\nfunctions_s -> FN ID ( list ) RARROW TYPE ;\n");$$ = new functionNode($2->content,$7->type,$4->parameters);}
        ;

function_s:
          FN ID '(' ')' RARROW TYPE '{' { printx("\nfunctions_s -> fn id ( ) -> type {\n");$$ = new functionNode($2->content,$6->type,nullptr);
                                        currentSymbolTable = currentSymbolTable->addFunction($$); returnType = $6->type;
                                         }

        | FN ID '(' parameter_List ')' RARROW TYPE '{' { printx("\nfunctions_s -> fn id ( list ) -> type {\n");  $$ = new functionNode($2->content,$7->type,$4->parameters);
                                        currentSymbolTable=  currentSymbolTable->addFunction($$);returnType = $7->type;
                                        }
        ;

function_call: ID '(' rvalues ')' {printx("functioncall -> id ( rvalues )\n");$$ = new functionCall($1->content); $$->setArgs($3); 
                        bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
        |   ID '(' ')'  {printx("functioncall -> id ()\n");$$ = new functionCall($1->content);  
                        bool correct = $$->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
        ;

rvalues: rval {printx("rvalues -> rval\n");$$ = new rValueNodes(); $$->addRvalue($1); }
        | rvalues ',' rval {printx("rvalues -> rvalues , rval\n");$1->addRvalue($3);$$=$1;}
        ;

parameter_List: parameter_List ','  parameter {printx("parameter list -> parameter llist , parameter\n"); $$ = $1; $$->addParameter($3);}
        | parameter {printx("parameter list -> parameter\n");$$ = new parameterList();$$->addParameter($1);}
        ;

parameter: TYPE ID { printx("\nparamter -> type id"); $$ = new Symbol(0,$1->type,$2->content,nullptr);}
        ;

expr:     expr '+' expr { printx("\nexpr -> expr + expr\n");$$ = new expressionNode(operTypes::plus,$1,$3, $1->content +"+" + $3->content); delete $1; delete $3; } 
        | expr '-' expr { printx("\nexpr -> expr - expr\n");$$ = new expressionNode(operTypes::minus,$1,$3, $1->content +"-" + $3->content); delete $1; delete $3; } 
        | ID {printf("expr -> ID\n");$$ = new expressionNode(nullptr, $1->content); delete $1;}; 
        | NR {printf("expr -> NR\n");$$ = new expressionNode(nullptr, $1->content); delete $1;};  
        ;

assignment: lval '=' rval  { $$ = new generalNode($1->content +"=" + $3->content); delete $1; delete $3;}
        ;

lval: ID        {printx("lva -> id\n"); checkSymbol($1);  }
        ;

rval:     NR    {printx("\nrval -> NR\n"); $$ = new intValueNode($1->content);}
        | ID    {printx("\nrval -> ID\n"); checkSymbol($1); Symbol* res = getSymbol($1); 
                 if(res) $$ = new rvalueNode($1->content,res->type); else $$ = new rvalueNode($1->content);}
        ;
ISCONST : CONST {printx("isconst -> const\n");$$ = $1;} 
        ;

IF_S:   IF '(' expr ')' '{'  { printx("\nIF_S -> IF ( expr ) {\n");$$ = new generalNode("IF_S"); delete $1;string expr = "if("; expr+=$3->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}    
    ;

IF_B:   IF_S statement '}' { printx("\nIF_B -> IF_S statement }\n");$$ = new generalNode("IF_B"); backtrackScope();}
    ;        

IF_ELSE_S:  IF_S statement '}' ELSE '{'  { printx("\nIF_ELSE_S -> IF_S statement } ELSE {\n");$$ = new generalNode("IF_ELSE_S"); delete $1; delete $4;string elsescope = "else(" + currentSymbolTable->name+")"; backtrackScope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}    
    ;

IF_ELSE_B: IF_ELSE_S statement '}' { printx("\nIF_ELSE_B -> IF_ESLE_S statement }\n");$$ = new generalNode("IF_ELSE_B"); backtrackScope();}
    ;

class_s: CLASS ID '{' {printx("\nclassb_S-> class id { \n");$$ = currentSymbolTable = currentSymbolTable->newClass($2);}
        ;
decls_funcs: function {printx("\ndecls_funcs -> funcs\n");}
        | declaration  {printx("\ndecls_funcs -> decls\n"); }
        | decls_funcs ';'  declaration {printx("\ndecls_funcs -> decls_funcs declaration\n");  }
        | decls_funcs ';'  function {printx("\ndecls_funcs -> decls_funcs function\n");  }

class_b:  class_s decls_funcs '}' {printx("\nclassb -> class_S decls_funcs } \n"); backtrackScope();}
        | class_s '}' {printx("\nclassb -> class_S } \n");backtrackScope();}
        ;
member_access: ID '.' ID {printx("\nmember_access -> ID . ID \n"); currentSymbolTable->check_member_access($1,$3); $$ = new generalNode("member accsss");}

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