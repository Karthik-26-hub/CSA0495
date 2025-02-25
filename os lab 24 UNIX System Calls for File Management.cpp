#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd;
    char buffer[100];
    fd=open("testfile.txt",O_CREAT|O_RDWR,0644);
    if(fd==-1)
	{
        printf("Error opening file\n");
        return 1;
    }
    write(fd,"Hello,UNIX System Calls!",25);
    lseek(fd,0,SEEK_SET);
    read(fd,buffer,25);
    buffer[25]='\0';
    printf("File content: %s\n", buffer);
    close(fd);
    return 0;
}
