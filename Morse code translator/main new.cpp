#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <cctype>
#include <string>
using namespace std;
string morse_codes[]=
{
  ".-",    "-...",  "-.-.",  "-..",   ".",     /// A-E
  "..-.",  "--.",   "....",  "..",    ".---",  /// F-J
  "-.-",   ".-..",  "--",    "-.",    "---",   /// K-O
  ".--.",  "--.-",  ".-.",   "...",   "-",     /// P-T
  "..-",   "...-",  ".--",   "-..-",  "-.--",  /// U-Y
  "--..",                                      /// Z
  "-----", ".----", "..---", "...--", "....-", /// 0-4
  ".....", "-....", "--...", "---..", "----.", /// 5-9
};
string English_To_Morse( string s )
{
  string result;
  for (int i = 0; i < s.length(); i++)
  {
    result += /// convert s[ i ] to a morse sequence. (Hint: use a function!)
    result += ' ';
  }
  return result.substr( 0, result.length() - 1 );  /// (skip the last space)
}
string English_To_Morse_1( char letter_or_digit )
{
  /// Is it a letter?
  if (isalpha( letter_or_digit ))
    /// Yes. Convert the letter to uppercase and find it's difference with 'A' to index the correct Morse sequence.
    return morse_codes[ toupper( letter_or_digit ) - 'A' ];

  /// Is it a digit?
  if (isdigit( letter_or_digit ))
    /// Yes. Find the difference between it an '0' and don't forget the offset in the table of the digits.
    return morse_codes[ 26 + letter_or_digit - '0' ];

  /// It is not a letter or a digit, so it turns into... nothing!
  return "";
}
char Morse_To_English_1( string s )
{
  int i = index of s in morse[];  /// you can figure out how to do this! (hint: use a loop)

  /// Was it a letter?
  if (i < 26)
    /// Yes. Add the offset to 'A' to get the correct letter.
    return 'A' + i;

  /// Was it a digit?
  if ((i - 26) < 10)
    /// Yes. Add the offset to '0' to get the correct digit.
    return '0' + i - 26;

  /// It was not a letter or a digit, so it turns into... nothing!
  return ' ';
}
string Morse_To_English( string s )
{
  string result;
  int i = 0;

  /// So long as we have characters left in s to examine...
  while (i < s.length())
  {
    /// Skip all leading spaces
    while ((i < s.length()) && isspace( s[ i ] )) i++;

    /// Gather the next code (ending with the next space or the end of the string) into current_code
    string current_code;
    while ((i < s.length()) && !isspace( s[ i ] ))
    {
      current_code += s[ i ];
      i++;
    }

    /// At this point, we should have something in current_code that can (potentially) be turned into a letter or digit.
    result += /// convert the current code into a letter or digit (Hint: Use the function!)
  }
  return result;
}
int main ()
{
	int c;
	string userinput;
	cout<<"Enter 1 for text to morse. 2 for morse to text\n";
	cout<<"Choice: ";
	cin>>c;

	while (c==1){
		getline(cin, userinput);
		string out="";
		for(int i=0; i<userinput.length(); i++)
		{
			out+= texttomorse(userinput[i]);
		}
		cout<< out << endl;}

	while (c==2){
		getline(cin, userinput);
		string out="";
		for(int i=0; i<userinput.length(); i++)
		{
			out+= morsetotext(userinput[i]);
		}
		cout<< out << endl;}
return 0;}
