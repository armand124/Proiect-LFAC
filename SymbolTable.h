#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

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

        IdInfo();
        IdInfo(const std::string& t,const std::string& n, const std::string& c, const std::vector<ParamInfo>*);
};

class SymbolTable {
    private:
        SymbolTable* parent;
        std::map<std::string, IdInfo> ids;
        std::string name;
    public:
        SymbolTable(const std::string& name, SymbolTable* parent = nullptr);
        bool existsId(const std::string& s);
        IdInfo* lookup(const std::string& name);
        void addVar(const std::string& type, const std::string& name, const std::string& category, const std::vector<ParamInfo>* param = nullptr);
        void print(std::ostream& os);
        SymbolTable* getParent();
        static const std::vector<SymbolTable*>& getAllTables();
        ~SymbolTable();
        static SymbolTable* class_lookup(const std::string &name , std::map < std::string , SymbolTable* > &classes);
    private:
        static std::vector<SymbolTable*> allTables;
};
