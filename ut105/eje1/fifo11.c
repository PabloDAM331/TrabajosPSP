#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define FIFO1 "/tmp/FIFO1"
#define FIFO2 "/tmp/FIFO2"

int main() {
    int fd_envio, fd_respuesta;
    char buffer[50];
    float numero;

    unlink(FIFO1);
    unlink(FIFO2);
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    srand((unsigned)time(NULL));
    numero = (float)(rand() % 11); 
    printf("[fifo11] Número generado: %.0f\n", numero);

    
    sprintf(buffer, "%f", numero);
    
    printf("[fifo11] Abriendo FIFO1 para enviar...\n");
    fd_envio = open(FIFO1, O_WRONLY); 
    write(fd_envio, buffer, strlen(buffer) + 1);
    close(fd_envio);

    
    printf("[fifo11] Esperando respuesta por FIFO2...\n");
    fd_respuesta = open(FIFO2, O_RDONLY); 
    
    read(fd_respuesta, buffer, sizeof(buffer));
    close(fd_respuesta);

    printf("[fifo11] El factorial de %.0f es: %s\n", numero, buffer);

    unlink(FIFO1);
    unlink(FIFO2);
    

    exit (0);
}