#pragma once 
#include <string> 

 enum TYPE {INT , FLOAT , BOOL , STRING , CHAR , ID_INFO , OBJECT , VOID , RETURN_VAL};
 enum OP { _OR , _AND , _BIT_OR , _BIT_XOR , _BIT_AND , EQ_ , NEQ_ , 
          LT_ , GT_ , GEQ_ , LEQ_ , _BIT_LSHIFT , _BIT_RSHIFT , ADD_ , SUB_ , 
          MUL_ , DIV_ , MOD_ , ASSIGN_ , PRINT , NOT_ , UMINUS_ , DOT_ , NEW_ , CALL_ , BLOCK_ , SEQ_ , RET_ , DECL_ };

extern std::string type_enum[];
extern int yylineno;
