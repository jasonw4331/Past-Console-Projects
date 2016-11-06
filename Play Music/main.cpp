#include <iostream>
#include <windows.h>
using namespace std;
int main(){
string file = "C:\\Documents and Settings\\Jason\\My Documents\\Jason\\My Music\\",filename;
cout<<"Enter the sound file's directory\nEX: Music.m4a\n>";
cin>>filename;
file=file+=filename;
if ((int)ShellExecuteA( NULL, "open", file.c_str(), NULL, NULL, SW_SHOWNORMAL ) <= 32)
  cout<<"Playing!\nFile:"<<file;
return 0;}
