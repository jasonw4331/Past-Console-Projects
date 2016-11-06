#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
int flip,t,x,heads=0,tails=0,a;
do{
    cout << "How many times would you like to toss the coin?" << endl;
    cin >> t;
		srand(time(NULL)); ///Initializes random number seed.
		for (x = 0; x < t; x++){flip = rand() % 2 + 1;
		if (flip == 2){heads++;}else{tails++;}}

	cout << "In " << t << " tosses. There were " << heads << " heads and " << tails << " tails.";
	cout<<"\nDo again? Y/N\n> ";
	do{
    a=getchar();
    if(a=='N'||a=='n'){break;}
  }while (a!='y');
	if(a=='N'||a=='n'){break;}
	}while(a!='n'||a!='N');
	system("pause");
	return 0;}
