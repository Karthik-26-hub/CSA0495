#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
void listFiles(const char *path)
{
struct dirent *entry;
DIR *dir=opendir(path);
if(dir==NULL)
{
printf("Could not open directory %s\n",path);
return;
}
while((entry=readdir(dir))!=NULL)
{
printf("%s\n",entry->d_name);
}
closedir(dir);
}
int main(int argc,char *argv[])
{
const char *path=(argc>1)?argv[1]:".";
listFiles(path);
return 0;
}
