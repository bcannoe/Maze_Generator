// Blake Cannoe
// Maze Generator V0.1
// A program that will generate a maze of a size specified by the user.
// After the maze is generated it will be sent to text file as well as displayed on the console.

#include "Maze.h"
#include <cstdlib>

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

int main(int argc, char *argv[]) {
  // maze is 30 X 30 by default
  int row = 30, col = 30;
  if (argc == 1) {
    ;
  }
  else if (argv[1] != NULL) {
    row = atoi(argv[1]);
    col = atoi(argv[2]);
  }

  Maze newMaze(row, col);
  newMaze.generateMaze(1, 1);
  newMaze.printMaze();
  newMaze.exportMaze();
}