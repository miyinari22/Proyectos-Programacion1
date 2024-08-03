#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define puerto 55558
#define SERV_HOST_ADDR "192.168.1.80"
char buf_rx[100];
char buf_tx2[10];
int buf_tx,n;
static const char alpahanum[]= "ABCDEFGHJKLMNIOQRSTUVWXYZabcdefghijklmnopqrstuvwxys";

int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    srand(time(NULL));
    //creacion de socket 
    sockfd=socket(AF_INET, SOCK_STREAM,0);
    if(sockfd==-1){printf("La creacion del socker no ha sido exitosa\n"); return -1;}
    else{ printf("El socket se ha creado exitosamente...\n");}
    memset(&servaddr,0,sizeof(servaddr));
    //poner direccion IP
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
    servaddr.sin_port=htons(puerto);
    //conectando al server
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0){
        printf("No se pudo conectar con el despachador...\n"); return -1;
    }
    printf("Se ha conectado con el despachador\n");
    //ENVIANDO Procesos
    while(1){
        sleep(2);
        //numero aleatorio
        buf_tx=rand()%13+1;
        n=htonl(buf_tx);
        //printf("%i\n",buf_tx);
        write(sockfd,&n,sizeof(n));
        //palabra aleatoria 
        for(int i=0;i<9;i++){
            buf_tx2[i]=alpahanum[rand()%(sizeof(alpahanum)-1)];
        }
        buf_tx2[9]='\0';
        printf("%i %s\n",buf_tx,buf_tx2);
        write(sockfd,buf_tx2,sizeof(buf_tx2));
        //Respuesta despachador
        read(sockfd,buf_rx,sizeof(buf_rx));
        printf("%s\n",buf_rx);
    }
    //cerrar socket 
    close(sockfd);
}