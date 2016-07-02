#include<stdio.h>
#include<conio.h>
#include<string.h>
#define pf printf
#define sf scanf
float Value();
float Series();
float Parallel();
float Output();
//Global Variables
float et=0;
float rt=0;
float it=0;
float pt=0;
float e[50];
float i[50];
float p[50];
int res[50];
int tir,x;
char c;

int main()
{
	pf("\n S-eries Circuit\n P-arallel Circuit");

pf("\n\n Choose a circuit : ");
c=getche();
system("cls");
switch (c){
	case 's' : case 'S':
	pf("\t  Series Circuit");
	Value();
	system("cls");
	Series();
	break;
	case 'p' :case 'P' :
	pf(" \t  Parallel Circuit");
	Value();
	system("cls");
	Parallel();
	break;
	default :
	pf("\t  %c is invalid !\n",c);
	main();
	break;
}
}

float Value(){
	pf("\n\n Enter the total value of Voltage\n : ");
	sf("%f",&et);
	pf("\n How many Resistance do you have? \n : ");
	sf("%d",&tir);
	if (tir<2){
		system("cls");
		pf("\n You need atleast 2 Resistance \n");
		Value();
	}
		for (x=1;x<=tir;x++){
			system("cls");
			pf("\n Resistance\n");
		pf(" R%d : ",x);
		sf("%d",&res[x]);
	}

}
//Series
float Series(){
	system("cls");
	for (x=1;x<=tir;x++){
		rt+=res[x];
	}
	it=et/rt;
	pt=it*et;

for (x=1;x<=tir;x++){
	e[x]=it*res[x];
	i[x]=it;
	p[x]=(it*it)*res[x];
}
	pf("\t  Series Circuit\n\n");
Output();
}

//Parallel
float Parallel(){
	int lcd=1;
	float subt=0;
    int x=1;

	while(x<=tir){
		if ((lcd%res[x])==0){
		 subt+=(lcd/res[x]);
		 x++;
		}
		else{
			lcd++;
			x=1;
			subt=0;
		}
	}
	rt=lcd/subt;
	it=et/rt;
	pt=it*et;
	for (x=1; x<=tir;x++){
		e[x]=et;
		i[x]=et/res[x];
		p[x]=(et*et)/res[x];
	}
	pf(" \t  Parallel Circuit\n\n");
	Output();
}


float Output(){
	pf(" Total");
	pf("\n RT = %0.2f(ohms)\n ET = %0.2fV \n IT = %0.2fA \n PT = %0.2fW ",rt,et,it,pt);

	pf("\n\n ----------");
	for (x=1;x<=tir;x++){
	pf("\n\n R%d = %d(ohms)",x,res[x]);
	pf("\n E%d = %0.2fV",x,e[x]);
	pf("\n I%d = %0.2fA",x,i[x]);
	pf("\n P%d = %0.2fW",x,p[x]);
	}
}
