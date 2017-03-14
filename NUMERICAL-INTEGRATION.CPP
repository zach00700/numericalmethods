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

// Numerical Integration (using trapezoidal and Simpson's methods)

#include<iostream.h>
#include<conio.h>
#include<math.h>

double f(double x) { // define function
double fx;
fx = 0.2 + 25*x - 200*pow(x,2) + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5);
return fx;
}

double err(double x) {
double error;
error = fabs(1 - 1875*x / 3076);
error = error * 100;
return error;
}

void main() {
double a, b, temp;
double fa, fb, range, trap, simp13, simp38;
int n, div;
double tmult, interval, s13ma;
clrscr();
cout<<"Numerical Integration for function \n";
cout<<"f(x) = 0.2 + 25*x - 200*x^2 + 675*x^3 -900*x^4 + 200*x^5 \n";
cout<<"Enter lower limit: "; cin>>a;
cout<<"Enter upper limit: "; cin>>b;
if (b < a) {
	cout<<"Upper limit is lower than lower limit. Switching values.";
	temp = b;
	b = a;
	a = temp;
}
range = b - a;
fa = f(a);
fb = f(b);
trap = range * (fa + fb) / 2;
simp13 = range * (fa + 4*f(a + range/2) + fb)/6;
simp38 = range * (fa + 3*f(a + range/3) + 3*f(a + 2*range/3) + fb)/8;
cout<<"Trapezoidal approximation: I(f(x)) = "<<trap;
cout<<"\n% error = "<<err(trap)<<"%";
cout<<"\nSimpson's 1/3 rule: I(f(x)) = "<<simp13;
cout<<"\n% error = "<<err(simp13)<<"%";
cout<<"\nSimpson's 3/8 rule: I(f(x)) = "<<simp38;
cout<<"\n% error = "<<err(simp38)<<"%" ;
cout<<"\nEnter number of divisions (2-100):  "; cin>>n;

double sum = 0;
double sum2 = 0;
interval = range/n;
for (int i = 1; i < n; i++) {
	sum = sum + f(i*interval);
}
tmult = range * (fa + 2*sum + fb) / (2*n);
cout<<"MA trapezoidal approximation: I(f(x)) = "<<tmult;
cout<<"\n% error = "<<err(tmult)<<"%" ;
if (div % 2 == 0) {
	sum = 0;
	for(i = 1; i < n; i += 2) {
		sum += f(a + interval*(i));
	}
	for(i = 2; i < n - 1; i += 2) {
		sum2 += f(a + interval*(i));
	}
	s13ma = range * (fa + 4*sum + 2*sum2 + fb)/(3*n);
	cout<<"\nMA Simpson's 1/3 approximation: I(f(x)) = "<<s13ma;
	cout<<"\n% error = "<<err(s13ma)<<"%" ;
}
getch();
return;
}