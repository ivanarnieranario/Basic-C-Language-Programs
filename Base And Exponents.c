#include<stdio.h>
#include<conio.h>
int CalculatePower(int b , int x);
main(){
	int base,exp;
	printf("\n Enter a base number : ");
	scanf("%d",&base);
	printf("\n Enter a exponent number : ");
	scanf("%d",&exp);
	
	printf("\n Power Value : %d",CalculatePower(base,exp));
	
}

int CalculatePower(int b , int x){
	int pow=1,count;
	
	for (count=1;count<=x;count++){
		pow=pow*b;
	}
	
	return pow;
	
}