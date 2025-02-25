#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t rw_mutex, mutex;
int read_count=0,data=0;
void *writer(void *arg) {
    int id=*(int *)arg;
    sem_wait(&rw_mutex);
    data++;
    printf("Writer %d wrote data: %d\n", id, data);
    sem_post(&rw_mutex);
    return NULL;
}
void *reader(void *arg) {
    int id=*(int *)arg;
    sem_wait(&mutex);
    read_count++;
    if (read_count==1)
        sem_wait(&rw_mutex);
    sem_post(&mutex);
    printf("Reader %d read data: %d\n",id,data);
    sem_wait(&mutex);
    read_count--;
    if(read_count==0)
        sem_post(&rw_mutex);
    sem_post(&mutex);
    return NULL;
}
int main()
{
    pthread_t r[5],w[3];
    int i,id[5]={1,2,3,4,5};
    sem_init(&rw_mutex,0,1);
    sem_init(&mutex,0,1);
    for(i=0;i<3;i++)
        pthread_create(&w[i],NULL,writer,&id[i]);
    for(i=0;i<5;i++)
        pthread_create(&r[i],NULL,reader,&id[i]);
    for(i=0;i<3;i++)
        pthread_join(w[i], NULL);
    for(i=0;i<5;i++)
        pthread_join(r[i], NULL);
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    return 0;
}
