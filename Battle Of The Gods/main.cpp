#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void charselect(void); // character slect screen
void setplayer(void); // apply chosen element to player
void fight(void); // full cycle of combat from initialization to finish
void turnMenu(void); // HUD displaying turn options, such as attack, defend, surrender, and abilities
void combat(void); // one turn combat cycle
void checkdead(void); // is anyone dead?
void victory(void); // after someone is declared dead, set the winner
void printheader(void); // HUD displaying health, energy, element, and status
void windbody(void); // wind's dodge applying to abilities
void hinder(void); // half damage if effected
void attacking(void); // performing a basic attack
void cast1(void); // select and perform ability 1 based on element
void cast2(void); // select and perform ability 2 based on element
void cast3(void); // select and perform ability 3 based on element
void passives(void); // perform passive abilities if it occurs on every turn
void statuscheck(void); // status effect check, can you perform whatever action are you performing? are you on fire and taking damage?
void barrier(void); // half damage
void shadowbreak(void); // enable dodging for Dark, Venom, and Energy
void absorb(void); // morphling absorbing enemy energy
void record(void); // save match winner
void aigo(void); // ai code
void searchdata(void); // find data the player desires
void calcwin(void); // calculate win rate of a matchup
void ability1describe(void); // written description of ability 1
void ability2describe(void); // written description of ability 2
void ability3describe(void); // written description of ability 3
void passivedescribe(void); // written description of passive ability
void visuals(void); // WIP, trying to create code for image display
void describe(void); // description of element as a whole
void reimburse(void); // morphling ability selection
void topmenu(void); // press start to play

string Element[2]; // player elements
int health[2], armor[2], dodge[2], speed[2], power[2], energy[2]; // player stats
string ability[2][3]; // name of ablities
int cost[2][3]; // Energy cost of abilities
string passive[2]; // name of passive abilities
string status[2]; // status effects
int statusduration[2]; // remaining time on the status effects
int turn[2]; // player turn variables
int winner; // variable to select winner
int looser; // variable to select looser
int attack; // random number for damage for both attacking and abilities
int a[2]; // ability set for a given player, each number alligns with a certain element
int hit; // random number for dodging attacks
int c, e; //current/enemy player
int thisturn; // who moves first based on speed rng
int venom[2]; // how many stacks of venom
int mimic[2]; // what element morphling is copying
int charge[2]; // how high is (energy/idler/tech)'s charge?
int matchwin; // data search, who won?
int matchloose;	// data search, who lost?
int k, j; // placeholders used for logging data
int matchup[14][14]; // the data matrix
int play; // true - false, is the game going?
int filldat; // enable alternate modes such as sweep or systemfill
char search; // yes / no search data
int chance; // % chance of victory
int sweeper; // variable for tracking elements if sweep mode is active
int systemic; // variable for tracking elements if system fill mode is active
double total; // number of matches fought between 2 combatants
double wins; // number of wins a certain combatant has against another
int hpsave; // morphlings current hp
int mnsave; // morphlings current energy


int main() {
	topmenu();
	play = 0;
	sweeper = 0;
	systemic = 1;
	winner = 1;
	while(play == 0){
		charge[0] = 0;
		charge[1] = 0;
		venom[0] = 0;
		venom[1] = 0;
		system("CLS");
		charselect();
		winner = 0;
		fight();
		victory();
		record();
		searchdata();
		thisturn = 0;
	}
	system("pause");

	return 0;
}

void charselect() {

	Element[1].assign("none");
	c = 0;
	do {
		cout << "Player " << c + 1 << ", choose your element" << endl
			<< endl // Health: 150 200 250 300 350+ Attack: 10 20 30 40 50+
			<< "           Health      Attack      Ability Damage Utility     Difficulty" << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl
			<< "Zues:      |||||6      ||||5       |||||||8       Stun        |2        " << endl << "------------------------------------------------------------------------" << endl
			<< "Hera:      ||||||7     ||3         |||||6         Defensive   ||3       " << endl << "------------------------------------------------------------------------" << endl
			<< "Poeseidon: |||||||8    |||||||8    ||||||7        Absorbtion  ||||||7   " << endl << "------------------------------------------------------------------------" << endl
			<< "Hades:     ||||||7     ||||||||9   |||4           Defensive   ||||5     " << endl << "------------------------------------------------------------------------" << endl
			<< "Hestia:    |||4        ||||||7     ||||||7        Evasion     |||||||8  " << endl << "------------------------------------------------------------------------" << endl
			<< "Athena:    |||||||||0  |||||||8    |||||||8       Stun        ||3       " << endl << "------------------------------------------------------------------------" << endl
			<< "artemis:   ||||||7     |||||||||0  1              Lifesteal   |||||6    " << endl << "------------------------------------------------------------------------" << endl
			<< "Apollo:    |||||6      ||3         1              Evasion     |||||||8  " << endl << "------------------------------------------------------------------------" << endl
			<< "Aristaios: ||||5       ||3         |||||||8       Poison      |||4      " << endl << "------------------------------------------------------------------------" << endl
			<< "Hephaestus:||||||||9   |||||||||0  |2             None        1         " << endl
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
			<< "                             * 0  for random or ai" << endl
			<< endl
			<< "(use capital first letter)" << endl
			<< endl;
		if (filldat == 0){  // Admin Commands
			cin >> Element[c];
		}
		if (Element[0] == "Rand" || Element[0] == "sf"){
			cin >> mimic[c];
			attack = 0;
			while (attack < mimic[c]){
				hit = rand() % 13;
				attack++;
			}
			if (Element[c] == "Rand"){
				Element[c].assign("Secret");
			}
			if (Element[c] == "sf"){
				Element[c].assign("SystemFillOne");
			}
		}
		if (Element[c] == "no"){
			searchdata();
		}
		if (Element[c] == "Secret"){
			system("CLS");
			cout << "Player " << c + 1 << ", choose your element" << endl
				<< endl // Health: 150 200 250 300 350+ Attack: 10 20 30 40 50+
				<< "           Health      Attack      Ability Damage Utility     Difficulty" << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
				<< "Fire:      |||||6      ||||5       |||||||8       Stun        |2        " << endl << "------------------------------------------------------------------------" << endl
				<< "Water:     ||||||7     ||3         |||||6         Defensive   ||3       " << endl << "------------------------------------------------------------------------" << endl
				<< "Static:    |||||||8    |||||||8    ||||||7        Absorbtion  ||||||7   " << endl << "------------------------------------------------------------------------" << endl
				<< "Holy:      ||||||7     ||||||||9   |||4           Defensive   ||||5     " << endl << "------------------------------------------------------------------------" << endl
				<< "Wind:      |||4        ||||||7     ||||||7        Evasion     |||||||8  " << endl << "------------------------------------------------------------------------" << endl
				<< "Earth:     |||||||||0  |||||||8    |||||||8       Stun        ||3       " << endl << "------------------------------------------------------------------------" << endl
				<< "Blood:     ||||||7     |||||||||0  1              Lifesteal   |||||6    " << endl << "------------------------------------------------------------------------" << endl
				<< "Dark:      |||||6      ||3         1              Evasion     |||||||8  " << endl << "------------------------------------------------------------------------" << endl
				<< "Venom:     ||||5       ||3         |||||||8       Poison      |||4      " << endl << "------------------------------------------------------------------------" << endl
				<< "Swordsman: ||||||||9   |||||||||0  |2             None        1         " << endl << "------------------------------------------------------------------------" << endl
				<< "Morphling: |||||||8    |||||6      |||||||||0     Omnipotence ||||||||9 " << endl << "------------------------------------------------------------------------" << endl
				<< "Energy:    ||||5       ||||5       ||||||||9      No Mana     |||||||8  " << endl << "------------------------------------------------------------------------" << endl
				<< "Idler:     |||4        ||3         ||3            Stun        |||||||||0 " << endl << "------------------------------------------------------------------------" << endl
				<< "Tech:      |||4        ||||||||9   ||||||||9      Evasion     |||||||||0 " << endl
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
				<< "                             * 0  for random or ai" << endl
				<< endl
				<< "(use capital first letter)" << endl
				<< endl;
			if (filldat == 0){
				cin >> Element[c];
			}


		}
		if (Element[c] == "FillData"){ // Admin commands continued
			filldat = 1;
		}
		if (Element[c] == "FillDataFast"){
			filldat = 2;
		}
		if (Element[1] == "FillDataOne" && c == 1){
			filldat = 3;
		}
		if (Element[1] == "Sweep" && c == 1){
			filldat = 4;
		}
		if (Element[0] == "SystemFill"){
			filldat = 5;
		}
		if (Element[0] == "SystemFillOne"){
			filldat = 6;
		}
		if ((filldat == 1) || (filldat == 3 && c == 1) || (filldat == 2) || (filldat == 4 && c == 1) || ((filldat == 5 || filldat == 6) || filldat == 6)){ // go to next element if sweep or system, random if filldat
			if (filldat == 1 || filldat == 2 || filldat == 3){
				a[c] = (rand() % 13) + 1;
			}
			if (filldat == 4 && c == 1){
				if (winner == 1){
					sweeper = sweeper + 1;
				}
				a[1] = sweeper;
			}
			if (((filldat == 5 || filldat == 6) || filldat == 6)){
				if (c == 0){
					sweeper = sweeper + 1;
					if (sweeper >= 14){
						sweeper = 1;
					}
					a[c] = sweeper;
					switch (sweeper){
					case 1: // sweeper color to determine progress
						system("Color C0");
						break;
					case 2:
						system("Color 10");
						break;
					case 3:
						system("Color 60");
						break;
					case 4:
						system("Color 70");
						break;
					case 5:
						system("Color 80");
						break;
					case 6:
						system("Color D0");
						break;
					case 7:
						system("Color 20");
						break;
					case 8:
						system("Color 40");
						break;
					case 9:
						system("Color 50");
						break;
					case 10:
						system("Color A0");
						break;
					case 11:
						system("Color 90");
						break;
					case 12:
						system("Color F0");
						break;
					case 13:
						system("Color E0");
						break;
					}
				}
				if (c == 1){
					a[c] = systemic;
					switch (systemic){
					case 1:
						system("Color C0");
						break;
					case 2:
						system("Color 10");
						break;
					case 3:
						system("Color 60");
						break;
					case 4:
						system("Color 70");
						break;
					case 5:
						system("Color 80");
						break;
					case 6:
						system("Color D0");
						break;
					case 7:
						system("Color 20");
						break;
					case 8:
						system("Color 40");
						break;
					case 9:
						system("Color 50");
						break;
					case 10:
						system("Color A0");
						break;
					case 11:
						system("Color 90");
						break;
					case 12:
						system("Color F0");
						break;
					case 13:
						system("Color E0");
						break;
					}
				}
			}
			switch (a[c]){
			case 1:
				Element[c] = "Zues";
				break;
			case 2:
				Element[c] = "Herra";
				break;
			case 3:
				Element[c] = "Poesideon";
				break;
			case 4:
				Element[c] = "Hades";
				break;
			case 5:
				Element[c] = "Hestia";
				break;
			case 6:
				Element[c] = "Hephaestus";
				break;
			case 7:
				Element[c] = "Hestia";
				break;
			case 8:
				Element[c] = "Athena";
				break;
			case 9:
				Element[c] = "Artemis";
				break;
			case 10:
				Element[c] = "Apollo";
				break;
			case 11:
				Element[c] = "Aristaios";
				break;
			case 12:
				Element[c] = "ManaBurn";
				break;
			case 13:
				Element[c] = "Valkyrie";
				break;
			}
		}
		if (Element[c] == "0"){ // Random Element
			a[c] = (rand() % 10) + 1;
			switch (a[c]){
			case 1:
				Element[c] = "Zues";
				break;
			case 2:
				Element[c] = "Hera";
				break;
			case 3:
				Element[c] = "Poesideon";
				break;
			case 4:
				Element[c] = "Hades";
				break;
			case 5:
				Element[c] = "Hestia";
				break;
			case 6:
				Element[c] = "Hephaestus";
				break;
			case 7:
				Element[c] = "Athena";
				break;
			case 8:
				Element[c] = "Artemis";
				break;
			case 9:
				Element[c] = "Apollo";
				break;
			case 10:
				Element[c] = "Aristaios";
				break;
			}
		}
		if ((filldat == 4 || filldat == 3 || (filldat == 5 || filldat == 6)) && (a[0] == 13 || a[0] == 14) && c == 0){ // secret codes
			Element[0] = "Valkyrie";
		}
		if ((filldat == 4 || filldat == 3 || (filldat == 5 || filldat == 6)) && a[0] == 12 && c == 0){
			Element[0] = "ManaBurn";
		}
		if ((filldat == 4 || filldat == 3 || (filldat == 5 || filldat == 6)) && a[0] == 11 && c == 0){
			Element[0] = "1029384756";
		}
		setplayer();
		system("CLS"); // display element stats
		cout << Element[c] << " element:" << endl << endl
			<< "Health: " << health[c] << endl
			<< "Armor: " << armor[c] << endl
			<< "Speed: " << speed[c] << endl
			<< "Agility: " << dodge[c] << endl
			<< "Max Damage: " << power[c] << endl
			<< "Starting Energy: " << energy[c] << endl
			<< endl << "Ablilities" << endl
			<< endl << "\t" << ability[c][0] << " [" << cost[c][0] << "]" << endl;
		ability1describe();

		cout << endl << "\t" << ability[c][1] << " [" << cost[c][1] << "]" << endl;
		ability2describe();

		cout << endl << "\t" << ability[c][2] << " [" << cost[c][2] << "]" << endl;
		ability3describe();

		cout << endl << "\tPassive ablility: " << passive[c] << endl;
		passivedescribe();
		cout << endl << endl
			<< "Tips:" << endl;
		describe();

		if (filldat == 0 || (filldat == 4 && c == 1)){
			system("pause");
		}

		system("CLS");

		c++;
	} while(c == 1);
}

void fight() {
	status[0].assign("Healthy");
	status[1].assign("Healthy");

	while (winner == 0){ // loop to have multiple turns of combat

		c = 0;
		if (filldat == 0 || filldat == 4){
			system("Color C0");
		}
		cout << "Player 1 up next" << endl;
		turnMenu();
		c = 1;
		if (filldat == 0){
			system("Color 90");
		}
		cout << "Player 2 up next" << endl;
		turnMenu();
		if (filldat == 0 || filldat == 4){
			system("Color 0F");
		}
		combat(); // energy regen +1 at end of turn
		energy[0]++;
		energy[1]++;

	}
}

void setplayer() {
	if (Element[c] == "Fire") {
		ability[c][0].assign("Blast          "); // single turn damage 40
		ability[c][1].assign("Flame Thrower  "); // single turn damage, stuns enemy if they are ignited, 35 damage
		ability[c][2].assign("Rain of Fire   "); // high damage ablilty 120
		passive[c].assign   ("Ignite"); // ablities light an enemy on fire dealing 10 damage per turn for 2 turns, extra ablilities reset duration
		a[c] = 1;
		cost[c][0] = 2;
		cost[c][1] = 3;
		cost[c][2] = 6;
		health[c] = 200;
		armor[c] = 6;
		power[c] = 25;
		speed[c] = 55;
		dodge[c] = 30;
		energy[c] = 3;
	}
	else if (Element[c] == "Water") {
		ability[c][0].assign("Wave           "); // 24 damage
		ability[c][1].assign("Barrier        "); // halfs incoming damage and removes status effects
		ability[c][2].assign("Tsunami        "); // high damage ability, halfs opponent damage for 2 turns 110
		passive[c].assign   ("Changing Tide");// one third of ability damage is returned as hp
		a[c] = 2;
		cost[c][0] = 1;
		cost[c][1] = 4;
		cost[c][2] = 6;
		health[c] = 250;
		armor[c] = 4;
		power[c] = 15;
		speed[c] = 40;
		dodge[c] = 20;
		energy[c] = 5;
	}
	else if (Element[c] == "Static") {
		ability[c][0].assign("Discharge      ");// drains all energy, deals 15 damage per 1 point of energy used
		ability[c][1].assign("Shock Absorb   ");// opposing ability damage heals you for this turn
		ability[c][2].assign("High Voltage   ");// 100 damage and stun opponent for 2 turns
		passive[c].assign   ("Shock Guard"); // +1 extra energy from a successful guard (an attack must be blocked). guard blocks for 75% damage rather than 50%
		a[c] = 3;
		cost[c][0] = 0;
		cost[c][1] = 3;
		cost[c][2] = 7;
		health[c] = 270;
		armor[c] = 8;
		power[c] = 38;
		speed[c] = 55;
		dodge[c] = 15;
		energy[c] = 5;
	}
	else if (Element[c] == "Holy") {
		ability[c][0].assign("Divine Blessing");//heal 25 hp
		ability[c][1].assign("Hinder         ");// reduce enemy damage by 50% for 3 turns
		ability[c][2].assign("Smite          ");// 150 damage
		passive[c].assign   ("Cleanse");// remove opposing status effects at the end of battle phase
		a[c] = 4;
		cost[c][0] = 4;
		cost[c][1] = 5;
		cost[c][2] = 6;
		health[c] = 250;
		armor[c] = 6;
		power[c] = 45;
		speed[c] = 40;
		dodge[c] = 15;
		energy[c] = 4;
	}
	else if (Element[c] == "Wind") {
		ability[c][0].assign("Gust           ");// 20 damage, deals 3 damage per turn for a max of 5 turns
		ability[c][1].assign("Wind Charge    ");// increase dodge to 100% for this turn, increase attack damage to 85 for 3 turns (+50)
		ability[c][2].assign("Tempest        ");// increase dodge to 100% for 2 turns (this one included), deal 100 damage
		passive[c].assign   ("Wind Body");// dodge applies to spells
		a[c] = 5;
		cost[c][0] = 1;
		cost[c][1] = 3;
		cost[c][2] = 7;
		health[c] = 170;
		armor[c] = 3;
		power[c] = 35;
		speed[c] = 75;
		dodge[c] = 35;
		energy[c] = 2;
	}
	else if (Element[c] == "Earth") {
		ability[c][0].assign("Boulder        "); // 30 damage, stun for 1 turn
		ability[c][1].assign("Shakedown      "); // 30% enemy hp as damage
		ability[c][2].assign("Quake          "); // 120 damage and 15 damage per turn until interrupted (10 turns max)
		passive[c].assign   ("Stone Skin");// armor applies to abilities with 1.5 multiplier
		a[c] = 7;
		cost[c][0] = 3;
		cost[c][1] = 4;
		cost[c][2] = 7;
		health[c] = 350;
		armor[c] = 10;
		power[c] = 40;
		speed[c] = 35;
		dodge[c] = 15;
		energy[c] = 2;
	}
	else if (Element[c] == "Blood") {
		ability[c][0].assign("Bleed          "); // 10% enemy hp as damage for 3 turns
		ability[c][1].assign("Drain          "); // steal 20 hp
		ability[c][2].assign("Ravage         "); // 4x + 20 auto damage for 3 turns
		passive[c].assign   ("Vampirism"); // 20% damage dealt with attack returns as health
		a[c] = 8;
		cost[c][0] = 2;
		cost[c][1] = 3;
		cost[c][2] = 6;
		health[c] = 250;
		armor[c] = 4;
		power[c] = 50;
		speed[c] = 70;
		dodge[c] = 25;
		energy[c] = 2;
	}
	else if (Element[c] == "Dark") {
		ability[c][0].assign("Shadowmeld     "); // evade all damage for 1 turn, proc passive once. if it is not used to dodge an ability, increase cost to 2, if successful, proc passive again
		ability[c][1].assign("Blackout       "); // double attack
		ability[c][2].assign("Shadow of Death"); // heal 50 hp, triple attack
		passive[c].assign   ("Growing Death"); // attacks grant + 5 maximum attack damage
		a[c] = 9;
		cost[c][0] = 1;
		cost[c][1] = 3;
		cost[c][2] = 7;
		health[c] = 200;
		armor[c] = 6;
		power[c] = 15;
		speed[c] = 70;
		dodge[c] = 20;
		energy[c] = 3;
	}
	else if (Element[c] == "Venom") {
		ability[c][0].assign("Ignition       "); // 15 damage to enemy per stack of venom
		ability[c][1].assign("Sneak Attack   "); // avoid damage this turn, + 30 (flat) damage next attack
		ability[c][2].assign("Piercing shot  "); // 10 damage per stack + 50, apply 3 stacks
		passive[c].assign   ("Corrosion"); // stacking poison with attacks, 3 damage per stack
		a[c] = 10;
		cost[c][0] = 3;
		cost[c][1] = 4;
		cost[c][2] = 6;
		health[c] = 170;
		armor[c] = 3;
		power[c] = 15;
		speed[c] = 55;
		dodge[c] = 25;
		energy[c] = 4;
	}
	else if (Element[c] == "ManaBurn") {
		Element[c].assign("Energy");
		ability[c][0].assign("Phase Shift    "); // dodge enemy ability, gain energy equal to energy cost of ability dodged and energy refund. energy refunds if attacked
		ability[c][1].assign("Energy Drain   "); // damage enemy based on 2 x their energy and 1/2 yours every turn until interrupted (or 10 turns), get healed for the same ammount
		ability[c][2].assign("Recoil         "); // reduce enemy mana to 0, deal damage equal to 10 * (enemy energy and your energy)
		passive[c].assign   ("Mana Blast"); // gain flat damage to auto attack equal to the cost of all abilities cast
		a[c] = 12;
		cost[c][0] = 2;
		cost[c][1] = 3;
		cost[c][2] = 8;
		health[c] = 170;
		armor[c] = 4;
		power[c] = 25;
		speed[c] = 90;
		dodge[c] = 25;
		energy[c] = 4;
	}
	else if (Element[c] == "1029384756") {
		Element[c].assign("Mimic");
		ability[c][0].assign("Morph 1        "); // copy 1
		ability[c][1].assign("Morph 2        "); // copy 2
		ability[c][2].assign("Morph 3        "); // copy 3
		passive[c].assign   ("Energy Absorbtion"); // enemy abilities give half the cost in energy to the morphling
		a[c] = 11;
		cost[c][0] = 4;
		cost[c][1] = 6;
		cost[c][2] = 8;
		health[c] = 270;
		armor[c] = 5;
		power[c] = 30;
		speed[c] = 60;
		dodge[c] = 20;
		energy[c] = 0;
	}
	else if (Element[c] == "Valkyrie") {
		Element[c].assign("Idler");
		ability[c][0].assign("Slacker        "); //Heal for 20 or 50% missing, whichever is higher, health and remove status effects || Rift Jump: Dodge an attack, attack, and apply plasma, plasma deals 5 damage per turn for 10 turns. Refunds cost if dodging an ability
		ability[c][1].assign("Disruption     "); //Stun for 2 turns, heal 20 and deal half that in damage, refunds cost if successfully used against an ability || Static Field: Deal 20 damage and apply plasma, if a target already has plasma, they are ignited dealing the remaining damage, stunning for the number of turns spent, and refunding the energy cost
		ability[c][2].assign("Fanales        "); //Transform into ultimate form "Techmaturgist" (Tech) gaining a whole new set of abilities || Genocide Halo: Deal 150 damage and return to original form
		passive[c].assign("Rest"); //Increase charge counter by 3 for every turn spent in idler stance || Annihilation: deal damage for every charge on every attack while in tech stance
		a[c] = 13;
		cost[c][0] = 2;
		cost[c][1] = 4;
		cost[c][2] = 6;
		health[c] = 170;
		armor[c] = 2;
		power[c] = 15;
		speed[c] = 20;
		dodge[c] = 15;
		energy[c] = 3;
	}
	else {
		Element[c].assign("Sword");
		ability[c][0].assign("Focus Strike   "); // deals 20 damage
		ability[c][1].assign("Meditate       "); // recover 30 hp
		ability[c][2].assign("Execution      "); // 40% of your missing hp as damage
		passive[c].assign   ("Valor"); // recover 3 hp per turn
		a[c] = 6;
		cost[c][0] = 1;
		cost[c][1] = 6;
		cost[c][2] = 7;
		health[c] = 300;
		armor[c] = 3;
		power[c] = 50;
		speed[c] = 50;
		dodge[c] = 20;
		energy[c] = 3;
	}
}

void turnMenu() {
	system("CLS"); // Idler ability name reset
	if (a[c] == 14) {
		ability[c][2].assign("Genocide Halo  ");
	}
	if (a[c] == 13) {
		ability[c][2].assign("Fanales        ");
	}
	cout << "Player " << c + 1 << " is up next" << endl << endl;
	if (filldat == 0){
		system("pause");
	}

	system("CLS");
	printheader();
	cout << "\t\t[" << Element[c] << " element's turn:]" << endl // print turn menu
		<< endl
		<< "\t _______________________________________________________" << endl
		<< "\t|                                                       |" << endl
		<< "\t|\t(1) Attack\t\t(2) Guard\t\t|" << endl
		<< "\t|\t\t\t\t\t\t\t|" << endl
		<< "\t|\t(3) " << ability[c][0] << "[" << cost[c][0] << "]\t(4) " << ability[c][1] << "[" << cost[c][1] << "]\t|" << endl
		<< "\t|\t\t\t\t\t\t\t|" << endl
		<< "\t|\t(5) " << ability[c][2] << "[" << cost[c][2] << "]\t(6) Surrender\t\t|" << endl
		<< "\t|_______________________________________________________|" << endl
		<< endl
		<< "\t\t\tYour Move:\t";
	if (filldat == 1 || filldat == 2 || filldat == 3|| (filldat == 4 && c == 1) || (filldat == 5 || filldat == 6)){ // ai code enable
		turn[c] = 0;
		if (Element[0] == Element[1] && filldat != 4){ // ai mirror matchup surrender
			turn[c] = 6;
		}
	}
	else {
		cin >> turn[c];
	}
	if (filldat == 4 && c == 0 && turn[c] == 0){ // sweep mode ai disabled
		turn[c] = 7;
	}
	if ((a[c] == 11) && (turn[c] == 3 || turn[c] == 4 || turn[c] == 5)){
		cout << "Mimic:\t";
		cin >> mimic[c];
		if (mimic[c] == 11 || mimic[c] > 14 || (turn[c] == 5 && (mimic[c] == 13 || mimic[c] == 14))){
			cout << "FAIL" << endl;
			mimic[c] = 6;
		}
	}
	system("CLS");
}

void combat() {

	c = 0; // set current player's turn, run ai code
	e = 1;
	if (turn[c] == 0){
		aigo();
	}
	c = 1;
	e = 0;
	if (turn[c] == 0){
		aigo();
	}
	if (a[0] == 13 && turn[0] == 4 && energy[0] >= cost[0][1]){ // idler's stun interruption, special that it activates before anything else
		status[1].assign("Stunned");
		statusduration[1] = 0;
	}
	if (a[1] == 13 && turn[1] == 4 && energy[1] >= cost[1][1]){
		status[0].assign("Stunned");
		statusduration[0] = 0;
	}
	thisturn = rand() % (speed[0] + speed[1]); // select who goes first

	if (thisturn > speed[0]) {
		c = 1;
		e = 0;
	}
	else {
		c = 0;
		e = 1;
	}
	if ((turn[c] == 4 && a[c] == 2 && energy[c] >= cost[c][1]) || (turn[c] == 4 && mimic[c] == 2 && a[c] == 11 && energy[c] >= cost[c][1])){ // water barrier activation goes here to correctly apply cleansing effect
		status[c].assign("Shielded");
		statusduration[c] = 10;
		cout << "Player " << c + 1 << " puts up a water barrier" << endl;
		attack = 0;
	}
	if (turn[c] == 5 && a[c] == 8){ // dark ult cleanses
		status[c].assign("Healthy");
	}
	if (health[0] > 0 && health[1] > 0) { // is the player stunned?
		if (status[c] == "Stunned"){
			cout << "Player " << c + 1 << " is stunned and cannot act" << endl;
		}

		else{ // determine player action based on number entered
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
	if ((turn[c] == 4 && a[c] == 2 && energy[c] >= cost[c][1]) || (turn[c] == 4 && mimic[c] == 2 && a[c] == 11 && energy[c] >= cost[c][1])){ // water barrier activation
		status[c].assign("Shielded");
		statusduration[c] = 10;
		cout << "Player " << c + 1 << " puts up a water barrier" << endl;
		attack = 0;
	}
	if (turn[c] == 5 && a[c] == 8){ // dark ult cleanse
		status[c].assign("Healthy");
	}
	if (health[0] > 0 && health[1] > 0) { // are they stunned?
		if (status[c] == "Stunned"){
			cout << "Player " << c + 1 << " is stunned and cannot act" << endl;
		}
		else { // what is the player's action?
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
		if (a[0] == 13){ // idler passive
			charge[0] = charge[0] + 2;
			cout << "Idler's Laziness has grown to [" << charge[0] << "]" << endl;
		}
		if (a[1] == 13){
			charge[1] = charge[1] + 2;
			cout << "Idler's Laziness has grown to [" << charge[1] << "]" << endl;
		}
		absorb(); // finish up turn be checking status effects and activating passives
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
	printheader(); // show new health and energy
	checkdead();

	if (filldat == 0 || filldat == 4){ // pause to show results
		system("pause");
	}

}

void checkdead() {

	if (health[0] <= 0 && winner == 0) { // if health = 0, the other player wins
		cout << "Player 1 has been slain" << endl;
		winner = 2;
		looser = 1;
		if (a[1] == 14){ // reset tech to idler for data saving
			a[1] = 13;
		}
		if (a[0] == 14){
			a[0] = 13;
		}
		matchwin = a[1]; // save winner
		matchloose = a[0];
		if (filldat == 0 || filldat == 4){
			system("Color C0");
			system("pause");
			system("Color 0F");
		}
		if (filldat == 3){
			system("Color C0");
		}

	}
	else if (health[1] <= 0 && winner == 0) {
		cout << "Player 2 has been slain" << endl;
		winner = 1;
		looser = 2;
		if (a[1] == 14){ // reset tech to idler for data saving
			a[1] = 13;
		}
		if (a[0] == 14){
			a[0] = 13;
		}
		matchwin = a[0]; // save winner
		matchloose = a[1];
		if (filldat == 0 || filldat == 4){
			system("Color 90");
			system("pause");
			system("Color 0F");
		}
		if (filldat == 3){
			system("Color 90");
		}
	}

}

void victory() {

	system ("CLS"); // you win screen
	cout << "Player " << winner << " has defeated their opponent and achieved victory!" << endl
		<< Element[winner - 1] << "\t" << health[winner - 1] << endl
		<< Element[looser - 1] << endl;
	if (filldat == 4 && winner == 1 && (a[1] == 13 || a[1] == 14)){ // sweep mode victory
		cout << "Sweep Complete!" << endl;
		filldat = 0;
	}
	if ((filldat == 5 || filldat == 6) && sweeper >= 13){
		systemic = systemic + 1;
		if (systemic >= 14){ // system fill options
			systemic = 1;
			if (filldat == 6){
				filldat = 0;
			}
		}

	}
}

void printheader() { // Print HUD
	cout << Element[0] << " Element: \t\t|\t\t" << Element[1] << " Element" << endl
		<< "[\t" << health[0] << "\t]\t|\t\t[\t" << health[1] << "\t]" << endl
		<< "\t[ " << status[0] << " ]\t|\t\t[ " << status[1] << " ]" << endl
		<< "\t[ " << energy[0] << " ]\t\t|\t\t[ " << energy[1] << " ]" << endl
		<< "..................................................................." << endl
		<< endl;
}

void windbody(){
	if (passive[e] == "Wind Body"){ // wind dodges abilities
		hit = 1 + rand() % 100;
		if (hit < dodge[e]){
			attack = 0;
		}
	}
	if (passive[e] == "Stone Skin"){// Earth passive also applies to ability damage reduction, - 1.5x armor
		attack = attack - (armor[e] * 1.5);
	}
	if (status[e] == "Phased"){ // energy element dodge with energy reimbursement and absorbtion

		attack = 0;
		status[e].assign("Healthy");
		switch (turn[c]){
		case 3:
			energy[e] = energy[e] + cost[c][0] + cost[e][0];
			break;
		case 4:
			energy[e] = energy[e] + cost[c][1] + cost[e][0];
			break;
		case 5:
			energy[e] = energy[e] + cost[c][2] + cost[e][0];
			break;
		default :
			break;
		}
	}
}

void hinder(){

	if (status[c] == "Hindered"){ // hinder halves damage
		attack = attack / 2;
	}

}

void barrier(){

	if (status[e] == "Shielded"){ // shield halves damage
		attack = attack / 2;
		if (turn[c] != 1){
			cout << "Player " << e + 1 << "'s shield absorbs the damage" << endl;
		}
	}

}

void shadowbreak(){

	if (status[e] == "Faded"){ // dark dodge, resets to normal if sucsessful

		attack = 0;
		status[e].assign("Healthy");

	}
	if (status[e] == "Boosted"){ // venom dodge and damage boost
		attack = 0;
	}
	if (status[e] == "Warped"){ // tech dodge
		attack = 0;
	}

}

void absorb(){

	if (passive[e] == "Energy Absorbtion"){ // morphling passive energy absorbtion, half mana cost goes to him (rounded up)

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
	hit = 1 + rand() % 100; // does the attack miss?
	if (hit <= dodge[e]) {
		cout << ", but misses" << endl;
		attack = 0;
	}
	else if (hit > dodge[e]) {
		if (passive[c] == "Corrosion"){ // apply venom's poison
			status[e].assign("Poisoned");
			statusduration[e] = 10;
			venom[e] = venom[e] + 1;
		}
		attack = 1 + rand() % power[c]; // calculate attack damage
		if (attack > armor[e]) {
			attack = attack - armor[e];
			if (turn[e] == 2) { // guard halves damage
				attack = attack / 2;
				if (a[e] == 3){ // static's shock guard halves it again
					attack = attack / 2;
					energy[e]++;
					cout << ", but Player " << e + 1 << "'s shock guard absorbs the attack." << endl
						<< "Player " << c + 1 << " attacks";
				}
			}
			if (status[c] == "Rampaging"){ // bonus damage for blood rampage
				attack = attack * 4 + 20;
			}
			if (passive[c] == "Growing Death"){ // dark passive proc
				power[c] = power[c] + 5;
			}
			barrier();
			hinder();
			shadowbreak();
			if (status[c] == "Boosted"){ // venom sneak attack
				attack = attack + 30;
			}
			cout << ", dealing " << attack << " damage." << endl;
			health[e] = health[e] - attack;
			if (a[c] == 8){ // blood 20% lifesteal
				health[c] = health[c] + attack / 5;
			}
			if (passive[c] == "Growing Death"){ // display dark's passive charge
				cout << "Darkness has grown to [" << power[c] << "]" << endl;
			}
			checkdead();
		}
		else { // fail armor
			cout << ", but only scratches the armor." << endl;
			attack = 0;
		}
		if (a[c] == 12 || a[c] == 14){ // energy and tech passive flat damage
			cout << "Player " << e + 1 << " is blasted for [" << charge[c] << "]" << endl;
			health[e] = health[e] - charge[c];
		}
	}
}

void cast1(){

	if (cost[c][0] <= energy[c]) {
		energy[c] = energy[c] - cost[c][0];
		if (a[c] == 12){ // energy passive damage growth
			charge[c] = charge[c] + cost[c][0];
			cout << "Energy's charge grows to [" << charge[c] << "]" << endl;
		}
		if (a[e] == 12){
			charge[e] = charge[e] + cost[c][0];
			cout << "Energy's charge grows to [" << charge[e] << "]" << endl;
		}
		switch (a[c]) {
		case 1: // blast, deal 40 damage and apply burn (10 damage per turn) for 2 turns
			attack = 40;
			windbody();
			shadowbreak();
			barrier();
			hinder();
			status[e].assign("Burning");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			break;
		case 2: // wave, deal 24 damage
			attack = 24;
			windbody();
			hinder();
			shadowbreak();
			barrier();
			health[e] = health[e] - attack;
			health[c] = health[c] + (attack / 4);
			break;
		case 3: // discharge, deplete energy, deal 15 per energy spent
			attack = energy[c] * 15;
			if (a[c] == 12){
				charge[c] = charge[c] + cost[c][0];
				cout << "Manaburn's charge grows to [" << charge[c] << "]" << endl;
			}
			if (a[e] == 12){
				charge[e] = charge[e] + cost[c][0];
				cout << "Manaburn's charge grows to [" << charge[e] << "]" << endl;
			}
			windbody();
			shadowbreak();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			energy[c] = 0;
			break;
		case 4: // divine blessing, heal 25
			health[c] = health[c] + 25;
			attack = 25;
			break;
		case 5: // gust, deal 20 damage, apply storm (3 damage per turn) for 5 turns
			attack = 20;
			windbody();
			hinder();
			shadowbreak();
			barrier();
			status[e].assign("Storm");
			statusduration[e] = 5;
			health[e] = health[e] - attack;
			break;
		case 6: // focus strike, deal 20 damage
			attack = 20;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			break;
		case 7: // boulder, deal 20 damage and stun for 1 turn
			attack = 20;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			status[e].assign("Stunned");
			statusduration[e] = 1;
			break;
		case 8: // Bleed, apply bleed (10% per turn) for 3 turns
			attack = 0;
			status[e].assign("Bleeding");
			statusduration[e] = 3;
			break;
		case 9: // Shadowmeld, go into dodge mode, with energy penalty for misfire, extra passive proc for success
			attack = 0;
			status[c].assign("Faded");
			statusduration[c] = 2;
			power[c] = power[c] + 5;
			venom[c] = 0;
			if (turn[e] <= 2){
				energy[c] = energy[c] - 1;
			}
			else {
				power[c] = power[c] + 5;
			}
			cout << "Darkness has grown to [" << power[c] << "]" << endl;
			break;
		case 10: // ignition, 15 damage per stack of poison
			attack = venom[e] * 15;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			break;
		case 12: // phase shift dodge mode
			if (a[c] == 12){
				attack = 0;
				status[c].assign("Phased");
				statusduration[c] = 2;
			}
			break;
		case 13: // slacker, heal 30% missing health or 20, remove status effects, if cleanse is sucsessful, penalize opponent by 2 energy
			attack = 3 * (200 - health[c]) / 10;
			if (20 >= attack){
				attack = 20;
			}
			health[c] = health[c] + attack;
			if (status[c] != "Healthy"){
				energy[e] = energy[e] - 2;
			}
			else{
				energy[c] = energy[c] - 1;
			}
			status[c].assign("Healthy");
			statusduration[c] = 0;
			venom[c] = 0;
			venom[e] = 0;
			charge[c] = charge[c] + 1;
			break;
		case 14: // Rift jump, dodge mode and apply plasma (5 damage per turn) for 10 turns
			attacking();
			status[c].assign("Warped");
			statusduration[c] = 2;
			venom[c] = 0;
			venom[e] = 0;
			status[e].assign("Plasma");
			statusduration[e] = 10;
			if (turn[e] >= 3){
				energy[c] = energy[c] + cost[c][0];
			}
			break;
		case 11: // read and copy designated ability
			a[c] = mimic[c];
			energy[c] = energy[c] + cost[c][0];
			reimburse();
			a[c] = 11;
			break;
		}
		cout << "Player " << c + 1 << ":\t" << ability[c][0] << " [" << attack << "]" << endl;
	}
	else { // not enough energy
		cout << "Player 2 attempts to use first ability, but is out of energy" << endl;
	}
}

void cast2(){
	if (cost[c][1] <= energy[c]) { // energy's passive absorbtion
		energy[c] = energy[c] - cost[c][1];
		if (a[c] == 12){
			charge[c] = charge[c] + cost[c][0];
			cout << "Manaburn's charge grows to [" << charge[c] << "]" << endl;
		}
		if (a[e] == 12){
			charge[e] = charge[e] + cost[c][0];
			cout << "Manaburn's charge grows to [" << charge[e] << "]" << endl;
		}
		switch (a[c]) {
		case 1: // Flamethrower, 35 damage, if burning, stun, if not, apply burn (10 damage per turn) for 2 turns
			attack = 35;
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
		case 3: // shock absorb, read opposing ability and heal for 3x its damage after the initial damage is applied (results in healing for 2x)
			if (turn[e] == 3 && cost[e][0] >= energy[e]){
				switch (a[e]){
				case 1:
					attack = 40;
					health[c] = health[c] + 60;
					break;
				case 2:
					attack = 66;
					health[c] = health[c] + 99;
					break;
				case 3:
					attack = energy[e] * 15 * 2;
					health[c] = health[c] + 3 * attack / 2;
					break;
				case 5:
					attack = 40;
					health[c] = health[c] + 60;
					break;
				case 6:
					attack = 50;
					health[c] = health[c] + 75;
					break;
				case 7:
					attack = 60;
					health[c] = health[c] + 90;
					break;
				case 10:
					attack = venom[c] * 15 * 2;
					health[c] = health[c] + (3 / 2 * attack);
					break;
				default:
					attack = 0;
					break;
				}

				cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
				energy[c] = energy[c] + 1;
			}
			else if (turn[e] == 4 && cost[e][1] >= energy[e]){
				switch (a[e]){
				case 1:
					attack = 70;
					health[c] = health[c] + 105;
					break;
				case 7:
					attack = health[c] / 10 * 3 * 2;
					health[c] = health[c] + 3 / 2 * attack;
					break;
				case 8:
					attack = 40;
					health[c] = health[c] + 60;
				case 13:
					attack = 2 * (15 + (charge[e] / 3));
					health[c] = health[c] + (3 * (15 + (charge[e] / 3)));
					break;
				case 14:
					attack = 40;
					health[c] = health[c] + 60;
					break;
				default:
					attack = 0;
					break;
				}

				cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
				energy[c] = energy[c] + 2;
			}
			else if (turn[e] == 5 && cost[e][2] >= energy[e]){
				switch (a[e]){
				case 1:
					attack = 240;
					health[c] = health[c] + 360;
					break;
				case 2:
					attack = 220;
					health[c] = health[c] + 330;
					break;
				case 3:
					attack = 200;
					health[c] = health[c] + 300;
					break;
				case 4:
					attack = 300;
					health[c] = health[c] + 450;
					break;
				case 5:
					attack = 200;
					health[c] = health[c] + 300;
					break;
				case 6:
					attack = (300 - health[e]) / 10 * 4 * 2;
					health[c] = health[c] + 3 * ((300 - health[c]) / 10 * 4);
					break;
				case 7:
					attack = 240;
					health[c] = health[c] + 360;
					break;
				case 10:
					attack = (venom[c] * 10 + 50) * 2;
					health[c] = health[c] + 3 / 2 * attack;
					break;
				case 13:
					if (ability[c][2] == "Genocide Halo"){
						attack = 300;
						health[c] = health[c] + 450;
					}
					break;
				default:
					attack = 0;
					break;
				}

				cout << "Player " << c + 1 << " absorbs the enemy ability and heals themselves" << endl;
				energy[c] = energy[c] + 3;
			}
			else {
				attack = 0;
			}
			statusduration[c] = 0;
			break;

		case 4: // hinder, apply hinder (half damage) for 6 turns
			status[e].assign("Hindered");
			statusduration[e] = 6;
			attack = 0;
			break;
		case 5: // wind charge, dodge mode for 1 turns and start charging (+50 damage) for 4 turns
			attack = 0;
			shadowbreak();
			status[c].assign("Charging");
			statusduration[c] = 4;
			dodge[c] = 100;
			break;
		case 6: // meditate, heal 30
			attack = 30;
			health[c] = health[c] + attack;
			break;
		case 7: // shakedown, deal 30% opposing hp as damage
			attack = health[e] / 10 * 3;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			break;
		case 8: // drain, steal 20 hp
			attack = 20;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			health[c] = health[c] + attack;
			break;
		case 9: // blackout, attack twice
			attacking();
			attacking();
			attack = 0;
			break;
		case 10: // sneak attack, start boosted (+30 damage on next attack, dodge mode) for 2 turns
			attack = 0;
			status[c].assign("Boosted");
			statusduration[c] = 2;
			break;
		case 12: // apply manaburn (steal 2x enemy energy and .5x your energy health per turn) for 10 turns
			attack = 0;
			status[e].assign("Manaburn");
			statusduration[e] = 10;
			break;
		case 13: // disruption, 1 turn stun to cancel opponent action, if used against an ability, reimburse energy cost. also heals for 15 + laziness / 3
			attack = 15 + (charge[c] / 3);
			if (turn[e] >= 3){
				energy[c] = energy[c] + cost[c][1];
				cout << "DENIED" << endl;
			}
			charge[c] = charge[c] + 2;
			health[c] = health[c] + attack;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - (attack / 2);
			break;
		case 14: // static grenade, deal 20 damage and apply plasma (5 damage per turn) for 10 turns, if already effected by plasma, deal the remaining damage, stun for as many turns as it was left sitting, and restore energy for the same ammount
			attack = 20;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			if (status[e] == "Plasma"){
				attack = attack + (statusduration[e] * 5);
				status[e].assign("Stunned");
				statusduration[e] = 10 - statusduration[e];
				energy[c] = energy[c] + statusduration[e];
			}
			else {
				status[e].assign("Plasma");
				statusduration[e] = 10;
			}
			health[e] = health[e] - attack;
			break;
		case 11: // copy designated ability
			a[c] = mimic[c];
			energy[c] = energy[c] + cost[c][1];
			reimburse();
			a[c] = 11;
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
		if (a[c] == 12){
			charge[c] = charge[c] + cost[c][0];
			cout << "Manaburn's charge grows to [" << charge[c] << "]" << endl;
		}
		if (a[e] == 12){
			charge[e] = charge[e] + cost[c][0];
			cout << "Manaburn's charge grows to [" << charge[e] << "]" << endl;
		}
		switch (a[c]) {
		case 1:// Rain of Fire, high damage ablilty 120 and apply burn (10 per turn) for 2 turns
			attack = 120;
			windbody();
			shadowbreak();
			hinder();
			barrier();
			status[e].assign("Burning");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			break;

		case 2:// Tsunami, high damage ability, deal 110 and apply hinder (half damage) for 2 turns
			attack = 110;
			windbody();
			shadowbreak();
			barrier();
			hinder();
			status[e].assign("Hindered");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			health[c] = health[c] + (attack / 4);
			break;

		case 3:// High Voltage, 100 stun opponent for 2 turns
			attack = 100;
			windbody();
			hinder();
			barrier();
			shadowbreak();
			status[e].assign("Stunned");
			statusduration[e] = 2;
			health[e] = health[e] - attack;
			break;

		case 4:// Smite, 150 damage
			attack = 150;
			shadowbreak();
			windbody();
			barrier();
			hinder();
			health[e] = health[e] - attack;
			break;

		case 5:// Tempest, increase dodge to 100% for 2 turns (this one included), deal 120 damage
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

		case 6: // Execution, 40% of your missing health as damage
			attack = (300 - health[c]) / 10 * 4;
			shadowbreak();
			windbody();
			barrier();
			hinder();
			health[e] = health[e] - attack;
			break;

		case 7: // quake, 120 damage and apply shaken (15 damage per turn) for 10 turns
			attack = 120;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			status[e].assign("Shaken");
			statusduration[e] = 10;
			break;

		case 8: // ravage, begin rampaging (attack increased to 4x + 20 damage) for 4 turns
			attack = 0;
			status[c].assign("Rampaging");
			statusduration[c] = 4;
			break;

		case 9: // shadow of death, heal 50 and attack 3 times
			health[c] = health[c] + 50;
			shadowbreak();
			attacking();
			attacking();
			attacking();
			attack = 50;
			break;
		case 10: // piercing shot, deal 50 + venom stacks x10 and add 3 stacks
			attack = venom[e] * 10 + 50;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			status[e].assign("Poisoned");
			statusduration[e] = 10;
			venom[e] = venom[e] + 3;
			health[e] = health[e] - attack;
			break;
		case 12: // recoil, deal 10x yours and your opponents energy, reduce opponent's energy to 0
			attack = (energy[c] + cost[c][2]) * 10;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			attack = attack + (energy[e] * 10);
			if (a[c] == 12){
				charge[c] = charge[c] + cost[c][0];
				cout << "Manaburn's charge grows to [" << charge[c] << "]" << endl;
			}
			if (a[e] == 12){
				charge[e] = charge[e] + cost[c][0];
				cout << "Manaburn's charge grows to [" << charge[e] << "]" << endl;
			}
			energy[e] = -1;
			health[e] = health[e] - attack;
			break;
		case 13: // transform into techmaturgy, genocide halo is changed later so it correctly displays now
			attack = 0;
			cout << "Idler has transformed into Techmaturgist" << endl
				<< "\tNew Ability: Rift Jump" << endl
				<< "\tNew Ability: Static Grenade" << endl
				<< "\tNew Ability: Genocide Halo" << endl
				<< "\tNew Passive: Annihilation" << endl;
			Element[c].assign("Tech");
			ability[c][0].assign("Rift Jump      "); //Heal for 20 or 50% missing, whichever is higher, health and remove status effects || Rift Jump: Dodge an attack, attack, and apply plasma, plasma deals 5 damage per turn for 10 turns. Refunds cost if dodging an ability
			ability[c][1].assign("Static Grenade "); //Stun for 2 turns, heal 20 and deal half that in damage, refunds cost if successfully used against an ability || Static Field: Deal 20 damage and apply plasma, if a target already has plasma, they are ignited dealing the remaining damage, stunning for the number of turns spent, and refunding the energy cost
			//ability[c][2].assign("Genocide Halo  "); //Transform into ultimate form "Techmaturgist" (Tech) gaining a whole new set of abilities || Genocide Halo: Deal 150 damage and return to original form
			passive[c].assign("Annihilation"); //Increase charge counter by 3 for every turn spent in idler stance || Annihilation: deal damage for every charge on every attack while in tech stance
			a[c] = 14;
			armor[c] = 6;
			power[c] = 45;
			speed[c] = 100;
			dodge[c] = 35;
			break;
		case 14: // transform into idler, fanales name is corrected later so it displays correctly now
			attack = 150;
			shadowbreak();
			windbody();
			hinder();
			barrier();
			health[e] = health[e] - attack;
			cout << "Techmaturgist has exausted themselves and turns back to Idler" << endl
				<< "\tNew Ability: Slacker" << endl
				<< "\tNew Ability: Disruption" << endl
				<< "\tNew Ability: Fanales" << endl
				<< "\tNew Passive: Rest" << endl;
			Element[c].assign("Idler");
			ability[c][0].assign("Slacker        "); //Heal for 20 or 50% missing, whichever is higher, health and remove status effects || Rift Jump: Dodge an attack, attack, and apply plasma, plasma deals 5 damage per turn for 10 turns. Refunds cost if dodging an ability
			ability[c][1].assign("Disruption     "); //Stun for 2 turns, heal 20 and deal half that in damage, refunds cost if successfully used against an ability || Static Field: Deal 20 damage and apply plasma, if a target already has plasma, they are ignited dealing the remaining damage, stunning for the number of turns spent, and refunding the energy cost
			//ability[c][2].assign("Fanales        "); //Transform into ultimate form "Techmaturgist" (Tech) gaining a whole new set of abilities || Genocide Halo: Deal 150 damage and return to original form
			passive[c].assign("Rest"); //Increase charge counter by 3 for every turn spent in idler stance || Annihilation: deal damage for every charge on every attack while in tech stance
			a[c] = 13;
			armor[c] = 2;
			power[c] = 15;
			speed[c] = 20;
			dodge[c] = 15;
			break;
		case 11: // copy selected ability
			a[c] = mimic[c];
			energy[c] = energy[c] + cost[c][2];
			reimburse();
			a[c] = 11;
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

	case 6: // swordsman's valor, heal 3 per turn
		health[c] = health[c] + 3;
		cout << "Player " << c + 1 << " regains [3] life" << endl;
		break;
	case 4: // holy's cleanse, remove status effects at end of turn
		status[c].assign("Healthy");
		cout << "Player " << c + 1 << " cleanses themselves of impurities" << endl;
		break;
	case 5: // wind, check damage modifier from charge and dodge modifier from tempest
		if (status[c] != "Charging"){
			power[c] = 35;
		}
		else {
			power[c] = 85;
		}
		if (status[c] != "Tempest"){
			dodge[c] = 35;
		}
		else{
			dodge[c] = 100;
		}
		break;
	case 11: // wind, alternate version for morphling, check damage modifier from charge and dodge modifier from tempest
		if (status[c] != "Charging"){
			power[c] = 30;
		}
		else {
			power[c] = 80;
		}
		if (status[c] != "Tempest"){
			dodge[c] = 20;
		}
		else{
			dodge[c] = 100;
		}
		break;
	default:
		break;
	} // reset poison stacks if not poisoned
	if (status[c] != "Poisoned"){
		venom[c] = 0;
	}
}

void statuscheck(){

	statusduration[c] = statusduration[c] - 1;

	if (status[c] == "Burning"){ // deal 10 damage if on fire
		health[c] = health[c] - 10;
		cout << "Player " << c + 1 << " Burns for [10], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Storm"){ // deal 3 damage if effected by gust
		health[c] = health[c] - 3;
		cout << "Player " << c + 1 << " is injured by resonate wind for [3], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Healthy"){ // healthy, do nothing
	}
	else if (status[c] == "Plasma"){ // deal 5 damage if covered in plasma
		health[c] = health[c] - 5;
		cout << "Player " << c + 1 << " Burns for [5], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Shaken"){ // deal 15 damage if ground is shaking from quake
		health[c] = health[c] - 15;
		cout << "Player " << c + 1 << " is shaken for [15]" << endl;
	}
	else if (status[c] == "Bleeding"){  // loose 10% health if bleeding
		attack = health[c] / 10;
		health[c] = health[c] - attack;
		cout << "Player " << c + 1 << " bleeds for [" << attack << "], " << statusduration[c] << " turn(s) remaining" << endl;
	}
	else if (status[c] == "Poisoned"){ // loose 3 health for each stack of poison
		attack = venom[c] * 3;
		health[c] = health[c] - attack;
		cout << "Player " << c + 1 << " is poisoned for [" << attack << "]. There are a total of [" << venom[c] << "] stacks" << endl;
	}
	else if (status[c] == "Manaburn"){ // steal health equal to enemy energy * 2 + your energy / 2
		attack = (energy[c] * 2) + (energy[e] / 2);
		if ((energy[c] * 2) + (energy[e] / 2) <= 0){
			attack = 1;
		}
		health[c] = health[c] - attack;
		health[e] = health[e] + attack;

		cout << "Player " << c + 1 << " is Manaburned for [" << attack << "]" << endl;
	}
	else { // remaining duration
		cout << "Player " << c + 1 << " is [" << status[c] << "], " << statusduration[c] << " turn(s) remaining" << endl;
	}

	if (statusduration[c] <= 0){ // duration expire, status reset
		status[c].assign("Healthy");
	}

}

void record(){
	ifstream infile; // load previous data, add current match data to it, and save new data
	infile.open("Balance.txt");

	// cycle load for matrix
	j = 0;

	while (j < 13){

		k = 0;

		while (k < 13){
			infile >> matchup[k][j];
			k++;

		}
		j++;

	}

	infile.close();

	matchwin = matchwin - 1;
	matchloose = matchloose - 1;

	// add results
	matchup[matchloose][matchwin]++;

	ofstream outfile;

	outfile.open("Balance.txt");

	// save new data
	j = 0;

	while (j < 13){

		k = 0;

		while (k < 13){
			outfile << matchup[k][j] << "\t";
			k++;

		}
		outfile << endl;
		j++;
	}

	j = 0;

	while (j < 10){

		k = 0;

		while (k < 10){
			cout << matchup[k][j] << "\t";
			k++;

		}
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
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 4){
				turn[c] = 5;
			}
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
		if (energy[c] >= cost[c][1] && status[c] != "Shielded"){
			turn[c] = 4;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 1 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 4){
				turn[c] = turn[c] - 1;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 1){
				turn[c] = turn[c] + 2;
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
		if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 4){
				turn[c] = 5;
			}
		}
		else if (energy[c] >= cost[c][1] && status[e] != "Hindered"){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 3 || turn[c] == 2){
				turn[c] = 4;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
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
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 2){
				turn[c] = 3;
			}
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 4){
				turn[c] = 5;
			}
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
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 4){
				turn[c] = 5;
			}
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
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 2 || turn[c] == 3){
				turn[c] = 4;
			}
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
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
		if (status[c] == "Rampaging"){
			turn[c] = 1;
		}
		else if (status[e] != "Bleeding" && energy[c] >= cost[c][0] && health[e] >= 100){
			turn[c] = (rand() % 3) + 1;
			if (energy[c] == 2){
				turn[c] = 3;
			}
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
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
		if (energy[c] >= cost[c][2]){ //use ult if available
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
		}
		else if (health[e] <= power[c]){ //attack if darkness is greater than enemy hp
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
		else if (energy[e] == cost[e][2]){ //dodge if enemy 3 is ready
			turn[c] = 3;
		}
		else if (energy[e] == cost[e][1]){ //dodge if enemy 2 is ready
			turn[c] = 3;
		}
		else if (energy[e] == cost[e][0]){ //dodge if enemy 1 is ready
			turn[c] = 3;
		}
		else if (energy[c] >= cost[c][1]){ //random move if 2 is ready
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
		}
		else if (energy[c] >= cost[c][0]){ // random move if 1 is ready
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 2){
				turn[c] = 1;
			}
		}
		else if (energy[c] < cost[c][0]){ // attack
			turn[c] = 1;
		}
		break;
	case 10: // venom ai
		if (status[c] == "Boosted"){
			turn[c] = 1;
		}
		else if (energy[c] >= cost[c][1] && energy[e] >= cost[e][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 3 || turn[c] == 5){
				turn[c] = 4;
			}
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
	case 11: // mimic ai
		if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			mimic[c] = (rand() % 13) + 1;
			if (mimic[c] >= 11){
				mimic[c]++;
			}
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			mimic[c] = (rand() % 13) + 1;
			if (mimic[c] >= 11){
				mimic[c]++;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
			mimic[c] = (rand() % 13) + 1;
			if (mimic[c] >= 11){
				mimic[c]++;
			}
		}
		else {
			turn[c] = (rand() % 2) + 1;
		}
		break;
	case 12: // Energy ai
		if (energy[c] >= cost[c][0] && (energy[e] == cost[e][0] || energy[e] == cost[e][2])){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 4 || turn[c] == 5){
				turn[c] = 3;
			}
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
		}
		else if (energy[c] >= cost[c][1]){
			turn[c] = (rand() % 4) + 1;
			if (status[e] == "ManaBurn" && turn[c] == 4){
				turn[c] = 1;
			}
		}
		else if (energy[c] >= cost[c][0]){
			turn[c] = (rand() % 3) + 1;
		}
		else if (energy[c] < cost[c][0]){
			turn[c] = 1;
		}
		break;
	case 13: // idler ai
		if (status[c] == "Stunned"){
			turn[c] = 2;
		}
		else if (energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 1 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
		}
		else if (energy[c] >= cost[c][0] && status[c] != "Healthy"){
			turn[c] = 3;
			if (status[c] == "Poisoned" && health[c] >= 100 && venom[c] <= 4){
				if (energy[c] >= cost[c][1]){
					turn[c] = 4;
				}
				else {
					turn[c] = 2;
				}
			}
		}
		else if ((energy[e] == cost[e][0] || energy[e] == cost[e][1] || energy[e] == cost[e][2]) && energy[c] >= cost[c][1]){
			turn[c] = 4;
		}
		else if (health[c] <= 60 && energy[c] >= cost[c][0]){
			turn[c] = 3;
		}
		else {
			turn[c] = 2;
		}
		break;
	case 14: // tech ai
		if (status[c] == "Stunned"){
			turn[c] = 2;
		}
		else if ((health[e] <=150 || health[c] <= 50) && energy[c] >= cost[c][2]){
			turn[c] = (rand() % 5) + 1;
			if (turn[c] == 2 || turn[c] == 3 || turn[c] == 4){
				turn[c] = 5;
			}
		}
		else if ((energy[e] == cost[e][0] || energy[e] == cost[e][1] || energy[e] == cost[e][2]) && energy[c] >= cost[c][0]){
			if (energy[c] >= cost[c][1] && status[e] == "Plasma"){
				turn[c] = 4;
			}
			else {
				turn[c] = 3;
			}
		}
		else if (energy[c] >= cost[c][1] && status[e] == "Plasma"){
			turn[c] = (rand() % 4) + 1;
			if (turn[c] == 2 || turn[c] == 3){
				turn[c] = 1;
			}
		}
		else if (energy[c] >= cost[c][0] && status[e] != "Plasma"){
			turn[c] = (rand() % 3) + 1;
			if (turn[c] == 2 || turn[c] == 3){
				turn[c] = 1;
			}
		}
		else {
			turn[c] = 1;
		}
		break;
	default:
		cout << "There is no ai code for " << Element[c] << " Element" << endl;
		break;
	}
}

void searchdata(){

	do {
		cout << "Would you like to search for a specific matchup?" << endl
			<<  "               (y for yes, anything else for no)" << endl;
		if (filldat < 2){
			cin >> search;
		}
		if (filldat != 4){
			if (search == 'y'){ // imput desired matchup

				cout << "First element:" << endl;
				cin >> Element[0];
				cout << "Second element:" << endl;
				cin >> Element[1];
				c = 0;

				ifstream infile;
				infile.open("Balance.txt");

				j = 0;
				// cycle open matrix
				while (j < 13){

					k = 0;

					while (k < 13){
						infile >> matchup[k][j];
						k++;

					}
					j++;

				}

				infile.close();

				c = 0;

				while (c < 2){ // load data number based on elements entered
					if (Element[c] == "Fire"){
						a[c] = 0;
					}
					else if (Element[c] == "Water"){
						a[c] = 1;
					}
					else if (Element[c] == "Static"){
						a[c] = 2;
					}
					else if (Element[c] == "Holy"){
						a[c] = 3;
					}
					else if (Element[c] == "Wind"){
						a[c] = 4;
					}
					else if (Element[c] == "Earth"){
						a[c] = 6;
					}
					else if (Element[c] == "Blood"){
						a[c] = 7;
					}
					else if (Element[c] == "Dark"){
						a[c] = 8;
					}
					else if (Element[c] == "Venom"){
						a[c] = 9;
					}
					else if (Element[c] == "Morphling"){
						a[c] = 10;
					}
					else if (Element[c] == "Energy"){
						a[c] = 11;
					}
					else if (Element[c] == "Idler" || Element[c] == "Techmaturgist"){
						a[c] = 12;
					}
					else if (Element[c] == "All"){
						a[c] = 99;
					}
					else {
						Element[c].assign("Swordsman");
						a[c] = 5;
					}
					c++;
				}
				system("CLS");
				if (a[0] == 99 || a[1] == 99){ // if all to be shown, print all win rates

					cout << "Element:\t\tWins:\tLosses:\tTotal:\tWin Rate:" << endl << endl;
					total = 0;
					wins = 0;
					k = 0;
					j = 0;

					while (j < 13){
						total = 0;
						wins = 0;
						j++;
						switch (j){
						case 1:
							Element[c] = "Fire     ";
							break;
						case 2:
							Element[c] = "Water    ";
							break;
						case 3:
							Element[c] = "Static   ";
							break;
						case 4:
							Element[c] = "Holy     ";
							break;
						case 5:
							Element[c] = "Wind     ";
							break;
						case 6:
							Element[c] = "Swordsman";
							break;
						case 7:
							Element[c] = "Earth    ";
							break;
						case 8:
							Element[c] = "Blood    ";
							break;
						case 9:
							Element[c] = "Dark     ";
							break;
						case 10:
							Element[c] = "Venom    ";
							break;
						case 11:
							Element[c] = "Morphling";
							break;
						case 12:
							Element[c] = "Energy   ";
							break;
						case 13:
							Element[c] = "Idler    ";
							break;
						}
						j = j - 1;
						cout << Element[c] << "\t\t";

						k = 0;
						total = 0;
						wins = 0;

						while (k < 13){
							total = total + matchup[k][j] + matchup[j][k];
							wins = wins + matchup[k][j];
							k++;
						}

						total = total - (2 * matchup[j][j]);
						wins = wins - matchup[j][j];
						j++;

						cout << wins << "\t" << total - wins << "\t" << total << "\t" << (wins / total) * 100 << "%" << endl << endl;

						total = 0;
						wins = 0;
					}
					cout << endl;

				}

				else if (a[0] != a[1]){ // search for specific mathup, show wins vs losses
					ifstream infile;
					infile.open("Balance.txt");

					j = 0;
					// cycle open to load matrix of data
					while (j < 13){

						k = 0;

						while (k < 13){
							infile >> matchup[k][j];
							k++;

						}
						j++;

					}

					infile.close();

					chance = matchup[a[1]][a[0]] + matchup[a[0]][a[1]];

					cout << "\t" << Element[0] << "\t" << Element[1] << endl
						<< "Wins:\t" << matchup[a[1]][a[0]] << "\t\t" << matchup[a[0]][a[1]] << endl
						<< "% chance of victory:  " << matchup[a[1]][a[0]] * 100 / chance << "%" << endl
						<< endl;
				}

				else if (a[0] == a[1]){ // search a single element's stats
					total = 0;
					wins = 0;
					k = 0;

					while (k < 13){
						total = total + matchup[k][a[0]] + matchup[a[0]][k];
						wins = wins + matchup[k][a[0]];
						k++;
					}
					total = total - (2* matchup[a[0]][a[0]]);
					wins = wins - matchup[a[0]][a[0]];

					cout << "\t" << Element[0] << " Element:" << endl
						<< "Total Games:  " << total << endl
						<< "Wins:         " << wins << endl
						<< "Losses:       " << total - wins << endl
						<< "Win %:        " << wins * 100 / total << "%" << endl
						<< endl;
					cout << "Best Matchups:" << endl;
					for (k = 0; k < 13; k++){
						if (matchup[k][a[0]] > matchup[a[0]][k]){
							calcwin();
						}

					}
					cout << endl
						<< "Even Matchups" << endl;
					for (k = 0; k < 13; k++){
						if (matchup[k][a[0]] == matchup[a[0]][k]){
							calcwin();
						}

					}
					cout << endl;
					cout << "Worst Matchups:" << endl;
					for (k = 0; k < 13; k++){
						if (matchup[k][a[0]] < matchup[a[0]][k]){
							calcwin();
						}

					}
					cout << endl;
					system("pause");
				}
			}
		}
	} while(search == 'y');
}

void calcwin(){ // calculate the win rate for looking up a singlee element's data
	total = matchup[k][a[0]];
	total = total + matchup[a[0]][k];
	wins = matchup[k][a[0]];

	switch(k){
	case 0:
		cout << "Fire\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 1:
		cout << "Water\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 2:
		cout << "Static\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 3:
		cout << "Holy\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 4:
		cout << "Wind\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 5:
		cout << "Swordsman\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 6:
		cout << "Earth\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 7:
		cout << "Blood\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 8:
		cout << "Dark\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 9:
		cout << "Venom\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 10:
		cout << "Morphling\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 11:
		cout << "Energy\t\t" << (wins / total) * 100 << "%" << endl;
		break;
	case 12:
		cout << "Idler\t\t" << (wins / total) * 100 << "%" << endl;
	}
}

void ability1describe(){

	switch(a[c]){

	case 1:
		cout << "Deal 40 Damage to the Enemy" << endl;
		break;

	case 2:
		cout << "Deal 24 Damage to the Enemy" << endl;
		break;

	case 3:
		cout << "Consume all energy to deal 15 times the energy used in damage" << endl;
		break;

	case 4:
		cout << "Restore 25 Health" << endl;
		break;

	case 5:
		cout << "Deal 20 damage, and then 3 for the next 5 turns" << endl;
		break;

	case 6:
		cout << "Deal 20 damage" << endl;
		break;

	case 7:
		cout << "Deal 20 damage and stun the enemy for 1 turn" << endl;
		break;

	case 8:
		cout << "Deal 10% of the enemy's health for 3 turns" << endl;
		break;

	case 9:
		cout << "Evade all damage next turn, stack passive once. If no ability is dodged," << endl << "Energy Cost is increased to 2";
		break;

	case 10:
		cout << "Deal 20 damage per stack of poison" << endl;
		break;

	case 11:
		cout << "Copy any first ability" << endl;
		break;

	case 12:
		cout << "Take no damage next turn. If it blocks and ability," << endl << "refund the cost and gain the mana cost of the ability used" << endl;
		break;

	case 13:
		cout << "Heal 30% of missing health or 20, whichever is higher. Remove Debuffs." << endl << "Builds 1 additional charge" << endl;
		break;
	}

}

void ability2describe(){

	switch (a[c]){

	case 1:
		cout << "Deal 35 damage, if they are on fire, stun them for 2 turns" << endl;
		break;

	case 2:
		cout << "Gain a shield that halfs incoming damage for 10 turns, can be used to remove all debuffs" << endl;
		break;

	case 3:
		cout << "Absorb an enemy ability getting healed for 2x the ammount after taking the initial damage" << endl;
		break;

	case 4:
		cout << "Half your opponent's damage for 3 turns" << endl;
		break;

	case 5:
		cout << "Take no damage this turn, then increase attack damage by 50 for 3 turns" << endl;
		break;

	case 6:
		cout << "Restore 30 health" << endl;
		break;

	case 7:
		cout << "Deal 30% of the enemy's health in damage" << endl;
		break;

	case 8:
		cout << "Steal 20 health" << endl;
		break;

	case 9:
		cout << "Attack twice" << endl;
		break;

	case 10:
		cout << "Take no damage this turn, next attack deals 40 extra damage" << endl;
		break;

	case 11:
		cout << "Copy any second ability" << endl;
		break;

	case 12:
		cout << "Deals 2x enemy energy and 1/2 your energy in damage per turn," << endl << "get healed for the same ammout for 10 turns" << endl;
		break;

	case 13:
		cout << "Stun an enemy, heal 15 + charges/3 and deal half that in damage." << endl << "If it blocks an ability, refund the cost. Builds 2 additional charges" << endl;
		break;
	}

}

void ability3describe(){

	switch (a[c]){

	case 1:
		cout << "Deal 120 damage" << endl;
		break;

	case 2:
		cout << "Deal 110 damage and half enemy damage for 2 turns" << endl;
		break;

	case 3:
		cout << "Deal 100 damage and stun opponent for 2 turns" << endl;
		break;

	case 4:
		cout << "Deal 150 damage" << endl;
		break;

	case 5:
		cout << "Deal 100 damage and take no damage for 2 turns" << endl;
		break;

	case 6:
		cout << "Deal 40% of your missing health in damage" << endl;
		break;

	case 7:
		cout << "Deal 120 damage and 15 damage per turn for 10 turns" << endl;
		break;

	case 8:
		cout << "Deal 4x + 20 damage for 3 turns" << endl;
		break;

	case 9:
		cout << "Restore 50 health and attack 3 times" << endl;
		break;

	case 10:
		cout << "Deal 50 damage +10 per stack of poison, and apply 3 stacks" << endl;
		break;

	case 11:
		cout << "Copy any third ability" << endl;
		break;

	case 12:
		cout << "Deal damage equal to 10x yours and enemy's energy and reduce their energy to 0" << endl;
		break;

	case 13:
		cout << "Transform" << endl;
		break;

	}

}

void passivedescribe(){

	switch (a[c]){

	case 1:
		cout << "Deal 10 damage for 2 turns after using an ability" << endl;
		break;

	case 2:
		cout << "25% of ability damage is returned as health" << endl;
		break;

	case 3:
		cout << "A successful guard will block 25% more damage and will restore 1 energy" << endl;
		break;

	case 4:
		cout << "Remove all debuffs at the end of the turn" << endl;
		break;

	case 5:
		cout << "Dodge applies to abilities in addition to normal attacks" << endl;
		break;

	case 6:
		cout << "Regenerate 3 health per turn" << endl;
		break;

	case 7:
		cout << "150% of armor applies to abilities" << endl;
		break;

	case 8:
		cout << "20% of attack damage will be returned as health" << endl;
		break;

	case 9:
		cout << "Every attack will increase maximum attack damage by 5" << endl;
		break;

	case 10:
		cout << "Attacking applies poison dealing 3 damage per turn, can stack multiple times" << endl;
		break;

	case 11:
		cout << "Enemy abilities transfer half their energy cost to you" << endl;
		break;

	case 12:
		cout << "Gain bonus flat damage equal to the energy cost of all abilities cast" << endl;
		break;

	case 13:
		cout << "Increase charge by 2 for every turn" << endl;
		break;
	}
}

void visuals(){ // wip

}

void describe(){
	switch (a[c]){

	case 1:
		cout << "A powerful mage that uses simple combos for large damage and stunning to avoid" << endl << "retaliation. Strong in short skirmishes as they lack healing ability for" << endl << "longer slugfests." << endl;
		break;

	case 2:
		cout << "Defensive mage who tries to drag the battle out thanks to shielding and" << endl << "regeneration. Power is significantly weakened if the battle ends quickly." << endl;
		break;

	case 3:
		cout << "Defensive specialist who absorbs enemy attacks, turning them into health" << endl << "and energy. They then use this energy for heavy hitting, high cost abilities." << endl << "Careful timing is paramount in order to avoid wasting energy" << endl;
		break;

	case 4:
		cout << "Healer who boasts high combat stats and large nuking potential with Smite." << endl << "Weak in short skirmeshes due to inability to get multiple heals out, or store" << endl << "up long enough for Smite" << endl;
		break;

	case 5:
		cout << "Mobility specialist who can dodge both attacks and abilities." << endl << "Weak in drawn out fights due to inability to heal" << endl;
		break;

	case 6:
		cout << "Powerhouse fighter who boasts high combat stats and straightforward abilites." << endl << "Execution only deals significant damage if you are at low health, keep this in" << endl << "mind when fighting" << endl;
		break;

	case 7:
		cout << "Heavy armor shock and awe fighter who thrives in mid length fights." << endl << "Lack of starting energy and high costs leads to a weak early game," << endl << "but this is helped by high natural durability. Cannot last in fights that go too long though," << endl << "as he lacks sustain abilities." << endl;
		break;

	case 8:
		cout << "Fighter whose attack is also their defence." << endl << "Lacks the ability to survive front end burst and can be locked down easily, be careful." << endl;
		break;

	case 9:
		cout << "Lightweight assassin who dances around their opponent until he sees an opening" << endl << " to finish. Dodge timing is key to avoid damage as their offence is only" << endl << "notable in the later stages of the game." << endl;
		break;

	case 10:
		cout << "Assassin who poisons enemies early and kills them quickly." << endl << "Be sure to keep poison stacks up as all of your power will come from them." << endl << "Lack of a heal or any significant defensive abilty also means you need to win fast, or not at all" << endl;
		break;

	case 11:
		cout << "Unknown entity who can use any ability from any character." << endl << "Knowledge of all character's abilities is required in order to optimally play the morphling." << endl;
		break;

	case 12:
		cout << "Anti mage who can trounce any opponent foolish enough to stock up energy" << endl << "Energy type looses all of their power if their opponent uses little energy" << endl;
		break;

	case 13:
		cout << "Lazy weakling who can sustain through heavy damage, but their untapped potential" << endl << "in technology magic is a force to be reckoned with." << endl << "High cost risk and reward abilities can be power, but misuse can leave them helpless." << endl;
		break;
	}
	cout << endl << endl;
}

void reimburse(){ // morphling copy ability
	// save previous hp and energy
	hpsave = health[c];
	mnsave = energy[c];
	// set morphling to new character
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
	case 12:
		Element[c] = "ManaBurn";
		break;
	case 13:
		Element[c] = "Valkyrie";
		break;
	}

	setplayer();
	// reset health to saved values
	health[c] = hpsave;
	energy[c] = mnsave;
	// which ablity tier are they copying?
	switch (turn[c]){
	case 3:
		cast1();
		break;
	case 4:
		cast2();
		break;
	case 5:
		cast3();
		break;
	}
	// save new hp and energy values
	hpsave = health[c];
	mnsave = energy[c];
	// reset to morphling
	Element[c] = "1029384756";

	setplayer();
	// reset health and energy to saved values
	health[c] = hpsave;
	energy[c] = mnsave;

}

void topmenu(){ // title screen

	cout << "                                                    Jasonwynn10's Battle Of The Gods Project:" << endl
		<< "                                            Please enable fullscreen now" << endl
		<< endl
		<< endl
		<< endl;



	system("pause");
	system("CLS");

}
