/*Alumno: Octavio Augusto Martinez Reyes     Matricula:201904948 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 20 


typedef struct raiz{ 
	char modelo[MAX];
	int precio;
	int capacidad;
	int existencias;
	struct raiz *sig;
	
}nodoM; 

typedef struct cliente{
	char marca[MAX];
	char modelo[MAX];
	int precio;
	int cantidad;
	struct cliente *sig;
}nodoC;

char llenadoCambiar();
char llenado();
void guardar(nodoM *LG, nodoM *Xiaomi, nodoM *Moto, nodoM *Samsung, nodoM *Huawei);

nodoC *agregarCompra(nodoC *ListaC, char name[MAX], int compra, int precio, char llen);
void guardarcliente(nodoC *ListaC);
void imprimirrecibo(nodoC *lista);

nodoM *agregarNodo(nodoM *celular, char name[MAX], int precio, int capacidad, int existencias);
nodoM *obtenerAux(nodoM *celular, char nombreBuscar[MAX]);
int buscarEquipo(nodoM *celular, char nombreBuscar[MAX]);
void imprimirNodo(nodoM *celular);

void menu();

int main(){
	menu();
	return 0;
}
	
void menu(){
		/*SE INICIALIZAN LAS LISTAS EN NULL 
		---------------------------------
		*/
		nodoM  *LG   = NULL, *auxLG;
		nodoM  *Xiaomi  = NULL, *auxXiaomi;
		nodoM *Moto = NULL, *auxMoto;
		nodoM  *Samsung  = NULL, *auxSamsung;
		nodoM *Huawei = NULL, *auxHuawei;
		
		nodoC *ListaC = NULL;
		FILE *fp;
		char typeOf[20] = {'\0'};
		int op, compra, precio;
		
		char nombreAgregar[MAX];
		int precioAgregar, capacidadAgregar, existenciasAgregar;
		char name[MAX];
		int capacidad, existencias, i;
		
		char llen;
		int bandera;
		
		fp = fopen("SmartphonesDB.txt", "r");	
		if (fp == NULL) {
			printf("No se pudo abrir archivo\n");
		}
		else{
			while (!feof(fp)) {
				fscanf(fp, "%s", typeOf);	
				fflush(stdin);
				fscanf(fp, "%s", nombreAgregar);
				fflush(stdin);
				fscanf(fp, "%d", &precioAgregar);
				fflush(stdin);
				fscanf(fp, "%d", &capacidadAgregar);
				fflush(stdin);
				fscanf(fp, "%d", &existenciasAgregar);
				fflush(stdin);
				
				if (!feof(fp)) {
					for (int i = 0; nombreAgregar[i] != '\0'; ++i) {
						if (nombreAgregar[i] == '_') {
							nombreAgregar[i] = ' ';	
						}	
					}
					
					if (strcmp(typeOf, "LG") == 0) {
						LG = agregarNodo(LG, nombreAgregar, precioAgregar, capacidadAgregar, existenciasAgregar);
					}
					if (strcmp(typeOf, "XIAOMI") == 0) {
						Xiaomi = agregarNodo(Xiaomi, nombreAgregar, precioAgregar, capacidadAgregar, existenciasAgregar);
					}
					if (strcmp(typeOf, "MOTO") == 0) {
						Moto = agregarNodo(Moto, nombreAgregar, precioAgregar, capacidadAgregar, existenciasAgregar);
					}
					if (strcmp(typeOf, "SAMSUNG") == 0) {
						Samsung = agregarNodo(Samsung, nombreAgregar, precioAgregar, capacidadAgregar, existenciasAgregar);
					}
					if (strcmp(typeOf, "HUAWEI") == 0) {
						Huawei = agregarNodo(Huawei, nombreAgregar, precioAgregar, capacidadAgregar, existenciasAgregar);
					}
				}
				
			}
			fclose(fp);
		}
		
		
		/*MENU PRINCIPAL*/
		do {
			printf("\t\tBIENVENIDO\t\t\nQue desea hacer?\n\n1.-Comprar Equipos\n2.-Mostrar Equipos\n");
			printf("3.-Salir\n\n");
			scanf("%d", &op);
			switch(op){
			case 1:
				llen = llenado();
				switch(llen){
				case 'L':
					printf("Modelo del equipo (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarEquipo(LG, name);
					if (bandera == 1) {
							printf("Cuantos desea comprar?");
							scanf("%d", &compra);
							LG->existencias = LG->existencias-compra;
							precio = LG->precio;
							ListaC = agregarCompra(ListaC, name, compra, precio, llen);
					}else{
						printf("\nNo se ha encontrado el modelo, pruebe con otro\nEnter para volver al menu\n");
						getchar();
					}
					break;
				case 'X':
					printf("Modelo del equipo (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarEquipo(Xiaomi, name);
					if (bandera == 1) {
						printf("Cuantos desea comprar?");
						scanf("%d", &compra);
						Xiaomi->existencias = Xiaomi->existencias-compra;
						precio = Xiaomi->precio;
						ListaC=agregarCompra(ListaC,name, compra, precio, llen);
					}
					else{
						printf("\nNo se ha encontrado el modelo, pruebe con otro\nEnter para volver al menu\n");
						getchar();
					}
					break;
				case 'M':
					printf("Nombre del equipo(Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarEquipo(Moto, name);
					if (bandera == 1) {
						printf("Cuantos desea comprar?");
						scanf("%d", &compra);
						Moto->existencias = Moto->existencias-compra;
						precio = Moto->precio;
						ListaC = agregarCompra(ListaC, name, compra, precio, llen);
					}
					else{
						printf("\nNo se ha encontrado el equipo, pruebe con otro\nEnter para volver al menu\n");
						getchar();
					}
					break;
				case 'S':
					printf("Nombre del equipo (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarEquipo(Samsung, name);
					if (bandera == 1) {
						printf("Cuantos desea comprar?");
						scanf("%d", &compra);
						Samsung->existencias = Samsung->existencias-compra;
						ListaC = agregarCompra(ListaC, name, compra, precio, llen);
					}
					else{
						printf("\nNo se ha encontrado el modelo, pruebe con otro\nEnter para volver al menu\n");
						getchar();
					}
				case 'H':
						printf("Nombre de la pelicula (Use Mayusculas): ");
						scanf(" %[^\n]", name);
						fflush(stdin);
						bandera = buscarEquipo(Huawei, name);
						if (bandera == 1) {
							printf("Cuantos desea comprar?");
							scanf("%d", &compra);
							Huawei->existencias = Huawei->existencias-compra;
							ListaC = agregarCompra(ListaC, name, compra, precio, llen);
						}
						else{
							printf("\nNo se ha encontrado el modelo, pruebe con otro\nEnter para volver al menu\n");
							getchar();
						}
						break;
					break;
				default:
					printf("Opcion invalida\n");
					break;
				}
				break;
			case 2:
				llen = llenado();
				switch(llen){
				case 'L':
					imprimirNodo(LG);
					getchar();
					break;
				case 'X':
					imprimirNodo(Xiaomi);
					getchar();
					break;
				case 'M':
					imprimirNodo(Moto);
					getchar();
					
					break;
				case 'S':
					imprimirNodo(Samsung);
					getchar();
					break;
				case 'H':
					imprimirNodo(Huawei);
					getchar();
					break;
				default:
					printf("Opcion invalida\n");
				}		break;
				break;
			case 3:
				imprimirrecibo(ListaC);
				guardarcliente(ListaC);
				guardar(LG, Xiaomi, Moto, Samsung, Huawei);
				break;
			}
			} while (op != 3);
		getchar();
	}
		
char llenado(){
	/*PREGUNTA POR LA MARCA DEL EQUIPO PARA PODER ASIGNARLA A LA LISTA CORRECTA*/
	char llen;
	printf("\nDe que marca es el equipo?\n (L)G\n (X)iaomi\n (M)oto\n (S)amsung\n (H)uawei\n ");
	scanf(" %c", &llen);
	
	printf("\n");
	return llen;
}
	
char llenadoCambiar(){
				/*PREGUNTA POR EL GENERO DE LA PELICULA PARA PODER ASIGNARLA A LA LISTA CORRECTA*/
	char llen;
	printf("\nDe que marca es el equipo que desea comprar?\n (L)G\n (X)iaomi\n (M)oto\n (S)amsung\n (H)uawei\n ");
	scanf(" %c", &llen);
	printf("\n");
	return llen;
}
	
	
nodoC *agregarCompra(nodoC *celular , char name[MAX], int compra, int precio, char llen){
			char nombre[MAX]     = {'\0'};
			nodoC *nuevoNodo;
			int i;
			
			nuevoNodo = (nodoC *)malloc(sizeof(nodoC));
			strcpy(nombre, name);
			
			
			for (i = 0; nombre[i] != '\0' ; ++i) {
				nombre[i] = toupper(nombre[i]);
			}
			
			strcpy((*nuevoNodo).modelo, nombre);
			nuevoNodo->precio = precio;
			
			nuevoNodo->cantidad = compra;
			switch(llen){
			case 'L':
				strcpy(nuevoNodo->marca, "LG");
				break;
			case 'X':
				strcpy(nuevoNodo->marca, "XIAOMI");
				break;
			case 'M':
				strcpy(nuevoNodo->marca, "MOTO");
				break;
			case 'S':
				strcpy(nuevoNodo->marca, "SAMSUNG");
				break;
			case 'H':
				strcpy(nuevoNodo->marca, "HUAWEI");
				break;
			}
			nuevoNodo->sig = celular;
			celular = nuevoNodo;
			return celular;
}
			
int buscarEquipo(nodoM *Lista, char nombreBuscar[MAX]){
			nodoM *aux = Lista;
			int bandera1 = 0;
			for (int i = 0; nombreBuscar[i] != '\0' ; ++i) {
				nombreBuscar[i] = toupper(nombreBuscar[i]);
			}
			if (Lista == NULL) {
				bandera1 = 0;
			}
			else{	
				if (strcmp(aux->modelo, nombreBuscar) == 0) {
					bandera1 = 1;	
				}
				else{
					while(strcmp(aux->modelo, nombreBuscar) != 0 && aux->sig != NULL){
						if (strcmp((aux->sig)->modelo,nombreBuscar) == 0 && aux->existencias == 0) {
							bandera1 = 0;
							printf("Existecia no disponible");
						}
						if (strcmp((aux->sig)->modelo,nombreBuscar) == 0) {
							bandera1 = 1;
							break;
						}
						aux = aux->sig;
					}
				}
			}
			return bandera1;
}
	
	
nodoM *obtenerAux(nodoM *celular, char nombreBuscar[MAX]){
		nodoM *aux = celular;
		while(strcmp(aux->modelo, nombreBuscar) && aux->sig != NULL){
			aux = aux->sig;
		}
	return aux;
}

nodoM *agregarNodo(nodoM *Lista, char name[MAX], int precio, int capacidad, int existencias){
			char nombre[MAX]     = {'\0'};
			nodoM *nuevoNodo;
			int i;
			nuevoNodo = (nodoM *)malloc(sizeof(nodoM));
			strcpy(nombre, name);
			
			for (i = 0; nombre[i] != '\0' ; ++i) {
				nombre[i] = toupper(nombre[i]);
			}
			
			strcpy((*nuevoNodo).modelo, nombre);
			nuevoNodo->precio = precio;
			nuevoNodo->capacidad = capacidad;
			nuevoNodo->existencias = existencias;
			
			nuevoNodo->sig = Lista;
			Lista = nuevoNodo;
			return Lista;
}
			
nodoM *modificarNodo(nodoM *Lista, char nombreBuscar[MAX]){
			nodoM *auxB;
			nodoM *anterior = NULL;
			auxB = Lista;
			
			while((auxB != NULL) && strcmp(auxB->modelo, nombreBuscar) != 0 ){
				anterior = auxB;
				auxB = auxB->sig;
				if (auxB == NULL)
				{
					printf("No existe el elemento en la lista\n");
				}
			}
			
			if (anterior == NULL)
			{
				Lista = Lista->sig;
				free(auxB);
			}
			else{
				anterior->sig = auxB->sig;
				free(auxB);
			}
			return Lista;
}


void imprimirNodo(nodoM *Lista){
	nodoM *aux;
	aux = Lista;
				
	while (aux != NULL) {
	printf("Modelo: %s\n", aux->modelo);
	printf("Precio: %d\n", aux->precio);
	printf("Capacidad: %d GB\n ", aux->capacidad);
	printf("Existencias: %d\n", aux->existencias);
	printf("\n");
	aux = aux->sig;
	}
}			

void imprimirrecibo(nodoC *ListaC){
		nodoC *aux;
		aux = ListaC;
		int pre=0;
		
		printf("COMPROBANTE DE PAGO\n Tienda XCD S.A de C.V \t\t\n\n");
		while (aux != NULL) {
			printf("%s %s %d X %d\n", aux->marca, aux->modelo, aux->cantidad, aux->precio);
			pre = pre + aux->precio;
			aux = aux->sig;
			
		}
		printf("---------------\n\nTotal: %d ", pre);
		
}			
		
void guardarcliente(nodoC *ListaC){
	nodoC *auxc = ListaC;
	FILE *f;
	char nombre[MAX] = {'\0'};
	f = fopen("compras.db", "wb");
	
	while (auxc != NULL) {
		strcpy(nombre, auxc->modelo);
		
		for (int i = 0; nombre[i] != '\0'; ++i) {
			if (nombre[i] == ' ') {
				nombre[i] = '_';
			}	
		}
		
		fprintf(f, "%s %s %d %d %d",auxc->marca, auxc->modelo, auxc->precio, auxc->cantidad);	
		fprintf(f, "\n");
		
		auxc = auxc->sig;
	}
	
	fclose(f);
}

void guardar(nodoM *LG, nodoM *Xiaomi, nodoM *Moto, nodoM *Samsung, nodoM *Huawei){ 
		nodoM   *auxL = LG;
		nodoM  *auxX = Xiaomi;
		nodoM *auxM = Moto;
		nodoM  *auxS = Samsung;
		nodoM *auxH = Huawei;
		FILE *fp;
		char nombre[MAX] = {'\0'};
		fp = fopen("SmartphonesDB.txt", "w");
					
			while (auxL != NULL) {
				strcpy(nombre, auxL->modelo);
					
				for (int i = 0; nombre[i] != '\0'; ++i) {
					if (nombre[i] == ' ') {
						nombre[i] = '_';
						}	
				}
					
			fprintf(fp, "LG %s %d %d %d", nombre, auxL->precio, auxL->capacidad, auxL->existencias);	
			fprintf(fp, "\n");
					
				auxL = auxL->sig;
				}
					
			while (auxX != NULL) {
				strcpy(nombre, auxX->modelo);
				
				for (int i = 0; nombre[i] != '\0'; ++i) {
					if (nombre[i] == ' ') {
						nombre[i] = '_';
					}	
				}
						
			fprintf(fp, "XIAOMI %s %d %d %d", nombre, auxX->precio, auxX->capacidad, auxX->existencias);	
			fprintf(fp, "\n");
					
			auxX = auxX->sig;
			}
					
			while (auxM != NULL) {
				strcpy(nombre, auxM->modelo);
						
				for (int i = 0; nombre[i] != '\0'; ++i) {
					if (nombre[i] == ' ') {
						nombre[i] = '_';
						}	
				}
					
			fprintf(fp, "MOTO %s  %d  %d %d", nombre, auxM->precio, auxM->capacidad, auxM->existencias);	
			fprintf(fp, "\n");
						
			auxM = auxM->sig;
			}	
					
			while (auxS != NULL) {
				strcpy(nombre, auxS->modelo);
						
				for (int i = 0; nombre[i] != '\0'; ++i) {
					if (nombre[i] == ' ') {
						nombre[i] = '_';
					}	
				}
						
			fprintf(fp, "SAMSUNG %s  %d  %d %d", nombre, auxS->precio, auxS->capacidad, auxS->existencias);	
			fprintf(fp, "\n");
						
			auxS = auxS->sig;
			}
					
	while (auxH != NULL) {
	strcpy(nombre, auxH->modelo);
				
	for (int i = 0; nombre[i] != '\0'; ++i) {
	     if (nombre[i] == ' ') {
			nombre[i] = '_';
		}	
	}
	
	fprintf(fp, "HUAWEI %s  %d  %d %d", nombre, auxH->precio, auxH->capacidad, auxH->existencias);	
	fprintf(fp, "\n");
	auxH = auxH->sig;
	}
	fclose(fp);
} 
					
