#include <iostream>
#include "Monster.h"

using namespace std;

int main()
{
    Monster m1(200, 300, 60, 85);
    Monster m2(300, 300, 45, 95);
    m1.fight(m2);
    return 0;
}
