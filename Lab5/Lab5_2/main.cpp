#include <iostream>
#include "a.h"

using namespace std;

int main()
{
    C c(100, 200, 300);
    c.MyFuncs();
    C cc(100, 300, 500);
    c = cc;
    c.MyFuncs();
    return 0;
}
