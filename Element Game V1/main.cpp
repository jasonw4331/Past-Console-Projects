#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

void charselect(void);
void setplayer(void);
void fight(void);
void turnMenu(void);
void combat(void);
void checkdead(void);
void victory(void);
void printheader(void);
void windbody(void);
void hinder(void);
void attacking(void);
void cast1(void);
void cast2(void);
void cast3(void);
void passives(void);
void statuscheck(void);
void barrier(void);
void shadowbreak(void);
void absorb(void);
void record(void);
void aigo(void);

string Element[2]; // player 1 element
int health[2], armor[2], dodge[2], speed[2], power[2], energy[2]; // player 1 stats
string ability[2][3]; // player 1 placeholders for ablities
int cost[2][3];
string passive[2];
string status[2];
int statusduration[2];
int turn[2]; // player 1 turn variable
int winner; // for game end screen
int attack; // random number for damage
int a[2]; // ability set
int hit; // random number for dodging
int c, e; //current/enemy player
int thisturn;
int venom[2];
int mimic;
int charge;
int matchwin;
int matchloose;
int k, j;
int matchup[12][12];
int play;

int main() {
	play = 0;
	while(play == 0){
		system("pause");
		system("CLS");
		charselect();
		fight();
		victory();
		record();
		thisturn = 0;
		winner = 0;
	}
	system("pause");
	return 0;
}

void charselect() {

	Element[1].assign("none");
	c = 0;
	do {
		cout << "Player " << c + 1 << ", choose your element" << endl
			<< endl
			<< "           Health      Damage    Spell Damage Utility" << endl
			<< "Fire:      Medium      Medium    Medium-High  Medium" << endl
			<< "Water:     High        Low       High         High" << endl
			<< "Static:    Medium-High low       Medium-High  High" << endl
			<< "Holy:      Medium-Low  High      Medium-low   Medium" << endl
			<< "Wind:      Low         Low/High  Medium       High" << endl
			<< "Earth:     High        Medium    High         Medium-Low" << endl
			<< "Blood:     Medium-High High      Low          Medium-Low" << endl
			<< "Dark:      Medium      Very High None         High" << endl
			<< "Venom:     Medium-High Mid High  Low/High     Low" << endl
			<< "Swordsman: High        High      Low          Low" << endl
			<< "--------------------------------------------------" << endl
			<< "                             * 0  for random or ai" << endl
			<< endl
			<< "(use capital first letter)" << endl
			<< endl;
		cin >> Element[c];
		if (Element[c] == "0"){
			a[c] = (rand() % 10) + 1;
			switch (a[c]){
			case 1:
				Element[c] = "Fire";
				break;
			case 2:
				Element[c] = "Water";
				break;
			case 3:
				Element[c] = "Static";
				break;
			case 4:
				Element[c] = "Holy";
				break;
			case 5:
				Element[c] = "Wind";
				break;
			case 6:
				Element[c] = "S";
				break;
			case 7:
				Element[c] = "Earth";
				break;
			case 8:
				Element[c] = "Blood";
				break;
			case 9:
				Element[c] = "Dark";
				break;
			case 10:
				Element[c] = "Venom";
				break;
			}
		}
		setplayer();
		system("CLS");
		cout << Element[c] << " element:" << endl << endl
			<< "Health: " << health[c] << endl
			<< "Armor: " << armor[c] << endl
			<< "Speed: " << speed[c] << endl
			<< "Agility: " << dodge[c] << endl
			<< "Max damage: " << power[c] << endl
			<< "Max Energy: " << energy[c] << endl
			<< endl << "Ablilities" << endl
			<< ability[c][0] << " [" << cost[c][0] << "]" << endl
			<< ability[c][1] << " [" << cost[c][1] << "]" << endl
			<< ability[c][2] << " [" << cost[c][2] << "]" << endl
			<< endl << "Passive ablility: " << passive[c] << endl << endl;
		system("pause");
		system("CLS");

		c++;
	} while(c == 1);
}

void fight() {
	status[0].assign("Healthy");
	status[1].assign("Healthy");

	while (winner == 0){

		c = 0;
		cout << "Player 1 up next" << endl;
		turnMenu();
		c = 1;
		cout << "Player 2 up next" << endl;
		turnMenu();
		combat();
		energy[0]++;
		energy[1]++;

	}
}

void setplayer() {
	if (Element[c] == "Fire") {
		ability[c][0].assign("Blast"); // single turn damage 40
		ability[c][1].assign("Flame Thrower"); // single turn damage, stuns enemy if they are ignited, 45 damage
		ability[c][2].assign("Rain of Fire"); // high damage ablilty 120
		passive[c].assign("Ignite"); // ablities light an enemy on fire dealing 10 damage per turn for 2 turns, extra ablilities reset duration
		a[c] = 1;
		cost[c][0] = 2;
		cost[c][1] = 3;
		cost[c][2] = 6;
		health[c] = 200;
		armor[c] = 3;
		power[c] = 30;
		speed[c] = 50;
		dodge[c] = 20;
		energy[c] = 4;
	}
	else if (Element[c] == "Water") {
		ability[c][0].assign("Wave"); // 33 damage
		ability[c][1].assign("Barrier"); // halfs incoming damage and removes status effects
		ability[c][2].assign("Tsunami"); // high damage ability, halfs opponent damage for 2 turns 110
		passive[c].assign("Changing Tide");// one third of ability damage is returned as hp
		a[c] = 2;
		cost[c][0] = 2;
		cost[c][1] = 3;
		cost[c][2] = 6;
		health[c] = 250;
		armor[c] = 4;
		power[c] = 15;
		speed[c] = 40;
		dodge[c] = 20;
		energy[c] = 5;
	}
	else if (Element[c] == "Static") {
		ability[c][0].assign("Discharge");// drains all energy, deals 20 damage per 1 point of energy used
		ability[c][1].assign("Shock Absorb");// opposing ability damage heals you for this turn
		ability[c][2].assign("High Voltage");// 100 stun opponent for 2 turns
		passive[c].assign("Shock Guard"); // +1 extra energy from a successful guard (an attack must be blocked). guard blocks for 75% damage rather than 50%
		a[c] = 3;
		cost[c][0] = 0;
		cost[c][1] = 3;
		cost[c][2] = 7;
		health[c] = 230;
		armor[c] = 2;
		power[c] = 38;
		speed[c] = 55;
		dodge[c] = 25;
		energy[c] = 5;
	}
	else if (Element[c] == "Holy") {
		ability[c][0].assign("DivineBlessing");//heal 25 hp
		ability[c][1].assign("Hinder");// reduce enemy damage by 50% for 3 turns
		ability[c][2].assign("Smite");// 150 damage
		passive[c].assign("Cleanse");// remove opposing status effects at the end of battle phase
		a[c] = 4;
		cost[c][0] = 3;
		cost[c][1] = 4;
		cost[c][2] = 7;
		health[c] = 170;
		armor[c] = 4;
		power[c] = 38;
		speed[c] = 35;
		dodge[c] = 15;
		energy[c] = 5;
	}
	else if (Element[c] == "Wind") {
		ability[c][0].assign("Gust");// 20 damage, deals 3 damage per turn for a max of 5 turns
		ability[c][1].assign("Wind Charge");// increase dodge to 100% for this turn, increase attack damage to 75 for 3 turns (+50)
		ability[c][2].assign("Tempest");// increase dodge to 100% for 2 turns (this one included), deal 120 damage
		passive[c].assign("Wind Body");// dodge applies to spells
		a[c] = 5;
		cost[c][0] = 1;
		cost[c][1] = 4;
		cost[c][2] = 6;
		health[c] = 150;
		armor[c] = 3;
		power[c] = 25;
		speed[c] = 80;
		dodge[c] = 35;
		energy[c] = 3;
	}
	else if (Element[c] == "Earth") {
		ability[c][0].assign("Boulder"); // 20 damage, stun for 1 turn
		ability[c][1].assign("Shakedown"); // 30% enemy hp as damage
		ability[c][2].assign("Quake"); // 120 damage, 15 damage per turn until interrupted (10 turns max)
		passive[c].assign("Stone Skin");// armor applies to abilities with 1.5 multiplier
		a[c] = 7;
		cost[c][0] = 4;
		cost[c][1] = 6;
		cost[c][2] = 8;
		health[c] = 300;
		armor[c] = 6;
		power[c] = 30;
		speed[c] = 30;
		dodge[c] = 15;
		energy[c] = 3;
	}
	else if (Element[c] == "Blood") {
		ability[c][0].assign("Bleed"); // 5% enemy hp as damage for 3 turns
		ability[c][1].assign("Drain"); // steal 20 hp
		ability[c][2].assign("Ravage"); // 4x auto damage for 3 turns
		passive[c].assign("Vampirism"); // 20% damage dealt with attack returns as health
		a[c] = 8;
		cost[c][0] = 2;
		cost[c][1] = 4;
		cost[c][2] = 5;
		health[c] = 250;
		armor[c] = 3;
		power[c] = 35;
		speed[c] = 70;
		dodge[c] = 25;
		energy[c] = 2;
	}
	else if (Element[c] == "Dark") {
		ability[c][0].assign("Shadowmeld"); // 100% dodge for 1 turn
		ability[c][1].assign("Speed of Shadow"); // double attack
		ability[c][2].assign("Invading Black"); // heal 50 hp, triple attack
		passive[c].assign("Growing Death"); // attacks grant + 5 power
		a[c] = 9;
		cost[c][0] = 1;
		cost[c][1] = 3;
		cost[c][2] = 7;
		health[c] = 200;
		armor[c] = 3;
		power[c] = 30;
		speed[c] = 65;
		dodge[c] = 20;
		energy[c] = 3;
	}
	else if (Element[c] == "Venom") {
		ability[c][0].assign("Ignition"); // 15 damage to enemy per stack of venom
		ability[c][1].assign("Hidden"); // avoid damage this turn, + 30 (flat) damage next attack
		ability[c][2].assign("Piercing shot"); // 10 damage per stack + 50. stun enemy for 1 turn, apply 3 stacks
		passive[c].assign("Corrosion"); // stacking poison with attacks, 5 per stack
		a[c] = 10;
		cost[c][0] = 3;
		cost[c][1] = 4;
		cost[c][2] = 5;
		health[c] = 230;
		armor[c] = 2;
		power[c] = 30;
		speed[c] = 55;
		dodge[c] = 25;
		energy[c] = 4;
	}
	else if (Element[c] == "ManaBurn") {
		ability[c][0].assign("Phase Shift"); // dodge enemy ability, gain energy = to energy cost of ability dodged
		ability[c][1].assign("Energy Drain"); // damage enemy based on 2 x their energy every turn until interrupted (or 10 turns), get healed for the same ammount
		ability[c][2].assign("Recoil"); // reduce enemy mana to 0, 60 damage + 10 * enemy mana
		passive[c].assign("Mana Blast"); // gain flat damage to auto attack = 1/2 the cost of all abilities cast
		a[c] = 12;
		cost[c][0] = 2;
		cost[c][1] = 4;
		cost[c][2] = 6;
		health[c] = 230;
		armor[c] = 2;
		power[c] = 25;
		speed[c] = 100;
		dodge[c] = 30;
		energy[c] = 4;
	}
	else if (Element[c] == "1029384756") {
		Element[c].assign("Morphling");
		ability[c][0].assign("Morph 1");
		ability[c][1].assign("Morph 2");
		ability[c][2].assign("Morph 3");
		passive[c].assign("Energy Absorbtion"); // enemy abilities give half the cost in energy to the morphling
		a[c] = 11;
		cost[c][0] = 4;
		cost[c][1] = 6;
		cost[c][2] = 8;
		health[c] = 250;
		armor[c] = 3;
		power[c] = 25;
		speed[c] = 60;
		dodge[c] = 20;
		energy[c] = 0;
	}
	else {
		Element[c].assign("Swordsman");
		ability[c][0].assign("Focus Strike"); // deals 25 damage
		ability[c][1].assign("Meditate"); // recover 30 hp
		ability[c][2].assign("Execution"); // 40% of your missing hp as damage
		passive[c].assign("Valor"); // recover 3 hp per turn
		a[c] = 6;
		cost[c][0] = 1;
		cost[c][1] = 4;
		cost[c][2] = 5;
		health[c] = 300;
		armor[c] = 5;
		power[c] = 60;
		speed[c] = 60;
		dodge[c] = 30;
		energy[c] = 3;
	}
}

void turnMenu() {
	system("CLS");
	printheader();
	cout << "\t\t[" << Element[c] << " element's turn:]" << endl
		<< endl
		<< "\t _______________________________________________________" << endl
		<< "\t|                                                       |" << endl
		<< "\t|\t(1) Attack\t\t(2) Guard\t\t|" << endl
		<< "\t|\t\t\t\t\t\t\t|" << endl
		<< "\t|\t(3) " << ability[c][0] << "[" << cost[c][0] << "]" << "\t\t(4) " << ability[c][1] << "[" << cost[c][1] << "]\t\t|" << endl
		<< "\t|\t\t\t\t\t\t\t|" << endl
		<< "\t|\t(5) " << ability[c][2] << "[" << cost[c][2] << "]\t\t(6) Surrender\t\t|" << endl
		<< "\t|_______________________________________________________|" << endl
		<< endl
		<< "\t\t\tYour Move:\t";
	cin >> turn[c];
	if ((a[c] == 11) && (turn[c] == 3 || turn[c] == 4 || turn[c] == 5)){
		cout << "Mimic:\t";
		cin >> mimic;
	}
}

void combat() {

	c = 0;
	e = 1;
	if (turn[c] == 0){
		aigo();
	}
	c = 1;
	e = 0;
	if (turn[c] == 0){
		aigo();
	}

	thisturn = rand() % (speed[0] + speed[1]);

	if (thisturn > speed[0]) {
		c = 1;
		e = 0;
	}
	else {
		c = 0;
		e = 1;
	}
	if ((turn[c] == 4 && a[c] == 2) || (turn[c] == 4 && mimic == 2 && a[c] == 11)){
		status[c].assign("Shielded");
		statusduration[c] = 10;
		cout << "Player " << c + 1 << " puts up a water barrier" << endl;
		attack = 0;
	}
	if (turn[c] == 5 && a[c] == 8){
		status[c].assign("Healthy");
	}
	if (health[0] > 0 && health[1] > 0) {
		if (status[c] == "Stunned"){
			cout << "Player " << c + 1 << " is stunned and cannot act" << endl;
		}

		else{
			switch (turn[c]){
			case 1:
				attacking();
				break;

			case 2:
				cout << "Player " << c + 1 << " protects themselves." << endl;
				break;

			case 3:
				cast1();
				break;

			case 4:
				cast2();
				break;

			case 5:
				cast3();
				break;

			case 6:
				health[c] = 0;
				cout << "Player " << c + 1 << " surrenders" << endl;
				break;
			default:
				cout << "Player " << c + 1 << " sits idle" << endl;
				break;
			}
		}
		absorb();
		statuscheck();
	}
	if (c == 0){
		c = 1;
		e = 0;
	}
	else {
		c = 0;
		e = 1;
	}
	if ((turn[c] == 4 && a[c] == 2) || (turn[c] == 4 && mimic == 2 && a[c] == 11)){
		status[c].assign("Shielded");
		statusduration[c] = 10;
		cout << "Player " << c + 1 << " puts up a water barrier" << endl;
		attack = 0;
	}
	if (turn[c] == 5 && a[c] == 8){
		status[c].assign("Healthy");
	}
	if (health[0] > 0 && health[1] > 0) {
		if (status[c] == "Stunned"){
			cout << "Player " << c + 1 << " is stunned and cannot act" << endl;
		}
		else {
			switch (turn[c]){

			case 1:
				attacking();
				checkdead();
				break;

			case 2:
				cout << "Player " << c + 1 << " protects themselves." << endl;
				break;

			case 3:
				cast1();
				checkdead();
				break;

			case 4:
				cast2();
				checkdead();
				break;

			case 5:
				cast3();
				checkdead();
				break;

			case 6:
				health[c] = 0;
				cout << "Player " << c + 1 << " surrenders" << endl;
				checkdead();
				break;

			}
		}
		absorb();
		statuscheck();
		c = 0;
		e = 1;
		passives();
		checkdead();
		c = 1;
		e = 0;
		passives();
		checkdead();
	}
	cout << endl << endl;
	checkdead();
	system("pause");
}

void checkdead() {

	if (health[0] <= 0) {
		cout << "Player 1 has been slain" << endl;
		winner = 2;
		matchwin = a[1];
		matchloose = a[0];
		system("pause");
	}
	if (health[1] <= 0) {
		cout << "Player 2 has been slain" << endl;
		winner = 1;
		matchwin = a[0];
		matchloose = a[1];
		system("pause");
	}

}

void victory() {

	system ("CLS");
	cout << "Player " << winner << " has defeated their opponent and achieved victory!" << endl << endl;

}

void printheader() {

	cout << "Player " << c + 1 << " is up next" << endl
		<< endl;
	system("pause");
	system("CLS");
	cout << Element[0] << " Element: \t\t|\t\t" << Element[1] << " Element" << endl
		<< "[\t" << health[0] << "\t]\t|\t\t[\t" << health[1] << "\t]" << endl
		<< "\t[ " << status[0] << " ]\t|\t\t[ " << status[1] << " ]" << endl
		<< "\t[ " << energy[0] << " ]\t\t|\t\t[ " << energy[1] << " ]" << endl
		<< "..................................................................." << endl
		<< endl;
}

void windbody(){
	if (passive[e] == "Wind Body"){
		hit = 1 + rand() % 100;
		if (hit < dodge[e]){
			attack = 0;
		}
	}
	if (passive[e] == "Stone Skin"){// both passives are used in the same situations, so I attached Earth's passive to the code
		attack = attack - 9;
	}
	if (status[e] == "Phased"){

		attack = 0;

		switch (turn[c]){
		case 3:
			energy[e] = energy[e] + (2 * cost[c][0]) + 2;
			break;
		case 4:
			energy[e] = energy[e] + (2 * cost[c][1]) + 2;
			break;
		case 5:
			energy[e] = energy[e] + (2 * cost[c][2]) + 2;
			break;
		default :
			break;
		}
	}
}

void hinder(){

	if (status[c] == "Hindered"){
		attack = attack / 2;
	}

}

void barrier(){

	if (status[e] == "Shielded"){
		attack = attack / 2;
		if (turn[c] != 2){
			cout << "Player " << e + 1 << "'s shield absorbs the damage" << endl;
		}
	}

}

void shadowbreak(){

	if (status[e] == "Faded"){

		attack = 0;
		status[e].assign("Healthy");

	}
	if (status[e] == "Boosted"){
		attack = 0;
	}

}

void absorb(){

	if (passive[e] == "Energy Absorbtion"){

		switch (turn[c]){

		case 3:
			energy[e] = energy[e] + ((cost[c][0] + 1) / 2);
			break;
		case 4:
			energy[e] = energy[e] + ((cost[c][1] + 1) / 2);
			break;
		case 5:
			energy[e] = energy[e] + ((cost[c][2] + 1) / 2);
			break;
		default:
			break;
		}

	}

}

void attacking(){
	cout << "Player " << c + 1 << " attacks";
	hit = 1 + rand() % 100;
	if (hit <= dodge[e]) {
		cout << ", but misses" << endl;
	}
	else if (hit > dodge[e]) {
		if (passive[c] == "Corrosion"){
			status[e].assign("Poisoned");
			statusduration[e] = 10;
			venom[e] = venom[e] + 1;
		}
		attack = 1 + rand() % power[c];
		if (attack > armor[e]) {
			attack = attack - armor[e];
			if (turn[e] == 2) {
				attack = attack / 2;
				if (a[e] == 3){
					attack = attack / 2;
					energy[e]++;
					cout << ", but Player " << e + 1 << "'s shock guard absorbs the attack." << endl
						<< "Player " << c + 1 << " attacks";
				}
			}
			if (status[c] == "Rampaging"){
				attack = attack * 4;
			}
			if (passive[c] == "Growing Death"){
				power[c] = power[c] + 5;
			}
			barrier();
			hinder();
			shadowbreak();
			if (status[c] == "Boosted"){
				attack = attack + 30;
			}
			cout << ", dealing " << attack << " damage." << endl;
			health[e] = health[e] - attack;
			if (a[c] == 8){
				health[c] = health[c] + attack / 5;
			}
			if (passive[c] == "Growing Death"){
				cout << "Darkness has grown to [" << power[c] << "]" << endl;
			}
			checkdead();
		}
		else {
			cout << ", but only scratches the armor." << endl;
		}
		if (a[c] == 12){
			cout << "Player " << e + 1 << " is blasted for [" << charge << "]" << endl;
			health[e] = health[e] - charge;
		}
	}
}

void cast1(){

	if (cost[c][0] <= energy[c]) {
		energy[c] = energy[c] - cost[c][0];
		if (a[e] == 12 || a[c] == 12){
			charge = charge + cost[c][0];
			cout << "Manaburn's charge grows to [" << charge << "]" << endl;
		}
		switch (a[c]) {
		case 1: // blast
			attack = 40;
			windbody();
			shadowbreak();
			barrier();
			hinder();
			status[e].assign("Burning");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			break;
		case 2: // wave
			attack = 33;
			windbody();
			hinder();
			shadowbreak();
			barrier();
			health[e] = health[e] - attack;
			health[c] = health[c] + (attack/3);
			break;
		case 3: // discharge
			attack = energy[c] * 15;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			energy[c] = 0;
			break;
		case 4: // divine blessing
			health[c] = health[c] + 25;
			attack = 25;
			break;
		case 5: // gust
			attack = 20;
			windbody();
			hinder();
			shadowbreak();
			barrier();
			status[e].assign("Storm");
			statusduration[e] = 5;
			health[e] = health[e] - attack;
			break;
		case 6: // focus strike
			attack = 25;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			break;
		case 7:
			attack = 20;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			status[e].assign("Stunned");
			statusduration[e] = 1;
			break;
		case 8:
			attack = 0;
			status[e].assign("Bleeding");
			statusduration[e] = 3;
			break;
		case 9:
			attack = 0;
			status[c].assign("Faded");
			statusduration[c] = 2;
			power[c] = power[c] + 5;
			cout << "Darkness has grown to [" << power[c] << "]" << endl;
			break;
		case 10:
			attack = venom[e] * 15;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			break;
		case 12:
			if (a[c] == 12){
				attack = 0;
				status[c].assign("Phased");
				statusduration[c] = 2;
			}
			break;
		case 11:
			switch (mimic){
			case 1: // blast
				attack = 40;
				windbody();
				shadowbreak();
				hinder();
				barrier();
				status[e].assign("Burning");
				statusduration[e] = 2;
				health[e] = health[e] - attack;
				energy[c] = energy[c] + 2;
				break;
			case 2: // wave
				attack = 33;
				windbody();
				hinder();
				shadowbreak();
				barrier();
				health[e] = health[e] - attack;
				health[c] = health[c] + (attack/3);
				energy[c] = energy[c] + 2;
				break;
			case 3: // discharge
				energy[c] = energy[c] + 4;
				attack = energy[c] * 15;
				windbody();
				shadowbreak();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				energy[c] = 0;
				break;
			case 4: // divine blessing
				health[c] = health[c] + 25;
				energy[c] = energy[c] + 1;
				attack = 25;
				break;
			case 5: // gust
				attack = 20;
				windbody();
				hinder();
				shadowbreak();
				barrier();
				status[e].assign("Storm");
				statusduration[e] = 5;
				health[e] = health[e] - attack;
				energy[c] = energy[c] + 3;
				break;
			case 6: // focus strike
				energy[c] = energy[c] + 3;
				attack = 25;
				windbody();
				shadowbreak();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				break;
			case 7:
				attack = 20;
				windbody();
				shadowbreak();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				status[e].assign("Stunned");
				statusduration[e] = 1;
				break;
			case 8:
				attack = 0;
				status[e].assign("Bleeding");
				statusduration[e] = 3;
				energy[c] = energy[c] + 2;
				break;
			case 9:
				attack = 0;
				status[c].assign("Faded");
				statusduration[c] = 2;
				power[c] = power[c] + 5;
				cout << "Darkness has grown to [" << power[c] << "]" << endl;
				energy[c] = energy[c] + 3;
				break;
			case 10:
				attack = venom[e] * 15;
				shadowbreak();
				windbody();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				energy[c] = energy[c] + 1;
				break;
			}
			break;
		}
		cout << "Player " << c + 1 << ":\t" << ability[c][0] << " [" << attack << "]" << endl;
	}
	else {
		cout << "Player 2 attempts to use first ability, but is out of energy" << endl;
	}
}

void cast2(){
	if (cost[c][1] <= energy[c]) {
		energy[c] = energy[c] - cost[c][1];
		if (a[e] == 12 || a[c] == 12){
			charge = charge + cost[c][1];
		}
		switch (a[c]) {
		case 1: // Flamethrower
			attack = 45;
			shadowbreak();
			hinder();
			windbody();
			barrier();
			if (status[e] == "Burning"){
				status[e].assign("Stunned");
				statusduration[e] = 2;
				cout << "Player " << c + 1 << " fuels the fire and stuns Player " << e + 1 << endl;
			}
			else {
				status[e].assign("Burning");
				statusduration[e] = 2;
			}
			health[e] = health[e] - attack;
			break;
		case 2: // barrier, see other section, needed to be moved to properly use cleanse effect against stuns
			break;
		case 3: // shock absorb
			if (turn[e] == 3){
				switch (a[e]){
				case 1:
					attack = 20;
					health[c] = health[c] + 40;
					break;
				case 2:
					attack = 33;
					health[c] = health[c] + 66;
					break;
				case 3:
					attack = energy[e] * 15;
					health[c] = health[c] + 2 * attack;
					break;
				case 5:
					attack = 20;
					health[c] = health[c] + 40;
					break;
				case 6:
					attack = 25;
					health[c] = health[c] + 50;
					break;
				case 7:
					attack = 20;
					health[c] = health[c] + 40;
					break;
				case 10:
					attack = venom[c] * 15;
					health[c] = health[c] + (2 * attack);
					break;
				default:
					break;
				}

				cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
			}
			else if (turn[e] == 4){
				switch (a[e]){
				case 1:
					attack = 45;
					health[c] = health[c] + 90;
					break;
				case 7:
					attack = health[c] / 10 * 3;
					health[c] = health[c] + 2 * attack;
					break;
				case 8:
					attack = 20;
					health[c] = health[c] + 40;
				default:
					break;
				}

				cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
			}
			else if (turn[e] == 5){
				switch (a[e]){
				case 1:
					attack = 120;
					health[c] = health[c] + 240;
					break;
				case 2:
					attack = 110;
					health[c] = health[c] + 220;
					break;
				case 3:
					attack = 100;
					health[c] = health[c] + 200;
					break;
				case 4:
					attack = 150;
					health[c] = health[c] + 300;
					break;
				case 5:
					attack = 120;
					health[c] = health[c] + 240;
					break;
				case 6:
					attack = (300 - health[e]) / 10 * 4;
					health[c] = health[c] + 2 * ((300 - health[e]) / 10 * 4);
					break;
				case 7:
					attack = 120;
					health[c] = health[c] + 240;
					break;
				case 10:
					attack = venom[c] * 10 + 50;
					health[c] = health[c] + 2 * attack;
					break;
				default:
					break;
				}

				cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
			}
			else {
				attack = 0;
			}
			break;

		case 4: // hinder
			status[e].assign("Hindered");
			statusduration[e] = 3;
			attack = 0;
			break;
		case 5: // wind charge
			attack = 0;
			shadowbreak();
			status[c].assign("Charging");
			statusduration[c] = 4;
			dodge[c] = 100;
			break;
		case 6: // meditate
			attack = 30;
			health[c] = health[c] + attack;
			break;
		case 7:
			attack = health[e] / 10 * 3;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			break;
		case 8:
			attack = 20;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			health[c] = health[c] + attack;
			break;
		case 9:
			attacking();
			attacking();
			attack = 0;
			break;
		case 10:
			attack = 0;
			status[c].assign("Boosted");
			statusduration[c] = 2;
			break;
		case 12:
			attack = 0;
			status[e].assign("Manaburn");
			statusduration[e] = 10;
			break;
		case 11:
			switch (mimic){
			case 1: // Flamethrower
				attack = 45;
				shadowbreak();
				hinder();
				windbody();
				barrier();
				if (status[e] == "Burning"){
					status[e].assign("Stunned");
					statusduration[e] = 2;
					cout << "Player " << c + 1 << " fuels the fire and stuns Player " << e + 1 << endl;
				}
				else {
					status[e].assign("Burning");
					statusduration[e] = 2;
				}
				energy[c] = energy[c] + 3;
				health[e] = health[e] - attack;
				break;
			case 2: // barrier, see other section, needed to be moved to properly use cleanse effect against stuns
				energy[c] = energy[c] + 3;
				break;
			case 3: // shock absorb
				if (turn[e] == 3){
					energy[c] = energy[c] + 3;
					switch (a[e]){
					case 1:
						attack = 20;
						health[c] = health[c] + 40;
						break;
					case 2:
						attack = 33;
						health[c] = health[c] + 66;
						break;
					case 3:
						attack = energy[e] * 15;
						health[c] = health[c] + 2 * attack;
						break;
					case 5:
						attack = 20;
						health[c] = health[c] + 40;
						break;
					case 6:
						attack = 25;
						health[c] = health[c] + 50;
						break;
					case 7:
						attack = 20;
						health[c] = health[c] + 40;
						break;
					case 10:
						attack = venom[c] * 15;
						health[c] = health[c] + (2 * attack);
						break;
					default:
						break;
					}

					cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
				}
				else if (turn[e] == 4){
					switch (a[e]){
					case 1:
						attack = 45;
						health[c] = health[c] + 90;
						break;
					case 7:
						attack = health[c] / 10 * 3;
						health[c] = health[c] + 2 * attack;
						break;
					case 8:
						attack = 20;
						health[c] = health[c] + 40;
					default:
						break;
					}

					cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
				}
				else if (turn[e] == 5){
					switch (a[e]){
					case 1:
						attack = 120;
						health[c] = health[c] + 240;
						break;
					case 2:
						attack = 110;
						health[c] = health[c] + 220;
						break;
					case 3:
						attack = 100;
						health[c] = health[c] + 200;
						break;
					case 4:
						attack = 150;
						health[c] = health[c] + 300;
						break;
					case 5:
						attack = 120;
						health[c] = health[c] + 240;
						break;
					case 6:
						attack = (300 - health[e]) / 10 * 4;
						health[c] = health[c] + 2 * ((300 - health[e]) / 10 * 4);
						break;
					case 7:
						attack = 120;
						health[c] = health[c] + 240;
						break;
					case 10:
						attack = venom[c] * 10 + 50;
						health[c] = health[c] + 2 * attack;
						break;
					default:
						break;
					}

					cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
				}
				else {
					attack = 0;
				}
				break;

			case 4: // hinder
				status[e].assign("Hindered");
				statusduration[e] = 3;
				attack = 0;
				energy[c] = energy[c] + 3;
				break;
			case 5: // wind charge
				attack = 0;
				shadowbreak();
				status[c].assign("Charging");
				statusduration[c] = 4;
				dodge[c] = 100;
				energy[c] = energy[c] + 2;
				break;
			case 6: // meditate
				attack = 30;
				energy[c] = energy[c] + 2;
				health[c] = health[c] + attack;
				break;
			case 7:
				attack = health[e] / 10 * 3;
				shadowbreak();
				windbody();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				break;
			case 8:
				attack = 20;
				shadowbreak();
				windbody();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				health[c] = health[c] + attack;
				energy[c] = energy[c] + 2;
				break;
			case 9:
				attacking();
				attacking();
				attack = 0;
				energy[c] = energy[c] + 2;
				break;
			case 10:
				attack = 0;
				status[c].assign("Boosted");
				statusduration[c] = 2;
				energy[c] = energy[c] + 2;
				break;
			}
			break;
		}
		cout << "Player " << c + 1 << ":\t" << ability[c][1] << " [" << attack << "]" << endl;
	}
	else {
		cout << "Player " << c + 1 << " attempts to use second ability, but is out of energy" << endl;
	}
}

void cast3(){
	if (cost[c][2] <= energy[c]) {
		energy[c] = energy[c] - cost[c][2];
		if (a[e] == 12 || a[c] == 12){
			charge = charge + cost[c][2];
		}
		switch (a[c]) {
		case 1:// ("Rain of Fire"); // high damage ablilty 120
			attack = 120;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			status[e].assign("Burning");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			break;

		case 2://("Tsunami"); // high damage ability, halfs opponent damage for 2 turns 110
			attack = 110;
			windbody();
			shadowbreak();
			barrier();
			hinder();
			status[e].assign("Hindered");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			health[c] = health[c] + attack / 3;
			break;

		case 3://("High Voltage");// 100 stun opponent for 2 turns
			attack = 100;
			windbody();
			hinder();
			barrier();
			shadowbreak();
			status[e].assign("Stunned");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			break;

		case 4://("Smite");// 150 damage
			attack = 150;
			shadowbreak();
			windbody();
			barrier();
			hinder();
			health[e] = health[e] - attack;
			break;

		case 5://("Tempest");// increase dodge to 100% for 2 turns (this one included), deal 120 damage
			attack = 120;
			shadowbreak();
			windbody();
			barrier();
			hinder();
			status[c].assign("Tempest");
			dodge[c] = 100;
			statusduration[c] = 2;
			health[e] = health[e] - attack;
			break;

		case 6://("Execution"); // 40% of your missing hp as damage
			attack = (300 - health[c]) / 10 * 4;
			shadowbreak();
			windbody();
			barrier();
			hinder();
			health[e] = health[e] - attack;
			break;

		case 7:
			attack = 120;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			status[e].assign("Shaken");
			statusduration[e] = 10;
			break;

		case 8:
			attack = 0;
			status[c].assign("Rampaging");
			statusduration[c] = 4;
			break;

		case 9:
			health[c] = health[c] + 50;
			shadowbreak();
			attacking();
			attacking();
			attacking();
			attack = 50;
			break;
		case 10:
			status[e].assign("Poisoned");
			statusduration[e] = 10;
			attack = venom[e] * 10 + 50;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			venom[e] = venom[e] + 3;
			health[e] = health[e] - attack;
			break;
		case 12:
			attack = ((energy[c] + energy[e] + cost[c][2]) * 10);
			energy[e] = -1;
			health[e] = health[e] - attack;
			break;
		case 11:
			switch(mimic){
			case 1:// ("Rain of Fire"); // high damage ablilty 120
				attack = 120;
				windbody();
				shadowbreak();
				hinder();
				barrier();
				status[e].assign("Burning");
				statusduration[e] = 2;

				health[e] = health[e] - attack;
				energy[c] = energy[c] + 2;
				break;

			case 2://("Tsunami"); // high damage ability, halfs opponent damage for 2 turns 110
				attack = 110;
				windbody();
				shadowbreak();
				barrier();
				hinder();
				status[e].assign("Hindered");
				statusduration[e] = 2;
				health[e] = health[e] - attack;
				health[c] = health[c] + attack / 3;
				energy[c] = energy[c] + 2;
				break;

			case 3://("High Voltage");// 100 stun opponent for 2 turns
				attack = 100;
				windbody();
				hinder();
				barrier();
				shadowbreak();
				status[e].assign("Stunned");
				statusduration[e] = 2;
				health[e] = health[e] - attack;
				energy[c] = energy[c] + 1;
				break;

			case 4://("Smite");// 150 damage
				attack = 150;
				shadowbreak();
				windbody();
				barrier();
				hinder();
				energy[c] = energy[c] + 1;
				health[e] = health[e] - attack;
				break;

			case 5://("Tempest");// increase dodge to 100% for 2 turns (this one included), deal 120 damage
				attack = 120;
				shadowbreak();
				windbody();
				barrier();
				hinder();
				energy[c] = energy[c] + 2;
				status[c].assign("Tempest");
				dodge[c] = 100;
				statusduration[c] = 2;
				health[e] = health[e] - attack;
				break;

			case 6://("Execution"); // 40% of your missing hp as damage
				attack = (300 - health[c]) / 10 * 4;
				shadowbreak();
				windbody();
				barrier();
				hinder();
				energy[c] = energy[c] + 3;
				health[e] = health[e] - attack;
				break;

			case 7:
				attack = 120;
				shadowbreak();
				windbody();
				hinder();
				barrier();
				health[e] = health[e] - attack;
				status[e].assign("Shaken");
				statusduration[e] = 10;
				break;

			case 8:
				status[c].assign("Rampaging");
				statusduration[c] = 4;
				energy[c] = energy[c] + 3;
				break;

			case 9:
				health[c] = health[c] + 50;
				shadowbreak();
				attacking();
				attacking();
				attacking();
				energy[c] = energy[c] + 1;
				attack = 50;
				break;
			case 10:
				attack = venom[e] * 10 + 50;
				shadowbreak();
				windbody();
				hinder();
				barrier();
				energy[c] = energy[c] + 3;
				venom[e] = venom[e] + 3;
				health[e] = health[e] - attack;
				break;
			}
			break;
		}

		cout << "Player " << c + 1 << ":\t" << ability[c][2] << " [" << attack << "]" << endl;
	}
	else {
		cout << "Player " << c + 1 << " attempts to use third ability, but is out of energy" << endl;
	}
}

void passives() {

	switch (a[c]){

	case 6: // swordsman's valor
		health[c] = health[c] + 3;
		cout << "Player " << c + 1 << " regains [3] life" << endl;
		break;
	case 4: // holy's cleanse
		status[c].assign("Healthy");
		cout << "Player " << c + 1 << " cleanses themselves of impurities" << endl;
		break;
	case 5: // wind, check damage modifier from charge and dodge modifier from tempest
		if (status[c] != "Charging"){
			power[c] = 25;
		}
		else {
			power[c] = 75;
		}
		if (status[c] != "Tempest"){
			dodge[c] = 35;
		}
		else{
			dodge[c] = 100;
		}
		break;
	case 11: // wind, check damage modifier from charge and dodge modifier from tempest
		if (status[c] != "Charging"){
			power[c] = 25;
		}
		else {
			power[c] = 75;
		}
		if (status[c] != "Tempest"){
			dodge[c] = 35;
		}
		else{
			dodge[c] = 100;
		}
		break;
	default:
		break;
	}
	if (status[c] != "Poisoned"){
		venom[c] = 0;
	}
}

void statuscheck(){
	// Burning			O
	// Hindered			X
	// Storm			O
	// Stunned			X
	// Shielded			X
	// Charging			X
	// Tempest			X
	// Healthy			X
	// Shaken			O
	// Bleeding			O
	// Rampaging		X
	statusduration[c] = statusduration[c] - 1;

	if (status[c] == "Burning"){
		health[c] = health[c] - 10;
		cout << "Player " << c + 1 << " Burns for [10], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Storm"){
		health[c] = health[c] - 3;
		cout << "Player " << c + 1 << " is injured by resonate wind for [3], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Healthy"){
	}
	else if (status[c] == "Shaken"){
		health[c] = health[c] - 15;
		cout << "Player " << c + 1 << " is shaken for [15]" << endl;
	}
	else if (status[c] == "Bleeding"){
		attack = health[c] / 20;
		health[c] = health[c] - attack;
		cout << "Player " << c + 1 << " bleeds for [" << attack << "], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Poisoned"){
		attack = venom[c] * 5;
		health[c] = health[c] - attack;
		cout << "Player " << c + 1 << " is poisoned for [" << attack << "]. There are a total of [" << venom[c] << "] stacks" << endl;
	}
	else if (status[c] == "Manaburn"){
		health[c] = health[c] - (energy[c] * 2) - (energy[e] * 2);
		health[e] = health[e] + (energy[c] * 2) + (energy[e] * 2);
		attack = (energy[c] * 2) + (energy[e] * 2);
		cout << "Player " << c + 1 << " is Manaburned for [" << attack << "]" << endl;
	}
	else {
		cout << "Player " << c + 1 << " is [" << status[c] << "], " << statusduration[c] << " turn(s) remaining" << endl;
	}

	if (statusduration[c] <= 0){
		status[c].assign("Healthy");
	}

}

void record(){
	ifstream infile;
	infile.open("Balance.txt");

	j = 0;

	while (j < 12){

		k = 0;

		while (k < 12){
			infile >> matchup[k][j];
			k++;

		}
		j++;

	}

	infile.close();

	matchwin = matchwin - 1;
	matchloose = matchloose - 1;

	matchup[matchloose][matchwin]++;

	ofstream outfile;

	outfile.open("Balance.txt");

	j = 0;

	while (j < 12){

		k = 0;

		while (k < 12){
			outfile << matchup[k][j] << "\t";
			k++;

		}
		outfile << endl;
		j++;
		cout << endl;
	}

	outfile.close();
}

void aigo(){
	switch (a[c]){
	case 1: // fire ai
		if (energy[c] >= 3 && status[e] == "Burning"){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 2: // water ai
		if (energy[c] >= 3 && status[c] != "Shielded"){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 4){
				turn[c] = turn[c] - 1;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 4){
				turn[c] = turn[c] - 1;
			}
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 3: // static ai
		if (status[e] == "Stunned"){
			turn[c] = 1;
		}
		else if (energy[e] >= cost[e][2] && energy[c] >= cost[c][1]){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 3);
			if (turn[c] == 1){
				turn[c] = 3;
			}
			else if (turn[c] == 0){
				turn[c] = 5;
			}
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 1){
				turn[c]++;
			}
		}
		else if (energy[c] < cost[c][1]){
			turn[c] = 2;
		}
		break;
	case 4: // holy ai
		if (energy[c] >= cost[c][1] && status[e] != "Hindered"){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][0] && health[c] <=100){
			turn[c] = 3;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 5: // wind ai
		if (status[c] == "Charging"){
			turn[c] = 1;
		}
		else if (energy[c] >= cost[c][0] && (status[e] != "Healthy" && status[e] != "Storm" && status[e] != "Faded")){
			turn[c] = 3;
		}
		else if (energy[c] >= cost[c][2]){
				turn[c] = 5;
		}
		else if (energy[c] >= cost[c][1]){
			do {
				turn[c] = (rand() % 3) + 1;
			} while (turn[c] == 2);
		}
		else if (energy[c] >= cost[c][0]){
			do {
				turn[c] = (rand() % 3) + 1;
			} while (turn[c] == 2);
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 6: // swordsman ai
		if (health[c] <= 100 && energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][1] && health[c] <= 100){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
		}
		else if (energy[c] >= cost[c][0]){
			do {
				turn[c] = (rand() % 3) + 1;
			} while (turn[c] == 2);
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 7: // earth ai
		if (health[e] >= 150 && energy[c] >= cost[c][1]){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 8: // blood ai
		if (status[e] != "Bleeding" && status[e] != "Healthy"){
			turn[c] = 3;
		}
		else if (status[c] == "Rampaging"){
			turn[c] = 1;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = 1;
		}
		break;
	case 9: // dark ai
		if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (health[e] <= power[c]){
			if (energy[c] >= cost[c][2]){
				turn[c] = 5;
			}
			else if (energy[c] >= cost[c][1]){
				turn[c] = 4;
			}
			else if (energy[c] <= cost[c][1]){
				turn[c] = 1;
			}
		}
		else if (energy[e] == cost[e][2]){
			turn[c] = 3;
		}
		else if (status[c] != "Healthy" && status[c] != "Faded"){
			turn[c] = 3;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = 1;
		}
		break;
	case 10: // venom ai
		if (status[c] == "Boosted"){
			turn[c] = 1;
		}
		else if (energy[c] >= cost[c][1] && energy[e] == cost[e][2]){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = 5;
		}
		else if (energy[c] >= cost[c][0] && venom[e] >= 3){
			turn[c] = 3;
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 2 || turn[c] == 3){
				turn[c] = 1;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = 1;
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = 1;
		}
		break;
	default:
		cout << "There is no ai code for " << Element[c] << " Element" << endl;
		break;
	}
}
