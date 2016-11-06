#include <iostream>
#include <cstdlib>
#include <time.h>
#include <complex>


using namespace std;

int main()
{

  int cDay; // Current values
  int cMonth;
  int cYear;

  int bDay; // Birth values
  int bMonth;
  int bYear;








 // Current year, month, day
  cout << "Type in the current year: ";
  cin >> cYear;

  cout << "Type in the current month number: " ;
  cin >> cMonth;

  cout << "Type in the current day: ";
  cin >> cDay;

  // Birth year, month, day

  cout << "Type in your birth year: ";
  cin >> bYear;

  cout << "Type in the birth month: ";
  cin >> bMonth;

  cout << "Type in the birth day: ";
  cin >> bDay;

  int Alder = cYear - bYear;
  int ferdigAlder;


  if (bMonth > cMonth)
  {
      cout << "You are ";
cout << Alder - 1 ;
cout << " years old";
cin >> ferdigAlder;

  }
  else
  {
      cout << "You are ";
      cout << Alder;
      cout << " years old";
      cin >> ferdigAlder;

  }
  int foo = -foo;
  int ferdigManeder = cMonth - bMonth;
  cout << "You are";
  cout << ferdigManeder;
  cout << " months old";




  return 0;
}
