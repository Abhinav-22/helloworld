//--------------------- REGULAR QUEUE ------------------

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int queue[CAPACITY], front = -1, rear = -1;

void display()
{   int i;
    if (front == -1 && rear == -1)
    {   printf("\nQueue underflow");    }
    else
    {   printf("\nQueue is : ");
        for (i = front; i <= rear; i++)
            printf("%d  ", queue[i]);
    }
    printf("\nFront = %d", front);
    printf("\nRear = %d", rear);
    printf("\n");
}

void insert(int element)
{   if (front == -1 && rear == -1)
    {   front = 0;
        rear = 0;
        queue[rear] = element;
        printf("%d inserted", element); }
    else
    {   rear++;
        queue[rear] = element;
        printf("%d inserted", element); }

    display();
}

void delete()
{   if (front == -1 && rear == -1)
    {   printf("\nQueue Underflow!");   }
    else {
        if (front == rear)
        {   printf("%d removed", queue[front]);
            front = -1;
            rear = -1;      }
        else
        {   printf("%d removed", queue[front]);
            front++;    } 
        
        display();
    }
}

void main()
{  int ch, element;
    printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");

    while (1)
    {   printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {   case 1:
            if (rear == CAPACITY - 1)
            printf("\nQueue Overflow");
            else{
                printf("\nEnter the element to be inserted : ");
                scanf("%d", &element);
                insert(element);
            }
            break;
            
            case 2:delete();break;
            
            case 3:display();break;
            
            case 4:exit(0);
            
            default:
            printf("\nWrong choice");
        }
    }
}
