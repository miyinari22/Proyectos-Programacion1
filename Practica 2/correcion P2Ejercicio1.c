/*1.	Determinar el total de impuesto a pagar por un trabajador de acuerdo a los siguientes criterios:
-Si al anjo gano mas o igual a 400,000 pesos, debe pagar un impuesto del 20% sobre lo que gano
-Si al anjo gano menos de 400,000 pesos, debe  pagar un impuesto del 16% sobre lo ganado.
Independientemente de cuando gano al anjo, puede deducir gastos y de esta manera ganar un reembolso.
Por cada factura se le deducira un 2%, siempre y cuando el total del reembolso no exceda 5,000 pesos*/
#include <stdio.h>

int main(){
	
	int numfact, i;
	float des1, des2, gan, fact;
	
	des2=0;
	
	printf("Ingrese cuanto gano al anjo\n");
	scanf("%f", &gan);
	printf("Ingrese la cantidad de facturas a deducir\n");
	scanf("%d", &numfact);
	
	for (i=0; i<numfact; i++){
		printf("Ingrese gasto de la factura\n");
		scanf("%f", &fact);
		des1=fact*.02;
		des2=des1+des2;
	}
		if (des2>0 && des2<5000) printf ("Su descuento es de: %.2f \n", des2);
		if (gan>= 400000){
			des1=.02*gan;
			printf("El impuesto a pagar es de: %f \n", des1);
		}else{
			des1=.16*gan;
			printf("El impuesto a pagar es de : %f \n", des1);
		}
}
