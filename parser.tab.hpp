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

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.ypp"

    #include <iostream>
    #include <string>
    #include <cstring>
    #include <vector>
    #include "SymbolTable.h"
    #include "helper.h"
    #include "AbstractSyntaxTree.h"

#line 59 "parser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    TYPE = 259,                    /* TYPE  */
    INT_CONST = 260,               /* INT_CONST  */
    FLOAT_CONST = 261,             /* FLOAT_CONST  */
    STRING_CONST = 262,            /* STRING_CONST  */
    KEYWORD_CLASS = 263,           /* KEYWORD_CLASS  */
    KEYWORD_FUNC = 264,            /* KEYWORD_FUNC  */
    KEYWORD_IF = 265,              /* KEYWORD_IF  */
    KEYWORD_MAIN = 266,            /* KEYWORD_MAIN  */
    KEYWORD_RETURN = 267,          /* KEYWORD_RETURN  */
    KEYWORD_WHILE = 268,           /* KEYWORD_WHILE  */
    KEYWORD_FOR = 269,             /* KEYWORD_FOR  */
    KEYWORD_PRINT = 270,           /* KEYWORD_PRINT  */
    KEYWORD_DEFINE = 271,          /* KEYWORD_DEFINE  */
    KEYWORD_THEN = 272,            /* KEYWORD_THEN  */
    ADD_OP = 273,                  /* ADD_OP  */
    SUB_OP = 274,                  /* SUB_OP  */
    MUL_OP = 275,                  /* MUL_OP  */
    DIV_OP = 276,                  /* DIV_OP  */
    ASSIGN_OP = 277,               /* ASSIGN_OP  */
    MOD_OP = 278,                  /* MOD_OP  */
    EQ_OP = 279,                   /* EQ_OP  */
    NEQ_OP = 280,                  /* NEQ_OP  */
    LT_OP = 281,                   /* LT_OP  */
    GT_OP = 282,                   /* GT_OP  */
    GEQ_OP = 283,                  /* GEQ_OP  */
    LEQ_OP = 284,                  /* LEQ_OP  */
    OP_AND = 285,                  /* OP_AND  */
    OP_OR = 286,                   /* OP_OR  */
    OP_BIT_AND = 287,              /* OP_BIT_AND  */
    OP_BIT_OR = 288,               /* OP_BIT_OR  */
    OP_BIT_XOR = 289,              /* OP_BIT_XOR  */
    OP_BIT_LSHIFT = 290,           /* OP_BIT_LSHIFT  */
    OP_BIT_RSHIFT = 291,           /* OP_BIT_RSHIFT  */
    OPEN_ROUND_PAR = 292,          /* OPEN_ROUND_PAR  */
    CLOSED_ROUND_PAR = 293,        /* CLOSED_ROUND_PAR  */
    OPEN_RECTANGLE_PAR = 294,      /* OPEN_RECTANGLE_PAR  */
    CLOSED_RECTANGLE_PAR = 295,    /* CLOSED_RECTANGLE_PAR  */
    OPEN_CURLY_BRACE = 296,        /* OPEN_CURLY_BRACE  */
    CLOSED_CURLY_BRACE = 297,      /* CLOSED_CURLY_BRACE  */
    SEMICOLON = 298,               /* SEMICOLON  */
    DOT = 299,                     /* DOT  */
    COMMA = 300,                   /* COMMA  */
    DOLLA_SIGN = 301,              /* DOLLA_SIGN  */
    UMINUS = 302                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.ypp"

    int val_int;
    float val_float;
    std::string* Str;
    std::vector<ParamInfo>* Params;
    std::vector < std::string > *params_type;
    ASTnode *node;

#line 132 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
