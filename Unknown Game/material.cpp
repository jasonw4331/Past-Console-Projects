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

class material{
	public:
		void getMaterial();
};

void material::getMaterial() {
		string material_[7] = {"wood", "stone", "iron", "steel", "gold", "mithril", "ebony"};
	
		srand(time(0));
		int randomMaterial = rand();
		int randMaterial = (randomMaterial % 7);
}