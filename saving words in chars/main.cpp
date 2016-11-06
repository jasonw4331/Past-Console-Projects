#include <iostream>

using namespace std;

int main()
{
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
    char g;
    int h;

    cout << "enter a letter per space\n";
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    cin >> g;

    cout << "your word was " << a << b << c << d << e << f << g << " correct? \n\n1 is yes and 2 is no\n       ";
    cin >> h;

    if(h==1){
        cout << "you said yes";

    }else{cout << "you said no, ";
        cout << "please enter a letter per space\n";
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    cin >> g;

    cout << "your word was " << a << b << c << d << e << f << g << " correct? \n\n1 is yes and 2 is no\n       ";
    cin >> h;

    if(b==1){
        cout << "you said yes";

    }else{
        cout << "you said no";


    }

    }
}
