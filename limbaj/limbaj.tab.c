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

#define checkSymbol(x) {if ( currentSymbolTable->isSymbolDefinedInPath(x->content)==nullptr) printf("\nsymbol not defined %s at %d:%d\n",x->content.c_str(),x->row,x->col); }
#define getSymbol(x) {currentSymbolTable->isSymbolDefinedInPath(x->content)}
#define checkRetType(x) {if (x->type != returnType){printf("incorrect return type");} else printf("correct return type");}
#define checkVoidReturn() {if (returnType != VOID) printf("incorrect return type"); else printf("correct return type");}
#define backtrackScope() {currentSymbolTable = currentSymbolTable->getParent();}
string join_buffer;
//#define join_helper(arg, ...) { join_buffer+=arg; if(__VA_ARGS__ != -1) join_helper(__VA_ARGS__); }
//#define join(arg, ...) {if(__VA_ARGS__ != -1)  join_helper(__VA_ARGS__);  printf("%s\n",join_buffer.c_str());} 

#line 100 "limbaj.tab.c"

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
  YYSYMBOL_NR = 6,                         /* NR  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_RARROW = 13,                    /* RARROW  */
  YYSYMBOL_FN = 14,                        /* FN  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_CLASS = 16,                     /* CLASS  */
  YYSYMBOL_TYPE = 17,                      /* TYPE  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* ';'  */
  YYSYMBOL_20_ = 20,                       /* '['  */
  YYSYMBOL_21_ = 21,                       /* ']'  */
  YYSYMBOL_22_ = 22,                       /* '}'  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* '{'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_progr = 30,                     /* progr  */
  YYSYMBOL_statement = 31,                 /* statement  */
  YYSYMBOL_declarations = 32,              /* declarations  */
  YYSYMBOL_declaration = 33,               /* declaration  */
  YYSYMBOL_ARRAY = 34,                     /* ARRAY  */
  YYSYMBOL_array_indexing = 35,            /* array_indexing  */
  YYSYMBOL_functions = 36,                 /* functions  */
  YYSYMBOL_function = 37,                  /* function  */
  YYSYMBOL_function_s = 38,                /* function_s  */
  YYSYMBOL_function_call = 39,             /* function_call  */
  YYSYMBOL_rvalues = 40,                   /* rvalues  */
  YYSYMBOL_parameter_List = 41,            /* parameter_List  */
  YYSYMBOL_parameter = 42,                 /* parameter  */
  YYSYMBOL_expr = 43,                      /* expr  */
  YYSYMBOL_assignment = 44,                /* assignment  */
  YYSYMBOL_lval = 45,                      /* lval  */
  YYSYMBOL_rval = 46,                      /* rval  */
  YYSYMBOL_ISCONST = 47,                   /* ISCONST  */
  YYSYMBOL_IF_S = 48,                      /* IF_S  */
  YYSYMBOL_IF_B = 49,                      /* IF_B  */
  YYSYMBOL_IF_ELSE_S = 50,                 /* IF_ELSE_S  */
  YYSYMBOL_IF_ELSE_B = 51,                 /* IF_ELSE_B  */
  YYSYMBOL_class_s = 52,                   /* class_s  */
  YYSYMBOL_decls_funcs = 53,               /* decls_funcs  */
  YYSYMBOL_class_b = 54                    /* class_b  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


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
      23,    24,     2,    27,    26,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    22,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    65,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    79,    80,    89,    91,    93,    95,
      97,    99,   101,   102,   104,   105,   108,   109,   111,   113,
     115,   117,   118,   122,   126,   131,   133,   137,   138,   141,
     142,   145,   148,   149,   150,   151,   154,   157,   160,   161,
     164,   167,   170,   173,   176,   179,   181,   182,   183,   185,
     186
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
  "ASSIGN", "NR", "ID", "IF", "ELSE", "WHILE", "FOR", "CONST", "RARROW",
  "FN", "RETURN", "CLASS", "TYPE", "'='", "';'", "'['", "']'", "'}'",
  "'('", "')'", "'{'", "','", "'+'", "'-'", "$accept", "progr",
  "statement", "declarations", "declaration", "ARRAY", "array_indexing",
  "functions", "function", "function_s", "function_call", "rvalues",
  "parameter_List", "parameter", "expr", "assignment", "lval", "rval",
  "ISCONST", "IF_S", "IF_B", "IF_ELSE_S", "IF_ELSE_B", "class_s",
  "decls_funcs", "class_b", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     102,   -31,     1,   -12,   -31,    11,    15,    27,    41,   102,
       0,   -31,    44,    35,   -31,    54,   -31,   104,   -31,    61,
      64,   102,   -31,   102,   -31,    84,   -31,    33,   127,    -1,
     129,    70,    62,   110,   -31,   102,    82,   -31,   -31,    93,
     127,   -31,    32,   129,   129,   127,    96,    66,    78,   -31,
       0,    91,   -31,    90,   -31,   -31,   -31,    92,   -31,    43,
     -31,   -31,    99,    -8,   -31,   129,   -31,   105,   100,   103,
     127,   -31,   104,   104,    98,   119,   130,   -31,   -31,   -31,
     108,   -31,   -31,   127,   115,   134,   131,    51,   -31,     9,
     121,   -31,   -31,   123,   -31,   129,   -31,   118,   -31,   -31,
     -31,   132,   133,   135,   -31,   -31,   -31,    23,   -31,     7,
     136,   -31,   -31,   -31,   -31,    34,   -31,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    45,    44,     0,    50,     0,     0,     0,     0,     2,
       5,    14,     0,    12,     9,     0,    11,     6,    10,     0,
       0,     0,     7,     0,     8,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     1,     4,     0,    15,    20,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,    60,
      57,    56,    26,     0,    21,    48,    49,     0,    36,     0,
      37,    44,     0,     0,    55,     0,    19,     0,     0,     0,
       0,    29,    42,    43,     0,     0,    52,    54,    27,    59,
      58,    24,    35,     0,     0,     0,     0,     0,    40,     0,
       0,    23,    25,     0,    46,     0,    17,     0,    38,    51,
      41,     0,     0,     0,    18,    22,    28,     0,    53,     0,
       0,    39,    16,    31,    33,     0,    32,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,    10,   -23,    -7,   -31,   -31,   -31,   -24,   -31,
     -31,   -31,   -31,    45,   -30,   -31,   -31,   -25,   -31,   -31,
     -31,   -31,   -31,   -31,   122,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,    35,    10,    11,    12,    13,    51,    14,    15,
      16,    59,    87,    88,    17,    18,    19,    57,    20,    21,
      22,    23,    24,    25,    80,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    52,    50,    37,    60,    55,    56,    36,    27,    85,
       9,    30,     4,    72,    73,    69,    86,     7,    31,   -47,
      74,    28,    32,    58,    29,    42,   113,    78,   104,    52,
      50,    47,   114,    48,    33,    89,    43,    44,     1,     2,
       3,    34,   112,    37,     4,    93,     5,    70,     6,     7,
      43,    44,    54,   116,    71,    40,    52,    50,    98,   117,
       1,     2,     3,    38,    39,   107,     4,    82,     5,    83,
       6,     7,     1,     2,     3,   102,    41,   103,     4,    45,
       5,    46,     6,     7,     1,     2,     3,    64,    76,    27,
       4,    36,     5,    63,     6,     7,     4,    36,     5,    68,
      77,     7,     4,    75,     5,     5,    49,     7,     1,     2,
       3,    90,    79,    81,     4,    36,     5,    94,     6,     7,
       4,    91,     5,    84,    92,     7,    43,    44,    65,    66,
      67,    43,    44,    55,    56,     1,    61,    95,    96,    97,
      99,   100,   105,   108,   101,   106,   110,    53,   111,   109,
       0,     0,    85,   115
};

static const yytype_int8 yycheck[] =
{
      30,    25,    25,    10,    29,     6,     7,     7,     7,    17,
       0,    23,    12,    43,    44,    40,    24,    17,     7,    18,
      45,    20,     7,    24,    23,    15,    19,    51,    19,    53,
      53,    21,    25,    23,     7,    65,    27,    28,     6,     7,
       8,     0,    19,    50,    12,    70,    14,    15,    16,    17,
      27,    28,    19,    19,    22,    20,    80,    80,    83,    25,
       6,     7,     8,    19,    20,    95,    12,    24,    14,    26,
      16,    17,     6,     7,     8,    24,    22,    26,    12,    18,
      14,    17,    16,    17,     6,     7,     8,    25,    22,     7,
      12,     7,    14,    23,    16,    17,    12,     7,    14,     6,
      22,    17,    12,     7,    14,    14,    22,    17,     6,     7,
       8,     6,    22,    21,    12,     7,    14,    19,    16,    17,
      12,    21,    14,    24,    21,    17,    27,    28,    18,    19,
      20,    27,    28,     6,     7,     6,     7,    18,    19,     9,
      25,     7,    21,    25,    13,    22,    13,    25,   103,    17,
      -1,    -1,    17,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    12,    14,    16,    17,    30,    31,
      32,    33,    34,    35,    37,    38,    39,    43,    44,    45,
      47,    48,    49,    50,    51,    52,    54,     7,    20,    23,
      23,     7,     7,     7,     0,    31,     7,    33,    19,    20,
      20,    22,    31,    27,    28,    18,    17,    31,    31,    22,
      32,    36,    37,    53,    19,     6,     7,    46,    24,    40,
      46,     7,    43,    23,    25,    18,    19,    20,     6,    46,
      15,    22,    43,    43,    46,     7,    22,    22,    37,    22,
      53,    21,    24,    26,    24,    17,    24,    41,    42,    43,
       6,    21,    21,    46,    19,    18,    19,     9,    46,    25,
       7,    13,    24,    26,    19,    21,    22,    43,    25,    17,
      13,    42,    19,    19,    25,    17,    19,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    32,    32,    33,    33,    33,    33,
      33,    33,    34,    34,    35,    35,    36,    36,    37,    37,
      37,    37,    37,    38,    38,    39,    39,    40,    40,    41,
      41,    42,    43,    43,    43,    43,    44,    45,    46,    46,
      47,    48,    49,    50,    51,    52,    53,    53,    53,    54,
      54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     6,     4,     5,     3,
       2,     3,     5,     4,     4,     4,     1,     2,     5,     3,
       2,     7,     8,     7,     8,     4,     3,     1,     3,     3,
       1,     2,     3,     3,     1,     1,     4,     1,     1,     1,
       1,     5,     3,     5,     3,     3,     1,     1,     2,     3,
       2
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
  case 2: /* progr: statement  */
#line 64 "limbaj.y"
                    { printx("\nsyntactically correct program\n");}
#line 1221 "limbaj.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 65 "limbaj.y"
                    { printx("\nempty prog\n");}
#line 1227 "limbaj.tab.c"
    break;

  case 4: /* statement: statement statement  */
#line 68 "limbaj.y"
                               { (yyval.node) = (yyvsp[-1].node); printx("\nstmt -> stmt stmt\n");}
#line 1233 "limbaj.tab.c"
    break;

  case 5: /* statement: declarations  */
#line 69 "limbaj.y"
                       { printx("\nstmt -> declaration\n");}
#line 1239 "limbaj.tab.c"
    break;

  case 6: /* statement: expr  */
#line 70 "limbaj.y"
               { printx("\nstmt -> expr\n");}
#line 1245 "limbaj.tab.c"
    break;

  case 7: /* statement: IF_B  */
#line 71 "limbaj.y"
               { printx("\nstmt -> IF_B\n");}
#line 1251 "limbaj.tab.c"
    break;

  case 8: /* statement: IF_ELSE_B  */
#line 72 "limbaj.y"
                    { printx("\nstatement -> IF_ELSE_B\n");}
#line 1257 "limbaj.tab.c"
    break;

  case 9: /* statement: function  */
#line 73 "limbaj.y"
                   { printx("\nstatement -> function\n"); (yyval.node) = (yyvsp[0].funcNode);}
#line 1263 "limbaj.tab.c"
    break;

  case 10: /* statement: assignment  */
#line 74 "limbaj.y"
                     {printx("\nstatement -> assignment\n");}
#line 1269 "limbaj.tab.c"
    break;

  case 11: /* statement: function_call  */
#line 75 "limbaj.y"
                        {printx("statement -> functionCall\n");}
#line 1275 "limbaj.tab.c"
    break;

  case 12: /* statement: array_indexing  */
#line 76 "limbaj.y"
                         {printx("statement -> array_indexing\n");(yyvsp[0].arrayIndexingNode)->checkIndexes();}
#line 1281 "limbaj.tab.c"
    break;

  case 13: /* statement: class_b  */
#line 77 "limbaj.y"
                  {printx("statement -> class_b\n");}
#line 1287 "limbaj.tab.c"
    break;

  case 14: /* declarations: declaration  */
#line 79 "limbaj.y"
                          {printx("decls -> decl\n"); (yyval.node)=(yyvsp[0].node);}
#line 1293 "limbaj.tab.c"
    break;

  case 15: /* declarations: declarations declaration  */
#line 80 "limbaj.y"
                                   {printx("decls -> decls decl\n"); (yyval.node) = new generalNode((yyvsp[-1].node)->content + " " + (yyvsp[0].node)->content); delete (yyvsp[-1].node); delete (yyvsp[0].node);}
#line 1299 "limbaj.tab.c"
    break;

  case 16: /* declaration: ISCONST TYPE ID '=' expr ';'  */
#line 89 "limbaj.y"
                                       { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->defineSymbol(1,(yyvsp[-4].typenode)->type,(yyvsp[-3].node)->content,(yyvsp[-1].exprnode));  (yyval.node) = new generalNode((yyvsp[-5].node)->content + " " + (yyvsp[-4].typenode)->content+ " " + (yyvsp[-3].node)->content+ " " + (yyvsp[-1].exprnode)->content); delete (yyvsp[-5].node); delete (yyvsp[-4].typenode);delete (yyvsp[-3].node); delete (yyvsp[-1].exprnode);}
#line 1306 "limbaj.tab.c"
    break;

  case 17: /* declaration: ISCONST TYPE ID ';'  */
#line 91 "limbaj.y"
                              { printx("\ndecl->const type id;\n");
                                            currentSymbolTable->defineSymbol(1,(yyvsp[-2].typenode)->type,(yyvsp[-1].node)->content,nullptr);  (yyval.node) = new generalNode("const " + (yyvsp[-3].node)->content + " " + (yyvsp[-2].typenode)->content); delete (yyvsp[-3].node); delete (yyvsp[-2].typenode);delete (yyvsp[-1].node);}
#line 1313 "limbaj.tab.c"
    break;

  case 18: /* declaration: TYPE ID '=' expr ';'  */
#line 93 "limbaj.y"
                               { printx("\ndecl->type id init;\n");
                                            currentSymbolTable->defineSymbol(0,(yyvsp[-4].typenode)->type,(yyvsp[-3].node)->content,(yyvsp[-1].exprnode));  (yyval.node) = new generalNode((yyvsp[-4].typenode)->content + " " + (yyvsp[-3].node)->content+ " = " + (yyvsp[-1].exprnode)->content); delete (yyvsp[-4].typenode); delete (yyvsp[-3].node); delete (yyvsp[-1].exprnode);}
#line 1320 "limbaj.tab.c"
    break;

  case 19: /* declaration: TYPE ID ';'  */
#line 95 "limbaj.y"
                      { printx("\ndecl->type id;\n");
                                        currentSymbolTable->defineSymbol(0,(yyvsp[-2].typenode)->type,(yyvsp[-1].node)->content,nullptr);  (yyval.node) = new generalNode((yyvsp[-2].typenode)->content + " " + (yyvsp[-1].node)->content); delete (yyvsp[-2].typenode); delete (yyvsp[-1].node);}
#line 1327 "limbaj.tab.c"
    break;

  case 20: /* declaration: ARRAY ';'  */
#line 97 "limbaj.y"
                    { printx("\ndecl -> array\n");printf("array name : %s\n",(yyvsp[-1].node)->content.c_str());arraySymbol * as = arraySymbol::buildFromStack(0);currentSymbolTable->defineSymbol((yyvsp[-1].node)->content,as); (yyval.node) = (yyvsp[-1].node);}
#line 1333 "limbaj.tab.c"
    break;

  case 21: /* declaration: ID ID ';'  */
#line 99 "limbaj.y"
                    {printx("\ndecl -> ID ID ;\n"); if(!currentSymbolTable->isClassDefined((yyvsp[-2].node)->content)) printf("undefined class %s\n",(yyvsp[-2].node)->content.c_str()); }
#line 1339 "limbaj.tab.c"
    break;

  case 22: /* ARRAY: TYPE ID '[' NR ']'  */
#line 101 "limbaj.y"
                          { printx("\narray -> type id [ nr ]\n"); (yyval.node) = (yyvsp[-3].node); arrayType=(yyvsp[-4].typenode)->type; arrayStack.push_back(atoi((yyvsp[-1].node)->content.c_str()));}
#line 1345 "limbaj.tab.c"
    break;

  case 23: /* ARRAY: ARRAY '[' NR ']'  */
#line 102 "limbaj.y"
                           { printx("\narray -> array [ nr ]\n"); (yyval.node) = (yyvsp[-3].node);arrayStack.push_back(atoi((yyvsp[-1].node)->content.c_str()));}
#line 1351 "limbaj.tab.c"
    break;

  case 24: /* array_indexing: ID '[' rval ']'  */
#line 104 "limbaj.y"
                                {printx("array_indexing -> ID '[' rval ']'");(yyval.arrayIndexingNode)  = new arrayIndexing((yyvsp[-3].node)); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode)); }
#line 1357 "limbaj.tab.c"
    break;

  case 25: /* array_indexing: array_indexing '[' rval ']'  */
#line 105 "limbaj.y"
                                      {printx("array_indexing -> array_indexing '[' NR ']'"); (yyval.arrayIndexingNode) = (yyvsp[-3].arrayIndexingNode); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode));}
#line 1363 "limbaj.tab.c"
    break;

  case 26: /* functions: function  */
#line 108 "limbaj.y"
                    {printx("funcs -> func\n"); (yyval.node) = new generalNode((yyvsp[0].funcNode)->name);}
#line 1369 "limbaj.tab.c"
    break;

  case 27: /* functions: functions function  */
#line 109 "limbaj.y"
                             {printx("funcs -> funcs func\n"); (yyval.node) = new generalNode((yyvsp[-1].node)->content + " " + (yyvsp[0].funcNode)->content); delete (yyvsp[-1].node); }
#line 1375 "limbaj.tab.c"
    break;

  case 28: /* function: function_s statement RETURN rval '}'  */
#line 111 "limbaj.y"
                                               { printx("\nfunction -> function_s statement return rval}\n"); 
                                                backtrackScope();(yyval.funcNode) = (yyvsp[-4].funcNode); checkRetType((yyvsp[-1].rvalNode));}
#line 1382 "limbaj.tab.c"
    break;

  case 29: /* function: function_s statement '}'  */
#line 113 "limbaj.y"
                                   { printx("\nfunction -> function_s statement }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-2].funcNode); checkVoidReturn();}
#line 1389 "limbaj.tab.c"
    break;

  case 30: /* function: function_s '}'  */
#line 115 "limbaj.y"
                         { printx("\nfunction -> function_s statement }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-1].funcNode); checkVoidReturn();}
#line 1396 "limbaj.tab.c"
    break;

  case 31: /* function: FN ID '(' ')' RARROW TYPE ';'  */
#line 117 "limbaj.y"
                                        { printx("\nfunctions_s -> FN ID ( ) RARROW TYPE ;\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[-1].typenode)->type,nullptr);}
#line 1402 "limbaj.tab.c"
    break;

  case 32: /* function: FN ID '(' parameter_List ')' RARROW TYPE ';'  */
#line 118 "limbaj.y"
                                                       { printx("\nfunctions_s -> FN ID ( list ) RARROW TYPE ;\n");(yyval.funcNode) = new functionNode((yyvsp[-6].node)->content,(yyvsp[-1].typenode)->type,(yyvsp[-4].parListNode)->parameters);}
#line 1408 "limbaj.tab.c"
    break;

  case 33: /* function_s: FN ID '(' ')' RARROW TYPE '{'  */
#line 122 "limbaj.y"
                                        { printx("\nfunctions_s -> fn id ( ) -> type {\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[-1].typenode)->type,nullptr);
                                        currentSymbolTable = currentSymbolTable->addFunction((yyval.funcNode)); returnType = (yyvsp[-1].typenode)->type;
                                         }
#line 1416 "limbaj.tab.c"
    break;

  case 34: /* function_s: FN ID '(' parameter_List ')' RARROW TYPE '{'  */
#line 126 "limbaj.y"
                                                       { printx("\nfunctions_s -> fn id ( list ) -> type {\n");  (yyval.funcNode) = new functionNode((yyvsp[-6].node)->content,(yyvsp[-1].typenode)->type,(yyvsp[-4].parListNode)->parameters);
                                        currentSymbolTable=  currentSymbolTable->addFunction((yyval.funcNode));returnType = (yyvsp[-1].typenode)->type;
                                        }
#line 1424 "limbaj.tab.c"
    break;

  case 35: /* function_call: ID '(' rvalues ')'  */
#line 131 "limbaj.y"
                                  {printx("functioncall -> id ( rvalues )\n");(yyval.funcCall) = new functionCall((yyvsp[-3].node)->content); (yyval.funcCall)->setArgs((yyvsp[-1].rvaluesNode)); 
                        bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1431 "limbaj.tab.c"
    break;

  case 36: /* function_call: ID '(' ')'  */
#line 133 "limbaj.y"
                        {printx("functioncall -> id ()\n");(yyval.funcCall) = new functionCall((yyvsp[-2].node)->content);  
                        bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1438 "limbaj.tab.c"
    break;

  case 37: /* rvalues: rval  */
#line 137 "limbaj.y"
              {printx("rvalues -> rval\n");(yyval.rvaluesNode) = new rValueNodes(); (yyval.rvaluesNode)->addRvalue((yyvsp[0].rvalNode)); }
#line 1444 "limbaj.tab.c"
    break;

  case 38: /* rvalues: rvalues ',' rval  */
#line 138 "limbaj.y"
                           {printx("rvalues -> rvalues , rval\n");(yyvsp[-2].rvaluesNode)->addRvalue((yyvsp[0].rvalNode));(yyval.rvaluesNode)=(yyvsp[-2].rvaluesNode);}
#line 1450 "limbaj.tab.c"
    break;

  case 39: /* parameter_List: parameter_List ',' parameter  */
#line 141 "limbaj.y"
                                              {printx("parameter list -> parameter llist , parameter\n"); (yyval.parListNode) = (yyvsp[-2].parListNode); (yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1456 "limbaj.tab.c"
    break;

  case 40: /* parameter_List: parameter  */
#line 142 "limbaj.y"
                    {printx("parameter list -> parameter\n");(yyval.parListNode) = new parameterList();(yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1462 "limbaj.tab.c"
    break;

  case 41: /* parameter: TYPE ID  */
#line 145 "limbaj.y"
                   { printx("\nparamter -> type id"); (yyval.parameterNode) = new Symbol(0,(yyvsp[-1].typenode)->type,(yyvsp[0].node)->content,nullptr);}
#line 1468 "limbaj.tab.c"
    break;

  case 42: /* expr: expr '+' expr  */
#line 148 "limbaj.y"
                        { printx("\nexpr -> expr + expr\n");(yyval.exprnode) = new expressionNode(operTypes::plus,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"+" + (yyvsp[0].exprnode)->content); delete (yyvsp[-2].exprnode); delete (yyvsp[0].exprnode); }
#line 1474 "limbaj.tab.c"
    break;

  case 43: /* expr: expr '-' expr  */
#line 149 "limbaj.y"
                        { printx("\nexpr -> expr - expr\n");(yyval.exprnode) = new expressionNode(operTypes::minus,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"-" + (yyvsp[0].exprnode)->content); delete (yyvsp[-2].exprnode); delete (yyvsp[0].exprnode); }
#line 1480 "limbaj.tab.c"
    break;

  case 44: /* expr: ID  */
#line 150 "limbaj.y"
             {printf("expr -> ID\n");(yyval.exprnode) = new expressionNode(nullptr, (yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1486 "limbaj.tab.c"
    break;

  case 45: /* expr: NR  */
#line 151 "limbaj.y"
             {printf("expr -> NR\n");(yyval.exprnode) = new expressionNode(nullptr, (yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1492 "limbaj.tab.c"
    break;

  case 46: /* assignment: lval '=' rval ';'  */
#line 154 "limbaj.y"
                              { (yyval.node) = new generalNode((yyvsp[-3].node)->content +"=" + (yyvsp[-1].rvalNode)->content); delete (yyvsp[-3].node); delete (yyvsp[-1].rvalNode);}
#line 1498 "limbaj.tab.c"
    break;

  case 47: /* lval: ID  */
#line 157 "limbaj.y"
                {printx("lva -> id\n"); checkSymbol((yyvsp[0].node));  }
#line 1504 "limbaj.tab.c"
    break;

  case 48: /* rval: NR  */
#line 160 "limbaj.y"
                {printx("\nrval -> NR\n"); (yyval.rvalNode) = new intValueNode((yyvsp[0].node)->content);}
#line 1510 "limbaj.tab.c"
    break;

  case 49: /* rval: ID  */
#line 161 "limbaj.y"
                {printx("\nrval -> ID\n"); checkSymbol((yyvsp[0].node)); Symbol* res = getSymbol((yyvsp[0].node)); 
                 if(res) (yyval.rvalNode) = new rvalueNode((yyvsp[0].node)->content,res->type); else (yyval.rvalNode) = new rvalueNode((yyvsp[0].node)->content);}
#line 1517 "limbaj.tab.c"
    break;

  case 50: /* ISCONST: CONST  */
#line 164 "limbaj.y"
                {printx("isconst -> const\n");(yyval.node) = (yyvsp[0].node);}
#line 1523 "limbaj.tab.c"
    break;

  case 51: /* IF_S: IF '(' expr ')' '{'  */
#line 167 "limbaj.y"
                             { printx("\nIF_S -> IF ( expr ) {\n");(yyval.node) = new generalNode("IF_S"); delete (yyvsp[-4].node);string expr = "if("; expr+=(yyvsp[-2].exprnode)->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}
#line 1529 "limbaj.tab.c"
    break;

  case 52: /* IF_B: IF_S statement '}'  */
#line 170 "limbaj.y"
                           { printx("\nIF_B -> IF_S statement }\n");(yyval.node) = new generalNode("IF_B"); backtrackScope();}
#line 1535 "limbaj.tab.c"
    break;

  case 53: /* IF_ELSE_S: IF_S statement '}' ELSE '{'  */
#line 173 "limbaj.y"
                                         { printx("\nIF_ELSE_S -> IF_S statement } ELSE {\n");(yyval.node) = new generalNode("IF_ELSE_S"); delete (yyvsp[-4].node); delete (yyvsp[-1].node);string elsescope = "else(" + currentSymbolTable->name+")"; backtrackScope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}
#line 1541 "limbaj.tab.c"
    break;

  case 54: /* IF_ELSE_B: IF_ELSE_S statement '}'  */
#line 176 "limbaj.y"
                                   { printx("\nIF_ELSE_B -> IF_ESLE_S statement }\n");(yyval.node) = new generalNode("IF_ELSE_B"); backtrackScope();}
#line 1547 "limbaj.tab.c"
    break;

  case 55: /* class_s: CLASS ID '{'  */
#line 179 "limbaj.y"
                      {printx("\nclassb_S-> class id { \n");(yyval.classNode) = currentSymbolTable = currentSymbolTable->newClass((yyvsp[-1].node));}
#line 1553 "limbaj.tab.c"
    break;

  case 56: /* decls_funcs: functions  */
#line 181 "limbaj.y"
                       {printx("\ndecls_funcs -> funcs\n"); (yyval.node) = (yyvsp[0].node);}
#line 1559 "limbaj.tab.c"
    break;

  case 57: /* decls_funcs: declarations  */
#line 182 "limbaj.y"
                       {printx("\ndecls_funcs -> decls\n"); (yyval.node)=(yyvsp[0].node);}
#line 1565 "limbaj.tab.c"
    break;

  case 58: /* decls_funcs: decls_funcs decls_funcs  */
#line 183 "limbaj.y"
                                  {printx("\ndecls_funcs -> decls_funcs decls_funcs\n"); (yyval.node) = new generalNode((yyvsp[-1].node)->content + " " + (yyvsp[0].node)->content); delete (yyvsp[-1].node); delete (yyvsp[0].node); }
#line 1571 "limbaj.tab.c"
    break;

  case 59: /* class_b: class_s decls_funcs '}'  */
#line 185 "limbaj.y"
                                  {printx("\nclassb -> class_S decls_funcs } \n"); backtrackScope();}
#line 1577 "limbaj.tab.c"
    break;

  case 60: /* class_b: class_s '}'  */
#line 186 "limbaj.y"
                      {printx("\nclassb -> class_S } \n");backtrackScope();}
#line 1583 "limbaj.tab.c"
    break;


#line 1587 "limbaj.tab.c"

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

#line 188 "limbaj.y"




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
