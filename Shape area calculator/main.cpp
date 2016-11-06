#include<iostream>
#include<iomanip>
#include<math.h>
#include<windows.h>
#include<string>
using namespace std;
///shared stuff
int choice;
const double PI = 3.14;
double area,b,l,h,r,w,s,wh,hl,wl,ls,r1,r2;
///main function
int main()
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
         << "9. Quit"<< endl << endl;
         cin >> choice;
         Sleep(1000);
                    switch (choice)
                    {
                           case 1:
                                    cout << "Enter the radius(half the diameter): ";
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
                                cout << " Please enter the length. " ;
                                cin>>l;
                                cout << " Please enter the width. " ;
                                cin>>w;
                                area =l*w;
                                cout << "The area of the rectangle is " << area << "sq units. \n";
                                system("pause");
                                system("cls");
                                break;
                            case 4:
                                cout << " Please enter the height. " ;
                                cin>>h;
                                cout << " Please enter the base. " ;
                                cin>>b;
                                area=(0.5*b)*h;
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
                                cout << " Please enter the width. " ;
                                cin>>w;
                                cout << " Please enter the length. " ;
                                cin>>l;
                                cout << " Please enter the height. " ;
                                cin>>h;
                                area=(w*l)+(w*h)+(h*l);
                                cout << "The area of the Rectangular solid is " << area << "sq units. \n";
                                system("pause");
                                system("cls");
                            break;
                            case 7:
                                cout << " Please enter the height. " ;
                                cin>>h;
                                cout << " Please enter the length. " ;
                                cin>>l;
                                cout << " Please enter the width. " ;
                                cin>>w;
                                cout << " Please enter the length of the diagonal side. " ;
                                cin>>s;
                                area=(w*h)+(h*l)+(w*l)+(l*s);
                                cout << "The area of the Triangular prism is " << area << "sq units. \n";
                                system("pause");
                                system("cls");
                                break;
                            case 8:
                                cout << "Enter the radius(half the diameter): ";
                                cin >> r;
                                area = (PI*4)*pow(r,2);
                                cout << "The area of the Sphere is " << area << "sq units. \n";
                                system("pause");
                                system("cls");
                                break;
                            case 9:
                                return 0;
                                break;
                           default:
                                cout<<"Repeat that please: ";
                                cin>>choice;
                                break;
}}while (choice !=9);
return 0;}
