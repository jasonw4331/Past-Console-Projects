// Password Input

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <string>

using namespace std;

int main ()
{
	char ch[9];
	char mypass[5]="pass";
	int y=0;
	char upass[]="     ";

	cout<<"Enter PIN: ";






	do{
		ch[0]=getch();

		if(ch[0]==13 || y==7) //enter is the 13 scan code
		{
			upass[y]='\0'; //null char, end of your upass string
			break;
		}
		else if(ch[0]==8 && y!=0) //scancode 8 is backspace
		{
			y--;
			cout<<"\b";
			cout<<" ";
			cout<<"\b";
		}
		else
		{
			y++;
			upass[y]=ch[0]; //assign the value 'ch' as your password
			cout<<"*";

		}
}
	while(1);

	if(strcmp(mypass,upass)==0){


		cout<<"\n Granted";

}
	else
	{
		cout<<"\n Denied";
	}
}
