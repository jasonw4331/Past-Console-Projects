#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
int number;
int option;
int helper = 0;
int p;
do
{
cout << "Cool Configurations: Primality and Factorization\n";
cout << "You can use this program in order to test a integer for primality and/or to find the factors of your chosen integer.\n";

cout << "Menu\n";
cout << "1) Choose option '1' if you would like to determine the primality of your number\n";
cout << "2) Choose option '2' if you would like to factor your number\n";
cout << "3) Choose option '3' if you would like to Exit this Program\n";

cout << "Please enter your chosen option from the above menu.\n";
cin >> option;

if (option == 1)
{
cout << "Please enter a positive integer.\n";
cin >> number;
cout << " Your number is " << number << ".\n";

switch(number)
{
case 1:
cout << "One is not a prime number.\n";
break;
case 2:
cout << "Two is totally a prime number!\n";
break;
case 3:
for (p = 2; p*p <= number; p++)
{
if (number % p == 0)
{
helper = helper + 1;
}
}
if (helper == 0)
{
cout << "This number is a prime number.\n";
}
else
{
cout << "This number is not a prime number.\n";
break;
default:

break;
}
}
}

else if (option == 2){
return 0;
}
Sleep(2000);
system("cls");
}while(option!=3);
return 0;}
