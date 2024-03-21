#include "Maze.h"
Coordinate findStartCoordinate(Maze);

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
  std::string filename = "mazeBadDFSRuntime.txt";
  Maze newMaze;
  
  newMaze.loadMaze(filename);
  Coordinate startCoord = findStartCoordinate(newMaze);
  //std::cout << startCoord.getX() << ", " << startCoord.getY() << ", " << startCoord.getTile() << std::endl;
  newMaze.mazeDFS(startCoord);
  return 0;
}


