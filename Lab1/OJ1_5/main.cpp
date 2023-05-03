#include <iostream>
#include <vector>
#include <cmath>

#include "TRandom.h"
using namespace std;

int isInDistance(float r, float x, float y) {
    if (pow(x, 2) + pow(y, 2) <= r) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    TRandom Rnd(114514);
    vector<int> a;
    for (int i = 0; i < 54; i++) {
        a.push_back(i);
    }
    int flag[54] = {0};
    vector<int>::iterator i;
    vector<int> deck;
    while (deck.size() != 54) {
        int card = a[Rnd.Integer(0, 53)];
        if (!flag[card]) {
            flag[card] = 1;
            deck.push_back(card);
        }
    }
    for (i = deck.begin(); i != deck.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // Í¶Õë·¨¹ÀËãPI

    int N = 1000000000;
    int M = 0;
    for (int i = 0; i < N; i++) {
        float x = Rnd.Real();
        float y = Rnd.Real();
        M += isInDistance(1, x, y);
    }
    cout << 4.0 * M / N << endl;
    return 0;
}
