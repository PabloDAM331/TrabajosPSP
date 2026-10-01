#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
pid_t p2,p3,p4;
p2=fork();
if(p2==0){
    p3=fork();
    if(p3==0){
        p4=fork();
        if(p4==0){
            printf("P4 pid= %d , ppid= %d suma pids= %d \n", getpid(), getppid(), (getpid()+getppid()));
        }else{
            wait(NULL);
            printf("P3 pid= %d , ppid= %d suma pids= %d \n", getpid(), getppid(), (getpid()+getppid()));
        }
    }else{
        wait(NULL);
            printf("P2 pid= %d , ppid= %d suma pids= %d \n", getpid(), getppid(), (getpid()+getppid()));
    }
}else{
    wait(NULL);
            printf("P1 pid= %d , ppid= %d suma pids= %d \n", getpid(), getppid(), (getpid()+getppid()));
}
}