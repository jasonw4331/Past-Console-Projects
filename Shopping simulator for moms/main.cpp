#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
string list2[]={"Pickles","Milk","OJ","Apples","Bananas","Grapes","Tomatoes","Carrots","Celery","Peanut Butter","Ice Cream","Cereal","Eggs","Egg Nog","Cheese"};
int main()
{
    cout <<"\t\t\t\tWelcome To Shopping Simulator!" <<endl
         <<"\t\t\t\t         (For Moms)           " <<endl;
    srand(time(NULL));
    cout<<rand()%7<<endl;
    cout<<rand()%7<<endl;
    cout<<rand()%7<<endl;
    system("pause"); system("cls");
    cout <<"\t\tList:"<<endl<<endl;
    for(int b;b!=5;b++){
    int a=rand()%7;
    cout<<"\t     "<<list2[a]<<endl;}
}
