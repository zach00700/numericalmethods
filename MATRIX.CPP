#include<iostream.h>
#include<conio.h>
int main()
{int a[3][3],b[3][3],c[3][3];
int x,y,row=0,col=0;
clrscr();
cout<<"enter matrix A value\n";
x=5;
y=2;
for(row=0;row<3;row++)
{for (col=0;col<3;col++)
 { gotoxy(x,y);
 cin>>a[row][col];
 x=x+5;
}y=y+2;
x=5;
cout<<"\n";
}
cout<<"enter matrix B value\n";
x=5;
y=10;
for(row=0;row<3;row++)
{for (col=0;col<3;col++)
 { gotoxy(x,y);
 cin>>b[row][col];
 x=x+5;
}y=y+2;
x=5;
cout<<"\n";
}
cout<<"Sum of matrix A and B is\n";
x=5;
y=18;
for(row=0;row<3;row++)
{for (col=0;col<3;col++)
 {c[row][col]=a[row][col]+b[row][col];
 gotoxy(x,y);
 cout<<c[row][col];
 x=x+5;
}
y=y+2;
x=5;
cout<<"\n";
}
getch();
return 0;
}
