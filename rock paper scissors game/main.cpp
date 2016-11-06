#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

char a,b;
string PLAYER_1,PLAYER_2;
string YN;
int x;
int main()
{
while(x!=1){
cout << "Enter your name:"<<endl;
cin >> PLAYER_1;
cout << "Enter your name:"<<endl;
cin >> PLAYER_2;
system("cls");

cout<<"P = paper"<<endl;
cout<<"R = rock"<<endl;
cout<<"S = scissor"<<endl;

cout<<"Player 1 choose"<<endl;
cin>>a;
system("cls");

cout<<"P = paper"<<endl;
cout<<"R = rock"<<endl;
cout<<"S = scissor"<<endl;

cout<<"Player 2 choose"<<endl;
cin>>b;
system("cls");

if(toupper(a) == toupper(b))
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n                                                   "<<PLAYER_1<<" and "<<PLAYER_2<<" TIE!";
}

else if ((a=='p'||a=='P') && (b=='r'||b=='R') || (a=='r'||a=='R') && (b=='s'||b=='S') || (a=='s'||a=='S') && (b=='p'||b=='P') )
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n                                                   "<< PLAYER_1 <<" WON!";
}
else if ((a=='r'||a=='R') && (b=='p'||b=='P') || (a=='s'||a=='S') && (b=='r'||b=='R') || (a=='p'||a=='P') && (b=='s'||b=='S') )
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n                                                   "<< PLAYER_2 <<" WON!";
}else cout << "Logic Error!";
cout << "\nHit the spacebar to play again";
Sleep(2000);
if(GetAsyncKeyState(VK_SPACE)){
    system("cls");
}else{x=1;}}
system("cls");
cout << "Ending program in 2 seconds\n";
Sleep(1000);
cout << "Ending program in 1 seconds";
Sleep(1000);
system("cls");
system("exit");
}
