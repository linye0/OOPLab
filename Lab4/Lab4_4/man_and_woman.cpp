#include "man.h"
#include "woman.h"

Man::Man(const std::string& name) : name(name), woman(nullptr) {}

void Man::marry(Woman *woman) {
    if (this->woman == nullptr && woman->man == nullptr) {
        this->woman = woman;
        woman->man = this;
        std::cout << name << " and " << woman->getName() << " got married." << std::endl;
    }
}

void Man::divorce() {
    if (this->woman == nullptr && woman->man == nullptr) {
        this->woman = woman;
        woman->man = this;
        std::cout << name << " and " << woman->getName() << " got married." << std::endl;
    }
}

void Man::knowsWife() {
    if (woman != nullptr) {
        std::cout << name << " knows his wife " << woman->getName() << "." << std::endl;
    }
}

Woman::Woman(const std::string& name) : name(name), man(nullptr) {}

void Woman::marry(Man* man) {
    if (this->man == nullptr && man->woman == nullptr) {
        this->man = man;
        man->woman = this;
        std::cout << name << " and " << man->getName() << " got married." << std::endl;
    }
}

void Woman::divorce() {
    if (man != nullptr) {
        std::cout << name << " divorced " << man->getName() << "." << std::endl;
        man->woman = nullptr;
        man = nullptr;
    }
}

void Woman::knowsHusband() {
    if (man != nullptr) {
        std::cout << name << " knows her husband " << man->getName() << "." << std::endl;
    }
}
