#include <iostream>
#include <windows.h>
using namespace std;
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
WORD wOldColorAttrs = csbiInfo.wAttributes;
void DrawRowOfNonLitStars() ///Not Lit Star
{
cout<<endl;
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\t    *   \t    *   \t    *   \t    *   \t    *   \t    *   \t    *   "<<endl;
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
cout<<"\t    ^\t            ^\t            ^\t            ^\t            ^\t            ^\t            ^"<<endl
    <<"\t   /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\"<<endl
    <<"\t  //";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\"<<endl
    <<"\t ///";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\         ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\"<<endl
    <<"\t    ";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<""<<endl
    <<"-------------------------------------------------------------------------------------------------------------------"<<endl;
}
void DrawRowOfLitStars() ///Lit Star
{
cout<<"\t";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<" _ \\ / _\t _ \\ / _\t _ \\ / _\t _ \\ / _\t _ \\ / _\t _ \\ / _\t _ \\ / _"<<endl
    <<"\t _- * -_\t _- * -_\t _- * -_\t _- * -_\t _- * -_\t _- * -_\t _- * -_"<<endl;
           SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
cout<<"\t   ";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t           ";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t           ";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t           ";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t           ";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t           ";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t           ";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"/";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"^";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
cout<<"\\";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<""<<endl
    ///<<"\t   /_\\\t           /_\\\t           /_\\\t           /_\\\t           /_\\\t           /_\\\t           /_\\"<<endl
    <<"\t   /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\\\t           /";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\"<<endl
    <<"\t  //";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\t          //";
SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\"<<endl
    <<"\t ///";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\\t ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\         ///";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\\\\\\"<<endl
    <<"\t    ";SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<"\t            ";
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED| BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout<<"|";SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN| BACKGROUND_RED | FOREGROUND_INTENSITY);cout<<""<<endl
    <<"-------------------------------------------------------------------------------------------------------------------"<<endl;
}
int main()
{
    system("color 4A");

    for(int a=0;a!=500;a++)
    {
        cout<<"\t\t\t\t\t    MERRY CHRISTMAS!"<<endl;
        for( int j = 0; j < 6; j++ )
        {
            if(a%2==0)
            {
                DrawRowOfNonLitStars();
            }
            else
            {
                DrawRowOfLitStars();
            }

        }
        Sleep(550);
        system("cls");
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    MERRY CHRISTMAS!"<<endl;
    //PG2();
    cout<<endl;
    system("pause");
    return 0;}
