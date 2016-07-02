#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define base 2

int main(){
char binary[99];
printf("Binary to Decimal\n");
printf("\nEnter a binary digit:\n");
gets(binary);


int length=strlen(binary);
int data[99];
int decimal=0;
int exp=0;
int temp=0;
int x; //I always use x for index of an array

for (x=length-1;x>=0;x--){
    if (binary[x]=='1'){
       temp = pow(base,exp++);
        data[exp-1]=temp;
       decimal+=temp;
    } else if (binary[x]=='0'){
data[exp]=temp =pow(base,exp);
exp++;
continue;
    } else {
     printf("-Invalid Keyword!");
     return;
    }
}//end of for loop

printf("Binaries:\n");
for (x=0;x<length;x++){
printf("%c ",binary[x]);
}//print the inputted binaries

printf("\n\nComputation:\n");//new line
int index=0;
for (x=length-1;x>=0;x--){
printf("%d",data[x]);
if (binary[index]=='1'){
printf("+ "); index++;
} else {
printf(" "); index++;
}
}

index=0;
printf("\n\n");
for (x=length-1;x>=0;x--){
if (binary[index]=='1'){
printf("%d\n",data[x]); index++;
} else {
index++;
}
}

int underScore;
underScore = floor(log10(abs(decimal))) + 1;
for (x=0;x<underScore;x++){
printf("_");
}
printf("\n%d (decimal)",decimal);
}//end of main