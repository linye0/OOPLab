#include <iostream>

#include "Card.h"
using namespace std;

int main()
{
    int pos1[] = {3, 4};
    Card card1(1, 0, 3, 10, 10, pos1);
    card1.info();
    int pos2[] = {4, 5};
    Card card2(1, 2, 4, 10, 10, pos2);
    card2.info();
    int pos3[] = {5, 6};
    card2.setPos(pos3);
    card2.info();
    card2.oppoPos();
    cout << card1.checkSameID(card2) << endl;
    cout << card1.checkSameSuit(card2) << endl;
    cout << card1.checkSameRank(card2) << endl;
    cout << card1.checkID(1) << endl;
    cout << card1.checkSuit(1) << endl;
    cout << card1.checkRank(1) << endl;
    Card copyCard(card2);
    copyCard.info();
    return 0;
}
