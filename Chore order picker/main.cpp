#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
int Random;
string name1,name2,name3;
int check;
srand(time(0));

cout << "Enter your name Player 1"<<endl;
cin >> name1;
cout << "Enter your name Player 2"<<endl;
cin >> name2;
cout << "Enter your name Player 3"<<endl;
cin >> name3;
system("cls");

Random=1+(rand()%7);
cout << "The random number is: " <<Random << endl;

if(Random <= 3){
cout << name1 <<" picks first\n";
}else if((Random == 4||Random ==  5)||Random == 6){
cout << name2 <<" picks first\n";
}else if(Random >= 6){
cout << name3 <<" picks first\n";
}else if(Random > 9){
cout << "Resarting..."<< endl;
Sleep(1000);
system("cls");

Random=1+(rand()%7);
cout << "The random number is:\n" <<Random << endl;
if(Random < 3){
cout << name1 <<" picks first\n";
}else if((Random == 4||Random ==  5)||Random == 6){
cout << name2 <<" picks first\n";
}else if(Random > 6){
cout << name3 <<" picks first\n";
}else if(Random < 9){
cout << "Restart the program!"<< endl;
system("cls");
}}
Random=1+(rand()%7);
cout << "The random number is: " <<Random << endl;
check=Random;
if(Random <= 3){
cout << name1 <<" picks second\n";
}else if((Random == 4||Random ==  5)||Random == 6){
cout << name2 <<" picks second\n";
}else if(Random >= 6){
cout << name3 <<" picks second\n";
}else if(Random > 9||check==Random){
cout << "Resarting..."<< endl;
Sleep(1000);
system("cls");

Random=1+(rand()%7);
cout << "The random number is:\n" <<Random << endl;
if(Random < 3){
cout << name1 <<" picks second\n";
}else if((Random == 4||Random ==  5)||Random == 6){
cout << name2 <<" picks second\n";
}else if(Random > 6){
cout << name3 <<" picks second\n";
}else if(Random < 9||check==Random){
cout << "Restart the program!"<< endl;
system("cls");
}}
system("pause");
}
