/*Alumno: Octavio Augusto Martinez Reyes
Matricula: 201904948 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 /*Se pueden guardar 2 tipos de modelos diferentes, 2 por cada marca*/

typedef struct marcas{
	int marca;
	char modelo[8]; /*Maximo de caracteres para ingresar el modelo*/
	int memoria;
	int precio;
	int existencias;	
	
}marcas;

int menu();

int main(){
	
	marcas A[MAX]; /*Arreglo de los celulares*/
	menu(A); /*Funcion menu*/
	
	return 0;
}

int menu(marcas A[]){
	int op;
	int i;
	FILE *f;

	f= fopen("smartphonedb.txt", "w"); /*Se abre o crea el archivo*/
	if(f!=NULL){
		do{
			for(i=0; i<10; i++){
				printf("Bienvenido\n\nQue marca es el celular a ingresar?\n\n1) LG\n2) Xiaomi\n3) Moto\n4) Samsung\n5) Huawei\n");
				printf("6) Salir del programa\n");
				scanf("%d", &op);
				switch(op){
						
					case 1: 
						A[i].marca=1; /*Utiliza la opcion del menu para identificar la marca del celular*/
						fprintf(f,"%d", i); /*Deja en el archivo en que posicion del arreglo se encuentra¨*/
						fprintf(f, " %d", A[i].marca); /*Guarda la opcion para identificar la marca*/
						printf("Ingrese el modelo del celular\n");
						scanf("%s", &A[i].modelo);
						fprintf(f, " %s", A[i].modelo); /*Guarda el modelo del celular*/
						printf("Ingrese capacidad de memoria (GB, utilice 3 caracteres)\n");
						scanf("%d", &A[i].memoria);
						fprintf(f, " %d", A[i].memoria); /*Guarda su capacidad*/
						printf("Ingrese precio (utilice 6 caracteres)\n");
						scanf("%d", &A[i].precio);
						fprintf(f, " %d", A[i].precio); /*Guarda su precio*/
						printf("Ingrese cantidad de existencias (utilice 2 caracteres)\n");
						scanf("%d", &A[i].existencias);
						fprintf(f, " %d\n", A[i].existencias); /*Guarda la cantidad de existencias*/
						break;
					case 2:
						A[i].marca=2; /*Utiliza la opcion del menu para identificar la marca del celular*/
						fprintf(f,"%d", i);
						fprintf(f, " %d", A[i].marca);
						printf("Ingrese el modelo del celular\n");
						scanf("%s", &A[i].modelo);
						fprintf(f, " %s", A[i].modelo);
						printf("Ingrese capacidad de memoria (GB, utilice 3 caracteres)\n");
						scanf("%d", &A[i].memoria);
						fprintf(f, " %d", A[i].memoria);
						printf("Ingrese precio (utilice 6 caracteres)\n");
						scanf("%d", &A[i].precio);
						fprintf(f, " %d", A[i].precio);
						printf("Ingrese cantidad de existencias (utilice 2 caracteres)\n");
						scanf("%d", &A[i].existencias);
						fprintf(f, " %d\n", A[i].existencias);
						break;
					case 3:
						A[i].marca=3; /*Utiliza la opcion del menu para identificar la marca del celular*/
						fprintf(f,"%d", i);
						fprintf(f, " %d", A[i].marca);
						printf("Ingrese el modelo del celular\n");
						scanf("%s", &A[i].modelo);
						fprintf(f, " %s", A[i].modelo);
						printf("Ingrese capacidad de memoria (GB, utilice 3 caracteres)\n");
						scanf("%d", &A[i].memoria);
						fprintf(f, " %d", A[i].memoria);
						printf("Ingrese precio (utilice 6 caracteres)\n");
						scanf("%d", &A[i].precio);
						fprintf(f, " %d", A[i].precio);
						printf("Ingrese cantidad de existencias (utilice 2 caracteres)\n");
						scanf("%d", &A[i].existencias);
						fprintf(f, " %d\n", A[i].existencias);
						break;
					case 4:
						A[i].marca=4;/*Utiliza la opcion del menu para identificar la marca del celular*/
						fprintf(f,"%d", i);
						fprintf(f, " %d", A[i].marca);
						printf("Ingrese el modelo del celular\n");
						scanf("%s", &A[i].modelo);
						fprintf(f, " %s", A[i].modelo);
						printf("Ingrese capacidad de memoria (GB, utilice 3 caracteres)\n");
						scanf("%d", &A[i].memoria);
						fprintf(f, " %d", A[i].memoria);
						printf("Ingrese precio (utilice 6 caracteres)\n");
						scanf("%d", &A[i].precio);
						fprintf(f, " %d", A[i].precio);
						printf("Ingrese cantidad de existencias (utilice 2 caracteres)\n");
						scanf("%d", &A[i].existencias);
						fprintf(f, " %d\n", A[i].existencias);
						break;
					case 5:
						A[i].marca=5;/*Utiliza la opcion del menu para identificar la marca del celular*/
						fprintf(f,"%d", i);
						fprintf(f, " %d", A[i].marca);
						printf("Ingrese el modelo del celular\n");
						scanf("%s", &A[i].modelo);
						fprintf(f, " %s", A[i].modelo);
						printf("Ingrese capacidad de memoria (GB, utilice 3 caracteres)\n");
						scanf("%d", &A[i].memoria);
						fprintf(f, " %d", A[i].memoria);
						printf("Ingrese precio (utilice 6 caracteres)\n");
						scanf("%d", &A[i].precio);
						fprintf(f, " %d", A[i].precio);
						printf("Ingrese cantidad de existencias (utilice 2 caracteres)\n");
						scanf("%d", &A[i].existencias);
						fprintf(f, " %d\n", A[i].existencias);
						break;
					case 6: 
						fclose(f);/*Cuando salga del programa se cierra tambien el archivo*/
						exit(0) ; /*Cierra el programa automaticamente despues de guardar*/
				}
				
			}
		}while(op<6); 
	}
}
