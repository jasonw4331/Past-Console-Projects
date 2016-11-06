// A program that controls a list of my favourite games
// When you get up, try splitting up the switch statement into seperate functions/methods
// Try completing the "remove a game" case. == Completed
// Implement number of games. == Partial

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

int main(){
	string addGame, removeGame;
	vector<string> gameList;
	vector<string>::iterator gameIter;

	gameList.push_back("Call Of Duty");
	gameList.push_back("Minecraft");
	gameList.push_back("C++");
	gameList.push_back("MCPE");
	gameList.push_back("Hay Day");
	gameList.push_back("Clash Of Clans");

	int numberOfGames = gameList.size();
	int userSelection = 0;

	cout << "Welcome to your Game List\n" << endl;

	while (userSelection != 4) {

		cout << "Press 1 to add a game\n";
		cout << "Press 2 to remove a game\n";
		cout << "Press 3 to list all games\n";
		cout << "Press 4 to quit\n" << endl;
		cout << "Type your option: ";
		cin >> userSelection;

		switch (userSelection) {
		case 1:												// Add a title!
			cout << "\nType the names title to add: ";
			cin.get();
			getline(cin, addGame);
			gameList.push_back(addGame);
			sort(gameList.begin(), gameList.end());
			cin.clear();
			cin.sync();
			numberOfGames += 1;
			cout << "\nGame successfully added.\n" << endl;
			break;
		case 2:												// Remove a title!
			cout << "\nType the names title to remove: ";
			cin.get();
			getline(cin, removeGame);
			gameIter = find(gameList.begin(), gameList.end(), removeGame);
			if (removeGame == *gameIter) {
				cout << "\nTitle found!" << endl;
				gameList.erase(gameIter);
				numberOfGames -= 1;
				cout << "Title removed!\n" << endl;
			}
			else {
				cout << "Title not found\n";
			}
			break;
		case 3:
			cout << "\nYou currently have " << numberOfGames << " games in your list.\n" << endl;
			for (gameIter = gameList.begin(); gameIter != gameList.end(); ++gameIter) {
				cout <<"\t"<< *gameIter << endl;
			}
			cout << "\n";
			break;
		case 4:
			cout << "Program shutdown.\n" << endl;
			userSelection = 4;
			break;
		default:
			cout << "\nThat is not a valid selection.\n" << endl;
			break;
		}
		system("pause");
        system("CLS");
	}

	return 0;
}
