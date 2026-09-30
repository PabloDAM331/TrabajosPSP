#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void main()
{
printf("CCC \n");
if (fork()!=0)
{
printf("AAA \n");
} else{
    printf("BBB \n");

} 
exit(0);
}
/*
a)
P1000---->P1001

b)
Pueden salir varias opciones, la primera: 
CCC
AAA
BBB
La segunda: 
CCC
BBB
AAA

Ya que como no hemos puesto nada para controlar los procesos no sabemos cuál se va a ejecutar primero.

c)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
printf("CCC \n");
if (fork()!=0)
{
    wait(NULL);
printf("AAA \n");
} else{
    printf("BBB \n");


} 
exit(0);
}

*/