#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
string file;
    cin >> file;
    stringstream str;
    str<<"/C://Users//My/Desktop//C++//"<<file<<".wav/";
    string filepath=str.str();
    cout<<filepath;
    ifstream ipf("/C://Users/My//Desktop//C++//.wav/");
    if(ipf)
{cout << "hi";}
}
