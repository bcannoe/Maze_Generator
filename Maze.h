#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <unistd.h>
#include "Coordinate.h"

class Maze {
public:
  Maze ();
  Maze (int, int);
  int getRow ();
  int getCol ();
  std::vector<std::vector<Coordinate>> getMazeLayout ();
  void loadMaze (std::string);
  void generateMaze(int, int);
  void recursiveBacktracking(int, int);
  Coordinate mazeDFS (Coordinate);
  Coordinate nextCoord (Coordinate);
  bool validMove (Coordinate);
  void printMaze();
  

private:
  int row = 0;
  int col = 0;
  std::vector<std::vector<Coordinate>> mazeLayout;
  std::stack<Coordinate> history;
};
