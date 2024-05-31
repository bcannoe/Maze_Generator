# Maze_Generator

This is a project that will generate a maze in C++

This maze generator will be using DFS to solve the maze and is using recursive backtracking to generate it.

DFS is the simplest pathfinding alogorithm, it will go down a hallway until it no longer can, then it will either turn, or if there is no possible path forward it will pop it's location off a stack to return to a previous location where there is an unvisited tile of the maze and repeat the process until it finds the correct path.

To build project

mkdir build
cd build
cmake ..
make

Todo:
fix unsolvable maze when stack pops all the way back up to start
add new maze generation algorithms
add new maze searching algorithms
add SDL and GUI support