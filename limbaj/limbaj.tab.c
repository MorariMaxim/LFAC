/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"

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

#define checkSymbol(x) {if ( currentSymbolTable->is_symbol_defined_in_path(x->content)==nullptr) printf("symbol not defined %s at %d:%d",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->is_symbol_defined_in_path(x->content)}
#define backtrack_scope() {currentSymbolTable = currentSymbolTable->getParent();}
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


#line 109 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '{'  */
  YYSYMBOL_4_ = 4,                         /* '}'  */
  YYSYMBOL_5_ = 5,                         /* '['  */
  YYSYMBOL_6_ = 6,                         /* ']'  */
  YYSYMBOL_7_ = 7,                         /* ';'  */
  YYSYMBOL_8_ = 8,                         /* ','  */
  YYSYMBOL_BGIN = 9,                       /* BGIN  */
  YYSYMBOL_END = 10,                       /* END  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_ID = 12,                        /* ID  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_RARROW = 18,                    /* RARROW  */
  YYSYMBOL_FN = 19,                        /* FN  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_CLASS = 21,                     /* CLASS  */
  YYSYMBOL_EVAL = 22,                      /* EVAL  */
  YYSYMBOL_BTYPE = 23,                     /* BTYPE  */
  YYSYMBOL_FLOAT_TYPE = 24,                /* FLOAT_TYPE  */
  YYSYMBOL_INT_TYPE = 25,                  /* INT_TYPE  */
  YYSYMBOL_BOOL_TYPE = 26,                 /* BOOL_TYPE  */
  YYSYMBOL_STRING_TYPE = 27,               /* STRING_TYPE  */
  YYSYMBOL_CHAR_TYPE = 28,                 /* CHAR_TYPE  */
  YYSYMBOL_INTVAL = 29,                    /* INTVAL  */
  YYSYMBOL_FLOATVAL = 30,                  /* FLOATVAL  */
  YYSYMBOL_BOOLVAL = 31,                   /* BOOLVAL  */
  YYSYMBOL_STRINGVAL = 32,                 /* STRINGVAL  */
  YYSYMBOL_CHARVAL = 33,                   /* CHARVAL  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_progr = 45,                     /* progr  */
  YYSYMBOL_statements = 46,                /* statements  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_return_statement = 48,          /* return_statement  */
  YYSYMBOL_return_value = 49,              /* return_value  */
  YYSYMBOL_gtype = 50,                     /* gtype  */
  YYSYMBOL_init = 51,                      /* init  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_class_declaration = 53,         /* class_declaration  */
  YYSYMBOL_object_init = 54,               /* object_init  */
  YYSYMBOL_field_val = 55,                 /* field_val  */
  YYSYMBOL_expressions = 56,               /* expressions  */
  YYSYMBOL_array_value = 57,               /* array_value  */
  YYSYMBOL_array_indexing = 58,            /* array_indexing  */
  YYSYMBOL_array_element = 59,             /* array_element  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_function_body = 61,             /* function_body  */
  YYSYMBOL_func_signature = 62,            /* func_signature  */
  YYSYMBOL_return_type = 63,               /* return_type  */
  YYSYMBOL_function_call = 64,             /* function_call  */
  YYSYMBOL_id_parameters = 65,             /* id_parameters  */
  YYSYMBOL_exprs = 66,                     /* exprs  */
  YYSYMBOL_arguments = 67,                 /* arguments  */
  YYSYMBOL_param_list = 68,                /* param_list  */
  YYSYMBOL_parameter = 69,                 /* parameter  */
  YYSYMBOL_expr = 70,                      /* expr  */
  YYSYMBOL_assignment = 71,                /* assignment  */
  YYSYMBOL_ISCONST = 72,                   /* ISCONST  */
  YYSYMBOL_IF_S = 73,                      /* IF_S  */
  YYSYMBOL_IF_B = 74,                      /* IF_B  */
  YYSYMBOL_IF_ELSE_S = 75,                 /* IF_ELSE_S  */
  YYSYMBOL_IF_ELSE_B = 76,                 /* IF_ELSE_B  */
  YYSYMBOL_class_s = 77,                   /* class_s  */
  YYSYMBOL_decls_funcs = 78,               /* decls_funcs  */
  YYSYMBOL_class_b = 79,                   /* class_b  */
  YYSYMBOL_member_access = 80,             /* member_access  */
  YYSYMBOL_eval_expression = 81            /* eval_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    36,    34,     8,    35,    43,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,     7,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     2,     6,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    87,    89,    90,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   106,   107,   108,   110,   111,
     114,   115,   118,   120,   122,   128,   130,   132,   133,   134,
     135,   138,   139,   141,   145,   146,   148,   150,   153,   154,
     157,   161,   162,   164,   166,   169,   170,   173,   174,   176,
     177,   179,   180,   183,   186,   187,   188,   189,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   206,
     207,   208,   213,   216,   219,   222,   225,   228,   230,   231,
     232,   233,   235,   236,   239,   241
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'{'", "'}'", "'['",
  "']'", "';'", "','", "BGIN", "END", "ASSIGN", "ID", "IF", "ELSE",
  "WHILE", "FOR", "CONST", "RARROW", "FN", "RETURN", "CLASS", "EVAL",
  "BTYPE", "FLOAT_TYPE", "INT_TYPE", "BOOL_TYPE", "STRING_TYPE",
  "CHAR_TYPE", "INTVAL", "FLOATVAL", "BOOLVAL", "STRINGVAL", "CHARVAL",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "'='", "'('", "')'", "':'", "'.'",
  "$accept", "progr", "statements", "statement", "return_statement",
  "return_value", "gtype", "init", "declaration", "class_declaration",
  "object_init", "field_val", "expressions", "array_value",
  "array_indexing", "array_element", "function", "function_body",
  "func_signature", "return_type", "function_call", "id_parameters",
  "exprs", "arguments", "param_list", "parameter", "expr", "assignment",
  "ISCONST", "IF_S", "IF_B", "IF_ELSE_S", "IF_ELSE_B", "class_s",
  "decls_funcs", "class_b", "member_access", "eval_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     200,   223,    20,   -21,   -94,    11,   229,    17,    -9,   -94,
     -94,   -94,   -94,   -94,   -94,   223,    36,   200,   -94,   -94,
      26,   -94,    33,   -94,   -94,   -94,    84,   -94,   -94,   208,
      63,    52,   200,   -94,   200,   -94,   266,   -94,    38,    72,
      29,    22,   190,   -94,   223,    41,   223,    79,    71,     2,
     223,    47,   -94,   -94,   230,    87,   223,   257,   -94,   -94,
       5,   -94,   -94,   126,   -94,   -94,   223,   223,   223,   223,
     -94,   -94,   156,   178,   -94,    82,   -94,   -94,   267,   223,
     -94,    90,   -94,   223,    92,    30,   -94,   190,   -94,    -4,
     190,    59,   -94,   223,   223,   265,    39,    58,   -94,   -94,
     273,   -94,   -94,   223,   -94,     8,   -94,    49,    49,   -94,
     -94,    86,   -94,   -94,   -94,   -94,   190,   190,   -94,    76,
     -94,    12,   223,   -94,   128,   190,   119,   -94,   111,    13,
     -94,   -94,    -6,   -94,   -94,   239,   -94,   122,   223,   120,
     -94,   190,   -94,   -94,   -94,    -6,   -94,   130,   -94,   -94,
     190,    93,   -94,   -94,   223,   190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    59,     0,    72,     0,     0,     0,     0,    19,
      60,    61,    63,    62,    64,     0,     0,     2,     4,    14,
       0,     6,     0,    68,    67,    10,     0,    66,    44,     0,
       0,     0,     0,     8,     0,     9,     0,    12,    65,     0,
      59,     0,    31,    65,     0,    25,     0,     0,     0,    36,
       0,     0,    17,    15,     0,     0,     0,     0,     1,     5,
       0,    24,    39,     0,    37,     7,     0,     0,     0,     0,
      11,    18,     0,     0,    83,     0,    79,    78,     0,     0,
      13,    36,    33,     0,     0,     0,    26,    69,    46,     0,
      47,    84,    43,     0,     0,     0,     0,     0,    16,    77,
       0,    58,    21,     0,    22,     0,    38,    54,    55,    57,
      56,    74,    76,    82,    80,    81,    71,    32,    34,     0,
      27,     0,     0,    45,     0,    70,     0,    50,     0,     0,
      52,    42,     0,    40,    85,     0,    23,     0,     0,     0,
      28,    48,    35,    73,    53,     0,    49,     0,    20,    75,
      29,     0,    51,    41,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -10,   -15,   -94,   -94,   -93,    31,   -28,   -94,
     -94,   -94,   -94,   -94,   -34,   -94,   -27,   -94,   -94,   -94,
     -94,    94,   -94,   -94,   -94,    -5,    -1,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,     1,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    53,    20,   104,    21,    22,
      86,   121,    41,    23,    49,    24,    25,    64,    26,   133,
      27,    28,    89,    97,   129,   130,    29,    30,    31,    32,
      33,    34,    35,    36,    78,    37,    43,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    38,    59,   128,   122,    54,    81,    93,    76,    77,
      44,     4,   102,    93,    57,   102,    63,     9,    38,    50,
     139,   145,    72,    51,    73,    44,   105,    38,    82,    55,
      83,    56,    45,    38,    44,    38,    58,   123,    60,   147,
      61,    94,   119,    84,   103,    87,    90,   103,    59,    95,
     114,   115,   128,   140,   146,   100,     4,    59,    59,    46,
      47,   131,     9,    48,    38,   107,   108,   109,   110,    47,
      70,   120,    48,    38,    38,    71,   132,    79,   116,    80,
     127,    85,   117,    91,     1,    68,    69,    96,    62,     1,
      99,    40,   124,   125,    45,    93,     2,     3,   118,    47,
     137,     4,   135,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    10,    11,    12,    13,    14,   138,    15,
      88,   141,   143,   144,    15,   149,    66,    67,    68,    69,
     106,     1,   151,   153,   142,   154,   136,   150,     2,     3,
     152,     0,    92,     4,     0,     5,     6,     7,     8,     9,
       0,     0,     0,   155,     0,    10,    11,    12,    13,    14,
     111,     1,    66,    67,    68,    69,    15,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     8,     9,
       0,     0,   112,     1,     0,    10,    11,    12,    13,    14,
       2,     3,     0,     0,     0,     4,    15,     5,     6,     7,
       8,     9,     0,     0,     0,     1,     0,    10,    11,    12,
      13,    14,     2,     3,     0,    65,     0,     4,    15,     5,
       6,     7,     8,     9,    66,    67,    68,    69,     1,    10,
      11,    12,    13,    14,     1,    40,    52,    98,     0,     0,
      15,    40,    66,    67,    68,    69,   148,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,     0,    10,    11,
      12,    13,    14,    15,    66,    67,    68,    69,     0,    15,
      74,   113,     0,    66,    67,    68,    69,     0,    75,    75,
       0,     0,     0,     4,     4,     5,     5,     0,     0,     9,
       9,    66,    67,    68,    69,     0,     0,     0,   101,    66,
      67,    68,    69,     0,     0,     0,   126,    66,    67,    68,
      69,     0,     0,     0,   134
};

static const yytype_int16 yycheck[] =
{
       1,     0,    17,    96,     8,     6,    40,     5,    36,    36,
       5,    17,     7,     5,    15,     7,    26,    23,    17,    40,
       8,     8,    32,    12,    34,     5,    60,    26,     6,    12,
       8,    40,    12,    32,     5,    34,     0,    41,    12,   132,
       7,    39,    12,    44,    39,    46,    47,    39,    63,    50,
      78,    78,   145,    41,    41,    56,    17,    72,    73,    39,
      40,     3,    23,    43,    63,    66,    67,    68,    69,    40,
       7,    41,    43,    72,    73,    23,    18,    39,    79,     7,
      41,    40,    83,    12,     5,    36,    37,    40,     4,     5,
       3,    12,    93,    94,    12,     5,    12,    13,     6,    40,
      14,    17,   103,    19,    20,    21,    22,    23,    29,    30,
      31,    32,    33,    29,    30,    31,    32,    33,    42,    40,
      41,   122,     3,    12,    40,     3,    34,    35,    36,    37,
       4,     5,    12,     3,     6,    42,   105,   138,    12,    13,
     145,    -1,    48,    17,    -1,    19,    20,    21,    22,    23,
      -1,    -1,    -1,   154,    -1,    29,    30,    31,    32,    33,
       4,     5,    34,    35,    36,    37,    40,    -1,    12,    13,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    23,
      -1,    -1,     4,     5,    -1,    29,    30,    31,    32,    33,
      12,    13,    -1,    -1,    -1,    17,    40,    19,    20,    21,
      22,    23,    -1,    -1,    -1,     5,    -1,    29,    30,    31,
      32,    33,    12,    13,    -1,     7,    -1,    17,    40,    19,
      20,    21,    22,    23,    34,    35,    36,    37,     5,    29,
      30,    31,    32,    33,     5,    12,     7,     7,    -1,    -1,
      40,    12,    34,    35,    36,    37,     7,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    29,    30,
      31,    32,    33,    40,    34,    35,    36,    37,    -1,    40,
       4,     4,    -1,    34,    35,    36,    37,    -1,    12,    12,
      -1,    -1,    -1,    17,    17,    19,    19,    -1,    -1,    23,
      23,    34,    35,    36,    37,    -1,    -1,    -1,    41,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    34,    35,    36,
      37,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    12,    13,    17,    19,    20,    21,    22,    23,
      29,    30,    31,    32,    33,    40,    45,    46,    47,    48,
      50,    52,    53,    57,    59,    60,    62,    64,    65,    70,
      71,    72,    73,    74,    75,    76,    77,    79,    80,    81,
      12,    56,    70,    80,     5,    12,    39,    40,    43,    58,
      40,    12,     7,    49,    70,    12,    40,    70,     0,    47,
      12,     7,     4,    46,    61,     7,    34,    35,    36,    37,
       7,    23,    46,    46,     4,    12,    52,    60,    78,    39,
       7,    58,     6,     8,    70,    40,    54,    70,    41,    66,
      70,    12,    65,     5,    39,    70,    40,    67,     7,     3,
      70,    41,     7,    39,    51,    58,     4,    70,    70,    70,
      70,     4,     4,     4,    52,    60,    70,    70,     6,    12,
      41,    55,     8,    41,    70,    70,    41,    41,    50,    68,
      69,     3,    18,    63,    41,    70,    51,    14,    42,     8,
      41,    70,     6,     3,    12,     8,    41,    50,     7,     3,
      70,    12,    69,     3,    42,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    60,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    73,    74,    75,    76,    77,    78,    78,
      78,    78,    79,    79,    80,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     2,     1,     1,
       1,     2,     1,     2,     1,     2,     2,     1,     2,     1,
       3,     1,     3,     4,     2,     2,     3,     2,     3,     3,
       5,     1,     3,     3,     3,     4,     2,     2,     2,     1,
       4,     3,     1,     3,     1,     4,     3,     1,     3,     3,
       2,     3,     1,     2,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1,     5,     3,     5,     3,     3,     1,     1,
       2,     2,     3,     2,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* progr: statements  */
#line 86 "limbaj.y"
                   { print_reduction("syntactically correct program"); }
#line 1315 "limbaj.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 87 "limbaj.y"
                     { print_reduction("empty prog");}
#line 1321 "limbaj.tab.c"
    break;

  case 4: /* statements: statement  */
#line 89 "limbaj.y"
                       { (yyval.node) = (yyvsp[0].node); print_reduction("statements -> statement");}
#line 1327 "limbaj.tab.c"
    break;

  case 5: /* statements: statements statement  */
#line 90 "limbaj.y"
                                { (yyval.node) = (yyvsp[-1].node); print_reduction("statements -> statements statement");}
#line 1333 "limbaj.tab.c"
    break;

  case 6: /* statement: declaration  */
#line 93 "limbaj.y"
                      { print_reduction("stmt -> declaration");}
#line 1339 "limbaj.tab.c"
    break;

  case 7: /* statement: expr ';'  */
#line 94 "limbaj.y"
                    { print_reduction("stmt -> expr");}
#line 1345 "limbaj.tab.c"
    break;

  case 8: /* statement: IF_B  */
#line 95 "limbaj.y"
               { print_reduction("stmt -> IF_B");}
#line 1351 "limbaj.tab.c"
    break;

  case 9: /* statement: IF_ELSE_B  */
#line 96 "limbaj.y"
                    { print_reduction("statement -> IF_ELSE_B");}
#line 1357 "limbaj.tab.c"
    break;

  case 10: /* statement: function  */
#line 97 "limbaj.y"
                   { print_reduction("statement -> function"); (yyval.node) = (yyvsp[0].funcNode);}
#line 1363 "limbaj.tab.c"
    break;

  case 11: /* statement: assignment ';'  */
#line 98 "limbaj.y"
                         {print_reduction("statement -> assignment");}
#line 1369 "limbaj.tab.c"
    break;

  case 12: /* statement: class_b  */
#line 99 "limbaj.y"
                  {print_reduction("statement -> class_b");}
#line 1375 "limbaj.tab.c"
    break;

  case 13: /* statement: eval_expression ';'  */
#line 100 "limbaj.y"
                              {print_reduction("statement -> eval_expression");}
#line 1381 "limbaj.tab.c"
    break;

  case 14: /* statement: return_statement  */
#line 101 "limbaj.y"
                           {print_reduction("statement -> return statement");}
#line 1387 "limbaj.tab.c"
    break;

  case 15: /* return_statement: RETURN return_value  */
#line 106 "limbaj.y"
                                      {print_reduction("ret_statement -> return return_value "); treat_return_statement((yyvsp[0].exprnode)); ignore_after_return_statement = true;}
#line 1393 "limbaj.tab.c"
    break;

  case 16: /* return_value: expr ';'  */
#line 107 "limbaj.y"
                       {(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 1399 "limbaj.tab.c"
    break;

  case 17: /* return_value: ';'  */
#line 108 "limbaj.y"
                   {(yyval.exprnode)=nullptr;}
#line 1405 "limbaj.tab.c"
    break;

  case 18: /* gtype: ISCONST BTYPE  */
#line 110 "limbaj.y"
                     {(yyval.TypeNode) = (yyvsp[0].TypeNode); (yyval.TypeNode)->is_const = 1;}
#line 1411 "limbaj.tab.c"
    break;

  case 19: /* gtype: BTYPE  */
#line 111 "limbaj.y"
                {(yyval.TypeNode) = (yyvsp[0].TypeNode);}
#line 1417 "limbaj.tab.c"
    break;

  case 20: /* init: '=' expr ';'  */
#line 114 "limbaj.y"
                    {(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 1423 "limbaj.tab.c"
    break;

  case 21: /* init: ';'  */
#line 115 "limbaj.y"
              {(yyval.exprnode) = nullptr;}
#line 1429 "limbaj.tab.c"
    break;

  case 22: /* declaration: gtype ID init  */
#line 118 "limbaj.y"
                          { print_reduction("decl->const type id init;");
                                            currentSymbolTable->declare_symbol((yyvsp[-2].TypeNode),(yyvsp[-1].node),(yyvsp[0].exprnode));  (yyval.node) = new RawNode("");}
#line 1436 "limbaj.tab.c"
    break;

  case 23: /* declaration: gtype ID array_indexing init  */
#line 120 "limbaj.y"
                                        { print_reduction("decl -> gtype ID array_indexing init");
                                                currentSymbolTable->declare_array_symbol((yyvsp[-2].node),(yyvsp[-3].TypeNode), (yyvsp[-1].arrayIndexingNode),(yyvsp[0].exprnode)); (yyval.node) = (yyvsp[-2].node);}
#line 1443 "limbaj.tab.c"
    break;

  case 24: /* declaration: class_declaration ';'  */
#line 122 "limbaj.y"
                                {print_reduction(" declaration -> class_declaration ");}
#line 1449 "limbaj.tab.c"
    break;

  case 25: /* class_declaration: ID ID  */
#line 128 "limbaj.y"
                {print_reduction(" dclass_Declaration -> uninitialized ");currentSymbolTable->declare_user_symbol((yyvsp[-1].node),(yyvsp[0].node));}
#line 1455 "limbaj.tab.c"
    break;

  case 26: /* class_declaration: ID ID object_init  */
#line 130 "limbaj.y"
                            {print_reduction(" dclass_Declaration -> initialized");currentSymbolTable->declare_user_symbol((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].container));}
#line 1461 "limbaj.tab.c"
    break;

  case 27: /* object_init: '(' ')'  */
#line 132 "limbaj.y"
                     {(yyval.container) = nullptr;}
#line 1467 "limbaj.tab.c"
    break;

  case 28: /* object_init: '(' field_val ')'  */
#line 133 "limbaj.y"
                            {(yyval.container) = (yyvsp[-1].container);}
#line 1473 "limbaj.tab.c"
    break;

  case 29: /* field_val: ID ':' expr  */
#line 134 "limbaj.y"
                       {print_reduction("field_Val -> ID : expr"); (yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[-2].node));(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1479 "limbaj.tab.c"
    break;

  case 30: /* field_val: field_val ',' ID ':' expr  */
#line 135 "limbaj.y"
                                    {print_reduction("field_Val -> field_val , ID : expr"); (yyval.container) = (yyvsp[-4].container); (yyval.container)->add_element((yyvsp[-2].node));(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1485 "limbaj.tab.c"
    break;

  case 31: /* expressions: expr  */
#line 138 "limbaj.y"
                  {print_reduction("expressions -> expr"); (yyval.container) = new Vector();(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1491 "limbaj.tab.c"
    break;

  case 32: /* expressions: expressions ',' expr  */
#line 139 "limbaj.y"
                               {print_reduction("expressions -> expressions , expr"); (yyval.container) = (yyvsp[-2].container);(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1497 "limbaj.tab.c"
    break;

  case 33: /* array_value: '[' expressions ']'  */
#line 141 "limbaj.y"
                                 {print_reduction("array_value ->  [ expressions ] "); (yyval.array_value_node) = new ArrayValue((yyvsp[-1].container));}
#line 1503 "limbaj.tab.c"
    break;

  case 34: /* array_indexing: '[' expr ']'  */
#line 145 "limbaj.y"
                             {print_reduction("array_indexing -> '[' rval ']'");(yyval.arrayIndexingNode)  = new ArrayIndexing(); (yyval.arrayIndexingNode)->add_index((yyvsp[-1].exprnode)); }
#line 1509 "limbaj.tab.c"
    break;

  case 35: /* array_indexing: array_indexing '[' expr ']'  */
#line 146 "limbaj.y"
                                      {print_reduction("array_indexing -> array_indexing '[' INTVAL ']'"); (yyval.arrayIndexingNode) = (yyvsp[-3].arrayIndexingNode); (yyval.arrayIndexingNode)->add_index((yyvsp[-1].exprnode));}
#line 1515 "limbaj.tab.c"
    break;

  case 36: /* array_element: ID array_indexing  */
#line 148 "limbaj.y"
                                 {print_reduction("array element") ;(yyval.value_node) = currentSymbolTable->symbol_indexing((yyvsp[-1].node),(yyvsp[0].arrayIndexingNode));}
#line 1521 "limbaj.tab.c"
    break;

  case 37: /* function: func_signature function_body  */
#line 150 "limbaj.y"
                                      { print_reduction("function -> func_signature statements return rval}");
                                                backtrack_scope();(yyval.funcNode) = (yyvsp[-1].funcNode);(yyval.funcNode)->check_return_type();(yyval.funcNode)->set_lines((yyvsp[-1].funcNode),(yyvsp[0].node)); }
#line 1528 "limbaj.tab.c"
    break;

  case 38: /* function_body: statements '}'  */
#line 153 "limbaj.y"
                              {print_reduction(" funcbody -> statements }"); (yyval.node) = (yyvsp[-1].node);(yyval.node)->set_span((yyvsp[0].spanned));printf("body set spanned to %s\n",(yyvsp[0].spanned)->span_to_string().c_str());}
#line 1534 "limbaj.tab.c"
    break;

  case 39: /* function_body: '}'  */
#line 154 "limbaj.y"
              {print_reduction(" funcbody -> empty }"); (yyval.node) = new RawNode();(yyval.node)->set_span((yyvsp[0].spanned));printf("body set spanned to %s\n",(yyvsp[0].spanned)->span_to_string().c_str());}
#line 1540 "limbaj.tab.c"
    break;

  case 40: /* func_signature: FN ID arguments return_type  */
#line 157 "limbaj.y"
                                     { print_reduction("functions_s -> fn id arguments -> type {"); (yyval.funcNode) = new FunctionDetails((yyvsp[-2].node)->content,(yyvsp[0].TypeNode),(yyvsp[-1].container)); (yyval.funcNode)->set_span((yyvsp[-2].node)); printf("signature set spanned to %s\n",(yyval.funcNode)->span_to_string().c_str());
                                        currentSymbolTable=  currentSymbolTable->addFunction((yyval.funcNode)); currentSymbolTable->set_span((yyvsp[-2].node));
                                        }
#line 1548 "limbaj.tab.c"
    break;

  case 41: /* return_type: RARROW gtype '{'  */
#line 161 "limbaj.y"
                              {print_reduction("return_type -> RARROW gtype {"); (yyval.TypeNode) = (yyvsp[-1].TypeNode);}
#line 1554 "limbaj.tab.c"
    break;

  case 42: /* return_type: '{'  */
#line 162 "limbaj.y"
             {print_reduction("return_type - -> empty {"); (yyval.TypeNode) = nullptr;}
#line 1560 "limbaj.tab.c"
    break;

  case 43: /* function_call: ID '.' id_parameters  */
#line 164 "limbaj.y"
                                     {print_reduction("FunctionCall -> ID . id_parameters"); (yyval.funcCall) = new FunctionCall((yyvsp[-2].node),(yyvsp[0].container));
                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call");}
#line 1567 "limbaj.tab.c"
    break;

  case 44: /* function_call: id_parameters  */
#line 166 "limbaj.y"
                               {print_reduction("FunctionCall -> id_parameters"); (yyval.funcCall) = new FunctionCall(nullptr,(yyvsp[0].container));

                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call");}
#line 1575 "limbaj.tab.c"
    break;

  case 45: /* id_parameters: ID '(' exprs ')'  */
#line 169 "limbaj.y"
                                {print_reduction("id_parameters -> id ( rvalues )");(yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[-3].node));(yyval.container)->add_element((yyvsp[-1].container)); }
#line 1581 "limbaj.tab.c"
    break;

  case 46: /* id_parameters: ID '(' ')'  */
#line 170 "limbaj.y"
                        {print_reduction("id_parameters -> id ()");(yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[-2].node));}
#line 1587 "limbaj.tab.c"
    break;

  case 47: /* exprs: expr  */
#line 173 "limbaj.y"
            {print_reduction("exprs -> expr");(yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[0].exprnode)); }
#line 1593 "limbaj.tab.c"
    break;

  case 48: /* exprs: exprs ',' expr  */
#line 174 "limbaj.y"
                         {print_reduction("exprs -> exprs , expr");(yyvsp[-2].container)->add_element((yyvsp[0].exprnode));(yyval.container)=(yyvsp[-2].container);}
#line 1599 "limbaj.tab.c"
    break;

  case 49: /* arguments: '(' param_list ')'  */
#line 176 "limbaj.y"
                              {print_reduction("arguments -> parameter llist"); (yyval.container) = (yyvsp[-1].container);}
#line 1605 "limbaj.tab.c"
    break;

  case 50: /* arguments: '(' ')'  */
#line 177 "limbaj.y"
                  {print_reduction("arguments -> empty"); (yyval.container) = nullptr;}
#line 1611 "limbaj.tab.c"
    break;

  case 51: /* param_list: param_list ',' parameter  */
#line 179 "limbaj.y"
                                      {print_reduction("parameter list -> parameter llist , parameter"); (yyval.container) = (yyvsp[-2].container); (yyval.container)->add_element((yyvsp[0].symbol_node));}
#line 1617 "limbaj.tab.c"
    break;

  case 52: /* param_list: parameter  */
#line 180 "limbaj.y"
                     {print_reduction("parameter list -> parameter");(yyval.container) = new Vector();(yyval.container)->add_element((yyvsp[0].symbol_node));}
#line 1623 "limbaj.tab.c"
    break;

  case 53: /* parameter: gtype ID  */
#line 183 "limbaj.y"
                    { print_reduction("paramter -> type id"); (yyval.symbol_node) = new Symbol((yyvsp[0].node)->content,(yyvsp[-1].TypeNode),nullptr);}
#line 1629 "limbaj.tab.c"
    break;

  case 54: /* expr: expr '+' expr  */
#line 186 "limbaj.y"
                        { print_reduction("expr -> expr + expr");(yyval.exprnode) = new Expression(OperTypes::ADD,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1635 "limbaj.tab.c"
    break;

  case 55: /* expr: expr '-' expr  */
#line 187 "limbaj.y"
                        { print_reduction("expr -> expr - expr");(yyval.exprnode) = new Expression(OperTypes::SUB,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1641 "limbaj.tab.c"
    break;

  case 56: /* expr: expr '/' expr  */
#line 188 "limbaj.y"
                        { print_reduction("expr -> expr / expr");(yyval.exprnode) = new Expression(OperTypes::DIV,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1647 "limbaj.tab.c"
    break;

  case 57: /* expr: expr '*' expr  */
#line 189 "limbaj.y"
                        { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::MUL,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1653 "limbaj.tab.c"
    break;

  case 58: /* expr: '(' expr ')'  */
#line 191 "limbaj.y"
                       { print_reduction("expr -> ( expr ) ");(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 1659 "limbaj.tab.c"
    break;

  case 59: /* expr: ID  */
#line 192 "limbaj.y"
             {print_reduction("expr -> ID");(yyval.exprnode) = new Expression((yyvsp[0].node)); delete (yyvsp[0].node);}
#line 1665 "limbaj.tab.c"
    break;

  case 60: /* expr: INTVAL  */
#line 193 "limbaj.y"
                 {print_reduction("expr -> INTVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1671 "limbaj.tab.c"
    break;

  case 61: /* expr: FLOATVAL  */
#line 194 "limbaj.y"
                   {print_reduction("expr -> FLOATVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1677 "limbaj.tab.c"
    break;

  case 62: /* expr: STRINGVAL  */
#line 195 "limbaj.y"
                    {print_reduction("expr -> STRINGVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1683 "limbaj.tab.c"
    break;

  case 63: /* expr: BOOLVAL  */
#line 196 "limbaj.y"
                  {print_reduction("expr -> BOOLVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1689 "limbaj.tab.c"
    break;

  case 64: /* expr: CHARVAL  */
#line 197 "limbaj.y"
                  {print_reduction("expr -> CHARVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1695 "limbaj.tab.c"
    break;

  case 65: /* expr: member_access  */
#line 198 "limbaj.y"
                        {print_reduction("expr -> member_access");(yyval.exprnode) = new Expression((yyvsp[0].symbol_node)); }
#line 1701 "limbaj.tab.c"
    break;

  case 66: /* expr: function_call  */
#line 199 "limbaj.y"
                        {print_reduction("epxr - function call ");(yyval.exprnode) = new Expression((yyvsp[0].funcCall));}
#line 1707 "limbaj.tab.c"
    break;

  case 67: /* expr: array_element  */
#line 200 "limbaj.y"
                        {print_reduction("epxr - array_element ");(yyval.exprnode) = new Expression((yyvsp[0].value_node));}
#line 1713 "limbaj.tab.c"
    break;

  case 68: /* expr: array_value  */
#line 201 "limbaj.y"
                      {print_reduction("epxr - array_value ");(yyval.exprnode) = new Expression((yyvsp[0].array_value_node));}
#line 1719 "limbaj.tab.c"
    break;

  case 69: /* assignment: ID '=' expr  */
#line 206 "limbaj.y"
                      {print_reduction(" ID = expr"); currentSymbolTable->assign((yyvsp[-2].node), (yyvsp[0].exprnode), nullptr);}
#line 1725 "limbaj.tab.c"
    break;

  case 70: /* assignment: ID array_indexing '=' expr  */
#line 207 "limbaj.y"
                                     {print_reduction(" ID = expr"); currentSymbolTable->assign((yyvsp[-3].node),(yyvsp[0].exprnode),(yyvsp[-2].arrayIndexingNode));}
#line 1731 "limbaj.tab.c"
    break;

  case 71: /* assignment: member_access '=' expr  */
#line 208 "limbaj.y"
                                 {print_reduction(" member_access = expr"); currentSymbolTable->assign((yyvsp[-2].symbol_node),(yyvsp[0].exprnode),nullptr);}
#line 1737 "limbaj.tab.c"
    break;

  case 72: /* ISCONST: CONST  */
#line 213 "limbaj.y"
                {print_reduction("isconst -> const");(yyval.node) = (yyvsp[0].node);}
#line 1743 "limbaj.tab.c"
    break;

  case 73: /* IF_S: IF '(' expr ')' '{'  */
#line 216 "limbaj.y"
                             { print_reduction("IF_S -> IF ( expr ) {");(yyval.node) = new RawNode("IF_S"); delete (yyvsp[-4].node);string expr = "if()"; ; currentSymbolTable = currentSymbolTable->addScope(expr);}
#line 1749 "limbaj.tab.c"
    break;

  case 74: /* IF_B: IF_S statements '}'  */
#line 219 "limbaj.y"
                            { print_reduction("IF_B -> IF_S statements }");(yyval.node) = new RawNode("IF_B"); backtrack_scope();}
#line 1755 "limbaj.tab.c"
    break;

  case 75: /* IF_ELSE_S: IF_S statements '}' ELSE '{'  */
#line 222 "limbaj.y"
                                          { print_reduction("IF_ELSE_S -> IF_S statements } ELSE {");(yyval.node) = new RawNode("IF_ELSE_S"); delete (yyvsp[-4].node); delete (yyvsp[-1].node);string elsescope = "else(" + currentSymbolTable->name+")"; backtrack_scope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}
#line 1761 "limbaj.tab.c"
    break;

  case 76: /* IF_ELSE_B: IF_ELSE_S statements '}'  */
#line 225 "limbaj.y"
                                    { print_reduction("IF_ELSE_B -> IF_ESLE_S statements }");(yyval.node) = new RawNode("IF_ELSE_B"); backtrack_scope();}
#line 1767 "limbaj.tab.c"
    break;

  case 77: /* class_s: CLASS ID '{'  */
#line 228 "limbaj.y"
                      {print_reduction("classb_S-> class id { ");(yyval.classNode) = currentSymbolTable = currentSymbolTable->add_class((yyvsp[-1].node));}
#line 1773 "limbaj.tab.c"
    break;

  case 78: /* decls_funcs: function  */
#line 230 "limbaj.y"
                      {print_reduction("decls_funcs -> funcs");}
#line 1779 "limbaj.tab.c"
    break;

  case 79: /* decls_funcs: declaration  */
#line 231 "limbaj.y"
                       {print_reduction("decls_funcs -> decls"); }
#line 1785 "limbaj.tab.c"
    break;

  case 80: /* decls_funcs: decls_funcs declaration  */
#line 232 "limbaj.y"
                                   {print_reduction("decls_funcs -> decls_funcs declaration");  }
#line 1791 "limbaj.tab.c"
    break;

  case 81: /* decls_funcs: decls_funcs function  */
#line 233 "limbaj.y"
                               {print_reduction("decls_funcs -> decls_funcs function");  }
#line 1797 "limbaj.tab.c"
    break;

  case 82: /* class_b: class_s decls_funcs '}'  */
#line 235 "limbaj.y"
                                  {print_reduction("classb -> class_S decls_funcs } "); backtrack_scope();}
#line 1803 "limbaj.tab.c"
    break;

  case 83: /* class_b: class_s '}'  */
#line 236 "limbaj.y"
                      {print_reduction("classb -> class_S } ");backtrack_scope();}
#line 1809 "limbaj.tab.c"
    break;

  case 84: /* member_access: ID '.' ID  */
#line 239 "limbaj.y"
                         {print_reduction("member_access -> ID . ID "); (yyval.symbol_node) = currentSymbolTable->check_member_access((yyvsp[-2].node),(yyvsp[0].node));}
#line 1815 "limbaj.tab.c"
    break;

  case 85: /* eval_expression: EVAL '(' expr ')'  */
#line 241 "limbaj.y"
                                     {print_reduction("evalexpr -> eval ( expr ) "); (yyvsp[-1].exprnode)->eval_wrapper(); }
#line 1821 "limbaj.tab.c"
    break;


#line 1825 "limbaj.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 243 "limbaj.y"


void yyerror(const char * s){
    printf("error: %s at lin/column:%d/%d", s, gRow,gCol);
}
 
int main(int argc, char** argv){ 
        gCol = gRow = 1; 
        rootSymbolTable = new SymbolTable("global");
        currentSymbolTable = rootSymbolTable;
        yyin = fopen(argv[1], "r");    
        yyparse(); 

        rootSymbolTable->printTable(0);
}

