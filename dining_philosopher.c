#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define N 5
sem_t forks[N];

void *philosopher(void *arg){
  int id = (int)arg;
  while(1){
    printf("Philosopher %d is thinking\n", id);
    sleep(1);
    sem_wait(&forks[id]);
    sem_wait(&forks[(id+1)%N]);
    printf("Philosopher %d is eating\n", id);
    sleep(2);
    sem_post(&forks[id]);
    sem_post(&forks[(id+1)%N]);
    printf("Philosopher %d is done eating\n", id);
  }
}

int main(){
  pthread_t philosophers[N];
  int ids[N];
  for(int i=0; i<N; i++){
    sem_init(&forks[i], 0, 1);
    ids[i] = i;
  }
  for(int i=0;i<N;i++){
    pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
  }
  for(int i=0;i<N;i++){
    pthread_join(philosophers[i], NULL);
  }
}
