#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class weapon {
	public:
		int getWeapon();
		string weapon_[];
};

	string weapon_[] = {"dagger", "sword", "war hammer", "mace", "great sword", "battle axe", "war axe"};
	string bow[] = {"bow", "long bow", "recurve bow", "composite bow"};

	srand(time(0));
	int randomWeapon = rand();
	int randWeapon = (randomWeapon % 7);

	int randomBow = rand();
	int randBow = (randomBow % 4);

int getWeapon() {

	m.getMaterial();
	cout << " ";
	weapon_[randWeapon];
}
