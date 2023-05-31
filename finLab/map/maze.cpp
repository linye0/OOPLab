#include "maze.h"
#include <vector>
#include <string>

using namespace std;

vector<char> GameMap::gridName = {'L', 'S', 'P', 'M'};

void GameMap::printGirdName(){
    for (auto i : GameMap::gridName) {
        cout << i << endl;
    }
}

void GameMap::setGridName(string newNames){
    for (int i = 0; i < 4; i++) {
        gridName[i] = newNames[i];
    }
}

void GameMap::setGridName(int i, char newName) {
    GameMap::gridName[i] = newName;
}

void GameMap::setGridName(char oldName, char newName) {
    for (int i = 0; i < 4; i++) {
        if (gridName[i] == oldName) gridName[i] = newName;
    }
}

void GameMap::show() {
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

void GameMap::sumTrap(int row, int col) {
    int sum = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue;
            if (i < this->row && i >= 0 && j < this->col && j >= 0 && map[i][j] != 0) sum++;
        }
    }
    printf("(%d, %d)around trapCount is %d\n\n", row, col, sum);
}

void GameMap::setGrid(int row, int col, char newGrid) {
    int num = 0;
    for (int i = 0; i < 4; i++) {
        if (newGrid == GameMap::gridName[i]) {
            num = i;
            break;
        }
    }
    map[row][col] = num;
}

void GameMap::printInfo() {
    int sum[4] = {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] != 0) {
                sum[0]++;
                sum[map[i][j]]++;
            }
        }
    }
    cout << "Map Info:" << endl;
    cout << "Trap: " << sum[0] << endl << "Sand Trap: " << sum[1] << endl << "Pit Trap: " << sum[2] << endl << "Mine Trap: " << sum[3] << endl << endl;
}
