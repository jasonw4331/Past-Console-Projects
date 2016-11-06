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

class enemy{
	public:
		void genRandEnemy();
		void genRandDragon();
		void genRandBoss();
};

void genRandEnemy() {

	string enemy[] = {"troll", "wolf", "wraith", "spider", "scorpion", "hydra", "snake", "reaper", "centipede", "worm"};
	string enemyType[] = {"hell", "ice", "soul eater", "bone", "carnivorous"};

	srand(time(0));
	int randomEnemy = rand();
	int randomEnemyType = rand();

	int randEnemy = (randomEnemy % 10);
	int randEnemyType = (randomEnemyType % 5);

	cout << enemyType[randEnemyType];
	cout << " ";
	cout << enemy[randEnemy];

}

void genRandDragon() {
	string dragon = "dragon";
	string dragonType[] = {"hell", "soul crusher", "ice", "acient", "elder", "bone", "reaper"};

	srand(time(0));
	int randomDragonType = rand();
	int randDragonType = (randomDragonType % 7);

	cout << dragonType[randDragonType];
	cout << " ";
	cout << dragon;
}

void genRandBoss() {
	string boss[] = {"neom", "phatom"};
	string bossType[] = {"bone", "soul eater", "water", "hell", "ice"};

	srand(time(0));
	int randomBoss = rand();
	int randomBossType = rand();

	int randBoss = (randomBoss % 2);
	int randBossType = (randomBossType % 6);

	cout << bossType[randBossType];
	cout << " ";
	cout << boss[randBoss];
}
