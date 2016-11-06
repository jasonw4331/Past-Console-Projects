#include <iostream>
#include <windows.h>
using namespace std;
int b=1;
char quit;
int answer;
void rev(int x);

int main() {
    int x;
do{
cout<<"Please enter the number\n> ";
    cin >> x;
    if ( x >= 0 ){rev (x);}
    else {x = (x*-1); cout << "-"; rev (x);}
    cout<<"\nDo you want to do it again? Y/N\n> ";
    cin>>quit;
    if(quit=='n'||quit=='N'){return 0;}
    system("cls");
    }while(b=1);
    return 0;}
void rev (int x){
int arr[100000];
int i=0;
    do {arr[i] = x % 10; i++; x = x / 10; }while (x != 0);
    for ( int j = 0; j < i; j++){cout <<  arr[j];}}
