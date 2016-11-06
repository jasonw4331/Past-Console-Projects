#include "Maze.h"
///#include "Stack.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>



/// Position constructor initializes a position according to the passed in args

Maze::Position::Position( int r, int c, Position *p )
   {
   row = r;
   col = c;
   previous = p;
   }



/// The maze constructor reads in and builds the maze representation

Maze::Maze( ifstream &infile )
   {
   infile >> rows >> cols;   // read in the size of the maze

   /// set up the 2-D dynamic arrays: maze[][] and visited[][]
   /// -------------------------------------------------------
   maze.resize( rows );
   visited.resize( rows );
   for (int i = 0; i < rows; i++)
      {
      maze[i].resize( cols );
      visited[i].resize( cols );
      }

   /// read in the maze
   /// ----------------
   for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
         {
         infile >> maze[i][j];

         if (maze[i][j] == 0)
            visited[i][j] = true;    /// mark walls visited so we don't go there
         else
            visited[i][j] = false;   /// initialize all locations to unvisited
         }

   infile.close();
   }
