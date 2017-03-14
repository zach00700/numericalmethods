/* 
-- Start of note-- 
DO NOT REMOVE THIS NOTE.
Original code provided by Zach Joseph R. Espiritu in fulfillment of the requirements 
for the subject Numerical Methods for Academic Year 2016-2017.
Based on Numerical Methods by Chapra & Canale.

Feel free to use this code for research purposes. You may modify it, play with it, or improve it (in which case I would encourage you to send me your improvement to the code at zach (underscore) espiritu (at) yahoo (dot) com). However, YOU MAY NOT SUBMIT THIS AS YOUR OWN CODE. 

Disclaimer:  The author of the code, Zach Joseph R. Espiritu, shall not be held 
responsible for any consequence arising from the use or misuse of this code. 
If you encounter bugs or incompatibility issues email me at 
zach (underscore) espiritu (at) yahoo (dot) com.
-- End of note --
*/

// Secant Method

#include<iostream.h>
#include<math.h>
#include<iomanip.h>
#include<conio.h>

double f(double x)
{
double fx;
fx = exp(-x)-x;
return fx;
}

void main()
{
clrscr();
int i = 0;
double x0, xi, x2, per;
const double tol = 0.01;
cout<<"f(x) = exp(-x) - x = 0\n\n";
cout<<"Enter xi-1: ";
cin>>x0;
cout<<"Enter   xi: ";
cin>>xi;

gotoxy(1,7); cprintf("xi-1");
gotoxy(9,7); cprintf("xi");
gotoxy(20,7); cprintf("xi+1");
gotoxy(30,7); cprintf("Error");
gotoxy(45,7); cprintf("Remarks");
cout.precision(5);

do {
x2 = xi - (f(xi) * (xi-x0) / (f(xi)-f(x0)));
per = fabs (x2-xi) / x2;

gotoxy(1,i + 8); cout<<x0;
gotoxy(9,i + 8); cout<<xi;
gotoxy(20,i + 8); cout<<x2;
gotoxy(30,i + 8); cout<<per*100<<"x";

if (per < tol) {
gotoxy(45,i + 8); cout<<"True"; }
else {
gotoxy(45,i + 8); cout<<"False"; };
x0=xi;
xi=x2;
i++; }
while (per > tol);
gotoxy(10,i + 10); cout<<"\nThe value of x after "<<i<<" iterations is "<<xi;
getch();
return;
}