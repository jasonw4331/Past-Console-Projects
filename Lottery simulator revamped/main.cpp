#include<iostream>
#include<cstdlib>
#include <windows.h>
#include<ctime>
using namespace std;


int main()
{
int WN[5];
int UI[5];
int MN = 0;

WN[0] = (rand() % 10);
WN[1] = (rand() % 10);
WN[2] = (rand() % 10);
WN[3] = (rand() % 10);
WN[4] = (rand() % 10);

cout << "LOTTO Winning Numbers: " << WN[0] << WN[1] << WN[2] << WN[3] << WN[4] << endl;

cout << "1st USER Number: ";
cin >> UI[0];
cout << "2nd USER Number: ";
cin >> UI[1];
cout << "3rd USER Number: ";
cin >> UI[2];
cout << "4th USER Number: ";
cin >> UI[3];
cout << "5th USER Number: ";
cin >> UI[4];

cout << "Matching Numbers: ";
for(int i=0;i<5;i++)
{
    for(int j= 0;j<5;j++)
    {
        if ( WN[i] == UI[j] )
        cout << WN[i] ;
        {
        MN++ ;
        }
     }
}

if (MN = 5)
cout << endl << "Prize: $500,000. Congratulations! You one lucky son of a Human!" << endl;
else if (MN = 4)
cout << endl << "Prize: $100,000. Congratulations! The odds is in your favor!"<<endl;
else if (MN = 3)
cout << endl << "Prize: $20,000. Congratulations! You can now buy an expensive item of your choice!" << endl;
else if (MN = 2)
cout << endl << "Prize: $500. Yay! Added allowance!" << endl;
else if (MN = 1)
cout << endl << "Prize: $10. Ten Dollars!" << endl;
else if (MN = 0)
cout << endl << "Zero Matching Digits. Try Again.";


system("pause>0");
return 0;
}
