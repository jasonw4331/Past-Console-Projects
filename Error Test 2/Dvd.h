#include <iostream>
#include<string>

class Dvd
{
private:
int movieLength;
bool status;

public:
Dvd(int);
int getLength()const;
bool getStatus()const;
void setLength(int);
void setStatus(bool);
void checkStatus(int);

};