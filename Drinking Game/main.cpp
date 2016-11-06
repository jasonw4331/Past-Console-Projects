#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#define CHOICES 7
#define TIME 10

void drinks();
int rand0toN(int n);

using namespace std;

int main(){

    int p;
    srand(time(NULL));  // Set seed for Randomizing

    //Prompt user with instructions and ask for players
    cout << "~~~~~Welcome to the drinking game!!~~~~~\n\n";
    cout << "Instructions:\n";
    cout << "1: Enter number of players and assign each player a number.\n";
    cout << "2: Each player has 10 seconds to complete drinking task. Start when\n";
    cout << "it says go.\n";
    cout << "3: If can/glass is not on the table before time is up\n";
    cout << "players loses and is out of the game.\n\n";
    cout << "Enter number of players(0 to exit): ";
    cin >> p;

    //Cycle through number of players, 0 to exit.
    while(p!=0){
            for(int i=1;i<=p;i++){
            cout << "Player " << i << endl;
            drinks();
            cout << " Ready... Set...\n";
                Sleep(6000);//Give them some time to read the challenge.
                cout << "GOOOOO!\n";
                //Count down timer.
                for(int s=1;s<=TIME;s++){
                    Sleep(1000);
                    cout << s << endl;
                }
            cout << "Time's up!!!\n\n";
            Sleep(1000);
            }
            cout << "Enter new number of players(0 to exit): ";
            cin >> p;
    }





system("pause");
return 0;
}

//This function makes a random choice for the player.
void drinks(){
    int c = rand0toN(CHOICES);
    switch(c){
        case 1:
            cout << "Take 1 gulps!";
            break;

        case 2:
            cout << "Take 2 gulps!";
            break;

        case 3:
            cout << "Take 3 gulps, or 1 shot!";
            break;

        case 4:
            cout << "Slam your drink!";
            break;

        case 5:
            cout << "Choose someone for 2 gulps! Pick quick!";
            break;

        case 6:
            cout << "Choose someone for 3 gulps or 1 shot! Pick quick!";
            break;

        case 7:
            cout << "Take shots until the clock runs out!(Or slam your drink)";
            break;
        default:
            break;
    }


}
//Random number selection for function "drinks"
int rand0toN(int n){
    return (rand()%n)+1;

}
