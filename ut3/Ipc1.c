#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void main(){
    pid_t p2;
     int fd[2];
     pipe(fd);
    p2=fork();
    if(p2==0){
        ssize_t n;
        close(fd[1]);
        char buffer [100];
        n=read(fd[0], &buffer, sizeof(buffer)-1);
        printf("Hijo a recibido %s\n", buffer);
        close(fd[0]);

    }else{
        close(fd[0]);
        time_t hora;
        time(&hora);
        char *fecha = ctime(&hora);
    
        write (fd[1], fecha, strlen(fecha)+1);
        close(fd[1]);
        wait(NULL);
    }
}



