#include<stdio.h>

void  compareTriplets(int a[],int b[])
{
	int result[]={0,0};
	for (int i = 0; i < 3; ++i)
	{
		if(a[i]>b[i])
			result[0]+=1;
		else if(a[i]<b[i])
			result[1]+=1;
	}
	for (int i = 0; i < 2; ++i)
		printf("%d ",result[i]);
}

int main()
{
	int a[3],b[3],result[2];
	for (int i = 0; i < 3; ++i)
		scanf("%d",&a[i]);
	for (int i = 0; i < 3; ++i)
		scanf("%d",&b[i]);
	compareTriplets(a,b);
}