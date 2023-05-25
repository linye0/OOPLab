#ifndef MAN_H
#define MAN_H

#include "woman.h"
#include <iostream>
#include <string>
using namespace std;

class Woman; // 前向声明

class Man {
protected:
    std::string name;
    Woman* woman; // 妻子

public:
    Man(const std::string& name);

    void marry(Woman* woman);

    void divorce();

    std::string getName() const {
        return name;
    }

    void knowsWife();

    friend class Woman;
};

#endif // MAN_H
