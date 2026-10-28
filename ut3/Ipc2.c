#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p2;
    int fd[2];
    pipe(fd);
    p2 = fork();

    if (p2 == 0) {
        
        close(fd[1]); 

        int valor;
        int suma = 0;
        ssize_t n;

        while ((n = read(fd[0], &valor, sizeof(valor))) > 0) {
            
            if (valor == '+') {
                printf("Recibido carácter +\n");
                break; 
            }

            
            printf("Numero a sumar: %d\n", valor);
            suma += valor;
        }

        
        printf("La suma total es igual a: %d\n", suma);
        
        close(fd[0]); 

    } else {
       
        close(fd[0]); 

        int numero;
        char entrada[100];

        printf("Introduce números para sumar (escribe '+' para terminar):\n");

        
        while (1) {
            printf("Numero a sumar: ");
            scanf("%s", entrada); 
            if(entrada[0]=='+'){
                int fin=entrada[0];
                write(fd[1], &fin , sizeof(fin));
                break;
            }

            numero = atoi(entrada); 
            write(fd[1], &numero, sizeof(numero));
            
        }

        close(fd[1]); 
        wait(NULL);   
    }

    exit(0);
}