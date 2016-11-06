#include <iostream>
#include <windows.h>
using namespace std;
void p1();
void p2();
void p3();
double P,P2,p,ans,ans2,restart;
char V;
int Pick,Pick2,Pick3,Parts;
int main()
{
while(restart!=2){
cout<<"How many steps are in this equation?\n> ";
cin>>Parts;
switch(Parts){
case 1:
p1();
break;
case 2:
p2();
break;
default:
cout<<"I do not have that many steps coded in yet.\n";
break;
}
cout<<"\n\nRestart?\n1) Yes\n2) No\n> ";
cin>>restart;
system("cls");
}}
void p1()
{
cout<<"EX:"<<endl;
    cout<<"\tW3===9"<<endl;
    cout<<"\t--  --"<<endl;
    cout<<"\t 3   3"<<endl;
    cout<<"\t------"<<endl;
    cout<<"\tW====3"<<endl;
    cout<<"______________________________________________"<<endl;
    cout<<"Please enter the variable letter: ";
    cin>>V;
    cout<<"\nPlease enter the number next to the variable: ";
    cin>>P;
    cout<<"\nPlease enter the answer: ";
    cin>>p;
    cout<<"\nWhat type of equation is this?\n1) Add\n2) Subtract\n3) Multiply\n4) Divide"<<endl;
    cin>>Pick;
    switch(Pick){
    case 4:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P;
    cout<<"\t"<<V<<"/"<<P<<"==="<<p<<endl;
    cout<<"\t*"<<P<<"    *"<<P<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 3:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p/P;
    cout<<"\t"<<V<<P<<"==="<<p<<endl;
    cout<<"\t---  ---"<<endl;
    cout<<"\t "<<P<<"   "<<P<<endl;
    cout<<"\t---------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 2:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p+P;
    cout<<"\t"<<V<<"-"<<P<<"==="<<p<<endl;
    cout<<"\t+"<<P<<"   +"<<P<<endl;
    cout<<"\t--------"<<endl;
    cout<<"\t  "<<V<<"==="<<ans<<endl;
    break;
    case 1:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p-P;
    cout<<"\t"<<V<<"+"<<P<<"==="<<p<<endl;
    cout<<"\t-"<<P<<"   -"<<P<<endl;
    cout<<"\t--------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;}}
void p2()
{
cout<<"EX:"<<endl;
    cout<<"\tW3+2===9"<<endl;
    cout<<"\t-----  --"<<endl;
    cout<<"\t 3     3"<<endl;
    cout<<"\t--------"<<endl;
    cout<<"\t W=====3"<<endl;
    cout<<"\t-2    -2"<<endl;
    cout<<"\t--------"<<endl;
    cout<<"\t W=====1"<<endl;
    cout<<"______________________________________________"<<endl;
    cout<<"Please enter the variable letter: ";
    cin>>V;
    cout<<"\nPlease enter the number next to the variable: ";
    cin>>P;
    cout<<"\nPlease enter the other number next to the variable: ";
    cin>>P2;
    cout<<"\nPlease enter the answer: ";
    cin>>p;
    cout<<endl<<"\t"<<V<<"_"<<P<<"_"<<P2<<"==="<<p<<endl;
    cout<<"\nWhat is equation type 1?\n1) Add\n2) Subtract\n3) Multiply\n4) Divide"<<endl;
    cin>>Pick;
    switch(Pick){
    case 4:
    cout<<"\t"<<V<<"/"<<P<<"_"<<2<<"==="<<p<<endl;
    cout<<"\nWhat is equation type 2?\n1) Add\n2) Subtract\n3) Multiply\n4) Divide"<<endl;
    cin>>Pick2;
    switch(Pick2){
    case 4:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P; ans=ans*P2;
    cout<<"\t"<<V<<"/"<<P<<"/"<<P2<<"==="<<p<<endl;
    cout<<"\t *"<<P<<"     *"<<P<<endl;
    cout<<"\t *"<<P2<<"     *"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 3:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P; ans=ans/P2;
    cout<<"\t"<<V<<"/"<<P<<"*"<<P2<<"==="<<p<<endl;
    cout<<"\t *"<<P<<"     *"<<P<<endl;
    cout<<"\t /"<<P<<"     /"<<P<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 2:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P; ans=ans+P2;
    cout<<"\t"<<V<<"/"<<P<<"-"<<P2<<"==="<<p<<endl;
    cout<<"\t *"<<P<<"     *"<<P<<endl;
    cout<<"\t +"<<P2<<"     +"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 1:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P; ans=ans-P2;
    cout<<"\t"<<V<<"/"<<P<<"+"<<P2<<"==="<<p<<endl;
    cout<<"\t *"<<P<<"     *"<<P<<endl;
    cout<<"\t -"<<P2<<"     -"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    }
    break;
    case 3:
    cout<<"\t"<<VP<<"_"<<2<<"==="<<p<<endl;
    cout<<"\nWhat is equation type 2?\n1) Add\n2) Subtract\n3) Multiply\n4) Divide"<<endl;
    cin>>Pick2;
    switch(Pick2){
    case 4:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p/P; ans=ans*P2;
    cout<<"\t"<<V<<P<<"/"<<P2<<"==="<<p<<endl;
    cout<<"\t-----  --"<<endl;
    cout<<"\t "<<P<<"     "<<P<<endl;

    cout<<"\t *"<<P2<<"     *"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 3:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p/P;
    cout<<"\t"<<V<<P<<"*"<<P2<<"==="<<p<<endl;
    cout<<"\t-----  --"<<endl;
    cout<<"\t "<<P<<"     "<<P<<endl;
    cout<<"\t    "<<V<<"==="<<ans<<endl; ans=ans/P2;
    cout<<"\t-----  --"<<endl;
    cout<<"\t "<<P<<"     "<<P<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 2:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p/P; ans=ans+P2;
    cout<<"\t"<<V<<P<<"-"<<P2<<"==="<<p<<endl;
    cout<<"\t-----  --"<<endl;
    cout<<"\t  "<<P<<"     "<<P<<endl;
    cout<<"\t +"<<P2<<"     +"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 1:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p/P; ans=ans-P2;
    cout<<"\t"<<V<<P<<"+"<<P2<<"==="<<p<<endl;
    cout<<"\t-----  --"<<endl;
    cout<<"\t  "<<P<<"     "<<P<<endl;
    cout<<"\t -"<<P2<<"     -"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    }
    break;
    case 2:
    cout<<"\t"<<V<<"-"<<P<<"_"<<2<<"==="<<p<<endl;
    cout<<"\nWhat is equation type 2?\n1) Add\n2) Subtract\n3) Multiply\n4) Divide"<<endl;
    cin>>Pick2;
    switch(Pick2){
    case 4:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P2; ans=ans+P;
    cout<<"\t"<<V<<"-"<<P<<"/"<<P2<<"==="<<p<<endl;
    cout<<"\t +"<<P<<"     +"<<P<<endl;
    cout<<"\t *"<<P2<<"     *"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 3:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=P*P2; ans=P+ans;
    cout<<"\t"<<V<<"-"<<P<<"*"<<P2<<"==="<<p<<endl;
    cout<<"\t +"<<P<<"     +"<<P<<endl;

    cout<<"\t-----  --"<<endl;
    cout<<"\t "<<P2<<"     "<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 2:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p+P; ans=ans+P2;
    cout<<"\t"<<V<<"-"<<P<<"-"<<P2<<"==="<<p<<endl;
    cout<<"\t +"<<P<<"     +"<<P<<endl;
    cout<<"\t +"<<P2<<"     +"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 1:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p+P; ans=ans-P2;
    cout<<"\t"<<V<<"-"<<P<<"+"<<P2<<"==="<<p<<endl;
    cout<<"\t +"<<P<<"     +"<<P<<endl;
    cout<<"\t -"<<P2<<"     -"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    }
    break;
    case 1:
    cout<<"\t"<<V<<"+"<<P<<"_"<<2<<"==="<<p<<endl;
    cout<<"\nWhat is equation type 2?\n1) Add\n2) Subtract\n3) Multiply\n4) Divide"<<endl;
    cin>>Pick2;
    switch(Pick2){
    case 4:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p*P2; ans=ans-P;
    cout<<"\t"<<V<<"+"<<P<<"/"<<P2<<"==="<<p<<endl;
    cout<<"\t -"<<P<<"     -"<<P<<endl;
    cout<<"\t *"<<P2<<"     *"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 3:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p/P2; ans=ans-P;
    cout<<"\t"<<V<<"+"<<P<<"*"<<P2<<"==="<<p<<endl;
    cout<<"\t -"<<P<<"     -"<<P<<endl;

    cout<<"\t-----  --"<<endl;
    cout<<"\t "<<P<<"     "<<P<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 2:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p-P; ans=ans+P2;
    cout<<"\t"<<V<<"+"<<P<<"-"<<P2<<"==="<<p<<endl;
    cout<<"\t -"<<P<<"     -"<<P<<endl;
    cout<<"\t +"<<P2<<"     +"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;
    case 1:
    cout<<"\nThe Equation is:\n"<<endl;
    ans=p-P; ans=ans-P2;
    cout<<"\t"<<V<<"+"<<P<<"+"<<P2<<"==="<<p<<endl;
    cout<<"\t -"<<P<<"     -"<<P<<endl;
    cout<<"\t -"<<P2<<"     -"<<P2<<endl;
    cout<<"\t----------"<<endl;
    cout<<"\t "<<V<<"==="<<ans<<endl;
    break;}break;}}
