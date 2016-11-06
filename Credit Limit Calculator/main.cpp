#include <iostream>
#include <cstdio>
using namespace std;

int ac;
char End;
double bb,tch,tcr,cl,nb,ch;
int main(void){
cout<<"Enter Account Number (or -1 to end)";
cin>>ac;
while (ac!=-1){
cout<<"Enter Beginning Balance: ";
cin>>bb;
cout<<"Enter total charge: ";
cin>>tch;
cout<<"Enter total credits: ";
cin>>tcr;
cout<<"Enter Credit limit: ";
cin>>cl;
nb=(bb+ch)-tcr;
cout<<"New Balance is: "<<nb<<endl;
if (nb>cl)
{
cout<<"Account: "<<ac<<endl;
cout<<"Credit Limit: "<<cl<<endl;
cout<<"Balance: "<<nb<<endl;
cout<<"Credit limit Exceeded"<<endl;
}
cout<<"End? Y or N?\n> ";
cin>>End;
if(End=='Y'){ac=-1;}
}
}
