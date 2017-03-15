/* 
-- Start of note-- 
DO NOT REMOVE THIS NOTE.
Original code provided by Zach Joseph R. Espiritu in fulfillment of the requirements 
for the subject Numerical Methods for Academic Year 2016-2017.
Based on Numerical Methods by Chapra & Canale.

Feel free to use this code for research purposes. You may modify it, play with it, or 
improve it (in which case I would encourage you to send me your improvement to the 
code at zach (underscore) espiritu (at) yahoo (dot) com). 
However, YOU MAY NOT SUBMIT THIS AS YOUR OWN CODE.

Disclaimer:  The author of the code, Zach Joseph R. Espiritu, shall not be held 
responsible for any consequence arising from the use or misuse of this code. 
If you encounter bugs or incompatibility issues email me at 
zach (underscore) espiritu (at) yahoo (dot) com.
-- End of note --
*/

// Regula Falsi (aka False Position) Method

#include<iostream.h>
#include<iomanip.h>
#include<math.h>
#include<conio.h>
#define tol 0.00001

double x0, x1, x2, a, b;
int i;

double f(double x)
{	double fx;
	fx=3*x+sin(x)-exp(x);
	return(fx);
}

void main()
{	clrscr();
	cout<<"Please enter initial values:\n"
	<<"x0:";
	cin>>x0;
	cout<<"x1:";
	cin>>x1;
	cout<<"\n--------------------------\n\n|";
a=x0;
b=x1;
i=0;
	cout<<setw(4)<<"i"
	    <<setw(16)<<"x0"
	    <<setw(16)<<"x1"
	    <<setw(16)<<"x2"
	    <<setw(16)<<"abs(x0-x1)\n";

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(6);
	while((fabs(x0-x1))>(2*tol))
	{
	i++;
	x2=x1-((f(x1)*(x0-x1)/(f(x0)-f(x1))));
	cout<<setw(4)<<i
	    <<setw(16)<<x0
	    <<setw(16)<<x1
	    <<setw(16)<<x2
	    <<setw(16)<<fabs(x0-x1)
	    <<"\n";
	if ((f(x2)*f(x0))<0)
		x1=x2;
	else
		x0=x2;
	}
	cout<<"\n----------------------\n";
	if (fabs(f(x2))<(2*tol))
		cout<<"\nThe root of f(x) found after"
		    <<i<<"iterations is"
		    <<x2<<"\n";
	else
		cout<<"\nThere is no root between the points"
		    <<a<<" and "<<b<<"\n";
		cout<<"\nPress any key.";
		getch();
		}
