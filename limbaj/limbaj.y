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
int gRow, gCol;
Span gTempSpan;

void yyerror(const char * s); 
Expression* gReturnExpr = nullptr;

#define backtrack_scope() {currentSymbolTable = currentSymbolTable->getParent();}
#define check_main(f) {if(f->name != "main" ) semantic_error("no main function");  }
bool treat_return_statement(Expression * val) { 

        gTempSpan.start.row = gRow;
        gTempSpan.start.col = gCol;
        if(gReturnExpr) delete gReturnExpr ; 
        gReturnExpr = nullptr;

        if(currentSymbolTable->type != scopeType::FUNC_SCOPE) {
                semantic_error("line %d... return statement in a non-function block",gRow);                
                return false;
        }
        gReturnExpr = val;        
        return true;
}

%}

%union {
    class Span * spanned;    
    class RawNode* node; 
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
    class FloatValue * float_value;
    class ValueNode * value_node;
    class ArrayValue * array_value_node; 
}

%token<spanned>  '{' '}' '[' ']' ';' ',' '(' ')' 
%token<node>  BGIN END ASSIGN ID IF ELSE WHILE FOR  CONST RARROW FN RETURN CLASS EVAL TYPEOF CLASS_SECTION GLOBAL_FUNCTIONS GLOBAL_VARIABLES MAIN_FUNCTION LORT LANDT LNOTT EQT NEQT LEQT GEQT 
%token<TypeNode> BTYPE FLOAT_TYPE INT_TYPE BOOL_TYPE STRING_TYPE CHAR_TYPE
%token <value_node> INTVAL FLOATVAL BOOLVAL STRINGVAL CHARVAL

%type<TypeNode> gtype return_type 
%type<node>     class_declaration declaration if_s if_b statement statements if_else_b if_else_s  assignment ISCONST decls_funcs eval_expression typeof_expression function_body class_section global_variables global_functions main while_s while_b  
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


%left LORT
%left LANDT
%left EQT NEQT
%left '>' GEQT
%left '<' LEQT
%left '+' '-'
%left '*' '/'

%right LNOTT
%right UMINUS




%%

progr: class_section global_variables global_functions main  { print_reduction("syntactically correct program"); }
        |            { print_reduction("empty prog");}
        ;
statements: statement  { $$ = $1; print_reduction("statements -> statement");}
        | statements statement  { $$ = $1; print_reduction("statements -> statements statement");}

statement:
          declaration { print_reduction("stmt -> declaration");}
        | expr ';'  { print_reduction("stmt -> expr");}
        | if_b { print_reduction("stmt -> IF_B");}
        | if_else_b { print_reduction("statement -> IF_ELSE_B");}
        | function { print_reduction("statement -> function"); $$ = $1;}
        | assignment ';' {print_reduction("statement -> assignment");} 
        | eval_expression ';' {print_reduction("statement -> eval_expression");} 
        | typeof_expression ';' {print_reduction("statement -> typeof_expression");} 
        | return_statement {print_reduction("statement -> return statement");} 
        | while_b {print_reduction("statement -> while_b");}
        | for_b {print_reduction("statement -> for_b");}
        ;

class_section: CLASS_SECTION 
        | class_section class_b 

global_variables: GLOBAL_VARIABLES
        | global_variables declaration

global_functions: GLOBAL_FUNCTIONS
        | global_functions function

main:   MAIN_FUNCTION function {check_main($2);}


return_statement: RETURN return_value {print_reduction("ret_statement -> return return_value "); treat_return_statement($2); ignore_after_return_statement = true;}
return_value: expr ';' {$$ = $1;}
        |       ';'{$$=nullptr;}

gtype: ISCONST BTYPE {$$ = $2; $$->is_const = 1;}
        | BTYPE {$$ = $1;}
        //| ID {$$ = new ClassType($1);} maybe to do

init: '=' expr ';'  {$$ = $2;}
        | ';' {$$ = nullptr;}

declaration:
          gtype ID init   { print_reduction("decl->const type id init;");
                                            currentSymbolTable->declare_symbol($1,$2,$3);  $$ = new RawNode("");}
        | gtype ID array_indexing init  { print_reduction("decl -> gtype ID array_indexing init");
                                                currentSymbolTable->declare_array_symbol($2,$1, $3,$4); $$ = $2;}
        | class_declaration ';' {print_reduction(" declaration -> class_declaration ");}
        ;



class_declaration: 
         ID ID  {print_reduction(" dclass_Declaration -> uninitialized ");currentSymbolTable->declare_user_symbol($1,$2);}
        
        | ID ID object_init {print_reduction(" dclass_Declaration -> initialized");currentSymbolTable->declare_user_symbol($1,$2,$3);}
        
object_init: '(' ')' {$$ = nullptr;}
        | '(' field_val ')' {$$ = $2;}
field_val: ID ':' expr {print_reduction("field_Val -> ID : expr"); $$ = new Vector(); $$->add_element($1);$$->add_element($3);}
        | field_val ',' ID ':' expr {print_reduction("field_Val -> field_val , ID : expr"); $$ = $1; $$->add_element($3);$$->add_element($5);}


expressions: expr {print_reduction("expressions -> expr"); $$ = new Vector();$$->add_element($1);}
        | expressions ',' expr {print_reduction("expressions -> expressions , expr"); $$ = $1;$$->add_element($3);}

array_value: '[' expressions ']' {print_reduction("array_value ->  [ expressions ] "); $$ = new ArrayValue($2);}



array_indexing: '[' expr ']' {print_reduction("array_indexing -> '[' rval ']'");$$  = new ArrayIndexing(); $$->add_index($2); }
        | array_indexing '[' expr ']' {print_reduction("array_indexing -> array_indexing '[' INTVAL ']'"); $$ = $1; $$->add_index($3);}
        ;

array_element: ID array_indexing {print_reduction("array element") ;$$ = currentSymbolTable->symbol_indexing($1,$2);}

function: func_signature function_body{ print_reduction("function -> func_signature boddy}");
                        backtrack_scope();$$ = $1; $$->defined = true; $$->check_return_type();$$->set_lines($1,$2);}
        | func_signature ';' { print_reduction("function -> func_signature }");
                        backtrack_scope();$$ = $1;}
                                                                        
function_body: '{' statements '}' {print_reduction(" funcbody -> statements }"); $$ = $2; $$->set_span($3);}
        | '{' '}' {print_reduction(" funcbody -> empty }"); $$ = new RawNode();$$->set_span($2);}

func_signature:
         FN ID arguments return_type { print_reduction("functions_s -> fn id arguments -> type {"); $$ = new FunctionDetails($2->content,$4,$3); $$->set_span($2); ;
                                        currentSymbolTable=  currentSymbolTable->addFunction($$); currentSymbolTable->set_span($2);
                                        }
        ;
return_type: ')' RARROW gtype  {print_reduction("return_type -> RARROW gtype "); $$ = $3; }
        | ')' {print_reduction("return_type - -> empty {"); $$ = nullptr;}

function_call : ID '.' id_parameters {print_reduction("FunctionCall -> ID . id_parameters"); $$ = new FunctionCall($1,$3);
                                bool correct = $$->checkCall();if(!correct)  semantic_error("incorrect call");}
        |       id_parameters  {print_reduction("FunctionCall -> id_parameters"); $$ = new FunctionCall(nullptr,$1);
                                bool correct = $$->checkCall();if(!correct)  semantic_error("incorrect call");}
id_parameters: ID '(' exprs ')' {print_reduction("id_parameters -> id ( rvalues )");$$ = new Vector(); $$->add_element($1);$$->add_element($3); }
        |   ID '(' ')'  {print_reduction("id_parameters -> id ()");$$ = new Vector(); $$->add_element($1);}
        ;

exprs: expr {print_reduction("exprs -> expr");$$ = new Vector(); $$->add_element($1); }
        | exprs ',' expr {print_reduction("exprs -> exprs , expr");$1->add_element($3);$$=$1;}
        ;
arguments: '(' param_list  {print_reduction("arguments -> parameter llist"); $$ = $2;}
        | '('  {print_reduction("arguments -> empty"); $$ = nullptr;}

param_list: param_list ','  parameter {print_reduction("parameter list -> parameter llist , parameter"); $$ = $1; $$->add_element($3);}
        |  parameter {print_reduction("parameter list -> parameter");$$ = new Vector();$$->add_element($1);}
        ;

parameter: gtype ID { print_reduction("paramter -> type id"); $$ = new Symbol($2->content,$1,nullptr);}
        ;

expr:     expr '+' expr { print_reduction("expr -> expr + expr");$$ = new Expression(OperTypes::ADD,$1,$3);}
        | expr '-' expr { print_reduction("expr -> expr - expr");$$ = new Expression(OperTypes::SUB,$1,$3);} 
        | expr '/' expr { print_reduction("expr -> expr / expr");$$ = new Expression(OperTypes::DIV,$1,$3);} 
        | expr '*' expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::MUL,$1,$3);} 

        | expr LORT expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::LOR,$1,$3);} 
        | expr LANDT expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::LAND,$1,$3);} 
        | LNOTT expr %prec UMINUS  { print_reduction("expr -> ! expr");$$ = new Expression(OperTypes::LNOT,$2,nullptr);}  
        | expr EQT expr { print_reduction("expr -> expr == expr");$$ = new Expression(OperTypes::EQ,$1,$3);} 
        | expr NEQT expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::NEQ,$1,$3);} 
        | expr '<' expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::LE,$1,$3);} 
        | expr LEQT expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::LEQ,$1,$3);} 
        | expr '>' expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::GE,$1,$3);} 
        | expr GEQT expr { print_reduction("expr -> expr * expr");$$ = new Expression(OperTypes::GEQ,$1,$3);} 

        | '-' expr %prec UMINUS  { print_reduction("expr -> - expr");$$ = new Expression(OperTypes::NEG,$2,nullptr);}  
        | '+' expr %prec UMINUS  { print_reduction("expr -> + expr");$$ = $2;}  
        | '(' expr ')' { print_reduction("expr -> ( expr ) ");$$ = $2;$$->set_span_start($1);$$->set_span_end($3);$1->print_span();$3->print_span();}  
        | ID {print_reduction("expr -> ID");$$ = new Expression($1); delete $1;};
        | INTVAL {print_reduction("expr -> INTVAL");$$ = new Expression($1); };  
        | FLOATVAL {print_reduction("expr -> FLOATVAL");$$ = new Expression($1); };  
        | STRINGVAL {print_reduction("expr -> STRINGVAL");$$ = new Expression($1); };  
        | BOOLVAL {print_reduction("expr -> BOOLVAL");$$ = new Expression($1); };  
        | CHARVAL {print_reduction("expr -> CHARVAL");$$ = new Expression($1); };  
        | member_access {print_reduction("expr -> member_access");$$ = new Expression($1); };
        | function_call {print_reduction("epxr - function call ");$$ = new Expression($1);}
        | array_element {print_reduction("epxr - array_element ");$$ = new Expression($1);}
        | array_value {print_reduction("epxr - array_value ");$$ = new Expression($1);}

        ;

assignment: 
          ID '=' expr {print_reduction(" ID = expr"); currentSymbolTable->assign($1, $3, nullptr);}
        | ID array_indexing '=' expr {print_reduction(" ID = expr"); currentSymbolTable->assign($1,$4,$2);}
        | member_access '=' expr {print_reduction(" member_access = expr"); currentSymbolTable->assign($1,$3,nullptr);}
 
        ;


ISCONST : CONST {print_reduction("isconst -> const");$$ = $1;} 
        ;

if_s:   IF '(' expr ')' '{'  { print_reduction("IF_S -> IF ( expr ) {");$$ = new RawNode("IF_S"); delete $1; currentSymbolTable = currentSymbolTable->addScope("if");}
    ;

if_b:   if_s statements '}' { print_reduction("IF_B -> IF_S statements }");$$ = new RawNode("IF_B"); backtrack_scope();}
        | if_s  '}' { print_reduction("IF_B -> IF_S  }");$$ = new RawNode("IF_B"); backtrack_scope();}
    ;        

if_else_s:  if_b ELSE '{'  { print_reduction("IF_ELSE_S -> if_b ELSE {");$$ = new RawNode("IF_ELSE_S"); delete $1; delete $2; delete $3; currentSymbolTable = currentSymbolTable->addScope("else");}    
    ;

if_else_b: if_else_s statements '}' { print_reduction("IF_ELSE_B -> if_else_s { statements } ");$$ = new RawNode("IF_ELSE_B"); backtrack_scope();}
        |  if_else_s '}' { print_reduction("IF_ELSE_B -> if_else_s { } ");$$ = new RawNode("IF_ELSE_B"); backtrack_scope();}
    ;

while_s: WHILE '(' expr ')' '{' {currentSymbolTable = currentSymbolTable->addScope("while"); }

while_b: while_s '}' {backtrack_scope();}
        | while_s statements '}'{backtrack_scope();}

for_b: for_s2 '}' {backtrack_scope();}
        | for_s2 statements '}'{backtrack_scope();}

for_s1: FOR { {print_reduction("for_s1 -> FOR");} currentSymbolTable = currentSymbolTable->addScope("for"); }

for_s2: for_s1 '(' for_d for_c for_st '{'

for_d: declaration {print_reduction("for_d -> declaration ;");}
        | ';'   {print_reduction("for_d -> ;");}
for_c: expr ';' {print_reduction("for_c -> expr ;");}
        | ';'{print_reduction("for_c -> ;");}
for_st: statements ')'
        | ')'



class_s: CLASS ID '{' {print_reduction("classb_S-> class id { ");$$ = currentSymbolTable = currentSymbolTable->add_class($2);}
        ;
decls_funcs: function {print_reduction("decls_funcs -> funcs");}
        | declaration  {print_reduction("decls_funcs -> decls"); }
        | decls_funcs declaration  {print_reduction("decls_funcs -> decls_funcs declaration");  }
        | decls_funcs function {print_reduction("decls_funcs -> decls_funcs function");  }

class_b:  class_s decls_funcs '}' {print_reduction("classb -> class_S decls_funcs } "); backtrack_scope();}
        | class_s '}' {print_reduction("classb -> class_S } ");backtrack_scope();}
        ;

member_access: ID '.' ID {print_reduction("member_access -> ID . ID "); $$ = currentSymbolTable->check_member_access($1,$3);$$->set_span($1,$3);}

eval_expression : EVAL '(' expr ')'  {print_reduction("evalexpr -> eval ( expr ) "); $3->eval_wrapper(1); }

typeof_expression : TYPEOF '(' expr ')' {print_reduction("typeof_expression -> typeof ( expr ) "); $3->eval_wrapper(0); }

%%

void yyerror(const char * s){
    printf("error: %s at lin/column:%d/%d", s, gRow,gCol);
}
 
int main(int argc, char** argv){ 
        gCol = gRow = 1; 
        rootSymbolTable = new SymbolTable("global");
        currentSymbolTable = rootSymbolTable;
        yyin = fopen(argv[1], "r");    
        yyparse(); 

        rootSymbolTable->printTable("table.txt");
}

