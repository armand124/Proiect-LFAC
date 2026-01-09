%{
#include <stdio.h>
#include <string>  
#include <stdlib.h>  
#include "parser.tab.hpp"
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
"if" {return KEYWORD_IF;}
"then" {return KEYWORD_THEN;}
"while" {return KEYWORD_WHILE;}
"class" {return KEYWORD_CLASS;}
"define" {return KEYWORD_DEFINE;}
"func" {return KEYWORD_FUNC;}
"INT"|"FLOAT"|"CHAR"|"STR"|"BOOL"|"VOID" {
    std::string type = yytext;
    if (type == "STR") type = "STRING";
    yylval.Str = new std::string(type);
    return TYPE;
}
"main" {return KEYWORD_MAIN;}
"return" {return KEYWORD_RETURN;}
"for" {return KEYWORD_FOR;}
"Print" { return KEYWORD_PRINT; }
"constr" { return KEYWORD_CONSTR; }
"true" { yylval.val_int = 1; return BOOL_CONST; }
"false" { yylval.val_int = 0; return BOOL_CONST; }

"+" {return ADD_OP;}
"!" {return NOT_OP;}
"-" {return SUB_OP;}
"*" {return MUL_OP;}
"%" {return MOD_OP;}
"/" {return DIV_OP;}
"=" {return ASSIGN_OP;}
"==" {return EQ_OP;}
"IS" {return EQ_OP;}
"!=" {return NEQ_OP;}
"<-" {return ASSIGN_CONSTR;}
"<" {return LT_OP;}
">" {return GT_OP;}
">=" {return GEQ_OP;}
"<=" {return LEQ_OP;}
"AND" {return OP_AND;}
"OR" {return OP_OR;}
"&" {return OP_BIT_AND;}
"|" {return OP_BIT_OR;}
"^" {return OP_BIT_XOR;}
"<<" {return OP_BIT_LSHIFT;}
">>" {return OP_BIT_RSHIFT;}
"(" {return OPEN_ROUND_PAR;}
")" {return CLOSED_ROUND_PAR;}
"[" {return OPEN_RECTANGLE_PAR;}
"]" {return CLOSED_RECTANGLE_PAR;}
"." {return DOT;}
"," {return COMMA;}
"$" {return DOLLA_SIGN;}
"{" { return OPEN_CURLY_BRACE;}
"}" { return CLOSED_CURLY_BRACE;}
";" { return SEMICOLON;}

{LETTER}({LETTER}|{DIGIT})* {
    yylval.Str = new std::string(yytext); return ID;
}

{DIGIT}+ {
    yylval.val_int = atoi(yytext);
    return INT_CONST;
}

{DIGIT}+"."{DIGIT}+ {
    yylval.val_float = atof(yytext);
    return FLOAT_CONST;
}

\"[^\"]*\" {
    yylval.Str = new std::string(yytext);
    // Remove quotes
    yylval.Str -> erase(0, 1);
    yylval.Str -> pop_back();
    return STRING_CONST;
}

[ \t]+    {}
\n        { yylineno++; }   
"#".* {}
. { std::cout<< yylineno << ": " <<"Error: Unknown character:" << yytext << std::endl; exit(1); }

%%
int yywrap() {
    return 1;
}