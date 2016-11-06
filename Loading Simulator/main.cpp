//Buffer Simulator
#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

int main()
{
string EorC;
int percent=1;
cout<<"Please wait while the program loads\n";
Sleep(2000);
while(EorC!="End"||EorC!="end"){
while(percent!=100){
srand(rand()%7);
cout << "Loading    "<<percent<<"%";
Sleep(rand());
system("cls");
cout << "Loading.   "<<percent<<"%";
Sleep(rand());
system("cls");
cout << "Loading..  "<<percent<<"%";
Sleep(rand());
system("cls");
cout << "Loading... "<<percent<<"%";
system("cls");
percent++;
}
cout << "You were waiting for nothing!"<<endl<<"End or Continue? ";
cin >> EorC;
if(EorC=="End"||EorC=="end"){
return 0;
}else
cout<<"Smile, your grandsons and granddaughter love you!";
system("pause");
return 0;
}}
