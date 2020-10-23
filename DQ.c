/*This is a c program to implement the concept of DEQUE.
The use can input and delete from both the ends of the queue.
*/
#include <stdio.h>
#include<conio.h>
int front=-1,rear=-1;
//Function to insert an element at the rear end of the queue.
void r_insert(int a[20],int n){
	int item;
	if(front==-1){
		front=0;
	}
	if(rear==(n-1)){
		printf("\nThis end of Deque is full");
	}
	else{
		rear++;
		printf("\nEnter the item:\t");
		scanf("%d",&item);
		a[rear]=item;
	}
}
//Function to insert an element at the front end of the queue.
void f_insert(int a[20],int n){
	int item;
	if(rear==-1){
		rear=0;
	}
	if(front==0){
		printf("\nThis end of Deque is full");
	}
	else{
		front--;
		printf("\nEnter the item:\t");
		scanf("%d",&item);
		a[front]=item;
	}
}
//Function to delete an element from the rear end of the queue.
void r_delete(int a[10],int n){
	int item;
	if(rear==-1){
		printf("\nNo more element to delete from this end");
	}
	else{
		item=a[rear];
		rear--;
		printf("\nYou have successfully deleted %d from the Deque",item);
	}
}
//Function to delete an element from the front end of the queue.
void f_delete(int a[10],int n){
	int item;
	if(front==(n-1)){
		printf("\nNo more element to delete from this end");
	}
	else{
		item=a[front];
		front++;
		printf("\nYou have successfully deleted %d from the Deque",item);
	}
}
//A function to show the current status of the queue.
void check(int a[10],int n){
	printf("\nThe current status of Deque is:");
	if(rear==-1||front==-1){
		printf("\tYour Deque is empty.");
	}
	else if(front==0&&rear==(n-1)){
		printf("\tYour Deque is full.");
	}
	else{
		printf("\tThe deque is neither empty nor full.");
	}
}
//Function to display the queue.
void display(int a[10]){
	int i;
	for(i=front;i<=rear;i++){
		printf(" %d",a[i]);
	}
}
//Main function
void main()
{
	int a[10],n,opt;
	char ch;
	printf("\n______________DEQUE____________");
	printf("\nEnter the number of elements in the deque:\t");
	scanf("%d",&n);
	do{
		printf("\n\tMENU\n\t1)INSERT AT REAR\n\t2)INSERT AT FRONT\n\t3)DELETE FROM REAR\n\t4)DELETE FROM FRONT\n\t5)DISPLAY");
		printf("\nEnter your choice:\t");
		scanf("%d",&opt);
		switch(opt){
			case 1:r_insert(a,n);break;
			case 2:f_insert(a,n);break;
			case 3:r_delete(a,n);break;
			case 4:f_delete(a,n);break;
			case 5:display(a);break;
			default:printf("\nInvalid Entry");break;
		}
		check(a,n);
		printf("\nDo you want to continue.press y to continue:\t");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
	getch();
}
