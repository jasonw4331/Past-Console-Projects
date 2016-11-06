#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // std::copy
#include <iterator> // std::ostream_iterator
using namespace std;

vector<int> parseLine( string str );
int main() {
  string line;

  vector<int> list1;
  if ( getline( cin, line ) ) {
    list1 = parseLine( line );
  }

  vector<int> list2;
  ifstream myfile( "input.txt" );
  if ( getline( myfile, line ) ) {
    list2 = parseLine( line );
  }

  cout << '\n';
  copy( list2.begin(), list2.end(), ostream_iterator<int>( cout, " " ) );
  cout << '\n';
  copy( list1.begin(), list1.end(), ostream_iterator<int>( cout, " " ) );
  cout << '\n';
  return 0;
}

vector<int> parseLine( string str ){
  istringstream ss(str);
  vector<int> result;
  ss.ignore( 30, '=' );
  int value;
  while ( ss >> value ) {
    result.push_back( value );
    ss.ignore( 1, ',' );
  }
  return result;
}
