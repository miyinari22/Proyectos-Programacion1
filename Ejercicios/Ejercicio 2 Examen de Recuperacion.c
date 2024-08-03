/* Alumno: Octavio Augusto Martinez Reyes*/
#include <stdio.h>
#include <string.h>

int main(){
	
	char nombre[10][10];/*Guarda los nombres de los articulos*/
	float precio[10];
	int cantidad[10];
	int pos[10];
	int num, i, can, band, n; /*Variables para el numero de articulos y guardar datos para el arreglo*/
	float pre;
	
	band=0;
	
	printf("Cuantos articulos va a ingresar (Maximo 10)\n");
	scanf("%d", &num);
	
	for (i=0; i<num; i++){
		printf("Ingrese el articulo (10 caracteres)\n");
		scanf("%s", nombre[i]);
		
		
	}
	for (i=0; i<num; i++){
		printf("Ingrese las existencias del articulo %s\n", nombre[i]);
		scanf("%d", &can);
		cantidad[i]=can;
	}
	
	for(i=0; i<num; i++){
		printf("Ingrese el precio del articulo %s\n", nombre[i]);
		scanf("%f", &pre);
		precio[i]=pre;
	}
	
	for(i=0; i<num;i++){
		i=pos[i];
	}
	
	for(i=0; i<num; i++){ /*Intercambia las posiciones*/
		band=strcmp(nombre[i], nombre[i+1]);
		if(band=1){
			n=pos[i+1];
			pos[i+1]=pos[i];
			pos[i]=n;
		}
	}
	/*Imprime los datos*/
	printf("Los datos son (como entraron): \n Producto\t Existencia\t Precio\t\n");
	for(i=0; i<num; i++){
		printf("%s\t\t %d\t\t %f\t\t\n", nombre[i], cantidad[i], precio[i]);
	}
	
	printf("Los datos son (En orden): \nProducto\t Existencia\t Precio\t \n");
	for(i=0; i<num;i++){
		printf("%s\t %d\t %f\t\n", nombre[(pos[i])], cantidad[(pos[i])], precio[(pos[i])]);
	}
}
