#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
pid_t pid1, pid2;
printf("AAA \n");
pid1 = fork();
if (pid1==0)
{
printf("BBB \n");
}
else
{
pid2 = fork();
printf("CCC \n");
}
exit(0);
}

/*
a) P1000------->P1001
    |
    |
    v
    P1002

b) AAA      AAA
   BBB  o   CCC
   CCC      CCC
   CCC      BBB

   Ya que no controlamos los procesos mediante un wait por lo cual no sabemos cual se va a ejecutar primero.

c)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    printf("AAA \n");

    pid1 = fork();
    if (pid1 == 0)
    {
        
        printf("BBB \n");
                        
    }
    else
    {
        
        pid2 = fork();
        if (pid2 == 0)
        {
            
            printf("CCC \n");
                       
        }
        else
        {
           
            wait(NULL);         
            wait(NULL);         
            printf("CCC \n");    
            
        }
    }
        exit(0);
}
*/