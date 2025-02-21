#include<stdio.h>
struct process
{
    int pid;
    int bt;
    int at;
    int wt;
    int tat;
};
void sortbybursttime(struct process p[],int n)
{
    struct process temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].bt>p[j].bt){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
void calculatetimes(struct process p[],int n)
{
    int total_wt=0,total_tat=0;
    p[0].wt=0;
    p[0].tat=p[0].bt;
    for(int i=1;i<n;i++){
        p[i].wt=p[i-1].wt+p[i-1].bt;
        p[i].tat=p[i].wt+p[i].bt;
        total_wt+=p[i].wt;
        total_tat+=p[i].tat;
    }
    printf("\nprocess\tburst time\twaiting time\tturnaround time\n");
    for(int i=0;i<n;i++)
	{
        printf("p%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
    }
    printf("\naverage waiting time: %.2f\n",(float)total_wt/n);
    printf("average turnaround time: %.2f\n",(float)total_tat/n);
}
int main()
{
    int n;
    printf("enter number of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++)
	{
        p[i].pid=i+1;
        printf("enter burst time for process p%d: ",p[i].pid);
        scanf("%d",&p[i].bt);
    }
    sortbybursttime(p,n);
    calculatetimes(p,n);
    return 0;
}
