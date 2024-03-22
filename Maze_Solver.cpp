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
  std::string filename = "maze_2.txt";
  Maze newMaze;
  
  newMaze.loadMaze(filename);
  Coordinate startCoord = findStartCoordinate(newMaze);
  newMaze.mazeDFS(startCoord);
  return 0;
}


