#include<stdio.h>
#include<conio.h>
#include<string.h>
void PushPrefix(char x);
void PushStacks(char x,int rank);
void OutputProcess();
void Display();

//Global Variables
char infix[50];
char stacks[10];
char prefix[50];
int topStacks=-1;
int topPrefix=-1;
int temp=0;

//Main Function
int main(){
printf("\nInfix: ");
gets(infix);

int length=strlen(infix)-1;
for (int x=length;x>=0;x--){
switch (infix[x]){
case '*' :
PushStacks(infix[x],4); break;
case '/' :
PushStacks(infix[x],3); break;
case '+' :
PushStacks(infix[x],2); break;
case '-' :
PushStacks(infix[x],1); break;
default :
PushPrefix(infix[x]);
break;
}
}
OutputProcess();
Display();
}//end of main

void PushPrefix(char x){
prefix[++topPrefix]=x;
}//end of PushPrefix

void PushStacks(char x,int rank){
if (rank>=temp){
stacks[++topStacks]=x;
} else {
PushPrefix(stacks[topStacks]);
topStacks--;
stacks[++topStacks]=x;
}
temp=rank;
}//end of PushStacks

void OutputProcess(){
for (int x=topStacks;x>=0;x--){
PushPrefix(stacks[x]);
}
}//end of Output Process

void Display(){
printf("\nPrefix: ");
for (int x=topPrefix;x>=0;x--){
printf("%c",prefix[x]);
}
}//end of display