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
#line 11 "parser.ypp"

    #include <iostream>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <fstream>
    #include "SymbolTable.h"
    #include "helper.h"
    #include "AbstractSyntaxTree.h"

    #define YYDEBUG 1 
    
    extern int yylex();
    extern int yylineno;
    extern char* yytext;
    void yyerror(const char *s);

    SymbolTable* currentScope = nullptr , *globalScope = nullptr;
    std::map < std::string , SymbolTable* > classes;
   

#line 93 "parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_TYPE = 4,                       /* TYPE  */
  YYSYMBOL_INT_CONST = 5,                  /* INT_CONST  */
  YYSYMBOL_BOOL_CONST = 6,                 /* BOOL_CONST  */
  YYSYMBOL_FLOAT_CONST = 7,                /* FLOAT_CONST  */
  YYSYMBOL_STRING_CONST = 8,               /* STRING_CONST  */
  YYSYMBOL_KEYWORD_CLASS = 9,              /* KEYWORD_CLASS  */
  YYSYMBOL_KEYWORD_FUNC = 10,              /* KEYWORD_FUNC  */
  YYSYMBOL_KEYWORD_IF = 11,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_MAIN = 12,              /* KEYWORD_MAIN  */
  YYSYMBOL_KEYWORD_RETURN = 13,            /* KEYWORD_RETURN  */
  YYSYMBOL_KEYWORD_WHILE = 14,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_FOR = 15,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_PRINT = 16,             /* KEYWORD_PRINT  */
  YYSYMBOL_KEYWORD_DEFINE = 17,            /* KEYWORD_DEFINE  */
  YYSYMBOL_KEYWORD_THEN = 18,              /* KEYWORD_THEN  */
  YYSYMBOL_ADD_OP = 19,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 20,                    /* SUB_OP  */
  YYSYMBOL_MUL_OP = 21,                    /* MUL_OP  */
  YYSYMBOL_DIV_OP = 22,                    /* DIV_OP  */
  YYSYMBOL_ASSIGN_OP = 23,                 /* ASSIGN_OP  */
  YYSYMBOL_MOD_OP = 24,                    /* MOD_OP  */
  YYSYMBOL_EQ_OP = 25,                     /* EQ_OP  */
  YYSYMBOL_NEQ_OP = 26,                    /* NEQ_OP  */
  YYSYMBOL_LT_OP = 27,                     /* LT_OP  */
  YYSYMBOL_GT_OP = 28,                     /* GT_OP  */
  YYSYMBOL_GEQ_OP = 29,                    /* GEQ_OP  */
  YYSYMBOL_LEQ_OP = 30,                    /* LEQ_OP  */
  YYSYMBOL_OP_AND = 31,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 32,                     /* OP_OR  */
  YYSYMBOL_OP_BIT_AND = 33,                /* OP_BIT_AND  */
  YYSYMBOL_OP_BIT_OR = 34,                 /* OP_BIT_OR  */
  YYSYMBOL_OP_BIT_XOR = 35,                /* OP_BIT_XOR  */
  YYSYMBOL_OP_BIT_LSHIFT = 36,             /* OP_BIT_LSHIFT  */
  YYSYMBOL_OP_BIT_RSHIFT = 37,             /* OP_BIT_RSHIFT  */
  YYSYMBOL_NOT_OP = 38,                    /* NOT_OP  */
  YYSYMBOL_OPEN_ROUND_PAR = 39,            /* OPEN_ROUND_PAR  */
  YYSYMBOL_CLOSED_ROUND_PAR = 40,          /* CLOSED_ROUND_PAR  */
  YYSYMBOL_OPEN_RECTANGLE_PAR = 41,        /* OPEN_RECTANGLE_PAR  */
  YYSYMBOL_CLOSED_RECTANGLE_PAR = 42,      /* CLOSED_RECTANGLE_PAR  */
  YYSYMBOL_OPEN_CURLY_BRACE = 43,          /* OPEN_CURLY_BRACE  */
  YYSYMBOL_CLOSED_CURLY_BRACE = 44,        /* CLOSED_CURLY_BRACE  */
  YYSYMBOL_SEMICOLON = 45,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 46,                       /* DOT  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_DOLLA_SIGN = 48,                /* DOLLA_SIGN  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_global_declarations = 53,       /* global_declarations  */
  YYSYMBOL_class_decl = 54,                /* class_decl  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_class_body = 56,                /* class_body  */
  YYSYMBOL_constructor_decl = 57,          /* constructor_decl  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_field_decl = 59,                /* field_decl  */
  YYSYMBOL_method_decl = 60,               /* method_decl  */
  YYSYMBOL_61_4 = 61,                      /* $@4  */
  YYSYMBOL_func_decl = 62,                 /* func_decl  */
  YYSYMBOL_63_5 = 63,                      /* $@5  */
  YYSYMBOL_func_params = 64,               /* func_params  */
  YYSYMBOL_main_block = 65,                /* main_block  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_statement_block = 67,           /* statement_block  */
  YYSYMBOL_statement_list = 68,            /* statement_list  */
  YYSYMBOL_variable_decl = 69,             /* variable_decl  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_lvalue = 71,                    /* lvalue  */
  YYSYMBOL_assignment = 72,                /* assignment  */
  YYSYMBOL_print_stmt = 73,                /* print_stmt  */
  YYSYMBOL_func_call = 74,                 /* func_call  */
  YYSYMBOL_call_args = 75,                 /* call_args  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_expression_base = 77,           /* expression_base  */
  YYSYMBOL_type_specifier = 78             /* type_specifier  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    84,    90,    91,    92,    93,    98,    97,
     119,   120,   121,   122,   127,   126,   145,   153,   152,   177,
     176,   200,   202,   208,   216,   215,   229,   233,   234,   245,
     252,   265,   266,   267,   271,   273,   274,   275,   300,   301,
     302,   306,   316,   340,   360,   367,   410,   437,   440,   445,
     453,   457,   462,   467,   472,   477,   482,   487,   492,   497,
     502,   503,   504,   505,   506,   507,   508,   510,   514,   521,
     522
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "TYPE",
  "INT_CONST", "BOOL_CONST", "FLOAT_CONST", "STRING_CONST",
  "KEYWORD_CLASS", "KEYWORD_FUNC", "KEYWORD_IF", "KEYWORD_MAIN",
  "KEYWORD_RETURN", "KEYWORD_WHILE", "KEYWORD_FOR", "KEYWORD_PRINT",
  "KEYWORD_DEFINE", "KEYWORD_THEN", "ADD_OP", "SUB_OP", "MUL_OP", "DIV_OP",
  "ASSIGN_OP", "MOD_OP", "EQ_OP", "NEQ_OP", "LT_OP", "GT_OP", "GEQ_OP",
  "LEQ_OP", "OP_AND", "OP_OR", "OP_BIT_AND", "OP_BIT_OR", "OP_BIT_XOR",
  "OP_BIT_LSHIFT", "OP_BIT_RSHIFT", "NOT_OP", "OPEN_ROUND_PAR",
  "CLOSED_ROUND_PAR", "OPEN_RECTANGLE_PAR", "CLOSED_RECTANGLE_PAR",
  "OPEN_CURLY_BRACE", "CLOSED_CURLY_BRACE", "SEMICOLON", "DOT", "COMMA",
  "DOLLA_SIGN", "UMINUS", "$accept", "program", "$@1",
  "global_declarations", "class_decl", "$@2", "class_body",
  "constructor_decl", "$@3", "field_decl", "method_decl", "$@4",
  "func_decl", "$@5", "func_params", "main_block", "$@6",
  "statement_block", "statement_list", "variable_decl", "statement",
  "lvalue", "assignment", "print_stmt", "func_call", "call_args",
  "expression", "expression_base", "type_specifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -39,    17,   -39,   -39,    18,   -39,    23,   -39,   -39,   -39,
     -39,   -24,   -39,   -39,     2,     5,    22,   -39,   -39,   -39,
      49,   -11,     7,    29,    52,   -39,    85,    57,    51,    51,
      51,    99,    67,     5,   -39,   -39,   -39,   -39,   -17,    62,
     -39,    74,   -39,     5,    77,    51,   -39,   -39,   -39,   -39,
      51,    51,    51,    72,   -39,   105,   111,    79,   -24,   -39,
      15,    81,    51,    51,   124,   -39,   -39,   -13,    13,    86,
     -39,    30,   111,   -39,   -39,    89,   -24,    51,    51,    51,
      51,    51,    51,    51,    51,    51,   -39,   -39,   132,    51,
      97,   -39,   101,    59,   -39,   -39,   -39,   -39,   -39,     5,
     138,   -39,    51,   -39,   137,    60,    60,   -39,   -39,    46,
     135,   135,   125,    73,   -39,   104,   106,    51,    82,   155,
     -24,   112,   -39,   111,   141,    99,   -39,    36,   158,   159,
     118,   -39,   161,   -24,   -24,   -39,   -24,   126,   -39,   -39,
     -39,   -39,   -39,     5,    40,   -39,   -24,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     0,    24,     0,     5,     6,     3,
       7,     0,    70,    69,     0,     0,     0,    27,    25,     8,
       0,     0,     0,     0,     0,    29,     0,    41,     0,     0,
       0,     0,     0,     0,    26,    40,    32,    28,     0,     0,
      38,     0,    10,    21,     0,    47,    63,    64,    65,    66,
       0,     0,     0,    61,    62,     0,    50,     0,     0,    41,
       0,     0,     0,     0,     0,    31,    39,     0,     0,     0,
      30,     0,    48,    68,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    35,     0,     0,
       0,    43,    42,     0,     9,    13,    11,    12,    19,     0,
       0,    45,     0,    60,    33,    51,    52,    53,    54,    59,
      57,    58,    55,    56,    42,     0,     0,    47,     0,     0,
       0,     0,    22,    49,     0,     0,    44,     0,    14,     0,
       0,    20,     0,     0,     0,    46,     0,     0,    16,    23,
      34,    36,    15,    21,     0,    17,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,    24,   -39,   -39,   -21,   -39,   144,
     -39,   -20,   -28,   -39,   146,    53,   -14,   -38,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     7,    23,    67,    95,   136,    96,
      97,   146,     8,   120,    68,     9,    11,    18,    22,    10,
      37,    53,    39,    40,    54,    71,    55,    56,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    35,    38,    61,    93,    19,    63,    72,    12,    13,
      27,    60,    73,    74,    75,    57,    58,     3,    28,    17,
      29,    30,    31,    32,    33,    21,    12,    13,    69,    64,
       5,    94,    14,    15,    25,     6,    26,    87,    63,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    90,    91,
      17,    34,    24,    98,    27,   104,    46,    47,    48,    49,
      99,    88,    12,    13,   123,    77,    78,    79,    80,   118,
     101,    50,    42,    82,    83,   115,   135,   102,   119,    72,
     145,    79,    80,   102,   121,   128,    13,    99,    44,    51,
      52,    43,    77,    78,    79,    80,    45,   134,    81,   131,
      82,    83,    59,   129,    84,    60,    62,    65,    77,    78,
      79,    80,   140,   141,    81,   142,    82,    83,    64,    66,
      84,    85,    70,    76,    86,   147,    89,    92,    69,   103,
      77,    78,    79,    80,   100,   114,    81,   116,    82,    83,
     117,   122,    84,    85,    77,    78,    79,    80,   124,   125,
      81,   126,    82,    83,    77,    78,    79,    80,   130,   133,
     132,   -70,   137,   138,   139,   143,    36,   144,    41,     0,
     127
};

static const yytype_int16 yycheck[] =
{
      15,    22,    22,    31,    17,     3,    23,    45,     3,     4,
       3,    31,    50,    51,    52,    29,    30,     0,    11,    43,
      13,    14,    15,    16,    17,     3,     3,     4,    43,    46,
      12,    44,     9,    10,    45,    17,    47,    58,    23,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    62,    63,
      43,    44,     3,    40,     3,    76,     5,     6,     7,     8,
      47,    46,     3,     4,   102,    19,    20,    21,    22,    10,
      40,    20,    43,    27,    28,    89,    40,    47,    93,   117,
      40,    21,    22,    47,    99,     3,     4,    47,     3,    38,
      39,    39,    19,    20,    21,    22,    39,   125,    25,   120,
      27,    28,     3,   118,    31,   125,    39,    45,    19,    20,
      21,    22,   133,   134,    25,   136,    27,    28,    46,    45,
      31,    32,    45,    18,    45,   146,    45,     3,   143,    40,
      19,    20,    21,    22,    48,     3,    25,    40,    27,    28,
      39,     3,    31,    32,    19,    20,    21,    22,    11,    45,
      25,    45,    27,    28,    19,    20,    21,    22,     3,    18,
      48,     3,     3,    45,     3,    39,    22,   143,    22,    -1,
     117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,    53,    12,    17,    54,    62,    65,
      69,    66,     3,     4,     9,    10,    78,    43,    67,     3,
      78,     3,    68,    55,     3,    45,    47,     3,    11,    13,
      14,    15,    16,    17,    44,    67,    69,    70,    71,    72,
      73,    74,    43,    39,     3,    39,     5,     6,     7,     8,
      20,    38,    39,    71,    74,    76,    77,    76,    76,     3,
      71,    72,    39,    23,    46,    45,    45,    56,    64,    78,
      45,    75,    77,    77,    77,    77,    18,    19,    20,    21,
      22,    25,    27,    28,    31,    32,    45,    67,    46,    45,
      76,    76,     3,    17,    44,    57,    59,    60,    40,    47,
      48,    40,    47,    40,    67,    77,    77,    77,    77,    77,
      77,    77,    77,    77,     3,    76,    40,    39,    10,    78,
      63,    78,     3,    77,    11,    45,    45,    75,     3,    78,
       3,    67,    48,    18,    72,    40,    58,     3,    45,     3,
      67,    67,    67,    39,    64,    40,    61,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    53,    53,    53,    53,    55,    54,
      56,    56,    56,    56,    58,    57,    59,    61,    60,    63,
      62,    64,    64,    64,    66,    65,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    73,    74,    74,    75,    75,    75,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     2,     0,     7,
       0,     2,     2,     2,     0,     5,     4,     0,     9,     0,
       9,     0,     3,     5,     0,     3,     3,     0,     2,     4,
       6,     2,     1,     4,     7,     3,     7,     3,     1,     2,
       1,     1,     3,     3,     5,     4,     6,     0,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1
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
  case 2: /* $@1: %empty  */
#line 84 "parser.ypp"
    { 
        currentScope = globalScope = new SymbolTable("Global"); 
        yylineno = 1;
    }
#line 1268 "parser.tab.cpp"
    break;

  case 8: /* $@2: %empty  */
#line 98 "parser.ypp"
    { 
        SymbolTable *class_scope = SymbolTable::class_lookup(*(yyvsp[0].Str) , classes);

        if(class_scope != nullptr)
        {
            std::cout << yylineno << ": " << "Class already defined: " << *(yyvsp[0].Str);
            exit(1);
        }

        currentScope->addVar("class", *(yyvsp[0].Str), "class", nullptr);
        currentScope = new SymbolTable(*(yyvsp[0].Str), currentScope);
        classes[*(yyvsp[0].Str)] = currentScope;
        
        SymbolTable::addClass(*(yyvsp[0].Str), currentScope);
    }
#line 1288 "parser.tab.cpp"
    break;

  case 9: /* class_decl: KEYWORD_DEFINE KEYWORD_CLASS ID $@2 OPEN_CURLY_BRACE class_body CLOSED_CURLY_BRACE  */
#line 114 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1296 "parser.tab.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 127 "parser.ypp"
    {
         if (*(yyvsp[0].Str) != currentScope->get_scope_name()) {
             std::cout << yylineno << ": Constructor name " << *(yyvsp[0].Str) << " must match class name " << currentScope->get_scope_name() << std::endl;
             exit(1);
         }
         
         currentScope->addVar("void", "constructor", "function", nullptr, nullptr); 
         currentScope = new SymbolTable("constructor", currentScope);
    }
#line 1310 "parser.tab.cpp"
    break;

  case 15: /* constructor_decl: KEYWORD_DEFINE KEYWORD_FUNC ID $@3 statement_block  */
#line 137 "parser.ypp"
    {
        currentScope = currentScope->getParent();
        IdInfo* ctor = currentScope->lookup("constructor");
        if (ctor) ctor->body = (yyvsp[0].node);
    }
#line 1320 "parser.tab.cpp"
    break;

  case 16: /* field_decl: KEYWORD_DEFINE type_specifier ID SEMICOLON  */
#line 146 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-2].Str), *(yyvsp[-1].Str), "field", nullptr);
    }
#line 1328 "parser.tab.cpp"
    break;

  case 17: /* $@4: %empty  */
#line 153 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "function", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1342 "parser.tab.cpp"
    break;

  case 18: /* method_decl: KEYWORD_DEFINE KEYWORD_FUNC type_specifier ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@4 statement_block  */
#line 163 "parser.ypp"
    { 
        SymbolTable* funcScope = currentScope;
        currentScope = currentScope->getParent();
        
        IdInfo* func = currentScope->lookup(*(yyvsp[-5].Str));
        if (func) {
             func->body = (yyvsp[0].node);
             func->scope = funcScope;
        }
    }
#line 1357 "parser.tab.cpp"
    break;

  case 19: /* $@5: %empty  */
#line 177 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "function", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1371 "parser.tab.cpp"
    break;

  case 20: /* func_decl: KEYWORD_DEFINE KEYWORD_FUNC type_specifier ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@5 statement_block  */
#line 187 "parser.ypp"
    { 
        SymbolTable* funcScope = currentScope;
        currentScope = currentScope->getParent();
        
        IdInfo* func = currentScope->lookup(*(yyvsp[-5].Str));
        if (func) {
             func->body = (yyvsp[0].node);
             func->scope = funcScope;
        }
    }
#line 1386 "parser.tab.cpp"
    break;

  case 21: /* func_params: %empty  */
#line 200 "parser.ypp"
    { (yyval.Params) = new std::vector<ParamInfo>(); }
#line 1392 "parser.tab.cpp"
    break;

  case 22: /* func_params: type_specifier DOLLA_SIGN ID  */
#line 203 "parser.ypp"
    {
        (yyval.Params) = new std::vector<ParamInfo>();
        (yyval.Params)->push_back(ParamInfo(*(yyvsp[-2].Str), *(yyvsp[0].Str)));
    }
#line 1401 "parser.tab.cpp"
    break;

  case 23: /* func_params: func_params COMMA type_specifier DOLLA_SIGN ID  */
#line 209 "parser.ypp"
    {
        (yyval.Params) = (yyvsp[-4].Params);
        (yyval.Params)->push_back(ParamInfo(*(yyvsp[-2].Str), *(yyvsp[0].Str)));
    }
#line 1410 "parser.tab.cpp"
    break;

  case 24: /* $@6: %empty  */
#line 216 "parser.ypp"
    { 
        currentScope = new SymbolTable("main", currentScope);
    }
#line 1418 "parser.tab.cpp"
    break;

  case 25: /* main_block: KEYWORD_MAIN $@6 statement_block  */
#line 220 "parser.ypp"
    { 
        if ((yyvsp[0].node)) (yyvsp[0].node)->evaluate();
        
        currentScope = currentScope->getParent();
    }
#line 1428 "parser.tab.cpp"
    break;

  case 26: /* statement_block: OPEN_CURLY_BRACE statement_list CLOSED_CURLY_BRACE  */
#line 229 "parser.ypp"
                                                       { (yyval.node) = (yyvsp[-1].node); }
#line 1434 "parser.tab.cpp"
    break;

  case 27: /* statement_list: %empty  */
#line 233 "parser.ypp"
    { (yyval.node) = nullptr; }
#line 1440 "parser.tab.cpp"
    break;

  case 28: /* statement_list: statement_list statement  */
#line 235 "parser.ypp"
    {
        if ((yyvsp[-1].node) == nullptr) (yyval.node) = (yyvsp[0].node);
        else (yyval.node) = new ASTnode((yyvsp[-1].node), Data(TYPE::CHAR, OP::SEQ_), (yyvsp[0].node), new std::string("VOID"));
    }
#line 1449 "parser.tab.cpp"
    break;

  case 29: /* variable_decl: KEYWORD_DEFINE type_specifier ID SEMICOLON  */
#line 246 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-2].Str), *(yyvsp[-1].Str), "variable", nullptr);
        ASTnode* typeNode = new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-2].Str))), nullptr, new std::string("STRING"));
        ASTnode* nameNode = new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-1].Str))), nullptr, new std::string("STRING"));
        (yyval.node) = new ASTnode(typeNode, Data(TYPE::CHAR, OP::DECL_), nameNode, new std::string("VOID"));
    }
#line 1460 "parser.tab.cpp"
    break;

  case 30: /* variable_decl: KEYWORD_DEFINE type_specifier ID COMMA ID SEMICOLON  */
#line 253 "parser.ypp"
    {
         currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "variable", nullptr);
         currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-1].Str), "variable", nullptr);
         
         ASTnode* typeNode = new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-4].Str))), nullptr, new std::string("STRING"));
         ASTnode* name1 = new ASTnode(typeNode, Data(TYPE::CHAR, OP::DECL_), new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-3].Str))), nullptr, new std::string("STRING")), new std::string("VOID"));
         ASTnode* name2 = new ASTnode(typeNode, Data(TYPE::CHAR, OP::DECL_), new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-1].Str))), nullptr, new std::string("STRING")), new std::string("VOID"));
         (yyval.node) = new ASTnode(name1, Data(TYPE::CHAR, OP::SEQ_), name2, new std::string("VOID"));
    }
#line 1474 "parser.tab.cpp"
    break;

  case 31: /* statement: assignment SEMICOLON  */
#line 265 "parser.ypp"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1480 "parser.tab.cpp"
    break;

  case 32: /* statement: variable_decl  */
#line 266 "parser.ypp"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1486 "parser.tab.cpp"
    break;

  case 33: /* statement: KEYWORD_IF expression KEYWORD_THEN statement_block  */
#line 268 "parser.ypp"
    {
         (yyval.node) = nullptr; 
    }
#line 1494 "parser.tab.cpp"
    break;

  case 34: /* statement: KEYWORD_IF expression KEYWORD_THEN statement_block KEYWORD_IF KEYWORD_THEN statement_block  */
#line 271 "parser.ypp"
                                                                                                 { (yyval.node) = nullptr; }
#line 1500 "parser.tab.cpp"
    break;

  case 35: /* statement: KEYWORD_WHILE expression statement_block  */
#line 273 "parser.ypp"
                                               {(yyval.node) = nullptr;}
#line 1506 "parser.tab.cpp"
    break;

  case 36: /* statement: KEYWORD_FOR assignment SEMICOLON expression SEMICOLON assignment statement_block  */
#line 274 "parser.ypp"
                                                                                       {(yyval.node) = nullptr;}
#line 1512 "parser.tab.cpp"
    break;

  case 37: /* statement: KEYWORD_RETURN expression SEMICOLON  */
#line 276 "parser.ypp"
    {
        SymbolTable* scope = currentScope;
        IdInfo* funcInfo = nullptr;
        if (scope->getParent()) {
            funcInfo = scope->getParent()->lookup(scope->get_scope_name());
        }
        
        if (funcInfo && funcInfo->category == "function") {
             std::string retType = funcInfo->return_type;
             std::string exprType = (yyvsp[-1].node)->get_type();
             
             if (retType == "VOID" || retType == "void") {
                 std::cout << yylineno << ": Void function '" << funcInfo->name << "' cannot return a value." << std::endl;
                 exit(1);
             }
             
             if (retType != exprType) {
                  std::cout << yylineno << ": Return type mismatch in function '" << funcInfo->name << "'. Expected " << retType << ", got " << exprType << std::endl;
                  exit(1);
             }
        }
        
        (yyval.node) = new ASTnode((yyvsp[-1].node), Data(TYPE::CHAR, OP::RET_), nullptr, (yyvsp[-1].node)->get_type_ptr());
    }
#line 1541 "parser.tab.cpp"
    break;

  case 38: /* statement: print_stmt  */
#line 300 "parser.ypp"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1547 "parser.tab.cpp"
    break;

  case 39: /* statement: func_call SEMICOLON  */
#line 301 "parser.ypp"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1553 "parser.tab.cpp"
    break;

  case 40: /* statement: statement_block  */
#line 302 "parser.ypp"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1559 "parser.tab.cpp"
    break;

  case 41: /* lvalue: ID  */
#line 307 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[0].Str));
        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[0].Str);
            exit(1);
        }
        (yyval.node) = new ASTnode(nullptr , Data(TYPE::ID_INFO , id_info) , nullptr , new std::string(id_info -> type));
    }
#line 1573 "parser.tab.cpp"
    break;

  case 42: /* lvalue: lvalue DOT ID  */
#line 317 "parser.ypp"
    {
        ASTnode* left = (yyvsp[-2].node);
        std::string type = left->get_type();
        
        SymbolTable *class_scope = SymbolTable::class_lookup(type, classes);
        if (class_scope == nullptr) {
            std::cout << yylineno << ": Type " << type << " is not a class" << std::endl;
            exit(1);
        }
        
        IdInfo *member = class_scope->lookup(*(yyvsp[0].Str));
        if(member == nullptr)
        {
            std::cout << yylineno << ": " << "Class " << type << ' ' << "does not have member: " << *(yyvsp[0].Str);
            exit(1);
        }
        
        ASTnode* memberNode = new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[0].Str))), nullptr, new std::string("STRING"));
        (yyval.node) = new ASTnode(left, Data(TYPE::CHAR, OP::DOT_), memberNode, new std::string(member->type));
    }
#line 1598 "parser.tab.cpp"
    break;

  case 43: /* assignment: lvalue ASSIGN_OP expression  */
#line 341 "parser.ypp"
    {
        std::string ltype = (yyvsp[-2].node)->get_type();
        std::string rtype = (yyvsp[0].node)->get_type();
        
        
        if (ltype != rtype) {
             if(!(ltype == "BOOL" && rtype == "INT")) {
                 if (rtype != "VOID") {
                    std::cout << yylineno << ": Type mismatch in assignment: '" << ltype << "' = '" << rtype << "'" << std::endl;
                    exit(1);
                 }
             }
        }
        
        (yyval.node) = new ASTnode((yyvsp[-2].node), Data(TYPE::CHAR, ASSIGN_), (yyvsp[0].node), new std::string(ltype));
    }
#line 1619 "parser.tab.cpp"
    break;

  case 44: /* print_stmt: KEYWORD_PRINT OPEN_ROUND_PAR expression CLOSED_ROUND_PAR SEMICOLON  */
#line 361 "parser.ypp"
    {
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR , PRINT) , nullptr , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1627 "parser.tab.cpp"
    break;

  case 45: /* func_call: ID OPEN_ROUND_PAR call_args CLOSED_ROUND_PAR  */
#line 368 "parser.ypp"
    { 
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-3].Str));
        bool is_constructor = false;
        
        if (id_info && id_info->category == "class") {
            is_constructor = true;
        } else if (id_info == nullptr) {
            if (SymbolTable::getClass(*(yyvsp[-3].Str))) is_constructor = true;
            else {
                 std::cout << yylineno << ": " << "Function or Class '" << *(yyvsp[-3].Str) << "' does not exist";
                 exit(1);
            }
        }
        
        if(is_constructor)
        {
             SymbolTable* classScope = SymbolTable::getClass(*(yyvsp[-3].Str));
             if (!classScope) {
                  std::cout << yylineno << ": " << "Class '" << *(yyvsp[-3].Str) << "' not found";
                  exit(1);
             }
             ASTnode* classNameNode = new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-3].Str))), nullptr, new std::string("STRING"));
             (yyval.node) = new ASTnode(classNameNode, Data(TYPE::CHAR, OP::NEW_), nullptr, new std::string(*(yyvsp[-3].Str)));
        } else {
             std::vector<std::string> argTypes;
             for (auto arg : *(yyvsp[-1].Args)) {
                 argTypes.push_back(arg->get_type());
             }
             check_func_parameters(*(yyvsp[-3].Str) , id_info -> param , argTypes);
             
             ASTnode* argsTree = nullptr;
             if ((yyvsp[-1].Args)->size() > 0) {
                 for (int i = (yyvsp[-1].Args)->size() - 1; i >= 0; --i) {
                     ASTnode* arg = (*(yyvsp[-1].Args))[i];
                     argsTree = new ASTnode(arg, Data(TYPE::CHAR, OP::SEQ_), argsTree, new std::string("ARGS"));
                 }
             }
             
             ASTnode* funcNode = new ASTnode(nullptr, Data(TYPE::ID_INFO, id_info), nullptr, new std::string(id_info->type));
             (yyval.node) = new ASTnode(funcNode, Data(TYPE::CHAR, OP::CALL_), argsTree, new std::string(id_info->return_type));
        }
    }
#line 1674 "parser.tab.cpp"
    break;

  case 46: /* func_call: lvalue DOT ID OPEN_ROUND_PAR call_args CLOSED_ROUND_PAR  */
#line 411 "parser.ypp"
    {
        ASTnode* obj = (yyvsp[-5].node);
        std::string objType = obj->get_type();
        SymbolTable* cls = SymbolTable::getClass(objType);
        IdInfo* method = cls->lookup(*(yyvsp[-3].Str));
        
        std::vector<std::string> argTypes;
        for (auto arg : *(yyvsp[-1].Args)) argTypes.push_back(arg->get_type());
        check_func_parameters(*(yyvsp[-3].Str), method->param, argTypes);
        
        ASTnode* memberNode = new ASTnode(nullptr, Data(TYPE::STRING, new std::string(*(yyvsp[-3].Str))), nullptr, new std::string("STRING"));
        ASTnode* dotNode = new ASTnode(obj, Data(TYPE::CHAR, OP::DOT_), memberNode, new std::string(method->type));
        
        ASTnode* argsTree = nullptr;
         if ((yyvsp[-1].Args)->size() > 0) {
             for (int i = (yyvsp[-1].Args)->size() - 1; i >= 0; --i) {
                 ASTnode* arg = (*(yyvsp[-1].Args))[i];
                 argsTree = new ASTnode(arg, Data(TYPE::CHAR, OP::SEQ_), argsTree, new std::string("ARGS"));
             }
         }
         
        (yyval.node) = new ASTnode(dotNode, Data(TYPE::CHAR, OP::CALL_), argsTree, new std::string(method->return_type));
    }
#line 1702 "parser.tab.cpp"
    break;

  case 47: /* call_args: %empty  */
#line 437 "parser.ypp"
    {
        (yyval.Args) = new std::vector<ASTnode*>();
    }
#line 1710 "parser.tab.cpp"
    break;

  case 48: /* call_args: expression_base  */
#line 441 "parser.ypp"
    {
        (yyval.Args) = new std::vector<ASTnode*>();
        (yyval.Args)->push_back((yyvsp[0].node));
    }
#line 1719 "parser.tab.cpp"
    break;

  case 49: /* call_args: call_args COMMA expression_base  */
#line 446 "parser.ypp"
    {
        (yyval.Args) = (yyvsp[-2].Args);
        (yyval.Args)->push_back((yyvsp[0].node));
    }
#line 1728 "parser.tab.cpp"
    break;

  case 50: /* expression: expression_base  */
#line 453 "parser.ypp"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1734 "parser.tab.cpp"
    break;

  case 51: /* expression_base: expression_base ADD_OP expression_base  */
#line 458 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR , OP::ADD_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1743 "parser.tab.cpp"
    break;

  case 52: /* expression_base: expression_base SUB_OP expression_base  */
#line 463 "parser.ypp"
    {
         check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::SUB_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1752 "parser.tab.cpp"
    break;

  case 53: /* expression_base: expression_base MUL_OP expression_base  */
#line 468 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::MUL_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1761 "parser.tab.cpp"
    break;

  case 54: /* expression_base: expression_base DIV_OP expression_base  */
#line 473 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::DIV_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1770 "parser.tab.cpp"
    break;

  case 55: /* expression_base: expression_base OP_AND expression_base  */
#line 478 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_AND) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1779 "parser.tab.cpp"
    break;

  case 56: /* expression_base: expression_base OP_OR expression_base  */
#line 483 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_OR) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1788 "parser.tab.cpp"
    break;

  case 57: /* expression_base: expression_base LT_OP expression_base  */
#line 488 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::LT_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1797 "parser.tab.cpp"
    break;

  case 58: /* expression_base: expression_base GT_OP expression_base  */
#line 493 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::GT_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1806 "parser.tab.cpp"
    break;

  case 59: /* expression_base: expression_base EQ_OP expression_base  */
#line 498 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::EQ_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1815 "parser.tab.cpp"
    break;

  case 60: /* expression_base: OPEN_ROUND_PAR expression_base CLOSED_ROUND_PAR  */
#line 502 "parser.ypp"
                                                      {(yyval.node) = (yyvsp[-1].node);}
#line 1821 "parser.tab.cpp"
    break;

  case 61: /* expression_base: lvalue  */
#line 503 "parser.ypp"
             { (yyval.node) = (yyvsp[0].node); }
#line 1827 "parser.tab.cpp"
    break;

  case 62: /* expression_base: func_call  */
#line 504 "parser.ypp"
                { (yyval.node) = (yyvsp[0].node); }
#line 1833 "parser.tab.cpp"
    break;

  case 63: /* expression_base: INT_CONST  */
#line 505 "parser.ypp"
                {(yyval.node) = new ASTnode(nullptr , Data(TYPE::INT , (yyvsp[0].val_int)) , nullptr , new std::string("INT"));}
#line 1839 "parser.tab.cpp"
    break;

  case 64: /* expression_base: BOOL_CONST  */
#line 506 "parser.ypp"
                 {(yyval.node) = new ASTnode(nullptr , Data(TYPE::BOOL , (bool)(yyvsp[0].val_int)) , nullptr , new std::string("BOOL"));}
#line 1845 "parser.tab.cpp"
    break;

  case 65: /* expression_base: FLOAT_CONST  */
#line 507 "parser.ypp"
                  {(yyval.node) = new ASTnode(nullptr , Data(TYPE::FLOAT , (yyvsp[0].val_float)) , nullptr , new std::string("FLOAT"));}
#line 1851 "parser.tab.cpp"
    break;

  case 66: /* expression_base: STRING_CONST  */
#line 508 "parser.ypp"
                   {(yyval.node) = new ASTnode(nullptr , Data(TYPE::STRING , (yyvsp[0].Str)) , nullptr , new std::string("STRING"));}
#line 1857 "parser.tab.cpp"
    break;

  case 67: /* expression_base: NOT_OP expression_base  */
#line 511 "parser.ypp"
    {
        (yyval.node) = new ASTnode((yyvsp[0].node) , Data(TYPE::CHAR, OP::NOT_) , nullptr , new std::string("BOOL"));
    }
#line 1865 "parser.tab.cpp"
    break;

  case 68: /* expression_base: SUB_OP expression_base  */
#line 515 "parser.ypp"
    {
         (yyval.node) = new ASTnode((yyvsp[0].node) , Data(TYPE::CHAR, OP::UMINUS_) , nullptr , (yyvsp[0].node)->get_type_ptr());
    }
#line 1873 "parser.tab.cpp"
    break;

  case 69: /* type_specifier: TYPE  */
#line 521 "parser.ypp"
         { (yyval.Str) = (yyvsp[0].Str); }
#line 1879 "parser.tab.cpp"
    break;

  case 70: /* type_specifier: ID  */
#line 523 "parser.ypp"
    {
        SymbolTable *class_scope = SymbolTable::class_lookup(*(yyvsp[0].Str) , classes);
        if(class_scope == nullptr && *(yyvsp[0].Str) != "INT" && *(yyvsp[0].Str) != "FLOAT" && *(yyvsp[0].Str) != "STRING" && *(yyvsp[0].Str) != "BOOL" && *(yyvsp[0].Str) != "VOID" && *(yyvsp[0].Str) != "STR")
        {
             
            std::cout << yylineno << ": " << "Invalid type declared: " << *(yyvsp[0].Str) << '\n';
            exit(1);
        } 
        if (*(yyvsp[0].Str) == "STR") (yyval.Str) = new std::string("STRING");
        else (yyval.Str) = (yyvsp[0].Str); 
    }
#line 1895 "parser.tab.cpp"
    break;


#line 1899 "parser.tab.cpp"

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

#line 536 "parser.ypp"


extern char* yytext;
void yyerror(const char *s) {
    std::cerr << "Syntax Error at line " << yylineno << ": " << s << " at token '" << yytext << "'" << std::endl;
    exit(1);
}

int main() {
    if (yyparse() == 0) {
        std::cout << "Parsing successful!" << std::endl;
    }
    return 0;
}
