#include<stdio.h>
#include<string.h>
#define MAX_USERS 10
#define MAX_FILES 10
struct File
{
char name[20];
};
struct UserDirectory
{
char username[20];
struct File files[MAX_FILES];
int file_count;
};
struct UserDirectory directories[MAX_USERS];
int user_count=0;
void createUser()
{
    if(user_count>=MAX_USERS)
	{
	printf("Maximum user limit reached!\n");
	return;
	}
    printf("Enter username: ");scanf("%s",directories[user_count].username);
    directories[user_count].file_count=0;
    user_count++;
    printf("User directory created successfully!\n");
}
void addFile()
{
    char username[20],filename[20];
    printf("Enter username: ");scanf("%s",username);
    for(int i=0;i<user_count;i++)
	{
        if(strcmp(directories[i].username,username)==0)
		{
            if(directories[i].file_count>=MAX_FILES){printf("Maximum file limit reached!\n");return;}
            printf("Enter file name: ");
            scanf("%s",directories[i].files[directories[i].file_count].name);
            directories[i].file_count++;
            printf("File added successfully!\n");
            return;
        }
    }
    printf("User not found!\n");
}
void listFiles()
{
    char username[20];
    printf("Enter username: ");scanf("%s",username);
    for(int i=0;i<user_count;i++)
	{
        if(strcmp(directories[i].username,username)==0)
		{
            printf("Files in %s's directory:\n",username);
            if(directories[i].file_count==0)printf("No files found!\n");
            else for(int j=0;j<directories[i].file_count;j++)printf("%s\n",directories[i].files[j].name);
            return;
        }
    }
    printf("User not found!\n");
}
void deleteFile()
{
    char username[20],filename[20];
    printf("Enter username: ");scanf("%s",username);
    for(int i=0;i<user_count;i++)
	{
        if(strcmp(directories[i].username,username)==0)
		{
            printf("Enter file name to delete: ");scanf("%s",filename);
            for(int j=0;j<directories[i].file_count;j++)
			{
                if(strcmp(directories[i].files[j].name,filename)==0)
				{
                    for(int k=j;k<directories[i].file_count-1;k++)
                        strcpy(directories[i].files[k].name,directories[i].files[k+1].name);
                    directories[i].file_count--;
                    printf("File deleted successfully!\n");
                    return;
                }
            }
            printf("File not found!\n");
            return;
        }
    }
    printf("User not found!\n");
}
int main()
{
    int choice;
    while(1){
        printf("\nTwo-Level Directory System\n");
        printf("1. Create User Directory\n2. Add File to User Directory\n3. List Files in User Directory\n4. Delete File from User Directory\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:createUser();break;
            case 2:addFile();break;
            case 3:listFiles();break;
            case 4:deleteFile();break;
            case 5:return 0;
            default:printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
