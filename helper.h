#pragma once 
#include <string> 

 enum TYPE {INT , FLOAT , BOOL , STRING , CHAR , ID_INFO};
 enum OP { _OR , _AND , _BIT_OR , _BIT_XOR , _BIT_AND , EQ_ , NEQ_ , 
          LT_ , GT_ , GEQ_ , LEQ_ , _BIT_LSHIFT , _BIT_RSHIFT , ADD_ , SUB_ , 
          MUL_ , DIV_ , MOD_ , ASSIGN_ , PRINT};

extern std::string type_enum[];
extern int yylineno;
