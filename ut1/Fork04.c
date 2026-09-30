#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
pid_t pid, pid2;

pid= fork();

if(pid<0){
exit(EXIT_FAILURE);
}

if(pid==0){
    printf("soy p2 y mi pid es pid=%d y mi ppid es ppid=%d\n", getpid(), getppid() );
    sleep(3);
    
        
}else{
        pid2 = fork();
        if(pid2==0){
                sleep(1);
                printf("Soy P3 Mi pid es: %d y mi ppid es %d \n",getpid(), getppid());
        }else{
                wait(NULL);
                wait(NULL);
                printf("Todos mis hijos han terminado, mi pid es: %d i el de mi padre es: %d\n", getpid(), getppid());

        }
}

exit(0);

}