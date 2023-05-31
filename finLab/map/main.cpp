#include <iostream>
#include "maze.h"

using namespace std;

int main()
{
    // 1���������µ�ͼ����map0������ʾ���п�����
    GameMap map0(4, 4, "0123012301230123");
    map0.show();
    // 2�����ÿ������캯������map0����һ����Ϸ��ͼָ��GameMap *map1��
    GameMap* map1 = new GameMap(map0);
    // 3����ʾmap1���п�
    map0.show();
    // 4�����ã�0��0����Ϊ��ɳ���͡���������ʾmap0���п飻
    map0.setGrid(0, 0, 'S');
    map0.show();
    // 5����ʾ��1��1��������͡�
    map0.printGrid(1, 1);
    // 6����ʾ��0��0�������Χ��������
    map0.sumTrap(0, 0);
    // 7����ʾ��0��1�������Χ��������
    map0.sumTrap(0, 1);
    // 8����ʾ��1��1�������Χ��������
    map0.sumTrap(1, 1);
    // 9����ʾ��3��2�������Χ��������
    map0.sumTrap(3, 2);
    // 10����ʾ��3��3�������Χ��������
    map0.sumTrap(3, 3);
    // 11������½�ؿ����ʾ��ʽΪ�ַ�A
    GameMap::setGridName('L', 'A');
    // 12��������ʾmap0�����п顣
    map0.show();
    // 13��������ʾmap1�����п顣
    map1->show();
    // ��ӡ������Ϣ
    // map1->printInfo();
    // 14.ɾ��map1
    delete map1;
}
