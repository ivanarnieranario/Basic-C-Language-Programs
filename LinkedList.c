#include<stdio.h>
#include<conio.h>
#include<string.h>
void Insert(int data);
void Print();
void Delete(int data);

//Declaring a Node
struct Node{
int data;
struct Node* link;
};

//Global Variables
struct Node* head;

int main(){
head=NULL;
int ch;//choose
Insert(23);
Insert(19);
Insert(207);
Insert(407);
Insert(890);
Print();

/*while (1){
printf("1.Insert Node\n2.Delete Node\n3.Exit\n: ");
scanf("%d",&ch);
switch (ch){
case 1:
printf("Insert a data: ");
scanf("%d",&data);
Insert(data);
break;
case 2:
printf("Delete a data: ");
scanf("%d",&data);
Delete(data);
break;
case 3:
 exit(0);
break;
}//end of switch case
system("cls");
}//end of while
*/
}//end of main

void Insert(int data){
struct Node* newNode = (struct Node*)malloc(sizeof (struct Node));//making a new node

if (head==NULL){
  newNode->data = data;
  newNode->link = NULL;
  head = newNode;
}else {
  newNode->data=data;
  newNode->link=head;
  head=newNode;
 }


}//end of insert

void Print(){
    int x;
struct Node* traversal = head;
printf("Address |  Link   | Data\n");
for (x=0;x<25;x++){
printf("_");
}
while (traversal!=NULL){
if (traversal->link==NULL){
printf("\n%p |  NULL   | %d",traversal,traversal->data);
break;
}
printf("\n%p | %p | %d ",traversal,traversal->link,traversal->data);
traversal = traversal->link;
}
}//end of print





void Delete(int data){

}//end of delete
