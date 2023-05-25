#include <iostream>
#include "a.h"

using namespace std;

void g(int n) {
    A** arr = new A*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new A(i + 1);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i]->Data() << endl;
    }
    // ÊÍ·ÅÊý×é
    for (int i = 0; i < n; i++) {
        delete arr[i];
    }
    delete[] arr;
}

int main()
{
    g(10);
    return 0;
}
