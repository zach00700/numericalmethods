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

// Newton's Method

#include<iostream.h>
#include<math.h>
#include<dos.h>
#include<conio.h>

int main()
{ int i;
float xi, xil, fxi, fx2, xitemp, per;
textcolor(BLUE);
clrscr();
cout<<"Enter initial value:\n"
<<"xi:";
cin>>xi;
clrscr();
cout.precision(5);
gotoxy(1,2);cprintf("xi");
gotoxy(12,2);cprintf("xi+1");
gotoxy(22,2);cprintf("percentage");
gotoxy(35,2);cprintf("remarks");
i=3;

do {
fxi = exp(-xi)-xi;
fx2 = -exp(-xi)-1;
xil = xi - (fxi/fx2);
per = ((xil-xi)/xil)*100;

if (per<0) {
per = -(per);}

gotoxy(1,i); cout<<xi;
gotoxy(12,i); cout<<xil;
gotoxy(22,i); cout<<per;
gotoxy(35,i); cout<<"false";
xi=xil;
i=i*2; }

while (per>0.01);
gotoxy(57, i-2); cout<<"true";
getch();
return 0; }
