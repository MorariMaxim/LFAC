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
            print_token("->", Colours::CFCOL); gCol+=yyleng; return RARROW;
            break;
            case FN:
            print_token("fn", Colours::CFCOL);gCol+=yyleng; return FN;
            break;
            case CLASS:
            print_token("class", Colours::TYPECOL);gCol+=yyleng; return CLASS;
            break;
            case IF:
            print_token("if", Colours::CFCOL);gCol+=yyleng; return IF;
            break;
            case RETURN:
            print_token("RETURN", Colours::CFCOL);gCol+=yyleng; return RETURN;
            break;
            case WHILE:
             gCol+=yyleng; return WHILE;
            break;
            case FOR:            
            gCol+=yyleng; return FOR;
            break;
            case ELSE:
            gCol+=yyleng; return ELSE;
            break;
            case CONST:
            print_token("CONST", Colours::TYPECOL);gCol+=yyleng; return CONST;
            break;
            case EVAL:
            print_token("EVAL");gCol+=yyleng; return EVAL;
            break;

            case BTYPE:
            print_token("type"); yylval.TypeNode = new TypeNode(yytext); gCol+=yyleng; return BTYPE; 
            break;
            case INT_TYPE:
            print_token("INTTYPE", Colours::TYPECOL); yylval.TypeNode = new IntType(); gCol+=yyleng;yylval.TypeNode->span_end();yylval.TypeNode->span_end(); return BTYPE; 
            break;
            case FLOAT_TYPE:
            print_token("FLOAT_TYPE", Colours::TYPECOL); yylval.TypeNode = new FloatType(); gCol+=yyleng;yylval.TypeNode->span_end(); return BTYPE; 
            break;
            case BOOL_TYPE:
            print_token("BOOL_TYPE", Colours::TYPECOL); yylval.TypeNode = new BoolType(); gCol+=yyleng;yylval.TypeNode->span_end(); return BTYPE; 
            break; 
            case STRING_TYPE:
            print_token("STRING_TYPE", Colours::TYPECOL); yylval.TypeNode = new StringType(); gCol+=yyleng;yylval.TypeNode->span_end(); return BTYPE; 
            break; 
            case CHAR_TYPE:
            print_token("CHAR_TYPE", Colours::TYPECOL); yylval.TypeNode = new CharType(); gCol+=yyleng;yylval.TypeNode->span_end(); return BTYPE; 
            break; 

            case INTVAL:
            print_token("INTVAL", Colours::VALCOL);yylval.value_node = new IntValue(yytext);gCol+=yyleng;yylval.TypeNode->span_end(); return INTVAL;
            break;
            case FLOATVAL:
            print_token("FLOATVAl", Colours::VALCOL);yylval.value_node = new FloatValue(yytext);gCol+=yyleng;yylval.TypeNode->span_end(); return FLOATVAL;
            break;
            case BOOLVAL:
            print_token("BOOLVAL", Colours::VALCOL);yylval.value_node = new BoolValue(yytext);gCol+=yyleng;yylval.TypeNode->span_end(); return BOOLVAL;
            break;
            case STRINGVAL:
            print_token("STRINGVAL", Colours::VALCOL);yylval.value_node = new StringValue(yytext);gCol+=yyleng;yylval.TypeNode->span_end(); return STRINGVAL;
            break;
            case CHARVAL:
            print_token("CHARVAL", Colours::VALCOL);yylval.value_node = new CharValue(yytext+1);gCol+=yyleng;yylval.TypeNode->span_end(); return CHARVAL;
            break;

            case LNOTT:
            print_token("LNOTT");gCol+=yyleng;return LNOTT;
            break;
            case LANDT:
            print_token("LANDT");gCol+=yyleng;return LANDT;
            break;
            case LORT:
            print_token("LORT");gCol+=yyleng;return LORT;
            break;
            case GEQT:
            print_token("GEQT");gCol+=yyleng;return GEQT;
            break;
            case LEQT:
            print_token("LEQT");gCol+=yyleng;return LEQT;
            break;
            case EQT:
            print_token("EQT");gCol+=yyleng;return EQT;
            break;
            case NEQT:
            print_token("NEQT");gCol+=yyleng;return NEQT;
            break;

            case BGIN:  
            gCol+=yyleng; return BGIN;
            break;
            case END:
            gCol+=yyleng; return END;
            break;
            case CLASS_SECTION: 
            gCol+=yyleng; return CLASS_SECTION;
            case GLOBAL_VARIABLES:
            gCol+=yyleng; return GLOBAL_VARIABLES;
            case GLOBAL_FUNCTIONS:
            gCol+=yyleng; return GLOBAL_FUNCTIONS;
            case MAIN_FUNCTION:
            gCol+=yyleng; return MAIN_FUNCTION;
            

            case ID:
            print_token("ID",Colours::IDCOL);yylval.node = new RawNode(yytext); gCol+=yyleng;yylval.node->span_end(); return ID;
            break; 
            
            break;
            default:
            string s = ""; s+=yytext[0];  yylval.spanned = new Span(); ;print_token(s); gCol+=yyleng; return yytext[0];
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
"private:" {print_token("private:");gCol+=yyleng; }
"public:" {print_token("public:");;gCol+=yyleng; }
"if" {treat_macro(IF);}
"return" {treat_macro(RETURN);}
"while" {treat_macro(WHILE);}
"for" {treat_macro(FOR);}
"else" {treat_macro(ELSE);}
"const" {treat_macro(CONST);}
"eval"  {treat_macro(EVAL);}
"||" {treat_macro(LORT);}
"&&" {treat_macro(LANDT);}
"!" {treat_macro(LNOTT);}
"==" {treat_macro(EQT);}
"!=" {treat_macro(NEQT);}
"<=" {treat_macro(LEQT);}
">=" {treat_macro(GEQT);}

"}"     {print_token("}");ignore_after_return_statement = false; treat_macro(yytext[0]);}
"CLASS_SECTION"  {treat_macro(CLASS_SECTION);}
"GLOBAL_VARIABLES"  {treat_macro(GLOBAL_VARIABLES);}
"GLOBAL_FUNCTIONS"  {treat_macro(GLOBAL_FUNCTIONS);}
"MAIN_FUNCTION" {treat_macro(MAIN_FUNCTION);}

"int" { treat_macro(INT_TYPE);}
"float" { treat_macro(FLOAT_TYPE);}
"char" { treat_macro(CHAR_TYPE);}
"string" { treat_macro(STRING_TYPE);}
"bool" { treat_macro(BOOL_TYPE);}
"void" {treat_macro(BTYPE);} 

"begin_progr" {treat_macro(BGIN);}
"end_progr" {treat_macro(END);}



[-+]?[0-9]+ {treat_macro(INTVAL);}
[-+]?[0-9]+\.[0-9]+ {treat_macro(FLOATVAL)}
true|false {treat_macro(BOOLVAL)}

[a-zA-Z][a-zA-Z0-9]* {treat_macro(ID);} 

"\""[^"]*"\""     { treat_macro(STRINGVAL); }
'.'                { treat_macro(CHARVAL); }

"#"[^#]*"#" {}
[ \t] {print_token("_");gCol+=yyleng;};
\n {print_token("NL\n");gRow++;gCol=1;}

. {treat_macro(yytext[0]);}

