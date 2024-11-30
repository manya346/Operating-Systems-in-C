#include<stdio.h>
#include<unistd.h>

int main(){
    int childPipes[2], parentPipes[2];
    int returnStatus;
    char writeMessages[2][20] = { "Hello", "World"};
    char readMessage1[20];
    char readMessage2[20];
    returnStatus = pipe(parentPipes);
    if(returnStatus==1){
        printf("Unable to create pipe");
    }
    returnStatus = pipe(childPipes);
    if(returnStatus==1){
        printf("Unable to create pipe");
    }
    int pid = fork();
    if(pid!=0){
        close(parentPipes[0]);
        close(childPipes[1]);
        printf("Parent writing Message 1 to pipe: %s\n", writeMessages[0]);
        write(parentPipes[1], writeMessages[0], sizeof(writeMessages[0]));
        read(childPipes[0], readMessage1, sizeof(readMessage1));
        printf("Parent read message from pipe is: %s\n", readMessage1);
    } 
    else{
        close(parentPipes[1]);
        close(childPipes[0]);
        printf("Child writing Message 1 to pipe: %s\n", writeMessages[1]);
        write(childPipes[1], writeMessages[1], sizeof(writeMessages[1]));
        read(parentPipes[0], readMessage2, sizeof(readMessage2));
        printf("Child read message from pipe is: %s\n", readMessage2);
    }
}
