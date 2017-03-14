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

// Numerical Differentiation (up to the 3rd derivative)

#include<iostream.h>
#include<conio.h>
#include<math.h>

double f(double x) {
	double fx;
	fx = exp(x);
	return fx;
}

void main () {
clrscr();
double x, df[3], d2f[3], d3f[3], h = 0.01;
cout<<"Numerical differentiation: f(x) = exp(x)\n";
cout<<"Input x: "; cin>>x;

df[0] = (f(x + h) - f(x))/h;
df[1] = (f(x + h) - f(x - h))/(2*h);
df[2] = (f(x) - f(x - h))/h;
cout<<"First derivative: \n";
cout<<"Forward: f'(x) = "<<df[0];
cout<<"\nCentral: f'(x) = "<<df[1];
cout<<"\nBackward: f'(x) = "<<df[2];

d2f[0] = (f(x + 2*h) - 2*f(x + h) + f(x))/pow(h,2);
d2f[1] = (f(x + 2*h) - 2*f(x) + f(x - 2*h))/(4*pow(h,2));
d2f[2] = (f(x) - 2*f(x - h) + f(x - 2*h))/pow(h,2);
cout<<"\nSecond derivative: \n";
cout<<"Forward: f''(x) = "<<d2f[0];
cout<<"\nCentral: f''(x) = "<<d2f[1];
cout<<"\nBackward: f''(x) = "<<d2f[2];

d3f[0] = (f(x + 3*h) - 3*f(x + 2*h) + 3*f(x + h) - f(x))/pow(h,3);
d3f[1] = (f(x + 3*h) - 3*f(x + h) + 3*f(x - h) - f(x - 3*h))/(8*pow(h,3));
d3f[2] = (f(x) - 3*f(x - h) + 3*f(x - 2*h) - f(x - 3*h))/pow(h,3);
cout<<"\nThird derivative: \n";
cout<<"Forward: f'''(x) = "<<d3f[0];
cout<<"\nCentral: f'''(x) = "<<d3f[1];
cout<<"\nBackward: f'''(x) = "<<d3f[2];
getch();
return;


}