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

// LU Factorization
#include<iostream.h>
#include<conio.h>
#include<math.h>
// predefined array size
#define size 20

// le program
void main() {

// initializing variables
double u[size][size], l[size][size], b[size], d[size], x[size], m, sum = 0;
int max, row, col, i, j;

// clean up any messes first
clrscr();

// give me the details and I'll work them out for you
cout<<"Enter no. of equations: ";
cin>>max;
cout<<"Enter values row-wise: \n";
// enter values row by row
for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		cin>>u[row][col];
	}
	cin>>b[row];
}
clrscr();

// display the input variables
for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		gotoxy(col * 6 + 1, row + 1); // added 1 to correct display error
		cout<<u[row][col];
	}
	col++;
	gotoxy(col * 6 + 1, row + 1);
	cout<<b[row];
}

// set precision to 4 decimal places
cout.precision(4);

// compute L and U matrices
for(i = 0; i < max; i++) { l[i][i] = 1; }
for(i = 0; i < max - 1; i++) { // i = pivot index
	// zero out elements below the pivot element
	for(row = i + 1; row < max; row++) {
		// if pivot element = 0 exit gracefully
		if(u[i][i] == 0) {
			cout<<"\nInvalid matrix. Pivot element is zero. \t";
			cout<<"Press any key to exit.";
			getch();
			return;
		}
		// or else compute multiplying factor
		m = u[row][i]/u[i][i];
		// meanwhile, stash multiplying factors into the 'l' matrix
		l[row][i] = m;
		// do the math
		for(col = 0; col < max; col++) {
			u[row][col] = u[row][col] - m*u[i][col];
		}
	}
}

// then print out final matrices
gotoxy(1, (max + 1) * (1) + 1);
cout<<"Upper Triangular Matrix:";
for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		gotoxy(col * 8 + 1, row + (max + 1) + 2); // added 1 to correct display error
		cout<<u[row][col];
	}
}
cout<<"\n\nLower Triangular Matrix:";
for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		gotoxy(col * 8 + 1, row + (max + 2) * 2 + 1); // added 1 to correct display error
		cout<<l[row][col];
	}
}

// [L] {d} = {b}; now find {d}
d[0] = b[0]/l[0][0]; // for first instance
for(i = 1; i < max; i++) { // the following instances
	// do you remember your dot product?
	for(j = 0; j < i; j++) {
		sum = sum + d[j]*l[i][j];
	}

	d[i] = (b[i] - sum)/l[i][i];
	// clean up "sum" variable before re-entering loop
	sum = 0;
}

// [U] {x} = {d}; now find {x}
x[max - 1] = d[max - 1]/u[max - 1][max - 1]; // for first instance
for(i = max - 2; i >= 0; i--) { // the following instances
	// do you remember your dot product?
	for(j = max - 1; j > i; j--) {
		sum = sum + x[j]*u[i][j];
	}

	x[i] = (d[i] - sum)/u[i][i];
	// clean up "sum" variable before re-entering loop
	sum = 0;
}

// displaying solutions
cout<<"\n";
for(i = 0; i < max; i++) {
	cout<<"\nd"<<i + 1<<" = "<<d[i];
}

cout<<"\n";
for(i = 0; i < max; i++) {
	cout<<"\nx"<<(i + 1)<<" = "<<x[i];
}

// mission accomplished
getch();
return;
}
