/*Integrantes: 						Fecha de inicio: 26 de Mayo de 2020
Molly Karime Paez Lopez				Fecha de conclusion:
Juan Luis Perez						Version: 0.1.0
Armando Castillo Tecocoatzi
Octavio Augusto Martinez Reyes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define twitter 280 /*Maximo de caracteres para describir algo con holgura*/
#define fecha 4 /*Limite de caracteres para ingresar el anjo*/
#define titulo 30 /*Maximo de caracteres para ingresar el titulo de la pelicula*/

typedef struct terror{
	char nombre[titulo];
	int anjo[fecha];
	char sinop[twitter];
	struct terror *sig;
	
}terror;

typedef struct Lista{
	terror *cabeza;
}Lista;


terror *crearNodoT(terror *listaT){ /*inicializa en NULL la lista*/
	
		terror *nodo = (terror *)malloc(sizeof(nodo));
		nodo->sig = NULL
		 
	return nodo;
}

void eliminarNodo(terror *nodo){
	free(nodo);
}
		 
void insertarPT(Lista *lista, terror *listaT){
	terror *nodo = crearNodoT(listaT);
	nodo->sig = lista->cabeza;
	lista->cabeza = nodo;
}
	
void insertarFT(Lista *lista, terror *listaT){
	terror *nodo = crearNodoT(listaT);
	terror *pt = lista->cabeza;
	while(pt->sig){
		
	}
}
void insertarT(int n; terror *listaT){ /*Ingresa un elemento despues de donde se pida*/
	terror *nodo = crearNodo(listaT);
	terror *pt= listaT->sig;
	int pos=0;
		
	if (lista->cabeza == NULL){
		lista->cabeza = nodo;
	} else {
		while(pos < n && pt->sig)
		{
			pt = lista->cabeza
			pos++;
		}
		nodo->sig = pt->sig;
		pt->sig = nodo;
	}
}

void quitarNodo(int n, terror *listaT){
	
	terror *pt = listaT->sig;
	terror *elim=pt->sig;
	int pos=0
	if(n==0){
		listaT->sig = listaT->cabeza->sig;
		eliminarNodo(elim);
		}
		if(listaT->sig){
			while(pos<(n-1)){
				pt = pt->sig;
				pos++;
			}
			pt->sig = elim->sig;
			eliminarNodo(elim);
		}
	 }
}
