#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main()
{
            srand(time(NULL));
    int b = 1+(rand()%5);
    int x;
    cout << "This is a passcode lock.\nYou have  to find the correct password between 1 and 10 in three tries.";
    cout << "\n\nenter password:\n";
    cin >> x;
    if(x==b){
        cout << "password accepted\n\nYOU WIN!";
    }else{
        cout << "Password denied!\n\n   Retry: ";


        for(int c=0; c < 2; c++){
            cin >> x;
    if(x==b){
        cout << "password accepted\n\nYOU WIN!";
}else{cout << "Password denied!\nProgram Ended!";}}}
Sleep(1000);
system("cls");
system("pause");
return 0;
}
