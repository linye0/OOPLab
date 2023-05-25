#include <iostream>

using namespace std;

void f(int n, int m) {
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    int num = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = num++;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    // 行求和
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        cout << "row" << i << ": " << sum << endl;
    }

    // 列求和
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][j];
        }
        cout << "col" << j << ":" << sum << endl;
    }

   for (int i = 0; i < n; i++) {
       delete[] a[i];
   }
   delete[] a;
}

int main()
{
    f(5, 6);
    return 0;
}
