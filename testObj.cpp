#include<iostream>
//#include "Coordinate.h"
#include "Maze.h"

int main() {
 Coordinate coord (5, 4, '#');
 Maze newMaze;
 std::string filename = "maze_1.txt";

 newMaze.loadMaze(filename);
 newMaze.printMaze();

 std::cout << "\n";
 std::cout << coord.getX() << ", " << coord.getY() << ", " << coord.getTile() << std::endl;

 return 0;
}
