#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	system("color 8f");
	int i,j,temp1,temp2;
	int at=0;
	int max=5;
	int wt[max],tat[max],et[max];
	int pro[5]={1,2,3,4,5};
	float awt=0,atat=0;
	int bt[5]={10,29,3,7,12};
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\tThe processes are as follows:\n");
	for(i=0;i<max;i++)
	{
		printf(" \t P[%d]\t",pro[i]);
	}
	printf("\n");
	printf("\n");
	printf("\t\tThe burst time of the respective processes are as follows:\n");
for(i=0;i<max;i++)
{
	printf("\t%d\t",bt[i]);
}
printf("\n");
printf("\n");
// bubble sort for sjf
for(i=0;i<max;i++)
{
	for(j=0;j<max-i-1;j++)
	{
		if(bt[j+1]<bt[j])
		{
			temp1=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=temp1;
			
			temp2=pro[j];
			pro[j]=pro[j+1];
			pro[j+1]=temp2;
			
		}
	}
}
printf("\n");
printf("    process id \t    burst time \t    waiting time    turnaround time    ending time \n");

for(i=0;i<max;i++)
{
	wt[i]=0;
	tat[i]=0;
	at=0;
	for(j=0;j<i;j++)
	{
	wt[i]+=bt[j];	
	}
	
	tat[i]=wt[i]+bt[i];
	et[i]=tat[i]+at;
	awt+=wt[i];
	atat+=tat[i];
	printf("\t%d\t\t %d\t\t %d\t\t %d\t\t   %d\n",pro[i],bt[i],wt[i],tat[i],et[i]);
	
}

awt/=max;
atat/=max;
printf("\n");
printf("\n\t\t\t\t  Average waiting time is= %f\n",awt);
printf("\n\t\t\t\tAverage turn around time is= %f\n",atat);
printf("\n\t\t\t     The ending time of P[i] which is P[%d] is =%d",pro[1],et[1]);
getch();
}
