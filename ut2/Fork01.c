#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t p2,p3,p4;
    p2=fork();
    if(p2==0){
        if(getpid()%2==0){
            printf("P2 PID= %d  y su padre es: %d\n", getpid(), getppid());
        }else{
            printf("P2 PID= %d \n", getpid());
        }

    }else{
        p3=fork();
        if(p3==0){
            p4=fork();
            if(p4==0){
                if(getpid()%2==0){
                    printf("P4 PID= %d  y su padre es: %d\n", getpid(), getppid());
                }else{
                    printf("P4 PID= %d  \n", getpid());
                }
            }else{
                wait(NULL);
                if(getpid()%2==0){
                    printf("P3 PID= %d  y su padre es: %d\n", getpid(), getppid());
                }else{
                    printf("P3 PID= %d  \n", getpid());
                }
            }
        }else{
            wait(NULL);
            wait(NULL);
            if(getpid()%2==0){
                printf("P1 PID= %d  y su padre es: %d\n", getpid(), getppid());
            }else{
                printf("P1 PID= %d  \n", getpid());
            }
        }
    }
    exit(0);
}

/*
a) Se los unicos que puedes tener dudas de quien se ejecuta primero es p4 o p2 pero los demoas seria p4-p2-p3-p1 o p2-p4-p3-p1
*/