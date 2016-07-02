#include<stdio.h>
#include<conio.h>
#define p printf
#define s scanf
int Last(int x[10],int y[10],int pts);
int Distance(int x[4], int y[4],int pts);
main()
{
	int x[4];
	int y[4];
	int pts;
	int a,b1=1,b2=2;
	p("\n How many Points do you have ?\n :");
	s("%d",&pts);
	if(pts<2){
	   p("\nYou need atleast 2 Points to find the Distance ");
	   return 0;
	}
	
	for (a=1;a<=pts;a++){
	p("Point %d (x,y) : \n",a);
	s("%d %d",&x[a],&y[a]);
	}
	
	Distance(x,y,pts);
	if(pts>1){
		p("\nPoint %d(%d,%d) to Point 1(%d,%d) \nDistance: %d\n",pts,x[pts],y[pts],x[1],y[2],Last(x,y,pts));
	}
	
}
int Distance(int x[4], int y[4],int pts)
{
	int distance;
	int a=1,b=2;
	p("\nThe Distance between");
	while(b<=pts){
	distance = ((x[a] - x[b]) * (x[a]- x[b])) + ((y[a] - y[b]) * (y[a]- y[b]));
	
	p("\nPoint %d(%d,%d) to Point %d(%d,%d) \nDistance: %d\n",a,x[a],y[a],b,x[b],y[b],distance);
	a++,b++;
		}
		
}

int Last(int x[10],int y[10],int pts){
	int distance;
			distance = ((x[pts] - x[1]) * (x[pts]- x[1])) + ((y[pts] - y[1]) * (y[pts]- y[1]));
		return distance;
	
}