#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

using namespace std;

class Monster{
public:
    Monster(int speed, int hitpoint, int damage, int defense): mSpeed(speed), mHitpoint(hitpoint), mDamage(damage), mDefense(defense) {}
    void fight(Monster& oppo) {
        int first = 1;
        if (oppo.mSpeed > mSpeed) {
            first = -1;
        }else if (oppo.mSpeed == mSpeed && oppo.mHitpoint > mHitpoint) {
            first = -1;
        }else if (oppo.mSpeed == mSpeed && oppo.mHitpoint == mHitpoint && oppo.mDamage > mDamage) {
            first = -1;
        }else if (oppo.mSpeed == mSpeed && oppo.mHitpoint == mHitpoint && oppo.mDamage == mDamage && oppo.mDefense > mDefense) {
            first = -1;
        }
        while (mHitpoint > 0 && oppo.mHitpoint > 0) {
            int damage = 0;
            if (first > 0) {
                damage = 2 * mDamage - oppo.mDefense;
                if (damage < 1) damage = 1;
                oppo.mHitpoint -= damage;
            }else {
                damage = 2 * oppo.mDamage - mDefense;
                if (damage < 1) damage = 1;
                mHitpoint -= damage;
            }
            first *= -1;
            cout << "damage: " << damage << endl;
            cout << "mHitpoint1: " << mHitpoint << endl;
            cout << "mHitpoint2: " << oppo.mHitpoint << endl;
        }
        if (mHitpoint <= 0) {
            cout << "Monster2 wins!" << endl;
        } else {
            cout << "Monster1 wins!" << endl;
        }
    }
private:
    int mSpeed;
    int mHitpoint;
    int mDamage;
    int mDefense;
};

#endif // MONSTER_H
