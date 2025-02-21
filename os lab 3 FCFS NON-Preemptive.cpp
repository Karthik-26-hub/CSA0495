#include<stdio.h>
struct process
{
	int pid;
	int arrival;
	int burst;
	int completion;
	int turnaround;
	int waiting;
};
void calculatetimes(struct process p[],int n)
{
	int currenttime=0;
	for(int i=0;i<n;i++)
	{
		if(currenttime<p[i].arrival)
		{
			currenttime=p[i].arrival;
		}
		p[i].completion=currenttime+p[i].burst;
		p[i].turnaround=p[i].completion-p[i].arrival;
		p[i].waiting=p[i].turnaround-p[i].burst;
		currenttime=p[i].completion;
	}
}
void displayresults(struct process p[],int n)
{
	float avgwaiting=0,avgturnaround=0;
	printf("\nprocess\tarrival\tburst\tcompletion\tturnaround\twaiting\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].completion,p[i].turnaround,p[i].waiting);
		avgwaiting+=p[i].waiting;
		avgturnaround+=p[i].turnaround;
	}
	avgwaiting/=n;
	avgturnaround/=n;
	printf("\naverage waiting time: %.2f",avgwaiting);
	printf("\naverage turnaround time: %.2f\n",avgturnaround);
}
int main()
{
	int n;
	printf("enter the number of processes:");
	scanf("%d",&n);
	struct process p[n];
	printf("enter arrival time and bursst time for each process:\n");
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf("process %d arrival time:",i+1);
		scanf("%d",&p[i].arrival);
		printf("process %d burst time:",i+1);
		scanf("%d",&p[i].burst);
	}
for(int i=0;i<n-1;i++)
{
	for(int j=0;j<n-i-1;j++)
	{
		if(p[j].arrival>p[j+1].arrival)
		{
			struct process temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
		}
	}
}
calculatetimes(p,n);
displayresults(p,n);
return 0;
}
