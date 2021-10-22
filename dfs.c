#include<stdio.h>
int top;
int a[100];
int stack[100];
int array[100][100];
int visited[100];
int n;

void dfs(int node) 
{

    int i;
    for (i=0;i<n;i++)
    {
        if(array[node][i] == 1 && !visited[i])
        {
            stack[++top] = i;
         
        }
    }

    if(top > 1)
    {
        if(!visited[stack[top]])
            printf(" %d " , a[stack[top]]);
        visited[stack[top]] = 1;
        dfs(stack[--top]);

    }

}


void main()
{
    int i , j,m;
                                                                                                       
    printf("\nEnter the number of nodes needed : ");
    scanf("%d", &n);

    // Emter the nodes 
    printf("\nEnter the nodes :");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        visited[i] = 0;
    }
    
    // Print Adjacency matrix;
    printf("\nWrite the Adjacency matrix :");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d -> %d : " , a[i] , a[j]);
            scanf("%d", &array[i][j]);
            printf("\n");
        }
    }

    // Print the adjacency matrix
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j <n ;j++)
        {

            printf("%d ", array[i][j]);
        }
            printf("\n");
    }

    // Enter the index of the element to be enter 
    printf("\nEnter the index of the element to be entered :");
    scanf("%d" , &stack[1]);
    top = 1;
    visited[stack[1]] = 1;
    printf(" %d " , a[stack[top]]);
    dfs(stack[1]);
/*    for(m=1;m<n;m++)
    {
        if(visited[m]==0)
        {
            top=1;
            printf(" %d " , a[stack[top]]);
            visited[stack[1]] = 1;
            dfs(stack[1]);
        
        }
    }*/

}
