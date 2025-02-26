#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
int findOptimal(int pages[],int frame[],int n,int frames,int index){
int i,j,farthest=index,pos=-1;
for(i=0;i<frames;i++){
int found=0;
for(j=index;j<n;j++){
if(frame[i]==pages[j]){
if(j>farthest){
farthest=j;
pos=i;
}
found=1;
break;
}
}
if(!found){
return i;
}
}
return (pos==-1)?0:pos;
}
void optimalPageReplacement(int pages[],int n,int frames){
int frame[MAX_FRAMES],pageFaults=0;
int i,j,pos,found;
for(i=0;i<frames;i++){
frame[i]=-1;
}
for(i=0;i<n;i++){
found=0;
for(j=0;j<frames;j++){
if(frame[j]==pages[i]){
found=1;
break;
}
}
if(!found){
if(i<frames){
pos=i;
}else{
pos=findOptimal(pages,frame,n,frames,i+1);
}
frame[pos]=pages[i];
pageFaults++;
}
printf("Frames: ");
for(j=0;j<frames;j++){
if(frame[j]!=-1){
printf("%d ",frame[j]);
}else{
printf("- ");
}
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
optimalPageReplacement(pages,n,frames);
return 0;
}
