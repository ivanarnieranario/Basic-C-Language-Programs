#include<stdio.h>
#include<conio.h>
#include<math.h>
#define base 2

int main(){

	int input,temp,bin;
    int arr[99];
    int top=-1;
    int data;
    int x;//for index of an array
	printf("Enter a Number : ");
	scanf("%d",&input);

    if (input>0){
temp=input;
printf("\n");
while (temp>0){
		bin=temp%2;
		temp=temp/2;
        arr[++top]=bin;
	}
    }else {
 printf("-Invalid Keyword!");
 return 0;
    }
 
printf("\nComputation:\n");
for (x=top;x>=0;x--){
data=pow(base,x);
if (arr[x]==1){
printf("%d+ ",data);
} else {
printf("%d ",data);
}
}

printf("\n\nBinaries:\n");
for (x=top;x>=0;x--){
printf("%d ",arr[x]);
}

return 0;
}//end of main