/// database.cpp
#include <iostream>
#include <vector>
#include <memory>
#include "employee.h"
#include "database.h"
using namespace std;

Database::Database(){}

Employee Database::addEmployee()
{
    Employee e;
    string f;
    string l;
    cout << "Enter first name: ";
    getline(cin, f);
    cout << "Enter last name: ";
    getline(cin, l);
    e.setFirstName(f);
    e.setLastName(l);
    e.setID(idCurrentNumber++);
    myVector.push_back(e);
    cout << "Employee added!" << endl;
    return e;
}

Employee* Database::findEmployee()
{
    int id;
    cout << "Please enter ID Number for the employee: "
         << endl;
    cin >> id;
    for(auto& findId : myVector)
    {
        if (findId.getID() == id)
        {
            pE = &findId;
            return pE;
        }
    }
    cout << "Employee not found!" << endl;
    pE = nullptr;
    return pE;
}

void Database::hireEmployee()
{
    pE = findEmployee();
    if(pE)
        pE->hire();
}

void Database::fireEmployee()
{
    pE = findEmployee();
    if(pE)
        pE->fire();
}

void Database::promoteEmployee()
{
    pE = findEmployee();
    if(pE)
        pE->promote();
}

void Database::demoteEmployee()
{
    pE = findEmployee();
    if(pE)
        pE->demote();
}

void Database::displayEmployees()
{
    for(auto& view : myVector)
    {
        view.displayInfo();
    }
}
