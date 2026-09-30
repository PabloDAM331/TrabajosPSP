#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t p2, p3, p4;

    p2=fork();
    if(p2==0){
       printf("P2 ha empezado\n");
       sleep(5);   
        printf("P2 ha terminado\n");
    }else{
        p3=fork();

        if(p3==0){
            printf("P3 ha empezado\n");
            sleep(2);
            printf("P3 ha terminado\n");
        }else{

            p4=fork();
            if (p4==0){
                printf("P4 ha empezado\n");
                sleep(4);
                printf("P4 ha terminado\n");
            }
            
        }
    }
    exit(0);
}
/*
a) Si el P3 va a terminar antes ya que es el que menos segundos de espera tiene.
b) Sería totalmente impredecible.

*/