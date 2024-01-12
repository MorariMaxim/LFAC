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
#define check_main(f) {if(f->name != "main" ) semantic_error("no main function");  }
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


#line 110 "limbaj.tab.c"

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
  YYSYMBOL_9_ = 9,                         /* '('  */
  YYSYMBOL_10_ = 10,                       /* ')'  */
  YYSYMBOL_BGIN = 11,                      /* BGIN  */
  YYSYMBOL_END = 12,                       /* END  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_ID = 14,                        /* ID  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_RARROW = 20,                    /* RARROW  */
  YYSYMBOL_FN = 21,                        /* FN  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_CLASS = 23,                     /* CLASS  */
  YYSYMBOL_EVAL = 24,                      /* EVAL  */
  YYSYMBOL_CLASS_SECTION = 25,             /* CLASS_SECTION  */
  YYSYMBOL_GLOBAL_FUNCTIONS = 26,          /* GLOBAL_FUNCTIONS  */
  YYSYMBOL_GLOBAL_VARIABLES = 27,          /* GLOBAL_VARIABLES  */
  YYSYMBOL_MAIN_FUNCTION = 28,             /* MAIN_FUNCTION  */
  YYSYMBOL_LORT = 29,                      /* LORT  */
  YYSYMBOL_LANDT = 30,                     /* LANDT  */
  YYSYMBOL_LNOTT = 31,                     /* LNOTT  */
  YYSYMBOL_EQT = 32,                       /* EQT  */
  YYSYMBOL_NEQT = 33,                      /* NEQT  */
  YYSYMBOL_LEQT = 34,                      /* LEQT  */
  YYSYMBOL_GEQT = 35,                      /* GEQT  */
  YYSYMBOL_BTYPE = 36,                     /* BTYPE  */
  YYSYMBOL_FLOAT_TYPE = 37,                /* FLOAT_TYPE  */
  YYSYMBOL_INT_TYPE = 38,                  /* INT_TYPE  */
  YYSYMBOL_BOOL_TYPE = 39,                 /* BOOL_TYPE  */
  YYSYMBOL_STRING_TYPE = 40,               /* STRING_TYPE  */
  YYSYMBOL_CHAR_TYPE = 41,                 /* CHAR_TYPE  */
  YYSYMBOL_INTVAL = 42,                    /* INTVAL  */
  YYSYMBOL_FLOATVAL = 43,                  /* FLOATVAL  */
  YYSYMBOL_BOOLVAL = 44,                   /* BOOLVAL  */
  YYSYMBOL_STRINGVAL = 45,                 /* STRINGVAL  */
  YYSYMBOL_CHARVAL = 46,                   /* CHARVAL  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* '<'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_UMINUS = 53,                    /* UMINUS  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_progr = 58,                     /* progr  */
  YYSYMBOL_statements = 59,                /* statements  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_class_section = 61,             /* class_section  */
  YYSYMBOL_global_variables = 62,          /* global_variables  */
  YYSYMBOL_global_functions = 63,          /* global_functions  */
  YYSYMBOL_main = 64,                      /* main  */
  YYSYMBOL_return_statement = 65,          /* return_statement  */
  YYSYMBOL_return_value = 66,              /* return_value  */
  YYSYMBOL_gtype = 67,                     /* gtype  */
  YYSYMBOL_init = 68,                      /* init  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_class_declaration = 70,         /* class_declaration  */
  YYSYMBOL_object_init = 71,               /* object_init  */
  YYSYMBOL_field_val = 72,                 /* field_val  */
  YYSYMBOL_expressions = 73,               /* expressions  */
  YYSYMBOL_array_value = 74,               /* array_value  */
  YYSYMBOL_array_indexing = 75,            /* array_indexing  */
  YYSYMBOL_array_element = 76,             /* array_element  */
  YYSYMBOL_function = 77,                  /* function  */
  YYSYMBOL_function_body = 78,             /* function_body  */
  YYSYMBOL_func_signature = 79,            /* func_signature  */
  YYSYMBOL_return_type = 80,               /* return_type  */
  YYSYMBOL_function_call = 81,             /* function_call  */
  YYSYMBOL_id_parameters = 82,             /* id_parameters  */
  YYSYMBOL_exprs = 83,                     /* exprs  */
  YYSYMBOL_arguments = 84,                 /* arguments  */
  YYSYMBOL_param_list = 85,                /* param_list  */
  YYSYMBOL_parameter = 86,                 /* parameter  */
  YYSYMBOL_expr = 87,                      /* expr  */
  YYSYMBOL_assignment = 88,                /* assignment  */
  YYSYMBOL_ISCONST = 89,                   /* ISCONST  */
  YYSYMBOL_if_s = 90,                      /* if_s  */
  YYSYMBOL_if_b = 91,                      /* if_b  */
  YYSYMBOL_if_else_s = 92,                 /* if_else_s  */
  YYSYMBOL_if_else_b = 93,                 /* if_else_b  */
  YYSYMBOL_while_s = 94,                   /* while_s  */
  YYSYMBOL_while_b = 95,                   /* while_b  */
  YYSYMBOL_for_b = 96,                     /* for_b  */
  YYSYMBOL_for_s1 = 97,                    /* for_s1  */
  YYSYMBOL_for_s2 = 98,                    /* for_s2  */
  YYSYMBOL_for_d = 99,                     /* for_d  */
  YYSYMBOL_for_c = 100,                    /* for_c  */
  YYSYMBOL_for_st = 101,                   /* for_st  */
  YYSYMBOL_class_s = 102,                  /* class_s  */
  YYSYMBOL_decls_funcs = 103,              /* decls_funcs  */
  YYSYMBOL_class_b = 104,                  /* class_b  */
  YYSYMBOL_member_access = 105,            /* member_access  */
  YYSYMBOL_eval_expression = 106           /* eval_expression  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   916

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       9,    10,    51,    49,     8,    50,    56,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     7,
      48,    54,    47,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    95,    97,    98,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   113,   114,   116,   117,
     119,   120,   122,   125,   126,   127,   129,   130,   133,   134,
     137,   139,   141,   147,   149,   151,   152,   153,   154,   157,
     158,   160,   164,   165,   167,   169,   172,   173,   176,   180,
     181,   183,   185,   188,   189,   192,   193,   195,   196,   198,
     199,   202,   205,   206,   207,   208,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   236,   237,   238,
     243,   246,   249,   250,   253,   256,   257,   260,   262,   263,
     265,   266,   268,   270,   272,   273,   274,   275,   276,   277,
     281,   283,   284,   285,   286,   288,   289,   292,   294
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
  "']'", "';'", "','", "'('", "')'", "BGIN", "END", "ASSIGN", "ID", "IF",
  "ELSE", "WHILE", "FOR", "CONST", "RARROW", "FN", "RETURN", "CLASS",
  "EVAL", "CLASS_SECTION", "GLOBAL_FUNCTIONS", "GLOBAL_VARIABLES",
  "MAIN_FUNCTION", "LORT", "LANDT", "LNOTT", "EQT", "NEQT", "LEQT", "GEQT",
  "BTYPE", "FLOAT_TYPE", "INT_TYPE", "BOOL_TYPE", "STRING_TYPE",
  "CHAR_TYPE", "INTVAL", "FLOATVAL", "BOOLVAL", "STRINGVAL", "CHARVAL",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'='", "':'", "'.'",
  "$accept", "progr", "statements", "statement", "class_section",
  "global_variables", "global_functions", "main", "return_statement",
  "return_value", "gtype", "init", "declaration", "class_declaration",
  "object_init", "field_val", "expressions", "array_value",
  "array_indexing", "array_element", "function", "function_body",
  "func_signature", "return_type", "function_call", "id_parameters",
  "exprs", "arguments", "param_list", "parameter", "expr", "assignment",
  "ISCONST", "if_s", "if_b", "if_else_s", "if_else_b", "while_s",
  "while_b", "for_b", "for_s1", "for_s2", "for_d", "for_c", "for_st",
  "class_s", "decls_funcs", "class_b", "member_access", "eval_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   -80,    14,    84,   -80,     6,   -80,    16,    85,   -80,
      67,    78,   -80,   -80,   -80,    70,    80,   -80,    88,    65,
     -80,    94,   -80,   -80,   111,   130,   -80,   100,    91,   -80,
     -80,    18,   -80,   -80,   104,   -80,   784,   784,    12,   118,
     137,   -80,   742,   158,   784,   -80,   -80,   -80,   -80,   -80,
     784,   177,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   651,   161,   220,   102,   263,   -80,   306,   -80,   -80,
     160,   349,   116,   164,   -80,   -80,   -80,    46,   -80,   -80,
     784,   -80,   784,   -80,    33,     9,    29,    13,    49,   856,
     -80,   789,   760,   784,   159,    -4,   784,   784,   -80,   -80,
     680,   784,   -80,   -80,   -80,   -80,   -80,   784,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   784,   784,   -80,
     -80,   392,   169,   -80,   435,   -80,   478,    17,   -80,   521,
     784,   -80,   -80,   119,   109,   526,   687,   784,   -80,   -80,
     165,   142,   -80,   -80,    35,   -80,   170,   -80,   784,   -80,
     -80,   150,   856,   856,   174,   -80,   784,   821,   832,   -80,
     864,   198,   241,    89,    89,   113,   155,   155,   113,   -18,
     -18,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   802,
     -80,   856,   784,   171,   -80,   -80,   -80,   556,   -80,    35,
     -80,   175,   856,   784,   -80,   856,   181,   184,   -80,   -80,
     711,   604,   856,   135,   -80,   -80,   -80,   856,   -80,   -80,
     -80,   -80,   646,   190,   784,   -80,   -80,   856
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    16,     0,     0,     1,     0,    18,     0,     0,    17,
       0,     0,    90,    20,    27,     0,     0,    19,     0,     0,
     116,     0,   112,   111,     0,     0,   110,    33,     0,     2,
      21,     0,    32,    26,     0,    47,     0,     0,    77,     0,
       0,   102,     0,     0,     0,    78,    79,    81,    80,    82,
       0,     0,     4,    13,     6,    86,    85,    10,    45,    84,
      52,     0,     0,     0,     8,     0,     9,     0,    14,    15,
       0,     0,    83,     0,   115,   113,   114,     0,    34,    22,
       0,    29,     0,    30,     0,     0,     0,    77,     0,    39,
      83,     0,     0,     0,     0,    44,     0,     0,    25,    23,
       0,     0,    68,    75,    46,     5,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      93,     0,     0,    96,     0,    98,     0,     0,   100,     0,
       0,    12,    35,     0,     0,     0,     0,     0,    31,    58,
       0,     0,    60,    50,     0,    48,    44,    41,     0,    76,
      54,     0,    55,    87,   117,    51,     0,     0,     0,    24,
       0,    66,    67,    69,    70,    72,    74,    73,    71,    62,
      63,    65,    64,    92,    94,    95,    99,   105,   104,     0,
     101,    89,     0,     0,    36,    42,    28,     0,    61,     0,
      57,     0,    40,     0,    53,    88,     0,     0,   118,   107,
       0,     0,    37,     0,    43,    59,    49,    56,    91,    97,
     106,   109,     0,     0,     0,   108,   103,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -58,   -36,   -80,   -80,   -80,   -80,   -80,   -80,
     -79,   125,     4,   -80,   -80,   -80,   -80,   -80,    -1,   -80,
      36,   -80,   -80,   -80,   -80,   103,   -80,   -80,   -80,    11,
     -34,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -24,   -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    51,    52,     3,     7,    15,    29,    53,    99,
      16,    83,    54,    18,    78,   134,    88,    55,    84,    56,
      57,    58,    24,   145,    59,    60,   151,    86,   141,   142,
      61,    62,    19,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   179,   201,   213,     8,    25,     9,    90,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,   137,    89,    91,     1,   121,   140,   124,   100,   126,
     102,    17,    22,   129,     4,   105,   103,    80,    80,   139,
      10,    92,    92,    80,   177,    81,    27,    72,    12,    75,
      11,    11,   143,   117,   118,    12,    12,    95,   137,    72,
      81,    72,    13,    72,    23,    14,   135,    72,   136,   144,
     156,    30,    14,    14,    12,   147,   132,   148,   152,   153,
     133,    76,   157,   158,    79,   191,    93,   160,    94,    94,
      26,    14,    82,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   105,   146,    82,   105,    20,
     105,    21,    27,   105,    31,    32,   181,    72,    28,    11,
      72,    33,    72,   187,    12,    72,    21,     5,    34,    77,
     140,     6,    21,    85,   192,    35,    36,   183,   122,   184,
      37,    14,   195,   111,   112,    38,    39,    96,    40,    41,
      12,   178,    21,    42,    74,    43,   113,   114,   115,   116,
     117,   118,    44,   212,    11,   200,    97,    14,   202,    12,
     189,    21,   190,    45,    46,    47,    48,    49,   193,   207,
     194,    50,   115,   116,   117,   118,    14,   101,   119,   127,
     130,   131,   174,   154,   182,   137,   105,    72,   206,   188,
     217,   104,    36,    92,   208,   203,    37,   209,    72,   111,
     214,    38,    39,   216,    40,    41,    12,   155,    21,    42,
     205,    43,     0,   114,   115,   116,   117,   118,    44,   138,
       0,     0,     0,    14,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,   120,    36,     0,    50,   108,    37,
     109,   110,   111,   112,    38,    39,     0,    40,    41,    12,
       0,    21,    42,     0,    43,   113,   114,   115,   116,   117,
     118,    44,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,   123,    36,     0,
      50,     0,    37,   109,   110,   111,   112,    38,    39,     0,
      40,    41,    12,     0,    21,    42,     0,    43,   113,   114,
     115,   116,   117,   118,    44,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,    45,    46,    47,    48,    49,
     125,    36,     0,    50,     0,    37,     0,     0,     0,     0,
      38,    39,     0,    40,    41,    12,     0,    21,    42,     0,
      43,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,   128,    36,     0,    50,     0,    37,     0,
       0,     0,     0,    38,    39,     0,    40,    41,    12,     0,
      21,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,   173,    36,     0,    50,
       0,    37,     0,     0,     0,     0,    38,    39,     0,    40,
      41,    12,     0,    21,    42,     0,    43,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,   175,
      36,     0,    50,     0,    37,     0,     0,     0,     0,    38,
      39,     0,    40,    41,    12,     0,    21,    42,     0,    43,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,    45,    46,    47,
      48,    49,   176,    36,     0,    50,     0,    37,     0,     0,
       0,     0,    38,    39,     0,    40,    41,    12,     0,    21,
      42,     0,    43,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,   180,    36,     0,    50,     0,
      37,     0,   185,     0,     0,    38,    39,     0,    40,    41,
      12,     0,    21,    42,     0,    43,     0,     0,     0,     0,
       0,     0,    44,     0,     0,   107,   108,    14,   109,   110,
     111,   112,   204,    45,    46,    47,    48,    49,     0,     0,
       0,    50,     0,   113,   114,   115,   116,   117,   118,     0,
       0,     0,     0,     0,     0,   107,   108,     0,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,    36,
       0,     0,     0,    37,   211,     0,     0,     0,    38,    39,
       0,    40,    41,    12,     0,    21,    42,     0,    43,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,    36,     0,     0,    50,    37,   215,     0,   106,     0,
      38,    39,     0,    40,    41,    12,     0,    21,    42,     0,
      43,     0,     0,     0,     0,     0,     0,    44,     0,     0,
     107,   108,    14,   109,   110,   111,   112,   159,    45,    46,
      47,    48,    49,     0,   186,     0,    50,     0,   113,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,   107,
     108,     0,   109,   110,   111,   112,   107,   108,   210,   109,
     110,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,     0,   113,   114,   115,   116,   117,   118,
     107,   108,     0,   109,   110,   111,   112,    36,     0,    98,
       0,    37,     0,     0,     0,     0,    87,     0,   113,   114,
     115,   116,   117,   118,     0,    36,     0,     0,     0,    37,
     150,     0,     0,    44,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    36,
       0,    44,    50,    37,     0,     0,     0,     0,    87,   149,
       0,     0,    45,    46,    47,    48,    49,    36,     0,   199,
      50,    37,     0,     0,     0,    44,    87,     0,   107,   108,
       0,   109,   110,   111,   112,     0,    45,    46,    47,    48,
      49,   196,     0,    44,    50,     0,   113,   114,   115,   116,
     117,   118,   197,     0,    45,    46,    47,    48,    49,     0,
     107,   108,    50,   109,   110,   111,   112,     0,     0,     0,
       0,   107,   108,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   198,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   107,   108,     0,   109,   110,
     111,   112,     0,   107,   108,     0,   109,   110,   111,   112,
       0,     0,     0,   113,   114,   115,   116,   117,   118,     0,
       0,   113,   114,   115,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
      24,     5,    36,    37,    25,    63,    85,    65,    42,    67,
      44,     7,     8,    71,     0,    51,    50,     5,     5,    10,
      14,     9,     9,     5,     7,     7,    14,    51,    19,    25,
      14,    14,     3,    51,    52,    19,    19,    38,     5,    63,
       7,    65,    26,    67,     8,    36,    80,    71,    82,    20,
      54,    15,    36,    36,    19,     6,    10,     8,    92,    93,
      14,    25,    96,    97,    28,   144,    54,   101,    56,    56,
       3,    36,    54,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   121,    87,    54,   124,     4,
     126,    21,    14,   129,    14,     7,   130,   121,    28,    14,
     124,    36,   126,   137,    19,   129,    21,    23,    14,     9,
     189,    27,    21,     9,   148,     4,     5,     8,    16,    10,
       9,    36,   156,    34,    35,    14,    15,     9,    17,    18,
      19,   127,    21,    22,     4,    24,    47,    48,    49,    50,
      51,    52,    31,   201,    14,   179,     9,    36,   182,    19,
       8,    21,    10,    42,    43,    44,    45,    46,     8,   193,
      10,    50,    49,    50,    51,    52,    36,     9,     7,     9,
      54,     7,     3,    14,    55,     5,   212,   201,     3,    14,
     214,     4,     5,     9,     3,    14,     9,     3,   212,    34,
      55,    14,    15,     3,    17,    18,    19,    94,    21,    22,
     189,    24,    -1,    48,    49,    50,    51,    52,    31,    84,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,     4,     5,    -1,    50,    30,     9,
      32,    33,    34,    35,    14,    15,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    47,    48,    49,    50,    51,
      52,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,     4,     5,    -1,
      50,    -1,     9,    32,    33,    34,    35,    14,    15,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    47,    48,
      49,    50,    51,    52,    31,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
       4,     5,    -1,    50,    -1,     9,    -1,    -1,    -1,    -1,
      14,    15,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,     4,     5,    -1,    50,    -1,     9,    -1,
      -1,    -1,    -1,    14,    15,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,     4,     5,    -1,    50,
      -1,     9,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,     4,
       5,    -1,    50,    -1,     9,    -1,    -1,    -1,    -1,    14,
      15,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,     4,     5,    -1,    50,    -1,     9,    -1,    -1,
      -1,    -1,    14,    15,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,     4,     5,    -1,    50,    -1,
       9,    -1,     6,    -1,    -1,    14,    15,    -1,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    29,    30,    36,    32,    33,
      34,    35,     6,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    -1,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,     5,
      -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    14,    15,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,     5,    -1,    -1,    50,     9,    10,    -1,     7,    -1,
      14,    15,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      29,    30,    36,    32,    33,    34,    35,     7,    42,    43,
      44,    45,    46,    -1,     7,    -1,    50,    -1,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    32,    33,    34,    35,    29,    30,     7,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    -1,    47,    48,    49,    50,    51,    52,
      29,    30,    -1,    32,    33,    34,    35,     5,    -1,     7,
      -1,     9,    -1,    -1,    -1,    -1,    14,    -1,    47,    48,
      49,    50,    51,    52,    -1,     5,    -1,    -1,    -1,     9,
      10,    -1,    -1,    31,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,     5,
      -1,    31,    50,     9,    -1,    -1,    -1,    -1,    14,    10,
      -1,    -1,    42,    43,    44,    45,    46,     5,    -1,     7,
      50,     9,    -1,    -1,    -1,    31,    14,    -1,    29,    30,
      -1,    32,    33,    34,    35,    -1,    42,    43,    44,    45,
      46,    10,    -1,    31,    50,    -1,    47,    48,    49,    50,
      51,    52,    10,    -1,    42,    43,    44,    45,    46,    -1,
      29,    30,    50,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    47,    48,
      49,    50,    51,    52,    10,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    29,    30,    -1,    32,    33,
      34,    35,    -1,    29,    30,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    -1,
      -1,    47,    48,    49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    58,    61,     0,    23,    27,    62,   102,   104,
      14,    14,    19,    26,    36,    63,    67,    69,    70,    89,
       4,    21,    69,    77,    79,   103,     3,    14,    28,    64,
      77,    14,     7,    36,    14,     4,     5,     9,    14,    15,
      17,    18,    22,    24,    31,    42,    43,    44,    45,    46,
      50,    59,    60,    65,    69,    74,    76,    77,    78,    81,
      82,    87,    88,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   105,   106,     4,    69,    77,     9,    71,    77,
       5,     7,    54,    68,    75,     9,    84,    14,    73,    87,
     105,    87,     9,    54,    56,    75,     9,     9,     7,    66,
      87,     9,    87,    87,     4,    60,     7,    29,    30,    32,
      33,    34,    35,    47,    48,    49,    50,    51,    52,     7,
       4,    59,    16,     4,    59,     4,    59,     9,     4,    59,
      54,     7,    10,    14,    72,    87,    87,     5,    68,    10,
      67,    85,    86,     3,    20,    80,    75,     6,     8,    10,
      10,    83,    87,    87,    14,    82,    54,    87,    87,     7,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,     4,     3,     4,     4,     7,    69,    99,
       4,    87,    55,     8,    10,     6,     7,    87,    14,     8,
      10,    67,    87,     8,    10,    87,    10,    10,    10,     7,
      87,   100,    87,    14,     6,    86,     3,    87,     3,     3,
       7,    10,    59,   101,    55,    10,     3,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    75,    75,    76,    77,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      89,    90,    91,    91,    92,    93,    93,    94,    95,    95,
      96,    96,    97,    98,    99,    99,   100,   100,   101,   101,
     102,   103,   103,   103,   103,   104,   104,   105,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     1,     2,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     2,     2,     2,     1,     2,     1,     3,     1,
       3,     4,     2,     2,     3,     2,     3,     3,     5,     1,
       3,     3,     3,     4,     2,     2,     2,     1,     4,     3,
       1,     3,     1,     4,     3,     1,     3,     3,     2,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       1,     5,     3,     2,     3,     3,     2,     5,     2,     3,
       2,     3,     1,     6,     1,     1,     2,     1,     2,     1,
       3,     1,     1,     2,     2,     3,     2,     3,     4
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
  case 2: /* progr: class_section global_variables global_functions main  */
#line 94 "limbaj.y"
                                                             { print_reduction("syntactically correct program"); }
#line 1495 "limbaj.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 95 "limbaj.y"
                     { print_reduction("empty prog");}
#line 1501 "limbaj.tab.c"
    break;

  case 4: /* statements: statement  */
#line 97 "limbaj.y"
                       { (yyval.node) = (yyvsp[0].node); print_reduction("statements -> statement");}
#line 1507 "limbaj.tab.c"
    break;

  case 5: /* statements: statements statement  */
#line 98 "limbaj.y"
                                { (yyval.node) = (yyvsp[-1].node); print_reduction("statements -> statements statement");}
#line 1513 "limbaj.tab.c"
    break;

  case 6: /* statement: declaration  */
#line 101 "limbaj.y"
                      { print_reduction("stmt -> declaration");}
#line 1519 "limbaj.tab.c"
    break;

  case 7: /* statement: expr ';'  */
#line 102 "limbaj.y"
                    { print_reduction("stmt -> expr");}
#line 1525 "limbaj.tab.c"
    break;

  case 8: /* statement: if_b  */
#line 103 "limbaj.y"
               { print_reduction("stmt -> IF_B");}
#line 1531 "limbaj.tab.c"
    break;

  case 9: /* statement: if_else_b  */
#line 104 "limbaj.y"
                    { print_reduction("statement -> IF_ELSE_B");}
#line 1537 "limbaj.tab.c"
    break;

  case 10: /* statement: function  */
#line 105 "limbaj.y"
                   { print_reduction("statement -> function"); (yyval.node) = (yyvsp[0].funcNode);}
#line 1543 "limbaj.tab.c"
    break;

  case 11: /* statement: assignment ';'  */
#line 106 "limbaj.y"
                         {print_reduction("statement -> assignment");}
#line 1549 "limbaj.tab.c"
    break;

  case 12: /* statement: eval_expression ';'  */
#line 107 "limbaj.y"
                              {print_reduction("statement -> eval_expression");}
#line 1555 "limbaj.tab.c"
    break;

  case 13: /* statement: return_statement  */
#line 108 "limbaj.y"
                           {print_reduction("statement -> return statement");}
#line 1561 "limbaj.tab.c"
    break;

  case 14: /* statement: while_b  */
#line 109 "limbaj.y"
                  {print_reduction("statement -> while_b");}
#line 1567 "limbaj.tab.c"
    break;

  case 15: /* statement: for_b  */
#line 110 "limbaj.y"
                {print_reduction("statement -> for_b");}
#line 1573 "limbaj.tab.c"
    break;

  case 23: /* return_statement: RETURN return_value  */
#line 125 "limbaj.y"
                                      {print_reduction("ret_statement -> return return_value "); treat_return_statement((yyvsp[0].exprnode)); ignore_after_return_statement = true;}
#line 1579 "limbaj.tab.c"
    break;

  case 24: /* return_value: expr ';'  */
#line 126 "limbaj.y"
                       {(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 1585 "limbaj.tab.c"
    break;

  case 25: /* return_value: ';'  */
#line 127 "limbaj.y"
                   {(yyval.exprnode)=nullptr;}
#line 1591 "limbaj.tab.c"
    break;

  case 26: /* gtype: ISCONST BTYPE  */
#line 129 "limbaj.y"
                     {(yyval.TypeNode) = (yyvsp[0].TypeNode); (yyval.TypeNode)->is_const = 1;}
#line 1597 "limbaj.tab.c"
    break;

  case 27: /* gtype: BTYPE  */
#line 130 "limbaj.y"
                {(yyval.TypeNode) = (yyvsp[0].TypeNode);}
#line 1603 "limbaj.tab.c"
    break;

  case 28: /* init: '=' expr ';'  */
#line 133 "limbaj.y"
                    {(yyval.exprnode) = (yyvsp[-1].exprnode);}
#line 1609 "limbaj.tab.c"
    break;

  case 29: /* init: ';'  */
#line 134 "limbaj.y"
              {(yyval.exprnode) = nullptr;}
#line 1615 "limbaj.tab.c"
    break;

  case 30: /* declaration: gtype ID init  */
#line 137 "limbaj.y"
                          { print_reduction("decl->const type id init;");
                                            currentSymbolTable->declare_symbol((yyvsp[-2].TypeNode),(yyvsp[-1].node),(yyvsp[0].exprnode));  (yyval.node) = new RawNode("");}
#line 1622 "limbaj.tab.c"
    break;

  case 31: /* declaration: gtype ID array_indexing init  */
#line 139 "limbaj.y"
                                        { print_reduction("decl -> gtype ID array_indexing init");
                                                currentSymbolTable->declare_array_symbol((yyvsp[-2].node),(yyvsp[-3].TypeNode), (yyvsp[-1].arrayIndexingNode),(yyvsp[0].exprnode)); (yyval.node) = (yyvsp[-2].node);}
#line 1629 "limbaj.tab.c"
    break;

  case 32: /* declaration: class_declaration ';'  */
#line 141 "limbaj.y"
                                {print_reduction(" declaration -> class_declaration ");}
#line 1635 "limbaj.tab.c"
    break;

  case 33: /* class_declaration: ID ID  */
#line 147 "limbaj.y"
                {print_reduction(" dclass_Declaration -> uninitialized ");currentSymbolTable->declare_user_symbol((yyvsp[-1].node),(yyvsp[0].node));}
#line 1641 "limbaj.tab.c"
    break;

  case 34: /* class_declaration: ID ID object_init  */
#line 149 "limbaj.y"
                            {print_reduction(" dclass_Declaration -> initialized");currentSymbolTable->declare_user_symbol((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].container));}
#line 1647 "limbaj.tab.c"
    break;

  case 35: /* object_init: '(' ')'  */
#line 151 "limbaj.y"
                     {(yyval.container) = nullptr;}
#line 1653 "limbaj.tab.c"
    break;

  case 36: /* object_init: '(' field_val ')'  */
#line 152 "limbaj.y"
                            {(yyval.container) = (yyvsp[-1].container);}
#line 1659 "limbaj.tab.c"
    break;

  case 37: /* field_val: ID ':' expr  */
#line 153 "limbaj.y"
                       {print_reduction("field_Val -> ID : expr"); (yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[-2].node));(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1665 "limbaj.tab.c"
    break;

  case 38: /* field_val: field_val ',' ID ':' expr  */
#line 154 "limbaj.y"
                                    {print_reduction("field_Val -> field_val , ID : expr"); (yyval.container) = (yyvsp[-4].container); (yyval.container)->add_element((yyvsp[-2].node));(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1671 "limbaj.tab.c"
    break;

  case 39: /* expressions: expr  */
#line 157 "limbaj.y"
                  {print_reduction("expressions -> expr"); (yyval.container) = new Vector();(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1677 "limbaj.tab.c"
    break;

  case 40: /* expressions: expressions ',' expr  */
#line 158 "limbaj.y"
                               {print_reduction("expressions -> expressions , expr"); (yyval.container) = (yyvsp[-2].container);(yyval.container)->add_element((yyvsp[0].exprnode));}
#line 1683 "limbaj.tab.c"
    break;

  case 41: /* array_value: '[' expressions ']'  */
#line 160 "limbaj.y"
                                 {print_reduction("array_value ->  [ expressions ] "); (yyval.array_value_node) = new ArrayValue((yyvsp[-1].container));}
#line 1689 "limbaj.tab.c"
    break;

  case 42: /* array_indexing: '[' expr ']'  */
#line 164 "limbaj.y"
                             {print_reduction("array_indexing -> '[' rval ']'");(yyval.arrayIndexingNode)  = new ArrayIndexing(); (yyval.arrayIndexingNode)->add_index((yyvsp[-1].exprnode)); }
#line 1695 "limbaj.tab.c"
    break;

  case 43: /* array_indexing: array_indexing '[' expr ']'  */
#line 165 "limbaj.y"
                                      {print_reduction("array_indexing -> array_indexing '[' INTVAL ']'"); (yyval.arrayIndexingNode) = (yyvsp[-3].arrayIndexingNode); (yyval.arrayIndexingNode)->add_index((yyvsp[-1].exprnode));}
#line 1701 "limbaj.tab.c"
    break;

  case 44: /* array_element: ID array_indexing  */
#line 167 "limbaj.y"
                                 {print_reduction("array element") ;(yyval.value_node) = currentSymbolTable->symbol_indexing((yyvsp[-1].node),(yyvsp[0].arrayIndexingNode));}
#line 1707 "limbaj.tab.c"
    break;

  case 45: /* function: func_signature function_body  */
#line 169 "limbaj.y"
                                      { print_reduction("function -> func_signature statements return rval}");
                                                backtrack_scope();(yyval.funcNode) = (yyvsp[-1].funcNode);(yyval.funcNode)->check_return_type();(yyval.funcNode)->set_lines((yyvsp[-1].funcNode),(yyvsp[0].node)); }
#line 1714 "limbaj.tab.c"
    break;

  case 46: /* function_body: statements '}'  */
#line 172 "limbaj.y"
                              {print_reduction(" funcbody -> statements }"); (yyval.node) = (yyvsp[-1].node);(yyval.node)->set_span((yyvsp[0].spanned));printf("body set spanned to %s\n",(yyvsp[0].spanned)->span_to_string().c_str());}
#line 1720 "limbaj.tab.c"
    break;

  case 47: /* function_body: '}'  */
#line 173 "limbaj.y"
              {print_reduction(" funcbody -> empty }"); (yyval.node) = new RawNode();(yyval.node)->set_span((yyvsp[0].spanned));printf("body set spanned to %s\n",(yyvsp[0].spanned)->span_to_string().c_str());}
#line 1726 "limbaj.tab.c"
    break;

  case 48: /* func_signature: FN ID arguments return_type  */
#line 176 "limbaj.y"
                                     { print_reduction("functions_s -> fn id arguments -> type {"); (yyval.funcNode) = new FunctionDetails((yyvsp[-2].node)->content,(yyvsp[0].TypeNode),(yyvsp[-1].container)); (yyval.funcNode)->set_span((yyvsp[-2].node)); printf("signature set spanned to %s\n",(yyval.funcNode)->span_to_string().c_str());
                                        currentSymbolTable=  currentSymbolTable->addFunction((yyval.funcNode)); currentSymbolTable->set_span((yyvsp[-2].node));
                                        }
#line 1734 "limbaj.tab.c"
    break;

  case 49: /* return_type: RARROW gtype '{'  */
#line 180 "limbaj.y"
                              {print_reduction("return_type -> RARROW gtype {"); (yyval.TypeNode) = (yyvsp[-1].TypeNode);}
#line 1740 "limbaj.tab.c"
    break;

  case 50: /* return_type: '{'  */
#line 181 "limbaj.y"
             {print_reduction("return_type - -> empty {"); (yyval.TypeNode) = nullptr;}
#line 1746 "limbaj.tab.c"
    break;

  case 51: /* function_call: ID '.' id_parameters  */
#line 183 "limbaj.y"
                                     {print_reduction("FunctionCall -> ID . id_parameters"); (yyval.funcCall) = new FunctionCall((yyvsp[-2].node),(yyvsp[0].container));
                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call");}
#line 1753 "limbaj.tab.c"
    break;

  case 52: /* function_call: id_parameters  */
#line 185 "limbaj.y"
                               {print_reduction("FunctionCall -> id_parameters"); (yyval.funcCall) = new FunctionCall(nullptr,(yyvsp[0].container));

                                bool correct = (yyval.funcCall)->checkCall();if(correct) printf("correct call\n"); else printf("incorrect call");}
#line 1761 "limbaj.tab.c"
    break;

  case 53: /* id_parameters: ID '(' exprs ')'  */
#line 188 "limbaj.y"
                                {print_reduction("id_parameters -> id ( rvalues )");(yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[-3].node));(yyval.container)->add_element((yyvsp[-1].container)); }
#line 1767 "limbaj.tab.c"
    break;

  case 54: /* id_parameters: ID '(' ')'  */
#line 189 "limbaj.y"
                        {print_reduction("id_parameters -> id ()");(yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[-2].node));}
#line 1773 "limbaj.tab.c"
    break;

  case 55: /* exprs: expr  */
#line 192 "limbaj.y"
            {print_reduction("exprs -> expr");(yyval.container) = new Vector(); (yyval.container)->add_element((yyvsp[0].exprnode)); }
#line 1779 "limbaj.tab.c"
    break;

  case 56: /* exprs: exprs ',' expr  */
#line 193 "limbaj.y"
                         {print_reduction("exprs -> exprs , expr");(yyvsp[-2].container)->add_element((yyvsp[0].exprnode));(yyval.container)=(yyvsp[-2].container);}
#line 1785 "limbaj.tab.c"
    break;

  case 57: /* arguments: '(' param_list ')'  */
#line 195 "limbaj.y"
                              {print_reduction("arguments -> parameter llist"); (yyval.container) = (yyvsp[-1].container);}
#line 1791 "limbaj.tab.c"
    break;

  case 58: /* arguments: '(' ')'  */
#line 196 "limbaj.y"
                  {print_reduction("arguments -> empty"); (yyval.container) = nullptr;}
#line 1797 "limbaj.tab.c"
    break;

  case 59: /* param_list: param_list ',' parameter  */
#line 198 "limbaj.y"
                                      {print_reduction("parameter list -> parameter llist , parameter"); (yyval.container) = (yyvsp[-2].container); (yyval.container)->add_element((yyvsp[0].symbol_node));}
#line 1803 "limbaj.tab.c"
    break;

  case 60: /* param_list: parameter  */
#line 199 "limbaj.y"
                     {print_reduction("parameter list -> parameter");(yyval.container) = new Vector();(yyval.container)->add_element((yyvsp[0].symbol_node));}
#line 1809 "limbaj.tab.c"
    break;

  case 61: /* parameter: gtype ID  */
#line 202 "limbaj.y"
                    { print_reduction("paramter -> type id"); (yyval.symbol_node) = new Symbol((yyvsp[0].node)->content,(yyvsp[-1].TypeNode),nullptr);}
#line 1815 "limbaj.tab.c"
    break;

  case 62: /* expr: expr '+' expr  */
#line 205 "limbaj.y"
                        { print_reduction("expr -> expr + expr");(yyval.exprnode) = new Expression(OperTypes::ADD,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1821 "limbaj.tab.c"
    break;

  case 63: /* expr: expr '-' expr  */
#line 206 "limbaj.y"
                        { print_reduction("expr -> expr - expr");(yyval.exprnode) = new Expression(OperTypes::SUB,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1827 "limbaj.tab.c"
    break;

  case 64: /* expr: expr '/' expr  */
#line 207 "limbaj.y"
                        { print_reduction("expr -> expr / expr");(yyval.exprnode) = new Expression(OperTypes::DIV,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1833 "limbaj.tab.c"
    break;

  case 65: /* expr: expr '*' expr  */
#line 208 "limbaj.y"
                        { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::MUL,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1839 "limbaj.tab.c"
    break;

  case 66: /* expr: expr LORT expr  */
#line 210 "limbaj.y"
                         { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::LOR,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1845 "limbaj.tab.c"
    break;

  case 67: /* expr: expr LANDT expr  */
#line 211 "limbaj.y"
                          { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::LAND,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1851 "limbaj.tab.c"
    break;

  case 68: /* expr: LNOTT expr  */
#line 212 "limbaj.y"
                                   { print_reduction("expr -> ! expr");(yyval.exprnode) = new Expression(OperTypes::LNOT,(yyvsp[0].exprnode),nullptr);}
#line 1857 "limbaj.tab.c"
    break;

  case 69: /* expr: expr EQT expr  */
#line 213 "limbaj.y"
                        { print_reduction("expr -> expr == expr");(yyval.exprnode) = new Expression(OperTypes::EQ,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1863 "limbaj.tab.c"
    break;

  case 70: /* expr: expr NEQT expr  */
#line 214 "limbaj.y"
                         { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::NEQ,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1869 "limbaj.tab.c"
    break;

  case 71: /* expr: expr '<' expr  */
#line 215 "limbaj.y"
                        { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::LE,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1875 "limbaj.tab.c"
    break;

  case 72: /* expr: expr LEQT expr  */
#line 216 "limbaj.y"
                         { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::LEQ,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1881 "limbaj.tab.c"
    break;

  case 73: /* expr: expr '>' expr  */
#line 217 "limbaj.y"
                        { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::GE,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1887 "limbaj.tab.c"
    break;

  case 74: /* expr: expr GEQT expr  */
#line 218 "limbaj.y"
                         { print_reduction("expr -> expr * expr");(yyval.exprnode) = new Expression(OperTypes::GEQ,(yyvsp[-2].exprnode),(yyvsp[0].exprnode));}
#line 1893 "limbaj.tab.c"
    break;

  case 75: /* expr: '-' expr  */
#line 220 "limbaj.y"
                                 { print_reduction("expr -> - expr");(yyval.exprnode) = new Expression(OperTypes::NEG,(yyvsp[0].exprnode),nullptr);}
#line 1899 "limbaj.tab.c"
    break;

  case 76: /* expr: '(' expr ')'  */
#line 221 "limbaj.y"
                       { print_reduction("expr -> ( expr ) ");(yyval.exprnode) = (yyvsp[-1].exprnode);(yyval.exprnode)->set_span_start((yyvsp[-2].spanned));(yyval.exprnode)->set_span_end((yyvsp[0].spanned));(yyvsp[-2].spanned)->print_span();(yyvsp[0].spanned)->print_span();}
#line 1905 "limbaj.tab.c"
    break;

  case 77: /* expr: ID  */
#line 222 "limbaj.y"
             {print_reduction("expr -> ID");(yyval.exprnode) = new Expression((yyvsp[0].node)); delete (yyvsp[0].node);}
#line 1911 "limbaj.tab.c"
    break;

  case 78: /* expr: INTVAL  */
#line 223 "limbaj.y"
                 {print_reduction("expr -> INTVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1917 "limbaj.tab.c"
    break;

  case 79: /* expr: FLOATVAL  */
#line 224 "limbaj.y"
                   {print_reduction("expr -> FLOATVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1923 "limbaj.tab.c"
    break;

  case 80: /* expr: STRINGVAL  */
#line 225 "limbaj.y"
                    {print_reduction("expr -> STRINGVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1929 "limbaj.tab.c"
    break;

  case 81: /* expr: BOOLVAL  */
#line 226 "limbaj.y"
                  {print_reduction("expr -> BOOLVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1935 "limbaj.tab.c"
    break;

  case 82: /* expr: CHARVAL  */
#line 227 "limbaj.y"
                  {print_reduction("expr -> CHARVAL");(yyval.exprnode) = new Expression((yyvsp[0].value_node)); }
#line 1941 "limbaj.tab.c"
    break;

  case 83: /* expr: member_access  */
#line 228 "limbaj.y"
                        {print_reduction("expr -> member_access");(yyval.exprnode) = new Expression((yyvsp[0].symbol_node)); }
#line 1947 "limbaj.tab.c"
    break;

  case 84: /* expr: function_call  */
#line 229 "limbaj.y"
                        {print_reduction("epxr - function call ");(yyval.exprnode) = new Expression((yyvsp[0].funcCall));}
#line 1953 "limbaj.tab.c"
    break;

  case 85: /* expr: array_element  */
#line 230 "limbaj.y"
                        {print_reduction("epxr - array_element ");(yyval.exprnode) = new Expression((yyvsp[0].value_node));}
#line 1959 "limbaj.tab.c"
    break;

  case 86: /* expr: array_value  */
#line 231 "limbaj.y"
                      {print_reduction("epxr - array_value ");(yyval.exprnode) = new Expression((yyvsp[0].array_value_node));}
#line 1965 "limbaj.tab.c"
    break;

  case 87: /* assignment: ID '=' expr  */
#line 236 "limbaj.y"
                      {print_reduction(" ID = expr"); currentSymbolTable->assign((yyvsp[-2].node), (yyvsp[0].exprnode), nullptr);}
#line 1971 "limbaj.tab.c"
    break;

  case 88: /* assignment: ID array_indexing '=' expr  */
#line 237 "limbaj.y"
                                     {print_reduction(" ID = expr"); currentSymbolTable->assign((yyvsp[-3].node),(yyvsp[0].exprnode),(yyvsp[-2].arrayIndexingNode));}
#line 1977 "limbaj.tab.c"
    break;

  case 89: /* assignment: member_access '=' expr  */
#line 238 "limbaj.y"
                                 {print_reduction(" member_access = expr"); currentSymbolTable->assign((yyvsp[-2].symbol_node),(yyvsp[0].exprnode),nullptr);}
#line 1983 "limbaj.tab.c"
    break;

  case 90: /* ISCONST: CONST  */
#line 243 "limbaj.y"
                {print_reduction("isconst -> const");(yyval.node) = (yyvsp[0].node);}
#line 1989 "limbaj.tab.c"
    break;

  case 91: /* if_s: IF '(' expr ')' '{'  */
#line 246 "limbaj.y"
                             { print_reduction("IF_S -> IF ( expr ) {");(yyval.node) = new RawNode("IF_S"); delete (yyvsp[-4].node); currentSymbolTable = currentSymbolTable->addScope("if");}
#line 1995 "limbaj.tab.c"
    break;

  case 92: /* if_b: if_s statements '}'  */
#line 249 "limbaj.y"
                            { print_reduction("IF_B -> IF_S statements }");(yyval.node) = new RawNode("IF_B"); backtrack_scope();}
#line 2001 "limbaj.tab.c"
    break;

  case 93: /* if_b: if_s '}'  */
#line 250 "limbaj.y"
                    { print_reduction("IF_B -> IF_S  }");(yyval.node) = new RawNode("IF_B"); backtrack_scope();}
#line 2007 "limbaj.tab.c"
    break;

  case 94: /* if_else_s: if_b ELSE '{'  */
#line 253 "limbaj.y"
                           { print_reduction("IF_ELSE_S -> if_b ELSE {");(yyval.node) = new RawNode("IF_ELSE_S"); delete (yyvsp[-2].node); delete (yyvsp[-1].node); delete (yyvsp[0].spanned); currentSymbolTable = currentSymbolTable->addScope("else");}
#line 2013 "limbaj.tab.c"
    break;

  case 95: /* if_else_b: if_else_s statements '}'  */
#line 256 "limbaj.y"
                                    { print_reduction("IF_ELSE_B -> if_else_s { statements } ");(yyval.node) = new RawNode("IF_ELSE_B"); backtrack_scope();}
#line 2019 "limbaj.tab.c"
    break;

  case 96: /* if_else_b: if_else_s '}'  */
#line 257 "limbaj.y"
                         { print_reduction("IF_ELSE_B -> if_else_s { } ");(yyval.node) = new RawNode("IF_ELSE_B"); backtrack_scope();}
#line 2025 "limbaj.tab.c"
    break;

  case 97: /* while_s: WHILE '(' expr ')' '{'  */
#line 260 "limbaj.y"
                                {currentSymbolTable = currentSymbolTable->addScope("while"); }
#line 2031 "limbaj.tab.c"
    break;

  case 98: /* while_b: while_s '}'  */
#line 262 "limbaj.y"
                     {backtrack_scope();}
#line 2037 "limbaj.tab.c"
    break;

  case 99: /* while_b: while_s statements '}'  */
#line 263 "limbaj.y"
                                {backtrack_scope();}
#line 2043 "limbaj.tab.c"
    break;

  case 100: /* for_b: for_s2 '}'  */
#line 265 "limbaj.y"
                  {backtrack_scope();}
#line 2049 "limbaj.tab.c"
    break;

  case 101: /* for_b: for_s2 statements '}'  */
#line 266 "limbaj.y"
                               {backtrack_scope();}
#line 2055 "limbaj.tab.c"
    break;

  case 102: /* for_s1: FOR  */
#line 268 "limbaj.y"
            { {print_reduction("for_s1 -> FOR");} currentSymbolTable = currentSymbolTable->addScope("for"); }
#line 2061 "limbaj.tab.c"
    break;

  case 104: /* for_d: declaration  */
#line 272 "limbaj.y"
                   {print_reduction("for_d -> declaration ;");}
#line 2067 "limbaj.tab.c"
    break;

  case 105: /* for_d: ';'  */
#line 273 "limbaj.y"
                {print_reduction("for_d -> ;");}
#line 2073 "limbaj.tab.c"
    break;

  case 106: /* for_c: expr ';'  */
#line 274 "limbaj.y"
                {print_reduction("for_c -> expr ;");}
#line 2079 "limbaj.tab.c"
    break;

  case 107: /* for_c: ';'  */
#line 275 "limbaj.y"
             {print_reduction("for_c -> ;");}
#line 2085 "limbaj.tab.c"
    break;

  case 110: /* class_s: CLASS ID '{'  */
#line 281 "limbaj.y"
                      {print_reduction("classb_S-> class id { ");(yyval.classNode) = currentSymbolTable = currentSymbolTable->add_class((yyvsp[-1].node));}
#line 2091 "limbaj.tab.c"
    break;

  case 111: /* decls_funcs: function  */
#line 283 "limbaj.y"
                      {print_reduction("decls_funcs -> funcs");}
#line 2097 "limbaj.tab.c"
    break;

  case 112: /* decls_funcs: declaration  */
#line 284 "limbaj.y"
                       {print_reduction("decls_funcs -> decls"); }
#line 2103 "limbaj.tab.c"
    break;

  case 113: /* decls_funcs: decls_funcs declaration  */
#line 285 "limbaj.y"
                                   {print_reduction("decls_funcs -> decls_funcs declaration");  }
#line 2109 "limbaj.tab.c"
    break;

  case 114: /* decls_funcs: decls_funcs function  */
#line 286 "limbaj.y"
                               {print_reduction("decls_funcs -> decls_funcs function");  }
#line 2115 "limbaj.tab.c"
    break;

  case 115: /* class_b: class_s decls_funcs '}'  */
#line 288 "limbaj.y"
                                  {print_reduction("classb -> class_S decls_funcs } "); backtrack_scope();}
#line 2121 "limbaj.tab.c"
    break;

  case 116: /* class_b: class_s '}'  */
#line 289 "limbaj.y"
                      {print_reduction("classb -> class_S } ");backtrack_scope();}
#line 2127 "limbaj.tab.c"
    break;

  case 117: /* member_access: ID '.' ID  */
#line 292 "limbaj.y"
                         {print_reduction("member_access -> ID . ID "); (yyval.symbol_node) = currentSymbolTable->check_member_access((yyvsp[-2].node),(yyvsp[0].node));(yyval.symbol_node)->set_span((yyvsp[-2].node),(yyvsp[0].node));}
#line 2133 "limbaj.tab.c"
    break;

  case 118: /* eval_expression: EVAL '(' expr ')'  */
#line 294 "limbaj.y"
                                     {print_reduction("evalexpr -> eval ( expr ) "); (yyvsp[-1].exprnode)->eval_wrapper(); }
#line 2139 "limbaj.tab.c"
    break;


#line 2143 "limbaj.tab.c"

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

#line 296 "limbaj.y"


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

