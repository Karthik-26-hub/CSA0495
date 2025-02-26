#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void grepFile(const char *filename,const char *keyword)
{
	FILE *file=fopen(filename,"r");
	if(file==NULL)
	{
		perror("Error opening file");
	return;
	}
	char line[1024];
	int lineNumber=1;
	while(fgets(line,sizeof(line),file))
	{
		if(strstr(line,keyword))
		{
			printf("%d: %s",lineNumber,line);
		}
	lineNumber++;
	}
	fclose(file);
}
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"Usage: %s <keyword> <filename>\n",argv[0]);
	return EXIT_FAILURE;
	}
grepFile(argv[2],argv[1]);
return EXIT_SUCCESS;
}
