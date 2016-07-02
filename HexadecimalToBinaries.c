#include<stdio.h>
#include<conio.h>
#include<string.h>

void Push(char join[4]);//to push the converted hexa to binaries and join them
void hexaToBin(char hexa[50]);

//Global Variables
char binaries[999];//where we store the converted hexa to bin

int main(){
char hexa[50];

puts("Enter a Hexadecimal: ");
gets(hexa);
hexaToBin(hexa);
printf("\n\nBinaries:\n");
puts(binaries);
}//end of main

//Stacks Concept
void Push(char join[4]){
strcat(binaries,join);
}//end of push


void hexaToBin(char hexa[50]){
   int length;
length=strlen(hexa);
int x;
  for (x=0;x<length;x++){
      switch (hexa[x]){
      case '0' : Push("0000"); break;
      case '1' : Push("0001"); break;
      case '2' : Push("0010"); break;
      case '3' : Push("0011"); break;
      case '4' : Push("0100"); break;
      case '5' : Push("0101"); break;
      case '6' : Push("0110"); break;
      case '7' : Push("0111"); break;
      case '8' : Push("1000"); break;
      case '9' : Push("1001"); break;
      case 'A' :  case 'a': Push("1010"); break;
      case 'B' :  case 'b': Push("1011"); break;
      case 'C' :  case 'c': Push("1100"); break;
      case 'D' :  case 'd': Push("1101"); break;
      case 'E' :  case 'e': Push("1110"); break;
      case 'F' :  case 'f': Push("1111"); break;
default:
  printf("\n-Invalid Keyword!");
  exit(0);
      }
  }
}