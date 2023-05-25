#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
using namespace std;

class Monster {
public:
    Monster(int hitpoint, int damage, int defense) : hitpoint(hitpoint), damage(damage), defense(defense) {}

    void fight(Monster* opponent) {
        while (this->hitpoint > 0 && opponent->hitpoint >= 0) {
            attack(opponent);
            opponent->attack(this);
        }
        if (this->hitpoint >= 0) {
            cout << "U win!" << endl;
        } else {
            cout << "Opponent win!" << endl;
        }
    }

    void adjustHitpoint(int n) {
        hitpoint += n;
    }

    int getDefense() {
        return defense;
    }

    virtual void attack(Monster* opponent) = 0;

protected:
    int hitpoint;
    int damage;
    int defense;
};

class Godzilla : public Monster {
public:
    Godzilla(int hitpoint, int damage, int defense) : Monster(hitpoint, damage, defense) {}
    virtual void attack(Monster* opponent) {
       int damage = -(this->damage - opponent->getDefense());
       if (damage < 0) {
            opponent->adjustHitpoint(damage);
       }
    }
};

class Cat : public Monster {
public:
    Cat(int hitpoint, int damage, int defense) : Monster(hitpoint, damage, defense) {}
    virtual void attack(Monster *opponent) {
        int damage = -(this->damage * 2 - opponent->getDefense());
        if (damage > -1) damage = -1;
        opponent->adjustHitpoint(damage);
    }
};

class Dog : public Monster {
public:
    Dog(int hitpoint, int damage, int defense) : Monster(hitpoint, damage, defense) {}
    virtual void attack(Monster *opponent) {
        int damage = -(this->damage - opponent->getDefense() + 5) * 2;
        if (damage > -2) damage = -2;
        opponent->adjustHitpoint(damage);
    }
};

#endif // MONSTER_H
