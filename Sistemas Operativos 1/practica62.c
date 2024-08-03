/*

Sistemas Operativos I

Equipo 6:

Ortega Tableros Rodrigo
José de Jesús Morales Morales
Jorge Alberto Flores Vélez
Carlos Martin Ventura Guevara
Octavio Augusto Martínez Reyes

21/11/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#define clientes 0
#define barberos 1
#define mutex 2
#define Sillas 5

void up(int sem_id,int sem_num,struct sembuf *semaphore) {
  semaphore->sem_num=sem_num;
  semaphore->sem_op=1;
  semaphore->sem_flg=0;
  semop(sem_id,semaphore,1);
}

void down(int sem_id,int sem_num,struct sembuf *semaphore) {
  semaphore->sem_num=sem_num;
  semaphore->sem_op=-1;
  semaphore->sem_flg=0;
  semop(sem_id,semaphore,1);
}

void initSem(int sem_id,int sem_num,int val) {
  union semnum {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
  }argument;
  argument.val=val;
  semctl(sem_id,sem_num,SETVAL,argument);
}

int main() {
  srand(time(NULL));
  int sem_key=1111,shm_key=2222;
  int sem_id,shm_id;
  int *waiting;
  struct sembuf semaphore;
  int count=1;
  shm_id=shmget(shm_key,sizeof(int),IPC_CREAT|0666);
  sem_id=semget(sem_key,3,IPC_CREAT|0666);
  waiting=shmat(shm_id,NULL,0);
  *waiting=0;
  initSem(sem_id,clientes,0);
  initSem(sem_id,barberos,0);
  initSem(sem_id,mutex,1);
  printf("Hay %d sillas.\n",Sillas);

  if(fork()) { //Proceso del barbero
    while(1) {
      down(sem_id,clientes,&semaphore);
      down(sem_id,mutex,&semaphore);
      *waiting=*waiting-1;
      up(sem_id,barberos,&semaphore);
      up(sem_id,mutex,&semaphore);
      printf("El barbero esta cortando el cabello.\n");
      sleep(rand()%7+1);  
    }
  }

  else { //proceso cliente
    while(1) {
      sleep(rand()%5+1); //Tiempo en el que llega el cliente 
      down(sem_id,mutex,&semaphore);
      if(*waiting<Sillas) {
      printf("Cliente %d ha tomado asiento.\n",count++);
      *waiting=*waiting+1;
      up(sem_id,clientes,&semaphore);
      up(sem_id,mutex,&semaphore);
      }
      else {
      printf("El cliente %d se ha ido.\n",count++);
      up(sem_id,mutex,&semaphore);
      }
    }
  }
} 