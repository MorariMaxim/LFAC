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
  YYSYMBOL_18_ = 18,                       /* '+'  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '*'  */
  YYSYMBOL_21_ = 21,                       /* '/'  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '['  */
  YYSYMBOL_25_ = 25,                       /* ']'  */
  YYSYMBOL_26_ = 26,                       /* '}'  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_progr = 33,                     /* progr  */
  YYSYMBOL_statements = 34,                /* statements  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_declaration = 36,               /* declaration  */
  YYSYMBOL_ARRAY = 37,                     /* ARRAY  */
  YYSYMBOL_array_indexing = 38,            /* array_indexing  */
  YYSYMBOL_function = 39,                  /* function  */
  YYSYMBOL_function_s = 40,                /* function_s  */
  YYSYMBOL_function_call = 41,             /* function_call  */
  YYSYMBOL_rvalues = 42,                   /* rvalues  */
  YYSYMBOL_parameter_List = 43,            /* parameter_List  */
  YYSYMBOL_parameter = 44,                 /* parameter  */
  YYSYMBOL_expr = 45,                      /* expr  */
  YYSYMBOL_assignment = 46,                /* assignment  */
  YYSYMBOL_lval = 47,                      /* lval  */
  YYSYMBOL_rval = 48,                      /* rval  */
  YYSYMBOL_ISCONST = 49,                   /* ISCONST  */
  YYSYMBOL_IF_S = 50,                      /* IF_S  */
  YYSYMBOL_IF_B = 51,                      /* IF_B  */
  YYSYMBOL_IF_ELSE_S = 52,                 /* IF_ELSE_S  */
  YYSYMBOL_IF_ELSE_B = 53,                 /* IF_ELSE_B  */
  YYSYMBOL_class_s = 54,                   /* class_s  */
  YYSYMBOL_decls_funcs = 55,               /* decls_funcs  */
  YYSYMBOL_class_b = 56,                   /* class_b  */
  YYSYMBOL_member_access = 57              /* member_access  */
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

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
      27,    28,    20,    18,    30,    19,    31,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    26,     2,     2,     2,     2,
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
       0,    70,    70,    71,    73,    74,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    94,    96,    98,   100,
     102,   104,   107,   108,   110,   111,   117,   119,   121,   123,
     124,   129,   133,   138,   140,   144,   145,   148,   149,   152,
     155,   156,   157,   158,   161,   164,   167,   168,   171,   174,
     177,   180,   183,   186,   188,   189,   190,   191,   193,   194,
     196
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
  "FN", "RETURN", "CLASS", "TYPE", "'+'", "'-'", "'*'", "'/'", "';'",
  "'='", "'['", "']'", "'}'", "'('", "')'", "'{'", "','", "'.'", "$accept",
  "progr", "statements", "statement", "declaration", "ARRAY",
  "array_indexing", "function", "function_s", "function_call", "rvalues",
  "parameter_List", "parameter", "expr", "assignment", "lval", "rval",
  "ISCONST", "IF_S", "IF_B", "IF_ELSE_S", "IF_ELSE_B", "class_s",
  "decls_funcs", "class_b", "member_access", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      51,   -33,    -2,   -17,   -33,    35,    39,    41,     3,    51,
      38,   -33,    42,    46,   -33,    24,   -33,    54,   -33,    58,
      60,    51,   -33,    51,   -33,     1,   -33,   -33,   -33,    10,
       0,    73,    69,    56,    53,    55,   -33,    62,   -33,    79,
      10,   -33,    -6,    69,    69,    10,    80,    63,    64,    81,
     -33,   -33,   -33,    13,   -33,   -33,    61,   -33,    -4,   -33,
     -33,   -33,    34,     6,   -33,    69,    85,   -33,    67,    68,
      10,   -33,   -33,   -33,   -33,    71,    86,   -33,    57,   -33,
     -33,   -33,    10,    70,    89,    84,    17,   -33,    54,    75,
     -33,   -33,    72,    69,    74,   -33,   -33,   -33,   -33,   -33,
      87,    88,    90,   -33,   -33,    54,   -33,    76,    91,   -33,
     -33,    77,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    43,    42,     0,    48,     0,     0,     0,     0,     2,
       0,     6,    20,    13,    10,     0,    12,     7,    11,     0,
       0,     0,     8,     0,     9,     0,    14,    15,    21,     0,
       0,     0,     0,     0,     0,    19,     1,     0,     4,     0,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    55,    54,     0,    46,    47,     0,    34,     0,    35,
      60,    42,     0,     0,    53,     0,     0,     5,     0,     0,
       0,    27,    40,    41,    44,    17,    50,    52,     0,    58,
      24,    33,     0,     0,     0,     0,     0,    38,    18,     0,
      23,    25,     0,     0,     0,    56,    57,    36,    49,    39,
       0,     0,     0,    22,    26,    16,    51,    29,     0,    37,
      31,    30,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,    28,   -24,   -33,   -33,   -23,   -33,   -33,
     -33,   -33,     7,   -32,   -33,   -33,   -26,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      58,    86,    87,    17,    18,    19,    56,    20,    21,    22,
      23,    24,    25,    53,    26,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    51,    52,    36,    59,    28,    54,    55,    49,    70,
      32,    72,    73,     4,    69,     5,    54,    55,     7,    74,
      71,   -45,    29,    84,    81,    30,    82,    50,    57,    31,
       1,     2,     3,    88,    85,    78,     4,    37,     5,    79,
       6,     7,    33,    42,    92,   101,    34,   102,    35,    47,
      41,    48,    43,    44,    95,    96,    97,     1,     2,     3,
      38,   105,    83,     4,    49,     5,    39,     6,     7,     4,
      40,     5,    43,    44,     7,     1,    61,    46,    65,    66,
      60,    45,    64,    63,    67,    68,    80,    75,    28,    76,
      77,    89,    90,    91,    93,    94,    99,   100,   104,    98,
     103,   108,     0,   106,   107,   110,   112,    84,   111,   109
};

static const yytype_int8 yycheck[] =
{
      32,    25,    25,     0,    30,     7,     6,     7,     7,    15,
      27,    43,    44,    12,    40,    14,     6,     7,    17,    45,
      26,    23,    24,    17,    28,    27,    30,    26,    28,    31,
       6,     7,     8,    65,    28,    22,    12,     9,    14,    26,
      16,    17,     7,    15,    70,    28,     7,    30,     7,    21,
      26,    23,    18,    19,    78,    78,    82,     6,     7,     8,
      22,    93,    28,    12,     7,    14,    24,    16,    17,    12,
      24,    14,    18,    19,    17,     6,     7,    17,    23,    24,
       7,    23,    29,    27,    22,     6,    25,     7,     7,    26,
      26,     6,    25,    25,    23,     9,     7,    13,    26,    29,
      25,    13,    -1,    29,    17,    29,    29,    17,    17,   102
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    12,    14,    16,    17,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    45,    46,    47,
      49,    50,    51,    52,    53,    54,    56,    57,     7,    24,
      27,    31,    27,     7,     7,     7,     0,    35,    22,    24,
      24,    26,    35,    18,    19,    23,    17,    35,    35,     7,
      26,    36,    39,    55,     6,     7,    48,    28,    42,    48,
       7,     7,    45,    27,    29,    23,    24,    22,     6,    48,
      15,    26,    45,    45,    48,     7,    26,    26,    22,    26,
      25,    28,    30,    28,    17,    28,    43,    44,    45,     6,
      25,    25,    48,    23,     9,    36,    39,    48,    29,     7,
      13,    28,    30,    25,    26,    45,    29,    17,    13,    44,
      29,    17,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    36,    36,    36,    36,
      36,    36,    37,    37,    38,    38,    39,    39,    39,    39,
      39,    40,    40,    41,    41,    42,    42,    43,    43,    44,
      45,    45,    45,    45,    46,    47,    48,    48,    49,    50,
      51,    52,    53,    54,    55,    55,    55,    55,    56,    56,
      57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     4,     2,
       1,     2,     5,     4,     4,     4,     5,     3,     2,     6,
       7,     7,     8,     4,     3,     1,     3,     3,     1,     2,
       3,     3,     1,     1,     3,     1,     1,     1,     1,     5,
       3,     5,     3,     3,     1,     1,     3,     3,     3,     2,
       3
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
#line 70 "limbaj.y"
                   { printx("\nsyntactically correct program\n"); }
#line 1214 "limbaj.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 71 "limbaj.y"
                     { printx("\nempty prog\n");}
#line 1220 "limbaj.tab.c"
    break;

  case 4: /* statements: statement ';'  */
#line 73 "limbaj.y"
                          { (yyval.node) = (yyvsp[-1].node); printx("\nstatement -> statement\n");}
#line 1226 "limbaj.tab.c"
    break;

  case 5: /* statements: statements statement ';'  */
#line 74 "limbaj.y"
                                   { (yyval.node) = (yyvsp[-2].node); printx("\nstatement -> statements statement\n");}
#line 1232 "limbaj.tab.c"
    break;

  case 6: /* statement: declaration  */
#line 77 "limbaj.y"
                      { printx("\nstmt -> declaration\n");}
#line 1238 "limbaj.tab.c"
    break;

  case 7: /* statement: expr  */
#line 78 "limbaj.y"
                { printx("\nstmt -> expr\n");}
#line 1244 "limbaj.tab.c"
    break;

  case 8: /* statement: IF_B  */
#line 79 "limbaj.y"
               { printx("\nstmt -> IF_B\n");}
#line 1250 "limbaj.tab.c"
    break;

  case 9: /* statement: IF_ELSE_B  */
#line 80 "limbaj.y"
                    { printx("\nstatement -> IF_ELSE_B\n");}
#line 1256 "limbaj.tab.c"
    break;

  case 10: /* statement: function  */
#line 81 "limbaj.y"
                   { printx("\nstatement -> function\n"); (yyval.node) = (yyvsp[0].funcNode);}
#line 1262 "limbaj.tab.c"
    break;

  case 11: /* statement: assignment  */
#line 82 "limbaj.y"
                     {printx("\nstatement -> assignment\n");}
#line 1268 "limbaj.tab.c"
    break;

  case 12: /* statement: function_call  */
#line 83 "limbaj.y"
                         {printx("statement -> functionCall\n");}
#line 1274 "limbaj.tab.c"
    break;

  case 13: /* statement: array_indexing  */
#line 84 "limbaj.y"
                          {printx("statement -> array_indexing\n");(yyvsp[0].arrayIndexingNode)->checkIndexes();}
#line 1280 "limbaj.tab.c"
    break;

  case 14: /* statement: class_b  */
#line 85 "limbaj.y"
                  {printx("statement -> class_b\n");}
#line 1286 "limbaj.tab.c"
    break;

  case 15: /* statement: member_access  */
#line 86 "limbaj.y"
                          {printx("statement -> member_access\n");}
#line 1292 "limbaj.tab.c"
    break;

  case 16: /* declaration: ISCONST TYPE ID '=' expr  */
#line 94 "limbaj.y"
                                    { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->defineSymbol(1,(yyvsp[-3].typenode)->type,(yyvsp[-2].node)->content,(yyvsp[0].exprnode));  (yyval.node) = new generalNode((yyvsp[-4].node)->content + " " + (yyvsp[-3].typenode)->content+ " " + (yyvsp[-2].node)->content+ " " + (yyvsp[0].exprnode)->content); delete (yyvsp[-4].node); delete (yyvsp[-3].typenode);delete (yyvsp[-2].node); delete (yyvsp[0].exprnode);}
#line 1299 "limbaj.tab.c"
    break;

  case 17: /* declaration: ISCONST TYPE ID  */
#line 96 "limbaj.y"
                           { printx("\ndecl->const type id;\n");
                                            currentSymbolTable->defineSymbol(1,(yyvsp[-1].typenode)->type,(yyvsp[0].node)->content,nullptr);  (yyval.node) = new generalNode("const " + (yyvsp[-2].node)->content + " " + (yyvsp[-1].typenode)->content); delete (yyvsp[-2].node); delete (yyvsp[-1].typenode);delete (yyvsp[0].node);}
#line 1306 "limbaj.tab.c"
    break;

  case 18: /* declaration: TYPE ID '=' expr  */
#line 98 "limbaj.y"
                            { printx("\ndecl->type id init;\n");
                                            currentSymbolTable->defineSymbol(0,(yyvsp[-3].typenode)->type,(yyvsp[-2].node)->content,(yyvsp[0].exprnode));  (yyval.node) = new generalNode((yyvsp[-3].typenode)->content + " " + (yyvsp[-2].node)->content+ " = " + (yyvsp[0].exprnode)->content); delete (yyvsp[-3].typenode); delete (yyvsp[-2].node); delete (yyvsp[0].exprnode);}
#line 1313 "limbaj.tab.c"
    break;

  case 19: /* declaration: TYPE ID  */
#line 100 "limbaj.y"
                   { printx("\ndecl->type id;\n");
                                        currentSymbolTable->defineSymbol(0,(yyvsp[-1].typenode)->type,(yyvsp[0].node)->content,nullptr);  (yyval.node) = new generalNode((yyvsp[-1].typenode)->content + " " + (yyvsp[0].node)->content); delete (yyvsp[-1].typenode); delete (yyvsp[0].node);}
#line 1320 "limbaj.tab.c"
    break;

  case 20: /* declaration: ARRAY  */
#line 102 "limbaj.y"
                 { printx("\ndecl -> array\n");printf("array name : %s\n",(yyvsp[0].node)->content.c_str());arraySymbol * as = arraySymbol::buildFromStack(0);currentSymbolTable->defineSymbol((yyvsp[0].node)->content,as); (yyval.node) = (yyvsp[0].node);}
#line 1326 "limbaj.tab.c"
    break;

  case 21: /* declaration: ID ID  */
#line 104 "limbaj.y"
                 {printx("\ndecl -> ID ID ;\n");currentSymbolTable->defineUserSymbol((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1332 "limbaj.tab.c"
    break;

  case 22: /* ARRAY: TYPE ID '[' NR ']'  */
#line 107 "limbaj.y"
                          { printx("\narray -> type id [ nr ]\n"); (yyval.node) = (yyvsp[-3].node); arrayType=(yyvsp[-4].typenode)->type; arrayStack.push_back(atoi((yyvsp[-1].node)->content.c_str()));}
#line 1338 "limbaj.tab.c"
    break;

  case 23: /* ARRAY: ARRAY '[' NR ']'  */
#line 108 "limbaj.y"
                           { printx("\narray -> array [ nr ]\n"); (yyval.node) = (yyvsp[-3].node);arrayStack.push_back(atoi((yyvsp[-1].node)->content.c_str()));}
#line 1344 "limbaj.tab.c"
    break;

  case 24: /* array_indexing: ID '[' rval ']'  */
#line 110 "limbaj.y"
                                {printx("array_indexing -> ID '[' rval ']'");(yyval.arrayIndexingNode)  = new arrayIndexing((yyvsp[-3].node)); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode)); }
#line 1350 "limbaj.tab.c"
    break;

  case 25: /* array_indexing: array_indexing '[' rval ']'  */
#line 111 "limbaj.y"
                                      {printx("array_indexing -> array_indexing '[' NR ']'"); (yyval.arrayIndexingNode) = (yyvsp[-3].arrayIndexingNode); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode));}
#line 1356 "limbaj.tab.c"
    break;

  case 26: /* function: function_s statement RETURN rval '}'  */
#line 117 "limbaj.y"
                                               { printx("\nfunction -> function_s statement return rval}\n"); 
                                                backtrackScope();(yyval.funcNode) = (yyvsp[-4].funcNode); checkRetType((yyvsp[-1].rvalNode));}
#line 1363 "limbaj.tab.c"
    break;

  case 27: /* function: function_s statement '}'  */
#line 119 "limbaj.y"
                                   { printx("\nfunction -> function_s statement }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-2].funcNode); checkVoidReturn();}
#line 1370 "limbaj.tab.c"
    break;

  case 28: /* function: function_s '}'  */
#line 121 "limbaj.y"
                         { printx("\nfunction -> function_s statement }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-1].funcNode); checkVoidReturn();}
#line 1377 "limbaj.tab.c"
    break;

  case 29: /* function: FN ID '(' ')' RARROW TYPE  */
#line 123 "limbaj.y"
                                     { printx("\nfunctions_s -> FN ID ( ) RARROW TYPE ;\n");(yyval.funcNode) = new functionNode((yyvsp[-4].node)->content,(yyvsp[0].typenode)->type,nullptr);}
#line 1383 "limbaj.tab.c"
    break;

  case 30: /* function: FN ID '(' parameter_List ')' RARROW TYPE  */
#line 125 "limbaj.y"
         { printx("\nfunctions_s -> FN ID ( list ) RARROW TYPE ;\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[0].typenode)->type,(yyvsp[-3].parListNode)->parameters);}
#line 1389 "limbaj.tab.c"
    break;

  case 31: /* function_s: FN ID '(' ')' RARROW TYPE '{'  */
#line 129 "limbaj.y"
                                        { printx("\nfunctions_s -> fn id ( ) -> type {\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[-1].typenode)->type,nullptr);
                                        currentSymbolTable = currentSymbolTable->addFunction((yyval.funcNode)); returnType = (yyvsp[-1].typenode)->type;
                                         }
#line 1397 "limbaj.tab.c"
    break;

  case 32: /* function_s: FN ID '(' parameter_List ')' RARROW TYPE '{'  */
#line 133 "limbaj.y"
                                                       { printx("\nfunctions_s -> fn id ( list ) -> type {\n");  (yyval.funcNode) = new functionNode((yyvsp[-6].node)->content,(yyvsp[-1].typenode)->type,(yyvsp[-4].parListNode)->parameters);
                                        currentSymbolTable=  currentSymbolTable->addFunction((yyval.funcNode));returnType = (yyvsp[-1].typenode)->type;
                                        }
#line 1405 "limbaj.tab.c"
    break;

  case 33: /* function_call: ID '(' rvalues ')'  */
#line 138 "limbaj.y"
                                  {printx("functioncall -> id ( rvalues )\n");(yyval.funcCall) = new functionCall((yyvsp[-3].node)->content); (yyval.funcCall)->setArgs((yyvsp[-1].rvaluesNode)); 
                        bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1412 "limbaj.tab.c"
    break;

  case 34: /* function_call: ID '(' ')'  */
#line 140 "limbaj.y"
                        {printx("functioncall -> id ()\n");(yyval.funcCall) = new functionCall((yyvsp[-2].node)->content);  
                        bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1419 "limbaj.tab.c"
    break;

  case 35: /* rvalues: rval  */
#line 144 "limbaj.y"
              {printx("rvalues -> rval\n");(yyval.rvaluesNode) = new rValueNodes(); (yyval.rvaluesNode)->addRvalue((yyvsp[0].rvalNode)); }
#line 1425 "limbaj.tab.c"
    break;

  case 36: /* rvalues: rvalues ',' rval  */
#line 145 "limbaj.y"
                           {printx("rvalues -> rvalues , rval\n");(yyvsp[-2].rvaluesNode)->addRvalue((yyvsp[0].rvalNode));(yyval.rvaluesNode)=(yyvsp[-2].rvaluesNode);}
#line 1431 "limbaj.tab.c"
    break;

  case 37: /* parameter_List: parameter_List ',' parameter  */
#line 148 "limbaj.y"
                                              {printx("parameter list -> parameter llist , parameter\n"); (yyval.parListNode) = (yyvsp[-2].parListNode); (yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1437 "limbaj.tab.c"
    break;

  case 38: /* parameter_List: parameter  */
#line 149 "limbaj.y"
                    {printx("parameter list -> parameter\n");(yyval.parListNode) = new parameterList();(yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1443 "limbaj.tab.c"
    break;

  case 39: /* parameter: TYPE ID  */
#line 152 "limbaj.y"
                   { printx("\nparamter -> type id"); (yyval.parameterNode) = new Symbol(0,(yyvsp[-1].typenode)->type,(yyvsp[0].node)->content,nullptr);}
#line 1449 "limbaj.tab.c"
    break;

  case 40: /* expr: expr '+' expr  */
#line 155 "limbaj.y"
                        { printx("\nexpr -> expr + expr\n");(yyval.exprnode) = new expressionNode(operTypes::plus,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"+" + (yyvsp[0].exprnode)->content); delete (yyvsp[-2].exprnode); delete (yyvsp[0].exprnode); }
#line 1455 "limbaj.tab.c"
    break;

  case 41: /* expr: expr '-' expr  */
#line 156 "limbaj.y"
                        { printx("\nexpr -> expr - expr\n");(yyval.exprnode) = new expressionNode(operTypes::minus,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"-" + (yyvsp[0].exprnode)->content); delete (yyvsp[-2].exprnode); delete (yyvsp[0].exprnode); }
#line 1461 "limbaj.tab.c"
    break;

  case 42: /* expr: ID  */
#line 157 "limbaj.y"
             {printf("expr -> ID\n");(yyval.exprnode) = new expressionNode(nullptr, (yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1467 "limbaj.tab.c"
    break;

  case 43: /* expr: NR  */
#line 158 "limbaj.y"
             {printf("expr -> NR\n");(yyval.exprnode) = new expressionNode(nullptr, (yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1473 "limbaj.tab.c"
    break;

  case 44: /* assignment: lval '=' rval  */
#line 161 "limbaj.y"
                           { (yyval.node) = new generalNode((yyvsp[-2].node)->content +"=" + (yyvsp[0].rvalNode)->content); delete (yyvsp[-2].node); delete (yyvsp[0].rvalNode);}
#line 1479 "limbaj.tab.c"
    break;

  case 45: /* lval: ID  */
#line 164 "limbaj.y"
                {printx("lva -> id\n"); checkSymbol((yyvsp[0].node));  }
#line 1485 "limbaj.tab.c"
    break;

  case 46: /* rval: NR  */
#line 167 "limbaj.y"
                {printx("\nrval -> NR\n"); (yyval.rvalNode) = new intValueNode((yyvsp[0].node)->content);}
#line 1491 "limbaj.tab.c"
    break;

  case 47: /* rval: ID  */
#line 168 "limbaj.y"
                {printx("\nrval -> ID\n"); checkSymbol((yyvsp[0].node)); Symbol* res = getSymbol((yyvsp[0].node)); 
                 if(res) (yyval.rvalNode) = new rvalueNode((yyvsp[0].node)->content,res->type); else (yyval.rvalNode) = new rvalueNode((yyvsp[0].node)->content);}
#line 1498 "limbaj.tab.c"
    break;

  case 48: /* ISCONST: CONST  */
#line 171 "limbaj.y"
                {printx("isconst -> const\n");(yyval.node) = (yyvsp[0].node);}
#line 1504 "limbaj.tab.c"
    break;

  case 49: /* IF_S: IF '(' expr ')' '{'  */
#line 174 "limbaj.y"
                             { printx("\nIF_S -> IF ( expr ) {\n");(yyval.node) = new generalNode("IF_S"); delete (yyvsp[-4].node);string expr = "if("; expr+=(yyvsp[-2].exprnode)->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}
#line 1510 "limbaj.tab.c"
    break;

  case 50: /* IF_B: IF_S statement '}'  */
#line 177 "limbaj.y"
                           { printx("\nIF_B -> IF_S statement }\n");(yyval.node) = new generalNode("IF_B"); backtrackScope();}
#line 1516 "limbaj.tab.c"
    break;

  case 51: /* IF_ELSE_S: IF_S statement '}' ELSE '{'  */
#line 180 "limbaj.y"
                                         { printx("\nIF_ELSE_S -> IF_S statement } ELSE {\n");(yyval.node) = new generalNode("IF_ELSE_S"); delete (yyvsp[-4].node); delete (yyvsp[-1].node);string elsescope = "else(" + currentSymbolTable->name+")"; backtrackScope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}
#line 1522 "limbaj.tab.c"
    break;

  case 52: /* IF_ELSE_B: IF_ELSE_S statement '}'  */
#line 183 "limbaj.y"
                                   { printx("\nIF_ELSE_B -> IF_ESLE_S statement }\n");(yyval.node) = new generalNode("IF_ELSE_B"); backtrackScope();}
#line 1528 "limbaj.tab.c"
    break;

  case 53: /* class_s: CLASS ID '{'  */
#line 186 "limbaj.y"
                      {printx("\nclassb_S-> class id { \n");(yyval.classNode) = currentSymbolTable = currentSymbolTable->newClass((yyvsp[-1].node));}
#line 1534 "limbaj.tab.c"
    break;

  case 54: /* decls_funcs: function  */
#line 188 "limbaj.y"
                      {printx("\ndecls_funcs -> funcs\n");}
#line 1540 "limbaj.tab.c"
    break;

  case 55: /* decls_funcs: declaration  */
#line 189 "limbaj.y"
                       {printx("\ndecls_funcs -> decls\n"); }
#line 1546 "limbaj.tab.c"
    break;

  case 56: /* decls_funcs: decls_funcs ';' declaration  */
#line 190 "limbaj.y"
                                       {printx("\ndecls_funcs -> decls_funcs declaration\n");  }
#line 1552 "limbaj.tab.c"
    break;

  case 57: /* decls_funcs: decls_funcs ';' function  */
#line 191 "limbaj.y"
                                    {printx("\ndecls_funcs -> decls_funcs function\n");  }
#line 1558 "limbaj.tab.c"
    break;

  case 58: /* class_b: class_s decls_funcs '}'  */
#line 193 "limbaj.y"
                                  {printx("\nclassb -> class_S decls_funcs } \n"); backtrackScope();}
#line 1564 "limbaj.tab.c"
    break;

  case 59: /* class_b: class_s '}'  */
#line 194 "limbaj.y"
                      {printx("\nclassb -> class_S } \n");backtrackScope();}
#line 1570 "limbaj.tab.c"
    break;

  case 60: /* member_access: ID '.' ID  */
#line 196 "limbaj.y"
                         {printx("\nmember_access -> ID . ID \n"); currentSymbolTable->check_member_access((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = new generalNode("member accsss");}
#line 1576 "limbaj.tab.c"
    break;


#line 1580 "limbaj.tab.c"

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

#line 198 "limbaj.y"

 
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
