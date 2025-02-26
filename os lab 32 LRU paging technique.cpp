#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
int findLRU(int time[],int frames)
{
int i,min=time[0],pos=0;
for(i=1;i<frames;i++)
{
if(time[i]<min)
{
min=time[i];
pos=i;
}
}
return pos;
}
void lruPageReplacement(int pages[],int n,int frames)
{
int frame[MAX_FRAMES],time[MAX_FRAMES],pageFaults=0,counter=0;
int i,j,pos,found;
for(i=0;i<frames;i++)
{
frame[i]=-1;
}
for(i=0;i<n;i++)
{
found=0;
for(j=0;j<frames;j++)
{
if(frame[j]==pages[i])
{
found=1;
time[j]=counter++;
break;
}
}
if(!found)
{
if(i<frames)
{
pos=i;
}
else
{
pos=findLRU(time,frames);
}
frame[pos]=pages[i];
time[pos]=counter++;
pageFaults++;
}
printf("Frames: ");
for(j=0;j<frames;j++)
{
if(frame[j]!=-1)
{
printf("%d ",frame[j]);
}
else
{
printf("- ");
}
}
printf("\n");
}
printf("Total Page Faults: %d\n",pageFaults);
}
int main()
{
int pages[MAX_PAGES],n,frames,i;
printf("Enter number of pages: ");
scanf("%d",&n);
printf("Enter page reference string: ");
for(i=0;i<n;i++)
{
scanf("%d",&pages[i]);
}
printf("Enter number of frames: ");
scanf("%d",&frames);
lruPageReplacement(pages,n,frames);
return 0;
}
