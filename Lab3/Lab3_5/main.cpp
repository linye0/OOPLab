#include <iostream>
#include "dynamic_array.h"

using namespace std;

int main()
{
    DynamicArray a(3, 4);
    a[1][2] = 1;
    a[2][3] = 2;
    const DynamicArray & ra = a;
    ra[1][2];
    cout << a[1][2] << endl;
    cout << a[2][3] << endl;
    return 0;
}
