#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int i,j,temp1,temp2;
	int at=0;
	int max=5;
	int wt[max],tat[max],et[max];
	int pro[5]={1,2,3,4,5};
	float awt=0,atat=0;
	int bt[5]={10,29,3,7,12};
	printf("The processes are as follows:\n");
	for(i=0;i<max;i++)
	{
		printf("P[%d]\n",pro[i]);
	}
	
	printf("The burst time of the processes are as follows:\n");
for(i=0;i<max;i++)
{
	printf("%d\n",bt[i]);
}
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

printf("\nAverage waiting time is= %f\n",awt);
printf("\nAverage turn around time is= %f\n",atat);
printf("\nThe ending time of P[%d] is =%d",pro[1],et[1]);
getch();
}
