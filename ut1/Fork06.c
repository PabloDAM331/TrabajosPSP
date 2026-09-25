#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

pid_t pid2, pid3;

pid2=fork();
if(pid2<0){
    printf("Error");
    exit(EXIT_FAILURE);
}
if(pid2==0){
    sleep(10);
    printf("Despierto\n");
    exit(0);
}else{
    pid3=fork();
    if(pid3==0){
        printf("Mi pid es: %d y el pid de mi padre es %d\n", getpid(), getppid());
    }else{
        wait(NULL);
        wait(NULL);
        printf("Soy el proceso padre este es mi pid: %d \n", getpid());
    }


}


}