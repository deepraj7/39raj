#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	system("color 8f");
	int i,j,temp1,temp2;
	int at=0;
	int max;
	int wt[max],tat[max],et[max]; //initialization of variables such as burst,waiting ending,turn around time,etc.
	int pro[max];
	float awt=0,atat=0;
	int bt[max];
	printf("\t\t\tEnter the number of processes\n");
	scanf("%d",&max); //to enter the number of process 
//	printf("\n");
	printf("\t\t\t\tEnter the process id:\n");
	for(i=0;i<max;i++)
	{
		printf("Enter the id of process(%d):=",i+1); //for process id
		scanf(" %d",&pro[i]);
	}
//	printf("\n");
//	printf("\n");
	printf("\t\tEnter the burst time of the respective processes:\n");
for(i=0;i<max;i++)
{
	printf("Enter the burst time of process(%d):=",i+1); // burst time of respective process
	scanf("%d",&bt[i]);
}
printf("\n");
printf("\n");
// bubble sort for sjf
for(i=0;i<max;i++)
{
	for(j=0;j<max-i-1;j++)
	{
		if(bt[j+1]<bt[j])  //compares for the shortest burst time
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
	wt[i]+=bt[j];	//calculation of waiting time
	}
	
	tat[i]=wt[i]+bt[i]; //calculation of turn around time
	et[i]=tat[i]+at; //calculation of ending/completion time
	awt+=wt[i]; //average waiting time
	atat+=tat[i]; //average turn around time
	printf("\t%d\t\t %d\t\t %d\t\t %d\t\t   %d\n",pro[i],bt[i],wt[i],tat[i],et[i]);
	
}

awt/=max;
atat/=max;
printf("\n");
printf("\n\t\t\t\t  Average waiting time is= %f\n",awt);
printf("\n\t\t\t\tAverage turn around time is= %f\n",atat);
printf("\n\t\t\t     The ending time of P[i] which is P[%d] is =%d",pro[1],et[1]); //for P[i}
getch();
}


/*
test cases
1st-
5
pids=1,2,3,4,5
bts=10,29,3,7,12

2nd-
3
pids=12,10,15
bts=50,75,73

3rd-
4
pids=56,48,75,96
bts=5,10,15,20
*/
