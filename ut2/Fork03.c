#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid_p2, pid_p3, pid_p4, pid_p5, pid_p6;
    pid_t abuelo;

   

    pid_p2 = fork();

    if (pid_p2 != 0) {
       abuelo=getppid();
        wait(NULL);
         printf("P1 PID=%d PPID=%d \n", getpid(), getppid());
    }
    else {
        
        printf("P2 PID=%d PPID=%d Abuelo=%d\n", getpid(), getppid(), abuelo);

        abuelo = getppid();   

        pid_p3 = fork();

        if (pid_p3 != 0) {
           
            pid_p4 = fork();

            if (pid_p4 != 0) {
                
                wait(NULL);
                wait(NULL);
            }
            else {
                
                printf("P4 PID=%d PPID=%d Abuelo=%d\n",getpid(), getppid(), abuelo);

                abuelo = getppid();   

                pid_p6 = fork();

                if (pid_p6 != 0) {
                   
                    wait(NULL);
                }
                else {
                    
                    printf("P6 PID=%d PPID=%d Abuelo=%d\n",getpid(), getppid(), abuelo);
                }
            }
        }
        else {
            
            printf("P3 PID=%d PPID=%d Abuelo=%d\n",getpid(), getppid(), abuelo);

            abuelo = getppid();   

            pid_p5 = fork();

            if (pid_p5 != 0) {
               
                wait(NULL);
            }
            else {
                
                printf("P5 PID=%d PPID=%d Abuelo=%d\n",getpid(), getppid(), abuelo);
            }
        }
    }

    exit(0);
}