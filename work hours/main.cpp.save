#include <iostream>
#include <windows.h>
using namespace std;

int main ()
 {
 int regHours; // Regular Hours
 float hourlyPay, gross, otime, socialtax, federaltax, statetax, uniondues, dep, health; // gross income, overtime, social tax, federal tax, state tax, union dues, depen covered, health insurance
double opay, sopay, fpay, spay, unpay, deppay, healthpay, netpay=0; // overtime scoial federal state union dependents and health withholdings including netpay

// Loop to do everything
{
cout << "Hello Employee" << endl;

cout << "Enter hours you have worked: ";
 cin >> regHours;

cout << "Enter hourly pay rate: $";
 cin >> hourlyPay;

cout << "Enter overtime rate: " ;
 cin >> otime;

cout << "Enter percentage to be withheld for social security tax in decimal form: ";
 cin >> socialtax;

cout << "Enter percentage to be withheld for federal income tax in decimal form: ";
 cin >> federaltax;

cout << "Enter percentage to be withheld for state income tax in decimal form: ";
 cin >> statetax;

cout << "Enter Union dues: ";
 cin >> uniondues;

cout << "Enter number of dependents covered: ";
 cin >> dep;

cout << "Enter additional health insurance expence: ";
 cin >> health;


 gross = regHours * hourlyPay; //Grosspay
 {gross += (regHours - 40) * otime * hourlyPay;}
 opay = regHours * 1.5; //Over time hours
 sopay = gross * socialtax; //Social income tax withholdings
 fpay = gross * federaltax; //Federal income tax withholdings
 spay = gross * statetax; //State withholdings
 unpay = gross - uniondues; //Union Dues
 deppay = gross - healthpay; //Number of dependents covered
 healthpay = gross - health; //Addition health insurance expence
 if( deppay >= 3 ){healthpay = gross - 10;}
 netpay = gross - opay - sopay - fpay - spay - deppay - healthpay; //Netpay

 cout << "Weekly Report: \n\n";
 cout << "Regular Hours: " << regHours << endl;
 cout << "Gross Pay: $" << gross << endl;
 cout << "Social income tax: $" << sopay << endl;
 cout << "Federal income tax: $" << fpay << endl;
 cout << "Union dues: $" << unpay << endl;
 cout << "Number of dependents covered: $" << deppay << endl;
 cout << "Additional health insurace expence: $" << healthpay << endl;
 cout << "Net take home pay: $" << netpay << endl;}
 return 0;}
