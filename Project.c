#include<stdio.h>

void sort();
void calcwt();
void printq();

int bt[10],waittime[10],pdata[10],priority[10];
int n, avgwt=0;
float avgtat=0;

int main()
{
	int i,j;
	printf("\nPreemptive Shortest Job First Scheduling:\n");
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter burst time for process P%d : ",i+1);
		scanf("%d",&bt[i]);
		pdata[i] = i+1;
	}

	sort();

	printf("\nProcess\t\tWaiting time\tTurn around time\tPriority");
	calcwt();

	printf("\n\nOrder of process execution: ");
	printq();

	printf("Average waiting time : %f\nAverage Turn around time : %f\n\n",avgwt/(float)n,avgtat/(float)n);
}

void sort()
{
	int x,y,temp;
	for(x=0;x<n;x++)
	{
		for(y=x;y<n;y++)
		{
			if(bt[x]>bt[y])
			{
				priority[x]=x;

				temp = bt[x];
				bt[x] = bt[y];
				bt[y] = temp;

				temp = pdata[x];
				pdata[x] = pdata[y];
				pdata[y] = temp;
			}
		}
	}
}

void calcwt()
{
	int j=0,z;
	for(z=0;z<n;z++)
	{
		waittime[z] = j;
		j = bt[z] + j;
		printf("\nP%d\t\t\t%d\t\t%d\t\t\t%d",pdata[z],waittime[z],waittime[z]+bt[z],priority[z]);
		avgwt+=waittime[z];
		avgtat+=waittime[z]+bt[z];
	}
}

void printq()
{
	int p;
	for(p=0;p<n;p++)
	{
		printf("P%d -> ",pdata[p]);
	}
	printf("End\n");
}
