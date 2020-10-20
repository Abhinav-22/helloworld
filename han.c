#include<stdio.h>
#include<math.h>
int item;
void push(int a[10],int *top)
{
    *top++;
    a[*top]=item;
}
void pop(int a[10],int *top)
{
    item=a[*top];
    *top--;
    if(*top==0)
        a[*top]==0;
}
void display(int a[10],int *top)
{
    int i;
    for(int i=*top;i>=1;i--)
    {
        printf("%d",a[i]);
    }
}

void main()
{
    int lim,n,i,atop=0,btop=0,ctop=0,a[10],b[10],c[10];
    a[0]=0;
    b[0]=0;
    c[0]=0;
    printf("enter the number of elements");
    scanf("%d",&n);
    
    for(i=n;i>=1;i--)
        {
            atop++;
            a[atop]=i;
            
        }
        
    lim=pow(2,n);
    for(i=1;i<=lim;i++)
    {
        printf("\n\n");
		printf("\nStack number 1:\t");
        if(a[atop]!=0)
	    	display(a,&atop);
        else
             printf("\n");
		printf("\nStack number 2:\t");
        if(b[btop]!=0)
		    display(b,&btop);
        else
        printf("\n");
		printf("\nStack number 3:\t");
        if(c[ctop]!=0)
    		display(c,&ctop);
        else
            printf("\n");
        if(i%3==1)
        {
            if(a[atop]==0 && c[ctop]!=0)
            {
                pop(c,&ctop);
                push(a,&atop);
                                         
            }
            else if (a[atop]!=0 && c[ctop]==0)
            {
                pop(a,&atop);
                push(c,&ctop);                
            }
            else if(a[atop]<c[ctop])
            {
                pop(c,&ctop);
                push(a,&atop);
            }
            else if(a[atop]>c[ctop])
            {
                pop(a,&atop);
                push(c,&ctop);   
            }
        }
        else if(i%3==2)
        {
             if(a[atop]==0 && b[btop]!=0)
            {
                pop(b,&btop);
                push(a,&atop);
                                         
            }
            else if (a[atop]!=0 && b[btop]==0)
            {
                pop(a,&atop);
                push(b,&btop);                
            }
            else if(a[atop]<b[btop])
            {
                pop(b,&btop);
                push(a,&atop);
            }
            else if(a[atop]>b[btop])
            {
                pop(a,&atop);
                push(b,&btop);   
            }            
                                   
        }            
        else if(i%3==0)
        {
             if(b[btop]==0 && c[ctop]!=0)
            {
                pop(c,&ctop);
                push(b,&btop);
                                         
            }
            else if (b[btop]!=0 && c[ctop]==0)
            {
                pop(b,&btop);
                push(c,&ctop);                
            }
            else if(b[btop]<c[ctop])
            {
                pop(c,&ctop);
                push(b,&btop);
            }
            else if(b[btop]>c[ctop])
            {
                pop(b,&btop);
                push(c,&ctop);   
            }            

        }
            
            
        


    }
    
}