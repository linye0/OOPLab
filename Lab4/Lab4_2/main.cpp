#include <iostream>
#include <police.h>

using namespace std;

int main()
{
    PoliceOffice policeOffice(0, 100);
    Police p1(&policeOffice), p2(&policeOffice), p3(&policeOffice), p4(&policeOffice);
    Thief t1(500), t2(800), t3(300), t4(1000);
    p1.caughtThief(t2);
    p1.caughtThief(t3);
    p2.caughtThief(t4);
    policeOffice.show();
    p1.printMoney();
    p2.printMoney();
    p3.printMoney();
    p4.printMoney();
    return 0;
}
