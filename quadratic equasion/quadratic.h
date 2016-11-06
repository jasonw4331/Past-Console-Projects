#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/// class Quadratic declaration
class Quadratic
{
 private:
     double a, b, c;
 public:
      ///constructor to initialize the private variables
     ///post: Initialize the values of a, b, and c with 0's
        Quadratic();

     ///Function to set the value of the member variables
     ///pre: The parameters are values to be assigned to variables a, b, and c
     ///post: Initialize the values of a, b, and c with passed values

     void set(double cdblA, double cdblB, double cdblC);

     ///Function to get the value of the member variable a
     ///post: Return the value stored in variable a

     double get_a() const;

     ///Function to get the value of the member variable b
     ///post: Return the value stored in variable b

     double get_b() const;

     ///Function to get the value of the member variable c
     ///post: Return the value stored in variable c

     double get_c() const;

     ///Function to evaluate the value of the quadratic expression
     ///for given value of x
     ///pre: The parameter is value x
     ///post: Evaluate the quadratic expression and return the value

     double evaluate(double x) const;

     ///Function to find the number of real roots to the quadratic equation
     ///post: Return the number of real roots

     int real_root () const;

     ///Function to find larger real root of the quadratic equation
     ///post: Return the larger real root

     double larger_root () const;

    ///Function to find smaller real root of the quadratic equation
    ///post: Return the smaller real root

     double smaller_root () const;

     void display() const;
};
Quadratic operator+(const Quadratic&, const Quadratic&);
Quadratic operator*(const double, const Quadratic&);



