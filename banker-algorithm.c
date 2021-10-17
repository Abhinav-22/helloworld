#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
int p_no,r_no,AVAIL[100],WORK[100],SAFE_SEQ[100],s_c=0,p_c;
struct process{
	int MAX[100],ALLOC[100],NEED[100];
	char F;
}p[100];
void max_matrix(){
	int i,j;
	printf("Enter the MAX matrix: ");
	for (i = 0; i < p_no; ++i)
	{
		for(j=0;j<r_no;++j){
			scanf("%d",&p[i].MAX[j]);
		}
	}
}
void max_matrix_display(){
	int i,j;
	printf("The MAX matrix is: \n");
	for(i = 0; i < p_no; ++i)
	{
		printf("P%d %d ",i,p[i].MAX[0]);
		for(j=1;j<r_no;++j){
			printf(" %d ",p[i].MAX[j]);
		}
		printf("\n");
	}
}
void available(){
	int i;
	printf("Enter the available matrix: ");
	for(i=0;i<r_no;i++){
		scanf("%d",&AVAIL[i]);
	}
}
void available_display(){
	int i;
	printf("The available matrix is: ");
	for(i=0;i<r_no;i++){
		printf(" %d ",AVAIL[i]);
	}
}

void allocation_matrix(){
	int i,j;
	printf("Enter the ALLOCATION matrix: ");
	for (i = 0; i < p_no; ++i)
	{
		for(j=0;j<r_no;++j){
			scanf("%d",&p[i].ALLOC[j]);
		}
	}
}
void allocation_matrix_display(){
	int i,j;
	printf("The ALLOCATION matrix is:\n");
	for(i = 0; i < p_no; ++i)
	{
		printf("P%d %d ",i,p[i].ALLOC[0]);
		for(j=1;j<r_no;++j){
			printf(" %d ",p[i].ALLOC[j]);
		}
		printf("\n");
	}
}
int main()
{
	int i,j,k,turn=0,flag=1,count=0,present;
	printf("Enter the number of processes: ");
	scanf("%d",&p_no);
	printf("Enter the number of resources: ");
	scanf("%d",&r_no);
	max_matrix();
	/*max_matrix_display();*/
	allocation_matrix();
	available();
	printf("PROCESS  MAX   ALLOCATION  AVAILABLE\n");
	/*for(i=0;i<p_no;i++){
		k=i;
		for(j=0;j<r_no;j++){
				if(k==i){
				printf("p%d\t%d\t%d\t%d",i,MAX[i][j],ALLOC[i][j],AVAIL[j]);
				k=-1;
			}
			else{
				printf(" \t%d\t%d",MAX[i][j],ALLOC[i][j]);
			}
		}
		printf("\n");
	}*/
	max_matrix_display();
	allocation_matrix_display();
	available_display();
	for(i=0;i<r_no;i++)
		WORK[i]=AVAIL[i];
	for(i=0;i<p_no;i++){
		for(j=0;j<r_no;j++){
			p[i].NEED[j]=p[i].MAX[j] - p[i].ALLOC[j];
		}
	}
	for(i=0;i<p_no;i++){
		p[i].F='F';
	}
/*do{
	for(i=0;i<\;i=(i+1)%p_no)
}while(done==1)*/
	/*do{
		
		for(i=0;;i=(i+1)%p_no){
			pf=1;
			for(j=0;j<r_no;j++){
				if(p[i].NEED[j]>WORK[j]){
					pf=0;
				}
			}
			if(pf==1){
				for(j=0;j<r_no;j++){
					WORK[j]=p[i].ALLOC[j];
					p[i].F=TRUE;
					SAFE_SEQ[s_c]=i;
					s_c++;
				}
			}
		}

	}while(done==1);*/
	/*turn=0;
	i=0
	for(p_c=0;(p_c<p_no);p_c++){
		for(;i<p_no;i=(i+1)%p_no){
			if(p[i].F=='F'){
				flag =1;
				for(j=0;j<r_no;j++){
					if(p[i].NEED[j]>AVAIL[j]){
						flag=0;
					}
				}
				if (flag==1)
				{
					SAFE_SEQ[s_c]=i;
					s_c++;
					p[i].F='T';
					for (j = 0; j < r_no; ++j)
					{
						WORK[j]=p[i].ALLOC[j];
					}
				}
			}
		}
	}*/
	

	turn=0;
	i=0;
	for(p_c=0;(p_c<p_no);p_c++){
		for(;i<p_no;i=(i+1)%p_no){
			if(p[i].F=='F'){
				flag =1;
				for(j=0;j<r_no;j++){
					if(p[i].NEED[j]>WORK[j]){
						flag=0;
					}
				}
				if (flag==1)
				{
					SAFE_SEQ[s_c]=i;
					s_c++;
					p[i].F='T';
					for (j = 0; j < r_no; ++j)
					{
						WORK[j]=p[i].ALLOC[j];
					}
				}
			}
		}
	}
	/*turn=0;
	while(count<p_no){
		present = count;
		for(i=0;i<p_no;i++){
			if(p[i].F=='F'){
				flag =1;
				for(j=0;j<r_no;j++){
					if(p[i].NEED[j]>WORK[j]){
						flag=0;
					}
				}
				if (flag==1)
				{
					SAFE_SEQ[s_c]=i;
					s_c++;
					count++;
					p[i].F='T';
					for (j = 0; j < r_no; ++j)
					{
						WORK[j]=p[i].ALLOC[j];
					}
				}
			}
		}
		if(present == count){
			printf("unsafe state");
			break;
		}
	}*/
	if(p_no == s_c){
	printf("\nSAFE STATE.The safe sequence is: ");
		for(k=0;k<s_c-1;k++){
			printf(" %d-->",SAFE_SEQ[k]);
		}
		printf(" %d",SAFE_SEQ[k]);
	}
	else{
		printf("\nUNSAFE STATE.The sequence is: ");
		for(k=0;k<s_c-1;k++){
			printf(" %d-->",SAFE_SEQ[k]);
		}
		printf(" %d",SAFE_SEQ[k]);
	}
	getch();
	return 0;
}