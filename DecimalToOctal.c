//Headers
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define divisor 8

/*----------------------------------*/
//Function Declaration
void displayConverted();
long int octalConverter(char in[20],long int input);
void octalComputation(long int in);
void insertNode(long int data,long int input);
void deleteNode(int n);//the argument is the position of the node you want to delete
void printLinkedList();
/*----------------------------------*/
//Global Variables
struct Node * head; //head pointer
int n=1;//position in the nodes
/*----------------------------------*/
//LINKED LIST CONCEPT
/*----------------------------------*/
//LINKED LIST
struct Node{//properties of a linked list
int position;
long int input;//hold the input
long int data; //hold the value of converted input to octal
struct Node *link; //hold the address of the next node
}; //declaring a node

//Insert Node Function
void insertNode(long int data,long int input){
struct Node* newNode = (struct Node*)malloc(sizeof (struct Node));//making a new node
newNode->position=n++;
//Inserting a node at the beggining of the linked list
if (head==NULL){
  newNode->data = data; //insert data into a new node
  newNode->input = input;
  newNode->link = NULL; //set the link into NULL
  head = newNode; //pass the newNode address to head
}else {
  newNode->data=data;
  newNode->input = input;
  newNode->link=head;
  head=newNode;
 }
}//end of insert node function
/*----------------------------------*/
//Delete Node Function
void deleteNode(int n){
struct Node* temp,*del;
//delete at the first node
if (head==NULL){
printf("-The Linked List is Empty-\n");
return;
}
if (head->position==n){
temp=head;
head=head->link;
free(temp);
return;
}//end of If

del=head;

//deleting a node at any position
while (del->link!=NULL){
  if (del->link->position==n){
     temp=del->link;
     del->link=temp->link;
     free(temp);//free the dynamic allocation of the heap
   return;
  }//end of if
del=del->link;
}//end of while
printf("Warning: Position is not valid!\n");
}//end of delete node
/*----------------------------------*/
//Print Linked List Function
void printLinkedList(){
//print the nodes one by one with the information of data,link,and address (traverse the linked list)
int x;
struct Node* traversal = head;
printf("-Linked List-\n\n");
printf("Head Pointer: %p",head);
printf("\n N | Address |  Link   | Data\n");
for ( x=0;x<33;x++){
printf("_");
}//end of for
while (traversal!=NULL){
if (traversal->link==NULL){
printf("\n %d | %p |   NULL  | %d = %d",traversal->position,traversal,traversal->input,traversal->data);
break;
}//end of if
printf("\n %d | %p | %p | %d = %d  ",traversal->position,traversal,traversal->link,traversal->input,traversal->data);
traversal = traversal->link;
}//end of while
}//end of print
/*----------------------------------*/
//MAIN FUNCTION
/*----------------------------------*/
//Main Function
int main(){
int ch;//choose
long int input;
printf("    -Decimal to Octal Converter-\n(Implementation of the Linked List)");//title

while (1){
printf("\n\n1.Convert\n2.Delete\n3.Exit\n\nchoose: ");
scanf("%d",&ch);
system("cls");
switch (ch){
case 1:
printf("Note:\nI will convert the value to octal\nAnd insert in the Beginning of the \nLinked List\n\nEnter a value to convert: ");
scanf("%d",&input);
system("cls");
octalComputation(input);
printLinkedList(); break;
case 2:
printf("Enter the position of the Node(N)\n: ");
 scanf("%d",&input);
system("cls");
deleteNode(input);
printLinkedList(); break;
case 3 :
exit(0); break;
}//end of switch case
}//end of while
}//end of main
/*----------------------------------*/
//OCTAL CONVERTING FUNCTIONS
/*----------------------------------*/
//Octal Converter Function
long int octalConverter(char in[20],long int input){
int length=strlen(in);//length of imput
int cNum;//converted digit
int octal=0;//answer
int exp=length-1;//exponent
int x;
//reverse and convert into integer the converted decimal to octal
for (x=(length-1);x>=0;x--){//reverse
cNum = in[x] - '0';//convert to int
octal+= pow(10,exp)*cNum;//combine the two number , example (10*1)*2 = 20 and (10*0) * 3 = 3 so when we add them the answer is 23
exp--;
}//end of for loop
insertNode(octal,input);
}//end of Octal Converter
/*----------------------------------*/

/*----------------------------------*/
//Octal Computation Function
void octalComputation(long int in){
long int quotient;
long int remainder;
long int temp;
int count=0;
char ci[99];//converted integer
quotient=in;

while (quotient!=0){
temp=quotient;//temporary hold the original value of quotient
quotient/=divisor;//get the quotient
remainder=temp-(quotient*divisor);//get the remainder
ci[count] = remainder + '0';//convert integer to character
count++;
}//end of while
octalConverter(ci,in);
}//end of Octal Computation
