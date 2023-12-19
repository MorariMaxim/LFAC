%{
#include <stdio.h>
#include "limbaj.tab.h"
#include "generalNode.h" 
visibilityType currentVisibility = PUBLIC;

%}
%option noyywrap
%%
"->" {printx("->"); yylval.node = new generalNode(yytext);col+=yyleng; return RARROW;}
"fn" {printx("fn");yylval.node = new generalNode(yytext);col+=yyleng; return FN;}
"class" {printx("class");yylval.node = new generalNode(yytext);col+=yyleng; return CLASS;}
"private:" {printx("private:");yylval.node = new generalNode(yytext);col+=yyleng; }
"public:" {printx("public:");yylval.node = new generalNode(yytext);col+=yyleng; }
"if" {printx("if");yylval.node = new generalNode(yytext);col+=yyleng; return IF;}
"return" {printx("if");yylval.node = new generalNode(yytext);col+=yyleng; return RETURN;}
"while" {yylval.node = new generalNode(yytext);col+=yyleng; return WHILE;}
"for" {yylval.node = new generalNode(yytext);col+=yyleng; return FOR;}
"else" {yylval.node = new generalNode(yytext);col+=yyleng; return ELSE;}
"const" {yylval.node = new generalNode(yytext);col+=yyleng; return CONST;}


"int"|"float"|"char"|"string"|"void" {printx("type"); yylval.typenode = new typeNode(yytext); col+=yyleng; return TYPE; } 
"begin_progr" {printx("a1\n");yylval.node = new generalNode(yytext);col+=yyleng; return BGIN;}
"end_progr" {printx("a2\n");yylval.node = new generalNode(yytext);col+=yyleng; return END;}
[a-zA-Z][a-zA-Z0-9]* {printx("ID");yylval.node = new generalNode(yytext,row,col); col+=yyleng; return ID;}
":=" {printx("a4\n");yylval.node = new generalNode(yytext);col+=yyleng; return ASSIGN;}
[0-9]+ {printx("NR");yylval.node = new generalNode(yytext);col+=yyleng; return NR;}
"#"[^#]*"#" {}
[ \t] {printx("_");col+=yyleng;};
\n {printx("NL\n");row++;col=1;}

[\{\}\(\);=\[\]] {printf("%c",yytext[0]);yylval.node = new generalNode(yytext);col+=yyleng; return yytext[0];}
. {string s = ""; s+=yytext[0] ;printx(s);yylval.node = new generalNode(yytext);col+=yyleng; return yytext[0];}

