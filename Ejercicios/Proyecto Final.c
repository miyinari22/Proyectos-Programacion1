/*Integrantes: 						Fecha de inicio: 26 de Mayo de 2020			Fecha de conclusion: 5 Junio 2020
Octavio Augusto Martinez Reyes*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define twitter 280 /*Maximo de caracteres para describir algo con holgura*/
#define Titulo 30 /*Maximo de caracteres para ingresar el titulo de la pelicula*/

typedef struct raiz{ /*Estructura para un solo tipo de genero*/
	char nombre[Titulo];
	int anjo;
	int duracion;
	char sinop[twitter];
	struct raiz *sig;
	
}nodoP; /*Nodo Pelicula*/

char llenado();
char llenadoCambiar();
void guardar(nodoP *ListaDrama, nodoP *ListaAccion, nodoP *ListaTerror, nodoP *ListaComedia); 

nodoP *agregarNodo(nodoP *Lista, char name[Titulo], char sinopsis[twitter], int fecha, int duracion);
nodoP *ordenarNodo(nodoP *Lista);
nodoP *obtenerAux(nodoP *Lista, char nombreBuscar[Titulo]);
nodoP *eliminarNodo(nodoP*Lista, char nombreBuscar[Titulo]);
int buscarPelicula(nodoP *Lista, char nombreBuscar[Titulo]);
void imprimirNodo(nodoP *Lista);

void menu();

int main(){
	menu();
	return 0;
}
	
void menu(){
		/*SE INICIALIZAN LAS LISTAS EN NULL 
		---------------------------------
		*/
		nodoP  *ListaDrama   = NULL, *auxDrama;
		nodoP  *ListaAccion  = NULL, *auxAccion;
		nodoP *ListaComedia = NULL, *auxComedia;
		nodoP  *ListaTerror  = NULL, *auxTerror;
		FILE *fp;
		char typeOf[20] = {'\0'};
		int op;
		
		char nombreAgregar[Titulo], sinopAgregar[twitter];
		int fechaAgregar, duracionAgregar;
		char name[Titulo], sinopsis[twitter];
		int fecha, duracion;
		
		char llen, gen;
		int bandera;
		
		fp = fopen("Listas.db", "rb");	
		if (fp == NULL) {
			printf("No se pudo abrir archivo\n");
		}
		else{
			while (!feof(fp)) {
				fscanf(fp, "%s", typeOf);	
				fflush(stdin);
				fscanf(fp, "%s", nombreAgregar);
				fflush(stdin);
				fscanf(fp, "%s", sinopAgregar);
				fflush(stdin);
				fscanf(fp, "%d", &fechaAgregar);
				fflush(stdin);
				fscanf(fp, "%d", &duracionAgregar);
				
				if (!feof(fp)) {
					for (int i = 0; nombreAgregar[i] != '\0'; ++i) {
						if (nombreAgregar[i] == '_') {
							nombreAgregar[i] = ' ';	
						}	
					}
					
					for (int i = 0; sinopAgregar[i] != '\0'; ++i) {
						if (sinopAgregar[i] == '_') {
							sinopAgregar[i] = ' ';	
						}	
					}
					
					if (strcmp(typeOf, "DRAMA") == 0) {
						ListaDrama = agregarNodo(ListaDrama, nombreAgregar, sinopAgregar, fechaAgregar, duracionAgregar);
					}
					if (strcmp(typeOf, "ACCION") == 0) {
						ListaAccion = agregarNodo(ListaAccion, nombreAgregar, sinopAgregar, fechaAgregar, duracionAgregar);
					}
					if (strcmp(typeOf, "COMEDIA") == 0) {
						ListaComedia = agregarNodo(ListaComedia, nombreAgregar, sinopAgregar, fechaAgregar, duracionAgregar);
					}
					if (strcmp(typeOf, "TERROR") == 0) {
						ListaTerror = agregarNodo(ListaTerror, nombreAgregar, sinopAgregar, fechaAgregar, duracionAgregar);
					}
				}
				
			}
			fclose(fp);
		}
		
		/*MENU PRINCIPAL*/
		do {
			printf("\t\tBIENVENIDO\t\t\nQue desea hacer?\n\n1.-Ingresar Pelicula\n2.-Modificar Datos\n3.-Mostrar Peliculas\n");
			printf("4.-Salir\n\n SI PRESIONA OTRA OPCION SALDRA AUTOMATICAMENTE\n");
			scanf("%d", &op);
			switch(op){
			case 1:
				llen = llenado();
				switch(llen){
				case 'T':
					printf("Nombre de la pelicula: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Sinopsis de la pelicula: ");
					scanf(" %[^\n]", sinopsis);
					fflush(stdin);
					printf("Fecha de la pelicula: ");
					scanf("%d", &fecha);
					fflush(stdin);
					printf("Duracion de la pelicula (minutos): ");
					scanf("%d", &duracion);
					fflush(stdin);
					ListaTerror = agregarNodo(ListaTerror, name, sinopsis, fecha, duracion);
					break;
				case 'C':
					printf("Nombre de la pelicula: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Sinopsis de la pelicula: ");
					scanf(" %[^\n]", sinopsis);
					fflush(stdin);
					printf("Fecha de la pelicula: ");
					scanf("%d", &fecha);
					fflush(stdin);
					printf("Duracion de la pelicula (en minutos): ");
					scanf("%d", &duracion);
					fflush(stdin);
					ListaComedia = agregarNodo(ListaComedia, name, sinopsis, fecha, duracion);
					break;
				case 'D':
					printf("Nombre de la pelicula: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Sinopsis de la pelicula: ");
					scanf(" %[^\n]", sinopsis);
					fflush(stdin);
					printf("Fecha de la pelicula: ");
					scanf("%d", &fecha);
					fflush(stdin);
					printf("Duracion de la pelicula (en minutos): ");
					scanf("%d", &duracion);
					fflush(stdin);
					ListaDrama = agregarNodo(ListaDrama, name, sinopsis, fecha, duracion);
					break;
				case 'A':
					printf("Nombre de la pelicula: ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					printf("Sinopsis de la pelicula: ");
					scanf(" %[^\n]", sinopsis);
					fflush(stdin);
					printf("Fecha de la pelicula: ");
					scanf("%d", &fecha);
					fflush(stdin);
					printf("Duracion de la pelicula (en minutos): ");
					scanf("%d", &duracion);
					fflush(stdin);
					ListaAccion = agregarNodo(ListaAccion, name, sinopsis, fecha, duracion);
					break;
				default:
					printf("Opcion invalida\n");
					break;
				}
				break;
			case 2:
				llen = llenado();
				switch(llen){
				case 'T':
					printf("Nombre de la pelicula (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarPelicula(ListaTerror, name);
					if (bandera == 1) {
						llen = llenadoCambiar();
						auxTerror = obtenerAux(ListaTerror, name);
						strcpy(sinopsis, auxTerror->sinop);
						fecha = auxTerror->anjo;
						duracion = auxTerror->duracion;
						if (llen == 'A') {
							ListaAccion = agregarNodo(ListaAccion, name, sinopsis, fecha, duracion);
							ListaTerror = eliminarNodo(ListaTerror, name);
						}
						if (llen == 'C') {
							ListaComedia = agregarNodo(ListaComedia, name, sinopsis, fecha, duracion);
							ListaTerror = eliminarNodo(ListaTerror, name);
						}
						if (llen == 'D') {
							ListaDrama = agregarNodo(ListaDrama, name, sinopsis, fecha, duracion);
							ListaTerror = eliminarNodo(ListaTerror, name);
						}
						if (llen == 'T') {
							printf("Su pelicula ya es de Terror\n");
							getchar();
						}
					}
					else{
						printf("\nNo se ha encontrado la pelicula, prueba con otra\nEnter para volver al menu\n");
						getchar();
					}
					break;
				case 'C':
					printf("Nombre de la pelicula (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarPelicula(ListaComedia, name);
					if (bandera == 1) {
						llen = llenadoCambiar();
						auxComedia = obtenerAux(ListaComedia, name);
						strcpy(sinopsis, auxComedia->sinop);
						fecha = auxComedia->anjo;
						duracion = auxComedia->duracion;
						if (llen == 'A') {
							ListaAccion = agregarNodo(ListaAccion, name, sinopsis, fecha, duracion);
							ListaComedia = eliminarNodo(ListaComedia, name);
						}
						if (llen == 'T') {
							ListaTerror = agregarNodo(ListaTerror, name, sinopsis, fecha, duracion);
							ListaComedia = eliminarNodo(ListaComedia, name);
						}
						if (llen == 'D') {
							ListaDrama = agregarNodo(ListaDrama, name, sinopsis, fecha, duracion);
							ListaComedia = eliminarNodo(ListaComedia, name);
						}
						if (llen == 'C') {
							printf("Su pelicula ya es de Comedia\n");
							getchar();
						}
					}
					else{
						printf("\nNo se ha encontrado la pelicula, prueba con otra\nEnter para volver al menu\n");
						getchar();
					}
					break;
				case 'D':
					printf("Nombre de la pelicula (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarPelicula(ListaDrama, name);
					if (bandera == 1) {
						llen = llenadoCambiar();
						auxDrama = obtenerAux(ListaDrama, name);
						strcpy(sinopsis, auxDrama->sinop);
						fecha = auxDrama->anjo;
						duracion = auxDrama->duracion;
						if (llen == 'A') {
							ListaAccion = agregarNodo(ListaAccion, name, sinopsis, fecha, duracion);
							ListaDrama = eliminarNodo(ListaDrama, name);
						}
						if (llen == 'T') {
							ListaTerror = agregarNodo(ListaTerror, name, sinopsis, fecha, duracion);
							ListaDrama = eliminarNodo(ListaDrama, name);
						}
						if (llen == 'C') {
							ListaComedia = agregarNodo(ListaComedia, name, sinopsis, fecha, duracion);
							ListaDrama = eliminarNodo(ListaDrama, name);
						}
						if (llen == 'D') {
							printf("Su pelicula ya es de Drama\n");
							getchar();
						}
					}
					else{
						printf("\nNo se ha encontrado la pelicula, prueba con otra\nEnter para volver al menu\n");
						getchar();
					}
					break;
				case 'A':
					printf("Nombre de la pelicula (Use Mayusculas): ");
					scanf(" %[^\n]", name);
					fflush(stdin);
					bandera = buscarPelicula(ListaAccion, name);
					if (bandera == 1) {
						llen = llenadoCambiar();
						auxAccion = obtenerAux(ListaAccion, name);
						strcpy(sinopsis, auxAccion->sinop);
						fecha = auxAccion->anjo;
						duracion = auxAccion->duracion;
						if (llen == 'T') {
							ListaTerror = agregarNodo(ListaTerror, name, sinopsis, fecha, duracion);
							ListaAccion = eliminarNodo(ListaAccion, name);
						}
						if (llen == 'C') {
							ListaComedia = agregarNodo(ListaComedia, name, sinopsis, fecha, duracion);
							ListaAccion = eliminarNodo(ListaAccion, name);
						}
						if (llen == 'D') {
							ListaDrama = agregarNodo(ListaDrama, name, sinopsis, fecha, duracion);
							ListaAccion = eliminarNodo(ListaAccion, name);
						}
						if (llen == 'A') {
							printf("Su pelicula ya es de Accion\n");
							getchar();
						}
					}
					else{
						printf("\nNo se ha encontrado la pelicula, prueba con otra\nEnter para volver al menu\n");
						getchar();
					}
					break;
				default:
					printf("Opcion invalida\n");
					break;
				}
				break;
			case 3:
				llen = llenado();
				switch(llen){
				case 'T':
					imprimirNodo(ListaTerror);
					getchar();
					break;
				case 'C':
					imprimirNodo(ListaComedia);
					getchar();
					break;
				case 'D':
					imprimirNodo(ListaDrama);
					getchar();
					
					break;
				case 'A':
					imprimirNodo(ListaAccion);
					getchar();
					break;
				default:
					printf("Opcion invalida\n");
				}		break;
				break;
			case 4:
				guardar(ListaDrama, ListaAccion, ListaTerror, ListaComedia);
				break;
			}
		} while (op != 4);
		getchar();
}

char llenado(){
			/*PREGUNTA POR EL GENERO DE LA PELICULA PARA PODER ASIGNARLA A LA LISTA CORRECTA*/
	char llen;
	printf("\nDe que genero es su pelicula?\n (T)error\n (C)omedia\n (D)rama\n (A)ccion\n ");
	scanf(" %c", &llen);
	
	printf("\n");
	return llen;
}

char llenadoCambiar(){
				/*PREGUNTA POR EL GENERO DE LA PELICULA PARA PODER ASIGNARLA A LA LISTA CORRECTA*/
	char llen;
	printf("\nA que genero desea cambiar su pelicula?\n (T)error\n (C)omedia\n (D)rama\n (A)ccion\n ");
	scanf(" %c", &llen);
	printf("\n");
	return llen;
}
	
nodoP *agregarNodo(nodoP *Lista, char name[Titulo], char sinopsis[twitter], int fecha, int duracion){
		char nombre[Titulo]     = {'\0'};
		nodoP *nuevoNodo;
		nuevoNodo = (nodoP *)malloc(sizeof(nodoP));
		strcpy(nombre, name);
		
		for (int i = 0; nombre[i] != '\0' ; ++i) {
			nombre[i] = toupper(nombre[i]);
		}
		
		strcpy((*nuevoNodo).nombre, nombre);
		strcpy((*nuevoNodo).sinop, sinopsis);
		nuevoNodo->anjo = fecha;
		nuevoNodo->duracion = duracion;
		
		nuevoNodo->sig = Lista;
		Lista = nuevoNodo;
		
		Lista = ordenarNodo(Lista);
		return Lista;
}
	
	
nodoP *ordenarNodo(nodoP *Lista){
			nodoP *aux, *siguiente;
			aux = Lista;
			char nombre[Titulo], sinopsis[twitter];
			int fecha;
			
			while(aux->sig != NULL){  
				siguiente = aux->sig;
				while(siguiente != NULL){
					if(strcmp(aux->nombre, siguiente->nombre) > 0){
						aux->sig = siguiente->sig;
						siguiente->sig = aux;
					}
					siguiente = siguiente->sig;
				}
				aux = aux->sig;
				siguiente = aux->sig;
			}
			return Lista;
}	
	

void imprimirNodo(nodoP *Lista){
		nodoP *aux;
		aux = Lista;

		while (aux != NULL) {
			printf("Nombre: %s\n", aux->nombre);
			printf("Sinopsis: %s\n", aux->sinop);
			printf("Anjo: %d\n", aux->anjo);
			printf("Duracion: %d minutos\n ", aux->duracion);
			printf("\n");
			aux = aux->sig;
		}
}			


int buscarPelicula(nodoP *Lista, char nombreBuscar[Titulo]){
			nodoP *aux = Lista;
			int bandera1 = 0;
			for (int i = 0; nombreBuscar[i] != '\0' ; ++i) {
				nombreBuscar[i] = toupper(nombreBuscar[i]);
			}
			if (Lista == NULL) {
				bandera1 = 0;
			}
			else{	
				if (strcmp(aux->nombre, nombreBuscar) == 0) {
					bandera1 = 1;	
				}
				else{
					while(strcmp(aux->nombre, nombreBuscar) != 0 && aux->sig != NULL){
						if (strcmp((aux->sig)->nombre,nombreBuscar) == 0) {
							bandera1 = 1;
							break;
						}
						aux = aux->sig;
					}
				}
			}
			return bandera1;
}
	
	
nodoP *obtenerAux(nodoP *Lista, char nombreBuscar[Titulo]){
		nodoP *aux = Lista;
		while(strcmp(aux->nombre, nombreBuscar) && aux->sig != NULL){
			aux = aux->sig;
		}
	return aux;
}

nodoP *eliminarNodo(nodoP *Lista, char nombreBuscar[Titulo]){
			nodoP *auxB;
			nodoP *anterior = NULL;
			auxB = Lista;
			
			while((auxB != NULL) && strcmp(auxB->nombre, nombreBuscar) != 0 ){
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


void guardar(nodoP *ListaDrama, nodoP *ListaAccion, nodoP *ListaTerror, nodoP *ListaComedia){ 
		nodoP   *auxD = ListaDrama;
		nodoP  *auxA = ListaAccion;
		nodoP *auxC = ListaComedia;
		nodoP  *auxT = ListaTerror;
		FILE *fp;
		char nombre[Titulo] = {'\0'}, sinopsis[twitter] = {'\0'};
		int fecha;
		fp = fopen("Listas.db", "wb");
		
		while (auxD != NULL) {
			strcpy(nombre, auxD->nombre);
			strcpy(sinopsis, auxD->sinop);
			
			for (int i = 0; nombre[i] != '\0'; ++i) {
				if (nombre[i] == ' ') {
					nombre[i] = '_';
				}	
			}
			
			for (int i = 0; sinopsis[i] != '\0'; ++i) {
				if (sinopsis[i] == ' ') {
					sinopsis[i] = '_';
				}	
			}
			
			fprintf(fp, "DRAMA %s  %s  %d %d", nombre, sinopsis, auxD->anjo, auxD->duracion);	
			fprintf(fp, "\n");
			
			auxD = auxD->sig;
		}
		while (auxA != NULL) {
			strcpy(nombre, auxA->nombre);
			strcpy(sinopsis, auxA->sinop);
			
			for (int i = 0; nombre[i] != '\0'; ++i) {
				if (nombre[i] == ' ') {
					nombre[i] = '_';
				}	
			}
			
			for (int i = 0; sinopsis[i] != '\0'; ++i) {
				if (sinopsis[i] == ' ') {
					sinopsis[i] = '_';
				}	
			}
			fprintf(fp, "ACCION %s  %s  %d %d", nombre, sinopsis, auxA->anjo, auxA->duracion);	
			fprintf(fp, "\n");
			
			auxA = auxA->sig;
		}
		while (auxC != NULL) {
			strcpy(nombre, auxC->nombre);
			strcpy(sinopsis, auxC->sinop);
			
			for (int i = 0; nombre[i] != '\0'; ++i) {
				if (nombre[i] == ' ') {
					nombre[i] = '_';
				}	
			}
			
			for (int i = 0; sinopsis[i] != '\0'; ++i) {
				if (sinopsis[i] == ' ') {
					sinopsis[i] = '_';
				}	
			}
			fprintf(fp, "COMEDIA %s  %s  %d %d", nombre, sinopsis, auxC->anjo, auxC->duracion);	
			fprintf(fp, "\n");
			
			auxC = auxC->sig;
		}	
		while (auxT != NULL) {
			strcpy(nombre, auxT->nombre);
			strcpy(sinopsis, auxT->sinop);
			
			for (int i = 0; nombre[i] != '\0'; ++i) {
				if (nombre[i] == ' ') {
					nombre[i] = '_';
				}	
			}
			
			for (int i = 0; sinopsis[i] != '\0'; ++i) {
				if (sinopsis[i] == ' ') {
					sinopsis[i] = '_';
				}	
			}
			fprintf(fp, "TERROR %s  %s  %d %d", nombre, sinopsis, auxT->anjo, auxT->duracion);	
			fprintf(fp, "\n");
			
			auxT = auxT->sig;
		}
		fclose(fp);
} 
	
		
