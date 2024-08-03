#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

main (int argc, char **argv){
 pid_t pid;
 int valor;

 pid = fork();
 switch(pid){
      case -1: exit(1)
      case 0: if (execvp(argv[1],&argv[1])< 0)
                 perror("exec");
      default: while (wait(&valor)!= pid);
               if(WIFEXITED(valor))
                 printf("El hijo termino normalmente y su valor devuelto fue %d\n", WEXITSTATUS(valor));
               if(WIFSIGNALED(valor))
                 printf("El hijo termino al recibir la señal %d\n", WTERMSIG(valor));
            } //else
        } //switch
}

           

