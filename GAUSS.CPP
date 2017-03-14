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

// Gaussian Method

#include<iostream.h>
#include<conio.h>
#include<math.h>
// predefined array size
#define size 20

// le program
void main() {

// initializing variables
double array[size][size + 1], x[size], m, sum = 0;
int max, row, col, i, j;

// clean up any messes first
clrscr();

// give me the details and I'll work them out for you
cout<<"Enter no. of equations: ";
cin>>max;
cout<<"Enter values row-wise: \n";
// enter values row by row
for(row = 0; row < max; row++) {
	for(col = 0; col <= max; col++) {
		cin>>array[row][col];
	}
}
clrscr();

// display the input variables
for(row = 0; row < max; row++) {
	for(col = 0; col < max + 1; col++) {
		gotoxy(col * 6 + 1, row + 1); // added 1 to correct display error
		cout<<array[row][col];
	}
}

// set precision to 4 decimal places
cout.precision(4);

// transform lower triangle to 0
for(i = 0; i < max - 1; i++) { // i = pivot index
	// zero out elements below the pivot element
	for(row = i + 1; row < max; row++) {
		// if pivot element = 0 exit gracefully
		if(array[i][i] == 0) {
			cout<<"\nInvalid matrix. Pivot element is zero. \t";
			cout<<"Press any key to exit.";
			getch();
			return;
		}
		// or else compute multiplying factor
		m = array[row][i]/array[i][i];
		// do the math
		for(col = 0; col <= max; col++) {
			array[row][col] = array[row][col] - m*array[i][col];
		}
	}
	// then print out results
	for(row = 0; row < max; row++) {
		for(col = 0; col < max + 1; col++) {
			gotoxy(col * 8 + 1, row + (max + 1) * (i + 1) + 1); // added 1 to correct display error
			cout<<array[row][col];
		}
	}
}

// back substitution
x[max - 1] = array[i][i + 1]/array[i][i]; // for first instance
for(i = max - 2; i >= 0; i--) { // the following instances
	// do you remember your dot product?
	for(j = max - 1; j > i; j--) {
		sum = sum + x[j]*array[i][j];
	}

	x[i] = (array[i][max] - sum)/array[i][i];
	// clean up "sum" variable before re-entering loop
	sum = 0;
}

// displaying solutions
for(i = 0; i < max; i++) {
	//	gotoxy(1, row + (max + 1) * (max) + i + 1);

	cout<<"\nx"<<(i + 1)<<" = "<<x[i];
}

// mission accomplished

getch();
return;
}
