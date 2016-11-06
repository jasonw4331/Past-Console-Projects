/// employee.cpp
#include <iostream>
#include "employee.h"
using namespace std;

// constructor for employee
Employee::Employee() :  firstName("John"), lastName("Doe"), eNumber(-1), eSalary(0), eHired(false)
{
    maxSalary = defaultSalary;
}

void Employee::displayInfo()
{
    cout     << "\nName: " << getFirstName() << " "
             << getLastName() << endl;
    cout     << "Employee ID: " << getID() << endl;
    cout     << "Hired: ";
    if(eHired)
        cout << "Yes"      << endl;
    else
        cout << "No"       << endl;
    cout     << "Salary: " << getSalary()    << endl;
}

void Employee::setFirstName(const string& f)
{
    firstName = f;
}

const string& Employee::getFirstName()
{
    return firstName;
}

void Employee::setLastName(const string& l)
{
    lastName = l;
}

const string& Employee::getLastName()
{
    return lastName;
}

void Employee::setID(int id)
{
    eNumber = id;
}

const int& Employee::getID()
{
    return eNumber;
}

void Employee::promote(int raise)
{
    if(eHired)
    {
    eSalary += raise;
    maxSalary += raise;
    cout << firstName << " " << lastName <<" has been promoted."
         << "\nand has been given a $" << raise << " raise." << endl;
    }
    else
        cout << "Sorry. Cannot promote non-employees." << endl;

}

void Employee::demote(int cut)
{
    if(!eHired)
    {
         cout << "Sorry, cannot demote non-employees." << endl;
         return;
    }
    if(eHired && eSalary > 10000)
    {
    eSalary -= cut;
    maxSalary -= cut;
    cout << firstName << " " << lastName <<" has been demoted."
         << "\nand has had $" << cut << " cut from salary." << endl;
    }
    else
        cout << "Sorry. Cannot cut salary below $10,000." << endl;
}

void Employee::hire()
{
    if(!eHired)
    {
    eHired = true;
    eSalary = maxSalary;
    cout << firstName << " " << lastName <<" is hired!" << endl;
    }
else
    cout << "Employee is already hired!" << endl;
}

void Employee::fire()
{
    if(eHired)
    {
    eHired = false;
    eSalary = 0;
    cout << firstName << " " << lastName <<" is fired!" << endl;
    }
    else
        cout << "Cannot fire. Employee is not currently employed."
             << endl;
}

const bool& Employee::getHiredStatus()
{
    return eHired;
}

const int& Employee::getSalary()
{
    return eSalary;
}
