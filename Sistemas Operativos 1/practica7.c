#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<sys/ipc.h>

#define PUERTO 55558
#define BUF_SIZE 100
#define SERV_HOST_ADDR "192.168.1.80"
#define BACKLOG 5
#define MAXPROLOT 10
#define MAXPROCESOSGEN 500



int main(int argc, char const *argv[])
{
    FILE *procesos;
    //Creacion Memoria compartida para base de datos despachador(tiempo procesos)
    int* Tprocesos= (int*)mmap(NULL,sizeof(int)*MAXPROCESOSGEN,PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0); 
    //Creacion Memoria compartida para base de datos despachador(Nombre procesos)
    char* Nprocesos= (char*)mmap(NULL,MAXPROCESOSGEN*10,PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0); 
    //Creacion Memoria compartida para base de datos despachador(tiempo procesos)
    int* LotProcSEND= (int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0); 

    int pid=fork();//creacion proceso hijo 

    if(pid>0){      //PROCESOS HIJOS
        //creacion archivo para procesos
        procesos=fopen("procesos2.dat","wt");
        fclose(procesos);
        int sockfd,connfd;
        unsigned int len;
        struct sockaddr_in servaddr, client;
        int len_rx,len_tx=0;
        char buff_tx[BUF_SIZE]="Procesos recibido\n";
        char buff_rx2[10];
        int buff_rx,n;
       
        //CREACION SOCKET
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd==-1){ printf("[SERVER]: El socket no se ha creado correctamente\n");}
        else{printf("[SERVER]: El socket se ha creado correctamente\n");}
        memset(&servaddr,0, sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
        servaddr.sin_port=htons(PUERTO);

        //UNION DE SOCKET
        if((bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)))!=0){
            printf("[SERVER]: Error en la union del socket \n"); return -1;
        }
        else{printf("[SERVER]: El socket se ha unido con exito\n");}

        //Socket pasivo 
        if((listen(sockfd,BACKLOG))!=0){
            printf("[SERVER]: Error al poner el socket pasivo\n"); return-1;
        }
        else{printf("[SERVER]: Escuchando...\n");}
        
        //Esperando a que el cliente se conecte 
        len=sizeof(client);

        //creacion memoria compartida num procesos
        int* Numeroprocesos= (int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0); 

        //creacion otro hijo 
        int pid2=fork();

        if (pid2>0){ //procesos hijo 2 (Lectura cliente)
            while (1)
            {
                //conectando a cliente
                connfd=accept(sockfd,(struct sockaddr *)&client, &len);
                if(connfd<0){ printf("[SERVER]: Conexion no aceptada\n"); return -1; } //error conexioin
                else{ //conexion recibida
                    //recibiendo datos
                    while(1){
                        len_rx=read(connfd,&buff_rx,sizeof(buff_rx));
                        if(len_rx==-1){
                            printf("[SERVER]: No se pudo leer lo que el cliente envio\n");
                        }
                        else{
                            if(len_rx==0){
                                printf("\n[SERVER]: El cliente ha cerrado el socket\n"); close(connfd); break;
                            }
                            //recibe dato exitosamente
                            else{
                                procesos=fopen("procesos2.dat","a");
                                write(connfd,buff_tx,strlen(buff_tx));
                                n=ntohl(buff_rx);
                                //printf("[Server]: Se recibio proceso %i \n",n);
                                fprintf(procesos,"%i ",n);
                                fclose(procesos);
                                //lectura palabra 
                                read(connfd,buff_rx2,sizeof(buff_rx2));
                                //printf("[Server]: Se recibio nombre de proceso %s \n",buff_rx2);
                                procesos=fopen("procesos2.dat","a");
                                fprintf(procesos,"%s\n",buff_rx2);
                                fclose(procesos);
                                *Numeroprocesos=*Numeroprocesos+1;
                                //printf("[Server]: Hay %d procesos generados \n",*Numeroprocesos);
                                sleep(2);
                            }
                        }
                    }
                }
            }
        }
        else{ //proceso hijo 1 (Creacion y direccion de lotes de procesos)
            procesos=fopen("procesos2.dat","r");
            rewind(procesos);
            int Nprocesospasados=0,Nprocesosrestantes=0,v=0;
            sleep(rand()%10+6);
            Nprocesosrestantes=*Numeroprocesos-Nprocesospasados;            
            while(1){
                sleep(rand()%10+6);
                *LotProcSEND=0;
                if(Nprocesosrestantes!=0){
                    int num[MAXPROLOT],Np[MAXPROLOT]; char NomProc[MAXPROLOT][10];
                    int zal=rand()%Nprocesosrestantes+1;
                    printf("\n[Despachador]: Se hara lote de %i procesos\n",zal);
                    for(int g=0;g<zal;g++){
                        fscanf(procesos,"%i",&num[g]);
                        Np[g]=num[g];
                        Tprocesos[v]=Np[g]; //enviando a memoria compartida de tiempo procesos
                        fscanf(procesos,"%s",NomProc[g]);
                        for (int f=0;f<11;f++){ //enviando a memoria compartida nombre procesos
                            Nprocesos[v*11+f]=NomProc[g][f];
                        }               
                        //printf("El proceso %s de tiempo %i esta en el lote\n",NomProc[g],Np[g]);
                        v++;
                    }
                    *LotProcSEND=zal; //enviando el numero de procesos que hay en el lote
                    Nprocesospasados=Nprocesospasados+zal;
                    Nprocesosrestantes=*Numeroprocesos-Nprocesospasados;
                    //printf("Hay %d procesos restantes\n\n",Nprocesosrestantes);                    
                }
            }
        }
        

    }
    //PROCESO PADRE
    if(pid==0){
        int m=0,T=0,ProcesosDentro=0,d=0,Totalprocesos=0;
        while(1){
            sleep(1);
            char NombProc[MAXPROCESOSGEN][10];
            int Procesos[MAXPROCESOSGEN][5],procxenvi=0;
            //envio de procesos a base de datos despachador
            if (procxenvi!=*LotProcSEND)
            {
                procxenvi=procxenvi+*LotProcSEND; 
                ProcesosDentro=ProcesosDentro+*LotProcSEND;
                Totalprocesos=Totalprocesos+*LotProcSEND;
                *LotProcSEND=0;
                
            }
            //printf("%i\n",procxenvi);      
            if(procxenvi>0){
                //printf("%i\n",procxenvi);
                for(int h=0;h<procxenvi;h++){
                    for (int g=0;g<11;g++){
                        NombProc[m][g]=Nprocesos[m*11+g];
                    }
                    Procesos[m][1]=T;
                    Procesos[m][2]=Tprocesos[m];
                    Procesos[m][3]=Tprocesos[m];
                    printf("[Despachador]: Se recibio el proceso %s de tiempo %i al segundo %i\n",NombProc[m],Procesos[m][2],T);
                    m++;
                }  
                procxenvi--;
            }
            //algoritmo despachador
            //printf("hay %i PRROCESOS DENTRO\n",ProcesosDentro);
            
            if(ProcesosDentro>0){
            for (int i=0; i<ProcesosDentro-1; i++) {
		    for(int j=i+1; j<ProcesosDentro; j++) {
			if (Procesos[j][3]<Procesos[i][3]) {
				int aux[3] = {Procesos[j][3],Procesos[j][2],Procesos[j][1]};
                char auxT[11];
                for (int Z=0;Z<11;Z++){
                        auxT[Z]=NombProc[j][Z];
                }
                Procesos[j][1] = Procesos[i][1];
				Procesos[j][3] = Procesos[i][3];
				//NombProc[j] = NombProc[i];
                for (int b=0;b<11;b++){
                        NombProc[j][b]=NombProc[i][b];
                }
                Procesos[j][2]=Procesos[i][2];
				Procesos[i][3] = aux[0];
				//NombProc[i] = aux;
                for (int l=0;l<11;l++){
                        NombProc[i][l]=auxT[l];
                }
                Procesos[i][2]=aux[1];
                Procesos[i][1]=aux[2];
			    }       
            }
            } 
            Procesos[d][3]--;
            if(Procesos[d][3]==0){
                Procesos[d][4]=T;
                printf("\nEl proceso %s ha terminado en %i segundos\n",NombProc[d],T);
                //sleep(1);
                d++;
                ProcesosDentro--;
            }
        }
        T++;
        
        
        }
        
               
    }
    return 0;
}

