#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *threadFunction(void *arg)
{
	printf("Thread %ld is running.\n",pthread_self());
	sleep(1);
	pthread_exit(NULL);
}
int main()
{
	pthread_t thread1,thread2;
	int status;
	status=pthread_create(&thread1,NULL,threadFunction,NULL);
	if(status)
	{
		printf("Error creating thread 1.\n");
		return 1;
	}
	status=pthread_create(&thread2,NULL,threadFunction,NULL);
	if(status)
	{
		printf("Error creating thread 2.\n");
		return 1;
	}
	if(pthread_equal(thread1,thread2))
	{
		printf("Threads are equal.\n");
	}
	else
	{
		printf("Threads are not equal.\n");
	}
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Threads have finished execution.\n");
	return 0;
}
