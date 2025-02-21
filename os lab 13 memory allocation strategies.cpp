#include<stdio.h>
#define MAX 100
void firstFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)allocation[i]=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(blockSize[j]>=processSize[i])
			{
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
    printf("\nFirst Fit Allocation:\n");
    for(int i=0;i<n;i++)
        printf("Process %d (%d KB) -> %s\n",i+1,processSize[i],
               allocation[i]!=-1?"Block allocated":"Not allocated");
}
void bestFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)allocation[i]=-1;
    for(int i=0;i<n;i++)
	{
        int bestIdx=-1;
        for(int j=0;j<m;j++)
            if(blockSize[j]>=processSize[i])
                if(bestIdx==-1||blockSize[j]<blockSize[bestIdx])
                    bestIdx=j;
        if(bestIdx!=-1){
            allocation[i]=bestIdx;
            blockSize[bestIdx]-=processSize[i];
        }
    }
    printf("\nBest Fit Allocation:\n");
    for(int i=0;i<n;i++)
        printf("Process %d (%d KB) -> %s\n",i+1,processSize[i],
               allocation[i]!=-1?"Block allocated":"Not allocated");
}
void worstFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)allocation[i]=-1;
    for(int i=0;i<n;i++)
	{
        int worstIdx=-1;
        for(int j=0;j<m;j++)
            if(blockSize[j]>=processSize[i])
                if(worstIdx==-1||blockSize[j]>blockSize[worstIdx])
                    worstIdx=j;
        if(worstIdx!=-1)
		{
            allocation[i]=worstIdx;
            blockSize[worstIdx]-=processSize[i];
        }
    }
    printf("\nWorst Fit Allocation:\n");
    for(int i=0;i<n;i++)
        printf("Process %d (%d KB) -> %s\n",i+1,processSize[i],
               allocation[i]!=-1?"Block allocated":"Not allocated");
}
int main()
{
    int blockSize[MAX],processSize[MAX],m,n;
    printf("Enter number of memory blocks: ");scanf("%d",&m);
    printf("Enter sizes of %d memory blocks: ",m);
    for(int i=0;i<m;i++)scanf("%d",&blockSize[i]);
    printf("Enter number of processes: ");scanf("%d",&n);
    printf("Enter sizes of %d processes: ",n);
    for(int i=0;i<n;i++)scanf("%d",&processSize[i]);
    int blockCopy[MAX];
    for(int i=0;i<m;i++)blockCopy[i]=blockSize[i];
    firstFit(blockCopy,m,processSize,n);
    for(int i=0;i<m;i++)blockCopy[i]=blockSize[i];
    bestFit(blockCopy,m,processSize,n);
    for(int i=0;i<m;i++)blockCopy[i]=blockSize[i];
    worstFit(blockCopy,m,processSize,n);
    return 0;
}
