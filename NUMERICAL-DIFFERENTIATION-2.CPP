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

// Numerical Differentiation (up to n derivatives, theoretically)

#include<iostream.h>
#include<conio.h>
#include<math.h>

int fact(int n) {
if (n == 0 || n == 1) {
	return 1;
}
return n*fact(n - 1);
}

int C(int a, int b) {
int combi;
combi = fact(a)/(fact(a - b)*fact(b));
return combi;
}

double f(double x) { // Define function here
	double fx;
	fx = exp(x);
	return fx;
}

void main() {
clrscr();
int sw, ord, i;
double der = 0, sum = 0, x = 0, h = 0.01;
cout<<"Numerical differentiation: f(x) = exp(x)\n";
cout<<"Enter order of derivative: "; cin>>ord;
cout<<"1: Forward\n";
cout<<"2: Central\n";
cout<<"3: Backward\n";
cout<<"Choose approximation type: \n"; cin>>sw;

cout<<"Input x: "; cin>>x;
if (sw == 1) { // Forward difference
	for(i = 0; i <= ord; i++) {
		sum = sum + pow(-1, i)*C(ord,i)*f(x + (ord - i)*h);
	}
	der = sum / pow(h,ord);
}
else if (sw == 2) { // Central difference
	for(i = 0; i <= ord; i++) {
		sum = sum + pow(-1, i)*C(ord,i)*f(x + (ord - 2*i)*h);
	}
	der = sum / pow(2*h,ord);
}
else if (sw == 3) { // Backward difference
	for(i = 0; i <= ord; i++) {
		sum = sum + pow(-1, i)*C(ord,i)*f(x - i*h);

	}
	der = sum / pow(h,ord);

}
else {
	cout<<"Invalid input. Now exiting.";
	getch();
	return;
}

cout<<"D"<<ord<<"x = "<<der;
getch();
return;
}