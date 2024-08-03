/*Benemerita Universidad Autonoma de Puebla*/
/*	Facultad de Ciencias de la Computacion*/

/*	Jose de Jesus Morales Morales*/
/*	Carlos Martin Ventura Guevara*/
/*	Jorge Alberto Flores Velez*/
/*	Octavio Augusto Martinez Reyes*/
/*	Rodrigo Ortega Tableros*/
	
/*	Sistemas Operativos*/
/*	Otoño 2021*/
/*	21/08/2021*/
	

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
}nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo(int a);
void insertarNodoI(int a);
void mostrarLista();
void buscarNodo();
void eliminarNodo();
int TamanoL=0;

int main(){
	int opcionMenu = 0;
	int tamano=0,Dato;
	do{
		printf("\n|-----------------------------------------|");
		printf("\n|          LISTA CIRCULAR SIMPLE          |");
		printf("\n|--------------------|--------------------|");
		printf("\n| 1.- Cargar archivo | 4.- Eliminar       |");
		printf("\n| 2.- Insertar i     | 5.- Mostrar        |");
		printf("\n| 3.- Buscar         | 6.- Salir          |");
		printf("\n|--------------------|--------------------|");
		printf("\n\n Seleccione una opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:{
				FILE * flujo = fopen("valores.txt", "rb");
				if(flujo == NULL){
					perror("Error en la apertura del archivo");
					return 1;
				}
				
				int numero;
				while(feof(flujo)==0){
					fscanf(flujo, "%d", &numero);
					insertarNodo(numero);
					tamano++;
				}
				
				TamanoL+=tamano;
				fclose(flujo);
				
				printf("Datos cargados en la lista circular: %d\n",TamanoL);
				break;
			}
			case 2:{
				printf("\nProporcione el dato a insertar: ");
				scanf("%d",&Dato);
				insertarNodoI(Dato);
				break;
			}
			case 3:{
				buscarNodo();
				break;
			}
			case 4:{
				eliminarNodo();
				break;
			}
			case 5:{
				mostrarLista();
				break;
			}
			case 6:{
				
				break;
			}
			default:{
				printf("\n\n Opcion no valida\n");
				break;
			}
		}
	}while(opcionMenu!=6);
	
	return 0;
}

// lista circular 17,8
// primero 17

void insertarNodo(int a){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->dato=a;
	
	if(primero==NULL){
		// 17->primero
		primero = nuevo;
		primero -> siguiente = primero;
		ultimo = primero;
	}else{
		//17->8->primero
		ultimo -> siguiente = nuevo;
		nuevo -> siguiente = primero;
		ultimo = nuevo;
	}
}

void insertarNodoI(int a){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	int posicion;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nuevo->dato=a;
	
	if(primero==NULL){
		printf("La lista esta vacia, se insertara en la primera posicion\n");
		primero = nuevo;
		primero -> siguiente = primero;
		ultimo = primero;
		TamanoL++;
	}
	else{
	printf("\nProporcione la posicion del dato: ");
	scanf("%d",&posicion);

	if(posicion<1 || posicion>TamanoL+1){
		printf("\nLa posicion es incorrecta\n");
	}else if(posicion==TamanoL+1){
		ultimo -> siguiente = nuevo;
		nuevo -> siguiente = primero;
		ultimo = nuevo;
		TamanoL++;
		printf("\n Dato insertado correctamente\n");
	}else if(posicion==1){
		nuevo->siguiente=primero;
		primero=nuevo;
		ultimo->siguiente=nuevo;
		TamanoL++;
		printf("\n Dato insertado correctamente\n");
	}else{
		while(posicion!=1){
			anterior = actual;
			actual=actual->siguiente;
			posicion--;	
		}
		anterior->siguiente=nuevo;
		nuevo->siguiente=actual;
		TamanoL++;
		printf("\n Dato insertado correctamente\n");
	}
	}
}

void mostrarLista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero==NULL){
		printf("\nLa lista se encuentra vacia");
	}else{
		printf("\nLa lista es: ");
		do{
			printf("%d ->", actual->dato);
			actual = actual->siguiente;
		}while(actual!=primero);
		printf("\n");
	}
}

void buscarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscar = 0, encontrado = 0;
	printf("\n\nIngrese el valor de nodo a buscar: ");
	scanf("%d", &nodoBuscar);
	if(primero==NULL){
		printf("\n La lista se encuentra vacia\n\n");
	}else{
		do{
			if(actual -> dato == nodoBuscar){
				printf("Nodo con el dato (%d) Encontrado\n", nodoBuscar);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual!=primero);
				
		if(encontrado == 0){
			printf("Nodo no Encontrado\n");
		}
	}
}

void eliminarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	int nodoBuscar = 0, encontrado = 0;
	printf("\n\nIngrese el valor de nodo a buscar para eliminar: ");
	scanf("%d", &nodoBuscar);
	if(primero==NULL){
		printf("\n La lista se encuentra vacia\n\n");
	}else{
		do{
			if(actual -> dato == nodoBuscar){
				printf("Nodo con el dato (%d) Encontrado\n", nodoBuscar);
				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
					TamanoL--;
				}else if(actual==ultimo){
					anterior->siguiente = primero;
					ultimo = anterior;
					TamanoL--;
				}else{
					anterior->siguiente = actual->siguiente;
					TamanoL--;
				}
				printf("Nodo eliminado\n");
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado !=1);
				
		if(encontrado == 0){
			printf("Nodo no Encontrado\n");
		}else{
			free(anterior);
		}
	}
}
