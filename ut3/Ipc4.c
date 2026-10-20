#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void main(){
    int pipe1 [2];
    int pipe2 [2];
    pipe(pipe1);
    pipe(pipe2);
    pid_t pid2 = fork();
    if(pid2==0){
        close(pipe1[1]); 
        close(pipe2[0]); 

        int numero;
        
        read(pipe1[0], &numero, sizeof(numero));

        
         int resultado = 1;
        for (int i = 1; i <= numero; i++) {
            resultado *= i;
        }

       
        write(pipe2[1], &resultado, sizeof(resultado));

        
        close(pipe1[0]);
        close(pipe2[1]);
       
    }else{
        close(pipe1[0]); 
        close(pipe2[1]); 

        int numero = rand() % 11;

        
        write(pipe1[1], &numero, sizeof(numero));
        printf("El proceso padre genera el numero %d en el pipe1\n", numero);

       
         int resultado;
        read(pipe2[0], &resultado, sizeof(resultado));

        
        printf("El factorial calculado por el proceso hijo: %d != %llu\n", numero, resultado);

       
        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
    }

     exit(0);
}