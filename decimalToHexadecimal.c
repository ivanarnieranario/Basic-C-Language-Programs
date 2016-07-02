#include<stdio.h>
#include<conio.h>
#define divisor 16

char hexa[99];//array
int top=-1; //pointer in stacks

//Stacks
void Push(char x){
switch (x){
case 10 : hexa[++top]='A'; break;
case 11 : hexa[++top]='B'; break;
case 12 : hexa[++top]='C'; break;
case 13 : hexa[++top]='D'; break;
case 14 : hexa[++top]='E'; break;
case 15 : hexa[++top]='F'; break;
default :
   hexa[++top]=x + '0'; break;
}//end of switch
}//end of push

int main(){
int decimal;
int rem=0;// remainder
int x;//index (counter)
int quotient;
int temp;

printf("Enter a Decimal: ");
scanf("%d",&decimal);

if (decimal>0){
printf("\nComputation:");
quotient=decimal;
while (quotient!=0){
temp=quotient;
quotient/=divisor;
rem=temp-(quotient*divisor);
printf("\n%d/16 = Quotient %d,Remainder %d",temp,quotient,rem);
Push(rem);
}//end of while

printf("\n\nHexadecimal: ");
for (x=top;x>=0;x--){
printf("%c",hexa[x]);
}
} else {
printf("-Invalid Keyword!");
return 0;
}
}//end of main