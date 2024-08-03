/*

Sistemas Operativos I

Equipo 6:

Ortega Tableros Rodrigo
José de Jesús Morales Morales
Jorge Alberto Flores Vélez
Carlos Martin Ventura Guevara
Octavio Augusto Martínez Reyes

10/11/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    int fd2[2];
        
    if (pipe(fd2)==-1){
        return 1;
    }
    if (pipe(fd)==-1){
        return 1;
    }
    int fd3[2];
    if (pipe(fd)==-1){
        return 1;
    }
    

    int pid=fork();
    //Error creacion hijo
    if(pid<0){
        printf("Error con fork()\n");
    }
    
    //Proceso padre 
    if (pid>0)
    {
        close(fd[0]);
        char procesoN[150];
        char procesoNM[150];

        printf("Dame el nombre del archivo de texto que desea abrir: \n");
        fgets(procesoN,150,stdin);
        write(fd[1],procesoN,150);
        close(fd[1]);
        kill(pid,SIGCONT);
        wait(NULL);
        read(fd3[0],procesoNM,150);
        close(fd3[0]);
        printf("%s\n",procesoNM);

    }

    //Proceso Hijo 1
    if (pid==0)
    {
        FILE *ARC;
        char procesoN[150];char WP2[150];
        read(fd[0],procesoN,150);
        close(fd[0]);
        char *pos;
        if((pos=strchr(procesoN,'\n'))!=NULL);
        *pos='\0';
        ARC=fopen(("%s",procesoN),"r");
        //lectura de caracteres 
        char ContARC[200];
        int f=0;
        while(feof(ARC)==0){
        ContARC[f]=fgetc(ARC);
        f++;
        }
        fscanf(ARC,"%s",ContARC);
        int T;
        T=strlen(ContARC);
   
        close(fd[1]);
        char WP[T],WPAUX[T]; int j=0,aux=0;
        for(int i=0; i<T; i++){
            WP[i]=ContARC[i];
            if(WP[i]==' '){
                //creacion hijo 2
                int pid2=fork();


                //Proceso Hijo 1
                if (pid2>0){
                write(fd2[1],WP,j+1);

                wait(NULL);
                read(fd2[0],WPAUX,T);
                printf("%s\n",WPAUX); //prueba
                for(aux;aux<=j;aux++){
                    WP[aux]=WPAUX[aux];
                }
                printf("%s\n",WP); //prueba
                aux=aux+j;  
                }

                //Proceso Hijo 2
                if(pid2==0){
                    read(fd2[0],WP2,T);
                    close(fd2[0]);
                    printf("%s\n",WP2); //prueba
                    int L;
                    L=strlen(WP2);
                    for(int Z=0;Z<L;Z++){
                        if(WP2[Z]<=57 && WP2[Z]>=48);
                        else{
                            WP2[Z]=' ';
                        }
                    }
                    write(fd2[1],WP2,L);
                    close(fd2[1]);
                }
            }
            j++;
            }
        close(fd3[0]);
        write(fd3[1],WP,T);
        close(fd3[1]);
        
        
    }
    
}
