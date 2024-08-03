/*practica 7
Armando Castillo Tecocoatzi
Molly Karime Paez Lopez
Juan Perez Luis
Octavio Augusto Martinez*/
#include <stdlib.h>
#include <stdio.h>

struct structNodo{
    int dato;
    struct structNodo *next;
};

typedef struct structNodo nodo;


nodo *crearNodo (nodo *lista);
nodo *insertarNodoInicio(int v, nodo *lista);
nodo *insertarNodoFinal(int v, nodo *lista);
void imprimirLista(nodo *lista);
nodo *eliminarInicio(nodo *lista);
nodo *eliminarFinal(nodo *lista);


int main(){
	
	nodo *lista;
	
	lista=crearNodo(lista);
	lista=insertarNodoFinal(9, lista);
    lista=insertarNodoInicio(10, lista);
	lista=insertarNodoInicio(8, lista);
	lista=insertarNodoInicio(15, lista);
	
	imprimirLista(lista);
	
	lista=eliminarInicio(lista);
	imprimirLista(lista);
	lista=eliminarFinal(lista);
	imprimirLista(lista);
		
    return 0;
}


nodo* crearNodo (nodo *lista){
   
    lista=NULL;
    
    return lista;
}


nodo *insertarNodoInicio(int v, nodo *lista){
	nodo *nodoN;
	
		nodoN=(nodo *)malloc(sizeof(nodo));
		if (nodoN!=NULL){
			nodoN->dato=v;
			nodoN->next=lista;
			
			lista=nodoN;
		}
	
	return lista;
}


nodo *insertarNodoFinal(int v, nodo *lista){
	nodo *nodoN, *nodoAu;
	
		nodoN=(nodo *)malloc(sizeof(nodo));
		
		if (nodoN!=NULL){
			nodoN->dato=v;
			nodoN->next=NULL;
			
			if(lista==NULL) 
				lista=nodoN;
				else{
					nodoAu=lista;
					
					while(nodoAu->next!=NULL){
						nodoAu=nodoAu->next;
						nodoAu->next=nodoN;
					}
			}
		}
		
	return lista;
}

void imprimirLista(nodo *lista){
	nodo *nodoAu;
	
	nodoAu=lista;
	printf("Inicio-> ");
	
	while(nodoAu!=NULL){
		printf("%d -> ", nodoAu->dato);
		nodoAu=nodoAu->next;
	}
	
	printf("NULL\n");
}

nodo *eliminarInicio(nodo *lista){
	nodo *nodoAu;
	int dato;
	
	if (lista==NULL){
		printf("La lista esta vacia\n");
		}else{
			nodoAu=lista;
			dato=nodoAu->dato;
			
			lista=nodoAu->next;
			printf("Se ha eliminado el elemento %d\n", dato);
			free(nodoAu);
		}
   return lista;
}

nodo *eliminarFinal(nodo *lista){
	nodo *nodoAu, *nodoA;
	int dato;
	
	if(lista==NULL){
		printf("Lista Vacia\n");
		}else{
			nodoAu=lista;
				while(nodoAu->next!=NULL){
					nodoA=nodoAu;
					nodoAu=nodoAu->next;
				}
			dato=nodoAu->dato;
			nodoA->next=NULL;
			printf("Se ha eliminado el elemento %d \n", dato);
			free(nodoAu);
	}
	return lista;
}
