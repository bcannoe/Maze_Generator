#include "Maze.h"
#include <fstream>

Maze::Maze() {
}

void Maze::loadMaze(std::string filename) {
    //std::cout << filename;
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
    //std::cout << "Rows: " << row << ", " "Cols: " << col << '\n';
    for (int i = 0; i < row; ++i) {
        
        std::getline(file, line);
        //std::cout << "line: " << line << std::endl; 
        mazeLayout.push_back(std::vector<Coordinate>());

        for (int j = 0; j < col; ++j) {
            Coordinate tempPos(i, j, line[j]);
            mazeLayout[i].push_back(tempPos);
            //std::cout << "Coordinate (" << tempPos.getX() << ", " << tempPos.getY() << ") - Tile: " << tempPos.getTile() << std::endl;
        }    
    }
    file.close();
}

void Maze::printMaze() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // This has to be very specific about what it is printing out or the program will segfault.
            std::cout << mazeLayout[i][j].getTile();
        }
        std::cout << '\n';
    }
}
