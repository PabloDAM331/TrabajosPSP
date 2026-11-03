#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
pid_t p2, p3;

int pipe1[2];
int pipe2[2];
int pipe3[2];
int pipe4[2];

pipe(pipe1);
pipe(pipe2);
pipe(pipe3);
pipe(pipe4);

float notas[10];
for (int i = 0; i < 10; i++) {
do {
printf("Introduce la nota del alumno %d (0-10): ", i + 1);
scanf("%f", &notas[i]);
if (notas[i] < 0 || notas[i] > 10) {
printf("Nota no valida, debe estar entre 0 y 10\n");
}
} while (notas[i] < 0 || notas[i] > 10);
}

p2 = fork();

if (p2 == 0) {
close(pipe1[0]);
close(pipe2[0]); close(pipe2[1]);
close(pipe3[1]);
close(pipe4[0]); close(pipe4[1]);

float recibidas[10];
read(pipe3[0], recibidas, sizeof(recibidas));
close(pipe3[0]);

float suma = 0, maxima = recibidas[0];
for (int i = 0; i < 10; i++) {
suma += recibidas[i];
if (recibidas[i] > maxima) {
maxima = recibidas[i];
}
}

float resultado[2];
resultado[0] = suma / 10;
resultado[1] = maxima;

write(pipe1[1], resultado, sizeof(resultado));
close(pipe1[1]);

} else {
p3 = fork();

if (p3 == 0) {
close(pipe1[0]); close(pipe1[1]);
close(pipe2[0]);
close(pipe3[0]); close(pipe3[1]);
close(pipe4[1]);

float recibidas[10];
read(pipe4[0], recibidas, sizeof(recibidas));
close(pipe4[0]);

int aprobados = 0, suspensos = 0;
for (int i = 0; i < 10; i++) {
if (recibidas[i] >= 5) {
aprobados++;
} else {
suspensos++;
}
}

int resultado[2];
resultado[0] = aprobados;
resultado[1] = suspensos;

write(pipe2[1], resultado, sizeof(resultado));
close(pipe2[1]);

} else {
close(pipe1[1]);
close(pipe2[1]);
close(pipe3[0]);
close(pipe4[0]);

write(pipe3[1], notas, sizeof(notas));
write(pipe4[1], notas, sizeof(notas));
close(pipe3[1]);
close(pipe4[1]);

float resP2[2];
int resP3[2];
read(pipe1[0], resP2, sizeof(resP2));
read(pipe2[0], resP3, sizeof(resP3));
close(pipe1[0]);
close(pipe2[0]);

printf("\nNota media: %.2f\n", resP2[0]);
printf("Nota maxima: %.2f\n", resP2[1]);
printf("Aprobados: %d\n", resP3[0]);
printf("Suspensos: %d\n", resP3[1]);

wait(NULL);
wait(NULL);
}
}

exit(0);
}