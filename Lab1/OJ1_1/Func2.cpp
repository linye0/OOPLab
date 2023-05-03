#include <iostream>
#include "Func1.h"
#include "Func2.h"

int g1(int num)
{
     return num*num;
}

int g2(int num)
{
    return f1(num*3);
}
