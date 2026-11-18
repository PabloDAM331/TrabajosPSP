#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO1 "/tmp/FIFO1"
#define FIFO2 "/tmp/FIFO2"

void main() {
    int fd_lectura, fd_escritura;
    char buffer[50];
    float numero_recibido;
    float resultado = 1.0;

    
    printf("[fifo12] Esperando número por FIFO1...\n");
    fd_lectura = open(FIFO1, O_RDONLY);
    
    read(fd_lectura, buffer, sizeof(buffer));
    close(fd_lectura);

    
    numero_recibido = atof(buffer);
    printf("[fifo12] He recibido el número: %.0f\n", numero_recibido);

    
    if (numero_recibido == 0) {
        resultado = 1.0;
    } else {
        for (int i = 1; i <= (int)numero_recibido; i++) {
            resultado *= i;
        }
    }

   
    sprintf(buffer, "%.0f", resultado); 

    printf("[fifo12] Abriendo FIFO2 para enviar respuesta...\n");
    fd_escritura = open(FIFO2, O_WRONLY); 
    write(fd_escritura, buffer, strlen(buffer) + 1);
    close(fd_escritura);

    printf("[fifo12] Respuesta enviada. Saliendo.\n");

    exit (0);
}