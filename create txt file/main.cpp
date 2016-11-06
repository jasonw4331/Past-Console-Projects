#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void read();
void wright();
void create();

int main () {
create();
wright();
read();
}
void read()
{
   ofstream myfile;
   myfile.open ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a pickle line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else{ cout << "Unable to open file";}
}
void wright()
{
    string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}
void create()
{
  ofstream myfile;
  myfile.open ("example.txt");
  myfile.close();
}
