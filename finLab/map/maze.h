#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class GameMap{
public:
    // 打印当前各格子类型的名字
    static void printGirdName();
    // 设置类型的显示名称
    static void setGridName(string newNames);
    static void setGridName(int i, char newName);
    static void setGridName(char oldName, char newName);
    // 构造函数
    GameMap(int row, int col, int type = 0) : row(row), col(col){
        map = new int*[row];
        for (int i = 0; i < row; i++) {
            map[i] = new int[col];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                map[i][j] = type;
            }
        }
    }
    GameMap(int row, int col, string inputMap) : row(row), col(col) {
        map = new int*[row];
        for (int i = 0; i < row; i++) {
            map[i] = new int[col];
        }
        for (int pos = 0; pos < row * col; pos++) {
            int curRow = pos / col;
            int curCol = pos % col;
            map[curRow][curCol] = inputMap[pos] - '0';
        }
    }
    // 拷贝构造
    GameMap(const GameMap& other) {
        row = other.getRow();
        col = other.getCol();
        map = new int*[row];
        for (int i = 0; i < row; i++) {
            map[i] = new int[col];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                map[i][j] = other.getGrid(i, j);
            }
        }
        cout << "copy structor call" << endl;
        cout << endl;
    }
    // 析构函数
    ~GameMap() {
        for (int i = 0; i < row; i++) {
            delete[] map[i];
        }
        delete[] map;
        cout << "destructor call" << endl << endl;
    }
    // 查看对象的一些信息
    int getRow() const {return row;}
    int getCol() const {return col;}
    int getGrid(int row, int col) const {return map[row][col];}
    void printGrid(int row, int col) {
        printf("(%d, %d)type is %c\n\n", row, col, GameMap::gridName[map[row][col]]);
    }
    // 打印整个地图
    void show();
    // 打印某一个旁边的陷阱数
    void sumTrap(int row, int col);
    // 打印总的陷阱信息（数量总和及部分数量）
    void printInfo();
    // 更改单元格
    void setGrid(int row, int col, char newGrid);
    void setGrid(int row, int col, int newGrid) {map[row][col] = newGrid;}
    // 不允许赋值
    GameMap* operator=(const GameMap& other) = delete;
    int* operator[](int i) {return map[i];}
private:
    int** map;
    int row;
    int col;
    static vector<char> gridName;
};

enum GridName {
    L,
    S,
    P,
    M
};

#endif // MAZE_H
