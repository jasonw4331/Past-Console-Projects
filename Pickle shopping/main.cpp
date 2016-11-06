#include <iostream>
#include <windows.h>
using namespace std;
int a,b;
void retry()
{while(true){
b=GetAsyncKeyState(VK_LEFT);
if(b){cout<<"YAY Pickles!"<<endl; break;}}}
int main()
{
    system("color 72");
    cout << "Shopping List:      Pickles" << endl<<endl;
    cout<<"<-- Vegetables\n    Fruit & More -->"<<endl;
    cout<<"Please use arrow keys."<<endl;
    system("pause");
    while(true){
    a=GetAsyncKeyState(VK_RIGHT); b=GetAsyncKeyState(VK_LEFT);
    if(a){
    cout<<"Try The other section..."<<endl; retry(); break;}else
    if(b){
    cout<<"YAY Pickles!"<<endl; break;}
}
system("pause");
}
