#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
void *shm;
char buff[100];
int shmid;
shmid=shmget((key_t)2345, 1024, 0666);
printf("Key of shared memory is %d\n",shmid);
shm =shmat(shmid,NULL,0);
printf("Process attached at %p\n",shm);
printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}
