#include <stdio.h>

int main(){
	
	int num[10];
	int n, i, re, cant;
	
	printf("Ingrese la cantidad de numeros a sumar: \n");
		scanf(" %d", &cant);
	
	for(i=0; i<cant; i++){
		printf("Ingrese el numero: \n");
		scanf("%d", &n);
		num[i] = n;
		re= re + n;
		if(i<10){
			num[10]=0;
		}
	}
	
	for(i=0; i<10; i++){
		printf("Los numeros sumados fueron %d \n", num[i]);
	}
	printf("\n La suma fue de: %d", re);
	return 0;
}
	
