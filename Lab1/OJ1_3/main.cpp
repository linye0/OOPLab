#include <iostream>
#include "a.h"
#include "b.h"

using namespace std;

int main(int argc, char* argv[])
{
    A aA;

    if (argc>1) {
        aA.Display(argv[1]);
    } else {
        aA.Display();
    }

    cout<<sizeof(A)<<endl;

    B bB(aA);

    bB.Func();

    bB.NewFunc();

    A::setA();

    A::addA(1);

    A::showA();

    aA.setAObj();

    return 0;
}
