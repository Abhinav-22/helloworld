#include<stdio.h>

void SparseAdd(int a[10][3], int b[10][3])
{
    int a_index,b_index,c_index,a_terms,b_terms,c_terms,c[10][3];
    if((a[0][0]!=b[0][0])||(a[0][1]!=b[0][1]))
        printf("Incompatible matrix");
    else{
        c[0][0]=a[0][0];
        c[0][1]=a[0][1];
        a_terms=1; b_terms=1; c_terms=1;
        while((a_terms<=a[0][2]) &&(b_terms<=b[0][2]))
        {
            a_index = a[a_terms][0]*a[0][1]+a[a_terms][1];
            b_index = b[b_terms][0]*b[0][1]+b[b_terms][1];
            if(a_index<b_index)
            {
                c[c_terms][0] = a[a_terms][0];
                c[c_terms][1] = a[a_terms][1];
                c[c_terms][2] = a[a_terms][2];
                a_terms++;
            }
        	else if(a_index>b_index)
        	{
        		c[c_terms][0] = b[b_terms][0];
                c[c_terms][1] = b[b_terms][1];
                c[c_terms][2] = b[b_terms][2];
                b_terms++;
        	} 
        	else
        	{
        		c[c_terms][0]=a[a_terms][0];
        		c[c_terms][1]=a[a_terms][1];
        		c[c_terms][2]=a[a_terms][2]+b[b_terms][2];
        		a_terms++;
        		b_terms++;
        	}
    	c_terms++;
    }
    for(;a_terms<a[0][2];a_terms++,c_terms++)
    {
    	c[c_terms][0]=a[a_terms][0];
    	c[c_terms][1]=a[a_terms][1];
    	c[c_terms][2]=a[a_terms][2];
    }
    for (;b_terms<b[0][2];b_terms++,c_terms++)
    {
    	c[c_terms][0]=b[b_terms][0];
    	c[c_terms][1]=b[b_terms][1];
    	c[c_terms][2]==b[b_terms][2];
    }
    c[0][2]=c_terms-1;
	}
	display(c);
}

void display(int a[10][3])
{
	int i,j,k=1,n;
	n=a[0][2];
    printf("");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}


void transpose(int a[10][3])
{
	int m,n,p,q=1,count,col,t[10][3];
	m=a[0][0];
	n=a[0][1];
	count=a[0][2];
	t[0][0]=n;
	t[0][1]=m;
	t[0][2]=count;
	if(count>0)
	{
		for(col=0;col<n;col++)
			for(p=1;p<=count;p++)
			{
				if(a[p][1]==col)
				{
					t[q][0]=a[p][1];
					t[q][1]=a[p][0];
					t[q][2]=a[p][2];
					q++;
				}
			}display(t);
	}

}

void sparse(int s[10][3],int a[10][10],int m,int n)
{
	int i,j,k=1;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				s[k][0]=i;
				s[k][1]=j;
				s[k][2]=a[i][j];
				k++;
			}
		}
		s[0][0]=m;
		s[0][1]=n;
		s[0][2]=k-1;
		display(s);
}


void main()
{
    int a[5][10],b[5][10],s1[10][3],i,j,m,n,p,q,s2[10][3],ch;
    char c;
    printf("Enter the rows and columns of the first matrix : ");
    scanf("%d%d",&m,&n);    
    printf("Enter the elements of the first matrix : ");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    printf("Sparse form of first matrix :\n");
    sparse(s1,a,m,n);
    printf("Enter the rows and columns of the second matrix : ");
    scanf("%d%d",&p,&q);    
    printf("Enter the elements of the second matrix : ");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d",&b[i][j]);
    printf("Sparse form of second matrix :\n");
    sparse(s2,b,p,q);
    do
    {
        printf("\n\t\tMENU \n1)ADDITION \n2)TRANSPOSE");
        printf("\nEnter your option : ");
        scanf("%d",&ch);
        switch(ch){
        	case 1:
           		SparseAdd(s1,s2);
            	break;
            
        	case 2:
        
            	printf("Transpose of first matrix :");
	            transpose(s1);
	            printf("\nTranspose of second matrix :");
	            transpose(s2);
	            break;
            default:printf("INVALID ENTRY");
        }
        printf("\nDo you want to continue (y/n)");
        scanf("%s",&c);
    }while(c == 'y');

}













