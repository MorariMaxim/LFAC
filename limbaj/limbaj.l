%{
#include <stdio.h>
#include "limbaj.tab.h"
#include "GeneralInfo.h" 
visibilityType currentVisibility = PUBLIC;
bool ignore_after_return_statement = false;
#define IGNORETOKEN -1000000
int treat_helper(int type) {  
    if(!ignore_after_return_statement){
        switch (type) {
            case RARROW:
            printx("->"); col+=yyleng; return RARROW;
            break;
            case FN:
            printx("fn");col+=yyleng; return FN;
            break;
            case CLASS:
            printx("class");col+=yyleng; return CLASS;
            break;
            case IF:
            printx("if");col+=yyleng; return IF;
            break;
            case RETURN:
            printx("RETURN");col+=yyleng; return RETURN;
            break;
            case WHILE:
             col+=yyleng; return WHILE;
            break;
            case FOR:            
            col+=yyleng; return FOR;
            break;
            case ELSE:
            col+=yyleng; return ELSE;
            break;
            case CONST:
            printx("CONST");col+=yyleng; return CONST;
            break;
            case EVAL:
            printx("EVAK");col+=yyleng; return EVAL;
            break;
            case TYPE:
            printx("type"); yylval.TypeAndValue = new TypeAndValue(yytext); col+=yyleng; return TYPE; 
            break;
            case INT_TYPE:
            printx("INT_TYPE"); yylval.TypeAndValue = new IntType(yytext); col+=yyleng; return TYPE; 
            break;
            case BGIN:
            col+=yyleng; return BGIN;
            break;
            case END:
            col+=yyleng; return END;
            break;
            case ID:
            printx("ID");yylval.node = new GeneralInfo(yytext,row,col); col+=yyleng; return ID;
            break;
            case ASSIGN:
            col+=yyleng; return ASSIGN;
            break;
            case INT_NR:
            printx("INT_NR");yylval.node = new IntType(yytext);col+=yyleng; return INT_NR;
            break;
            default:
            string s = ""; s+=yytext[0] ;printx(s); col+=yyleng; return yytext[0];
        }        
    } 
    return IGNORETOKEN; 
}

#define treat_macro(t) { int x = treat_helper(t); if(x!=IGNORETOKEN) {return x;} }

%}
%option noyywrap
%%
"->" {treat_macro(RARROW);}
"fn" {treat_macro(FN);}
"class" {treat_macro(CLASS);}
"private:" {printx("private:");col+=yyleng; }
"public:" {printx("public:");;col+=yyleng; }
"if" {treat_macro(IF);}
"return" {treat_macro(RETURN);}
"while" {treat_macro(WHILE);}
"for" {treat_macro(FOR);}
"else" {treat_macro(ELSE);}
"const" {treat_macro(CONST);}
"eval"  {treat_macro(EVAL);}
"}"     {printx("}");col+=yyleng;ignore_after_return_statement = false; return '}';}

"int" { treat_macro(INT_TYPE);}
"float"|"char"|"string"|"void" {treat_macro(TYPE);} 
"begin_progr" {treat_macro(BGIN);}
"end_progr" {treat_macro(END);}
[a-zA-Z][a-zA-Z0-9]* {treat_macro(ID);}
":=" {treat_macro(ASSIGN);}
[-+]{0,1}[0-9]+ {treat_macro(INT_NR);}
"#"[^#]*"#" {}
[ \t] {printx("_");col+=yyleng;};
\n {printx("NL\n");row++;col=1;}

. {treat_macro(yytext[0]);}

