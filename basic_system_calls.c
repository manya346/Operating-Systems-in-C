#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>
#include <sys/wait.h>
int main() {
int sz;
char *c = (char*)calloc(100,sizeof(char));
char *c1 = (char*)calloc(100,sizeof(char));
int fd = open("file.txt", O_RDWR);
if(fd<0){
 perror("open");
 exit(1);
}
printf("File opened successfully.\n");
lseek(fd, 15, SEEK_CUR);
printf("This program will sleep for 3 secs.\n");
sleep(3);
printf("The program is now awake and will proceed.");
sz = read(fd, c, 60);
printf("Called read(%d, c, 60). Returned that %d bytes were read.\n",fd,sz);
c[sz] = '\0';
printf("Those bytes are as follows: %s \n", c);
sz = write(fd, "this is an added text", strlen("this is an added text"));
printf("Called write(%d, \"this is an added text\", %ld). It returned %d\n", fd,
strlen("this is an added text"), sz);
pid_t p = fork();
printf("Edited\n");
wait(NULL);
//printf("Terminating child process.\n");
fork();
printf("Also edited\n");
//wait(NULL);
fork();
printf("hello\n");
//wait(NULL);
printf("Parent pid = %d\n", getpid());
printf("Process id(pid) = %d \n",getpid());
printf("Child pid = %d\n", p);
execlp("ls", "ls", "-l", NULL);
//wait(NULL);
//printf("STOPPED.");
return 0;
}
