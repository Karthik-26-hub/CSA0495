#include<stdio.h>
#include<stdlib.h>
void createFile(const char *filename)
{
FILE *file=fopen(filename,"w");
if(file==NULL)
{
printf("Error creating file!\n");
return;
}
printf("File '%s' created successfully.\n",filename);
fclose(file);
}
void writeFile(const char *filename)
{
FILE *file=fopen(filename,"w");
if(file==NULL)
{
printf("Error opening file for writing!\n");
return;
}
printf("Enter text to write to the file: ");
char text[1000];
getchar();
fgets(text,sizeof(text),stdin);
fprintf(file,"%s",text);
printf("Data written successfully.\n");
fclose(file);
}
void readFile(const char *filename)
{
FILE *file=fopen(filename,"r");
if(file==NULL)
{
printf("Error opening file for reading!\n");
return;
}
printf("Contents of '%s':\n",filename);
char ch;
while((ch=fgetc(file))!=EOF)
{
putchar(ch);
}
printf("\n");
fclose(file);
}
void deleteFile(const char *filename)
{
if(remove(filename)==0)
{
printf("File '%s' deleted successfully.\n",filename);
}
else
{
printf("Error deleting file.\n");
}
}
int main()
{
int choice;
char filename[100];
while(1)
{
printf("\nFile Management System\n");
printf("1. Create File\n");
printf("2. Write to File\n");
printf("3. Read from File\n");
printf("4. Delete File\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
if(choice==5)break;
printf("Enter filename: ");
scanf("%s",filename);
switch(choice)
{
case 1:
	createFile(filename);
	break;
case 2:
	writeFile(filename);
	break;
case 3:
	readFile(filename);
	break;
case 4:
	deleteFile(filename);
	break;
default:
	printf("Invalid choice!\n");
}
}
return 0;
}
