#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t pid2,pid3;
    pid2=fork();
    if(pid2<0){
        printf("Error");
        exit(EXIT_FAILURE);
    }
    if(pid2==0){
        pid3=fork();
        if(pid3==0){
            printf("mi pid es: pid=%d, el pid de mi padre es: ppid=%d soy el proceso 3 P3\n", getpid(), getppid());
            exit(0);
        }else{
            wait(NULL);
            printf("Mi pid es: pid=%d y el de mi padre es: ppid=%d y soy el proceso 2 P2 \n", getpid(),getppid() );
            exit(0);
        }
        
    }else{
       pid2= wait(NULL);
        printf("Mi pid es: pid=%d y el de mi hijo es: pid=%d y soy el proceso 1 P1\n", getpid(), pid2 );
        
    }

    exit(0);

}