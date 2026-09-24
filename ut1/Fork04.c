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
     printf("Proceso P2 finalizado\n");
        exit(0);
}
  pid2 = fork();

    if(pid2==0){
            printf("soy p3 y mi pid es pid=%d y mi ppid es ppid=%d\n", getpid(), getppid());
            sleep(1);
             printf("Proceso P3 finalizado\n");
            exit(0);
    }
wait(NULL);
wait(NULL);
printf("Todos mis hijos han terminado\n");

exit(0);

}