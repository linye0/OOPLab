#ifndef POLICE_H
#define POLICE_H

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

class PoliceOffice
{
public:
    PoliceOffice(int fund = 0, int fame = 0) {
        mFund = fund;
        mFame = fame;
    }
    void changeFund(int change) {
        mFund += change;
    }
    void changeFame(int change) {
        mFame += change;
    }
    void setFund(int fund) {
        mFund = fund;
    }
    void show() {
        cout << "Fame:" << mFame << endl;
        cout << "Fund:" << mFund << endl;
    }
private:
    int mFame;
    int mFund;
};

class Police: public People
{
public:
    Police(PoliceOffice* policeOffice, int money = 0) {
        mMoney = money;
        mPoliceOffice = policeOffice;
    }
    void caughtThief(Thief& thief) {
        mMoney += 100;
        mPoliceOffice->changeFame(1);
        mPoliceOffice->changeFund(thief.mMoney);
        thief.mMoney = 0;
    }
private:
    PoliceOffice* mPoliceOffice;
};

#endif // POLICE_H
