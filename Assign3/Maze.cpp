
//*****************************************************************
// FILE:      Maze.cpp
// AUTHOR:    Kenneth Harris
// LOGON ID:  z1733721
// DUE DATE:  10/11/2018
//
// PURPOSE:   Contains the methods for the Maze class.
//*****************************************************************//

#include <stdlib.h>
#include <string>
#include <fstream>
#include "Maze.h"
#include <iostream>

using namespace std;

/***************************************************************
Function: readMaze
Use: Reads maze data from the input file into the maze array
Parameters: C++ string that will not be changed 
Returns: Nothing
Notes:
***************************************************************/
void Maze::readMaze(const string& fileName)
{
ifstream inFile;
char lines;

inFile.open(fileName);
	if(! inFile)
	{
	cout << "Error opening file";
	exit(1);
	}

	inFile >> height;
	inFile >> width;

	for(int row = 0; row < height; row++)
	{
		for(int col = 0; col < width; col++)
		{
			inFile >>  lines;
			maze[row][col].type = (SquareType)lines;
			if(maze[row][col].type == START)
			{
			maze[row][col].type= START;
			StartPos.ypos = row;
			StartPos.xpos = col;
			}

			if(maze[row][col].type == END)
			{
			maze[row][col].type = END;
			EndPos.ypos = row;
			EndPos.xpos = col;
			}

			if(maze[row][col].type == WALL)
			{
			maze[row][col].type = WALL;
			}

		}
	}

inFile.close();
}

/***************************************************************
Function: printMaze
Use: Should print the characters in the maze array to the screen.
Parameters: None
Returns: Nothing
Notes:
***************************************************************/
void Maze::printMaze() const
{
	for(int row = 0; row < height; row++)
	{
		for(int col = 0; col < width; col++)
		{
		cout << (char)maze[row][col].type;
		}
		cout << '\n';
	}

}

/***************************************************************
Function: clearPath
Use: Loop through the maze array and set the visited member of each maze
array element to false.
Parameters: None
Returns: Nothing
Notes:
***************************************************************/ 
void Maze::clearPath()
{
	for(int row = 0; row < 25; row++)
	{
		for(int col  = 0; col < 25; col++)
		{
		maze[row][col].visited =  false;
		}
	}
}

/***************************************************************
Function: solveMaze
Use: Calls the solveMaze method and returns the value
Parameters: None
Returns: True if a solution for the maze is found and false if not
Notes:
***************************************************************/
bool Maze::solveMaze()
{
	clearPath();
	return solveMaze(StartPos.xpos, StartPos.ypos);

}

/***************************************************************
Function: recursive solveMaze
Use: Finds a solution for the maze
Parameters: Two integers. One for row and one for column
Returns: True if a solution for the maze is found and false if not
Notes:
***************************************************************/
bool Maze::solveMaze(int row, int col)
{
	if(maze[row][col].type == END)
	{
		return true;
	}

	if(maze[row][col].type == WALL)
	{
		return false;
	}

	maze[row][col].visited = true;

	//How do I check if I am in the first row..?
	if(row != 0)
	{
		if(solveMaze(row-1,col))
		{
			path.push('n');
			return true;
		}
	}

	//same question but with the last row..
	if(row != height-1)
	{
		if(solveMaze(row+1,col))
		{
			path.push('s');
			return true;
		}
	}

	//same question
	if(col != 0)
	{
		if(solveMaze(row,col-1))
		{
			path.push('w');
			return true;
		}
	}

	if(col != width-1)
	{
		if(solveMaze(row,col+1))
		{
			path.push('e');
			return true;
		}
	}

	return false;
}

/***************************************************************
Function: printPath
Use: prints the valid path through the maze if one has been found
Parameters: none
Returns: Nothing
***************************************************************/ 
void Maze::printPath()
{
	//how to know when stak is not empty
	while(path.top() != path.empty())
	{
		path.top();
		cout << path.top() << endl;
		path.pop();
	}


}


