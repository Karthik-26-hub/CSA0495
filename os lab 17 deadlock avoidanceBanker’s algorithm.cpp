#include<stdio.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3
int available[MAX_RESOURCES],maximum[MAX_PROCESSES][MAX_RESOURCES],allocation[MAX_PROCESSES][MAX_RESOURCES],need[MAX_PROCESSES][MAX_RESOURCES],safeSequence[MAX_PROCESSES],processCount,resourceCount;
void calculateNeed()
{
    for(int i=0;i<processCount;i++)
        for(int j=0;j<resourceCount;j++)
            need[i][j]=maximum[i][j]-allocation[i][j];
}
int isSafe()
{
    int work[MAX_RESOURCES],finish[MAX_PROCESSES]={0},safeIndex=0;
    for(int i=0;i<resourceCount;i++)
        work[i]=available[i];
    for(int count=0;count<processCount;count++)
	{
        int found=0;
        for(int i=0;i<processCount;i++)
		{
            if(!finish[i]){
                int canAllocate=1;
                for(int j=0;j<resourceCount;j++)
                    if(need[i][j]>work[j])
					{
                        canAllocate=0;
                        break;
                    }
                if(canAllocate)
				{
                    for(int j=0;j<resourceCount;j++)
                        work[j]+=allocation[i][j];
                    safeSequence[safeIndex++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found) return 0;
    }
    return 1;
}
void requestResources(int processID,int request[])
{
    for(int i=0;i<resourceCount;i++)
        if(request[i]>need[processID][i])
		{
            printf("Error: Exceeds maximum need!\n");
            return;
        }
    for(int i=0;i<resourceCount;i++)
        if(request[i]>available[i])
		{
            printf("Process %d must wait.\n",processID);
            return;
        }
    for(int i=0;i<resourceCount;i++)
	{
        available[i]-=request[i];
        allocation[processID][i]+=request[i];
        need[processID][i]-=request[i];
    }
    if(isSafe()) printf("Request granted.\n");
    else{
        for(int i=0;i<resourceCount;i++){
            available[i]+=request[i];
            allocation[processID][i]-=request[i];
            need[processID][i]+=request[i];
        }
        printf("Request denied.\n");
    }
}
void displayState()
{
    printf("\nProcess\tAllocation\tMax\t\tNeed\t\tAvailable\n");
    for(int i=0;i<processCount;i++){
        printf("%d\t",i);
        for(int j=0;j<resourceCount;j++) printf("%d ",allocation[i][j]);
        printf("\t\t");
        for(int j=0;j<resourceCount;j++) printf("%d ",maximum[i][j]);
        printf("\t\t");
        for(int j=0;j<resourceCount;j++) printf("%d ",need[i][j]);
        if(i==0){
            printf("\t\t");
            for(int j=0;j<resourceCount;j++) printf("%d ",available[j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter number of processes: ");
    scanf("%d",&processCount);
    printf("Enter number of resources: ");
    scanf("%d",&resourceCount);
    printf("Enter available resources: ");
    for(int i=0;i<resourceCount;i++)
        scanf("%d",&available[i]);
    printf("Enter Maximum resource matrix:\n");
    for(int i=0;i<processCount;i++)
        for(int j=0;j<resourceCount;j++)
            scanf("%d",&maximum[i][j]);
    printf("Enter Allocation matrix:\n");
    for(int i=0;i<processCount;i++)
        for(int j=0;j<resourceCount;j++)
            scanf("%d",&allocation[i][j]);
    calculateNeed();
    displayState();
    if(isSafe())
	{
        printf("\nSystem is in a SAFE state.\nSafe sequence: ");
        for(int i=0;i<processCount;i++)
            printf("P%d ",safeSequence[i]);
        printf("\n");
    }else{
        printf("\nSystem is in an UNSAFE state!\n");
    }
    int processID,request[MAX_RESOURCES];
    printf("\nEnter process ID making a request: ");
    scanf("%d",&processID);
    printf("Enter resource request: ");
    for(int i=0;i<resourceCount;i++)
        scanf("%d",&request[i]);
    requestResources(processID,request);
    displayState();
    return 0;
}
