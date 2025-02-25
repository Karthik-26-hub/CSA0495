#include<stdio.h>
#include<string.h>
#define MAX_FILES 100
#define NAME_SIZE 50
typedef struct
{
char name[NAME_SIZE];int in_use;
}File;
File directory[MAX_FILES];
void createFile()
{
    char filename[NAME_SIZE];
    printf("Enter file name: ");
	scanf("%s",filename);
    for(int i=0;i<MAX_FILES;i++)
        if(directory[i].in_use&&strcmp(directory[i].name,filename)==0)
		{
            printf("Error: File exists!\n");
            return;
        }
    for(int i=0;i<MAX_FILES;i++)
        if(!directory[i].in_use)
		{
            strcpy(directory[i].name,filename);
            directory[i].in_use=1;
            printf("File '%s' created.\n",filename);
            return;
        }
    printf("Error: Directory full!\n");
}
void deleteFile()
{
    char filename[NAME_SIZE];
    printf("Enter file name: ");scanf("%s",filename);
    for(int i=0;i<MAX_FILES;i++)
        if(directory[i].in_use&&strcmp(directory[i].name,filename)==0)
		{
            directory[i].in_use=0;
            printf("File '%s' deleted.\n",filename);
            return;
        }
    printf("Error: File not found!\n");
}
void searchFile()
{
    char filename[NAME_SIZE];
    printf("Enter file name: ");scanf("%s",filename);
    for(int i=0;i<MAX_FILES;i++)
        if(directory[i].in_use&&strcmp(directory[i].name,filename)==0){
            printf("File '%s' found.\n",filename);
            return;
        }
    printf("File not found!\n");
}
void displayFiles()
{
    printf("Files:\n");
    int found=0;
    for(int i=0;i<MAX_FILES;i++)
        if(directory[i].in_use)
		{
            printf("- %s\n",directory[i].name);
            found=1;
        }
    if(!found)printf("Directory empty.\n");
}
int main()
{
    int choice;
    while(1)
	{
        printf("\n1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:createFile();break;
            case 2:deleteFile();break;
            case 3:searchFile();break;
            case 4:displayFiles();break;
            case 5:return 0;
            default:printf("Invalid choice!\n");
        }
    }
}
