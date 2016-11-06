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

class armor{
	public:
		int getArmor();
};

	string armor_[] = {"helmet", "chestplate", "greives", "boots", "gauntlets"};

	srand(time(0));
	int randomArmor = rand();
	int randArmor = (randomArmor % 5);

int getArmor() {

	m.getMaterial();
	cout << " ";
	cout << armor_[randArmor];
}
