#ifndef MARRIAGE_H
#define MARRIAGE_H

#include <iostream>
#include <string>
using namespace std;

class Woman; // 前向声明

class Man {
protected:
    std::string name;
    Woman* woman; // 妻子

public:
    Man(const std::string& name) : name(name), woman(nullptr) {}

    void marry(Woman* woman) {
        if (this->woman == nullptr && woman->man == nullptr) {
            this->woman = woman;
            woman->man = this;
            std::cout << name << " and " << woman->getName() << " got married." << std::endl;
        }
    }

    void divorce() {
        if (woman != nullptr) {
            std::cout << name << " divorced " << woman->getName() << "." << std::endl;
            woman->man = nullptr;
            woman = nullptr;
        }
    }

    std::string getName() const {
        return name;
    }

    void knowsWife() {
        if (woman != nullptr) {
            std::cout << name << " knows his wife " << woman->getName() << "." << std::endl;
        }
    }

    friend class Woman;
};

class Woman {
protected:
    std::string name;
    Man* man; // 丈夫

public:
    Woman(const std::string& name) : name(name), man(nullptr) {}

    void marry(Man* man) {
        if (this->man == nullptr && man->woman == nullptr) {
            this->man = man;
            man->woman = this;
            std::cout << name << " and " << man->getName() << " got married." << std::endl;
        }
    }

    void divorce() {
        if (man != nullptr) {
            std::cout << name << " divorced " << man->getName() << "." << std::endl;
            man->woman = nullptr;
            man = nullptr;
        }
    }

    std::string getName() const {
        return name;
    }

    void knowsHusband() {
        if (man != nullptr) {
            std::cout << name << " knows her husband " << man->getName() << "." << std::endl;
        }
    }

    friend class Man;
};

#endif // MARRIAGE_H
