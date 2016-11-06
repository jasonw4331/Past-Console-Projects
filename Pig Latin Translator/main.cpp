#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

int main()
{
	std::cout << "Please enter a sentence: " << std::flush;
	std::string sentence;
	std::getline(std::cin, sentence);


	std::stringstream ss(sentence);
	std::string word;

	while (ss >> word)
	{
		///remove non alphabetic characters
		word.erase(std::remove_if(word.begin(), word.end(), [](char inChar) { return !isalpha(inChar); }), word.end());

		///move first character in word to the end of the word
		word.push_back(word.front());
		word.erase(word.begin());

		///make the entire word uppercase
		std::transform(word.begin(), word.end(), word.begin(), toupper);

		///print word
		std::cout << word << "AY ";
	}


	std::cin.ignore(10000, '\n');
	return 0;
}
