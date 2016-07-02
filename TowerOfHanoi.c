//Header
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//Functions
void displayStack();
void pushStack(int des);
void popStack(int src);
void defaultStack();
void playerInput();
void inputProcess(char src,char des);
void playerMoves();

//Global Variables
//Pointers for A,B and C
int topA=0,topB=0,topC=0;
int A[10]; //Stack for A
int B[10]; //Stack for B
int C[10]; //Stack for C
int moves=0; //No. of Moves
int recent=0; //Recent Value
int name[5]; //Name to save the scores in the Scores.txt

//Files
FILE *fRead;
FILE *fAdd;

int main(){
printf("       Tower of Hanoi\n\nEnter your name\n: ");
gets(name);
system("cls");

defaultStack(); //default value
while (1){ //continues
// if C : 5 4 3 2 1
if (C[0]==5){
  if (C[1]==4){
    if (C[2]==3){
       if (C[3]==2){
         if (C[4]==1){
//Then Win the Game and Print the No. of Moves
system("cls"); //clearscreen
printf("\n Binggo! You got it! \n\n\n Your moves: %d",moves);
playerMoves();
return 0;
         }
       }
    }
  }
}
displayStack(); // Display all Stack
//Print the No. of Moves
printf("\n\n No. of Moves: %d",moves);
playerInput(); //Call this function
}
return 0;
} // main end

//Stacks Concept------------------

//pushStack or Inserting Element
void pushStack(int des){
//A[++topA]=recent;
//means that the pointers topA may increase 1 value then pass the value of recent to A[++topA]
if (des==1){
A[++topA]=recent;
} else if (des==2){
B[++topB]=recent;
} else if (des==3){
C[++topC]=recent;
}
moves++; //increase the moves
} //end pushStack

//popStack // Remove Element
void popStack(int src){
if (src==1){
recent=A[topA];
//get the recent value
 A[topA--]; //remove the element
} else if (src==2){
recent=B[topB];
 B[topB--];
}else if(src==3) {
recent=C[topC];
 C[topC--];
}
} // end popStack

//Default Value
// Insert 5 4 3 2 1 in to A
void defaultStack(){
printf("\n Tower of Hanoi");//title
topA=-1;
topB=-1;
topC=-1;
// I dont use for loop for this because I got a problems when doing for loop for default value
A[++topA]=5;
A[++topA]=4;
A[++topA]=3;
A[++topA]=2;
A[++topA]=1;
} // end Default Value

// Game Concept-------------------

// Player Input
void playerInput(){
char src,des; //Source,Destination
int fir,sec; //First,Second
//Input A,B or C in src
printf("\n\n Source: ");
src=getche(); //get the value

//Source
switch (src){
//pass the Source value into First
case  'A' : case 'a' :
fir=A[topA]; break;
case  'B' : case 'b' :
fir=B[topB]; break;
case  'C' : case 'c' :
fir=C[topC]; break;
}// end Switch Case for Source

//Input A,B or C in des
printf("\n Destination: ");
des=getche(); //get the value
switch (des){
//pass the Destination into Second
case  'A' : case 'a' :
sec=A[topA]; break;
case  'B' : case 'b' :
sec=B[topB]; break;
case  'C' : case 'c' :
sec=C[topC]; break;
}//end Switch Case for Destination

if (fir!=0){ //if First not equal to 0
   if (sec!=0){ //if second not == 0
      if (fir>sec){ //if First > Second
system("cls"); //Clear Screen
//Invalid Moves
printf("\n Invalid Moves");
return;
      }
   }
}
//pass the value of source and destination into 2 arguments in inputProcess
inputProcess(src,des);
} //end playerInput

// Process the Input of the Player
void inputProcess(char src,char des){
int d=0; //stands for destination
int s=0;//stands for source
int valid=0; //check if the input is valid
system("cls");

//for Destination
switch (des){
//when the input is valid
//d=1 if A ,d=2 if B and d=3 if C
case 'A' : case 'a' :
valid=1; d=1; break;
case 'B' : case 'b' :
valid=1; d=2; break;
case 'C' : case 'c' :
valid=1; d=3; break;
}//end Switch Case for Destination

//for Source
switch (src) {
case 'A': case 'a':
if (topA<0){ //check Empty Stack
   printf("\n A is Empty");
return;
} else if (src!=des){
//check if the source input is equal to destination input
if (valid!=0){ //check if the input is valid
popStack(1); //pass the 1 if A
pushStack(d); // pass the d value
}
}
break; //break the case

case 'B': case 'b':
if (topB<0){
   printf("\n B is Empty");
return;
} else if (src!=des){
if (valid!=0){
popStack(2); //pass the 2 if B
pushStack(d); //pass the d
}
}
break;

case 'C': case 'c':
if (topC<0){
   printf("\n C is Empty");
return;
} else if (src!=des){
if (valid!=0){
popStack(3);  //pass the 3 if C
pushStack(d);
}
}
break;
}
} //end inputProcess

// Display
void displayStack(){
    int x;
//print the Stacks starting in recent number until 0 . the counter may be decrease
//for A
printf("\n\n A: ");
for ( x=0;x<=topA;x++){
    printf("%d ",A[x]);
}
//for B
printf("\n B: ");
for (x=0;x<=topB;x++){
    printf("%d ",B[x]);
}
//for C
printf("\n C: ");
for ( x=0;x<=topC;x++){
    printf("%d ",C[x]);
}
}// Display end


//OPTIONAL
//Save Player Scores
void playerMoves(){
fAdd=fopen("PlayerMoves.txt","a");
fprintf(fAdd,"Name: %s\nMoves: %d \n\n",name,moves);
fclose(fAdd);
} //end playerRecords--------------
