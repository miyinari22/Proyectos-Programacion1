/*Algoritmo MinyMaxSerie [Este programa determina el numero minimo y maximo de una serie sin arreglos] */
#include <stdio.h>
#include <conio.h>

int main () {

int i, max, min, sn, n, x;
   max=0;
   min=0;

printf("Ingrese una cantidad para la serie\n");
scanf("%d", &sn);
for(i=0; i<sn; i++){
    printf("Ingrese el numero: %d\n", i);
    scanf("%d", &n);
    	if(n==-1){
		printf("Fin del programa");
		} 
		else{
		if(sn>0);
    	max=n;
    	}
	min=n;
	if(n<0) min=n;
}

printf("El numero minimo es:%d\n", min);
printf("El numero maximo es:%d\n", max);
printf("El ultimo numero esta en la posicion: %f\n", sn); 

getchar();
}

