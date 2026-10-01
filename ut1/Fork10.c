#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

pid_t p2, p3;
int resultado = 0;
int x, y, z;

p2=fork();

if(p2==0){
    
    for(int i=1;i<=100; i++ ){
        x = resultado;      // valor anterior
        resultado += i;
        printf("%d+%d=%d\n", x, i, resultado);
    }
    printf("PID= %d suma 1..100 resultado= %i\n", getpid(), resultado);

}else{
    p3=fork();
    if(p3==0){
        resultado = 0;
        for(int i=101;i<=200; i++ ){
            y = resultado;
            resultado += i;
            printf("%d+%d=%d\n", y, i, resultado);
        }
        printf("PID= %d suma 101..200 resultado=%i\n", getpid(), resultado);

    }else{
        wait(NULL);
        wait(NULL);
        printf("Todos los calculos han terminado\n");
    }
    
}

exit(0);
}