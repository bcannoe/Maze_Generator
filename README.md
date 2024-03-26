# Maze_Generator

This is a project that will generate a maze in C++

The goal of this project is to act as a prototype for a maze generator plug-in that I will be making for Unreal Engine.

This maze generator will be using DFS to solve the maze and is using recursive backtracking to generate it.

DFS is the simplest pathfinding alogorithm, it will go down a hallway until it no longer can, then it will either turn, or if there is no possible path forward it will pop it's location off a stack to return to a previous location where there is an unvisited tile of the maze and repeat the process until it finds the correct path.

The solver is mostly complete barring a few issues, and the generator cannot generate a new maze properly yet.

to run, run the command
g++ -o Maze_Generator Maze_Generator.cpp Maze.cpp Coordinate.cpp
./Maze_Generator

Todo:
fix maze randomization
fix error when current node is on the edge of the maze
fix unsolvable maze when stack pops all the way back up to start
add border to maze
add graphics with openGL
add different shapes of mazes
add new maze generation algorithms
add new maze searching algorithms
