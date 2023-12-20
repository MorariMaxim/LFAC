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
#include "generalNode.h"
#include "symbolTable.h"

extern FILE* yyin;
extern char* yytext;  
extern int yylex();
symbolTalbeNode * rootSymbolTable ;
symbolTalbeNode * currentSymbolTable;
int row, col;
void yyerror(const char * s);
vector<int> arrayStack;
types arrayType;
class generalNode; 
types returnType;

#define checkSymbol(x) {if ( currentSymbolTable->is_symbol_defined_in_path(x->content)==nullptr) printf("\nsymbol not defined %s at %d:%d\n",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->is_symbol_defined_in_path(x->content)}
#define checkRetType(x) {if (x->type != returnType){printf("incorrect return type");} else printf("correct return type");}
#define checkVoidReturn() {if (returnType != VOID) printf("incorrect return type"); else printf("correct return type");}
#define backtrackScope() {currentSymbolTable = currentSymbolTable->getParent();}
string join_buffer;
//#define join_helper(arg, ...) { join_buffer+=arg; if(__VA_ARGS__ != -1) join_helper(__VA_ARGS__); }
//#define join(arg, ...) {if(__VA_ARGS__ != -1)  join_helper(__VA_ARGS__);  printf("%s\n",join_buffer.c_str());} 

#line 99 "limbaj.tab.c"

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
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_RARROW = 12,                    /* RARROW  */
  YYSYMBOL_FN = 13,                        /* FN  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_CLASS = 15,                     /* CLASS  */
  YYSYMBOL_EVAL = 16,                      /* EVAL  */
  YYSYMBOL_INT_NR = 17,                    /* INT_NR  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_19_ = 19,                       /* '+'  */
  YYSYMBOL_20_ = 20,                       /* '-'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* ':'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* '['  */
  YYSYMBOL_30_ = 30,                       /* ']'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_progr = 35,                     /* progr  */
  YYSYMBOL_statements = 36,                /* statements  */
  YYSYMBOL_statement = 37,                 /* statement  */
  YYSYMBOL_const_type = 38,                /* const_type  */
  YYSYMBOL_init = 39,                      /* init  */
  YYSYMBOL_declaration = 40,               /* declaration  */
  YYSYMBOL_class_declaration = 41,         /* class_declaration  */
  YYSYMBOL_field_val = 42,                 /* field_val  */
  YYSYMBOL_ARRAY = 43,                     /* ARRAY  */
  YYSYMBOL_array_indexing = 44,            /* array_indexing  */
  YYSYMBOL_function = 45,                  /* function  */
  YYSYMBOL_function_s = 46,                /* function_s  */
  YYSYMBOL_function_call = 47,             /* function_call  */
  YYSYMBOL_id_parameters = 48,             /* id_parameters  */
  YYSYMBOL_rvalues = 49,                   /* rvalues  */
  YYSYMBOL_parameter_List = 50,            /* parameter_List  */
  YYSYMBOL_parameter = 51,                 /* parameter  */
  YYSYMBOL_expr = 52,                      /* expr  */
  YYSYMBOL_assignment = 53,                /* assignment  */
  YYSYMBOL_lval = 54,                      /* lval  */
  YYSYMBOL_rval = 55,                      /* rval  */
  YYSYMBOL_ISCONST = 56,                   /* ISCONST  */
  YYSYMBOL_IF_S = 57,                      /* IF_S  */
  YYSYMBOL_IF_B = 58,                      /* IF_B  */
  YYSYMBOL_IF_ELSE_S = 59,                 /* IF_ELSE_S  */
  YYSYMBOL_IF_ELSE_B = 60,                 /* IF_ELSE_B  */
  YYSYMBOL_class_s = 61,                   /* class_s  */
  YYSYMBOL_decls_funcs = 62,               /* decls_funcs  */
  YYSYMBOL_class_b = 63,                   /* class_b  */
  YYSYMBOL_member_access = 64,             /* member_access  */
  YYSYMBOL_eval_expression = 65            /* eval_expression  */
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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
      25,    26,    21,    19,    28,    20,    33,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,    23,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    31,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    76,    77,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    93,    94,    95,    96,
      99,   101,   102,   105,   107,   109,   110,   114,   115,   117,
     118,   121,   123,   125,   127,   128,   133,   137,   141,   143,
     146,   147,   150,   151,   154,   155,   158,   161,   162,   163,
     164,   165,   166,   167,   171,   174,   177,   180,   183,   186,
     189,   192,   195,   197,   198,   199,   200,   202,   203,   206,
     208
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "ID", "IF", "ELSE", "WHILE", "FOR", "CONST", "RARROW", "FN",
  "RETURN", "CLASS", "EVAL", "INT_NR", "TYPE", "'+'", "'-'", "'*'", "'/'",
  "';'", "'='", "'('", "')'", "':'", "','", "'['", "']'", "'}'", "'{'",
  "'.'", "$accept", "progr", "statements", "statement", "const_type",
  "init", "declaration", "class_declaration", "field_val", "ARRAY",
  "array_indexing", "function", "function_s", "function_call",
  "id_parameters", "rvalues", "parameter_List", "parameter", "expr",
  "assignment", "lval", "rval", "ISCONST", "IF_S", "IF_B", "IF_ELSE_S",
  "IF_ELSE_B", "class_s", "decls_funcs", "class_b", "member_access",
  "eval_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     133,     2,   -13,   -70,    22,    24,     8,   -70,   -70,    46,
     133,   -70,    45,   -70,    36,   -16,    71,   -70,    80,    39,
     -70,   150,    40,    47,    63,   133,   -70,   133,   -70,    26,
     -70,   -70,    66,    60,    17,     5,    84,     5,    83,    86,
       5,   -70,   -70,    59,   -70,   -70,    96,   -70,     5,   -70,
      61,   -70,     5,     5,     5,     5,   -70,   -70,     5,   -70,
      99,   116,   113,   -70,   -70,   -70,    34,   -70,   114,    88,
     -70,    73,   160,   -70,    94,   100,   -70,   134,    38,   -70,
     142,   -70,     5,   109,   -70,    98,   105,     5,   -70,    -5,
      -5,   -70,   -70,   -70,   128,   -70,   -70,   115,   -70,   110,
      76,   135,   -70,     5,   -70,   111,   130,   139,    81,   -70,
     -70,   155,   122,   -70,   -70,   126,   127,   -70,     5,   -70,
     152,   -70,   -70,   -70,    62,   -70,   153,    62,   -70,   -70,
     -70,   -70,   160,   140,   151,    62,   -70,     5,   -70,   154,
     160,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    51,     0,    57,     0,     0,     0,    52,    17,     0,
       2,     4,     0,     6,     0,     0,     0,    10,     0,     0,
      39,     0,     0,     0,     0,     0,     8,     0,     9,     0,
      14,    53,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     1,     5,     0,    22,    21,     0,    13,     0,    33,
       0,    12,     0,     0,     0,     0,     7,    11,     0,    16,
       0,     0,     0,    68,    64,    63,     0,    15,     0,    51,
      41,     0,    56,    42,     0,    69,    38,     0,     0,    62,
       0,    19,     0,     0,    20,     0,     0,     0,    32,    47,
      48,    50,    49,    54,    59,    61,    67,     0,    66,     0,
       0,     0,    40,     0,    29,     0,     0,     0,     0,    45,
      70,     0,     0,    28,    30,     0,     0,    65,     0,    24,
       0,    69,    43,    58,     0,    46,     0,     0,    18,    27,
      31,    60,    25,     0,    34,     0,    44,     0,    36,    35,
      26,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,    11,     0,   -69,   -70,   -25,   -70,   -70,   -70,
     -70,   -24,   -70,   -70,   148,   -70,   -70,    58,   -34,   -70,
     -70,   -33,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    84,    13,    14,   100,    15,
      16,    17,    18,    19,    20,    71,   108,   109,    21,    22,
      23,    73,    24,    25,    26,    27,    28,    29,    66,    30,
      31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    72,    74,    77,    64,    65,    80,    45,    33,   107,
      42,    69,    37,    46,    72,    86,    54,    55,    89,    90,
      91,    92,     7,    69,    72,    93,   -55,    34,    38,    50,
      39,    35,    62,    40,     7,    36,    60,     3,    61,     4,
      62,    97,    98,    70,     8,     3,    41,     4,   111,     3,
      42,    43,     8,    72,   115,   134,     8,    63,   107,    44,
      42,    42,    51,    57,   106,    96,   139,     1,     2,    72,
     122,    58,     3,     3,     4,    87,     5,     6,     7,     8,
       8,    59,    81,    82,   132,    68,     1,     2,    83,    67,
      75,     3,    88,     4,    47,     5,     6,     7,     8,   102,
      48,   103,   119,   140,   120,     1,     2,   126,    78,   127,
       3,    49,     4,    85,     5,     6,     7,     8,    79,    33,
      99,   101,     1,     2,   104,    34,   112,     3,   113,     4,
      94,     5,     6,     7,     8,   114,   116,   118,   117,     1,
       2,   121,   124,   123,     3,   125,     4,    95,     5,     6,
       7,     8,   129,    52,    53,    54,    55,   130,   133,   131,
     105,    52,    53,    54,    55,   135,     0,   137,   110,    52,
      53,    54,    55,    56,    52,    53,    54,    55,   128,    52,
      53,    54,    55,   138,    76,   136,   141
};

static const yytype_int16 yycheck[] =
{
      34,    35,    35,    37,    29,    29,    40,    23,     6,    78,
      10,     6,    25,    29,    48,    48,    21,    22,    52,    53,
      54,    55,    17,     6,    58,    58,    24,    25,     6,    18,
       6,    29,     6,    25,    17,    33,    25,    11,    27,    13,
       6,    66,    66,    26,    18,    11,     0,    13,    82,    11,
      50,     6,    18,    87,    87,   124,    18,    31,   127,    23,
      60,    61,    23,    23,    26,    31,   135,     6,     7,   103,
     103,    24,    11,    11,    13,    14,    15,    16,    17,    18,
      18,    18,    23,    24,   118,    25,     6,     7,    29,    23,
       6,    11,    31,    13,    23,    15,    16,    17,    18,    26,
      29,    28,    26,   137,    28,     6,     7,    26,    25,    28,
      11,    31,    13,    17,    15,    16,    17,    18,    32,     6,
       6,    33,     6,     7,    30,    25,    17,    11,    30,    13,
      31,    15,    16,    17,    18,    30,     8,    27,    23,     6,
       7,     6,    12,    32,    11,     6,    13,    31,    15,    16,
      17,    18,    30,    19,    20,    21,    22,    31,     6,    32,
      26,    19,    20,    21,    22,    12,    -1,    27,    26,    19,
      20,    21,    22,    23,    19,    20,    21,    22,    23,    19,
      20,    21,    22,    32,    36,   127,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    11,    13,    15,    16,    17,    18,    35,
      36,    37,    38,    40,    41,    43,    44,    45,    46,    47,
      48,    52,    53,    54,    56,    57,    58,    59,    60,    61,
      63,    64,    65,     6,    25,    29,    33,    25,     6,     6,
      25,     0,    37,     6,    23,    23,    29,    23,    29,    31,
      36,    23,    19,    20,    21,    22,    23,    23,    24,    18,
      36,    36,     6,    31,    40,    45,    62,    23,    25,     6,
      26,    49,    52,    55,    55,     6,    48,    52,    25,    32,
      52,    23,    24,    29,    39,    17,    55,    14,    31,    52,
      52,    52,    52,    55,    31,    31,    31,    40,    45,     6,
      42,    33,    26,    28,    30,    26,    26,    38,    50,    51,
      26,    52,    17,    30,    30,    55,     8,    23,    27,    26,
      28,     6,    55,    32,    12,     6,    26,    28,    23,    30,
      31,    32,    52,     6,    38,    12,    51,    27,    32,    38,
      52,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    38,    38,    39,    39,
      40,    40,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    50,    51,    52,    52,    52,
      52,    52,    52,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    62,    62,    62,    63,    63,    64,
      65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     2,     1,     1,
       1,     2,     2,     2,     1,     2,     2,     1,     3,     1,
       3,     2,     2,     2,     5,     3,     5,     5,     4,     4,
       4,     5,     3,     2,     6,     7,     7,     8,     3,     1,
       4,     3,     1,     3,     3,     1,     2,     3,     3,     3,
       3,     1,     1,     1,     3,     1,     1,     1,     5,     3,
       5,     3,     3,     1,     1,     3,     2,     3,     2,     3,
       4
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
#line 73 "limbaj.y"
                   { printx("\nsyntactically correct program\n"); }
#line 1253 "limbaj.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 74 "limbaj.y"
                     { printx("\nempty prog\n");}
#line 1259 "limbaj.tab.c"
    break;

  case 4: /* statements: statement  */
#line 76 "limbaj.y"
                       { (yyval.node) = (yyvsp[0].node); printx("\nstatements -> statement\n");}
#line 1265 "limbaj.tab.c"
    break;

  case 5: /* statements: statements statement  */
#line 77 "limbaj.y"
                                { (yyval.node) = (yyvsp[-1].node); printx("\nstatements -> statements statement\n");}
#line 1271 "limbaj.tab.c"
    break;

  case 6: /* statement: declaration  */
#line 80 "limbaj.y"
                      { printx("\nstmt -> declaration\n");}
#line 1277 "limbaj.tab.c"
    break;

  case 7: /* statement: expr ';'  */
#line 81 "limbaj.y"
                    { printx("\nstmt -> expr\n");}
#line 1283 "limbaj.tab.c"
    break;

  case 8: /* statement: IF_B  */
#line 82 "limbaj.y"
               { printx("\nstmt -> IF_B\n");}
#line 1289 "limbaj.tab.c"
    break;

  case 9: /* statement: IF_ELSE_B  */
#line 83 "limbaj.y"
                    { printx("\nstatement -> IF_ELSE_B\n");}
#line 1295 "limbaj.tab.c"
    break;

  case 10: /* statement: function  */
#line 84 "limbaj.y"
                   { printx("\nstatement -> function\n"); (yyval.node) = (yyvsp[0].funcNode);}
#line 1301 "limbaj.tab.c"
    break;

  case 11: /* statement: assignment ';'  */
#line 85 "limbaj.y"
                         {printx("\nstatement -> assignment\n");}
#line 1307 "limbaj.tab.c"
    break;

  case 12: /* statement: function_call ';'  */
#line 86 "limbaj.y"
                             {printx("statement -> functionCall\n");}
#line 1313 "limbaj.tab.c"
    break;

  case 13: /* statement: array_indexing ';'  */
#line 87 "limbaj.y"
                             {printx("statement -> array_indexing\n");(yyvsp[-1].arrayIndexingNode)->checkIndexes();}
#line 1319 "limbaj.tab.c"
    break;

  case 14: /* statement: class_b  */
#line 88 "limbaj.y"
                  {printx("statement -> class_b\n");}
#line 1325 "limbaj.tab.c"
    break;

  case 15: /* statement: eval_expression ';'  */
#line 89 "limbaj.y"
                              {printx("statement -> eval_expression\n");}
#line 1331 "limbaj.tab.c"
    break;

  case 16: /* const_type: ISCONST TYPE  */
#line 93 "limbaj.y"
                         {(yyval.TypeNode) = (yyvsp[0].TypeNode); (yyval.TypeNode)->is_const = 1;}
#line 1337 "limbaj.tab.c"
    break;

  case 18: /* init: '=' expr ';'  */
#line 95 "limbaj.y"
                    {(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 1343 "limbaj.tab.c"
    break;

  case 19: /* init: ';'  */
#line 96 "limbaj.y"
              {(yyval.exprnode) = nullptr;}
#line 1349 "limbaj.tab.c"
    break;

  case 20: /* declaration: const_type ID init  */
#line 99 "limbaj.y"
                                { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->define_symbol((yyvsp[-2].TypeNode),(yyvsp[-1].node)->content,(yyvsp[0].exprnode));  (yyval.node) = new generalNode(""); delete (yyvsp[-2].TypeNode); delete (yyvsp[-1].node); delete (yyvsp[0].exprnode);}
#line 1356 "limbaj.tab.c"
    break;

  case 21: /* declaration: ARRAY ';'  */
#line 101 "limbaj.y"
                      { printx("\ndecl -> array\n");printf("array name : %s\n",(yyvsp[-1].node)->content.c_str());ArrayType * at = new ArrayType("",0);currentSymbolTable->define_array_symbol((yyvsp[-1].node)->content,at); (yyval.node) = (yyvsp[-1].node);}
#line 1362 "limbaj.tab.c"
    break;

  case 22: /* declaration: class_declaration ';'  */
#line 102 "limbaj.y"
                                {printx("\n declaration -> class_declaration \n");}
#line 1368 "limbaj.tab.c"
    break;

  case 23: /* class_declaration: ID ID  */
#line 105 "limbaj.y"
                {printx("\n dclass_Declaration -> uninitialized \n");currentSymbolTable->define_user_symbol((yyvsp[-1].node),(yyvsp[0].node));}
#line 1374 "limbaj.tab.c"
    break;

  case 24: /* class_declaration: ID ID '(' field_val ')'  */
#line 107 "limbaj.y"
                                  {printx("\n dclass_Declaration -> initialized\n");currentSymbolTable->define_user_symbol((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-1].container));}
#line 1380 "limbaj.tab.c"
    break;

  case 25: /* field_val: ID ':' expr  */
#line 109 "limbaj.y"
                       {printx("\nfield_Val -> ID : expr\n"); (yyval.container) = new myVectorClass(); (yyval.container)->add_pointer((yyvsp[-2].node));(yyval.container)->add_pointer((yyvsp[0].exprnode));}
#line 1386 "limbaj.tab.c"
    break;

  case 26: /* field_val: field_val ',' ID ':' expr  */
#line 110 "limbaj.y"
                                    {printx("\nfield_Val -> field_val , ID : expr\n"); (yyval.container) = (yyvsp[-4].container); (yyval.container)->add_pointer((yyvsp[-2].node));(yyval.container)->add_pointer((yyvsp[0].exprnode));}
#line 1392 "limbaj.tab.c"
    break;

  case 27: /* ARRAY: const_type ID '[' INT_NR ']'  */
#line 114 "limbaj.y"
                                    { printx("\narray -> type id [ INT_NR ]\n"); (yyval.node) = (yyvsp[-3].node); /*arrayType=$1->type; arrayStack.push_back($4->value);*/}
#line 1398 "limbaj.tab.c"
    break;

  case 28: /* ARRAY: ARRAY '[' INT_NR ']'  */
#line 115 "limbaj.y"
                               { printx("\narray -> array [ INT_NR ]\n"); (yyval.node) = (yyvsp[-3].node);arrayStack.push_back((yyvsp[-1].int_type_node)->value);}
#line 1404 "limbaj.tab.c"
    break;

  case 29: /* array_indexing: ID '[' rval ']'  */
#line 117 "limbaj.y"
                                {printx("array_indexing -> ID '[' rval ']'");(yyval.arrayIndexingNode)  = new arrayIndexing((yyvsp[-3].node)); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode)); }
#line 1410 "limbaj.tab.c"
    break;

  case 30: /* array_indexing: array_indexing '[' rval ']'  */
#line 118 "limbaj.y"
                                      {printx("array_indexing -> array_indexing '[' INT_NR ']'"); (yyval.arrayIndexingNode) = (yyvsp[-3].arrayIndexingNode); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode));}
#line 1416 "limbaj.tab.c"
    break;

  case 31: /* function: function_s statements RETURN rval '}'  */
#line 121 "limbaj.y"
                                                { printx("\nfunction -> function_s statements return rval}\n"); 
                                                backtrackScope();(yyval.funcNode) = (yyvsp[-4].funcNode); checkRetType((yyvsp[-1].rvalNode));}
#line 1423 "limbaj.tab.c"
    break;

  case 32: /* function: function_s statements '}'  */
#line 123 "limbaj.y"
                                    { printx("\nfunction -> function_s statements }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-2].funcNode); checkVoidReturn();}
#line 1430 "limbaj.tab.c"
    break;

  case 33: /* function: function_s '}'  */
#line 125 "limbaj.y"
                         { printx("\nfunction -> function_s }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-1].funcNode); checkVoidReturn();}
#line 1437 "limbaj.tab.c"
    break;

  case 34: /* function: FN ID '(' ')' RARROW const_type  */
#line 127 "limbaj.y"
                                           { printx("\nfunctions_s -> FN ID ( ) RARROW const_type ;\n");(yyval.funcNode) = new functionNode((yyvsp[-4].node)->content,(yyvsp[0].TypeNode)->type,nullptr);}
#line 1443 "limbaj.tab.c"
    break;

  case 35: /* function: FN ID '(' parameter_List ')' RARROW const_type  */
#line 129 "limbaj.y"
         { printx("\nfunctions_s -> FN ID ( list ) RARROW const_type ;\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[0].TypeNode)->type,(yyvsp[-3].parListNode)->parameters);}
#line 1449 "limbaj.tab.c"
    break;

  case 36: /* function_s: FN ID '(' ')' RARROW const_type '{'  */
#line 133 "limbaj.y"
                                              { printx("\nfunctions_s -> fn id ( ) -> type {\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[-1].TypeNode)->type,nullptr);
                                        currentSymbolTable = currentSymbolTable->addFunction((yyval.funcNode)); returnType = (yyvsp[-1].TypeNode)->type;
                                         }
#line 1457 "limbaj.tab.c"
    break;

  case 37: /* function_s: FN ID '(' parameter_List ')' RARROW const_type '{'  */
#line 137 "limbaj.y"
                                                             { printx("\nfunctions_s -> fn id ( list ) -> type {\n");  (yyval.funcNode) = new functionNode((yyvsp[-6].node)->content,(yyvsp[-1].TypeNode)->type,(yyvsp[-4].parListNode)->parameters);
                                        currentSymbolTable=  currentSymbolTable->addFunction((yyval.funcNode));returnType = (yyvsp[-1].TypeNode)->type;
                                        }
#line 1465 "limbaj.tab.c"
    break;

  case 38: /* function_call: ID '.' id_parameters  */
#line 141 "limbaj.y"
                                     {printx("functioncall -> ID . id_parameters\n"); (yyval.funcCall) = new functionCall((yyvsp[-2].node),(yyvsp[0].container));
                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1472 "limbaj.tab.c"
    break;

  case 39: /* function_call: id_parameters  */
#line 143 "limbaj.y"
                               {printx("functioncall -> id_parameters\n"); (yyval.funcCall) = new functionCall(nullptr,(yyvsp[0].container)); 

                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1480 "limbaj.tab.c"
    break;

  case 40: /* id_parameters: ID '(' rvalues ')'  */
#line 146 "limbaj.y"
                                  {printx("id_parameters -> id ( rvalues )\n");(yyval.container) = new myVectorClass(); (yyval.container)->add_pointer((yyvsp[-3].node));(yyval.container)->add_pointer((yyvsp[-1].rvaluesNode)); }
#line 1486 "limbaj.tab.c"
    break;

  case 41: /* id_parameters: ID '(' ')'  */
#line 147 "limbaj.y"
                        {printx("id_parameters -> id ()\n");(yyval.container) = new myVectorClass(); (yyval.container)->add_pointer((yyvsp[-2].node));}
#line 1492 "limbaj.tab.c"
    break;

  case 42: /* rvalues: rval  */
#line 150 "limbaj.y"
              {printx("rvalues -> rval\n");(yyval.rvaluesNode) = new rValueNodes(); (yyval.rvaluesNode)->addRvalue((yyvsp[0].rvalNode)); }
#line 1498 "limbaj.tab.c"
    break;

  case 43: /* rvalues: rvalues ',' rval  */
#line 151 "limbaj.y"
                           {printx("rvalues -> rvalues , rval\n");(yyvsp[-2].rvaluesNode)->addRvalue((yyvsp[0].rvalNode));(yyval.rvaluesNode)=(yyvsp[-2].rvaluesNode);}
#line 1504 "limbaj.tab.c"
    break;

  case 44: /* parameter_List: parameter_List ',' parameter  */
#line 154 "limbaj.y"
                                              {printx("parameter list -> parameter llist , parameter\n"); (yyval.parListNode) = (yyvsp[-2].parListNode); (yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1510 "limbaj.tab.c"
    break;

  case 45: /* parameter_List: parameter  */
#line 155 "limbaj.y"
                    {printx("parameter list -> parameter\n");(yyval.parListNode) = new parameterList();(yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1516 "limbaj.tab.c"
    break;

  case 46: /* parameter: const_type ID  */
#line 158 "limbaj.y"
                         { printx("\nparamter -> type id"); (yyval.parameterNode) = new Symbol(0,(yyvsp[-1].TypeNode)->type,(yyvsp[0].node)->content,nullptr);}
#line 1522 "limbaj.tab.c"
    break;

  case 47: /* expr: expr '+' expr  */
#line 161 "limbaj.y"
                        { printx("\nexpr -> expr + expr\n");(yyval.exprnode) = new ExpressionNode(OperTypes::ADD,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"+" + (yyvsp[0].exprnode)->content);  }
#line 1528 "limbaj.tab.c"
    break;

  case 48: /* expr: expr '-' expr  */
#line 162 "limbaj.y"
                        { printx("\nexpr -> expr - expr\n");(yyval.exprnode) = new ExpressionNode(OperTypes::SUB,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"-" + (yyvsp[0].exprnode)->content);  }
#line 1534 "limbaj.tab.c"
    break;

  case 49: /* expr: expr '/' expr  */
#line 163 "limbaj.y"
                        { printx("\nexpr -> expr / expr\n");(yyval.exprnode) = new ExpressionNode(OperTypes::DIV,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"/" + (yyvsp[0].exprnode)->content);  }
#line 1540 "limbaj.tab.c"
    break;

  case 50: /* expr: expr '*' expr  */
#line 164 "limbaj.y"
                        { printx("\nexpr -> expr * expr\n");(yyval.exprnode) = new ExpressionNode(OperTypes::MUL,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"*" + (yyvsp[0].exprnode)->content);  }
#line 1546 "limbaj.tab.c"
    break;

  case 51: /* expr: ID  */
#line 165 "limbaj.y"
             {printf("\nexpr -> ID\n");(yyval.exprnode) = new ExpressionNode((yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1552 "limbaj.tab.c"
    break;

  case 52: /* expr: INT_NR  */
#line 166 "limbaj.y"
                 {printf("\nexpr -> INT_NR\n");(yyval.exprnode) = new ExpressionNode((yyvsp[0].int_type_node)); }
#line 1558 "limbaj.tab.c"
    break;

  case 53: /* expr: member_access  */
#line 167 "limbaj.y"
                        {printf("\nexpr -> member_access\n");(yyval.exprnode) = new ExpressionNode((yyvsp[0].TypeNode)); }
#line 1564 "limbaj.tab.c"
    break;

  case 54: /* assignment: lval '=' rval  */
#line 171 "limbaj.y"
                           { (yyval.node) = new generalNode((yyvsp[-2].node)->content +"=" + (yyvsp[0].rvalNode)->content); delete (yyvsp[-2].node); delete (yyvsp[0].rvalNode);}
#line 1570 "limbaj.tab.c"
    break;

  case 55: /* lval: ID  */
#line 174 "limbaj.y"
                {printx("lval -> id\n"); checkSymbol((yyvsp[0].node));  }
#line 1576 "limbaj.tab.c"
    break;

  case 56: /* rval: expr  */
#line 177 "limbaj.y"
                 {printx("\nrval -> expression\n"); Symbol* _res = currentSymbolTable->create_temp_symbol((yyvsp[0].exprnode));
                 (yyval.rvalNode) = new IntType((yyvsp[0].exprnode)->content);}
#line 1583 "limbaj.tab.c"
    break;

  case 57: /* ISCONST: CONST  */
#line 180 "limbaj.y"
                {printx("isconst -> const\n");(yyval.node) = (yyvsp[0].node);}
#line 1589 "limbaj.tab.c"
    break;

  case 58: /* IF_S: IF '(' expr ')' '{'  */
#line 183 "limbaj.y"
                             { printx("\nIF_S -> IF ( expr ) {\n");(yyval.node) = new generalNode("IF_S"); delete (yyvsp[-4].node);string expr = "if("; expr+=(yyvsp[-2].exprnode)->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}
#line 1595 "limbaj.tab.c"
    break;

  case 59: /* IF_B: IF_S statements '}'  */
#line 186 "limbaj.y"
                            { printx("\nIF_B -> IF_S statements }\n");(yyval.node) = new generalNode("IF_B"); backtrackScope();}
#line 1601 "limbaj.tab.c"
    break;

  case 60: /* IF_ELSE_S: IF_S statements '}' ELSE '{'  */
#line 189 "limbaj.y"
                                          { printx("\nIF_ELSE_S -> IF_S statements } ELSE {\n");(yyval.node) = new generalNode("IF_ELSE_S"); delete (yyvsp[-4].node); delete (yyvsp[-1].node);string elsescope = "else(" + currentSymbolTable->name+")"; backtrackScope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}
#line 1607 "limbaj.tab.c"
    break;

  case 61: /* IF_ELSE_B: IF_ELSE_S statements '}'  */
#line 192 "limbaj.y"
                                    { printx("\nIF_ELSE_B -> IF_ESLE_S statements }\n");(yyval.node) = new generalNode("IF_ELSE_B"); backtrackScope();}
#line 1613 "limbaj.tab.c"
    break;

  case 62: /* class_s: CLASS ID '{'  */
#line 195 "limbaj.y"
                      {printx("\nclassb_S-> class id { \n");(yyval.classNode) = currentSymbolTable = currentSymbolTable->newClass((yyvsp[-1].node));}
#line 1619 "limbaj.tab.c"
    break;

  case 63: /* decls_funcs: function  */
#line 197 "limbaj.y"
                      {printx("\ndecls_funcs -> funcs\n");}
#line 1625 "limbaj.tab.c"
    break;

  case 64: /* decls_funcs: declaration  */
#line 198 "limbaj.y"
                       {printx("\ndecls_funcs -> decls\n"); }
#line 1631 "limbaj.tab.c"
    break;

  case 65: /* decls_funcs: decls_funcs declaration ';'  */
#line 199 "limbaj.y"
                                      {printx("\ndecls_funcs -> decls_funcs declaration\n");  }
#line 1637 "limbaj.tab.c"
    break;

  case 66: /* decls_funcs: decls_funcs function  */
#line 200 "limbaj.y"
                               {printx("\ndecls_funcs -> decls_funcs function\n");  }
#line 1643 "limbaj.tab.c"
    break;

  case 67: /* class_b: class_s decls_funcs '}'  */
#line 202 "limbaj.y"
                                  {printx("\nclassb -> class_S decls_funcs } \n"); backtrackScope();}
#line 1649 "limbaj.tab.c"
    break;

  case 68: /* class_b: class_s '}'  */
#line 203 "limbaj.y"
                      {printx("\nclassb -> class_S } \n");backtrackScope();}
#line 1655 "limbaj.tab.c"
    break;

  case 69: /* member_access: ID '.' ID  */
#line 206 "limbaj.y"
                         {printx("\nmember_access -> ID . ID \n"); (yyval.TypeNode) = currentSymbolTable->check_member_access((yyvsp[-2].node),(yyvsp[0].node));}
#line 1661 "limbaj.tab.c"
    break;

  case 70: /* eval_expression: EVAL '(' expr ')'  */
#line 208 "limbaj.y"
                                     {printx("\nevalexpr -> eval ( expr ) \n"); (yyvsp[-1].exprnode)->eval_wrapper(); }
#line 1667 "limbaj.tab.c"
    break;


#line 1671 "limbaj.tab.c"

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

#line 210 "limbaj.y"

 
void yyerror(const char * s){
    printf("\nerror: %s at lin/column:%d/%d\n", s, row,col);
}
 
int main(int argc, char** argv){
 
        col = row = 1; 
        rootSymbolTable = new symbolTalbeNode("global");
        currentSymbolTable = rootSymbolTable;
        yyin = fopen(argv[1], "r");    
        yyparse(); 

        rootSymbolTable->printTable(0);
}

