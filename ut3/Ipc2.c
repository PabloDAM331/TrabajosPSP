#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t p2;
    int fd[2];
    pipe(fd);
    p2 = fork();

    float num[] = {13, 56, 85};
    int n_elementos = sizeof(num) / sizeof(num[0]);  

    if (p2 == 0) {
        close(fd[1]);

        float valor;
        ssize_t n;
        int total = 0;
        float suma = 0;
        
        while ((n = read(fd[0], &valor, sizeof(valor))) > 0) {
            printf("Hijo recibió: %.2f\n", valor);
            suma += valor;
            total++;
        }

    
        printf("Hijo: %d números, suma = %.2f\n", total, suma);
        close(fd[0]);
        

    } else {
        close(fd[0]);

        for (int i = 0; i < n_elementos; i++) {
            write(fd[1], &num[i], sizeof(num[i]));
        }

        close(fd[1]);   
        wait(NULL);
      
    }
    exit(0);
}