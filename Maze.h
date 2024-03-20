#include <vector>
#include <string>
#include <iostream>
#include "Coordinate.h"

class Maze {
public:
  Maze();
  void loadMaze(std::string);
  void printMaze();
  //std::vector<std::vector<Coordinate>> getMazeLayout();

private:
  int row = 0;
  int col = 0;
  
  std::vector<std::vector<Coordinate>> mazeLayout;
};
