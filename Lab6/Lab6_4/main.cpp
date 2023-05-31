#include <iostream>
#include "box.h"

using namespace std;

int main()
{
    Box box;
    Fruit* apple1 = new Apple(50);
    Fruit* orange1 = new Orange(100);
    Fruit* apple2 = new Apple(60);
    Fruit* orange2 = new Orange(40);
    box.addFruit(apple1);
    box.addFruit(orange1);
    box.addFruit(apple2);
    box.addFruit(orange2);
    cout << box.getAppleCount() << endl;
    cout << box.getOrangeCount() << endl;
    cout << box.getCurrentTotalWeight() << endl;
    cout << box.getTotalWeightReduced() << endl;
    cout << box.getCurrentTotalWeight() << endl;
    cout << box.getTotalWeightReduced() << endl;
    cout << box.getCurrentTotalWeight() << endl;

}
