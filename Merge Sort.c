//Header----------------------------
#include<stdio.h>
#include<conio.h>

//Declaration of Function----------
void mergeSort(int arr[],int ,int,int ); // To Merged The numbers and Sorted it.
void dividedConquer(int arr[],int,int ); //To Find the Middle Point and Divided Conquer

int aux[8];//Stands for Auxiliary where to stored new sorted list

//Main------------------------------
int main(){
int arr[8]={8,2,9,4,5,3,1,6};
int orig[8];//hold the original value
int x; //I always use variable x for counter
int max=8; //to know if How Many Index in an Array
printf("\tMerge Sort\n\n");
    printf(" Original Array: \n");
    for(x=0;x<max;x++){
orig[x]=arr[x];
         printf(" %d",orig[x]);
    } //Print The Original Array

dividedConquer(arr,0,max-1);

    printf("\n\n Auxiliary Array:\n ");
    for(x=0;x<max;x++){
         aux[x]=arr[x];
         printf("%d ",aux[x]);
    } //Print the New Sorted Array
   return 0;
}//End Main Function---------------


//Divided Conquer Function-------
void dividedConquer(int arr[],int low,int high){
int mid;

    if(low<high){
mid=(low+high)/2; //divide into 2
dividedConquer(arr,low,mid);  //until we get 2 to compare and sort it
dividedConquer(arr,mid+1,high);
mergeSort(arr,low,mid,high);//pass the value to arguments and process the sorted operations
}
} //End of DividedConquer---------


//Merge Sort-----------------------
void mergeSort(int arr[],int low,int mid,int high){
int x;//I always used Variable x for counter

int i,y;
int temp[9];//temporary hold the value of original value

    y=low;
    i=low;
    int m=mid+1;

    while((y<=mid)&&(m<=high)){

         if(arr[y]<=arr[m]){
             temp[i]=arr[y];
             y++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(y>mid){
         for (x=m;x<=high;x++){
             temp[i]=arr[x];
             i++;
         }
    }
    else{
         for ( x=y;x<=mid;x++){
             temp[i]=arr[x];
             i++;
         }
    }

    for (x=low;x<=high;x++){
         arr[x]=temp[x];
    }
} //End of Merge Sort--------------
