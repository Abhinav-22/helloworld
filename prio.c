#include<stdio.h>
int size=5,top=-1;
struct element
{
    int v,p;
}a[20];

void insert()
{
    if (top==(size-1))
    {
        printf("Queue Full");
    }
    else
    {
        top++;
        printf("\nEnter Element\n");
        scanf("%d",&a[top].v);
        printf("enter priority value");
        scanf("%d",&a[top].p);
    }
}

void sort(int pos)
{
	int i;
	for(i=pos;i<=top;i++)
    {
		a[i]=a[i+1];
	}
}

int search()
{
    int pos=0,i,max=a[0].p;
	for(i=1;i<size;i++)
    {
		if(a[i].p>max)
        {
			max=a[i].p;
			pos=i;
		}
	}
    return pos;
}

void delete()
{   
    int item,pos;
    if(top==-1)
        printf("Queue Empty");
    else
    {
        pos=search();
        item=a[pos].v;
        printf("Element %d deleted from queue",item);
        sort(pos);
        top--;
        
    }

    
}


void isfull()
{
    if(top==size-1)
    {
        printf("Queue Full");
    }
    else
    {
        printf("Queue not full");
    }
    
}
void isempty()
{
    if(top==-1)
    {
        printf("Queue Empty");
    }
    else
    {
        printf("Queue not empty");
    }
    
}

void display()
{   int i;
if(top==-1)
{
    printf("Empty");
}
else{
    for(i=0;i<=top;i++)
    {
        printf("%d   ",a[i].v);
    }
}

}


    void main()
    {
	int c;
	char ch;
	do{
		printf("\n\tMENU\n\t1)INSERT\n\t2)DELETE\n\t3)CHECK IF QUEUE IS FULL\n\t4)CHECK IF QUEUE IS EMPTY\n\t5)DISPLAY\n\tEnter your choice:\t");
		scanf("%d",&c);
		switch(c)
        {
			case 1:insert();break;
			case 2:delete();break;
			case 3:isfull();break;
			case 4:isempty();break;
			case 5:display();break;
		}
		printf("\nDo you want to continue:(y/n) ");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
}

