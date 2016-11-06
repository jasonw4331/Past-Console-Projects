#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

int main(){

int yaxis[10][1] = {{1},{2},{3},{4},{5},{6},{7},{8},{9}};
int xaxis[1][10] = {{1,2,3,4,5,6,7,8,9}};



for(int x = 0; x < 9; x++){
    for(int i = 0; i < 9; i++){
    cout << setw(4) << yaxis[x][0] * xaxis[0][i] ;
        }
    cout << endl;
    }
system("pause");
    return 0;
}
