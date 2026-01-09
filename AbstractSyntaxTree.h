
#include "SymbolTable.h"

#pragma once 

union value
{
    int x;
    float y;
    bool z;
    std::string *s;
    IdInfo *id;
    char c;
};

struct Data 
{
    int type;
    value v;
    
    Data(int type , int x);
    Data(int type , float x);
    Data(int type , bool x);
    Data(int type , std::string *x );
    Data(int type , IdInfo *x );
    Data(int type , char x );

    int get_int();
    float get_float();
    bool get_bool();
    std::string *get_string();
    IdInfo *get_id_info();
    char get_char();
};

class ASTnode
{
    private:
        ASTnode *l , *r;
        Data data;
        std::string *type;
    public:
        ASTnode(ASTnode *l , Data data , ASTnode *r , std::string *type) : l(l) , data(data) , r(r) , type(type) {}
        Data evaluate();
        std::string get_type();
        std::string *get_type_ptr();
};

Data transf(DataId x);
DataId transf(Data x);