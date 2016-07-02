/*----------------------------------*/
//Headers
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define trueValue 9.8

/*----------------------------------*/

//Declaration of function
void Tables(struct Object obj[5]);
float Average(float t1,float t2,float t3);
float Gravitational(float ave);
float AoE(float gE);//means ammount of error
float percentD(float AoE);//percent difference
void Computation(struct Object o[10],int x);

/*----------------------------------*/

//Characteristics of an object
struct Object{
char name[10];
float trial[3];
float ave;
float mass;
float gE;//gravitational experimental
float aR; //amount of error
float pD;//percent of difference
};//end of struct

/*----------------------------------*/

//Global Variables
float height;
int max;

/*----------------------------------*/

//Main Function
int main(){
struct Object obj[5];//object
max = 1;
height=7.42;

printf("   Free Falling Bodies Calculator\n\n");
//Height
//printf("Enter the value of Height\n: ");
//scanf("%f",&height);
//clrscr();
int x;
for ( x=0;x<max;x++){
printf("Enter the value of the Following\n\n");
printf("\"Object %d\"\n",x+1);
printf("Name: ");
scanf("%s",&obj[x].name);
for (int y=0;y<3;y++){
printf("Trial %d : ",y+1);
scanf("%f",&obj[x].trial[y]);
}//end of trial
printf("Mass: ");
scanf("%f",&obj[x].mass);
system("cls");
}//end of tables

Tables(obj);
return 0;
}//end of main

/*----------------------------------*/

//Print the Table with Answers
//Tables Function
void Tables(struct Object obj[5]){
//Print the Tables
int x,y;
for ( x=0;x<max;x++){
//Object Name
if (x==0){
printf("____________________________________\n");
}
printf("____________________________________\n");
printf(" Object No. %d\n\n",x+1);
printf("Name\t  : %s",obj[x].name);
//Trials
for (y=0;y<3;y++){
printf("\nTrial %d   : %0.2fs",y+1,obj[x].trial[y]);
}//end of trials
//Average
printf("\nAverage   : %0.2fs",obj[x].ave=(Average(obj[x].trial[0],obj[x].trial[1],obj[x].trial[2])));
//Mass
printf("\nMass\t  : %0.2fcg",obj[x].mass);
//Gravitational Experimental
printf("\nGravity\t  : %0.2fm/s^2",obj[x].gE=Gravitational(obj[x].ave));
//Amount of Error
printf("\nError\t  : %0.2f",obj[x].aR=AoE(obj[x].gE));
//Percentage Difference
char percent='%';
printf("\nPercentage: %0.2f%c\n",obj[x].pD=percentD(obj[x].aR),percent);
//Show Solution
Computation(obj,x);
if (x==max-1){
printf("____________________________________\n");
}
printf("____________________________________\n");
}//end of object
}//end of tables

/*----------------------------------*/

//Sample Computation
void Computation(struct Object o[5],int x){
printf("\n\t -Sample Computation-\n\n");//title
//Average
printf("Average: \n(%0.2f + %0.2f + %0.2f) / 3",o[x].trial[0],o[x].trial[1],o[x].trial[2]);
printf("\n%0.2f / 3\n%0.2fs",(o[x].trial[0]+o[x].trial[1]+o[x].trial[2]),o[x].ave);
//Gravity
printf("\n\nGravity: \n2(%0.2f) / (%0.2f)^2",height,o[x].ave,o[x].gE);
printf("\n%0.2f / %0.4f\n%0.2fm/s^2",(2*height),pow(o[x].ave,2),o[x].gE);
//Amount of Error
printf("\n\nAmount of Error: \n%0.1f - %0.2f\n%0.2f",trueValue,o[x].gE,o[x].aR);
//Percent of Difference
char percent='%';
printf("\n\nPercent of Difference\n(%0.2f / %0.1f) * 100\n%0.4f * 100",o[x].aR,trueValue,(o[x].aR/trueValue));
printf("\n%0.2f%c\n",o[x].pD,percent);
}//end of Computation

/*----------------------------------*/
//Getting the Answer--------------

//Average Function
float Average(float t1,float t2,float t3){
float ave;
ave=(t1+t2+t3)/3;
//round to the 2 decimal places
ave= roundf(ave*100)/100;
return ave;
}//end of average

/*----------------------------------*/

//Gravitational Experimental
float Gravitational(float ave){
float gE;
gE = (2*height)/(ave*ave);
gE = roundf(gE*100)/100;
return gE;
}//end of gravitational

/*----------------------------------*/

//Ammount of Error Function
float AoE(float gE){
float AoE;
AoE=trueValue-gE;
AoE = round(AoE*100)/100;
return AoE;
}//end of ammount of error

/*----------------------------------*/

//Percent Difference
float percentD(float AoE){
float pD;
pD = (AoE*100)/trueValue;
pD = round(pD*100)/100;
return pD;
}//end of percent difference
/*----------------------------------*/
