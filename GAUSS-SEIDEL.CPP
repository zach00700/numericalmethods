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

// Gauss-Seidel Method

#include<iostream.h>
#include<conio.h>
#include<math.h>
#define size 20

void main() {
double array[size][size], b[size], x[size], m, sum = 0;
double error[size];
int max, row, col, i, j;

clrscr();


cout<<"Enter no. of equations: ";
cin>>max;
cout<<"Enter values row-wise: \n";

for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		cin>>array[row][col];
	}
	cin>>b[row];
}
clrscr();

for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		gotoxy(col * 10 + 1, row + 1);
		cout<<array[row][col];
	}

	gotoxy(col * 10 + 1, row + 1);
	cout<<b[row];
}

cout.precision(4);

do {
	for(row = 0; row < max; row++) {
		for(col = 0; col < max; col++){
		sum = sum + array[row][col] * x[col];
		}
		x[row] = ((b[row] - sum)/array[row][row]) + x[row] ;
		sum = 0;
	}
	cout<<"\n";
	for(j = 0; j < max; j++) {
		cout<<"\nx"<<j + 1<<" = "<<x[j];
	}
	error[0] = (1 - (x[0]/3)) * 100;
	error[1] = (1 - (x[1]/-2.5)) * 100;
	error[2] = (1 - (x[2]/7)) * 100;
	for(row = 0; row < max; row++) {
		cout<<"\nerror of x"<<row + 1<<" = "<<error[row];
	}
} while(error[0] > 0.001 || error[1] > 0.001 || error[2] > 0.001);



getch();
return;
}
