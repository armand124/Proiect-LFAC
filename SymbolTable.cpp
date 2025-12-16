#include "SymbolTable.h"
#include <iostream>

//Fallback constructor
IdInfo::IdInfo() : type(""), name(""), category(""), return_type("") {}

// Constructor general t -> type, n -> name, c -> category, p-> parameters (optional)
IdInfo::IdInfo(const std::string& t, const std::string& n, const std::string& c, const std::vector<ParamInfo>* p) 
    : type(t), name(n), category(c) {
    
    return_type = (c == "function" ? t : "");
    
    if(return_type != "")
        param = *p;
}

// Constructor
SymbolTable::SymbolTable(const std::string& n, SymbolTable* p) : name(n), parent(p) {}

// Destructor
SymbolTable::~SymbolTable() {
    ids.clear();
}

bool SymbolTable::existsId(const std::string& s) {
    return ids.find(s) != ids.end();
}

void SymbolTable::addVar(const std::string& type, const std::string& name, const std::string& category,const std::vector<ParamInfo>* param) {
    if (existsId(name)) {
        throw std::runtime_error("Error, element already in current scope");
    }

    IdInfo info(type, name, category, param);

    ids[name] = info;
}

void SymbolTable::printVars() {
    std::cout << "=== Scope: " << name << " ";
    if (parent != NULL) {
        std::cout << "(Parent: " << parent->name << ")";
    } else {
        std::cout << "(Global)";
    }
    std::cout << " ===" << std::endl;

    for (auto it = ids.begin(); it != ids.end(); ++it) {
        auto info = it->second;
        
        std::cout << "  Name: " << info.name 
                  << " | Type: " << info.type 
                  << " | Category: " << info.category;

        if (info.category == "function" && !info.param.empty()) {
            std::cout << " | Params: (";
            for (size_t i = 0; i < info.param.size(); ++i) {
                std::cout << info.param[i].type << " " << info.param[i].name;
                if (i < info.param.size() - 1) std::cout << ", ";
            }
            std::cout << ")";
        }
        std::cout << std::endl;
    }
    std::cout << "================================" << std::endl << std::endl;
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