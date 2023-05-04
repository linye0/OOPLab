#include <iostream>
#include "Demo.h"

using namespace std;

Demo* Demo::mInstance = nullptr;

int main()
{
    Demo* demo = Demo::getInstance();
    demo->showValue();
    demo->addValue(10);
    demo->showValue();
    Demo* demo2 = Demo::getInstance();
    demo2->showValue();
    return 0;
}
