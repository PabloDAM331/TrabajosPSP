#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void main() {
    pid_t p2;
    int fd[2];
    
    
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    p2 = fork();

    if (p2 == 0) {
        
        close(fd[0]); // El hijo no lee, cierra lectura

        
        int num1 = (rand() % 50) + 1;
        int num2 = (rand() % 50) + 1;

       
        write(fd[1], &num1, sizeof(num1));
        write(fd[1], &num2, sizeof(num2));

        close(fd[1]); 
       

    } else {
       
        close(fd[1]); 

        int num1, num2;
        
      
        read(fd[0], &num1, sizeof(num1));
        read(fd[0], &num2, sizeof(num2));

        close(fd[0]); 
        wait(NULL);   

        
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        printf("%d / %d = %d\n", num1, num2, num1 / num2);

        
    }
    exit(0);
}