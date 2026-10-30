#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void main(){                                   
pid_t p2, p3;

int pipe1[2];
int pipe2[2];
int pipe3[2];
int pipe4[2];

pipe(pipe1);
pipe(pipe2);
pipe(pipe3);
pipe(pipe4);

float num1;
float num2;
printf("Introduce dos numeros\n");
scanf("%f", &num1);
scanf("%f", &num2);

    p2=fork();

if(p2==0){
close(pipe1[1]);
close(pipe2[0]); close(pipe2[1]);             
close(pipe4[0]); close(pipe4[1]);             
float valores[2];
read(pipe1[0], &valores, sizeof(valores));
close(pipe1[0]);
float suma = valores[0]+valores[1];

close (pipe3[0]);
write (pipe3[1], &suma, sizeof(suma));
close(pipe3[1]);
exit(0);                                     

    }else{
        p3=fork();
if(p3==0){

close(pipe1[0]); close(pipe1[1]);            
close(pipe3[0]); close(pipe3[1]);             



close(pipe2[1]);
float valores[2];
read(pipe2[0], &valores, sizeof(valores));
close(pipe2[0]);
float producto  = valores[0]*valores[1];

close(pipe4[0]);
write(pipe4[1], &producto, sizeof(producto));
close(pipe4[1]);
exit(0);                                      

        }else{


close(pipe1[0]);
close(pipe2[0]);

write(pipe1[1], &num1, sizeof(num1));
write(pipe1[1], &num2, sizeof(num2));
close(pipe1[1]);

write(pipe2[1], &num1, sizeof(num1));
write(pipe2[1], &num2, sizeof(num2));
close(pipe2[1]);

close(pipe3[1]);
float valor_suma;
read(pipe3[0], &valor_suma, sizeof(valor_suma));
close(pipe3[0]);

printf("La suma de estos 2 numero son: %f\n", valor_suma);

close(pipe4[1]);
float valor_producto;
read(pipe4[0], &valor_producto, sizeof(valor_producto));
close(pipe4[0]);

printf("El producto de estos 2 numeros son: %f\n", valor_producto);

wait(NULL);
wait(NULL);                                  
        }
    }

exit(0);                                     
}