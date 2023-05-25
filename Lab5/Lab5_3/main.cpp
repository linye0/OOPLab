#include <iostream>
#include "wall_and_door.h"

using namespace std;

int main()
{
    WallWithDoor wallWithDoor;
    wallWithDoor.GetColor();
    wallWithDoor.newPaint(1);
    wallWithDoor.newPaint(2);
    WallWithDoorSingle wallWithDoorSingle;
    wallWithDoorSingle.GetColor();
    wallWithDoorSingle.newPaint(1);
    wallWithDoorSingle.newPaint(2);
    cout << wallWithDoorSingle.isOpened() << endl;
    return 0;
}
