#include<iostream>
#include<string>
#include<ctime>///[s]two libraries needed to generate random numbers[/s] This is uneeded, you could just use srand(rand());
#include<cstdlib>
#include<cctype>
using namespace std;

int position(int pos, string horse)
{
cout << horse << ": ";
pos = pos + rand() % 2 + 1; /// this code will generate a random number between 1 and 2
for(int b=0;b<=pos;b++)
cout << " ";
cout << "~n-n^";
cout << endl << endl;
return pos;
}
bool restart()
{
char YorN;
cout<<endl<<"Do you want to do it again? Y/N\n> ";
cin>>YorN;
if(YorN=='Y'||YorN=='y'){return true;}
else{return false;}
}
int main()
{
string horse, horsename,bethorse,bethorse2,bethorse3,bethorse4;
int playnum,posA=0,posB=0,posC=0,posD=0,highest=0,winner[] = {posA, posB, posC, posD};
double betcash=0,betcash2=0,betcash3=0,betcash4=0;
do{
system("cls");
cout<<"How many people are playing? Up to 4 can play."<<endl;
cin>>playnum;
switch(playnum){
case 1:
cout<<"Who do you think is going to win?\nPlace your Bet and find out!\n> $";
cin>>betcash;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
break;
case 2:
cout<<"Who do you think is going to win?\nPlace your Bet here Player 1\n> $";
cin>>betcash;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
cout<<"Who do you think is going to win?\nPlace your Bet here Player 2\n> $";
cin>>betcash;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
break;
case 3:
cout<<"Who do you think is going to win?\nPlace your Bet here Player 1\n> $";
cin>>betcash2;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse2;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
cout<<"Who do you think is going to win?\nPlace your Bet here Player 2\n> $";
cin>>betcash2;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse2;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
cout<<"Who do you think is going to win?\nPlace your Bet here Player 3\n> $";
cin>>betcash3;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse3;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
break;
case 4:
cout<<"Who do you think is going to win?\nPlace your Bet here Player 2\n> $";
cin>>betcash;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
cout<<"Who do you think is going to win?\nPlace your Bet here Player 2\n> $";
cin>>betcash2;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse2;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
cout<<"Who do you think is going to win?\nPlace your Bet here Player 2\n> $";
cin>>betcash3;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse3;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
cout<<"Who do you think is going to win?\nPlace your Bet here Player 2\n> $";
cin>>betcash4;
cout<<"On what horse? A, B, C, or D?\n> ";
cin>>bethorse4;
if(bethorse=="a"){bethorse="A";}
if(bethorse=="b"){bethorse="B";}
if(bethorse=="c"){bethorse="C";}
if(bethorse=="d"){bethorse="D";}
break;
}
srand(time(NULL)); /// this line of code ensures that our program will generate a new random number each time we ask for it

for(int a=0;a<=25;a++){
system("cls");

horse="A";
posA=position(posA,horse);
horse="B";
posB=position(posB,horse);
horse="C";
posC=position(posC,horse);
horse="D";
posD=position(posD,horse);
for(int timer=0;timer<=100000000;timer++);}
for(int p=0;p<=3;p++){if(winner[p]>winner[highest]){highest=p;}}
switch(highest){
case 0:
horsename="A";
break;
case 1:
horsename="B";
break;
case 2:
horsename="C";
break;
case 3:
horsename="D";
break;}
if(playnum==1){cout<<"The horse you guessed was "<<bethorse<<endl;}
cout<<"Winning Horse: Horse "<<horsename<<endl;
switch(playnum){
case 1:
if(horsename==bethorse){cout<<"You Won! You Get triple times the money you paid."<<endl;}
else cout<<"You Lost! Now your $"<<betcash<<" that you just bet is now mine!"<<endl;
break;
case 2:
if(horsename==bethorse){cout<<"Player 1 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 1 Lost! Now your $"<<betcash<<" that you just bet now belongs to the teller!"<<endl;
if(horsename==bethorse2){cout<<"Player 2 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 2 Lost! Now your $"<<betcash2<<" that you just bet now belongs to the teller!"<<endl;
break;
case 3:
if(horsename==bethorse){cout<<"Player 1 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 1 Lost! Now your $"<<betcash<<" that you just bet now belongs to the teller!"<<endl;
if(horsename==bethorse2){cout<<"Player 2 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 2 Lost! Now your $"<<betcash2<<" that you just bet now belongs to the teller!"<<endl;
if(horsename==bethorse3){cout<<"Player 3 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 3 Lost! Now your $"<<betcash3<<" that you just bet now belongs to the teller!"<<endl;
break;
case 4:
if(horsename==bethorse){cout<<"Player 1 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 1 Lost! Now your $"<<betcash<<" that you just bet now belongs to the teller!"<<endl;
if(horsename==bethorse2){cout<<"Player 2 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 2 Lost! Now your $"<<betcash2<<" that you just bet now belongs to the teller!"<<endl;
if(horsename==bethorse3){cout<<"Player 3 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 3 Lost! Now your $"<<betcash3<<" that you just bet now belongs to the teller!"<<endl;
if(horsename==bethorse4){cout<<"Player 4 Won! You Get triple times the money you paid."<<endl;}
else cout<<"Player 4 Lost! Now your $"<<betcash4<<" that you just bet now belongs to the teller!"<<endl;
break;}

}while(restart()==true);
system("pause");
return 0;}
