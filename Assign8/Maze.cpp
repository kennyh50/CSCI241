#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Maze.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;



/***************************************************************
Function: readMaze
Use: Reads the maze data from the input file into the maze array.
Parameters: C++ string that will not be changed by the function and that
contains the name of an input file
Returns: Nothing
Notes:
***************************************************************/
void Maze::readMaze(const string& fileName)
   {
   char ch;

   ifstream inFile(fileName);
   if (!inFile)
      {
      cout << "Error: unable to open maze file " << fileName << endl;
      exit(1);
      }

   inFile >> height;
   inFile >> width;

   for (int row = 0; row < height; row++)
      {
      for (int col = 0; col < width; col++)
         {
         inFile >> ch;
         maze[row][col].type = (SquareType) ch;

         if (maze[row][col].type == START)
            {
            StartPos.ypos = row;
            StartPos.xpos = col;
            }
         else if (maze[row][col].type == END)
            {
            EndPos.ypos = row;
            EndPos.xpos = col;
            }
         }
      }

   inFile.close();
   }

/***************************************************************
Function: printMaze
Use: Prints the maze from the maze array
Parameters: none
Returns: nothing
Notes:
***************************************************************/
void Maze::printMaze() const
   {
   for (int row = 0; row < height; row++)
      {
      for (int col = 0; col < width; col++)
         {
         cout << (char) maze[row][col].type;
         }

      cout << endl;
      }
   }

/***************************************************************
Function: clearPath
Use: Loops through the maze array and sets the visited member of 
each maze array element to false
Parameters: None
Returns: Nothing
Notes:
***************************************************************/
void Maze::clearPath()
   {
   for (int row = 0; row < height; row++)
      {
      for (int col = 0; col < width; col++)
         maze[row][col].visited = false;
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
	return solveMaze(StartPos.ypos, StartPos.xpos);

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

	if(maze[row][col].type == WALL || maze[row][col].visited == true)
	{
		return false;
	}

	maze[row][col].visited = true;


	if(row != 0)
	{
		if(solveMaze(row-1,col))
		{
			path.push('n');
			return true;
		}
	}


	if(row != height-1)
	{
		if(solveMaze(row+1,col))
		{
			path.push('s');
			return true;
		}
	}



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
	while(!path.empty())
	{
		path.top();
		cout << path.top() << " ";
		path.pop();
	}


}

