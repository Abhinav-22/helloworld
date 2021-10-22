#include<stdio.h>
int front=0,rear=0,n;
int a[100];
int queue[100];
int array[100][100];
int visited[100];


void bfs(int node) {

    int i;
    for (i=0;i<n;i++)
    {
      
        if(array[node][i] == 1 && !visited[i])
        {
            if(front == 0)
            {
                front= 1;
                rear= 1;
                queue[front]= i;
                visited[i]= 1;
            }
            else
            {            
                queue[++rear]= i;
                visited[i]= 1;
            }
        }
    }

    if(front <= rear)
    {
        printf("%d " , a[queue[front]]);
        bfs(queue[front++]);
    }

}



void main()
{
    int i , j;
    printf("\nEnter the number of nodess needed : ");
    scanf("%d", &n);

    // Emter the nodes 
    printf("\nEnter the nodes :");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        visited[i] = 0;
    }
    
    printf("\nWrite the Adjacency matrix :");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j <n ; j++)
        {
            printf("%d -> %d : " , a[i] , a[j]);
            scanf("%d", &array[i][j]);
            printf("\n");
        }
    }

    // Print the adjacency matrix
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;++j)
        {
            printf("%d ",array[i][j]);
        }
            printf("\n");
    }

    // Enter the index of the element to be enter 
    printf("\nEnter the index of the element to be entered :");
    scanf("%d" , &queue[1]);
  //  printf("%d", queue[1]);
    front=1;
    rear=1;
    visited[queue[1]]=1;
    bfs(queue[1]);

}
