#include "SymbolTable.h"
#include <iostream>
#include <cassert>
#include "helper.h"


extern int yylineno;

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
            printf("%d: Function %s expects %s on the %d-th parameter" , yylineno , f_name.c_str() , f_param[i].type.c_str() , i + 1);
            exit(1);
        }

    }

    return true;
}


IdInfo::IdInfo() : type(""), name(""), category(""), return_type("") , value(DataId(TYPE::INT , 0)), body(nullptr), scope(nullptr) {}

IdInfo::IdInfo(const std::string& t, const std::string& n, const std::string& c, const std::vector<ParamInfo>* p , DataId value, ASTnode* body, SymbolTable* scope) 
    : type(t), name(n), category(c) , value(value), body(body), scope(scope) {
    
    return_type = (c == "function" ? t : "");
    
    if(return_type != "" && p != nullptr)
        param = *p;
}

std::vector<SymbolTable*> SymbolTable::allTables;
std::map<std::string, SymbolTable*> SymbolTable::classes;

SymbolTable::SymbolTable(const std::string& n, SymbolTable* p) : name(n), parent(p) {
    allTables.push_back(this);
}

SymbolTable::~SymbolTable() {
    ids.clear();
}

bool SymbolTable::existsId(const std::string& s) {
    return ids.find(s) != ids.end();
}

DataId decide_default_value(std::string type)
{
    if(type == "INT") return DataId(INT , 0);
    if(type == "FLOAT") return DataId(FLOAT , 0);
    if(type == "BOOL") return DataId(BOOL , 0);
    if(type == "STRING" || type == "STR") return DataId(STRING , new std::string);
    return DataId(INT , 0); 
}

void SymbolTable::addVar(const std::string& type, const std::string& name, const std::string& category,const std::vector<ParamInfo>* param, ASTnode* body, SymbolTable* scope) {
    if (existsId(name)) {
        std::cout << yylineno << ": " <<  "Variable already declared in the current scope " << name;
        exit(1);
    }


    IdInfo info(type, name, category, param , decide_default_value(type), body, scope);

    ids[name] = info;
}

void SymbolTable::print(std::ostream& os) {
    os << "=== Scope: " << name << " ";
    if (parent != NULL) {
        os << "(Parent: " << parent->name << ")";
    } else {
        os << "(Global)";
    }
    os << " ===" << std::endl;

    for (auto it = ids.begin(); it != ids.end(); ++it) {
        auto info = it->second;
        
        os << "  Name: " << info.name 
                  << " | Type: " << info.type 
                  << " | Category: " << info.category;

        if (info.category == "function" && !info.param.empty()) {
            os << " | Params: (";
            for (size_t i = 0; i < info.param.size(); ++i) {
                os << info.param[i].type << " " << info.param[i].name;
                if (i < info.param.size() - 1) os << ", ";
            }
            os << ")";
        }
        os << std::endl;
    }
    os << "================================" << std::endl << std::endl;
}

const std::vector<SymbolTable*>& SymbolTable::getAllTables() {
    return allTables;
}

SymbolTable* SymbolTable::getParent() {
    return parent;
}

IdInfo* SymbolTable::lookup(const std::string& searchName) {
    if (ids.count(searchName)) {
        return &ids.at(searchName);
    }

    if (parent != nullptr) {
        return parent->lookup(searchName);
    }

    return nullptr;
}

SymbolTable* SymbolTable::class_lookup(const std::string &name , std::map < std::string , SymbolTable* > &classes)
{
    if(classes.count(name) == 0)
        return nullptr;

    return classes.find(name) -> second;
}

SymbolTable* SymbolTable::getClass(const std::string& name) {
    if (classes.find(name) != classes.end())
        return classes[name];
    return nullptr;
}

void SymbolTable::addClass(const std::string& name, SymbolTable* table) {
    classes[name] = table;
}

void SymbolTable::instantiate(SymbolTable* instance) {
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        IdInfo info = it->second;
        if (info.category == "field") {
             instance->addVar(info.type, info.name, "field", nullptr, nullptr);
             IdInfo* newInfo = instance->lookup(info.name);
             if (newInfo) newInfo->value = info.value;
        }
    }
}

std::string SymbolTable::get_scope_name() 
{
    return name;
}

DataId::DataId() : type(TYPE::INT) { v.x = 0; }
DataId::DataId(int type , int x)
{
    this -> type = type;
    this -> v.x = x;
}

DataId::DataId(int type , float x)
{
    this -> type = type;
    this -> v.y = x;
}

DataId::DataId(int type , bool x)
{
    this -> type = type;
    this -> v.z = x;
}

DataId::DataId(int type , std::string *x )
{
    this -> type = type;
    this -> v.s = x;
}

DataId::DataId(int type , SymbolTable *x)
{
    this -> type = type;
    this -> v.obj = x;
}

int DataId::get_int()
{
    assert(type == TYPE::INT);
    return v.x;
}

float DataId::get_float()
{
    assert(type == TYPE::FLOAT);
    return v.y;
}

bool DataId::get_bool()
{
    assert(type == TYPE::BOOL);
    return v.z;
}

std::string *DataId::get_string()
{
    assert(type == TYPE::STRING);
    return v.s;
}

SymbolTable *DataId::get_object()
{
    assert(type == TYPE::OBJECT);
    return v.obj;
}