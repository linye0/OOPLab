#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class GameMap{
public:
    static void printGirdName(){
        for (auto i : GameMap::gridName) {
            cout << i << endl;
        }
    }
    static void setGridName(string newNames){
        for (int i = 0; i < 4; i++) {
            gridName[i] = newNames[i];
        }
    }
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
    }
    ~GameMap() {
        for (int i = 0; i < row; i++) {
            delete[] map[i];
        }
        delete[] map;
    }
    int getRow() const {return row;}
    int getCol() const {return col;}
    int getGrid(int row, int col) const {return map[row][col];}
    void printGrid(int row, int col) {
        cout << GameMap::gridName[map[row][col]] << endl;
    }
    void printMaze() {
        printf("  ");
        for (int i = 0; i < col; i++) {
            printf("%d ", i);
            if (i == col - 1) printf("\n");
        }
        for (int i = 0; i < row; i++) {
            printf("%d ", i);
            for (int j = 0; j < col; j++) {
                char name = GameMap::gridName[map[i][j]];
                printf("%c ", name);
            }
            printf("\n");
        }
        cout << endl;
    }
    GameMap* operator=(const GameMap& other) {
        if (this != &other) {

        }
        return this;
    }
    void sumTrap(int row, int col) {
        int sum = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (i == row && j == col) continue;
                if (i < this->row && i >= 0 && j < this->col && j >= 0 && map[i][j] != 0) sum++;
            }
        }
        cout << sum << endl;
    }
    int* operator[](int i) {
        return map[i];
    }

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
