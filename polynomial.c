#include<stdio.h>
#include<math.h>
struct poly
{
	int coe,exp;
};

void display(struct poly a[100],int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		if(i==n-1)
			printf("%dx^%d",a[i].coe,a[i].exp);
		else
			printf("%dx^%d+",a[i].coe,a[i].exp);

	}
}

void polyread(struct poly a[100],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the coefficient of element %d:\t",i+1);
		scanf("%d",&a[i].coe);
		printf("\nEnter the exponent of element %d:\t",i+1);
		scanf("%d",&a[i].exp);
	}
}

void polyadd(struct poly a[],struct poly b[],int a_count,int b_count)
{
	int a_terms=0,b_terms=0,c_terms=0;
	int x;
	struct poly c[100];
	while(a_terms<a_count && b_terms<b_count)
	{
		if(a[a_terms].exp>b[b_terms].exp)
		{
			c[c_terms].coe=a[a_terms].coe;
			c[c_terms].exp=a[a_terms].exp;
			a_terms++;
			
		}
		else if(a[a_terms].exp<b[b_terms].exp)
		{
			c[c_terms].coe=b[b_terms].coe;
			c[c_terms].exp=b[b_terms].exp;
			b_terms++;
			
		}
		else
		{
			c[c_terms].coe=a[a_terms].coe+b[b_terms].coe;
			c[c_terms].exp=b[b_terms].exp;
			a_terms++;
			b_terms++;
			
		}
		c_terms++;
	}
	for(;a_terms<a_count;a_terms++,c_terms++)
	{
		c[c_terms].coe=a[a_terms].coe;
		c[c_terms].exp=a[a_terms].exp;
	}
	for(;b_terms<b_count;b_terms++,c_terms++)
	{
		c[c_terms].coe=b[b_terms].coe;
		c[c_terms].exp=b[b_terms].exp;		
	}
	display(c,c_terms);
	printf("\nenter the value of x");
	scanf("%d",&x);
	polyeval(c,c_terms,x);
}

void polymultiply(struct poly a[100],struct poly b[100],int a_count,int b_count)
{	
	int a_terms,b_terms,c_terms=0,max,j=0,s=0,x;
	struct poly c[100],d[100];
	for(a_terms=0;a_terms<a_count;a_terms++)
	{
		for(b_terms=0;b_terms<b_count;b_terms++)
		{
			c[c_terms].coe=a[a_terms].coe*b[b_terms].coe;
			c[c_terms].exp=a[a_terms].exp+b[b_terms].exp;
			c_terms++;
		}
	}

max=c[0].exp;
for(;max>=0;max--)
{int i;

	s=0;
	for(i=0;i<c_terms;i++)
	{
		if(c[i].exp==max)
		{
			s=s+c[i].coe;
		}
		
	}
		d[j].coe=s;
		d[j].exp=max;
		j++;
}
display(d,j);
printf("\nenter the value of x");
scanf("%d",&x);
polyeval(d,j,x);
}

void polyeval(struct poly a[100],int a_count,int x)
{
	int a_terms,eval=0,i,t;
	for(a_terms=0;a_terms<a_count;a_terms++)
	{
		for(t=1,i=0;i<a[a_terms].exp;i++)
			t*=x;
			eval+=a[a_terms].coe*t;
	}
	printf("answer after evaluation=%d",eval);
}

void main()
{
	int a_count,b_count,x,c;
	char ch;
	struct poly a[100],b[100];
	printf("enter the number of elements in polynomial 1 ");
	scanf("%d",&a_count);
	polyread(a,a_count);
	printf("enter the number of elementsin polynomial 2 ");
	scanf("%d",&b_count);
	polyread(b,b_count);
	
	do {
			printf("\n\n\t\tMENU\n\t\t1.ADD\n\t\t2.MULTIPLY\n\t\tENTER CHOICE ");
			scanf("%d",&c);
			switch(c)
			{
				case 1:{polyadd(a,b,a_count,b_count);
						break;
					}
				case 2:{polymultiply(a,b,a_count,b_count);
						break;
					}
				default:{printf("INVALID ENTRY");
					}
			}
			printf("\nDo you want to continue(y/n)");
			scanf("%s",&ch);
		}while(ch=='y');

}