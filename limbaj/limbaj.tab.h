/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BGIN = 258,                    /* BGIN  */
    END = 259,                     /* END  */
    ASSIGN = 260,                  /* ASSIGN  */
    ID = 261,                      /* ID  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    FOR = 265,                     /* FOR  */
    CONST = 266,                   /* CONST  */
    RARROW = 267,                  /* RARROW  */
    FN = 268,                      /* FN  */
    RETURN = 269,                  /* RETURN  */
    CLASS = 270,                   /* CLASS  */
    EVAL = 271,                    /* EVAL  */
    TYPEOF = 272,                  /* TYPEOF  */
    CLASS_SECTION = 273,           /* CLASS_SECTION  */
    GLOBAL_FUNCTIONS = 274,        /* GLOBAL_FUNCTIONS  */
    GLOBAL_VARIABLES = 275,        /* GLOBAL_VARIABLES  */
    MAIN_FUNCTION = 276,           /* MAIN_FUNCTION  */
    LORT = 277,                    /* LORT  */
    LANDT = 278,                   /* LANDT  */
    LNOTT = 279,                   /* LNOTT  */
    EQT = 280,                     /* EQT  */
    NEQT = 281,                    /* NEQT  */
    LEQT = 282,                    /* LEQT  */
    GEQT = 283,                    /* GEQT  */
    BTYPE = 284,                   /* BTYPE  */
    FLOAT_TYPE = 285,              /* FLOAT_TYPE  */
    INT_TYPE = 286,                /* INT_TYPE  */
    BOOL_TYPE = 287,               /* BOOL_TYPE  */
    STRING_TYPE = 288,             /* STRING_TYPE  */
    CHAR_TYPE = 289,               /* CHAR_TYPE  */
    INTVAL = 290,                  /* INTVAL  */
    FLOATVAL = 291,                /* FLOATVAL  */
    BOOLVAL = 292,                 /* BOOLVAL  */
    STRINGVAL = 293,               /* STRINGVAL  */
    CHARVAL = 294,                 /* CHARVAL  */
    UMINUS = 295                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "limbaj.y"

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

#line 123 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
