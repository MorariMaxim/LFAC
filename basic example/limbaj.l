%{
#include <stdio.h>
#include "limbaj.tab.h"
#include "generalNode.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string" { yylval.node = new generalNode(yytext); return TYPE; }
"begin_progr" {return BGIN;}
"end_progr" {return END;}
[a-zA-Z][a-zA-Z0-9]* {yylval.node = new generalNode(yytext); return ID;}
":=" {return ASSIGN;}
[0-9]+ {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
