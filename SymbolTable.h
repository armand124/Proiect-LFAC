#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "helper.h"

class SymbolTable;
class ASTnode;

union valueId
{
    int x;
    float y;
    bool z;
    std::string *s;
    SymbolTable *obj;
};

struct DataId
{
    int type;
    valueId v;
    
    DataId();
    DataId(int type , int x);
    DataId(int type , float x);
    DataId(int type , bool x);
    DataId(int type , std::string *x );
    DataId(int type , SymbolTable *x);
    
    int get_int();
    float get_float();
    bool get_bool();
    std::string *get_string();
    SymbolTable *get_object();
};

struct ParamInfo{
    std::string type;
    std::string name;

    ParamInfo(const std::string& t, const std::string& n) : type(t), name(n) {}
};

class IdInfo {
    public:
        std::string type;
        std::string name;
        std::string category;
        std::string return_type;
        std::vector<ParamInfo>param;
        DataId value;
        ASTnode* body;
        SymbolTable* scope;

        IdInfo();
        IdInfo(const std::string& t,const std::string& n, const std::string& c, const std::vector<ParamInfo>* , DataId value = DataId(TYPE::INT , 0), ASTnode* body = nullptr, SymbolTable* scope = nullptr);
};

class SymbolTable {
    public:
        std::map<std::string, IdInfo> ids;
    private:
        SymbolTable* parent;
        std::string name;
        static std::map<std::string, SymbolTable*> classes;
    public:
        SymbolTable(const std::string& name, SymbolTable* parent = nullptr);
        bool existsId(const std::string& s);
        IdInfo* lookup(const std::string& name);
        void addVar(const std::string& type, const std::string& name, const std::string& category, const std::vector<ParamInfo>* param = nullptr, ASTnode* body = nullptr, SymbolTable* scope = nullptr);
        void print(std::ostream& os);
        SymbolTable* getParent();
        static const std::vector<SymbolTable*>& getAllTables();
        ~SymbolTable();
        static SymbolTable* class_lookup(const std::string &name , std::map < std::string , SymbolTable* > &classes);
        static SymbolTable* getClass(const std::string& name);
        static void addClass(const std::string& name, SymbolTable* table);
        void instantiate(SymbolTable* instance);
        std::string get_scope_name();
    private:
        static std::vector<SymbolTable*> allTables;
};

std::string check_matching_types(std::string type1 , std::string type2);
bool check_func_parameters(std::string f_name , std::vector < ParamInfo > &f_param , std::vector < std::string > &c_param);
