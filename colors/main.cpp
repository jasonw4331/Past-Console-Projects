#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()
{
    char color;

    system("color j3");
    system("pause");
    cout << "press the number coordinated with the color\n      DO NOT USE LETTERS\n";
    cin >> color;
    system("CLS");
    switch(color){
    case 00:
        system("color 00");
    break;
    case 1:
        system("color 01");
    break;
    case 2:
        system("color 02");
    break;
    case 3:
        system("color 03");
    break;
    case 4:
        system("color 04");
    break;
    case 5:
        system("color 05");
    break;
    case 6:
        system("color 06");
    break;
    case 7:
        system("color 07");
    break;
    case 8:
        system("color 00");
    break;
    case 9:
        system("color 00");
    break;
    //case 0A:

  //  break;
}}
