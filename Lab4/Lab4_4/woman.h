#ifndef WOMAN_H
#define WOMAN_H

#include "man.h"
#include <iostream>
#include <string>
using namespace std;

class Man;

class Woman {
protected:
    std::string name;
    Man* man; // ’…∑Ú

public:
    Woman(const std::string& name);

    void marry(Man* man);

    void divorce();

    std::string getName() const {
        return name;
    }

    void knowsHusband();

    friend class Man;
};

#endif // WOMAN_H
