#include<iostream>
#include<vector>
#include<stack>
#include<fstream>
#include<sstream>

struct coord {
  int x;
  int y;
};

std::vector<std::vector<char>> read_to_array(const std::string&);
void solveMazeDFS (std::vector<std::vector<char>>);
coord findStartCoord (std::vector<std::vector<char>>);
bool isNextMovePossible(coord);
coord nextMove(coord);

std::vector<std::vector<char>> read_to_array(const std::string& filename) {
  // First pass: Determine dimensions
  int rows = 0;
  int cols = 0;
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    ++rows;
    cols = std::max(cols, static_cast<int>(line.length()));
  }
  file.clear();   // Reset file state
  file.seekg(0);  // Reset file position

  // Second pass: Populate the array
  std::vector<std::vector<char>> array(rows, std::vector<char>(cols, ' '));
  for (int i = 0; i < rows; ++i) {
    std::getline(file, line);
    for (int j = 0; j < cols; ++j) {
      array[i][j] = line[j];
    }
  }

  return array;

}

void solveMazeDFS (std::vector<std::vector<char>> maze) {
  coord startCoord;
  std::vector<std::vector<char>> visited = maze;
  startCoord = findStartCoord(maze);
  coord curIndex = startCoord;
  std::stack<char> path;
  path.push(startCoord);
  visited[startCoord.x][startCoord.y] = '.';
  
  while(maze[curIndex.x][curIndex.y] != 'G') {
    
    if (isNextMovePossible(curIndex, visited)) {
      curIndex = nextMove(curIndex);
      isVisited[curIndex.x][curIndex.y] = '.';
      path.push(curIndex);
    
    } else {
      path.pop();
      curIndex = path.top();
    }
    
    for (const auto& row : visited) {
      
      for (char value : row) {
        std::cout << value;
      }
      
      std::cout << '\n';
    }
  }
}

coord findStartCoord (std::vector<std::vector<char>> maze) {
  coord initCoord;
  int i = 0, j = 0;
  for (const auto& row : maze) {
    for (char col : row) {
      if (col == 'S') {
        std::cout << j << '\n';
        initCoord.x = i;
        initCoord.y = j;
        return initCoord;
      }
      j++;
    }
    j = 0;
    i++;
  }
  return initCoord;
}

bool isNextMovePossible(coord curIndex, std::vector<std::vector<char> maze) {
  
  if (maze[curIndex.x + 1][curIndex.y] != '#') {
    return true;
  }

  if (maze[curIndex.x][curIndex.y + 1] != '#') {
    return true;
  }
  
  if (maze[curIndex.x - 1][curIndex.y] != '#') {
    return true;
  }

  if (maze[curIndex.x][curIndex.y - 1] != '#') {
    return true;
  }

  return false;
  
}

coord nextMove(coord curIndex) {

}

int main() {
  std::string filename = "maze.txt";
  std::vector<std::vector<char>> maze = read_to_array(filename);
  for (const auto& row : maze) {
    for (char value : row) {
      std::cout << value;
    }
    std::cout << '\n';
  }
  
  solveMazeDFS(maze);

  return 0;
}


