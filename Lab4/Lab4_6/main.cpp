#include <iostream>
#include "a.h"

using namespace std;

int main()
{
    A* a = new A(10);
    delete a;
    A* b = new A[10];
    delete[] b;
    return 0;
}
