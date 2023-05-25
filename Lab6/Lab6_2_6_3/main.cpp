#include <iostream>
#include "monster.h"

using namespace std;

int main()
{
    Monster* g1 = new Godzilla(300, 100, 50);
    Monster* g2 = new Godzilla(400, 85, 60);
    g1->fight(g2);
    Monster* cat = new Cat(300, 100, 50);
    Monster* dog = new Dog(400, 85, 60);
    cat->fight(dog);
    return 0;
}
