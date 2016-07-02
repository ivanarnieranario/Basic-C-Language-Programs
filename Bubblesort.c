#include<stdio.h>
#include<conio.h>
void Bubblesort(int length);
int arr[99]={5,4,3,6,0,1,7,1,2,9};

int main(){
int length=10;
int x;
length--;
printf("Sorting Algorithm\n[BUBBLE SORT]");

printf("\n\nOriginal: \n");
for (x=0;x<=length;x++){
printf("%d",arr[x]);
}

Bubblesort(length);

printf("\n\nBubble Sort: \n");
for ( x=0;x<=length;x++){
printf("%d",arr[x]);
}
}//end of main

void Bubblesort(int length){
int temp;
int x;

while (1){
if (length<1){
break;
}
for ( x=0;x<length;x++){
if (arr[x]>arr[x+1]){
temp=arr[x];
arr[x]=arr[x+1];
arr[x+1]=temp;
}
}
length--;
}
}//end of bubblesort
