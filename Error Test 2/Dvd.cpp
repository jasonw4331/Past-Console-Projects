#include <iostream>
#include "Dvd.h"

using namespace std;

int Dvd::getLength()const
{
return movieLength;
}
Dvd::Dvd(int x)
{
movieLength = x;
status = true;
if (x<80 || x>150)
{
cout << "This movie will cause the Dvd player to turn off before it finishes. " << endl;
return;
}

}
bool Dvd::getStatus()const
{
return status;
}
void Dvd::setLength(int x)
{
movieLength = x;
}
void Dvd::setStatus(bool status)
{
this->status = status;
}
void Dvd::checkStatus(int time)
{
if (time > movieLength)
{
status = false;
}
}
