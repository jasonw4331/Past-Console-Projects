#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;

int main()
{
    double angle;
    double sinVal;
    double numSpaces;
    int numSteps=40;
    double maxAngle=M_PI*4;
    int i,j;

    for(i=0; i<=numSteps; i++)
    {
         angle=(double)i/(double)numSteps*maxAngle;
         sinVal=sin(angle);
         numSpaces=30+sinVal*30;
         printf("%3d:%5.2f",i,angle);
        for(j=0; j<=numSpaces; j++)
        {
         printf(" ");
    	}
    	printf("*\n");
}
return 0;
}
