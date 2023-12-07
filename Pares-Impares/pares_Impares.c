/*Ejercicio 1: Escriba un programa que lea numeros hasta encontrar un 0, 
y almacene los pares en un arreglo PARES y los impares en un arreglo IMPARES. 
Cuando el programa termine el programa debe imprimir el numero de pares 
y a continuacion el contenido de PARES, y despues el numero de impares 
y a continuacion el contenido de IMPARES.*/

#include <stdio.h>
#define MAX 10

 int main(){
 	
 	int d, re, x, contp, conti, i, k, j, l, m;
 	int IMPAR[MAX]={0,0,0,0,0,0,0,0,0,0}; /*Rellena las matrices con 0*/
	int PAR[MAX]={0,0,0,0,0,0,0,0,0,0};
	
 	contp=0; /*Contador para numeros pares*/
 	conti=0; /*Contador para numeros impares*/
 	j=0;
 	k=0;

 	printf("Escriba la cantidad de numeros a ingresar\n");
 	scanf("%d", &d);
 	if(d>0){ /*Verifica que la cantidad a ingresar sea mayor a 0*/
 		for (i=0; i<=d-1; i++){
 				printf("Ingrese su numero por favor\n", i);
				scanf("%d", &x);
				if(x==0){
					printf("El numero es 0 \n");
				}else{
						re= x % 2; /*Verifica si el numero es par o no*/
		 			if (re==0){
			 			contp+= 1; /*Asigna el valor al arreglo ademas de sumar uno al contador de pares*/
			 			PAR[j]= x;
			 			j++;
			    	}
					if(re!=0){ /*Asigna el valor al arreglo ademas de sumar uno al contador de Impares*/
							conti+= 1;
							IMPAR[k]= x;
							k++;
			     	}
			     		printf("Usted ingreso %d numeros pares\n", contp);
						for(l=0; l<MAX; l++) printf("%d\n", PAR[l]);
						printf("\n");
						printf("Usted ingreso %d numeros impares\n", conti);
						for(m=0; m<MAX; m++) printf("%d\n", IMPAR[m]);
						printf("\n");
				}
		 }
	}
 	getchar();
 }
