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
#line 9 "parser.ypp"

    #include <iostream>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <fstream>
    #include "SymbolTable.h"

    #define YYDEBUG 1 
    
    extern int yylex();
    extern int yylineno;
    void yyerror(const char *s);

    SymbolTable* currentScope = nullptr , *globalScope = nullptr;
    std::map < std::string , SymbolTable* > classes;

    std::string check_matching_types(std::string type1 , std::string type2)
    {
        if(type1 != type2)
        {
            std::cout << yylineno << ": " << "Cannot combine " << type1 << ' ' << "and " << type2 << " into an expression";
            exit(1);
        }

        return type1;
    }

    bool check_func_parameters(std::string f_name , std::vector < ParamInfo > &f_param , std::vector < std::string > &c_param)
    {
        if(f_param.size() != c_param.size())
        {
            std::cout << yylineno << ": " << "Function " << f_name << " takes " << f_param.size() << " parameters, but there were given " << c_param.size();
            exit(1);
        }

        for(int i = 0 ; i < f_param.size() ; i++)
        {
            if(f_param[i].type != c_param[i])
            {
                printf("Function %s expects %s on the %d-th parameter" , f_name.c_str() , f_param[i].type.c_str() , i + 1);
                exit(1);
            }

        }

        return true;
    }

#line 121 "parser.tab.cpp"

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
  YYSYMBOL_FLOAT_CONST = 6,                /* FLOAT_CONST  */
  YYSYMBOL_KEYWORD_CLASS = 7,              /* KEYWORD_CLASS  */
  YYSYMBOL_KEYWORD_FUNC = 8,               /* KEYWORD_FUNC  */
  YYSYMBOL_KEYWORD_IF = 9,                 /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_MAIN = 10,              /* KEYWORD_MAIN  */
  YYSYMBOL_KEYWORD_RETURN = 11,            /* KEYWORD_RETURN  */
  YYSYMBOL_KEYWORD_WHILE = 12,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_FOR = 13,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_PRINT = 14,             /* KEYWORD_PRINT  */
  YYSYMBOL_KEYWORD_DEFINE = 15,            /* KEYWORD_DEFINE  */
  YYSYMBOL_KEYWORD_THEN = 16,              /* KEYWORD_THEN  */
  YYSYMBOL_ADD_OP = 17,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 18,                    /* SUB_OP  */
  YYSYMBOL_MUL_OP = 19,                    /* MUL_OP  */
  YYSYMBOL_DIV_OP = 20,                    /* DIV_OP  */
  YYSYMBOL_ASSIGN_OP = 21,                 /* ASSIGN_OP  */
  YYSYMBOL_MOD_OP = 22,                    /* MOD_OP  */
  YYSYMBOL_EQ_OP = 23,                     /* EQ_OP  */
  YYSYMBOL_NEQ_OP = 24,                    /* NEQ_OP  */
  YYSYMBOL_LT_OP = 25,                     /* LT_OP  */
  YYSYMBOL_GT_OP = 26,                     /* GT_OP  */
  YYSYMBOL_GEQ_OP = 27,                    /* GEQ_OP  */
  YYSYMBOL_LEQ_OP = 28,                    /* LEQ_OP  */
  YYSYMBOL_OP_AND = 29,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 30,                     /* OP_OR  */
  YYSYMBOL_OP_BIT_AND = 31,                /* OP_BIT_AND  */
  YYSYMBOL_OP_BIT_OR = 32,                 /* OP_BIT_OR  */
  YYSYMBOL_OP_BIT_XOR = 33,                /* OP_BIT_XOR  */
  YYSYMBOL_OP_BIT_LSHIFT = 34,             /* OP_BIT_LSHIFT  */
  YYSYMBOL_OP_BIT_RSHIFT = 35,             /* OP_BIT_RSHIFT  */
  YYSYMBOL_OPEN_ROUND_PAR = 36,            /* OPEN_ROUND_PAR  */
  YYSYMBOL_CLOSED_ROUND_PAR = 37,          /* CLOSED_ROUND_PAR  */
  YYSYMBOL_OPEN_RECTANGLE_PAR = 38,        /* OPEN_RECTANGLE_PAR  */
  YYSYMBOL_CLOSED_RECTANGLE_PAR = 39,      /* CLOSED_RECTANGLE_PAR  */
  YYSYMBOL_OPEN_CURLY_BRACE = 40,          /* OPEN_CURLY_BRACE  */
  YYSYMBOL_CLOSED_CURLY_BRACE = 41,        /* CLOSED_CURLY_BRACE  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_DOLLA_SIGN = 45,                /* DOLLA_SIGN  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_global_declarations = 50,       /* global_declarations  */
  YYSYMBOL_class_decl = 51,                /* class_decl  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_class_body = 53,                /* class_body  */
  YYSYMBOL_field_decl = 54,                /* field_decl  */
  YYSYMBOL_method_decl = 55,               /* method_decl  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_func_decl = 57,                 /* func_decl  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_func_params = 59,               /* func_params  */
  YYSYMBOL_main_block = 60,                /* main_block  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_compound_statement = 62,        /* compound_statement  */
  YYSYMBOL_block_item_list = 63,           /* block_item_list  */
  YYSYMBOL_block_item = 64,                /* block_item  */
  YYSYMBOL_variable_decl = 65,             /* variable_decl  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_assignment = 67,                /* assignment  */
  YYSYMBOL_print_stmt = 68,                /* print_stmt  */
  YYSYMBOL_func_call = 69,                 /* func_call  */
  YYSYMBOL_call_args = 70,                 /* call_args  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_type_specifier = 72             /* type_specifier  */
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
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   103,   106,   107,   108,   109,   114,   113,
     133,   135,   136,   140,   148,   147,   165,   164,   181,   183,
     189,   197,   196,   208,   211,   212,   216,   217,   223,   227,
     236,   237,   238,   239,   240,   241,   242,   243,   247,   263,
     304,   308,   321,   364,   369,   375,   384,   390,   395,   400,
     405,   410,   415,   420,   425,   430,   435,   440,   445,   446,
     458,   476,   477,   478,   479,   513,   517,   518
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
  "INT_CONST", "FLOAT_CONST", "KEYWORD_CLASS", "KEYWORD_FUNC",
  "KEYWORD_IF", "KEYWORD_MAIN", "KEYWORD_RETURN", "KEYWORD_WHILE",
  "KEYWORD_FOR", "KEYWORD_PRINT", "KEYWORD_DEFINE", "KEYWORD_THEN",
  "ADD_OP", "SUB_OP", "MUL_OP", "DIV_OP", "ASSIGN_OP", "MOD_OP", "EQ_OP",
  "NEQ_OP", "LT_OP", "GT_OP", "GEQ_OP", "LEQ_OP", "OP_AND", "OP_OR",
  "OP_BIT_AND", "OP_BIT_OR", "OP_BIT_XOR", "OP_BIT_LSHIFT",
  "OP_BIT_RSHIFT", "OPEN_ROUND_PAR", "CLOSED_ROUND_PAR",
  "OPEN_RECTANGLE_PAR", "CLOSED_RECTANGLE_PAR", "OPEN_CURLY_BRACE",
  "CLOSED_CURLY_BRACE", "SEMICOLON", "DOT", "COMMA", "DOLLA_SIGN",
  "UMINUS", "$accept", "program", "$@1", "global_declarations",
  "class_decl", "$@2", "class_body", "field_decl", "method_decl", "$@3",
  "func_decl", "$@4", "func_params", "main_block", "$@5",
  "compound_statement", "block_item_list", "block_item", "variable_decl",
  "statement", "assignment", "print_stmt", "func_call", "call_args",
  "expression", "type_specifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -40,     4,   -40,   -40,    34,   -40,   -40,   -40,    87,   -40,
     -40,   -40,   -40,    11,   -33,    14,    52,    16,    22,   -40,
     -40,   -40,    45,     8,     6,    17,    19,    36,   -40,   -30,
     -40,   -40,     6,     6,    89,   -40,    58,    53,     6,     6,
       6,    94,    71,    52,   -40,   -40,   -40,   -40,   -40,    72,
     -40,    75,   -40,    52,     6,   110,   -40,   172,   -40,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   -40,     6,   116,   202,   114,   154,   -16,    79,     6,
     -40,   -40,    -5,   -22,    77,   -21,   216,    88,   -40,    85,
      85,   -40,   -40,   255,   255,    92,    92,    92,    92,   243,
     230,   216,   -18,   -33,   -40,   -40,   122,     6,   187,    95,
     -40,   -40,   -40,   -40,    52,   123,   -40,     6,     6,     6,
     -40,   106,   134,    86,    52,   126,   -33,    90,   -40,   216,
       9,   216,    94,   -40,   127,   103,   -40,   143,   -40,   -33,
     111,   -40,   -40,   -40,    52,    10,   -40,   -33,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     0,    67,    66,    21,     0,     5,
       6,     3,     7,     0,     0,     0,     0,     0,     0,    24,
      22,     8,     0,     0,     0,     0,     0,     0,    28,    59,
      61,    62,     0,     0,     0,    63,     0,    67,     0,     0,
       0,     0,     0,     0,    23,    37,    25,    26,    27,     0,
      35,     0,    10,    18,    43,     0,    65,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    36,     0,     0,     0,     0,    44,    64,    58,    46,
      47,    48,    49,    57,    56,    52,    53,    55,    54,    50,
      51,    38,     0,     0,    34,    32,     0,     0,     0,     0,
       9,    11,    12,    16,     0,     0,    41,     0,    43,     0,
      31,     0,     0,     0,     0,     0,     0,     0,    19,    45,
       0,    39,     0,    40,     0,     0,    17,     0,    42,     0,
       0,    13,    20,    33,    18,     0,    14,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,     5,   -40,   -40,   -24,   -40,   -40,   125,   -40,
     -39,   -40,   130,    30,     1,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     9,    26,    82,   111,   112,   147,
      10,   126,    83,    11,    14,    20,    25,    46,    12,    48,
      49,    50,    35,    85,    86,    13
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    45,    78,   119,     3,    72,    54,    19,    22,    29,
     109,    30,    31,    55,    18,   113,   116,    21,   118,    23,
      37,     6,   114,   117,    32,    36,    38,   106,    39,    40,
      41,    42,    43,    56,    57,    17,   110,     5,     6,    74,
      75,    76,    33,    24,     7,    84,   138,   146,    27,     8,
      28,    34,   105,   117,   114,     5,     6,    19,    44,    52,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    53,   101,    72,    59,    60,    61,    62,   120,
     108,    63,    64,    65,    66,    67,    68,    69,    70,    54,
       5,     6,    58,   139,    15,    16,    73,    77,     5,     6,
      71,   125,   136,   124,    61,    62,   127,    79,   122,    59,
      60,    61,    62,    87,    80,   143,   134,    81,   129,   102,
     131,   107,   115,   148,   118,   121,   128,   119,   133,   135,
     140,    59,    60,    61,    62,   137,    84,    63,    64,    65,
      66,    67,    68,    69,    70,   141,   142,   144,   130,   145,
      47,    59,    60,    61,    62,    51,   104,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,     0,   132,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,     0,     0,    59,
      60,    61,    62,     0,    19,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    59,    60,    61,    62,     0,    88,
      63,    64,    65,    66,    67,    68,    69,    70,   103,    59,
      60,    61,    62,     0,   123,    63,    64,    65,    66,    67,
      68,    69,    70,    59,    60,    61,    62,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    59,    60,    61,
      62,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      59,    60,    61,    62,     0,     0,    63,    64,    65,    66,
      67,    68,    59,    60,    61,    62,     0,     0,     0,     0,
      65,    66,    67,    68
};

static const yytype_int16 yycheck[] =
{
       8,    25,    41,    21,     0,    21,    36,    40,    16,     3,
      15,     5,     6,    43,     3,    37,    37,     3,    36,     3,
       3,     4,    44,    44,    18,    24,     9,    43,    11,    12,
      13,    14,    15,    32,    33,    43,    41,     3,     4,    38,
      39,    40,    36,    21,    10,    53,    37,    37,     3,    15,
      42,    45,    76,    44,    44,     3,     4,    40,    41,    40,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    36,    72,    21,    17,    18,    19,    20,   103,
      79,    23,    24,    25,    26,    27,    28,    29,    30,    36,
       3,     4,     3,   132,     7,     8,    43,     3,     3,     4,
      42,   109,   126,     8,    19,    20,   114,    36,   107,    17,
      18,    19,    20,     3,    42,   139,   124,    42,   117,     3,
     119,    42,    45,   147,    36,     3,     3,    21,    42,     3,
       3,    17,    18,    19,    20,    45,   144,    23,    24,    25,
      26,    27,    28,    29,    30,    42,     3,    36,   118,   144,
      25,    17,    18,    19,    20,    25,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    40,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    17,    18,    19,    20,    -1,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    16,    17,
      18,    19,    20,    -1,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    17,    18,    19,    20,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    17,    18,    19,
      20,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      17,    18,    19,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,    50,     3,     4,    10,    15,    51,
      57,    60,    65,    72,    61,     7,     8,    72,     3,    40,
      62,     3,    72,     3,    21,    63,    52,     3,    42,     3,
       5,     6,    18,    36,    45,    69,    71,     3,     9,    11,
      12,    13,    14,    15,    41,    62,    64,    65,    66,    67,
      68,    69,    40,    36,    36,    43,    71,    71,     3,    17,
      18,    19,    20,    23,    24,    25,    26,    27,    28,    29,
      30,    42,    21,    43,    71,    71,    71,     3,    67,    36,
      42,    42,    53,    59,    72,    70,    71,     3,    37,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,     3,    16,    42,    62,    43,    42,    71,    15,
      41,    54,    55,    37,    44,    45,    37,    44,    36,    21,
      62,     3,    71,    37,     8,    72,    58,    72,     3,    71,
      70,    71,    42,    42,    72,     3,    62,    45,    37,    67,
       3,    42,     3,    62,    36,    59,    37,    56,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    49,    48,    50,    50,    50,    50,    52,    51,
      53,    53,    53,    54,    56,    55,    58,    57,    59,    59,
      59,    61,    60,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    69,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     2,     0,     7,
       0,     2,     2,     4,     0,     9,     0,     9,     0,     3,
       5,     0,     3,     3,     0,     2,     1,     1,     4,     5,
       2,     4,     3,     7,     3,     1,     2,     1,     3,     5,
       5,     4,     6,     0,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     1,     1,     3,     2,     1,     1
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
#line 103 "parser.ypp"
    { currentScope = globalScope = new SymbolTable("Global"); yylineno = 1;}
#line 1305 "parser.tab.cpp"
    break;

  case 8: /* $@2: %empty  */
#line 114 "parser.ypp"
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
#line 1323 "parser.tab.cpp"
    break;

  case 9: /* class_decl: KEYWORD_DEFINE KEYWORD_CLASS ID $@2 OPEN_CURLY_BRACE class_body CLOSED_CURLY_BRACE  */
#line 128 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1331 "parser.tab.cpp"
    break;

  case 13: /* field_decl: KEYWORD_DEFINE type_specifier ID SEMICOLON  */
#line 141 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-2].Str), *(yyvsp[-1].Str), "field", nullptr);
    }
#line 1339 "parser.tab.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 148 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "function", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1353 "parser.tab.cpp"
    break;

  case 15: /* method_decl: KEYWORD_DEFINE KEYWORD_FUNC type_specifier ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@3 compound_statement  */
#line 158 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1361 "parser.tab.cpp"
    break;

  case 16: /* $@4: %empty  */
#line 165 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "function", (yyvsp[-1].Params));
        currentScope = new SymbolTable(*(yyvsp[-3].Str), currentScope);
        if ((yyvsp[-1].Params)) {
           for (const auto& param : *(yyvsp[-1].Params)) {
               currentScope->addVar(param.type, param.name, "param", nullptr);
           }
        }
    }
#line 1375 "parser.tab.cpp"
    break;

  case 17: /* func_decl: KEYWORD_DEFINE KEYWORD_FUNC type_specifier ID OPEN_ROUND_PAR func_params CLOSED_ROUND_PAR $@4 compound_statement  */
#line 175 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1383 "parser.tab.cpp"
    break;

  case 18: /* func_params: %empty  */
#line 181 "parser.ypp"
    { (yyval.Params) = new std::vector<ParamInfo>(); }
#line 1389 "parser.tab.cpp"
    break;

  case 19: /* func_params: type_specifier DOLLA_SIGN ID  */
#line 184 "parser.ypp"
    {
        (yyval.Params) = new std::vector<ParamInfo>();
        (yyval.Params)->push_back(ParamInfo(*(yyvsp[-2].Str), *(yyvsp[0].Str)));
    }
#line 1398 "parser.tab.cpp"
    break;

  case 20: /* func_params: func_params COMMA type_specifier DOLLA_SIGN ID  */
#line 190 "parser.ypp"
    {
        (yyval.Params) = (yyvsp[-4].Params);
        (yyval.Params)->push_back(ParamInfo(*(yyvsp[-2].Str), *(yyvsp[0].Str)));
    }
#line 1407 "parser.tab.cpp"
    break;

  case 21: /* $@5: %empty  */
#line 197 "parser.ypp"
    { 
        currentScope = new SymbolTable("main", currentScope);
    }
#line 1415 "parser.tab.cpp"
    break;

  case 22: /* main_block: KEYWORD_MAIN $@5 compound_statement  */
#line 201 "parser.ypp"
    { 
        currentScope = currentScope->getParent();
    }
#line 1423 "parser.tab.cpp"
    break;

  case 28: /* variable_decl: KEYWORD_DEFINE type_specifier ID SEMICOLON  */
#line 224 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-2].Str), *(yyvsp[-1].Str), "variable", nullptr);
    }
#line 1431 "parser.tab.cpp"
    break;

  case 29: /* variable_decl: type_specifier ID ASSIGN_OP expression SEMICOLON  */
#line 228 "parser.ypp"
    { 
        currentScope->addVar(*(yyvsp[-4].Str), *(yyvsp[-3].Str), "variable", nullptr);
    }
#line 1439 "parser.tab.cpp"
    break;

  case 38: /* assignment: ID ASSIGN_OP expression  */
#line 248 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-2].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[-2].Str);
            exit(1);
        }

        if(id_info -> type != *(yyvsp[0].Str))
        {
            std::cout << yylineno << ": " << "Casting not allowed between " << id_info -> type << " and " << *(yyvsp[0].Str);
            exit(1);
        }
    }
#line 1459 "parser.tab.cpp"
    break;

  case 39: /* assignment: ID DOT ID ASSIGN_OP expression  */
#line 264 "parser.ypp"
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

        if(submember -> type != *(yyvsp[0].Str))
        {
            std::cout << yylineno << ": " << "Casting not allowed between " << submember -> type << " and " << *(yyvsp[0].Str);
            exit(1);
        }
    }
#line 1501 "parser.tab.cpp"
    break;

  case 41: /* func_call: ID OPEN_ROUND_PAR call_args CLOSED_ROUND_PAR  */
#line 309 "parser.ypp"
    { 
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[-3].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Function: " << *(yyvsp[-3].Str) << " does not exist";
            exit(1); 
        }

        check_func_parameters(*(yyvsp[-3].Str) , id_info -> param , *(yyvsp[-1]. params_type ));
        (yyval. Str ) = new std::string(id_info -> return_type);
    }
#line 1518 "parser.tab.cpp"
    break;

  case 42: /* func_call: ID DOT ID OPEN_ROUND_PAR call_args CLOSED_ROUND_PAR  */
#line 322 "parser.ypp"
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
        (yyval. Str ) = new std::string(submember -> return_type);
    }
#line 1562 "parser.tab.cpp"
    break;

  case 43: /* call_args: %empty  */
#line 364 "parser.ypp"
    {
        std::vector < std::string > *result = new std::vector < std::string >;
        (yyval. params_type ) = result;
    }
#line 1571 "parser.tab.cpp"
    break;

  case 44: /* call_args: expression  */
#line 370 "parser.ypp"
    {
        std::vector < std::string > *result = new std::vector < std::string >;
        result -> push_back(*(yyvsp[0].Str));
        (yyval. params_type ) = result;
    }
#line 1581 "parser.tab.cpp"
    break;

  case 45: /* call_args: call_args COMMA expression  */
#line 376 "parser.ypp"
    {
        std::vector < std::string > *result = (yyvsp[-2]. params_type );
        result -> push_back(*(yyvsp[0].Str));
        (yyval. params_type ) = result;
    }
#line 1591 "parser.tab.cpp"
    break;

  case 46: /* expression: expression ADD_OP expression  */
#line 385 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));

        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1601 "parser.tab.cpp"
    break;

  case 47: /* expression: expression SUB_OP expression  */
#line 391 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1610 "parser.tab.cpp"
    break;

  case 48: /* expression: expression MUL_OP expression  */
#line 396 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1619 "parser.tab.cpp"
    break;

  case 49: /* expression: expression DIV_OP expression  */
#line 401 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1628 "parser.tab.cpp"
    break;

  case 50: /* expression: expression OP_AND expression  */
#line 406 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1637 "parser.tab.cpp"
    break;

  case 51: /* expression: expression OP_OR expression  */
#line 411 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1646 "parser.tab.cpp"
    break;

  case 52: /* expression: expression LT_OP expression  */
#line 416 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1655 "parser.tab.cpp"
    break;

  case 53: /* expression: expression GT_OP expression  */
#line 421 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1664 "parser.tab.cpp"
    break;

  case 54: /* expression: expression LEQ_OP expression  */
#line 426 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1673 "parser.tab.cpp"
    break;

  case 55: /* expression: expression GEQ_OP expression  */
#line 431 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1682 "parser.tab.cpp"
    break;

  case 56: /* expression: expression NEQ_OP expression  */
#line 436 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1691 "parser.tab.cpp"
    break;

  case 57: /* expression: expression EQ_OP expression  */
#line 441 "parser.ypp"
    {
        check_matching_types(*(yyvsp[-2].Str) , *(yyvsp[0].Str));
        (yyval.Str) = (yyvsp[-2].Str);
    }
#line 1700 "parser.tab.cpp"
    break;

  case 58: /* expression: OPEN_ROUND_PAR expression CLOSED_ROUND_PAR  */
#line 445 "parser.ypp"
                                                 {(yyval.Str) = (yyvsp[-1].Str);}
#line 1706 "parser.tab.cpp"
    break;

  case 59: /* expression: ID  */
#line 447 "parser.ypp"
    {
        IdInfo *id_info = currentScope -> lookup(*(yyvsp[0].Str));

        if(id_info == nullptr)
        {
            std::cout << yylineno << ": " << "Variable not declared in the scope: " << *(yyvsp[0].Str);
            exit(1);
        }

        (yyval.Str) = new std::string(id_info -> type);
    }
#line 1722 "parser.tab.cpp"
    break;

  case 60: /* expression: DOLLA_SIGN ID  */
#line 459 "parser.ypp"
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

        (yyval.Str) = new std::string(id_info -> type);
    }
#line 1744 "parser.tab.cpp"
    break;

  case 61: /* expression: INT_CONST  */
#line 476 "parser.ypp"
                {(yyval.Str) = new std::string("INT");}
#line 1750 "parser.tab.cpp"
    break;

  case 62: /* expression: FLOAT_CONST  */
#line 477 "parser.ypp"
                  {(yyval.Str) = new std::string("FLOAT");}
#line 1756 "parser.tab.cpp"
    break;

  case 63: /* expression: func_call  */
#line 478 "parser.ypp"
                {(yyval.Str) = (yyvsp[0]. Str );}
#line 1762 "parser.tab.cpp"
    break;

  case 64: /* expression: ID DOT ID  */
#line 480 "parser.ypp"
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

        (yyval.Str) = new std::string(submember -> type);
    }
#line 1800 "parser.tab.cpp"
    break;

  case 65: /* expression: SUB_OP expression  */
#line 513 "parser.ypp"
                                     {(yyval.Str) = (yyvsp[0].Str);}
#line 1806 "parser.tab.cpp"
    break;

  case 66: /* type_specifier: TYPE  */
#line 517 "parser.ypp"
         { (yyval.Str) = (yyvsp[0].Str); }
#line 1812 "parser.tab.cpp"
    break;

  case 67: /* type_specifier: ID  */
#line 518 "parser.ypp"
         { (yyval.Str) = (yyvsp[0].Str); }
#line 1818 "parser.tab.cpp"
    break;


#line 1822 "parser.tab.cpp"

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

#line 521 "parser.ypp"


void yyerror(const char *s) {
    std::cerr << "Syntax Error: " << s << std::endl;
}

int main() {
    // yydebug = 1; 
    if (yyparse() == 0) {
        std::cout << yylineno << ": " << "Parsing successful!" << std::endl;
        
        std::ofstream outFile("tables.txt");
        const auto& tables = SymbolTable::getAllTables();
        for (auto table : tables) {
            table->print(outFile);
        }
        outFile.close();
        std::cout << yylineno << ": " << "Symbol tables written to tables.txt" << std::endl;
    }
    return 0;
}
