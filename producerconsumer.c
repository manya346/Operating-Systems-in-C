#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t empty, full, mutex;

void consumer(void vargp){
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
        printf("Consumer consuming from buffer \n");
        sleep(1);
        printf("consumer done consuming\n");
        sem_post(&mutex);
        sem_post(&empty);
    }
}

void *producer(void *vargp){
    while(1){
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("producer is producing\n");
        sleep(2);
        printf("producer is done\n");
        sem_post(&mutex);
        sem_post(&full);
    }
}

int main(){
    sem_init(&empty, 0, 3);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    printf("Before thread\n");
    pthread_t producer_id, consumer_id;
    pthread_create(&producer_id, NULL, producer, NULL);
    pthread_create(&consumer_id, NULL, consumer, NULL);
    pthread_join(consumer_id, NULL);
    pthread_join(producer_id, NULL);
    printf("After thread\n");
}
