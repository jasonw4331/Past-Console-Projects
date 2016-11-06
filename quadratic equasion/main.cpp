///The driver for this:  driver.cpp
///----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include "Quadratic.h"

///constructor to initialize the private variables
///pre: values to be assigned (zeros) to a, b, and c are passed
///post: Initialize the values of a, b, and c with 0's

Quadratic::Quadratic() : a(0), b(0), c(0) {}

///Function to set the value of the member variables
///pre: values to be assigned to a, b, and c are passed
///post: Initialize the values of a, b, and c with passed values

void Quadratic::set(double cdblA, double cdblB, double cdblC)
{
     a = cdblA;
     b = cdblB;
     c = cdblC;
}

///Function to get the value of the member variable a
///post: Return the value stored in variable a

double Quadratic::get_a() const
{
     return a;
}

///Function to get the value of the member variable b
///post: Return the value stored in variable b

double Quadratic::get_b() const
{
     return b;
}

///Function to get the value of the member variable c
///post: Return the value stored in variable c

double Quadratic::get_c() const
{
     return c;
}

///Function to evaluate the value of the quadratic expression
///for given value of x
///pre: The parameter is value x
///post: Evaluate the quadratic expression and return the value

double Quadratic::evaluate(double x) const
{
     return (a * x * x) + (b * x) + c;
}

///Function to add two quadratic expressions
///pre: The parameter the objects q1 and q2
///post: Add q1 and q2 and store the result in object q

Quadratic operator+(const Quadratic & q1, const Quadratic & q2)
{
     double a = q1.get_a() + q2.get_a();
     double b = q1.get_b() + q2.get_b();
     double c = q1.get_c() + q2.get_c();
     Quadratic q;
     q.set(a, b, c);
     return q;
}

///Function to multiply the quadratic expression with a constant
///pre: r has been assigned
///post: Multiply q with a constant r and store it in q1, return q1

Quadratic operator*(double r, const Quadratic & q )
{
     double a = r * q.get_a();
     double b = r * q.get_b();
     double c = r * q.get_c();
     Quadratic q1;
     q1.set(a, b, c);
     return q1;
}

///Function to find the number of real roots to the quadratic equation
///post: Return the number of real roots

int Quadratic::real_root() const
{
     double x1 = 0.0;
     double x2 = 0.0;
     int real_root;
     ///If a, b and c are all zero, then every value of x is a real root.
     if(a == 0 && b == 0 && c == 0)
     {
          real_root = -1;
     }
     ///If a and b are zero and c is non-zero, then there are no real roots.
     else if(a == 0 && b == 0 && c != 0)
     {
          real_root = 0;
     }
     ///If a is zero and b is non-zero, then the only real root is x = -c/b.
     else if(a == 0 && b != 0)
     {
          real_root = 1;
     }
     ///If a is non-zero and b^2 < 4ac, then there are no real roots.
     else if(a != 0 && b*b < (4*a*c))
     {
          real_root = 0;
     }
     ///If a is non-zero and b^2 = 4ac, then there is one real root x = -b/2a.
     else if(a != 0 && b*b == (4*a*c))
     {
          real_root = 1;
     }
     ///If a is non-zero and b2 > 4ac, then there are two real roots.
     else if(a != 0 && b*b > (4*a*c))
     {
          real_root = 2;
     }
     return real_root;
}

///Function to find larger real root of the quadratic equation
///post: Return the larger real root

double Quadratic::larger_root() const
{
     double larger;
     assert(real_root()>0);
     ///If a is zero and b is non-zero, then the only real root is x = -c/b.
     if(a == 0 && b != 0)
          larger = -c/b;
     else if(a != 0 && b*b == (4*a*c))
          larger = -b/2*a;
     ///If a is non-zero and b2 > 4ac, then there are two real roots.
     else if(a != 0 && b*b > (4*a*c))
          larger = (-b + (sqrt(pow(b,2)-(4*a*c))))/(2*a);
     return larger; }

///Function to find smaller real root of the quadratic equation
///post: Return the smaller real root

double Quadratic::smaller_root()const
{      double smaller;
     assert(real_root()>0);
     ///If a is zero and b is non-zero, then the only real root is x = -c/b.
     if(a == 0 && b != 0)
          smaller = -c/b;
     else if(a != 0 && b*b == (4*a*c))
          smaller = -b/2*a;
     ///If a is non-zero and b2 > 4ac, then there are two real roots.
     else if(a != 0 && b*b > (4*a*c))
          smaller = (-b - (sqrt(pow(b,2)-(4*a*c))))/(2*a);
     return smaller; }

///Function to display quadratic equation
///post: display the quadratic equation in standard form

void Quadratic::display() const
{      cout << a << " X^2 + "<< b << " X + " <<c; }

///***************************************************************
/// Function: main
///***************************************************************
int main()

{
     ///create object of type class Quadratic
     Quadratic q,res;
     double a, b, c, value;
     char ch = 'y';
     do
     {
          ///prompt the user to enter values of a, b, and c
          ///read the values entered by the uses
          cout<<"Enter values of co-efficient of quadratic equation..."<<endl;
          cout<<"a: ";
          cin>>a;

          cout<<"b: ";
          cin>>b;

          cout<<"c: ";
          cin>>c;

          ///assign the values
          q.set(a,b,c);

          ///display quadratic equation
          cout<<"The quadratic equation is ";
          q.display();
          cout<<" ...!"<<endl;

          ///display roots
          cout<<"Larger root is : "<<q.larger_root()<<endl;
          cout<<"Smaller root is : "<<q.smaller_root()<<endl;
          cout<<"Do you want to find roots to another equation "
              <<"(press 'y' to continue) : ";
          cin>>ch;
     }
          while(ch=='y'||ch=='Y');

     ///display quadratic equation
     cout<<"The quadratic equation is ";
     q.display();
     cout<<"!"<<endl;
     cout<<"Enter a value to multiply : ";
     cin>>value;
     res = value*q;
     cout<<"The resultant quadratic equation is ";
     res.display();
     cout<<" ...!"<<endl;
     cout<<"Enter a value to evaluate : ";
     cin>>value;
     cout<<"The result is "<<q.evaluate(value)<<endl;

     ///to halt the system
     system("PAUSE");
     return 0;
}
