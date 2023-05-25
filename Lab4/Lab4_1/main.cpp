#include <iostream>
#include <thief_and_walker.h>

using namespace std;

int main()
{
    Thief thief;
    Walker walker1(100);
    walker1.printMoney();
    thief.printMoney();
    thief.theftMoney(walker1);
    walker1.printMoney();
    thief.printMoney();
    return 0;
}
