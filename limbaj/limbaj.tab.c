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
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* ':'  */
  YYSYMBOL_27_ = 27,                       /* ','  */
  YYSYMBOL_28_ = 28,                       /* '['  */
  YYSYMBOL_29_ = 29,                       /* ']'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_progr = 34,                     /* progr  */
  YYSYMBOL_statements = 35,                /* statements  */
  YYSYMBOL_statement = 36,                 /* statement  */
  YYSYMBOL_declaration = 37,               /* declaration  */
  YYSYMBOL_class_declaration = 38,         /* class_declaration  */
  YYSYMBOL_field_val = 39,                 /* field_val  */
  YYSYMBOL_ARRAY = 40,                     /* ARRAY  */
  YYSYMBOL_array_indexing = 41,            /* array_indexing  */
  YYSYMBOL_function = 42,                  /* function  */
  YYSYMBOL_function_s = 43,                /* function_s  */
  YYSYMBOL_function_call = 44,             /* function_call  */
  YYSYMBOL_id_parameters = 45,             /* id_parameters  */
  YYSYMBOL_rvalues = 46,                   /* rvalues  */
  YYSYMBOL_parameter_List = 47,            /* parameter_List  */
  YYSYMBOL_parameter = 48,                 /* parameter  */
  YYSYMBOL_expr = 49,                      /* expr  */
  YYSYMBOL_assignment = 50,                /* assignment  */
  YYSYMBOL_lval = 51,                      /* lval  */
  YYSYMBOL_rval = 52,                      /* rval  */
  YYSYMBOL_ISCONST = 53,                   /* ISCONST  */
  YYSYMBOL_IF_S = 54,                      /* IF_S  */
  YYSYMBOL_IF_B = 55,                      /* IF_B  */
  YYSYMBOL_IF_ELSE_S = 56,                 /* IF_ELSE_S  */
  YYSYMBOL_IF_ELSE_B = 57,                 /* IF_ELSE_B  */
  YYSYMBOL_class_s = 58,                   /* class_s  */
  YYSYMBOL_decls_funcs = 59,               /* decls_funcs  */
  YYSYMBOL_class_b = 60,                   /* class_b  */
  YYSYMBOL_member_access = 61              /* member_access  */
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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

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
      24,    25,    20,    18,    27,    19,    32,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    22,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    30,     2,     2,     2,     2,
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
     102,   103,   106,   108,   110,   111,   116,   117,   119,   120,
     123,   125,   127,   129,   130,   135,   139,   143,   145,   148,
     149,   152,   153,   156,   157,   160,   163,   164,   165,   166,
     169,   172,   175,   178,   181,   184,   187,   190,   193,   195,
     196,   197,   198,   200,   201,   203
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
  "'='", "'('", "')'", "':'", "','", "'['", "']'", "'}'", "'{'", "'.'",
  "$accept", "progr", "statements", "statement", "declaration",
  "class_declaration", "field_val", "ARRAY", "array_indexing", "function",
  "function_s", "function_call", "id_parameters", "rvalues",
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

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,   -32,     0,   -13,   -32,    15,    34,    38,    53,   111,
     -32,    32,   -32,    27,    -3,   -32,    72,    60,   -32,    90,
      71,    37,    80,   111,   -32,   111,   -32,    22,   -32,    77,
      79,     2,     8,    68,     8,    86,    73,    28,   -32,   -32,
     -32,   115,   -32,     8,   -32,    51,   -32,     8,     8,   -32,
     -32,     8,   117,    84,    99,   119,   -32,   108,   -32,    57,
     -32,   124,   -32,   -32,    45,    12,   -32,   103,   109,   -32,
      25,    -7,   -32,     8,   128,   106,   107,     8,   -32,   -32,
     -32,   -32,   114,   129,   -32,   -32,   -32,   118,   -32,   113,
      58,   -32,     8,   -32,   110,   135,   130,    95,   -32,    12,
     116,   -32,   -32,   120,     8,   121,   -32,     8,   -32,   137,
     -32,   -32,   -32,   131,   133,   132,   -32,   -32,    12,   -32,
     -32,   125,   122,   138,   -32,     8,   -32,   123,   -32,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    49,    48,     0,    53,     0,     0,     0,     0,     2,
       4,     0,    21,    20,     0,    10,     0,     0,    38,     0,
       0,     0,     0,     0,     8,     0,     9,     0,    14,     0,
      22,     0,     0,     0,     0,     0,     0,    19,     1,     5,
       6,     0,    13,     0,    32,     0,    12,     0,     0,     7,
      11,     0,     0,     0,     0,     0,    64,     0,    59,     0,
      15,     0,    48,    40,     0,    52,    41,     0,    65,    37,
       0,     0,    58,     0,     0,     0,     0,     0,    31,    46,
      47,    50,    17,    55,    57,    60,    63,     0,    62,     0,
       0,    39,     0,    28,     0,     0,     0,     0,    44,    18,
       0,    27,    29,     0,     0,     0,    61,     0,    23,     0,
      42,    54,    45,     0,     0,     0,    26,    30,    16,    56,
      24,     0,    33,     0,    43,     0,    35,    34,    25,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,    10,    -5,   -22,   -32,   -32,   -32,   -32,   -21,
     -32,   -32,   126,   -32,   -32,    41,   -31,   -32,   -32,   -30,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    90,    13,    14,    15,
      16,    17,    18,    64,    97,    98,    19,    20,    21,    66,
      22,    23,    24,    25,    26,    27,    59,    28,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    65,    67,    70,    39,    57,    58,    30,     1,    62,
      95,    34,    65,    76,     1,    62,    79,    80,    96,    42,
      65,    81,    35,   -51,    31,    43,    45,    63,    32,    55,
      47,    48,    33,    53,     4,    54,     5,    87,    88,     7,
      39,    36,    99,    47,    48,    37,    65,   103,    39,    39,
      94,    73,    56,    38,    40,    41,    74,     1,     2,     3,
      51,    65,   110,     4,    55,     5,    77,     6,     7,     4,
      91,     5,    92,   118,     7,    68,    65,   120,     1,     2,
       3,    78,    46,   108,     4,   109,     5,    86,     6,     7,
       1,     2,     3,    50,    65,   128,     4,    52,     5,    60,
       6,     7,    44,    61,    72,     1,     2,     3,    47,    48,
      71,     4,    49,     5,    83,     6,     7,     1,     2,     3,
     114,    75,   115,     4,    82,     5,    30,     6,     7,    84,
      85,    89,    93,    31,   100,   101,   102,   104,   105,   107,
     106,   111,   112,   113,   121,   116,   123,     0,   122,    95,
     117,   125,   119,   126,   129,   127,   124,     0,     0,    69
};

static const yytype_int8 yycheck[] =
{
      31,    32,    32,    34,     9,    27,    27,     7,     6,     7,
      17,    24,    43,    43,     6,     7,    47,    48,    25,    22,
      51,    51,     7,    23,    24,    28,    16,    25,    28,     7,
      18,    19,    32,    23,    12,    25,    14,    59,    59,    17,
      45,     7,    73,    18,    19,     7,    77,    77,    53,    54,
      25,    23,    30,     0,    22,    28,    28,     6,     7,     8,
      23,    92,    92,    12,     7,    14,    15,    16,    17,    12,
      25,    14,    27,   104,    17,     7,   107,   107,     6,     7,
       8,    30,    22,    25,    12,    27,    14,    30,    16,    17,
       6,     7,     8,    22,   125,   125,    12,    17,    14,    22,
      16,    17,    30,    24,    31,     6,     7,     8,    18,    19,
      24,    12,    22,    14,    30,    16,    17,     6,     7,     8,
      25,     6,    27,    12,     7,    14,     7,    16,    17,    30,
      22,     7,    29,    24,     6,    29,    29,    23,     9,    26,
      22,    31,     7,    13,     7,    29,    13,    -1,    17,    17,
      30,    26,    31,    31,    31,    17,   115,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    12,    14,    16,    17,    34,    35,
      36,    37,    38,    40,    41,    42,    43,    44,    45,    49,
      50,    51,    53,    54,    55,    56,    57,    58,    60,    61,
       7,    24,    28,    32,    24,     7,     7,     7,     0,    36,
      22,    28,    22,    28,    30,    35,    22,    18,    19,    22,
      22,    23,    17,    35,    35,     7,    30,    37,    42,    59,
      22,    24,     7,    25,    46,    49,    52,    52,     7,    45,
      49,    24,    31,    23,    28,     6,    52,    15,    30,    49,
      49,    52,     7,    30,    30,    22,    30,    37,    42,     7,
      39,    25,    27,    29,    25,    17,    25,    47,    48,    49,
       6,    29,    29,    52,    23,     9,    22,    26,    25,    27,
      52,    31,     7,    13,    25,    27,    29,    30,    49,    31,
      52,     7,    17,    13,    48,    26,    31,    17,    52,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    37,    37,    37,    37,
      37,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    42,    42,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    49,    49,    49,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      59,    59,    59,    60,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     1,     2,     5,     3,     4,     2,
       1,     1,     2,     5,     3,     5,     5,     4,     4,     4,
       5,     3,     2,     6,     7,     7,     8,     3,     1,     4,
       3,     1,     3,     3,     1,     2,     3,     3,     1,     1,
       3,     1,     1,     1,     5,     3,     5,     3,     3,     1,
       2,     3,     2,     3,     2,     3
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
#line 1231 "limbaj.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 71 "limbaj.y"
                     { printx("\nempty prog\n");}
#line 1237 "limbaj.tab.c"
    break;

  case 4: /* statements: statement  */
#line 73 "limbaj.y"
                       { (yyval.node) = (yyvsp[0].node); printx("\nstatements -> statement\n");}
#line 1243 "limbaj.tab.c"
    break;

  case 5: /* statements: statements statement  */
#line 74 "limbaj.y"
                                { (yyval.node) = (yyvsp[-1].node); printx("\nstatements -> statements statement\n");}
#line 1249 "limbaj.tab.c"
    break;

  case 6: /* statement: declaration ';'  */
#line 77 "limbaj.y"
                          { printx("\nstmt -> declaration\n");}
#line 1255 "limbaj.tab.c"
    break;

  case 7: /* statement: expr ';'  */
#line 78 "limbaj.y"
                    { printx("\nstmt -> expr\n");}
#line 1261 "limbaj.tab.c"
    break;

  case 8: /* statement: IF_B  */
#line 79 "limbaj.y"
               { printx("\nstmt -> IF_B\n");}
#line 1267 "limbaj.tab.c"
    break;

  case 9: /* statement: IF_ELSE_B  */
#line 80 "limbaj.y"
                    { printx("\nstatement -> IF_ELSE_B\n");}
#line 1273 "limbaj.tab.c"
    break;

  case 10: /* statement: function  */
#line 81 "limbaj.y"
                   { printx("\nstatement -> function\n"); (yyval.node) = (yyvsp[0].funcNode);}
#line 1279 "limbaj.tab.c"
    break;

  case 11: /* statement: assignment ';'  */
#line 82 "limbaj.y"
                         {printx("\nstatement -> assignment\n");}
#line 1285 "limbaj.tab.c"
    break;

  case 12: /* statement: function_call ';'  */
#line 83 "limbaj.y"
                             {printx("statement -> functionCall\n");}
#line 1291 "limbaj.tab.c"
    break;

  case 13: /* statement: array_indexing ';'  */
#line 84 "limbaj.y"
                             {printx("statement -> array_indexing\n");(yyvsp[-1].arrayIndexingNode)->checkIndexes();}
#line 1297 "limbaj.tab.c"
    break;

  case 14: /* statement: class_b  */
#line 85 "limbaj.y"
                  {printx("statement -> class_b\n");}
#line 1303 "limbaj.tab.c"
    break;

  case 15: /* statement: member_access ';'  */
#line 86 "limbaj.y"
                             {printx("statement -> member_access\n");}
#line 1309 "limbaj.tab.c"
    break;

  case 16: /* declaration: ISCONST TYPE ID '=' expr  */
#line 94 "limbaj.y"
                                    { printx("\ndecl->const type id init;\n");
                                            currentSymbolTable->defineSymbol(1,(yyvsp[-3].TypeNode)->type,(yyvsp[-2].node)->content,(yyvsp[0].exprnode));  (yyval.node) = new generalNode((yyvsp[-4].node)->content + " " + (yyvsp[-3].TypeNode)->content+ " " + (yyvsp[-2].node)->content+ " " + (yyvsp[0].exprnode)->content); delete (yyvsp[-4].node); delete (yyvsp[-3].TypeNode);delete (yyvsp[-2].node); delete (yyvsp[0].exprnode);}
#line 1316 "limbaj.tab.c"
    break;

  case 17: /* declaration: ISCONST TYPE ID  */
#line 96 "limbaj.y"
                           { printx("\ndecl->const type id;\n");
                                            currentSymbolTable->defineSymbol(1,(yyvsp[-1].TypeNode)->type,(yyvsp[0].node)->content,nullptr);  (yyval.node) = new generalNode("const " + (yyvsp[-2].node)->content + " " + (yyvsp[-1].TypeNode)->content); delete (yyvsp[-2].node); delete (yyvsp[-1].TypeNode);delete (yyvsp[0].node);}
#line 1323 "limbaj.tab.c"
    break;

  case 18: /* declaration: TYPE ID '=' expr  */
#line 98 "limbaj.y"
                            { printx("\ndecl->type id init;\n");
                                            currentSymbolTable->defineSymbol(0,(yyvsp[-3].TypeNode)->type,(yyvsp[-2].node)->content,(yyvsp[0].exprnode));  (yyval.node) = new generalNode((yyvsp[-3].TypeNode)->content + " " + (yyvsp[-2].node)->content+ " = " + (yyvsp[0].exprnode)->content); delete (yyvsp[-3].TypeNode); delete (yyvsp[-2].node); delete (yyvsp[0].exprnode);}
#line 1330 "limbaj.tab.c"
    break;

  case 19: /* declaration: TYPE ID  */
#line 100 "limbaj.y"
                   { printx("\ndecl->type id;\n");
                                        currentSymbolTable->defineSymbol(0,(yyvsp[-1].TypeNode)->type,(yyvsp[0].node)->content,nullptr);  (yyval.node) = new generalNode((yyvsp[-1].TypeNode)->content + " " + (yyvsp[0].node)->content); delete (yyvsp[-1].TypeNode); delete (yyvsp[0].node);}
#line 1337 "limbaj.tab.c"
    break;

  case 20: /* declaration: ARRAY  */
#line 102 "limbaj.y"
                 { printx("\ndecl -> array\n");printf("array name : %s\n",(yyvsp[0].node)->content.c_str());ArrayType * at = new ArrayType("",0);currentSymbolTable->define_array_symbol((yyvsp[0].node)->content,at); (yyval.node) = (yyvsp[0].node);}
#line 1343 "limbaj.tab.c"
    break;

  case 21: /* declaration: class_declaration  */
#line 103 "limbaj.y"
                            {printx("\n declaration -> class_declaration \n");}
#line 1349 "limbaj.tab.c"
    break;

  case 22: /* class_declaration: ID ID  */
#line 106 "limbaj.y"
                {printx("\n dclass_Declaration -> uninitialized \n");currentSymbolTable->define_user_symbol((yyvsp[-1].node),(yyvsp[0].node));}
#line 1355 "limbaj.tab.c"
    break;

  case 23: /* class_declaration: ID ID '(' field_val ')'  */
#line 108 "limbaj.y"
                                  {printx("\n dclass_Declaration -> initialized\n");currentSymbolTable->define_user_symbol((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-1].container));}
#line 1361 "limbaj.tab.c"
    break;

  case 24: /* field_val: ID ':' rval  */
#line 110 "limbaj.y"
                       {printx("\nfield_Val -> ID : rval\n"); (yyval.container) = new myVectorClass(); (yyval.container)->add_pointer((yyvsp[-2].node));(yyval.container)->add_pointer((yyvsp[0].rvalNode));}
#line 1367 "limbaj.tab.c"
    break;

  case 25: /* field_val: field_val ',' ID ':' rval  */
#line 111 "limbaj.y"
                                    {printx("\nfield_Val -> field_val , ID : rval\n"); (yyval.container) = (yyvsp[-4].container); (yyval.container)->add_pointer((yyvsp[-2].node));(yyval.container)->add_pointer((yyvsp[0].rvalNode));}
#line 1373 "limbaj.tab.c"
    break;

  case 26: /* ARRAY: TYPE ID '[' NR ']'  */
#line 116 "limbaj.y"
                          { printx("\narray -> type id [ nr ]\n"); (yyval.node) = (yyvsp[-3].node); arrayType=(yyvsp[-4].TypeNode)->type; arrayStack.push_back(atoi((yyvsp[-1].node)->content.c_str()));}
#line 1379 "limbaj.tab.c"
    break;

  case 27: /* ARRAY: ARRAY '[' NR ']'  */
#line 117 "limbaj.y"
                           { printx("\narray -> array [ nr ]\n"); (yyval.node) = (yyvsp[-3].node);arrayStack.push_back(atoi((yyvsp[-1].node)->content.c_str()));}
#line 1385 "limbaj.tab.c"
    break;

  case 28: /* array_indexing: ID '[' rval ']'  */
#line 119 "limbaj.y"
                                {printx("array_indexing -> ID '[' rval ']'");(yyval.arrayIndexingNode)  = new arrayIndexing((yyvsp[-3].node)); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode)); }
#line 1391 "limbaj.tab.c"
    break;

  case 29: /* array_indexing: array_indexing '[' rval ']'  */
#line 120 "limbaj.y"
                                      {printx("array_indexing -> array_indexing '[' NR ']'"); (yyval.arrayIndexingNode) = (yyvsp[-3].arrayIndexingNode); (yyval.arrayIndexingNode)->addRvalue((yyvsp[-1].rvalNode));}
#line 1397 "limbaj.tab.c"
    break;

  case 30: /* function: function_s statements RETURN rval '}'  */
#line 123 "limbaj.y"
                                                { printx("\nfunction -> function_s statements return rval}\n"); 
                                                backtrackScope();(yyval.funcNode) = (yyvsp[-4].funcNode); checkRetType((yyvsp[-1].rvalNode));}
#line 1404 "limbaj.tab.c"
    break;

  case 31: /* function: function_s statements '}'  */
#line 125 "limbaj.y"
                                    { printx("\nfunction -> function_s statements }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-2].funcNode); checkVoidReturn();}
#line 1411 "limbaj.tab.c"
    break;

  case 32: /* function: function_s '}'  */
#line 127 "limbaj.y"
                         { printx("\nfunction -> function_s }\n");  backtrackScope();
                                        (yyval.funcNode) = (yyvsp[-1].funcNode); checkVoidReturn();}
#line 1418 "limbaj.tab.c"
    break;

  case 33: /* function: FN ID '(' ')' RARROW TYPE  */
#line 129 "limbaj.y"
                                     { printx("\nfunctions_s -> FN ID ( ) RARROW TYPE ;\n");(yyval.funcNode) = new functionNode((yyvsp[-4].node)->content,(yyvsp[0].TypeNode)->type,nullptr);}
#line 1424 "limbaj.tab.c"
    break;

  case 34: /* function: FN ID '(' parameter_List ')' RARROW TYPE  */
#line 131 "limbaj.y"
         { printx("\nfunctions_s -> FN ID ( list ) RARROW TYPE ;\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[0].TypeNode)->type,(yyvsp[-3].parListNode)->parameters);}
#line 1430 "limbaj.tab.c"
    break;

  case 35: /* function_s: FN ID '(' ')' RARROW TYPE '{'  */
#line 135 "limbaj.y"
                                        { printx("\nfunctions_s -> fn id ( ) -> type {\n");(yyval.funcNode) = new functionNode((yyvsp[-5].node)->content,(yyvsp[-1].TypeNode)->type,nullptr);
                                        currentSymbolTable = currentSymbolTable->addFunction((yyval.funcNode)); returnType = (yyvsp[-1].TypeNode)->type;
                                         }
#line 1438 "limbaj.tab.c"
    break;

  case 36: /* function_s: FN ID '(' parameter_List ')' RARROW TYPE '{'  */
#line 139 "limbaj.y"
                                                       { printx("\nfunctions_s -> fn id ( list ) -> type {\n");  (yyval.funcNode) = new functionNode((yyvsp[-6].node)->content,(yyvsp[-1].TypeNode)->type,(yyvsp[-4].parListNode)->parameters);
                                        currentSymbolTable=  currentSymbolTable->addFunction((yyval.funcNode));returnType = (yyvsp[-1].TypeNode)->type;
                                        }
#line 1446 "limbaj.tab.c"
    break;

  case 37: /* function_call: ID '.' id_parameters  */
#line 143 "limbaj.y"
                                     {printx("functioncall -> ID . id_parameters\n"); (yyval.funcCall) = new functionCall((yyvsp[-2].node),(yyvsp[0].container));
                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1453 "limbaj.tab.c"
    break;

  case 38: /* function_call: id_parameters  */
#line 145 "limbaj.y"
                               {printx("functioncall -> id_parameters\n"); (yyval.funcCall) = new functionCall(nullptr,(yyvsp[0].container)); 

                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call\n");}
#line 1461 "limbaj.tab.c"
    break;

  case 39: /* id_parameters: ID '(' rvalues ')'  */
#line 148 "limbaj.y"
                                  {printx("id_parameters -> id ( rvalues )\n");(yyval.container) = new myVectorClass(); (yyval.container)->add_pointer((yyvsp[-3].node));(yyval.container)->add_pointer((yyvsp[-1].rvaluesNode)); }
#line 1467 "limbaj.tab.c"
    break;

  case 40: /* id_parameters: ID '(' ')'  */
#line 149 "limbaj.y"
                        {printx("id_parameters -> id ()\n");(yyval.container) = new myVectorClass(); (yyval.container)->add_pointer((yyvsp[-2].node));}
#line 1473 "limbaj.tab.c"
    break;

  case 41: /* rvalues: rval  */
#line 152 "limbaj.y"
              {printx("rvalues -> rval\n");(yyval.rvaluesNode) = new rValueNodes(); (yyval.rvaluesNode)->addRvalue((yyvsp[0].rvalNode)); }
#line 1479 "limbaj.tab.c"
    break;

  case 42: /* rvalues: rvalues ',' rval  */
#line 153 "limbaj.y"
                           {printx("rvalues -> rvalues , rval\n");(yyvsp[-2].rvaluesNode)->addRvalue((yyvsp[0].rvalNode));(yyval.rvaluesNode)=(yyvsp[-2].rvaluesNode);}
#line 1485 "limbaj.tab.c"
    break;

  case 43: /* parameter_List: parameter_List ',' parameter  */
#line 156 "limbaj.y"
                                              {printx("parameter list -> parameter llist , parameter\n"); (yyval.parListNode) = (yyvsp[-2].parListNode); (yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1491 "limbaj.tab.c"
    break;

  case 44: /* parameter_List: parameter  */
#line 157 "limbaj.y"
                    {printx("parameter list -> parameter\n");(yyval.parListNode) = new parameterList();(yyval.parListNode)->addParameter((yyvsp[0].parameterNode));}
#line 1497 "limbaj.tab.c"
    break;

  case 45: /* parameter: TYPE ID  */
#line 160 "limbaj.y"
                   { printx("\nparamter -> type id"); (yyval.parameterNode) = new Symbol(0,(yyvsp[-1].TypeNode)->type,(yyvsp[0].node)->content,nullptr);}
#line 1503 "limbaj.tab.c"
    break;

  case 46: /* expr: expr '+' expr  */
#line 163 "limbaj.y"
                        { printx("\nexpr -> expr + expr\n");(yyval.exprnode) = new ExpressionNode(OperTypes::ADD,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"+" + (yyvsp[0].exprnode)->content);  }
#line 1509 "limbaj.tab.c"
    break;

  case 47: /* expr: expr '-' expr  */
#line 164 "limbaj.y"
                        { printx("\nexpr -> expr - expr\n");(yyval.exprnode) = new ExpressionNode(OperTypes::SUB,(yyvsp[-2].exprnode),(yyvsp[0].exprnode), (yyvsp[-2].exprnode)->content +"-" + (yyvsp[0].exprnode)->content);  }
#line 1515 "limbaj.tab.c"
    break;

  case 48: /* expr: ID  */
#line 165 "limbaj.y"
             {printf("\nexpr -> ID\n");(yyval.exprnode) = new ExpressionNode(nullptr, (yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1521 "limbaj.tab.c"
    break;

  case 49: /* expr: NR  */
#line 166 "limbaj.y"
             {printf("\nexpr -> NR\n");(yyval.exprnode) = new ExpressionNode(nullptr, (yyvsp[0].node)->content); delete (yyvsp[0].node);}
#line 1527 "limbaj.tab.c"
    break;

  case 50: /* assignment: lval '=' rval  */
#line 169 "limbaj.y"
                           { (yyval.node) = new generalNode((yyvsp[-2].node)->content +"=" + (yyvsp[0].rvalNode)->content); delete (yyvsp[-2].node); delete (yyvsp[0].rvalNode);}
#line 1533 "limbaj.tab.c"
    break;

  case 51: /* lval: ID  */
#line 172 "limbaj.y"
                {printx("lval -> id\n"); checkSymbol((yyvsp[0].node));  }
#line 1539 "limbaj.tab.c"
    break;

  case 52: /* rval: expr  */
#line 175 "limbaj.y"
                 {printx("\nrval -> expression\n"); Symbol* _res = currentSymbolTable->create_temp_symbol((yyvsp[0].exprnode));
                 (yyval.rvalNode) = new IntType((yyvsp[0].exprnode)->content);}
#line 1546 "limbaj.tab.c"
    break;

  case 53: /* ISCONST: CONST  */
#line 178 "limbaj.y"
                {printx("isconst -> const\n");(yyval.node) = (yyvsp[0].node);}
#line 1552 "limbaj.tab.c"
    break;

  case 54: /* IF_S: IF '(' expr ')' '{'  */
#line 181 "limbaj.y"
                             { printx("\nIF_S -> IF ( expr ) {\n");(yyval.node) = new generalNode("IF_S"); delete (yyvsp[-4].node);string expr = "if("; expr+=(yyvsp[-2].exprnode)->content+")"; currentSymbolTable = currentSymbolTable->addScope(expr);}
#line 1558 "limbaj.tab.c"
    break;

  case 55: /* IF_B: IF_S statements '}'  */
#line 184 "limbaj.y"
                            { printx("\nIF_B -> IF_S statements }\n");(yyval.node) = new generalNode("IF_B"); backtrackScope();}
#line 1564 "limbaj.tab.c"
    break;

  case 56: /* IF_ELSE_S: IF_S statements '}' ELSE '{'  */
#line 187 "limbaj.y"
                                          { printx("\nIF_ELSE_S -> IF_S statements } ELSE {\n");(yyval.node) = new generalNode("IF_ELSE_S"); delete (yyvsp[-4].node); delete (yyvsp[-1].node);string elsescope = "else(" + currentSymbolTable->name+")"; backtrackScope(); currentSymbolTable = currentSymbolTable->addScope(elsescope);}
#line 1570 "limbaj.tab.c"
    break;

  case 57: /* IF_ELSE_B: IF_ELSE_S statements '}'  */
#line 190 "limbaj.y"
                                    { printx("\nIF_ELSE_B -> IF_ESLE_S statements }\n");(yyval.node) = new generalNode("IF_ELSE_B"); backtrackScope();}
#line 1576 "limbaj.tab.c"
    break;

  case 58: /* class_s: CLASS ID '{'  */
#line 193 "limbaj.y"
                      {printx("\nclassb_S-> class id { \n");(yyval.classNode) = currentSymbolTable = currentSymbolTable->newClass((yyvsp[-1].node));}
#line 1582 "limbaj.tab.c"
    break;

  case 59: /* decls_funcs: function  */
#line 195 "limbaj.y"
                      {printx("\ndecls_funcs -> funcs\n");}
#line 1588 "limbaj.tab.c"
    break;

  case 60: /* decls_funcs: declaration ';'  */
#line 196 "limbaj.y"
                          {printx("\ndecls_funcs -> decls\n"); }
#line 1594 "limbaj.tab.c"
    break;

  case 61: /* decls_funcs: decls_funcs declaration ';'  */
#line 197 "limbaj.y"
                                      {printx("\ndecls_funcs -> decls_funcs declaration\n");  }
#line 1600 "limbaj.tab.c"
    break;

  case 62: /* decls_funcs: decls_funcs function  */
#line 198 "limbaj.y"
                               {printx("\ndecls_funcs -> decls_funcs function\n");  }
#line 1606 "limbaj.tab.c"
    break;

  case 63: /* class_b: class_s decls_funcs '}'  */
#line 200 "limbaj.y"
                                  {printx("\nclassb -> class_S decls_funcs } \n"); backtrackScope();}
#line 1612 "limbaj.tab.c"
    break;

  case 64: /* class_b: class_s '}'  */
#line 201 "limbaj.y"
                      {printx("\nclassb -> class_S } \n");backtrackScope();}
#line 1618 "limbaj.tab.c"
    break;

  case 65: /* member_access: ID '.' ID  */
#line 203 "limbaj.y"
                         {printx("\nmember_access -> ID . ID \n"); currentSymbolTable->check_member_access((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = new generalNode("member accsss");}
#line 1624 "limbaj.tab.c"
    break;


#line 1628 "limbaj.tab.c"

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

#line 207 "limbaj.y"

 
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
