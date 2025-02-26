#include<stdio.h>
#include<stdlib.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
void fifoPageReplacement(int pages[],int n,int frames)
{
	int queue[MAX_FRAMES],front=0,rear=0,count=0,pageFaults=0;
	int i,j,found;
	for(i=0;i<frames;i++)
	{
		queue[i]=-1;
	}
for(i=0;i<n;i++)
{
found=0;
for(j=0;j<frames;j++)
{
if(queue[j]==pages[i])
{
found=1;
break;
}
}
if(!found)
{
queue[rear]=pages[i];
rear=(rear+1)%frames;
if(count<frames)
{
count++;
}
pageFaults++;
}
printf("Frames: ");
for(j=0;j<count;j++)
{
printf("%d ",queue[j]);
}
printf("\n");
}
printf("Total Page Faults: %d\n",pageFaults);
}
int main(){
int pages[MAX_PAGES],n,frames,i;
printf("Enter number of pages: ");
scanf("%d",&n);
printf("Enter page reference string: ");
for(i=0;i<n;i++){
scanf("%d",&pages[i]);
}
printf("Enter number of frames: ");
scanf("%d",&frames);
fifoPageReplacement(pages,n,frames);
return 0;
}
