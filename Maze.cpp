#include "Maze.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

Maze::Maze() {}

Maze::Maze(int row, int col) {
    this->row = row;
    this->col = col;
}

int Maze::getRow() {
    return row;
}

int Maze::getCol() {
    return col;
}

std::vector<std::vector<Coordinate>> Maze::getMazeLayout() {
    return mazeLayout;
}

void Maze::loadMaze(std::string filename) {

    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        ++row;
        col = line.length();
    }

    file.clear();
    file.seekg(0);

    for (int i = 0; i < row; ++i) {
        
        std::getline(file, line); 
        mazeLayout.push_back(std::vector<Coordinate>());

        for (int j = 0; j < col; ++j) {
            Coordinate tempPos(i, j, line[j]);
            mazeLayout[i].push_back(tempPos);
        }    
    }
    file.close();
}

void Maze::generateMaze(int startX, int startY) {
    // Initialize the maze with walls
    mazeLayout.clear();
    for (int i = 0; i < row; ++i) {
        mazeLayout.push_back(std::vector<Coordinate>());
        for(int j = 0; j < col; ++j) {
            Coordinate tempPos(i, j, '#');
            mazeLayout[i].push_back(tempPos);
        }
    }

    printMaze();
    // Generate maze using recursive backtracking
    recursiveBacktracking(startX, startY);
    
    // mark start and goal positions
    mazeLayout[startX][startY].setTile('S');
    mazeLayout[row/2][col/2].setTile('G');
}

void Maze::recursiveBacktracking(int x, int y) {
    // directions
    static const int dx[] = {0, 0, 1, -1};
    static const int dy[] = {1, -1, 0, 0};
    // choosing direction
    std::vector<int> dirs = {0, 1, 2, 3};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dirs.begin(), dirs.end(), g);

    for (int dir : dirs) {
        int nx = x + dx[dir] * 2;
        int ny = y + dy[dir] * 2;

        if (nx > 0 && nx < row - 1 && ny > 0 && ny < col - 1 && mazeLayout[nx][ny].getTile() == '#') {
            mazeLayout[x + dx[dir]][y + dy[dir]].setTile(' ');
            mazeLayout[nx][ny].setTile(' ');
            recursiveBacktracking(nx, ny);
        }
    }
}

Coordinate Maze::mazeDFS(Coordinate start) {
    std::stack<Coordinate> history;
    history.push(start);

    while (!history.empty()) {
        Coordinate curCoord = history.top();
        history.pop();

        // Mark the current position as visited
        mazeLayout[curCoord.getX()][curCoord.getY()].setTile('.');

        // Find the next valid move
        Coordinate next = nextCoord(curCoord);
        mazeLayout[next.getX()][next.getY()].visit();
        if (next.getTile() == 'G') {
            mazeLayout[next.getX()][next.getY()].setTile('*');
            printMaze();
            return next;
        }
        mazeLayout[next.getX()][next.getY()].setTile('@');

        printMaze();
        history.push(next);
        if (!history.empty()) {
            if (validMove(next)) {
                history.push(next);
            } else {
                while(!history.empty() && !validMove(history.top())) {
                    mazeLayout[next.getX()][next.getY()].setTile(' ');
                    history.pop();
            }
        }
        
       
        }
    }

    // Push the next position onto the stack
    return Coordinate(-1, -1, '~');
}

// Check for the next valid node
Coordinate Maze::nextCoord(Coordinate curCoord) {
    if (mazeLayout[curCoord.getX() + 1][curCoord.getY()].getTile() != '#' && mazeLayout[curCoord.getX() + 1][curCoord.getY()].getTile() != '.') {
        curCoord = mazeLayout[curCoord.getX() + 1][curCoord.getY()];
        return curCoord;
    }

    else if (mazeLayout[curCoord.getX()][curCoord.getY() + 1].getTile() != '#' && mazeLayout[curCoord.getX()][curCoord.getY() + 1].getTile() != '.') {
        curCoord = mazeLayout[curCoord.getX()][curCoord.getY() + 1];
        return curCoord;
    }

    else if (mazeLayout[curCoord.getX() - 1][curCoord.getY()].getTile() != '#' && mazeLayout[curCoord.getX() - 1][curCoord.getY()].getTile() != '.') {
        curCoord = mazeLayout[curCoord.getX() - 1][curCoord.getY()];
        return curCoord;
    }

    else if (mazeLayout[curCoord.getX()][curCoord.getY() - 1].getTile() != '#' && mazeLayout[curCoord.getX()][curCoord.getY() - 1].getTile() != '.') {
        curCoord = mazeLayout[curCoord.getX()][curCoord.getY() - 1];
        return curCoord;
    }

    return curCoord;
}

bool Maze::validMove(Coordinate curCoord) {
    if (mazeLayout[curCoord.getX() + 1][curCoord.getY()].getTile() != '#' && mazeLayout[curCoord.getX() + 1][curCoord.getY()].getTile() != '.') {
        return true;
    }

    else if (mazeLayout[curCoord.getX()][curCoord.getY() + 1].getTile() != '#' && mazeLayout[curCoord.getX()][curCoord.getY() + 1].getTile() != '.') {
        return true;
    }

    else if (mazeLayout[curCoord.getX() - 1][curCoord.getY()].getTile() != '#' && mazeLayout[curCoord.getX() - 1][curCoord.getY()].getTile() != '.') {
        return true;
    }

    else if (mazeLayout[curCoord.getX()][curCoord.getY() - 1].getTile() != '#' && mazeLayout[curCoord.getX()][curCoord.getY() - 1].getTile() != '.') {
        return true;
    }

    return false;
}

void Maze::printMaze() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << mazeLayout[i][j].getTile();
        }
        std::cout << '\n';
    }
    std::cout<< u8"\033[2J\033[1;1H"; 
}
