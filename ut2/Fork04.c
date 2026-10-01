#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid_p2, pid_p3, pid_p4, pid_p5;
    int acumulado;

    acumulado = getpid();   
    printf("P1 PID=%d  acumulado=%d\n", getpid(), acumulado);

    pid_p2 = fork();

    if (pid_p2 == 0) {
        
        if (getpid() % 2 == 0)
            printf("P2 PID=%d  acumulado=%d\n", getpid(), acumulado + 10);
        else
            printf("P2 PID=%d  acumulado=%d\n", getpid(), acumulado - 100);

        
        acumulado = getpid();

        pid_p5 = fork();

        if (pid_p5 == 0) {
            
            if (getpid() % 2 == 0)
                printf("P5 PID=%d  acumulado=%d\n", getpid(), acumulado + 10);
            else
                printf("P5 PID=%d  acumulado=%d\n", getpid(), acumulado - 100);
        }
        else {
            
            wait(NULL);
        }
    }
    else {
        
        pid_p3 = fork();

        if (pid_p3 == 0) {
            
            if (getpid() % 2 == 0)
                printf("P3 PID=%d  acumulado=%d\n", getpid(), acumulado + 10);
            else
                printf("P3 PID=%d  acumulado=%d\n", getpid(), acumulado - 100);

            
            acumulado = getpid();

            pid_p4 = fork();

            if (pid_p4 == 0) {
                
                if (getpid() % 2 == 0)
                    printf("P4 PID=%d  acumulado=%d\n", getpid(), acumulado + 10);
                else
                    printf("P4 PID=%d  acumulado=%d\n", getpid(), acumulado - 100);
            }
            else {
               
                wait(NULL);
            }
        }
        else {
            
            wait(NULL);
            wait(NULL);
            printf("P1 Todos los hijos terminaron.\n");
        }
    }

    return 0;
}