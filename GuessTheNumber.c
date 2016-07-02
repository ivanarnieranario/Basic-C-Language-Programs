#include<stdio.h>
#include<conio.h>
int input,life,level,score,lives,temp, max,guess;

declaration(){
	life=19;
	guess=0;
	max=1000;
	score=0;
	level=1;
	temp=max+2000;
	lives=9;
	guess= (rand() % max )+1;
	start();
}

 start(){
	printf("\n\nStarting in Level %d ",level);
	printf("\n\t\t\t\t\t Life : %d ",life);
	printf("\nClue : 1 to %d ",max);
	printf("\n\t\t     Score : %d",score);
	printf("\n\nGuess the number : ");
	scanf("%d",&input);
	inputProcess();
}

  inputProcess(){
  	while (life>1){
    system("cls");
 	   if(input==guess){
 	   	printf("\n You got it! \n %d is correct \n\n ",input);
 	   	score=guess+score;
 	   	winProcess();
 	   }
 	 else if((input<guess)&&(input>0)){
 	 	printf("\n %d is too low \n please try again \n\n",input);
 	 	life--;
 	 	score--;
 	 	start();
 	 }
 else if((input>guess)&&(input<=max)){
 	 	printf("\n %d is too high \n please try again \n\n",input);
 	 	life--;
 	 	score--;
 start();
 }
 	 else{
 	printf("\n\n %d is out of range \n please read the CLUE \n ",input);
 	start();
 }

  	}
  	printf("\n\n Game Over ! ");
  	printf("\n Total Score : %d ",score);
  	exit(1);
  }

  winProcess(){
 	if (temp==max){
 		temp+=2000;
 		lives+=5;
 		level++;
 		life+=lives;
 		max+=1000;
 	    guess= (rand()%max)+1;
 	    start();
 	}
 	else{
 		guess= (rand()%max)+1;
 	life+=lives;
 		level++;
 		max+=1000;
 		start();
 	}
 }


main(){
	srand(time(0));
	printf(" \n\t Guess the Number ");
	declaration();
}
