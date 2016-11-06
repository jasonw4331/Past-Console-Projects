#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;
const int MAX_TRIES=8;
int triesleft=8,score=100;
int letterFill(char, string, string&);
string displayHangman(int num_of_wrong_guesses);
string displayHangingStation(int x);

int main()
{
string name;
char letter;
int num_of_wrong_guesses = 0;
string word;
string words[] =
{
"apple",
"orange",
"car",
"truck",
"bicycle",
"cat",
"dog",
"snake",
"rock",
"sock"
};

///choose and copy a word from array of words randomly
srand(time(NULL));
int n = rand() % 10;
word = words[n];

/// Initialize the secret word with the * character.
string unknown(word.length(), '*');


/// welcome the user
cout << "\n\n WELCOME TO THE HANGMAN GAME";
cout << "\n\n You have 8 attempts to try and guess the word.";

/// Loop until the guesses are used up
while (num_of_wrong_guesses <= triesleft)
{
cout << "\n\n" << unknown;
cout << "\n\nGuess a letter: ";
cin >> letter;
/// Fill secret word with letter if the guess is correct,
/// otherwise increment the number of wrong guesses.
if (letterFill(letter, word, unknown) == 0)
{
cout << endl << "Whoops! That letter is already there!" << endl;
cout << displayHangman(num_of_wrong_guesses) << endl;}
else{cout << endl << "Good job you found a new letter!" << endl;}

/// Tell user how many guesses has left.
cout << "You have " <<triesleft--;
cout << " guesses left." << endl;
/// Check if user guessed the word.
if (word == unknown)
{
if (word.length()-num_of_wrong_guesses==0)
{score=100;}
else if (word.length()-num_of_wrong_guesses==word.length()-1)
{score=95;}
else if (word.length()-num_of_wrong_guesses==word.length()-2)
{score=90;}
else if (word.length()-num_of_wrong_guesses==word.length()-3)
{score=75;}
else if (word.length()-num_of_wrong_guesses==word.length()-4)
{score=60;}
else if (word.length()-num_of_wrong_guesses==word.length()-5)
{score=45;}
else if (word.length()-num_of_wrong_guesses==word.length()-6)
{score=30;}
else if (word.length()-num_of_wrong_guesses==word.length()-7)
{score=15;}
else if (word.length()-num_of_wrong_guesses>=word.length()-8)
{score=0;}


cout << word << endl;
cout << "Yeah! You got it!\nYour Score was "<<score<<"%"<< endl;
break;
}
}

if (num_of_wrong_guesses >= triesleft)
{
cout << "\nSorry you lose :(\nYour Score was "<<score<<"%"<< endl;
cout << "The word was : " << word << endl;
}

cin.ignore();
cin.get();

/** Take a one character guess and the secret word, and fill in the
unfinished guess word. Returns number of characters matched.
Also, returns zero if the character is already guessed. */


}
int letterFill(char guess, string secretword, string &guessword)
{
int i;
int matches = 0;
int len = secretword.length();
for (i = 0; i< len; i++)
{
/// Did we already match this letter in a previous guess?
if (guess == guessword[i])
return 0;

/// Is the guess in the secret word?
if (guess == secretword[i])
{
guessword[i] = guess;
matches++;
}
}
return matches;
}
string displayHangman(int x)
{
cout<<"\n___________\n|_________|\n  |\n  |\n";
for (int i = 0; i < 10; i++)
{
if (x == 1)
{
return "  O";
}
if (x == 2)
{
return "  O\n  |";
}
if (x == 3)
{
return "  O\n  |\n  |";
}
if (x == 4)
{
return "  O\n  |\n  |\n /";
}
if (x == 5)
{
return "  O\n  |\n  |\n /\\";
}
if (x == 6)
{
return "  O\n -|\n  |\n /\\";
}
if (x == 7)
{
return "  O\n -|-\n  |\n /\\";
}
if (x == 8)
{
return "  O\n -|-\n  |\n /\\";
}
}
}
