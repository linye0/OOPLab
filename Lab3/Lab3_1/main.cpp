#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
    MyString str1("linye");
    MyString str2("Adam");
    MyString str4(str2);
    cout << "4" << str4 << endl;
    cout << str1 << endl;
    str1 += str2;
    cout << str1 << endl;
    char* strr = str2;
    cout << "strr" << strr << endl;
    MyString str3 = str1 + str2;
    cout << str3 << endl;
    return 0;
}
