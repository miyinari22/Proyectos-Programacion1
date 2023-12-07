/*Alumno: Martinez Reyes Octavio Augusto
Matricula: 201904948*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef struct nodo{
	int precio;
	int marca;
	int cantidad;
	int modelo;
	struct nodo *sig;
}nodo;

nodo *agregar(nodo *lista);
nodo *llenar(nodo *lista,int op);
void impresion(nodo *lista);

int main(){
	nodo *lista;
	FILE *f;
	lista=NULL;
	int pos, pre, cap, ex, mar, op;
	char model[MAX];
	
	
	f=fopen("smartphonedb.txt", "r");
	if(f==NULL){
		printf("ERROR AL ABRIR EL ARCHIVO");
		return 1;
	} else {
		do{
			printf("Bienvenido\n\n Elija el modelo y marca de celular al comprar (Seleccione el numero)\n\n");
			printf("Marca     Modelo       Capacidad(GB)    Precio     Existencias\n");
			while(!feof(f)){
				fscanf(f, "%d %d %s %d %d %d", &pos, &mar, &model, &cap, &pre, &ex);
				printf("%d\t %s\t %d\t %d\t\t %d\t\n",mar, model, cap, pre, ex);
			}
			scanf("%d", &op);
			agregar(lista);
			llenar(lista, op);
			impresion(lista);
		}while(op<6);
		
	}
}

nodo *agregar(nodo *lista){
	nodo *nodoNuevo= NULL;
	
	nodoNuevo= (nodo *)malloc(sizeof(nodo));
	nodoNuevo->sig=lista;
	lista=nodoNuevo;
	
	return lista;
}

nodo *llenar(nodo *lista, int op){
	switch(op){
		case 1:
			lista->marca=1;
			printf("Cuantos equipos va a comprar?(Maximo 5)");
			scanf("%d",lista->cantidad);
			break;
		case 2:
			lista->marca=2;
			printf("Cuantos equipos va a comprar?(Maximo 5)");
			scanf("%d",lista->cantidad);
			break;
		case 3:
			lista->marca=3;
			printf("Cuantos equipos va a comprar?(Maximo 5)");
			scanf("%d",lista->cantidad);
			break;
		case 4:
			lista->marca=4;
			printf("Cuantos equipos va a comprar?(Maximo 5)");
			scanf("%d",lista->cantidad);
			break;
		case 5:
			lista->marca=5;
			printf("Cuantos equipos va a comprar?(Maximo 5)");
			scanf("%d",lista->cantidad);
			break;
	}
	
}

void impresion(nodo *lista){
	
	char marca, modelo;
	int cantidad, precio, total;
	
	time_t t;
	struct tm *tm;
	char fechayhora[100];
	int i;
	
	t=time(NULL);
	tm=localtime(&t);

	printf("Comprobante de Pago\n\nTienda: XCD S.A DE C.V %s\n", fechayhora);
	for(i=0; i<6; i++){
		printf("%s %s %d x %d", marca, modelo, cantidad, precio);
	}
	printf("------------\nTOTAL: %d", total);
	
}
