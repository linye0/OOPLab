#include <iostream>
#include "a_and_b.h"

using namespace std;

int main()
{
    B b(1,2);
    b.f();
    b.g();
    b.f(3);
    b.h();
    cout << "---------" << endl;
    A* pA = new B(1, 2);
    B* pB = new B(1, 2);
    pA->f();
    pB->f();
    //pA->f(1);
    pA->g();
    //pA->h();
    delete(pA);
    delete(pB);
}
