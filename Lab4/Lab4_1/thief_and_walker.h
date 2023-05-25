#ifndef THIEF_AND_WALKER_H
#define THIEF_AND_WALKER_H

#include <iostream>

using namespace std;

class People
{
public:
    People(int money = 0) {
        mMoney = money;
    }
    void printMoney() {
        cout << mMoney << endl;
    }
    void changeMoney(int money) {
        mMoney += money;
    }
    int mMoney;
};

class Walker: public People
{
public:
    Walker(int money = 0) {
        mMoney = money;
    }
    void earnMoney(int money) {
        mMoney += money;
    }
    int reduceMoney() {
        int change = mMoney;
        mMoney = 0;
        return change;

    }
};

class Thief: public People
{
public:
    Thief(int money = 0) {
        mMoney = money;
    }
    void theftMoney(Walker& walker) {
        mMoney += walker.reduceMoney();
    }
};

#endif // THIEF_AND_WALKER_H
