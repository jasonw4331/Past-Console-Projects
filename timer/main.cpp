#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <conio.h>
using namespace std;

int main()
{
    int a=0;
    int b=0;
    int d=0;
    cout << "Enter how long that you want this timer to run in seconds\n";
    cout << "Remember, 2700 is 45 minutes\n          1800 is 30 minutes\n           900 is 15 minutes\n            60 is one minute\n          ";
    cin >> a;
    system("cls");

                //loop does end
        while(b!=a){
        system("color 0c");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                  " << a << endl;
        Sleep(1000);
        system("cls ");
        a--;
}
        system("color 1f");
        while(d!=1){cout << "TIMER COMPLETE!\7\n";
        Sleep(1000);
        system("cls");
        cout << "Hit the SpaceBar!\7";
        Sleep(500);
        system("cls");
        if(GetAsyncKeyState(VK_SPACE)){d=1;}
        }
}
