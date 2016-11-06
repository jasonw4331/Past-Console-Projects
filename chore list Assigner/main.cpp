#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <ctime>
#include <windows.h>
#include <random>
using namespace std;

string addGame, removeGame,person1,person2;
vector<string> gameList;
vector<string>::iterator gameIter;
unsigned seed = time(NULL);
void reset();
int kids_number, userSelection = 0;
int numberOfGames = gameList.size(), a=0, choredivisions;
bool Reset;

void pushback()
{
    gameList.push_back("Sweep LR");
	gameList.push_back("Sweep Hall");
	gameList.push_back("Chrome");
	gameList.push_back("Trash");
	gameList.push_back("Kids Bathroom Toilet");
	gameList.push_back("kids Bathroom Sink");
	gameList.push_back("First Floor Bathroom Floor");
	gameList.push_back("First Floor Bathroom Mirror");
	gameList.push_back("First Floor Bathroom Toilet");
	gameList.push_back("Kids Bathroom Counter");
	gameList.push_back("Kids Bathroom Mirror");
	gameList.push_back("First Floor Bathroom Sink");
	///gameList.push_back("");
	sort(gameList.begin(), gameList.end());
	numberOfGames = gameList.size();

	Reset=true;

	}
void chore_assigner()
{
            cout<<"How many kids are here?\n";
            cin >> kids_number;

            choredivisions=numberOfGames/kids_number;
            shuffle (gameList.begin(), gameList.end(),default_random_engine(seed));
switch(kids_number){
    case 3:
            printf("Jason Has:\n");
            gameIter = gameList.begin();
while (a!=choredivisions) {
            cout <<"\t"<< *gameIter << endl;
            gameIter++;
            a++;
			}
			system("pause");
			a=0;
			printf("Faith Has:\n");
while (a!=choredivisions) {
            cout <<"\t"<< *gameIter << endl;
            gameIter++;
            a++;
			}
			system("pause");
			a=0;
			printf("Steven Has:\n");
while (a!=choredivisions) {
            cout <<"\t"<< *gameIter << endl;
            a++;
            gameIter++;}
            a=0;
			if(1==numberOfGames%kids_number){
        cout << "Unassigned Chore: " << *gameIter << endl;}
        else if(1<numberOfGames%kids_number){
while (a!=kids_number%numberOfGames) {
            if(){
            cout <<"Unassigned Chore: "<< *gameIter << endl;
            a++;
            gameIter++;}}}
        system("pause");
        Sleep(3000);
        break;
///===============================================================
    case 2:
        printf("Who is here?");
        cin>>person1;
        printf("Who else is here?");
        cin>>person2;
        cout<<person1<<" has:\n";
        gameIter = gameList.begin();
while (a!=choredivisions) {
            cout <<"\t"<< *gameIter << endl;
            gameIter++;
            a++;
			}
			system("pause");
			a=0;
			cout<<person2<<" has:\n";
while (a!=choredivisions) {
            cout <<"\t"<< *gameIter << endl;
            gameIter++;
            a++;
			}
			a=0;
			if(1==numberOfGames%kids_number){
        cout << "Unassigned Chore: " << *gameIter << endl;}
        else if(1<numberOfGames%kids_number){
while (a!=kids_number%numberOfGames) {
            if(){
            cout <<"Unassigned Chore: "<< *gameIter << endl;
            a++;
            gameIter++;}}}
        system("pause");
        break;
///=================================================================
    case 1:
        printf("Who is here?");
        cin>>person1;
        cout<<person1<<" has:\n";
        gameIter = gameList.begin();
while (a!=choredivisions) {
            cout <<"\t"<< *gameIter << endl;
            gameIter++;
            a++;
			}
			a=0;
			system("pause");
			if(1==numberOfGames%kids_number){
        cout << "Unassigned Chore: " << *gameIter << endl;}
        else if(1<numberOfGames%kids_number){
while (a!=kids_number%numberOfGames) {
            if(){
            cout <<"Unassigned Chore: "<< *gameIter << endl;
            a++;
            gameIter++;}}}
            system("pause");
            break;}
            reset();}
int main(void)
{
    if(Reset!=true){
    pushback();
    }
	cout << "Welcome to your Chore Assigner!\n" << endl;

	while (userSelection != 5) {

		cout << "Press 1 to add a Chore\n";
		cout << "Press 2 to remove a Chore\n";
		cout << "Press 3 to list all Chores\n";
		cout << "Press 4 to assign chores\n";
		cout << "Press 5 to quit\n" << endl;
		cout << "Type your option: ";
		cin >> userSelection;

		switch (userSelection) {
		case 1:   /// Add a title!
			cout << "\nType the names title to add: ";
			cin.get();
			getline(cin, addGame);
			gameList.push_back(addGame);
			cin.sync();
			numberOfGames++;
			cout << "\nChore successfully added.\n" << endl;
			system("pause");
			system("cls");
			break;
		case 2:   /// Remove a title!
            for (gameIter = gameList.begin(); gameIter != gameList.end(); ++gameIter) {
				cout <<"\t"<< *gameIter << endl;
			}
			cout << "\nType the Chores Exact title to remove.";

			cin.get();
			getline(cin, removeGame);
			gameIter = find(gameList.begin(), gameList.end(), removeGame);
			if (removeGame == *gameIter) {
				cout << "\nChore found!" << endl;
				gameList.erase(gameIter);
				numberOfGames--;
				cout << "Chore removed!\n" << endl;
			}
			else{
				cout << "Chore not found\n";

			}
			system("pause");
			system("cls");
			break;
		case 3:  ///List Chores
		    numberOfGames = gameList.size();
			cout << "\nYou currently have " << numberOfGames << " Chores in your list.\n" << endl;
			for (gameIter = gameList.begin(); gameIter != gameList.end(); ++gameIter) {
				cout <<"\t"<< *gameIter << endl;
			}
			cout << "\n";
			system("pause");
			system("cls");
			break;
        case 4:   ///Assign Chores
            chore_assigner();
            system("cls");
            break;
		case 5: ///end program
			cout << "Program shutdown.\n" << endl;
			system("cls");
			a=5;
			while (a!=0){
            cout << a;
            Sleep(1000);
            system("cls");
            a--;
			}
			return a;
			break;
		default:
			cout << "\nThat is not a valid selection.\n" << endl;
			break;}}return a;}
void reset()
{
    a=0;
    system("cls");
    main();}
