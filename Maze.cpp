#include "Maze.h"
#include <fstream>

Maze::Maze() {}

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
        col = std::max(col, static_cast<int>(line.length()));
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

// First find the start coordinate
// Check each adjacent node for a valid move to unvisited node
// move down valid path
// if there is no valid path pop nodes off the stack until there is a path.
void Maze::mazeDFS(Coordinate start) {

}

void Maze::printMaze() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << mazeLayout[i][j].getTile();
        }
        std::cout << '\n';
    }
}
