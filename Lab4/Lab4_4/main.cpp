#include <iostream>
#include "man.h"
#include "woman.h"

using namespace std;

int main()
{
    Man john("John");
        Woman jane("Jane");

        john.marry(&jane);
        jane.knowsHusband();
        john.knowsWife();

        john.divorce();
        jane.divorce();
    return 0;
}
