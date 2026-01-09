
#include "AbstractSyntaxTree.h"
#include "helper.h"
#include <cassert>
#include <iostream>

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
    if(x.type == TYPE::OBJECT) return Data(TYPE::OBJECT , x.get_object());
    std::cout << "invalid transform DataId";
    exit(1);
}

DataId transf(Data x)
{
    if(x.type == TYPE::INT) return DataId(TYPE::INT , x.get_int());
    if(x.type == TYPE::FLOAT) return DataId(TYPE::FLOAT , x.get_float());
    if(x.type == TYPE::BOOL) return DataId(TYPE::BOOL , x.get_bool());
    if(x.type == TYPE::STRING) return DataId(TYPE::STRING , x.get_string());
    if(x.type == TYPE::OBJECT) return DataId(TYPE::OBJECT , x.get_object());
    std::cout << "invalid transform Data";
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
            if(op == ADD_) return Data(STRING , new std::string(a + b));
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
            std::cout << "invalid type in combine: " << l.type;
            exit(1);
        }
    }
    
    std::cout << "invalid op";
    exit(1);
}

Data ASTnode::evaluate(bool as_lvalue) 
{
    Data lft(TYPE::ID_INFO , (IdInfo*)nullptr) , rgt(TYPE::ID_INFO , (IdInfo*) nullptr);

    if (data.type == CHAR) {
         if (data.get_char() == ASSIGN_) {
             lft = l->evaluate(true); 
             rgt = r->evaluate(false);
             if (lft.type != ID_INFO) {
                 std::cout << "Left side of assignment is not an l-value (type="<< lft.type <<")";
                 exit(1);
             }
             IdInfo *id = lft.get_id_info();
             id->value = transf(rgt);
             return rgt;
         }
         
         if (data.get_char() == DOT_) {
             lft = l->evaluate(false); 
             if (lft.type != OBJECT) {
                 std::cout << "Left side of . must be an object";
                 exit(1);
             }
             SymbolTable *obj = lft.get_object();
             
             if (r->data.type != STRING) {
                 std::cout << "Right side of . must be member name";
                 exit(1);
             }
             std::string *memberName = r->data.get_string();
             
             IdInfo *member = obj->lookup(*memberName);
             if (!member) {
                 std::cout << "Member " << *memberName << " not found in object";
                 exit(1);
             }
             
             if (as_lvalue) return Data(TYPE::ID_INFO, member);
             return transf(member->value);
         }
         
         if (data.get_char() == NEW_) {
             lft = l->evaluate(false); 
             std::string *className = lft.get_string();
             
             SymbolTable *classScope = SymbolTable::getClass(*className);
             if (!classScope) {
                 std::cout << "Class " << *className << " not found";
                 exit(1);
             }
             
             SymbolTable *instance = new SymbolTable(*className, classScope);
             classScope->instantiate(instance);
             
             IdInfo* ctor = instance->lookup("constructor");
             if (ctor && ctor->body) {
                 if (ctor->body) {
                    ctor->body->evaluate(); 
                 }
             }
             
             return Data(TYPE::OBJECT, instance);
         }
         
         if (data.get_char() == BLOCK_) {
             l->evaluate(); 
             if (r) r->evaluate(); 
             return Data(TYPE::VOID, 0); 
         }
         
         if (data.get_char() == SEQ_) {
              l->evaluate();
              if (r) return r->evaluate();
              return Data(TYPE::VOID, 0);
         }
         
         if (data.get_char() == RET_) {
             Data res = l->evaluate();
             IdInfo* retHolder = new IdInfo();
             retHolder->value = transf(res);
             return Data(TYPE::RETURN_VAL, retHolder);
             return res;
         }
         
         if (data.get_char() == CALL_) {
             IdInfo* func = nullptr;
             SymbolTable* parentScope = nullptr;

             if (l->data.type == CHAR && l->data.get_char() == DOT_) {
                  Data objData = l->l->evaluate(false);
                  if (objData.type != OBJECT) {
                      std::cout << "Method call on non-object";
                      exit(1);
                  }
                  SymbolTable* instance = objData.get_object();
                  
                  std::string* methodName = l->r->data.get_string();
                  func = instance->lookup(*methodName);
                  if (!func) {
                      std::cout << "Method " << *methodName << " not found";
                      exit(1);
                  }
                  parentScope = instance; 
             } else {
                  Data funcData = l->evaluate(true); 
                  if (funcData.type != ID_INFO) {
                      std::cout << "Call target is not a function";
                      exit(1);
                  }
                  func = funcData.get_id_info();
                  
                  if (func->scope)
                      parentScope = func->scope->getParent();
                  else 
                      parentScope = nullptr; 
             }
             
             if (!func->body) {
                 return Data(TYPE::VOID, 0); 
             }

             std::map<IdInfo*, DataId> savedState;
             if (func->scope) {
                 for (const auto& param : func->param) {
                     IdInfo* info = func->scope->lookup(param.name);
                     if (info) savedState[info] = info->value;
                 }
             }

             ASTnode* currentArgNode = r;
             int paramIndex = 0;
             while (currentArgNode != nullptr && paramIndex < func->param.size()) {
                 ASTnode* argExpr = currentArgNode->l;
                 Data argVal = argExpr->evaluate(false);
                 
                 std::string pName = func->param[paramIndex].name;
                 IdInfo* pInfo = func->scope ? func->scope->lookup(pName) : nullptr;
                 if (pInfo) {
                     pInfo->value = transf(argVal);
                 }
                 
                 currentArgNode = currentArgNode->r;
                 paramIndex++;
             }
             
             Data result(TYPE::VOID, 0);
             if (func->body) {
                 Data bodyRes = func->body->evaluate();
                 if (bodyRes.type == TYPE::RETURN_VAL) {
                      result = transf(bodyRes.v.id->value); 
                 }
             }
             
             for (auto const& [info, val] : savedState) {
                 info->value = val;
             }
             
             return result;
         }
         
         if (data.get_char() == DECL_) {
             std::string* name = r->data.get_string();
             std::string* typeName = l->data.get_string();
             
             return Data(TYPE::VOID, 0); 
         }

         if (data.get_char() == PRINT)
         {
             lft = l->evaluate(false);
             if (lft.type == TYPE::INT) std::cout << lft.get_int() << std::endl;
             else if (lft.type == TYPE::FLOAT) std::cout << lft.get_float() << std::endl;
             else if (lft.type == TYPE::BOOL) std::cout << (lft.get_bool() ? "true" : "false") << std::endl;
             else if (lft.type == TYPE::STRING) std::cout << *lft.get_string() << std::endl;
             return lft;
         }

         if (data.get_char() == NOT_)
         {
             lft = l->evaluate(false);
             if (lft.type == TYPE::INT)
                 return Data(TYPE::BOOL, !lft.get_int());
             return Data(TYPE::BOOL, !lft.get_bool());
         }

         if (data.get_char() == UMINUS_)
         {
              lft = l->evaluate(false);
              if(lft.type == TYPE::INT) return Data(TYPE::INT , -lft.get_int());
              if(lft.type == TYPE::FLOAT) return Data(TYPE::FLOAT , -lft.get_float());

              std::cout << "Invalid type for unary minus";
              exit(1);
         }

         if (l) lft = l->evaluate(false);
         if (r) rgt = r->evaluate(false);
         return combine(lft , data.get_char() , rgt);
    }
    
    
    if(l != nullptr) lft =  l -> evaluate(false); 
    if(r != nullptr) rgt = r -> evaluate(false);
    
    if(data.type == ID_INFO)
    {
        assert(l == nullptr && r == nullptr);
        if (as_lvalue) {
            return Data(TYPE::ID_INFO, data.get_id_info());
        }
        return transf(data.get_id_info() -> value);
    }

    if(data.type == INT || data.type == FLOAT || data.type == BOOL || data.type == STRING || data.type == OBJECT)
    {
        assert(l == nullptr && r == nullptr);
        return data;
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

Data::Data(int type , SymbolTable *x)
{
    this -> type = type;
    this -> v.obj = x;
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

SymbolTable *Data::get_object()
{
    assert(type == TYPE::OBJECT);
    return v.obj;
}
