%{
#include <iostream>
#include <vector>
#include "generalNode.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class generalNode;
%}

%union {
    class generalNode* node ;
    int x;
}

%token<node>  BGIN END ASSIGN NR ID TYPE
%type<node>   declaration
%start progr

%%

progr: declaration {delete $1;}
     ;

declaration: TYPE ID ';' declaration {$$ = new generalNode($1->content +" " + $2->content  +"; " + $4->content); delete $1; delete $2; delete $4;}
               | {$$ = new generalNode("");}
     ;
%%

void yyerror(const char * s){
    printf("error: %s at line:%d\n", s, yylineno);
}

int main(int argc, char** argv){
    yyin = fopen(argv[1], "r");
    yyparse(); 
}
