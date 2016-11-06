#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <conio.h>
using namespace std;

int main()
{
    int a=1800;
    int b=0;
    int d=0;
        system("color 0c");
        Sleep(5000);

        while(b!=a){
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
