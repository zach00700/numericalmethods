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

// Matrix Inverse

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>
// predefined array size
#define size 20

void main() {

// initializing variables
double u[size][size], l[size][size], b[size], d[size], inv[size][size], m, sum = 0;
int max, row, col, i, j;

// clean up any messes first
clrscr();
for (row = 0; row < max; i++) {
	b[row] = 0;
	d[row] = 0;
	for(col = 0; col < max; col++) {
		u[row][col] = 0;
		l[row][col] = 0;
		inv[row][col] = 0;
	}
}
// give me the details and I'll work them out for you
cout<<"Matrix Inverse Calculator\nEnter no. of equations: ";
cin>>max;
cout<<"Enter values row-wise: \n";
// enter values row by row
for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		cin>>u[row][col];
	}
}
clrscr();

// display the input variables
for(row = 0; row < max; row++) {
	for(col = 0; col < max; col++) {
		gotoxy(col * 6 + 1, row + 1); // added 1 to correct display error
		cout<<u[row][col];
	}
}

// make sure input is not zero
if(max == 0) {
	cout<<"Invalid input. Press any key to exit.";
	getch();
	return;
}
// set precision to 4 decimal places
;

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
		for(col = i + 1; col < max; col++) {
			u[row][col] = u[row][col] - m*u[i][col];
		}
		// no to floating point errors!
		u[row][i] = 0;
	}
}

// then print out final matrices
gotoxy(1, (max + 1) * (1) + 1);
cout<<"Upper Triangular Matrix:";
for(row = 0; row < max; row++) {
	cout<<"\n";
	for(col = 0; col < max; col++) {
		cout<<u[row][col];
		cout<<setw(10);
	}
}
cout<<"\nLower Triangular Matrix:";
for(row = 0; row < max; row++) {
	cout<<"\n";
	for(col = 0; col < max; col++) {
		cout<<l[row][col];
		cout<<setw(10);
	}
}

for(int index = 0; index < max; index ++) {
	// set {b} to an appropriate value
	for(i = 0; i < max; i++) {
		b[i] = 0;
	}
	b[index] = 1;

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
	for(i = max - 1; i >= 0; i--) { // the following instances
		// do you remember your dot product?
		for(j = max - 1; j > i; j--) {
			sum = sum + inv[j][index]*u[i][j];
		}

		inv[i][index] = (d[i] - sum)/u[i][i];
		// clean up "sum" variable before re-entering loop
		sum = 0;
	}
}

// displaying solutions
cout<<"\n\nInverse Matrix:";
for(row = 0; row < max; row++) {
	cout<<"\n";
	for(col = 0; col < max; col++) {
		cout<<inv[row][col];
		cout<<setw(14);
	}
}
// mission accomplished
getch();
return;
}
