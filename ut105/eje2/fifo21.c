#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define PIPE02 "/tmp/PIPE02"

int main() {
    int fd;
    time_t t;
    float numero;
    char texto[50];
    char buffer_respuesta[50];

    unlink(PIPE02);
    mkfifo(PIPE02, 0666);

    srand((unsigned)time(&t));
    numero = rand() % 11; 
    
    sprintf(texto, "%f", numero);
    printf("[fifo21] Número aleatorio generado: %.0f\n", numero);

    printf("[fifo21] Abriendo PIPE02 para enviar el número...\n");
    fd = open(PIPE02, O_WRONLY); 
    write(fd, texto, strlen(texto) + 1);
    close(fd);

    
    printf("[fifo21] Esperando el resultado del factorial...\n");
    fd = open(PIPE02, O_RDONLY); 
    read(fd, buffer_respuesta, sizeof(buffer_respuesta));
    close(fd);

    
    printf("[fifo21]  El factorial de %.0f es: %s\n", numero, buffer_respuesta);


    unlink(PIPE02);
    printf("[fifo21] Pipe eliminado. Saliendo.\n");

    return 0;
}