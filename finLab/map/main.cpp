#include <iostream>
#include "maze.h"

using namespace std;

int main()
{
    GameMap maze(4, 4);
    maze.printMaze();
    maze[0][1] = GridName::S;
    maze.printMaze();
    GameMap maze2(maze);
    maze2.printMaze();
    maze2.printGrid(1, 1);
    maze2.sumTrap(0, 1);
    maze2.sumTrap(1, 1);
    maze2.sumTrap(2, 1);
    GameMap maze3(2, 2, "1111");
    maze3.printMaze();
    return 0;
}
