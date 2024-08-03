#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int O,i=0,D,E=0; FILE *CA; FILE *LA;

int main (){
	CA=fopen("variablecompartida.dat","w");
    LA=fopen("variablecompartida.dat","r");
	O=fork();   
     	while (E!=50){
		if (O == 0){	/* Proceso hijo */
			printf ("\nProceso hijo. PID=%d, PPID=%d\n",getpid (), getppid ());
			if(i%4==0){	        
                    fscanf(LA,"%i",&D); 
                    rewind(LA);
                    printf("La variable hijo en el segundo %i es %i\n",i,D);    
					E=D;    
			}
            sleep(1);
        }

		else{	/* Proceso padre */
			printf ("\nProcesopadre. PID=%d\n", getpid ());
			if(i%3==0){
                    \
                    E++;
                    fprintf(CA,"%i",E);
                    rewind(CA);
                    printf("La variable padre en el segundo %i es %i\n",i,E);
			}
            sleep(1);    
        }
		i++;
		}
        
    printf ("Fin del proceso %d\n", getpid ());return 0;
   }

