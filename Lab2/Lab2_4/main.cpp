#include <iostream>
#include "hero.h"

using namespace std;

int main()
{
    Hero hero;
    hero.display();
    hero.carry_treasure(2);
    hero.display();
    hero.carry_treasure(1);
    hero.display();
    hero.carry_treasure(3);
    hero.display();
    hero.discard_treasure(0);
    hero.display();
    return 0;
}
