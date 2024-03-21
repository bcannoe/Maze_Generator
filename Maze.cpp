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
/*Coordinate Maze::mazeDFS(Coordinate start) {
    std::stack<Coordinate> history;
    history.push(start);
    std::cout << prevCoord.getX() << ", " << prevCoord.getY() << ", " << prevCoord.getTile() << std::endl;
    // This means we visited this node.
    mazeLayout[prevCoord.getX()][prevCoord.getY()].setTile('.');
    printMaze();

    if (prevCoord.getTile() == 'G') {
        mazeLayout[prevCoord.getX()][prevCoord.getY()].setTile('*');
        return prevCoord;
    }

    Coordinate curCoord = nextCoord(prevCoord);
    mazeLayout[curCoord.getX()][curCoord.getY()].visit();
    mazeLayout[curCoord.getX()][curCoord.getY()].setTile('@');
    
    sleep(1);
    //printMaze();
    if (curCoord.getX() == prevCoord.getX() && curCoord.getY() == prevCoord.getY()) {
        mazeLayout[curCoord.getX()][curCoord.getY()].setTile(' ');
        Coordinate result = mazeDFS(prevCoord);
    }
    else {
        Coordinate result = mazeDFS(curCoord);
    }
    if (curCoord.getTile() == 'G') {
        return curCoord;
    }

    mazeLayout[curCoord.getX()][curCoord.getY()].setTile(' ');
    return mazeDFS(prevCoord);
}*/

Coordinate Maze::mazeDFS(Coordinate start) {
    std::stack<Coordinate> history;
    history.push(start);

    while (!history.empty()) {
        Coordinate curCoord = history.top();
        history.pop();

        // Mark the current position as visited
        mazeLayout[curCoord.getX()][curCoord.getY()].setTile('.');

        if (curCoord.getTile() == 'G') {
            // Mark the goal position
            mazeLayout[curCoord.getX()][curCoord.getY()].setTile('*');
            return curCoord;
        }

        // Find the next valid move
        Coordinate next = nextCoord(curCoord);
        mazeLayout[next.getX()][next.getY()].visit();
        mazeLayout[next.getX()][next.getY()].setTile('@');

        sleep(1);
        printMaze();
        history.push(next);
        if (!history.empty()) {
            if (validMove(next)) {
                std::cout << "Got Here 1" << std::endl;
                history.push(next);
            } else {
                std::cout << "Got Here 3" << std::endl;
                std::cout << history.top().getX() << ", " << history.top().getY() << ", " << history.top().getTile() << std::endl;
                while(!history.empty() && !validMove(history.top())) {
                
                    history.pop();
            }
        }
        std::cout << "Got Here 2" << std::endl;
        
       /* if (next.getTile() != '#') {
            history.push(next);
        } else {
            while(!history.empty() && nextCoord(history.top()).getTile() == '#') {
                std::cout << "Got Here" << std::endl;
                history.pop();
            }*/
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
}
