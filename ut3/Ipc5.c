#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p2;
    int pipe1[2]; 
    int pipe2[2]; 

    pipe(pipe1);
    pipe(pipe2);

    p2 = fork();

    if (p2 == 0) {
        
        close(pipe1[0]); 
        close(pipe2[1]); 

        int dni;
        printf("Escribe el numero del dni sin la letra: ");
        scanf("%i", &dni); 

       
        write(pipe1[1], &dni, sizeof(dni));
        close(pipe1[1]); 

        
        char letra_recibida;
        read(pipe2[0], &letra_recibida, sizeof(letra_recibida));
        
        printf("La letra del NIF es: %c\n", letra_recibida);
        
        close(pipe2[0]);

    } else {
       
        close(pipe1[1]);
        close(pipe2[0]); 

        char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        int dni_recibido;

        
        read(pipe1[0], &dni_recibido, sizeof(dni_recibido));
        close(pipe1[0]);

        
        int resto = dni_recibido % 23;
        char letra_calculada = letras[resto];

        
        write(pipe2[1], &letra_calculada, sizeof(letra_calculada));
        close(pipe2[1]);

        wait(NULL); 
    }

    exit(0);
}