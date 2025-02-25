#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<io.h>
#include<direct.h>
int main()
{
    HANDLE hFile;
    DWORD bytesRead,bytesWritten;
    char buffer[100];
    hFile=CreateFile("test.txt",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
    if(hFile==INVALID_HANDLE_VALUE)
	{
        printf("Error opening file\n");
        return 1;
    }
    WriteFile(hFile,"Hello,Windows I/O!",19,&bytesWritten,NULL);
    SetFilePointer(hFile,0,NULL,FILE_BEGIN);
    ReadFile(hFile,buffer,19,&bytesRead,NULL);
    buffer[bytesRead]='\0';
    printf("Read from file:%s\n",buffer);
    DWORD fileSize=GetFileSize(hFile,NULL);
    printf("File size:%ld bytes\n",fileSize);
    CloseHandle(hFile);
    printf("\nContents of current directory:\n");
    WIN32_FIND_DATA findFileData;
    HANDLE hFind=FindFirstFile("*.*",&findFileData);
    if(hFind==INVALID_HANDLE_VALUE)
	{
        printf("Error opening directory\n");
        return 1;
    }
    else
	{
        do
		{
            printf("%s\n",findFileData.cFileName);
        }while(FindNextFile(hFind,&findFileData)!=0);
        FindClose(hFind);
    }
    return 0;
}
