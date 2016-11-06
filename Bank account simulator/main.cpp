#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <sstream>
using namespace std;

void menu();
void userinput();
void accountinput();
void accountlogin();
void Deposit();
void Withdraw();
void balanceholder();
void seconds_count();

double answer,deposit, withdraw,balance=0,chances = 3,Id,pass;
int choice;
const int MAX_WRONG = 5;
char cChoice;
string Pass, ID,Balance,s,IDin,Passin;
string username;
string password;

int main()
{
system ("color 2f");
printf("Do you want to register y/n -> ");
                cin>>cChoice;
                printf("\n");

                if(cChoice=='Y'||cChoice=='y')
                {
    ofstream myfile ("IDs_file.txt");
    if (myfile.is_open())
    {
    printf("\nEnter your new Pin -> ");
    cin>>ID;
    myfile << ID;
    printf("\nEnter your new Password -> ");
    cin>>Pass;
    myfile << ":" << Pass<<"\n";
    myfile.close();
    }
    else cout << "Unable to open file";
printf("\n\nRestart the program for the new pin and password to take effect\n\n");
system("pause");
return 0;}
accountlogin();
accountinput();
}
void accountlogin()
{
    ifstream myfile("IDs_file.txt");
    if(!myfile)
    {
        cerr << "Error opening ID input file.";
    }
    if(getline(myfile, username, ':') >> password){
    int wrong = 0;
    string userChoice;
    string userChoice2;
SYSTEM_LOOP:
    system ("cls");
    cout << "Username : " << endl;
    cin >> userChoice;
    cout<<endl;

    cout << "Password : " << endl;
    cin >> userChoice2;
    cout<<endl;

    if (userChoice == username && userChoice2 == password)
    {
        cout<<"correct !"<<endl;
        system ("pause");
        system ("cls");
    }
    else if (userChoice != username && userChoice2 != password)
    {
        cout<<"incorrect !"<<endl;
        wrong++;
        system ("pause");

        if (wrong == MAX_WRONG)
        {
            seconds_count();
        }
        goto SYSTEM_LOOP;
    }
    else if (userChoice == username && userChoice2 != password)
    {
        cout<<"incorrect !"<<endl<<endl;
        system ("pause");
        goto SYSTEM_LOOP;
    }
    else if (userChoice != username && userChoice2 == password)
    {
        cout<<"incorrect !"<<endl<<endl;
        system ("pause");
        goto SYSTEM_LOOP;
    }
}}
void accountinput()
{
  ifstream myfile("Balance.txt");
    if(!myfile){cerr << "Error opening ID input file.";}
    string data;
    getline(myfile, data, ':') >> balance;
    if(data==username)
    {

    }
    myfile.close();
userinput();
}
void userinput()
{
while (choice != 4)
{
cout << "Welcome to jasonwynn10's ATM Machine\n";
cout << "[1]Display Balance \n";
cout << "[2]Deposit Money\n";
cout << "[3]Withdraw Money\n";
cout << "[4]Exit\n";
cout << "Enter your Choice:";
cin >> choice;
switch (choice)
{
case 1:
cout << "Your Balance is :" <<balance<< endl;
system("pause");
system("cls");
break;
case 2:
Deposit();
break;
case 3:
Withdraw();
break;
case 4:
cout << "Your Balance is :" <<balance<< endl;
balanceholder();
system("pause");
break;
default:
cout<<"Say Again? \n> ";
cin >> choice;
break;
}
}
}
void Deposit()
{
cout << "Your Current Balance is " << balance << endl;
cout << "How much Money you want to deposit:" << endl;
cin >> deposit;
balance = balance + deposit;
cout << "Your new balance is :" << endl;
cout << balance;
cout << endl;
system("pause");
system("cls");
userinput();

}
void Withdraw()
{
cout << "Your Current Balance is " << balance << endl;
cout << "How much Money do you want to withdraw:" << endl;
cin >> withdraw;
if (withdraw > balance)
cout << "Sorry you don't have enough money to withdraw" << endl;
else if (withdraw <= 0)
cout << "sorry amount can not be zero or negative" << endl;
else
balance = balance - withdraw;
cout << "You Withdraw :" << withdraw << endl;
cout << "Your new balance is :" << endl;
cout << balance<<endl;
system("pause");
system("cls");
userinput();
}
void balanceholder()
{
    ofstream myfile ("Balance.txt");
    if (myfile.is_open())
    {
    myfile <<username<<":"<<balance;
    myfile.close();}
    else cout << "Unable to open file";
}
void seconds_count()
{
    for (int c = 30 ; c > 0 ; c--)
    {
        cout<<"Please wait "<<c<<" seconds"<<endl;
        Sleep (1000);
        system ("cls");
    }
}
