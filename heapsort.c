#include<stdio.h>

void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    int temp;
    if(left<=n && a[left]>a[largest])
    {
        largest=left;
    } 

    if(right<=n && a[right]>a[largest])
    {
        largest=right;
    }

    if(a[largest]!=a[i])
    {
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,n,largest);
    }
    
}

void heapsort(int a[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        heapify(a,n,i);
    }
    for(i=n;i>1;i--)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapify(a,i-1,1);
    }

}

void main()
{
    int i , a[100],n;
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the tree in array form");

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=1;i<=n;i++)
    printf("%d ",a[i]);
    heapsort(a,n);
    printf("\nAfter Sort\n");
    for(i=1;i<=n;i++)
    printf("%d ",a[i]);

}
