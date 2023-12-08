%{
#include <stdio.h>
#include "limbaj.tab.h"
#include "generalNode.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string" { yylval.node = new typeNode(yytext, types::FLOAT); return TYPE; }
"begin_progr" {yylval.node = new generalNode(yytext);return BGIN;}
"end_progr" {yylval.node = new generalNode(yytext);return END;}
[a-zA-Z][a-zA-Z0-9]* {yylval.node = new generalNode(yytext); return ID;}
":=" {yylval.node = new generalNode(yytext);return ASSIGN;}
[0-9]+ {yylval.node = new generalNode(yytext);return NR;}
[ \t] ;
\n {yylineno++;}
. {yylval.node = new generalNode(yytext);return yytext[0];}
