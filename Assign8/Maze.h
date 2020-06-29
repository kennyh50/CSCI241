#ifndef MAZE_H
#define MAZE_H
#include <string>
#include <stack>

//*****************************************************************
// FILE:      Maze.h
// AUTHOR:    Kenneth Harris
//
// PURPOSE:   Contains the declaration for the Maze class.
//*****************************************************************

		enum SquareType
		{
		WALL = '#',
		SPACE = '.',
		START = 's',
		END = 'e'
		};

		enum PathType
		{
		NORTH = 'n',
		SOUTH = 's',
		EAST = 'e',
		WEST = 'w'
		};

		struct MazePos
		{
		int xpos;
		int ypos;
		};

		struct MazeSquare
		{
		SquareType type;
		bool visited;
		};
class Maze
{
	private:

		MazeSquare maze[25][25];
		int width;
		int height;
		std::stack<char> path;

		MazePos StartPos;
		MazePos EndPos;

	public:

		void  printMaze() const;
		void readMaze(const std::string& fileName);
		void clearPath();
		bool solveMaze();
		bool solveMaze(int row, int col);
		void printPath();
};

#endif
