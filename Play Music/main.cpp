// Please keep in mind that this was made on Windows xp
#include <iostream>
#include <windows.h>
using namespace std;
int main(){
string file = "C:\\Documents and Settings\\",user,f2 = "\\Music\\",filename;
cout<<"Enter the user that you want music from\n> ";
cin>>user;
cout<<"Enter the sound file's directory\nEX: Music.m4a\n> ";
cin>>filename;
file=file+=user;
file=file+=f2;
file=file+=filename;
if ((int)ShellExecuteA( NULL, "open", file.c_str(), NULL, NULL, SW_SHOWNORMAL ) <= 32)
  cout<<"Playing!\nFile:"<<file;
return 0;}
