#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex;
void *process(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Process %d is in the critical section\n",*(int*)arg);
    sleep(2);
    printf("Process %d is leaving the critical section\n",*(int*)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
int main()
{
    pthread_t t1,t2;
    int p1=1,p2=2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,process,&p1);
    pthread_create(&t2,NULL,process,&p2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
