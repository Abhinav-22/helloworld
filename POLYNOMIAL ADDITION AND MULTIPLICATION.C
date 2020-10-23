#include<stdio.h>
void main()
{
    int poly1,poly2,i,j,length,option,coef,power,n;
    char choice='y';
    char space;
    do
    {
        int P1[10]={0},P2[10]={0},P3[20]={0};
        printf("\n\n\tMENU\n1.Polynomial Addition\n2.Polynomial Multiplication\n3.Exit");
        printf("\nEnter your option: ");
        scanf("%d",&option);
        if(option==3)
        exit(0);
        printf(" number of terms in first polynomial: ");
        scanf("%d",&n);
        printf(" coefficient and power of term 1: ");
        scanf("%d%d",&coef,&power);
        P1[power]=coef;
        poly1=power;
        for(i=1;i<n;i++)
        {
            printf(" coefficient and power of term %d: ",i+1);
            scanf("%d%d",&coef,&power);
            P1[power]=coef;
            if(poly1<power)
            poly1=power;
        }
        printf(" number of terms in second polynomial: ");
        scanf("%d",&n);
        printf(" coefficient and power of term 1: ");
        scanf("%d%d",&coef,&power);
        P2[power]=coef;
        poly2=power;
        for(i=1;i<n;i++)
        {
            printf(" coefficient and power of term %d: ",i+1);
            scanf("%d%d",&coef,&power);
            P2[power]=coef;
            if(poly2<power)
            poly2=power;
        }
        switch(option)
        {
            case 1:
                for(i=0;i<=poly1||i<=poly2;i++)
                P3[i]=P1[i]+P2[i];
                if(poly1>poly2)
                length=poly1;
                else
                length=poly2;
                printf("Sum of the polynomials :");
                for(i=length;i>=1;i--)
                printf("%dx^%d+",P3[i],i);
                printf("%d",P3[0]);
                break;
            case 2:
                for(i=poly1;i>=0;i--)
                for(j=poly2;j>=0;j--)
                P3[i+j]+=(P1[i]*P2[j]);
                length=poly1+poly2;
                printf("Product of the polynomials :");
                for(i=length;i>=1;i--)
                printf("%dx^%d+",P3[i],i);
                printf("%d",P3[0]);
                break;
        }  
        printf("\nDo you wish to continue (y/n): ");
        scanf("%c",&space);
        scanf("%c",&choice);
    }while(choice=='Y'||choice=='y');
}

