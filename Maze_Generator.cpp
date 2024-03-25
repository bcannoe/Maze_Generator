// Blake Cannoe
// Maze Generator V0.1
// A program that will generate a maze of a size specified by the user.
// After the maze is generated it will be sent to text file as well as displayed on the console.
// This program will make use of graph theory concepts as well as objects in C++

#include "Maze.h"
//#include "Coordinate.h"

Coordinate findStartCoordinate(Maze findCoord) {
  std::vector<std::vector<Coordinate>> initMaze = findCoord.getMazeLayout();

  for (int i = 0; i < findCoord.getRow(); i++) {
    for (int j = 0; j < findCoord.getCol(); j++) {
      if (initMaze[i][j].getTile() == 'S') {
        return initMaze[i][j];
      }
    }
  }

  return Coordinate(-1, -1, '-');
}

int main() {
  	Maze newMaze(10, 10);
	std::cout << newMaze.getRow() << ", " << newMaze.getCol() << std::endl;
	newMaze.generateMaze(0, 1);
	newMaze.printMaze();
	Coordinate startCoord = findStartCoordinate(newMaze);
	newMaze.mazeDFS(startCoord);
}
