/*Alumno:  Octavio Augusto Martinez Reyes  Matricula: 201904948*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define MAX 20 /*Maximo de caracteres para ingresar el modelo*/

typedef struct raiz{ 
	char modelo[MAX];
	int precio;
	int capacidad;
	int existencias;
	struct raiz *sig;
	
}nodoM; 

char llenado();
void guardar(nodoM *LG, nodoM *Xiaomi, nodoM *Moto, nodoM *Samsung, nodoM *Huawei); 

nodoM *agregarNodo(nodoM *celular, char name[MAX], int precio, int capacidad, int existencias);
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
		nodoM  *LG   = NULL;
		nodoM  *Xiaomi  = NULL;
		nodoM *Moto = NULL;
		nodoM  *Samsung  = NULL;
		nodoM *Huawei=NULL;
		
		FILE *fp;
		char typeOf[20] = {'\0'};
		int op;
		
		char nombreAgregar[MAX];
		int precioAgregar, capacidadAgregar, existenciasAgregar;
		char name[MAX];
		int precio, capacidad, existencias;
		
		char llen;
		
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
			printf("\t\tBIENVENIDO\t\t\nQue desea hacer?\n\n1.-Registrar Equipo\n2.-Mostrar Equipos\n");
			printf("3.-Salir\n\n SI PRESIONA SALIR SE GUARDARAN SUS DATOS\n");
			scanf("%d", &op);
			switch(op){
			case 1:
				llen = llenado();
				switch(llen){
				case 'L':
					printf("Ingrese el modelo del equipo: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Precio (6 Digitos): ");
					scanf("%d", &precio);
					fflush(stdin);
					printf("Capacidad (3 Digitos): ");
					scanf("%d", &capacidad);
					fflush(stdin);
					printf("Existencias (2 Digitos): ");
					scanf("%d", &existencias);
					fflush(stdin);
					LG = agregarNodo(LG, name, precio, capacidad, existencias);
					break;
				case 'X':
					printf("Ingrese el modelo del equipo: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Precio (6 Digitos): ");
					scanf("%d", &precio);
					fflush(stdin);
					printf("Capacidad (3 Digitos): ");
					scanf("%d", &capacidad);
					fflush(stdin);
					printf("Existencias (2 Digitos): ");
					scanf("%d", &existencias);
					fflush(stdin);
					Xiaomi = agregarNodo(Xiaomi, name, precio, capacidad, existencias);
					break;
				case 'M':
					printf("Ingrese el modelo del equipo: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Precio (6 Digitos): ");
					scanf("%d", &precio);
					fflush(stdin);
					printf("Capacidad (3 Digitos): ");
					scanf("%d", &capacidad);
					fflush(stdin);
					printf("Existencias (2 Digitos): ");
					scanf("%d", &existencias);
					fflush(stdin);
					Moto = agregarNodo(Moto, name, precio, capacidad, existencias);
					break;
				case 'S':
					printf("Ingrese el modelo del equipo: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Precio (6 Digitos): ");
					scanf("%d", &precio);
					fflush(stdin);
					printf("Capacidad (3 Digitos): ");
					scanf("%d", &capacidad);
					fflush(stdin);
					printf("Existencias (2 Digitos): ");
					scanf("%d", &existencias);
					fflush(stdin);
					Samsung = agregarNodo(Samsung, name, precio, capacidad, existencias);
					break;
				case 'H':
					printf("Ingrese el modelo del equipo: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Precio (6 Digitos): ");
					scanf("%d", &precio);
					fflush(stdin);
					printf("Capacidad (3 Digitos): ");
					scanf("%d", &capacidad);
					fflush(stdin);
					printf("Existencias (2 Digitos): ");
					scanf("%d", &existencias);
					fflush(stdin);
					Huawei = agregarNodo(Huawei, name, precio, capacidad, existencias);
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
				guardar(LG, Xiaomi, Moto, Samsung, Huawei);
				break;
			}
		} while (op != 3);
		getchar();
}

char llenado(){
	char llen;
	printf("\nDe que marca es el equipo?\n (L)G\n (X)iaomi\n (M)oto\n (S)amsung\n (H)uawei\n ");
	scanf(" %c", &llen);
	
	printf("\n");
	return llen;
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
			
			fprintf(fp, "MOTO %s  %d %d %d", nombre, auxM->precio, auxM->capacidad, auxM->existencias);	
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
	
		
