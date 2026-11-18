#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define PIPE02 "/tmp/PIPE02"

int main() {
    int fd;
    char buffer[50];
    float numero_recibido;
    float resultado = 1.0;

    
    printf("[fifo22] Esperando número por PIPE02...\n");
    fd = open(PIPE02, O_RDONLY); 
    
    
    memset(buffer, 0, sizeof(buffer));
    read(fd, buffer, sizeof(buffer));
    close(fd);

    
    numero_recibido = atof(buffer);
    printf("[fifo22] He recibido el número: %.0f. Calculando factorial...\n", numero_recibido);

   
    if (numero_recibido == 0) {
        resultado = 1.0; 
    } else {
        for (int i = 1; i <= (int)numero_recibido; i++) {
            resultado *= i;
        }
    }

   
    sprintf(buffer, "%.0f", resultado); 

    
    printf("[fifo22] Abriendo PIPE02 para enviar la respuesta...\n");
    fd = open(PIPE02, O_WRONLY); 
    write(fd, buffer, strlen(buffer) + 1);
    close(fd);

    printf("[fifo22] Respuesta enviada. Saliendo.\n");

    return 0;
}