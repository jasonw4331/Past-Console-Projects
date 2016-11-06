#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

string addmovie, removemovie, movietitle;
vector<string> movieList,snackList, drinkList;
vector<string>::iterator movieIter,snackIter, drinkIter;
const double movieCost=6.99;
char selection;
int x=0;
double number, total;
ifstream upload;

void snackinput() ///Edit what the snacks are here
{
snackList.push_back("Skittles");
snackList.push_back("twislers");
snackList.push_back("m&m's");
snackList.push_back("Nerds");
snackList.push_back("Laughy taffy");
snackList.push_back("gum drops");
}
void snackpick() ///Picking snacks code
{
cout<<"Do you want any snacks? (Y or N)\n> ";
cin>>selection;
cout<<endl;
if(selection == 'y' || selection == 'Y'){
cout<<" We currently have in stock:"<<endl;
snackIter = snackList.begin();
while(x!=snackList.size()-1){
cout<<" "<<*snackIter<<",";
++snackIter;
x++;}
cout<<"and "<<*snackIter<<endl;
cout<<""<<endl;


}}
void drinkinput() ///Edit what the drinks are here
{
drinkList.push_back("Coca-Cola");
drinkList.push_back("Sprite");
drinkList.push_back("Pepsi");
drinkList.push_back("Rootbeer");
drinkList.push_back("Fanta");
drinkList.push_back("Water");
drinkList.push_back("Hi-C");
}
void drinkpick() ///Picking drinks code
{
cout << "Do you want any drinks? (Y or N)\n> ";
cin >> selection;
cout << endl;
if(selection == 'y' || selection == 'Y'){
cout<<"We currently have: "<<endl;
drinkIter = drinkList.begin();
x=0;
while(x!=drinkList.size()-1){
cout<<" "<<*drinkIter<<",";
++drinkIter;
x++;}
cout<<"and "<<*drinkIter<<endl;




}}
void refreshmentsbuy() ///code for buying the refreshments
{

}
void movieupload() ///go to the movies.txt file to change the movies. *Remember to put a ':' as the first thing and after each movie*
{
upload.open("movies.txt");
while(getline(upload,removemovie,':')){
upload>>addmovie;
movieList.push_back(addmovie);
sort(movieList.begin(), movieList.end());
cin.clear();
cin.sync();}
}
void moviepick() ///Picking movies code
{
cout<<"\n Your movie options are:\n";
movieIter = movieList.begin();
int x=0;
while(x!=movieList.size()-1){
cout<<" "<<*movieIter<<",";
++movieIter;
x++;}
cout<<"and "<<*movieIter;
cout<<endl<<"What will you choose?"<<endl;
cin>>movietitle;
}
void moviedisplay()
{

}
int main()
{
cout<<"Would you like to see a movie today? (Y or N)\n> ";
cin>>selection;
if(selection == 'y' || selection == 'Y'){
cout << "All Movies are $6.99 per ticket." << endl;
cout << "How many tickets for your movie: " << endl;
cin >> number;
total=movieCost*number;
cout << "Total Price for movie tickets: $" << total << endl;
cout<<"Please pay with your Credit/Debit Card"<<endl<<endl;

snackinput();
snackpick();
drinkinput();
drinkpick();
refreshmentsbuy();
movieupload();
moviepick();
moviedisplay();}
cin.get();
return 0;
}
