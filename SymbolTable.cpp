#include "SymbolTable.h"
#include <iostream>

extern int yylineno;

//Fallback constructor
IdInfo::IdInfo() : type(""), name(""), category(""), return_type("") {}

// Constructor general t -> type, n -> name, c -> category, p-> parameters (optional)
IdInfo::IdInfo(const std::string& t, const std::string& n, const std::string& c, const std::vector<ParamInfo>* p) 
    : type(t), name(n), category(c) {
    
    return_type = (c == "function" ? t : "");
    
    if(return_type != "")
        param = *p;
}

std::vector<SymbolTable*> SymbolTable::allTables;

// Constructor
SymbolTable::SymbolTable(const std::string& n, SymbolTable* p) : name(n), parent(p) {
    allTables.push_back(this);
}

// Destructor
SymbolTable::~SymbolTable() {
    ids.clear();
}

bool SymbolTable::existsId(const std::string& s) {
    return ids.find(s) != ids.end();
}

void SymbolTable::addVar(const std::string& type, const std::string& name, const std::string& category,const std::vector<ParamInfo>* param) {
    if (existsId(name)) {
        std::cout << yylineno << ": " <<  "Variable already declared in the current scope " << name;
        exit(1);
    }

    IdInfo info(type, name, category, param);

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