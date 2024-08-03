/*
Ortega Tableros Rodrigo
Jose de Jesus Morales Morales
Jorge Alberto Flores Vélez
Carlos Martin Ventura Guevara
Octavio Augusto Martínez Reyes
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int E=2;

int main(int argc, char **argv){
    pid_t pid;
    char lectura[1024],aux[]="salir\0",aux1[]="./cuadratica\0";
    char ar1[3];
    char ar2[3];
    char ar3[3];
    int valor;
    
    do{
    pid=fork();
    switch (pid)
    {

    case -1:
        printf("Error con el fork()\n");
        break;

    //Proceso Hijo
    case 0:
        printf("interprete $");
	scanf("%s",lectura);
	if(strcmp(lectura,aux1)!=0){
	fgets(ar1,3,stdin);
	char *const argv2[]={lectura,ar1,NULL};
        if(strcmp(aux,lectura)==0){
            E=0;
            exit(7);
        }
        else{
            char *pos;
            if((pos=strchr(lectura, '\0'))!=NULL);
            *pos='\0';
            execvp(lectura,argv2);
            perror("Error");
        }
	}else{
	scanf("%s",ar1);
	scanf("%s",ar2);
	fgets(ar3,3,stdin);
	char *const argv2[]={lectura,ar1,ar2,ar3,NULL};
        if(strcmp(aux,lectura)==0){
            E=0;
            exit(7);
        }
        else{
            char *pos;
            if((pos=strchr(lectura, '\0'))!=NULL);
            *pos='\0';
            execvp(lectura,argv2);
            perror("Error");
        }
	}
        break;


    //Proceso Padre 
    default:
        while(wait(&valor)!=pid);{
        if(WIFEXITED(valor)){
            switch (WEXITSTATUS(valor))
            {
            case 2:
                printf("El proceso %d termino porque no se puede realizar una division entre 0\n",getpid());
                break;

            case 3:
                printf("El proceso %d termino porque hay raices imaginarias\n",getpid());
                break;
            
            case 4:
                printf("El proceso %d termino porque no hay valores en fibonacci\n",getpid());
                break;

            case 5:
            	printf("El hijo termino normalmente y su valor devuelto fue %d\n",WEXITSTATUS(valor));
                break;

            case 7:
                printf("El proceso %d termino satisfactoriamente\n",getpid());
                printf("Hasta luego\n");
                E=0;
                exit(1);
                break;

            default:
                exit(1);
                break;
            }
        }
        if(WIFSIGNALED(valor))
		printf("El hijo termino al recibir la señal %d\n",WTERMSIG(valor));
        }
    break;
    }}while(E=!0);// cierre while
}
