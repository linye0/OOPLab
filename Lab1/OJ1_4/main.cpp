#include <iostream>
#include "Classes.h"

using namespace std;

int main()
{
    Pen pen;
    pen.write();
    FountainPen fountainPen;
    fountainPen.write();
    fountainPen.showInk();
    Directory dir;
    dir.addFile("Linye");
    dir.addFile("hahaha");
    dir.showFile();
    Sky sky(100, 0);
    sky.show();
    sky.moonRise(100);
    sky.show();
}
