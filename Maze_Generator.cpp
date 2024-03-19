// Blake Cannoe
// Maze Generator V0.1
// A program that will generate a maze of a size specified by the user.
// After the maze is generated it will be sent to text file as well as displayed on the console.
// This program will make use of graph theory concepts as well as objects in C++

#include <iostream>
#include <vector>

class MazeGenerator {
private:
	int rows, cols;
	vector<vector<char>> maze;
	vector<vector<bool>> visited;

	bool isValid(int row, int col);
	void dfs(int row, int col);

public:
	MazeGenerator(int rows, int cols);
	void generateMaze();
	void printMaze();
};


int main() {
	
}
