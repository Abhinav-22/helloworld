/*This is a c program to implement priority queue.The user can input a queue(of maximum size 20) and its priority.
The elements will be inserted normally and deleted according to the priority.
*/

#include <stdio.h>
#include <conio.h>

int top=-1;
struct element
{
	int value,pri;
}a[20];

//To insert an element into queue
void insert(int n){
	if(top==(n-1)){
		printf("\nThe queue is full");
	}
	else{
		top++;
		printf("\nEnter the element:\t");
		scanf("%d",&a[top].value);
		printf("\nEnter the priority value:\t");
		scanf("%d",&a[top].pri);
	}
}

//To search for highest priority element
int search(int n){
	int pos=-1,i,max=a[0].pri;
	for(i=0;i<n;i++){
		if(a[i].pri>max){
			max=a[i].pri;
			pos=i;
		}
	}
	return pos;
}
//To sort after deletion
void sort(int n,int pos){
	int i,temp;
	for(i=pos;i<=n;i++){
		a[i]=a[i+1];
	}
}
//To delete an element from the queue
void delete(int n){
	int item,pos;
	if(top==-1){
		printf("\nThe queue is an empty queue");
	}
	else{
		pos=search(n);
		if(pos>0){
			item=a[pos].value;
			printf("\nYou have deleted %d from the queue",item);
			sort(n,pos);
			top--;
		}
		else{
			printf("\nNo element with that priority");
		}
	}
}
//To check whetehr the queue is full
void is_full(int n){
	if(top==n){
		printf("\nThe queue is full");
	}
	else{
		printf("\nThe queue is not full");
	}
}
//To check whetehr the queue is empty
void is_empty(int n){
	if(top==-1){
		printf("\nThe queue is empty");
	}
	else{
		printf("\nThe queue is not empty");
	}
}
//To display the queue
void display(int n){
	int i;
	for (i=0;i<=top;i++){
		printf(" %d",a[i].value);
	}
}
//Main
void main(){
	int opt,n;
	char ch;
	printf("\n______________PRIORITY QUEUE_________________");
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	do{
		printf("\n\tMENU\n\t1)INSERT\n\t2)DELETE\n\t3)CHECK IF QUEUE IS FULL\n\t4)CHECK IF QUEUE IS EMPTY\n\t5)DISPLAY\n\tEnter your choice:\t");
		scanf("%d",&opt);
		switch(opt){
			case 1:insert(n);break;
			case 2:delete(n);break;
			case 3:is_full(n);break;
			case 4:is_empty(n);break;
			case 5:display(n);break;
		}
		printf("\nDo you want to continue: ");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
}