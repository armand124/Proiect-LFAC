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
    void yyerror(const char *s);

    SymbolTable* currentScope = nullptr , *globalScope = nullptr;
    std::map < std::string , SymbolTable* > classes;
   

#line 92 "parser.tab.cpp"

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
  YYSYMBOL_KEYWORD_CONSTR = 19,            /* KEYWORD_CONSTR  */
  YYSYMBOL_ADD_OP = 20,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 21,                    /* SUB_OP  */
  YYSYMBOL_MUL_OP = 22,                    /* MUL_OP  */
  YYSYMBOL_DIV_OP = 23,                    /* DIV_OP  */
  YYSYMBOL_ASSIGN_OP = 24,                 /* ASSIGN_OP  */
  YYSYMBOL_MOD_OP = 25,                    /* MOD_OP  */
  YYSYMBOL_EQ_OP = 26,                     /* EQ_OP  */
  YYSYMBOL_NEQ_OP = 27,                    /* NEQ_OP  */
  YYSYMBOL_LT_OP = 28,                     /* LT_OP  */
  YYSYMBOL_GT_OP = 29,                     /* GT_OP  */
  YYSYMBOL_GEQ_OP = 30,                    /* GEQ_OP  */
  YYSYMBOL_LEQ_OP = 31,                    /* LEQ_OP  */
  YYSYMBOL_OP_AND = 32,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 33,                     /* OP_OR  */
  YYSYMBOL_OP_BIT_AND = 34,                /* OP_BIT_AND  */
  YYSYMBOL_OP_BIT_OR = 35,                 /* OP_BIT_OR  */
  YYSYMBOL_OP_BIT_XOR = 36,                /* OP_BIT_XOR  */
  YYSYMBOL_OP_BIT_LSHIFT = 37,             /* OP_BIT_LSHIFT  */
  YYSYMBOL_OP_BIT_RSHIFT = 38,             /* OP_BIT_RSHIFT  */
  YYSYMBOL_NOT_OP = 39,                    /* NOT_OP  */
  YYSYMBOL_OPEN_ROUND_PAR = 40,            /* OPEN_ROUND_PAR  */
  YYSYMBOL_CLOSED_ROUND_PAR = 41,          /* CLOSED_ROUND_PAR  */
  YYSYMBOL_OPEN_RECTANGLE_PAR = 42,        /* OPEN_RECTANGLE_PAR  */
  YYSYMBOL_CLOSED_RECTANGLE_PAR = 43,      /* CLOSED_RECTANGLE_PAR  */
  YYSYMBOL_OPEN_CURLY_BRACE = 44,          /* OPEN_CURLY_BRACE  */
  YYSYMBOL_CLOSED_CURLY_BRACE = 45,        /* CLOSED_CURLY_BRACE  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_DOLLA_SIGN = 49,                /* DOLLA_SIGN  */
  YYSYMBOL_UMINUS = 50,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_global_declarations = 54,       /* global_declarations  */
  YYSYMBOL_class_decl = 55,                /* class_decl  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_class_body = 57,                /* class_body  */
  YYSYMBOL_constructor_decl = 58,          /* constructor_decl  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_field_decl = 60,                /* field_decl  */
  YYSYMBOL_method_decl = 61,               /* method_decl  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_func_decl = 63,                 /* func_decl  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_func_params = 65,               /* func_params  */
  YYSYMBOL_main_block = 66,                /* main_block  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_function_body = 68,             /* function_body  */
  YYSYMBOL_function_item_list = 69,        /* function_item_list  */
  YYSYMBOL_function_item = 70,             /* function_item  */
  YYSYMBOL_statement_block = 71,           /* statement_block  */
  YYSYMBOL_statement_list = 72,            /* statement_list  */
  YYSYMBOL_variable_decl = 73,             /* variable_decl  */
  YYSYMBOL_statement = 74,                 /* statement  */
  YYSYMBOL_assignment = 75,                /* assignment  */
  YYSYMBOL_print_stmt = 76,                /* print_stmt  */
  YYSYMBOL_func_call = 77,                 /* func_call  */
  YYSYMBOL_call_args = 78,                 /* call_args  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_type_specifier = 80             /* type_specifier  */
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
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    81,    88,    89,    90,    91,    96,    95,
     115,   117,   118,   119,   124,   123,   144,   152,   151,   169,
     168,   185,   187,   193,   201,   200,   212,   215,   216,   220,
     221,   225,   228,   229,   235,   244,   253,   254,   255,   256,
     257,   271,   272,   276,   298,   342,   349,   377,   420,   425,
     431,   440,   445,   450,   455,   460,   465,   470,   475,   480,
     485,   490,   495,   500,   505,   510,   515,   520,   525,   530,
     531,   543,   561,   562,   563,   564,   565,   566,   602,   611,
     623,   624
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
  "KEYWORD_DEFINE", "KEYWORD_THEN", "KEYWORD_CONSTR", "ADD_OP", "SUB_OP",
  "MUL_OP", "DIV_OP", "ASSIGN_OP", "MOD_OP", "EQ_OP", "NEQ_OP", "LT_OP",
  "GT_OP", "GEQ_OP", "LEQ_OP", "OP_AND", "OP_OR", "OP_BIT_AND",
  "OP_BIT_OR", "OP_BIT_XOR", "OP_BIT_LSHIFT", "OP_BIT_RSHIFT", "NOT_OP",
  "OPEN_ROUND_PAR", "CLOSED_ROUND_PAR", "OPEN_RECTANGLE_PAR",
  "CLOSED_RECTANGLE_PAR", "OPEN_CURLY_BRACE", "CLOSED_CURLY_BRACE",
  "SEMICOLON", "DOT", "COMMA", "DOLLA_SIGN", "UMINUS", "$accept",
  "program", "$@1", "global_declarations", "class_decl", "$@2",
  "class_body", "constructor_decl", "$@3", "field_decl", "method_decl",
  "$@4", "func_decl", "$@5", "func_params", "main_block", "$@6",
  "function_body", "function_item_list", "function_item",
  "statement_block", "statement_list", "variable_decl", "statement",
  "assignment", "print_stmt", "func_call", "call_args", "expression",
  "type_specifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -97,     5,   -97,   -97,    26,   -97,    45,   -97,   -97,   -97,
     -97,    -5,   -97,   -97,    14,    23,    58,   -97,   -97,   -97,
      83,    43,    89,    46,    61,   -97,   -18,     7,     7,     7,
     103,    67,   -97,   -97,   -97,    62,   -97,    63,   -97,    23,
       7,     7,   107,   -36,   -97,   -97,   -97,   -97,     7,     7,
       7,   123,   -97,   238,   130,   174,   -17,    85,     7,   -97,
     -97,    -1,   -23,    87,   257,    10,   257,   -16,   129,   -97,
     -97,   194,   -97,    -5,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   -97,   -97,   134,     7,   216,   120,   -97,   -97,
     -97,   -97,   -97,    23,   135,   -97,     7,     7,     7,   100,
     -97,   -97,    71,    71,   -97,   -97,   -97,   352,   352,   371,
     371,   371,   371,   295,   276,   333,   314,    91,   122,   122,
     124,   152,   125,    23,   143,   146,   126,   142,   -97,   257,
     257,    11,   103,   -97,   166,   153,   167,   -97,   -97,   189,
     -97,    -5,   193,    23,   -97,    20,   -97,   -97,    23,    12,
      23,   -97,   -97,   -97,   -97,    47,   -97,   -97,   126,   126,
     -97,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     0,    24,     0,     5,     6,     3,
       7,     0,    81,    80,     0,     0,     0,    32,    25,     8,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    31,    42,    33,     0,    40,     0,    10,    21,
       0,    48,     0,    70,    72,    73,    74,    75,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,    35,
      41,     0,     0,     0,    43,     0,    49,     0,     0,    79,
      78,     0,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    37,     0,     0,     0,     0,     9,    13,
      11,    12,    19,     0,     0,    46,     0,     0,    48,    77,
      69,    36,    51,    52,    53,    54,    62,    68,    67,    63,
      64,    66,    65,    55,    56,    59,    57,    58,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    50,
      44,     0,     0,    45,     0,     0,     0,    27,    20,     0,
      47,     0,     0,    21,    16,     0,    23,    38,    21,     0,
       0,    26,    28,    29,    30,     0,    14,    17,     0,     0,
      15,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -96,   -97,   -97,   -84,   -97,   -97,
     -10,   -97,    79,   145,   -27,   -97,   -20,   132,    -8,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     7,    23,    61,    99,   168,   100,
     101,   169,     8,   136,    62,     9,    11,   148,   155,   162,
      33,    22,    10,    34,    35,    36,    52,    65,    66,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    18,    37,    57,    41,     3,    40,    40,   107,    20,
      43,    68,    44,    45,    46,    47,    97,    19,   102,    53,
      54,    55,    41,    26,   108,   103,    12,    13,    48,    42,
      94,    27,    64,    28,    29,    30,    31,   160,     5,    17,
      69,    70,    71,     6,    98,    93,    49,    50,    12,    13,
      96,   105,   150,   166,    14,    15,    51,   159,   106,   106,
     103,    21,   165,   111,    17,   161,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   170,   171,    24,   131,   167,    25,
      38,   135,    26,    76,    77,   103,    78,   137,   139,   140,
      27,    39,    28,    29,    30,    31,    56,    58,    59,    60,
      67,    74,    75,    76,    77,   151,    78,    79,    80,    81,
      82,    83,    84,    12,    13,    87,    72,   144,    90,    91,
     133,    95,   109,    17,    32,    37,   104,   130,   138,   134,
     108,   157,    74,    75,    76,    77,   145,    78,   107,   146,
      74,    75,    76,    77,    16,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   152,
     147,   143,    74,    75,    76,    77,    92,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   149,   156,   153,    74,    75,    76,    77,   142,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   154,    74,    75,    76,    77,    17,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   158,   163,   110,    74,    75,    76,    77,
     141,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    73,   132,    74,    75,
      76,    77,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    74,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    74,    75,    76,    77,
     164,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      87,    88,    89,    90,    91,    74,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,     0,     0,    87,
      88,    89,    90,    91,    74,    75,    76,    77,     0,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    87,     0,
      89,    90,    91,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      90,    91,    74,    75,    76,    77,     0,    78,     0,     0,
      81,    82,    83,    84,     0,     0,     0,     0,     0,    90,
      91,    74,    75,    76,    77,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91
};

static const yytype_int16 yycheck[] =
{
       6,    11,    22,    30,    40,     0,    24,    24,    24,    15,
       3,    47,     5,     6,     7,     8,    17,     3,    41,    27,
      28,    29,    40,     3,    40,    48,     3,     4,    21,    47,
      47,    11,    40,    13,    14,    15,    16,    17,    12,    44,
      48,    49,    50,    17,    45,    55,    39,    40,     3,     4,
      58,    41,    41,    41,     9,    10,    49,   153,    48,    48,
      48,     3,   158,    73,    44,    45,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   168,   169,     3,    95,    41,    46,
      44,    97,     3,    22,    23,    48,    25,   103,   106,   107,
      11,    40,    13,    14,    15,    16,     3,    40,    46,    46,
       3,    20,    21,    22,    23,   142,    25,    26,    27,    28,
      29,    30,    31,     3,     4,    34,     3,   133,    37,    38,
      10,    46,     3,    44,    45,   155,    49,     3,     3,    19,
      40,   151,    20,    21,    22,    23,     3,    25,    24,     3,
      20,    21,    22,    23,   160,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     3,
      44,    46,    20,    21,    22,    23,    46,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    49,     3,    40,    20,    21,    22,    23,    46,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    46,    20,    21,    22,    23,    44,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    40,   155,    41,    20,    21,    22,    23,
     108,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    18,    41,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    20,    21,    22,    23,
     155,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    37,    38,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    34,
      35,    36,    37,    38,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    -1,
      36,    37,    38,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    20,    21,    22,    23,    -1,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    53,     0,    54,    12,    17,    55,    63,    66,
      73,    67,     3,     4,     9,    10,    80,    44,    71,     3,
      80,     3,    72,    56,     3,    46,     3,    11,    13,    14,
      15,    16,    45,    71,    74,    75,    76,    77,    44,    40,
      24,    40,    47,     3,     5,     6,     7,     8,    21,    39,
      40,    49,    77,    79,    79,    79,     3,    75,    40,    46,
      46,    57,    65,    80,    79,    78,    79,     3,    47,    79,
      79,    79,     3,    18,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    46,    71,    47,    46,    79,    17,    45,    58,
      60,    61,    41,    48,    49,    41,    48,    24,    40,     3,
      41,    71,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
       3,    79,    41,    10,    19,    80,    64,    80,     3,    79,
      79,    78,    46,    46,    80,     3,     3,    44,    68,    49,
      41,    75,     3,    40,    46,    69,     3,    71,    40,    65,
      17,    45,    70,    73,    74,    65,    41,    41,    59,    62,
      68,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    53,    52,    54,    54,    54,    54,    56,    55,
      57,    57,    57,    57,    59,    58,    60,    62,    61,    64,
      63,    65,    65,    65,    67,    66,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     2,     0,     7,
       0,     2,     2,     2,     0,     8,     4,     0,     9,     0,
       9,     0,     3,     5,     0,     3,     3,     0,     2,     1,
       1,     3,     0,     2,     4,     2,     4,     3,     7,     3,
       1,     2,     1,     3,     5,     5,     4,     6,     0,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     3,     2,     2,
       1,     1
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
#line 81 "parser.ypp"
    { 
        currentScope = globalScope = new SymbolTable("Global"); 
        //Data data(TYPE::INT , 10);
        yylineno = 1;
    }
#line 1329 "parser.tab.cpp"
    break;

  case 8: /* $@2: %empty  */
#line 96 "parser.ypp"
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
    }
#line 1347 "parser.tab.cpp"
    break;

  case 9: /* class_decl: KEYWORD_DEFINE KEYWORD_CLASS ID $@2 OPEN_CURLY_BRACE class_body CLOSED_CURLY_BRACE  */
#line 110 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1355 "parser.tab.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 124 "parser.ypp"
    {
        if (*(yyvsp[-3].Str) != currentScope->get_scope_name()) {
             std::cout << yylineno << ": " << "Constructor name must match class name: " << *(yyvsp[-3].Str);
             exit(1);
        }
        currentScope->addVar("VOID", *(yyvsp[-3].Str), "constructor", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1373 "parser.tab.cpp"
    break;

  case 15: /* constructor_decl: KEYWORD_DEFINE KEYWORD_CONSTR ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@3 function_body  */
#line 138 "parser.ypp"
    {
        currentScope = currentScope->getParent();
    }
#line 1381 "parser.tab.cpp"
    break;

  case 16: /* field_decl: KEYWORD_DEFINE type_specifier ID SEMICOLON  */
#line 145 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-2].Str), *(yyvsp[-1].Str), "field", nullptr);
    }
#line 1389 "parser.tab.cpp"
    break;

  case 17: /* $@4: %empty  */
#line 152 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "function", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1403 "parser.tab.cpp"
    break;

  case 18: /* method_decl: KEYWORD_DEFINE KEYWORD_FUNC type_specifier ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@4 function_body  */
#line 162 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1411 "parser.tab.cpp"
    break;

  case 19: /* $@5: %empty  */
#line 169 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "function", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1425 "parser.tab.cpp"
    break;

  case 20: /* func_decl: KEYWORD_DEFINE KEYWORD_FUNC type_specifier ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@5 function_body  */
#line 179 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1433 "parser.tab.cpp"
    break;

  case 21: /* func_params: %empty  */
#line 185 "parser.ypp"
    { (yyval.Params) = new std::vector<ParamInfo>(); }
#line 1439 "parser.tab.cpp"
    break;

  case 22: /* func_params: type_specifier DOLLA_SIGN ID  */
#line 188 "parser.ypp"
    {
        (yyval.Params) = new std::vector<ParamInfo>();
        (yyval.Params)->push_back(ParamInfo(*(yyvsp[-2].Str), *(yyvsp[0].Str)));
    }
#line 1448 "parser.tab.cpp"
    break;

  case 23: /* func_params: func_params COMMA type_specifier DOLLA_SIGN ID  */
#line 194 "parser.ypp"
    {
        (yyval.Params) = (yyvsp[-4].Params);
        (yyval.Params)->push_back(ParamInfo(*(yyvsp[-2].Str), *(yyvsp[0].Str)));
    }
#line 1457 "parser.tab.cpp"
    break;

  case 24: /* $@6: %empty  */
#line 201 "parser.ypp"
    { 
        currentScope = new SymbolTable("main", currentScope);
    }
#line 1465 "parser.tab.cpp"
    break;

  case 25: /* main_block: KEYWORD_MAIN $@6 statement_block  */
#line 205 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1473 "parser.tab.cpp"
    break;

  case 34: /* variable_decl: KEYWORD_DEFINE type_specifier ID SEMICOLON  */
#line 236 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-2].Str), *(yyvsp[-1].Str), "variable", nullptr);
    }
#line 1481 "parser.tab.cpp"
    break;

  case 35: /* statement: assignment SEMICOLON  */
#line 245 "parser.ypp"
    {
        if(currentScope -> get_scope_name() == "main")
        {
            (yyvsp[-1]. node ) -> evaluate();
        }

        (yyval. node ) = (yyvsp[-1]. node );
    }
#line 1494 "parser.tab.cpp"
    break;

  case 36: /* statement: KEYWORD_IF expression KEYWORD_THEN statement_block  */
#line 253 "parser.ypp"
                                                         {(yyval. node ) = nullptr;}
#line 1500 "parser.tab.cpp"
    break;

  case 37: /* statement: KEYWORD_WHILE expression statement_block  */
#line 254 "parser.ypp"
                                               {(yyval. node ) = nullptr;}
#line 1506 "parser.tab.cpp"
    break;

  case 38: /* statement: KEYWORD_FOR assignment SEMICOLON expression SEMICOLON assignment statement_block  */
#line 255 "parser.ypp"
                                                                                       {(yyval. node ) = nullptr;}
#line 1512 "parser.tab.cpp"
    break;

  case 39: /* statement: KEYWORD_RETURN expression SEMICOLON  */
#line 256 "parser.ypp"
                                          {(yyval. node ) = nullptr;}
#line 1518 "parser.tab.cpp"
    break;

  case 40: /* statement: print_stmt  */
#line 258 "parser.ypp"
    {
        if(currentScope -> get_scope_name() == "main")
        {
            Data print_result = (yyvsp[0]. node ) -> evaluate();

            if(print_result.type == INT) std::cout << print_result.get_int() << '\n';
            if(print_result.type == FLOAT) std::cout << print_result.get_float() << '\n';
            if(print_result.type == STRING) std::cout << *print_result.get_string() << '\n';
            if(print_result.type == BOOL) std::cout << print_result.get_bool() << '\n';
        }
        
        (yyval. node ) = (yyvsp[0]. node );
    }
#line 1536 "parser.tab.cpp"
    break;

  case 41: /* statement: func_call SEMICOLON  */
#line 271 "parser.ypp"
                          {(yyval. node ) = nullptr;}
#line 1542 "parser.tab.cpp"
    break;

  case 42: /* statement: statement_block  */
#line 272 "parser.ypp"
                      {(yyval. node ) = nullptr;}
#line 1548 "parser.tab.cpp"
    break;

  case 43: /* assignment: ID ASSIGN_OP expression  */
#line 277 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-2].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[-2].Str);
            exit(1);
        }

        if(id_info -> type != (yyvsp[0].node) -> get_type())
        {
            if(!(id_info -> type == "BOOL" && (yyvsp[0].node) -> get_type() == "INT"))
            {
                std::cout << yylineno << ": " << "Casting not allowed between " << id_info -> type << " and " << (yyvsp[0].node) -> get_type();
                exit(1);
            }
        }

        ASTnode *id_astnode = new ASTnode(nullptr , Data(TYPE::ID_INFO , id_info) , nullptr , (yyvsp[0].node) -> get_type_ptr());
        (yyval. node ) = new ASTnode(id_astnode , Data(TYPE::CHAR , ASSIGN_) , (yyvsp[0].node) , (yyvsp[0].node) -> get_type_ptr());
    }
#line 1574 "parser.tab.cpp"
    break;

  case 44: /* assignment: ID DOT ID ASSIGN_OP expression  */
#line 299 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-4].Str));
        
        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[-4].Str);
            exit(1);
        }

        IdInfo *id_class = globalScope -> lookup(id_info -> type);

        if(id_class == nullptr)
        {
            std::cout << yylineno << ": " << "Type not a class: " << id_info -> type;
            exit(1);
        }
        else if(id_class -> category != "class")
        {
            std::cout << yylineno << ": " << "Type not a class: " << id_info -> type;
            exit(1);
        }

        SymbolTable *class_scope = SymbolTable::class_lookup(id_info -> type , classes);
        IdInfo *submember = class_scope -> lookup(*(yyvsp[-2].Str));

        if(submember == nullptr)
        {
            std::cout << yylineno << ": " << "Class " << id_info -> type << ' ' << "does not have member: " << *(yyvsp[-2].Str);
            exit(1);
        }

        if(submember -> type != (yyvsp[0].node) -> get_type())
        {
            std::cout << yylineno << ": " << "Casting not allowed between " << submember -> type << " and " << (yyvsp[0].node) -> get_type();
            exit(1);
        }

        ASTnode *id_astnode = new ASTnode(nullptr , Data(TYPE::ID_INFO , submember) , nullptr , (yyvsp[0].node) -> get_type_ptr());
        (yyval. node ) = new ASTnode(id_astnode , Data(TYPE::CHAR , ASSIGN_) , (yyvsp[0].node) , (yyvsp[0].node) -> get_type_ptr());
    }
#line 1619 "parser.tab.cpp"
    break;

  case 45: /* print_stmt: KEYWORD_PRINT OPEN_ROUND_PAR expression CLOSED_ROUND_PAR SEMICOLON  */
#line 343 "parser.ypp"
    {
        (yyval. node ) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR , PRINT) , nullptr , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1627 "parser.tab.cpp"
    break;

  case 46: /* func_call: ID OPEN_ROUND_PAR call_args CLOSED_ROUND_PAR  */
#line 350 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-3].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Function: " << *(yyvsp[-3].Str) << " does not exist";
            exit(1);
        }

        if (id_info->category == "class") {
             SymbolTable *class_scope = SymbolTable::class_lookup(*(yyvsp[-3].Str), classes);
             IdInfo *constr = class_scope->lookup(*(yyvsp[-3].Str));
             
             if (constr != nullptr && constr->category == "constructor") {
                  check_func_parameters(*(yyvsp[-3].Str), constr->param, *(yyvsp[-1]. params_type ));
             } else {
                  if ((yyvsp[-1]. params_type )->size() > 0) {
                       std::cout << yylineno << ": " << "No matching constructor for class " << *(yyvsp[-3].Str);
                       exit(1);
                  }
             }
             (yyval. node ) = new ASTnode(nullptr, Data(TYPE::INT, 0), nullptr, new std::string(*(yyvsp[-3].Str)));
        } else {
             check_func_parameters(*(yyvsp[-3].Str) , id_info -> param , *(yyvsp[-1]. params_type ));
             (yyval. node ) = new ASTnode(nullptr, Data(TYPE::INT, 0), nullptr, new std::string(id_info->return_type));
        }
    }
#line 1659 "parser.tab.cpp"
    break;

  case 47: /* func_call: ID DOT ID OPEN_ROUND_PAR call_args CLOSED_ROUND_PAR  */
#line 378 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-5].Str));
        
        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[-5].Str);
            exit(1);
        }

        IdInfo *id_class = globalScope -> lookup(id_info -> type);

        if(id_class == nullptr)
        {
            std::cout << yylineno << ": " << "Type not a class: " << id_info -> type;
            exit(1);
        }
        else if(id_class -> category != "class")
        {
            std::cout << yylineno << ": " << "Type not a class: " << id_info -> type;
            exit(1);
        }

        SymbolTable *class_scope = SymbolTable::class_lookup(id_info -> type , classes);
        IdInfo *submember = class_scope -> lookup(*(yyvsp[-3].Str));

        if(submember == nullptr)
        {
            std::cout << yylineno << ": " << "Class " << id_info -> type << ' ' << "does not have member: " << *(yyvsp[-3].Str);
            exit(1);
        }
        else if(submember -> category != "function")
        {
            std::cout << yylineno << ": " << "Class " << id_info -> type << ' ' << "does not have function called: " << *(yyvsp[-3].Str);
        }


        check_func_parameters(*(yyvsp[-3].Str) , submember -> param , *(yyvsp[-1]. params_type ));
        (yyval. node ) = new ASTnode(nullptr, Data(TYPE::INT, 0), nullptr, new std::string(submember->return_type));
    }
#line 1703 "parser.tab.cpp"
    break;

  case 48: /* call_args: %empty  */
#line 420 "parser.ypp"
    {
        std::vector < std::string > *result = new std::vector < std::string >;
        (yyval. params_type ) = result;
    }
#line 1712 "parser.tab.cpp"
    break;

  case 49: /* call_args: expression  */
#line 426 "parser.ypp"
    {
        std::vector < std::string > *result = new std::vector < std::string >;
        result -> push_back((yyvsp[0].node) -> get_type());
        (yyval. params_type ) = result;
    }
#line 1722 "parser.tab.cpp"
    break;

  case 50: /* call_args: call_args COMMA expression  */
#line 432 "parser.ypp"
    {
        std::vector < std::string > *result = (yyvsp[-2]. params_type );
        result -> push_back((yyvsp[0].node) -> get_type());
        (yyval. params_type ) = result;
    }
#line 1732 "parser.tab.cpp"
    break;

  case 51: /* expression: expression ADD_OP expression  */
#line 441 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR , OP::ADD_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1741 "parser.tab.cpp"
    break;

  case 52: /* expression: expression SUB_OP expression  */
#line 446 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::SUB_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1750 "parser.tab.cpp"
    break;

  case 53: /* expression: expression MUL_OP expression  */
#line 451 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::MUL_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1759 "parser.tab.cpp"
    break;

  case 54: /* expression: expression DIV_OP expression  */
#line 456 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::DIV_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1768 "parser.tab.cpp"
    break;

  case 55: /* expression: expression OP_AND expression  */
#line 461 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_AND) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1777 "parser.tab.cpp"
    break;

  case 56: /* expression: expression OP_OR expression  */
#line 466 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_OR) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1786 "parser.tab.cpp"
    break;

  case 57: /* expression: expression OP_BIT_OR expression  */
#line 471 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_BIT_OR) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1795 "parser.tab.cpp"
    break;

  case 58: /* expression: expression OP_BIT_XOR expression  */
#line 476 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_BIT_XOR) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1804 "parser.tab.cpp"
    break;

  case 59: /* expression: expression OP_BIT_AND expression  */
#line 481 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_BIT_AND) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1813 "parser.tab.cpp"
    break;

  case 60: /* expression: expression OP_BIT_LSHIFT expression  */
#line 486 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_BIT_LSHIFT) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1822 "parser.tab.cpp"
    break;

  case 61: /* expression: expression OP_BIT_RSHIFT expression  */
#line 491 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::_BIT_RSHIFT) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1831 "parser.tab.cpp"
    break;

  case 62: /* expression: expression MOD_OP expression  */
#line 496 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::MOD_) , (yyvsp[0].node) , (yyvsp[-2].node) -> get_type_ptr());
    }
#line 1840 "parser.tab.cpp"
    break;

  case 63: /* expression: expression LT_OP expression  */
#line 501 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::LT_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1849 "parser.tab.cpp"
    break;

  case 64: /* expression: expression GT_OP expression  */
#line 506 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::GT_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1858 "parser.tab.cpp"
    break;

  case 65: /* expression: expression LEQ_OP expression  */
#line 511 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::LEQ_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1867 "parser.tab.cpp"
    break;

  case 66: /* expression: expression GEQ_OP expression  */
#line 516 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::GEQ_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1876 "parser.tab.cpp"
    break;

  case 67: /* expression: expression NEQ_OP expression  */
#line 521 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::NEQ_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1885 "parser.tab.cpp"
    break;

  case 68: /* expression: expression EQ_OP expression  */
#line 526 "parser.ypp"
    {
        check_matching_types((yyvsp[-2].node) -> get_type() , (yyvsp[0].node) -> get_type());
        (yyval.node) = new ASTnode((yyvsp[-2].node) , Data(TYPE::CHAR, OP::EQ_) , (yyvsp[0].node) , new std::string("BOOL"));
    }
#line 1894 "parser.tab.cpp"
    break;

  case 69: /* expression: OPEN_ROUND_PAR expression CLOSED_ROUND_PAR  */
#line 530 "parser.ypp"
                                                 {(yyval.node) = (yyvsp[-1].node);}
#line 1900 "parser.tab.cpp"
    break;

  case 70: /* expression: ID  */
#line 532 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[0].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[0].Str);
            exit(1);
        }

        (yyval.node) = new ASTnode(nullptr , Data(TYPE::ID_INFO , id_info) , nullptr , new std::string(id_info -> type));
    }
#line 1916 "parser.tab.cpp"
    break;

  case 71: /* expression: DOLLA_SIGN ID  */
#line 544 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[0].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[0].Str);
            exit(1);
        }

        if(id_info -> category != "param")
        {
            std::cout << yylineno << ": " << "Variable not a parameter: " << *(yyvsp[0].Str);
            exit(1);
        }

        (yyval.node) = new ASTnode(nullptr , Data(TYPE::ID_INFO , id_info) , nullptr , new std::string(id_info -> type));
    }
#line 1938 "parser.tab.cpp"
    break;

  case 72: /* expression: INT_CONST  */
#line 561 "parser.ypp"
                {(yyval.node) = new ASTnode(nullptr , Data(TYPE::INT , (yyvsp[0].val_int)) , nullptr , new std::string("INT"));}
#line 1944 "parser.tab.cpp"
    break;

  case 73: /* expression: BOOL_CONST  */
#line 562 "parser.ypp"
                 {(yyval.node) = new ASTnode(nullptr , Data(TYPE::BOOL , (bool)(yyvsp[0].val_int)) , nullptr , new std::string("BOOL"));}
#line 1950 "parser.tab.cpp"
    break;

  case 74: /* expression: FLOAT_CONST  */
#line 563 "parser.ypp"
                  {(yyval.node) = new ASTnode(nullptr , Data(TYPE::FLOAT , (yyvsp[0].val_float)) , nullptr , new std::string("FLOAT"));}
#line 1956 "parser.tab.cpp"
    break;

  case 75: /* expression: STRING_CONST  */
#line 564 "parser.ypp"
                   {(yyval.node) = new ASTnode(nullptr , Data(TYPE::STRING , (yyvsp[0].Str)) , nullptr , new std::string("STRING"));}
#line 1962 "parser.tab.cpp"
    break;

  case 76: /* expression: func_call  */
#line 565 "parser.ypp"
                {(yyval.node) = (yyvsp[0]. node );}
#line 1968 "parser.tab.cpp"
    break;

  case 77: /* expression: ID DOT ID  */
#line 567 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-2].Str));
        
        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[-2].Str);
            exit(1);
        }

        IdInfo *id_class = globalScope -> lookup(id_info -> type);

        if(id_class == nullptr)
        {
            std::cout << yylineno << ": " << "Type not a class: " << id_info -> type;
            exit(1);
        }
        else if(id_class -> category != "class")
        {
            std::cout << yylineno << ": " << "Type not a class: " << id_info -> type;
            exit(1);
        }

        SymbolTable *class_scope = SymbolTable::class_lookup(id_info -> type , classes);
        IdInfo *submember = class_scope -> lookup(*(yyvsp[0].Str));

        if(submember == nullptr)
        {
            std::cout << yylineno << ": " << "Class " << id_info -> type << ' ' << "does not have member: " << *(yyvsp[0].Str);
            exit(1);
        }

       // $$ = new std::string(submember -> type);
        (yyval.node) = new ASTnode(nullptr , Data(TYPE::ID_INFO , submember) , nullptr , new std::string(submember -> type));

    }
#line 2008 "parser.tab.cpp"
    break;

  case 78: /* expression: NOT_OP expression  */
#line 603 "parser.ypp"
    {
        if ((yyvsp[0].node)->get_type() != "BOOL")
        {
             std::cout << yylineno << ": " << "Type mismatch: NOT operator requires BOOL, got " << (yyvsp[0].node)->get_type();
             exit(1);
        }
        (yyval.node) = new ASTnode((yyvsp[0].node) , Data(TYPE::CHAR, OP::NOT_) , nullptr , new std::string("BOOL"));
    }
#line 2021 "parser.tab.cpp"
    break;

  case 79: /* expression: SUB_OP expression  */
#line 612 "parser.ypp"
    {
        if ((yyvsp[0].node)->get_type() != "INT" && (yyvsp[0].node)->get_type() != "FLOAT")
        {
             std::cout << yylineno << ": " << "Type mismatch: Unary Minus operator requires INT or FLOAT, got " << (yyvsp[0].node)->get_type();
             exit(1);
        }
        (yyval.node) = new ASTnode((yyvsp[0].node) , Data(TYPE::CHAR, OP::UMINUS_) , nullptr , (yyvsp[0].node)->get_type_ptr());
    }
#line 2034 "parser.tab.cpp"
    break;

  case 80: /* type_specifier: TYPE  */
#line 623 "parser.ypp"
         { (yyval.Str) = (yyvsp[0].Str); }
#line 2040 "parser.tab.cpp"
    break;

  case 81: /* type_specifier: ID  */
#line 625 "parser.ypp"
    {
        SymbolTable *class_scope = SymbolTable::class_lookup(*(yyvsp[0].Str) , classes);
       
        if(class_scope == nullptr && *(yyvsp[0].Str) != "INT" && *(yyvsp[0].Str) != "FLOAT" && *(yyvsp[0].Str) != "STRING" && *(yyvsp[0].Str) != "BOOL")
        {
            std::cout << yylineno << ": " << "Invalid type declared: " << *(yyvsp[0].Str) << '\n';
            exit(1);
        } 

        (yyval.Str) = (yyvsp[0].Str); 
    }
#line 2056 "parser.tab.cpp"
    break;


#line 2060 "parser.tab.cpp"

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

#line 638 "parser.ypp"


void yyerror(const char *s) {
    std::cerr << "Syntax Error at line " << yylineno << ": " << s << std::endl;
    exit(1);
}

int main() {
    // yydebug = 1; 
    if (yyparse() == 0) {
        std::cout << "Parsing successful!" << std::endl;
        
        std::ofstream outFile("tables.txt");
        const auto& tables = SymbolTable::getAllTables();
        for (auto table : tables) {
            table->print(outFile);
        }
        outFile.close();
        std::cout << "Symbol tables written to tables.txt" << std::endl;
    }
    return 0;
}
