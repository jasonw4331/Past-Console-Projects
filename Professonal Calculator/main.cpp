#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <strings.h>
#include <ctgmath>
#include <Quadratic.h>
#include <assert.h>
using namespace std;
    string retry,symbol,word;
	double number1=0,answer=0,number2=0,number3=0,area,b,l,h,r,w,s,wh,hl,wl,ls,r1,r2,a,n,C,L,T,inf1,inf2,bb,tch,tcr,cl,nb,ch;
	double computeInflation(double v1, double v2);
	char End;
	int choice,ac;
    const double PI = 3.14159265;
	void add();
	void subtract();
	void multiply();
	void divide();
	void Answer();
	void exponent();
	void sqrt();
	void cbrt();
	void hypot();
	void roun();
	void absol();
	void Multiply_Add();
	void shapes();
	void quadratic();
	void norm();
	void inflation();
	void Credit();
    bool Repeat = true;///using for repeat

Quadratic::Quadratic() : a(0), b(0), c(0) {}
void Quadratic::set(double cdblA, double cdblB, double cdblC)
{
     a = cdblA;
     b = cdblB;
     c = cdblC;
}
double Quadratic::get_a()const
{
     return a;
}
double Quadratic::get_b()const
{
     return b;
}
double Quadratic::get_c()const
{
     return c;
}
double Quadratic::evaluate(double x)const
{
     return (a * x * x) + (b * x) + c;
}
Quadratic operator+(const Quadratic & q1, const Quadratic & q2)
{
     double a = q1.get_a() + q2.get_a();
     double b = q1.get_b() + q2.get_b();
     double c = q1.get_c() + q2.get_c();
     Quadratic q;
     q.set(a, b, c);
     return q;
}
Quadratic operator*(double r, const Quadratic & q )
{
     double a = r * q.get_a();
     double b = r * q.get_b();
     double c = r * q.get_c();
     Quadratic q1;
     q1.set(a, b, c);
     return q1;
}
int Quadratic::real_root()const
{
     int real_root;
     ///If a, b and c are all zero, then every value of x is a real root.
     if((a == 0 && b == 0) && c == 0)
     {
          real_root = -1;
     }
     ///If a and b are zero and c is non-zero, then there are no real roots.
     else if((a == 0 && b == 0) && c != 0)
     {
          real_root = 0;
     }
     ///If a is zero and b is non-zero, then the only real root is x = -c/b.
     else if(a == 0 && b != 0)
     {
          real_root = 1;
     }
     ///If a is non-zero and b^2 < 4ac, then there are no real roots.
     else if(a != 0 && b*b < (4*a*c))
     {
          real_root = 0;
     }
     ///If a is non-zero and b^2 = 4ac, then there is one real root x = -b/2a.
     else if(a != 0 && b*b == (4*a*c))
     {
          real_root = 1;
     }
     ///If a is non-zero and b2 > 4ac, then there are two real roots.
     else if(a != 0 && b*b > (4*a*c))
     {
          real_root = 2;
     }
     return real_root;
}
double Quadratic::larger_root()const
{
     double larger;
     real_root();
     assert(real_root()>0);
     ///If a is zero and b is non-zero, then the only real root is x = -c/b.
     if(a == 0 && b != 0)
          larger = -c/b;
     else if(a != 0 && b*b == (4*a*c))
          larger = -b/2*a;
     ///If a is non-zero and b2 > 4ac, then there are two real roots.
     else if(a != 0 && b*b > (4*a*c))
          larger = (-b + (sqrt(pow(b,2)-(4*a*c))))/(2*a);
     return larger; }
double Quadratic::smaller_root()const
{   double smaller;
     real_root();
     assert(real_root()>0);
     ///If a is zero and b is non-zero, then the only real root is x = -c/b.
     if(a == 0 && b != 0)
          smaller = -c/b;
     else if(a != 0 && b*b == (4*a*c))
          smaller = -b/2*a;
     ///If a is non-zero and b2 > 4ac, then there are two real roots.
     else if(a != 0 && b*b > (4*a*c))
          smaller = (-b - (sqrt(pow(b,2)-(4*a*c))))/(2*a);
     return smaller; }
void Quadratic::display()const
{      cout << a << " X^2 + "<< b << " X + " <<c; }
int main(void)
{
    do{
	cout << "What type of equation would you like to answer? \n";
	cout << "Please type the type of the equation you would like to complete\n";
	cout << "Your options are:\n Surface, Credit, Inflation, quadratic, Normal, Absolute, or End." << endl;
	cin >> word;

        if(word == "Normal"){
            cout << "You have chosen Normal."<<endl;
            norm();}
        else if(word == "quadratic"){
            system("cls");
			cout << "You have chosen Quadratic Equation" << endl;
			quadratic();}
        else if(word == "Surface"){
            system("cls");
			cout << "You have chosen Surface Area" << endl;
			shapes();}
        else if(word == "Absolute"){
            cout << "You have chosen Absolute Value."<<endl;
            absol();}
        else if(word == "Credit"){
            cout << "You have chosen Credit Limit Calculator."<<endl;
            Credit();}
        else if(word == "Inflation"){
                system("cls");
            cout << "You have chosen Inflation Calculator."<<endl;
            inflation();}
        else if(word == "End"){
            cout << "You have chosen to End."<<endl;
            continue;}
		else{
			cout << "You have not followed my instructions!" << endl;
			Sleep(2000);
			system("cls");}
			}while(word!="End");
			system("pause");
			return 0;
}
void Credit()
{
cout<<"Enter Account Number (or -1 to end)";
cin>>ac;
while (ac!=-1){
cout<<"Enter Beginning Balance: ";
cin>>bb;
cout<<"Enter total charge: ";
cin>>tch;
cout<<"Enter total credits: ";
cin>>tcr;
cout<<"Enter Credit limit: ";
cin>>cl;
nb=(bb+ch)-tcr;
cout<<"New Balance is: "<<nb<<endl;
if (nb>cl){
cout<<"Account: "<<ac<<endl;
cout<<"Credit Limit: "<<cl<<endl;
cout<<"Balance: "<<nb<<endl;
cout<<"Credit limit Exceeded"<<endl;
}
cout<<"End? Y or N?\n> ";
cin>>End;
if(End=='Y'){ac=-1;}
system("cls");
}
}
void norm()
{
    do{
cout << "Please type the type of the equation you would like to complete\n";
	cout << "Your options are:\n\t+,-,/,*,^,C-root, root, Hypot, round, Absolute, Multiply-Add, or Back." << endl;
	cin >> word;
             if (word == "+"){
			cout << "You have chosen Addition" << endl;
			add();}
		else if(word == "-"){
			cout << "You have chosen Subtraction" << endl;
			subtract();}
		else if(word == "/"){
			cout << "You have chosen Division" << endl;
			divide();}
		else if (word == "*"){
			cout << "You have chosen Multiplication" << endl;
			multiply();}
		else if(word == "^"||word == "Power"){
            cout << "You have chosen Exponents"<< endl;
            exponent();}
        else if(word == "root"){
            cout << "You have chosen to root"<<endl;
            sqrt();}
        else if(word == "C-root"){
            cout << "You have chosen to cube root"<<endl;
            cbrt();}
        else if(word == "Hypot"){
            cout << "You have chosen Hypotenuse"<<endl;
            hypot();}
        else if(word == "round"){
            cout << "You have chosen to round"<<endl;
            roun();}
        else if(word == "Multiply-Add"){
            cout << "You have chosen to multiply and add."<<endl;
            Multiply_Add();}
        else if(word == "Back"){
            cout << "You have chosen to go Back."<<endl;
            continue;}
		else{
			cout << "You have not followed my instructions!" << endl;
			Sleep(2000);
			system("cls");}
			}while(word!="Back");
			system("pause");
			system("cls");
}
void inflation()
{
cout << "Welcome to Inflation Calculator 1.0" << endl;
cout << "====================================" << endl;
cout << "Please enter the current price, last years price, and the price two years ago for the item when prompted." << endl;

cout << endl << endl << "Please enter the current price of the item: $";
cin >> C;

cout << endl << endl << "Please enter last years price for the item: $";
cin >> L;

inf1 = computeInflation(C, L);

cout << endl << endl << "Please enter the price two years ago for the item: $";
cin >> T;

inf2 = computeInflation(L, T);

if (inf1 > inf2)
cout << "Inflation is on the rise" << endl;
else if (inf2 > inf1)
cout << "Inflation is on decline" << endl;
else
cout << "There is no inflation" << endl;

system("PAUSE");
}
double computeInflation(double v1, double v2)
{
double inflation = 0;

inflation = (v1 - v2) / v2;

return inflation;
}
void add()
{
    cout << "Please type your 1st number" << endl;
	cin >> number1;
	cout << "Please type your 2nd number" << endl;
	cin  >> number2;
	answer = number1 + number2;
    cout << "The answer is: " << answer << endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void subtract()
{
    cout << "Please type your 1st number" << endl;
	cin >> number1;
	cout << "Please type your 2nd number" << endl;
	cin  >> number2;
	answer = number1 - number2;
    cout << "The answer is: " << answer << endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void multiply()
{
    cout << "Please type your 1st number" << endl;
	cin >> number1;
	cout << "Please type your 2nd number" << endl;
	cin  >> number2;
	answer = number1 * number2;
    cout << "The answer is: " << answer << endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void divide()
{
    cout << "Please type your 1st number" << endl;
	cin >> number1;
	cout << "Please type your 2nd number" << endl;
	cin  >> number2;
    if (symbol == "/" && number2 == 0){
    cout << "This is the only formula that is not yet supported, sorry about that!\n";
    Sleep(2500);
    system("cls");
    main();}
	answer = number1 / number2;
	cout << "The answer is: " << answer << endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void exponent()
{
    cout << "Please type your 1st number" << endl;
	cin >> number1;
	cout << "Please type your Exponent" << endl << endl;
	cin  >> number2;
	answer=pow(number1, number2);
    cout << "The answer is: " << answer << endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void sqrt()
{
	cout << "Please type your Root number" << endl << endl;
	cin  >> number1;
    cout << "The square root of "<<number1<<" is: "<<sqrt(number1)<< endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void cbrt()
{
	cout << "Please type your Root number" << endl << endl;
	cin  >> number1;
    cout << "The Cubic root of "<<number1<<" is: "<<cbrt(number1)<< endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void hypot()
{
    cout << "Please type the First number" << endl << endl;
	cin  >> number1;
	cout << "Please type the Second number" << endl << endl;
	cin >> number2;
    cout << "\nThe Hypotenuse of your triangle is: "<<hypot(number1,number2)<< endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void roun()
{
    cout << "Please type the number that you would like to round." << endl << endl;
	cin  >> number1;
    cout << "\nThe rounded number of your number is: "<<llround(number1)<< endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void absol()
{
    cout << "Please type the number that you would like to find the Absolute Value of." << endl << endl;
	cin  >> number1;
    cout << "\nThe Absolute Value of your number is: "<<fabs(number1)<< endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();
}
void Multiply_Add()
{
    cout << "Please type your 1st number to multiply." << endl;
	cin >> number1;
	cout << "Please type your 2nd Number to multiply." << endl;
	cin  >> number2;
    cout << "Please type your Number to add." << endl;
	cin  >> number3;
	answer=fma(number1, number2,number3);
    cout << "The answer is: " << answer << endl;
    cout << "Thank you for using The professional Calculator, made by jasonwynn10!" << endl;
    Sleep(2500);
    system("cls");
    main();}
void shapes()
{
cout << fixed << showpoint << setprecision(1); //sets to 1 decimal place
do
{
cout << "Welcome to calculating the area of shapes!" << endl << endl;
cout << "Please choose a shape to calculate the area" << endl << endl
         << "1. Circle" << endl
         << "2. Square" << endl
         << "3. Rectangle" << endl
         << "4. Triangle" << endl
         << "5. Cube" << endl
         << "6. Rectangular Solid" << endl
         << "7. Triangular Prism" << endl
         << "8. Sphere" << endl
         << "9. Cone" << endl
         << "10. Pentagon" << endl
         << "11. Hexagon" << endl
         << "12. Heptagon" << endl
         << "13. Octagon" << endl
         << "14. Nonagon" << endl
         << "15. Decagon" << endl
         << "16. Quit"<< endl << endl;
         cin >> choice;
         Sleep(1000);
                    switch (choice)
                    {
                           case 1:
                                    cout << "Enter the radius (half the diameter): ";
                                    cin >> r;
                                    area = pow(r,2)*PI;
                                    cout << "The area of the circle is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                break;
                            case 2:
                                    cout << " Enter the length of one side ";
                                    cin >> b;
                                    area = b*2;
                                    cout << "The area of the square is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;

                            case 3:
                                    cout << " Please enter the length: " ;
                                    cin>>l;
                                    cout << " Please enter the width: " ;
                                    cin>>w;
                                    area =l*w;
                                    cout << "The area of the rectangle is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 4:
                                    cout << " Please enter the height: " ;
                                    cin>>h;
                                    cout << " Please enter the base: " ;
                                    cin>>b;
                                    area=0.5*(b*h);
                                    cout<<"The area of the triangle is "<< area <<"sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 5:
                                    cout << " Enter the length of one side ";
                                    cin >> b;
                                    area = (b*2)*6;
                                    cout << "The area of the cube is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 6:
                                    cout << " Please enter the width: " ;
                                    cin>>w;
                                    cout << " Please enter the length: " ;
                                    cin>>l;
                                    cout << " Please enter the height: " ;
                                    cin>>h;
                                    area=(w*l)+(w*h)+(h*l);
                                    cout << "The area of the Rectangular solid is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                            break;
                            case 7:
                                    cout << " Please enter the height: " ;
                                    cin>>h;
                                    cout << " Please enter the length: " ;
                                    cin>>l;
                                    cout << " Please enter the width: " ;
                                    cin>>w;
                                    cout << " Please enter the length of the diagonal side. " ;
                                    cin>>s;
                                    area=(w*h)+(h*l)+(w*l)+(l*s);
                                    cout << "The area of the Triangular prism is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 8:
                                    cout << "Enter the radius (half the diameter): ";
                                    cin >> r;
                                    cout << " Please enter the height: " ;
                                    cin>>h;
                                    area = (PI*4)*pow(r,2);
                                    cout << "The area of the Sphere is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 9:
                                    cout << "Enter the radius (half the diameter): ";
                                    cin >> r;
                                    cout << " Please enter the height: " ;
                                    cin>>h;
                                    area=PI*r*(r+sqrt(pow(h,2)+pow(r,2)));
                                    cout << "The area of the Cone is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 10:
                                    cout << " Please enter the length of a side. " ;
                                    cin>>s;
                                    cout << " Please enter the length of the apothem. " ;
                                    cin>>a;
                                    area=2.5*s*a;
                                    cout << "The area of the Pentagon is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 11:
                                    cout << " Please enter the length of a side. " ;
                                    cin>>s;
                                    area=(3*sqrt(3)*pow(s,2))/2;
                                    cout << "The area of the Hexagon is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 12:
                                    cout << " Please enter the num of sides: " ;
                                    cin>>n;
                                    cout << " Please enter the length of a side: " ;
                                    cin>>s;
                                    cout << " Please enter the apothem: " ;
                                    cin>>r;
                                    area=0.5*n*s*r;
                                    cout << "The area of the Heptagon is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 13:
                                    cout << " Please enter the num of sides: " ;
                                    cin>>n;
                                    cout << " Please enter the length of a side: " ;
                                    cin>>s;
                                    cout << " Please enter the apothem: " ;
                                    cin>>r;
                                    area=0.5*n*s*r;
                                    cout << "The area of the Octagon is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 14:
                                    cout << " Please enter the num of sides: " ;
                                    cin>>n;
                                    cout << " Please enter the length of a side: " ;
                                    cin>>s;
                                    cout << " Please enter the apothem: " ;
                                    cin>>r;
                                    area=0.5*n*s*r;
                                    cout << "The area of the Nonagon is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 15:
                                    cout << " Please enter the num of sides: " ;
                                    cin>>n;
                                    cout << " Please enter the length of a side: " ;
                                    cin>>s;
                                    cout << " Please enter the apothem: " ;
                                    cin>>r;
                                    area=0.5*n*s*r;
                                    cout << "The area of the Decagon is " << area << "sq units. \n";
                                    system("pause");
                                    system("cls");
                                    break;
                            case 16:
                                    continue;
                                    break;
                           default:
                                    cout<<"Repeat that please: ";
                                    cin>>choice;
                                    break;
}}while (choice !=16);
system("cls");
}
void quadratic()
{
    char symbol;///using for repeat
    int a,b,c,disc;
    float x1,x2;
    while (Repeat){///also for repeat
    system("cls");
    cout << "This program finds the roots of a quadratic equation" << endl;
    cout << "ax^2 +- bx +- c" << endl;
    cout << "Enter values, a,b and c: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    disc = ((b*b) -4*a*c);
    if (disc > 0)
    {cout << "The discriminant is: " << disc << endl;
    x1 = (-b + sqrt( b*b - ( 4*a*c ))) / (2 * a);
    x2 = (-b - sqrt( b*b - ( 4*a*c ))) / (2 * a);
    cout << "X1: " << x1 << endl;
    cout << "X2: " << x2 << endl;
    }
    else if (disc ==0)
    {cout << "The discriminant is: " << disc << endl;
     x1=(-1*b)/(2*a);
     x2=(-1*b)/(2*a);
    }
    else
    {disc =-1*disc;
    cout << "No answer. Discriminant is less than 0"<< endl;
    cout << "Would you like to calculate again (Y or N): ";///Skip
    cin >> symbol;///Skip
    Repeat = (symbol == 'Y' || symbol == 'y') ? true : false;///And again
}}
system("cls");
}
