#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void Push(int x);
void Pop();
void Display();

	int stk[500], top;
	int i;
	
	
	
	
	
int main(){
	int ch;
	top=-1;
	
	while(1){
		printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit \n : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf(" Insert Element: ");
				scanf("%d",&ch);
				Push(ch);
				break;
			case 2:
				Pop();
				break;
			case 3:
				Display();
				break;
			case 4:
				return 0;
				break;
			default: 
				system("cls");
				printf("\n Invalid Keyword");
		}	
	}
	
	
	return 0;
}



		
	void Push(int x){
		if (top>500){
			system("cls");
			printf("\n The Stack is Full");
			return;
		}
		stk[++top]=x;
		system("cls");
		printf("\n Successfully Inserted!");
	}
	
	
	void Pop(){
		if (top<0){
			system("cls");
			printf("\n The Stack is Empty");
			return;
		}
		system("cls");
		printf("\n The Deleted Element is %d",stk[top--]);
	}
	
	
	void Display(){
		if (top<0){
			system("cls");
			printf(" The Stack is Empty");
			return;
		}
		system("cls");
		for (i=top;i>=0;i--){
			printf("%d ",stk[i]);
		}
	}


