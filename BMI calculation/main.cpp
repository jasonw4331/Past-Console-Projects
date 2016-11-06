/*
9/28/2014
Intro to Programming
Project 2:  BMI Calculator
This project will calculate body mass index of subject based on entries provided.
*/

#include <iostream> /// For basic library
#include <iomanip>  /// For setprecision() command
#include <cmath> /// For advanced math functions
#include <string> /// For string usage
using namespace std; /// Standard namespace std

int main() /// Initializing main function

{
	string getName = ""; ///Used for getting subject name
	double getWeight = 0; /// Used for getting subject weight
	int getHeight = 0; /// Used for getting subject height
	double displayBmi = 0; /// Used for displaying BMI

	///Get name
	cout << "Enter your name: ";
	cin >> getName;

	///Get weight in pounds
	cout << "Enter your weight in pounds to one decimal point: ";
	cin >> getWeight;

	///Get height in inches
	cout << "Enter your height in inches: ";
	cin >> getHeight;

	///calculate and display BMI (Body mass index) display to one decimal place (setprecision(3))
	if (displayBmi<1){
    setprecision(3);
	}
	cout <<endl<<getName<<", your Body Mass Index (BMI) is: " <<displayBmi;
	cout << (703 * getWeight / pow(getHeight, 2.0));

		///Display weight category in if/else 18.5 to 25
		if (displayBmi <= 18.5){

		/// Output underweight
		cout <<endl<<getName<<", you are currently underweight, eat more!\n";
		}else if (displayBmi >= 25){

		/// Output overweight.
		cout <<endl<<getName<<", you are currently overweight.  It may be time to start an exercise regiment in conjunction with a good diet!\n";
		}else{
		/// Output optimal.
		cout <<endl<<getName<<", you are currently in the optimal BMI category, great job!\n";}
return 0;
}
