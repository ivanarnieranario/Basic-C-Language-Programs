#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Declaring Functions
void PlayerX();
void PlayerO();
void PrintBox();
void Pattern();
void Reset();
int PatternCheck(int *patX,int *patO);
char InputProcess(char player,char turn);
char Duplicate(char player,char turn);
// -----------------------------------


// Global Variables
char box[3][3]={"123","456","789"};
int input=1;
char turn;
int dupli[10];
int haveWin=0;
int lifeX=0,lifeO=0;
int rnd=1;

// -----------------------------------


// Main Function -------------------
int main(){
if (rnd==1){
 printf("       TicTacToe\n");
}
if (rnd==5){
printf("      Final Round\n");
}
if (rnd==6){
system("cls");
   if(lifeX>lifeO){
    system("cls");
printf("\n The Winner is Player X\n\n %d out of 5",lifeX);
return 0;
   }else {
printf("\n\n The Winner is Player O\n\n %d out of 5",lifeO);
return 0;
   }
}

if (haveWin==1){
  Reset();
}
PrintBox();
//Player Turn
while (input<6){
PlayerX();
if (input>5){ break; }
PlayerO();
} Pattern();

if (haveWin==0){
PlayerO();
Pattern();
   if (haveWin==0){
      PlayerX();
      Pattern();
          if (haveWin==0){
             PlayerO();
             Pattern();
                 if (haveWin==0){
                    PlayerX();
                    Pattern(); 
                       if (haveWin==0){
printf("\n   The Game is Draw! \n");
printf("\n\n     press any key");
getch();
system("cls");
Reset();
main();
                       }
                 }
       }
   }
} // End Player Turn

return 0; 
}// ----------------------------------


// PrintBox ----------------------
void PrintBox(){
	int x,y;
printf("\n");
	for ( x=0;x<3;x++){
printf("\t|");
		for ( y=0;y<3;y++){
if ((x==2||1)&&(y==1))
{ printf("|"); 
}
			printf("%c",box[x][y]);
if ((x==2||1)&&(y==1))
{ printf("|");}
		}
printf("|");
		printf("\n");
	}
} // End PrintBox -----------------


// Player X Function ---------------
void PlayerX(){
char player;
printf("\n Round %d",rnd);
    printf("\n X=%d  O=%d",lifeX,lifeO);
    printf("\n Player X turn: ");
	player=getche();
	system("cls");
    turn='X';
    Duplicate(player,turn);
}// ----------------------------------


// Player O Function ---------------
void PlayerO(){
char player;
printf("\n Round %d",rnd);
printf("\n X=%d  O=%d",lifeX,lifeO);
    printf("\n Player O turn: ");
	player=getche();
	system("cls");
    turn='O';
    Duplicate(player,turn);
}// ----------------------------------


// Pattern Function ----------------
void Pattern(){
char top[3];
char mid[3];
char bot[3];
int patX=0,patO=0;
int x,y;

   for (y=0;y<3;y++){
      top[y]=box[0][y];
      mid[y]=box[1][y];
      bot[y]=box[2][y];
   }

//horizontal
for ( x=0;x<3;x++){
switch (top[x]){
case 'X' : patX++; break;
case 'O' : patO++; break;
}}
PatternCheck(&patX,&patO);
for (x=0;x<3;x++){
switch (mid[x]){
case 'X' : patX++; break;
case 'O' : patO++; break;
}}
PatternCheck(&patX,&patO);
for (x=0;x<3;x++){
switch (bot[x]){
case 'X' : patX++; break;
case 'O' : patO++; break;
}}
PatternCheck(&patX,&patO);
//End Horizontal 

// Vertical 
for (x=0;x<3;x++){
if (top[x]=='X'){ patX++;
   if (mid[x]=='X'){ patX++;
     if (bot[x]=='X'){ patX++;
PatternCheck(&patX,&patO);
     }
   }
}
} patX=0,patO=0;
for (x=0;x<3;x++){
if (top[x]=='O'){ patO++;
   if (mid[x]=='O'){ patO++;
     if (bot[x]=='O'){ patO++; 
PatternCheck(&patX,&patO);
     }
   }
}
} patX=0,patO=0;
//End Vertical 

//SLanting

int t=0,m=1,b=2;
for (x=0;x<2;x++){
if (top[t]=='X'){ patX++;
  if (mid[m]=='X'){ patX++;
      if (bot[b]=='X'){ patX++;
PatternCheck(&patX,&patO);
      }
  }
}
t=2,b=0;
PatternCheck(&patX,&patO);
}
t=0,m=1,b=2,patX=0,patO=0;

for (x=0;x<2;x++){
if (top[t]=='O'){ patO++;
  if (mid[m]=='O'){ patO++;
      if (bot[b]=='O'){ patO++;
PatternCheck(&patX,&patO);
      }
  }
}
t=2,b=0;
PatternCheck(&patX,&patO);
} t=0,m=1,b=2,patO=0,patX=0;
//End Slanting
}// ----------------------------------

int PatternCheck(int *patX,int *patO){

if (*patX==3){ 
printf("\n  The Player X wins!\n\n");
printf("\n     press any key");
getch();
system("cls");
haveWin=1; rnd++;
lifeX++; main();
 } else if (*patO==3){ 
printf("\n  The Player O wins!\n\n");
printf("\n     press any key");
getch();
system("cls");
haveWin=1; rnd++;
lifeO++; main();
}
*patX=0;
*patO=0;
}

//Reset Function
void Reset(){
input=1;
int z=1;
int x,y;

for ( x=0;x<3;x++){
   for ( y=0;y<3;y++){
     box[x][y]='0'+z;
     dupli[z]=0;
     z++;
   }
}
haveWin=0;
} //End Draw

// Process -------------------
char InputProcess(char player,char turn){

   switch (player){
   	case '1':
   	box[0][0]=turn;
       dupli[1]=1;
   	input++;
   	break;
   	case '2':
   	box[0][1]=turn;
       dupli[2]=1;
   	input++;
   	break;
   	case '3':
   	box[0][2]=turn;
       dupli[3]=1;
   	input++;
   	break;
   	case '4':
   	box[1][0]=turn;
       dupli[4]=1;
   	input++;
   	break;
   	case '5':
   	box[1][1]=turn;
       dupli[5]=1;
   	input++;
   	break;
   	case '6':
   	box[1][2]=turn;
       dupli[6]=1;
   	input++;
   	break;
   	case '7':
   	box[2][0]=turn;
       dupli[7]=1;
   	input++;
   	break;
   	case '8':
   	box[2][1]=turn;
       dupli[8]=1;
   	input++;
   	break;
   	case '9':
   	box[2][2]=turn;
       dupli[9]=1;
   	input++;
   	break;
   	default :
system("cls");
   	if (turn=='X'){
printf("    [%c] is invalid\n",player);
   		PrintBox();
   		PlayerX();
   		system("cls");
printf("\n");
   	}
      else {
printf("    [%c] is invalid\n",player);
   		PrintBox();
   		PlayerO();
   		system("cls");
printf("\n");
   	}
   }
}  //End InputProcess --------------

char Duplicate(char player,char turn){
system("cls");

printf("Player [%c] entered [%c]\n",turn,player);

int x=0;
switch (player){
case '1' : x=1; break;
case '2' : x=2; break;
case '3' : x=3; break;
case '4' : x=4; break;
case '5' : x=5; break;
case '6' : x=6; break;
case '7' : x=7; break;
case '8' : x=8; break;
case '9' : x=9; break;
}


if (dupli[x]==0){
   InputProcess(player,turn);
   PrintBox();
}
else {
   if (turn=='X'){
       printf("Slot[%c] has already have\n",player);
       PrintBox();
       PlayerX();
   }
   else{
       printf("Slot[%c] has already have\n",player);
       PrintBox();
       PlayerO();
   }
}
} //End Duplicate -----------------
