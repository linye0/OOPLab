#include <iostream>
#include <map>
#include <vector>

#include "Dice.h"
#include "TRandom.h"

using namespace std;

int main()
{
    Dice dice(114514);
    dice.roll();
    dice.show();
    return 0;
}
