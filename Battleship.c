//Header
#include<stdio.h>
#include<conio.h>
#include<string.h>
/*----------------------------------*/

//Function Declaration
void display_Grid(int rc);//display the grid
void random_Ship(int rc);//place the ship randomly in the grid
void level_Process(char name[10]); //where we input the coordinates(x,y)
void input_Coordinates(int rc);
int prevent_Crash(char input);
void player_Records(char name[10]);

/*----------------------------------*/

//Global Variables
int grid[9][9];//who hold the random ship
char disGrid[9][9];//who display the grid without seeing the random ship
int ship=0; //ship or the targets
int moves=0; //scores or no. of moves
int target;//tell how many targets in the grid 
int miss=0; //when we miss the ship
int level=0; //levels

/*----------------------------------*/

int main(){//Main Function
srand(time(0));//declare random algorithm using time
char name[10];
char inputName[99];
printf("\t    \"Battleship\"\n\n");//title

//input name to save in the records
puts("\n\n(maximum of 10 letters)\nEnter your Nickname:");
gets(inputName);
strncpy(name,inputName,10);
system("cls");

level_Process(name);//when we create a grid and increase the rows and columns every levels
}//End Main Function
/*----------------------------------*/

//level_Process Function
void level_Process(char name[10]){
int rc; //row and column, or the Coordinates(x,y)
rc=1;//minimum grid (2row x 2column) - starting grid
while (1){
if (ship<1){
if (level<5){
system("cls");
rc++; miss=0;  level++;
random_Ship(rc);
}else { //Last Level save the records
system("cls");
printf("\t    \"Battleship\"\n\n");//title
printf("-You reached the last level\nThank you for playing\n\n\n-%s \n-%d moves",name,moves);
player_Records(name);
return;
}
}
display_Grid(rc);
input_Coordinates(rc);
}
system("cls");//clear the screen

}//End level_Process Function

/*----------------------------------*/

//save the name and the moves of the player in the player records
void player_Records(char name[10]){
FILE * fadd;
fadd=fopen("PlayerRecords.txt","a");
fprintf(fadd," -%s- \n %d moves\n\n",name,moves);
fclose(fadd);
}//End player_Records

/*----------------------------------*/

//prevent_Crash Function
int prevent_Crash(char input){
//check if the input is character or a digits to prevent crashing of the program 
switch (input){
case '0' : return 0 ; break;
case '1' : return 1 ; break;
case '2' : return 2 ; break;
case '3' : return 3 ; break;
case '4' : return 4 ; break;
case '5' : return 5 ; break;
default :
return 19; //this is my favorite number ,but the point is when they put a character its return the 19 , 19 is > 9 so that number not belong into grid . because of that he prints out the -invalid coordinates
break;
}//end of switch case
}// End prevent_Crash

/*----------------------------------*/

//input_Coordinates Function
void input_Coordinates(int rc){
int xaxis=0,yaxis=0;// x and y (row,column)
char inX,inY;
printf("\nCannon Ready!\nCoordinates(x,y): ");
inX=getche(); 
printf(",");
inY=getche(); 
system("cls");

//convert the character input into a integer to access the array grid
xaxis=prevent_Crash(inX);
yaxis=prevent_Crash(inY);

if 
/*to prevent duplicate attack*/ (disGrid[xaxis][yaxis]=='s'||disGrid[xaxis][yaxis]=='1'){
printf("-Already Attack this Target!\n");
	return;
}//End of Duplicate Attack

//when we hit or miss the ship
if (xaxis<rc&&yaxis<rc){
    if (grid[xaxis][yaxis]==1){
        printf("-You hit the Ship!\n");
disGrid[xaxis][yaxis]='s';
moves++; target--; ship--;
return;
    } else {
        printf("-You missed the Ship!\n");
disGrid[xaxis][yaxis]='1';
moves++; target--; miss++;
return;
}
}else{ //when the inputted coordinates is not in the grid
printf("-Invalid Coordinates\n");
return;	
} 
}//End input_Coordinates

/*----------------------------------*/

//random_Ship Function
void random_Ship(int rc){
int rnd; //hold the random number
int x,y;//all rows and column = 0 to hide the random ship
for (x=0;x<rc;x++){
   for (y=0;y<rc;y++){
      disGrid[x][y]='0';
      grid[x][y]=0;
   }
} //display grid = '0'
target=rc*rc;//hold the targets or number of box(grid)

//insert 1 in the grid randomly or insert ship randomly
for (x=0;x<rc;x++){ 
rnd=(rand()%rc);//random 0 to rc
   for (y=0;y<rc;y++){
     if (rnd==y){ //insert ship in every row
ship++;
grid[x][y]=1;
     }else if (x>(rand()%rc+1)){//insert ship randomly in any column
ship++;
grid[x][y]=1;
     }
     }//end second loop
}//end first loop
}// End random_Ship

/*----------------------------------*/

//display_Grid Function
void display_Grid(int rc){
int x,y; //counter
int lu;//line up
//x for row and y for column
printf(" Y"); //print Y
for (y=0;y<rc;y++){
printf(" %d",y);
} //print the index of Y-Axis
if (level<5){
printf("   -Level %d-",level);
}else {
printf("   -Final Level-");
}
printf("\nX "); //print X

//print the ( ____ ) above the grid
for (lu=0;lu<((rc+rc)+1);lu++){
printf("_");
} // end of print line up


//print the all rows and columns
for (x=0;x<rc;x++){
printf("\n%d ",x);//index of X
   for (y=0;y<rc;y++){
printf("|%c",disGrid[x][y]);//print the display grid that and the ship not be seen
if (y==rc-1){ printf("|"); //add | at the end of every row
if (x==0){//print the missed
printf(" | Missed: %d",miss);
}// end of missed
   }//end of |
   }
}// end of print grid

//print the ( ``` ) below the grid
printf("\n  ");
for (lu=0;lu<((rc+rc)+1);lu++){
printf("`");
} // end of line down

//print the number of target,ship,levels and moves
char ss=' '; // s of ship
char st=' '; //s of target

if (ship>1){ ss= 's'; } //ships
if (target>1){ st= 's'; } //moves

printf("\n%d Target%c | %d Ship%c | Moves: %d",target,st,ship,ss,moves);
}//End display_Grid Function
