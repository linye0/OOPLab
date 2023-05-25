#ifndef WALL_AND_DOOR_H
#define WALL_AND_DOOR_H

#include <iostream>

using namespace std;

class Wall
{
public:
    Wall():color(0) { cout<<"����һ��ǽ"<<endl;}
    void Paint(int newColor) {
           color = newColor;
           cout<<"������ɫ��ˢǽ"<<endl;
    }
    int GetColor() const {return color;}
private:
    int  color;
};

class Door
{
public:
     Door():openOrClose(false) { cout<<"����һ����"<<endl;}
     void Open() {
        if (!IsOpened( )){
              openOrClose = true;
              cout<<"�ű�����"<<endl;
        }else{
          cout<<"�ſ����أ�"<<endl;
        }
     }
     void Close() {
        if ( IsOpened( ) ) {
              openOrClose = false;
              cout<<"�ű�������"<<endl;
        }else{
          cout<<"�Ź����أ�"<<endl;
        }
     }
     bool IsOpened() const { return openOrClose;}
private:
     bool openOrClose;
};

class WallWithDoor : public Wall, public Door{
public:
    WallWithDoor() {}
    void newPaint(int newColor) {
        Paint(newColor);
        if (GetColor() == 1) {
            Close();
        } else if (GetColor() == 2) {
            Open();
        }
    }
};

class WallWithDoorSingle : public Wall{
public:
    WallWithDoorSingle() {}
    void newPaint(int newColor) {
        Paint(newColor);
        if (GetColor() == 1) {
            door.Close();
        } else if (GetColor() == 2) {
            door.Open();
        }
    }
    bool isOpened() const {
        return door.IsOpened();
    }
private:
    Door door;
};

class WallWithDoorHorizon {
public:
    WallWithDoorHorizon() : wall(), door() { cout << "����һ����ŵ�ǽ" << endl; }

    void Paint(int newColor)
    {
        if (newColor == 0)
        {
            door.Close();
        }
        else if (newColor == 1)
        {
            door.Open();
        }

        wall.Paint(newColor);
    }

    bool isOpened() const {
        return door.IsOpened();
    }
private:
    Wall wall;
    Door door;
};

#endif // WALL_AND_DOOR_H
