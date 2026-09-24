#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
if (pid == 0) {
printf("Soy el hijo\n");
} else {
printf("Soy el padre\n");
}
printf("Fin\n");
}

/*
1. Al principio solo existe el proceso padre después del fork va a nacer un proceso hijo. Por lo cual va haber 2 procesos

2. El proceso padre va ejecutar el prinf soy el padre, print del inicio, el fork la linea del if el print de soy el padre y el print del final.
 Y el hijo va a ejecutar el if, el print de despues del fork , print soy hijo y print final. 

3. El mensaje de inicio va a aparcer una vez y lo va a ejecutar el padre. El segundo print lo van a ejcutar el padre y el hijo 
por lo que va a salir por pantalla dos veces. El cuarto print lo va a ejecutar el hijo y el quito el padre y los que pueden aparecer
en distinto orden son los print que paarecen dentro del if.
*/
