#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
void *shm;
char buff[100];
int shmid;
shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
//shm key = 1234, shm size = 1024, 0666 is permission mode, IPC_CREAT
creates a new shm if one does not exist
printf("Key of shared memory is %d\n", shmid);
shm = shmat(shmid, NULL, 0);
printf("Process is attached at %p\n", shm);
strcpy(buff, "Hello World, I am Manya");
strcpy((char*)shm, buff);
printf("Data in shared memory is: %s\n", (char*)shm);
}
