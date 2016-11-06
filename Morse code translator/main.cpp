#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <cctype>
#include <string>
using namespace std;
string texttomorse(char l)
{
		string text = "abcdefghijklmnopqrstuvwqyz 1234567890"; ///each letter of the alphabet, a space, and numbers 0-9
		string morse[] ={
						" .-"," -..."," -.-."," -..", " .", " ..-.", " --.",
						" ....", " ..", " .---", " -.-", " .-..", " --",
						" -.", " ---", " .--.", " --.-", " .-.", " ...", " -",
						" ..-", " ...-", " .--", " -..-", " -.--", " --..","  ",
						" .----", " ..---", " ...--", " ....-", " .....", " -....",
						" --...", " ---..", " ----.", " -----",/// Each letter and number in Morse
						};
		int index = text.find(l);///gets character from input and finds its Morse equivalent
			if(index!=-1)
				return morse[index];
			else
				return " ";}
string morsetotext(char l)
{
		string text[] = {"a","b","c","d", "e", "f", "g", "h", "i", "j", "k", "l", "m","n","o","p","q","r","s","t","u","v","w","q","y","z"," ","1","2","3","4","5","6","7","8","9","0"}; //each letter of the alphabet, a space, and numbers 0-9
		string morse={
					".-/ -.../ -.-./ -../ ./ ..-./ --./ ..../ ../ .---/ -.-/ .-../ --/ -./ ---/ .--./ --.-/ .-./ .../ -/ ..-/ ...-/ .--/ -..-/ -.--/ --../  / .----/ ..---/ ...--/ ....-/ ...../ -..../ --.../ ---../ ----./ -----"
}; /// Each letter and number in Morse
		int index = morse.find(l);///gets character from input and finds its Morse equivalent
			if(index!=-1)
				return text[index];
			else
				return " ";}
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
