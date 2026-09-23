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
        printf("PABLO\n");
        
    }else{
        pid_hijo= wait(NULL);
        printf("Mi pid es: pid=%d \n", getpid());
        printf("Mi hijo tiene como pdi pid=%d\n",pid_hijo);
        
    }

    

}
