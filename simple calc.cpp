#include <stdio.h>
#include<stdlib.h>
int main()
{
	float a,b,r;
	char op;
	printf("Enter 2 numbers \n");
	scanf("%f%f", &a,&b);
	printf("Enter operator \n");
	scanf(" %c",&op);
	 
	switch (op)
	{
		case '+':
			r=a+b;
			break;
			
			case '-':
				r=a-b;
				break;
				
				case '*':
					r=a*b;
					break;
					
					case '/':
						if (b!=0){
							r=a/b;
						}
						else {
							printf("Invalid operation \n");
							exit(1);
						}
						
						default: printf("Invalid input \n");
						exit(1);
	}
	printf("%f%c%f=%f",a,op,b,r);
}
