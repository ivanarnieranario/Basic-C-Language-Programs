#include<stdio.h>
#include<conio.h>
float CalculateArea(float p ,float r);

main(){
	float pi=3.1416;
	float raduis;
	printf("\n Enter a Raduis : ");
	scanf("%f",&raduis);
	printf("\n Area : %0.2f " ,CalculateArea(pi,raduis));
	
}

float CalculateArea(float p , float r){
	float area;
	area=p*r*r;
	return area;
}