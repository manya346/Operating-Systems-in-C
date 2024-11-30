#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *worker(void *data){
    char name = (char)data;
    for(int i=0; i<120; i++){
        usleep(500000);
        printf("Hi from thread %s\n", name);
    }
    printf("Thread %s is done\n", name);
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, worker, "X");
    pthread_create(&t2, NULL, worker, "Y");
    sleep(5);
    printf("Cancelling thread Y \n");
    pthread_cancel(t2);
    usleep(50000);
    printf("Cancelling thread X\n");
    pthread_cancel(t1);
    return 0;
}
