#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
bool prime(int j);
void specific();
bool isPrime(int x);
void Pos_Neg();

int main()
{
string swtch;
char YorN='Y';
do{
system("cls");
cout<<"Which version? Pos/Neg Or between Specific Nums\n> ";
cin>>swtch;
if(swtch=="Pos/Neg"||swtch=="pos/neg"){Pos_Neg();}
else{specific();}
cout<<"\nAgain? Y/N\n> ";
cin>>YorN;
}while(YorN=='Y'||YorN=='y');
return 0;
}
void Pos_Neg()
{
int N;
cout<<"How many prime numbers do you want? Positive or Negative?\n> ";
cin>>N;
int count = 1;
int num = 2;

if(N<=0)
{
N=N*-1;
while (count <= N) {
if (isPrime(num)) {
cout << count << ": -" << num << endl;
count++;}num++;}
}else{
while (count <= N) {
if (isPrime(num)) {
cout << count << ":  " << num << endl;
count++;}num++;}}
return;}
bool isPrime(int x)
{
for (int i = 2; i <= x/2; i++){
if (x % i == 0){
return false;}}
return true;}
void specific()
{
int m,n;

cout<< "Please insert the number with which the series of number will start(Smaller):" << endl;
cin >> n;
cout << "Please insert the number with which the series of numbers will end(Larger):" << endl;
cin>> m;

cout << "The primes of this series of number are"<< endl;
for(int j = n; j <= m; j++)
{
if (prime(j)==true)
cout << j<<", ";
}
return;}
bool prime(int j)
{
if (j < 2) return false;
for(int i=2; i<= sqrt(j); i++) {
if ((j%i) == 0) return false;
}
return true;}
