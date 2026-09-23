#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main (){

    pid_t pid, pid_hijo;
    pid=fork();
    if(pid==-1){
    printf("Hubo un problema al crear el proceduimiento hijo");
    }

    if(pid==0){
        pid_hijo=getpid();
        printf("Soy el proceso HIJO\n");
        printf("Mi pid es: pid=%d\n", getpid());
        printf("El pid de mi padre es: ppid=%d\n", getppid());

    }else{
        pid= wait(NULL);
        printf("Soy el proceso Padre\n");
        printf("Mi pid es: pid=%d \n", getpid());
        printf("Mi hijo tiene como pdi pid=%d\n",pid_hijo);
        printf("El proceso hijo ha terminado");
    }

    

}