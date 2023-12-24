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
            print_token("->", Colours::CFCOL); col+=yyleng; return RARROW;
            break;
            case FN:
            print_token("fn", Colours::CFCOL);col+=yyleng; return FN;
            break;
            case CLASS:
            print_token("class", Colours::TYPECOL);col+=yyleng; return CLASS;
            break;
            case IF:
            print_token("if", Colours::CFCOL);col+=yyleng; return IF;
            break;
            case RETURN:
            print_token("RETURN", Colours::CFCOL);col+=yyleng; return RETURN;
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
            print_token("CONST", Colours::TYPECOL);col+=yyleng; return CONST;
            break;
            case EVAL:
            print_token("EVAL");col+=yyleng; return EVAL;
            break;
            case BTYPE:
            print_token("type"); yylval.TypeNode = new TypeNode(yytext); col+=yyleng; return BTYPE; 
            break;
            case INT_TYPE:
            print_token("INTTYPE", Colours::TYPECOL); yylval.TypeNode = new IntType(); col+=yyleng; return BTYPE; 
            break;
            case BGIN:
            col+=yyleng; return BGIN;
            break;
            case END:
            col+=yyleng; return END;
            break;
            case ID:
            print_token("ID",Colours::IDCOL);yylval.node = new GeneralInfo(yytext,row,col); col+=yyleng; return ID;
            break;
            case ASSIGN:
            col+=yyleng; return ASSIGN;
            break;
            case INT_NR:
            print_token("INTVAL", Colours::VALCOL);yylval.int_value = new IntValue(yytext);col+=yyleng; return INT_NR;
            break;
            default:
            string s = ""; s+=yytext[0] ;print_token(s); col+=yyleng; return yytext[0];
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
"private:" {print_token("private:");col+=yyleng; }
"public:" {print_token("public:");;col+=yyleng; }
"if" {treat_macro(IF);}
"return" {treat_macro(RETURN);}
"while" {treat_macro(WHILE);}
"for" {treat_macro(FOR);}
"else" {treat_macro(ELSE);}
"const" {treat_macro(CONST);}
"eval"  {treat_macro(EVAL);}
"}"     {print_token("}");col+=yyleng;ignore_after_return_statement = false; return '}';}

"int" { treat_macro(INT_TYPE);}
"float"|"char"|"string"|"void" {treat_macro(BTYPE);} 
"begin_progr" {treat_macro(BGIN);}
"end_progr" {treat_macro(END);}
[a-zA-Z][a-zA-Z0-9]* {treat_macro(ID);}
":=" {treat_macro(ASSIGN);}
[-+]{0,1}[0-9]+ {treat_macro(INT_NR);}
"#"[^#]*"#" {}
[ \t] {print_token("_");col+=yyleng;};
\n {print_token("NL\n");row++;col=1;}

. {treat_macro(yytext[0]);}

