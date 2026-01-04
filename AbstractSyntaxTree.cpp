#include "AbstractSyntaxTree.h"
#include "helper.h"
#include <cassert>

std::string ASTnode::get_type()
{
    return *type;
}

std::string *ASTnode::get_type_ptr() 
{
    return type;
}

Data transf(DataId x)
{
    if(x.type == TYPE::INT) return Data(TYPE::INT , x.get_int());
    if(x.type == TYPE::FLOAT) return Data(TYPE::FLOAT , x.get_float());
    if(x.type == TYPE::BOOL) return Data(TYPE::BOOL , x.get_bool());
    if(x.type == TYPE::STRING) return Data(TYPE::STRING , x.get_string());
    std::cout << "invalid transform";
    exit(1);
}

DataId transf(Data x)
{
    if(x.type == TYPE::INT) return DataId(TYPE::INT , x.get_int());
    if(x.type == TYPE::FLOAT) return DataId(TYPE::FLOAT , x.get_float());
    if(x.type == TYPE::BOOL) return DataId(TYPE::BOOL , x.get_bool());
    if(x.type == TYPE::STRING) return DataId(TYPE::STRING , x.get_string());
    std::cout << "invalid transform";
    exit(1);
}

Data combine(Data l , char op , Data r)
{
    switch(l.type)
    {
        case INT:
        {
            int a = l.get_int();
            int b = r.get_int();

            if(op == _OR) return Data(BOOL , a || b);
            if(op == _AND) return Data(BOOL , a && b);
            if(op == _BIT_OR) return Data(INT , a | b);
            if(op == _BIT_XOR) return Data(INT , a ^ b);
            if(op == _BIT_AND) return Data(INT , a & b);
            if(op == EQ_) return Data(BOOL , a == b);
            if(op == NEQ_) return Data(BOOL , a != b);
            if(op == LT_) return Data(BOOL , a < b);
            if(op == GT_) return Data(BOOL , a > b);
            if(op == GEQ_) return Data(BOOL , a >= b);
            if(op == LEQ_) return Data(BOOL , a <= b);
            if(op == _BIT_LSHIFT) return Data(INT , a << b);
            if(op == _BIT_RSHIFT) return Data(INT , a >> b);
            if(op == ADD_) return Data(INT , a + b);
            if(op == SUB_) return Data(INT , a - b);
            if(op == MUL_) return Data(INT , a * b);
            if(op == DIV_) return Data(INT , a / b);
            if(op == MOD_) return Data(INT , a % b);

            std::cout << "invalid op";
            exit(1);
            break;
        }

        case FLOAT: 
        {
            float a = l.get_float();
            float b = r.get_float();

            if(op == _OR) return Data(BOOL , a || b);
            if(op == _AND) return Data(BOOL , a && b);
            if(op == _BIT_OR) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_XOR) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_AND) {std::cout << "Invalid operation"; exit(1);};
            if(op == EQ_) return Data(BOOL , a == b);
            if(op == NEQ_) return Data(BOOL , a != b);
            if(op == LT_) return Data(BOOL , a < b);
            if(op == GT_) return Data(BOOL , a > b);
            if(op == GEQ_) return Data(BOOL , a >= b);
            if(op == LEQ_) return Data(BOOL , a <= b);
            if(op == _BIT_LSHIFT) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_RSHIFT) {std::cout << "Invalid operation"; exit(1);};
            if(op == ADD_) return Data(FLOAT , a + b);
            if(op == SUB_) return Data(FLOAT , a - b);
            if(op == MUL_) return Data(FLOAT , a * b);
            if(op == DIV_) return Data(FLOAT , a / b);
            {std::cout << "Invalid operation"; exit(1);};

            std::cout << "invalid op";
            exit(1);
            break;
        }

        case BOOL: 
        {
            bool a = l.get_bool();
            bool b = r.get_bool();

            if(op == _OR) return Data(BOOL , a || b);
            if(op == _AND) return Data(BOOL , a && b);
            if(op == _BIT_OR) return Data(BOOL , a | b);
            if(op == _BIT_XOR) return Data(BOOL , a ^ b);
            if(op == _BIT_AND) return Data(BOOL , a & b);
            if(op == EQ_) return Data(BOOL , a == b);
            if(op == NEQ_) return Data(BOOL , a != b);
            if(op == LT_) return Data(BOOL , a < b);
            if(op == GT_) return Data(BOOL , a > b);
            if(op == GEQ_) return Data(BOOL , a >= b);
            if(op == LEQ_) return Data(BOOL , a <= b);
            if(op == _BIT_LSHIFT) return Data(BOOL , a << b);
            if(op == _BIT_RSHIFT) return Data(BOOL , a >> b);
            if(op == ADD_) return Data(BOOL , a + b);
            if(op == SUB_) return Data(BOOL , a - b);
            if(op == MUL_) return Data(BOOL , a * b);
            if(op == DIV_) return Data(BOOL , a / b);
            if(op == MOD_) return Data(BOOL , a % b);

            std::cout << "invalid op";
            exit(1);
            break;
        }

        case STRING: 
        {
            std::string a = *l.get_string();
            std::string b = *r.get_string();

            if(op == _OR) {std::cout << "Invalid operation"; exit(1);};
            if(op == _AND) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_OR) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_XOR) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_AND) {std::cout << "Invalid operation"; exit(1);};
            if(op == EQ_) return Data(BOOL , a == b);
            if(op == NEQ_) return Data(BOOL , a != b);
            if(op == LT_) return Data(BOOL , a < b);
            if(op == GT_) return Data(BOOL , a > b);
            if(op == GEQ_) return Data(BOOL , a >= b);
            if(op == LEQ_) return Data(BOOL , a <= b);
            if(op == _BIT_LSHIFT) {std::cout << "Invalid operation"; exit(1);};
            if(op == _BIT_RSHIFT) {std::cout << "Invalid operation"; exit(1);};
            if(op == ADD_) return Data(INT , new std::string(a + b));
            if(op == SUB_) {std::cout << "Invalid operation"; exit(1);};;
            if(op == MUL_) {std::cout << "Invalid operation"; exit(1);};;
            if(op == DIV_) {std::cout << "Invalid operation"; exit(1);};;
            if(op == MOD_) {std::cout << "Invalid operation"; exit(1);};;

            std::cout << "invalid op";
            exit(1);
            break;
        }

        default:
        {
            std::cout << "invalid type";
            exit(1);
        }
    }
    
    std::cout << "invalid op";
    exit(1);
}

Data ASTnode::evaluate() 
{
    Data lft(TYPE::ID_INFO , (IdInfo*)nullptr) , rgt(TYPE::ID_INFO , (IdInfo*) nullptr);
    if(l != nullptr) lft =  l -> evaluate();
    if(r != nullptr) rgt = r -> evaluate();
    
    if(data.type == ID_INFO)
    {
        assert(l == nullptr && r == nullptr);
        return transf(data.get_id_info() -> value);
    }

    if(data.type == INT || data.type == FLOAT || data.type == BOOL || data.type == STRING)
    {
        assert(l == nullptr && r == nullptr);
        return data;
    }

    if(data.type == CHAR)
    {
        assert(l != nullptr && r != nullptr);
        return combine(lft , data.get_char() , rgt);
    }

    return data;
}


Data::Data(int type , int x)
{
    this -> type = type;
    this -> v.x = x;
}

Data::Data(int type , float x)
{
    this -> type = type;
    this -> v.y = x;
}

Data::Data(int type , bool x)
{
    this -> type = type;
    this -> v.z = x;
}

Data::Data(int type , std::string *x )
{
    this -> type = type;
    this -> v.s = x;
}

Data::Data(int type , IdInfo *x )
{
    this -> type = type;
    this -> v.id = x;
}

Data::Data(int type , char x )
{
    this -> type = type;
    this -> v.c = x;
}

int Data::get_int()
{
    assert(type == TYPE::INT);
    return v.x;
}

float Data::get_float()
{
    assert(type == TYPE::FLOAT);
    return v.y;
}

bool Data::get_bool()
{
    assert(type == TYPE::BOOL);
    return v.z;
}

std::string *Data::get_string()
{
    assert(type == TYPE::STRING);
    return v.s;
}

IdInfo *Data::get_id_info()
{
    assert(type == TYPE::ID_INFO);
    return v.id;
}

char Data::get_char()
{
    assert(type == TYPE::CHAR);
    return v.c;
}