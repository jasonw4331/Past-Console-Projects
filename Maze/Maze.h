#ifndef MAZE_H
#define MAZE_H

#include <fstream>     /// for ifstream
#include <vector>      /// for the maze[][] and visited arrays
using namespace std;


class Maze
   {
   public:
      Maze( ifstream &infile );
      void solve();
	  /// void printSol(Position *p);
   private:
      int rows;    /// the number or rows in the maze
      int cols;    /// the number of columns in the maze

      vector< vector<int> > maze;       /// 2-D dynamic maze array
      vector< vector<bool> > visited;   /// the visited marks

      class Position  /// the class for a position in the maze
         {
         public:
            Position( int r, int c, Position *p );
            int row;
            int col;
            Position* previous;
         };
   };
#endif
