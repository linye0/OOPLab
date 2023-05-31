#include <iostream>
#include "maze.h"

using namespace std;

int main()
{
    // 1、生成如下地图对象map0，并显示所有块如下
    GameMap map0(4, 4, "0123012301230123");
    map0.show();
    // 2、利用拷贝构造函数，从map0拷贝一个游戏地图指针GameMap *map1；
    GameMap* map1 = new GameMap(map0);
    // 3、显示map1所有块
    map0.show();
    // 4、设置（0，0）块为流沙类型。并重新显示map0所有块；
    map0.setGrid(0, 0, 'S');
    map0.show();
    // 5、显示（1，1）块的类型。
    map0.printGrid(1, 1);
    // 6、显示（0，0）块的周围陷阱数。
    map0.sumTrap(0, 0);
    // 7、显示（0，1）块的周围陷阱数。
    map0.sumTrap(0, 1);
    // 8、显示（1，1）块的周围陷阱数。
    map0.sumTrap(1, 1);
    // 9、显示（3，2）块的周围陷阱数。
    map0.sumTrap(3, 2);
    // 10、显示（3，3）块的周围陷阱数。
    map0.sumTrap(3, 3);
    // 11、设置陆地块的显示方式为字符A
    GameMap::setGridName('L', 'A');
    // 12、重新显示map0的所有块。
    map0.show();
    // 13、重新显示map1的所有块。
    map1->show();
    // 打印陷阱信息
    // map1->printInfo();
    // 14.删除map1
    delete map1;
}
