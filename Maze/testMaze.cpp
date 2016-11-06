/** short program to test the maze class.  All it does is read in the command
   line arguments. open the file. and call the maze constructor to build the
   maze according to the input file and call the solve() function to solve it.
*/
#include "Maze.h"
#include <iostream>
#include <cstdlib>

int main( int argc, char *argv[] )
   {
   if (argc != 2)  /// make sure that the correct number of arguments were passed
      {
      cerr << "Usage: " << argv[0] << " <filename> " << endl;
      return 1;
      }

   ifstream infile;
   infile.open( argv[1] );   /// open the input file

   if (! infile.is_open()) {
      cerr << "ERROR: could not open file " << argv[1] << endl;
      exit(1);
      }

   Maze maze( infile );    /// build the maze
   maze.solve();           /// solve the maze

   return 0;
   }
