#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <map>
#include <vector>

#include "TRandom.h"

using namespace std;

class Dice
{
public:
    Dice(int seed = 114514):rnd(seed) {
    }
    vector<int> findAdjacedSides(int i) {
        return adjacedSide[i];
    }
    void rollAndShow() {
        roll();
        show();
    }
    void roll() {
        upper = rnd.Integer(1, 6);
    }
    void show() {
        if (upper == 0) {
            cout << "����������" << endl;
            return;
        }
        cout << "������" << upper << endl;
        cout << "�м���ֱ���";
        for (int i = 0; i < adjacedSide[upper].size(); ++i) {
            cout << adjacedSide[upper][i] << " ";
        }
        cout << endl;
        cout << "������" << oppositeSide[upper] << endl;
    }
private:
    TRandom rnd;
    map<int, vector<int>> adjacedSide = {
        {1, {2, 3, 4, 5}},
        {2, {1, 3, 4, 6}},
        {3, {1, 2, 5, 6}},
        {4, {1, 2, 5, 6}},
        {5, {1, 3, 4, 6}},
        {6, {2, 3, 4, 5}}
    };
    int upper = 0;
    map <int, int> oppositeSide = {
        {1, 6},
        {2, 5},
        {3, 4},
        {4, 3},
        {5, 2},
        {6, 1}
    };
};

#endif // DICE_H
