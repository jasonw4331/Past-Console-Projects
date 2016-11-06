// Programmed by Anthony Altreb. Date 10-16-12
//Reprogramed by jasonwynn10. Date 9-5-14
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;


int main ()

{
    srand(rand());
	int magic;// magic number.
	int guess;// user's guess.
	int c=0;// the amount of right guesses
	magic=rand()%20+1;//get a random number. between 0-19 then adds one.


	string name;
    int flag=1;

	 cout<<"Please enter your name \n";
	cin>>name;
	cout<<" Hello\n "<< name <<" you have 5 chances to guess the right value for 7 DIFFERENT numbers.\n";



	// This is the for loop that will control how many magic number values you have to guess
    for (int guesschance=1; guesschance < 8;guesschance++)

	{

	    cout << "Please keep your numbers within the range of 1-20.\n";

		// This is the for loop that will control the number of chances you get to guess the value.

		magic=rand()%20+1;

		for (int guessnum=1; guessnum < 6; guessnum++)

		{
			cout<<"Please enter guess #" <<guessnum<<" for guess value "<<guesschance<<": "; // The prompt message.

			// Obtain a guess value from user.

			cin>>guess;



				if (guess==magic && flag==1)

				{

					// Prompt message that tells user that their guess value was correct.

					cout<<"\n***You are well built, my respects!!!***\nMagic Number was"<<' '<<magic<<"!\n";

					// Prompt message that tells the user at which attempt the user guessed correctly.

					cout<<"Your guess was the #"<< guessnum <<" attempt.\n";

					// The expression is rechecked and found to be false thus breaking out of this block of code and ends the program.

					guessnum=6;

				}

				else

				{

					cout<<"\n...Sorry, you are wrong, please try again! \n"; // prompt message that lets user know their guess value was incorrect.

					if (guess>magic) cout<<"\nYour approximation has exceeded my expectation. Please lower your guess value.\n";
					// prompt message that lets user know their guess value was too high

					else cout<<"\nYour approximation is far lower then I expected. Please raise the value of your guess.\n"<<endl;
					// prompt message that lets user know their guess value was too low.

				}

				if (guessnum==5 && magic!=guess)

				{
					cout<<"The magic number was "<<magic<<endl;
				}
				Sleep(2000);
				system("cls");
		}
	    c++;
	    system("pause");
	    system("cls");

}
cout<<name<<", your success rate was "<< (c/7)*100<<"%"<<endl;
	return 0; // end of program.

}
