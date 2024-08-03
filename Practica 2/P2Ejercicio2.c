#include <stdio.h>
int main(){
    int tipo;
    float precio, predes;
    
    	printf("\n\tDigite el tipo de descuento segun corresponda:\n\n 1.- Discapacitado/3ra Edad\n 2.- Diabetico/Hipertenso\n 3.- Cliente frecuente\n 4.- Ninguno\n");
    	scanf("%d", &tipo);
    switch(tipo){
        case 1: printf("Ingrese el precio del producto\n");
                scanf("%f", &precio);
                predes=precio*0.80;
                printf("El precio es: %.2f", predes);
                break;
        case 2: printf("Ingrese el precio del producto\n");
                scanf("%f", &precio);
                predes=precio*0.90;
                printf("El precio es: %.2f", predes);
                break;
        case 3: printf("¿Cuenta con otro tipo de descuento?\n Digite segun corresponda\n 1.- Discapacitado/3ra Edad\n 2.- Diabetico/Hipertenso\n 3.- Ninguno\n");
                scanf("%d", &tipo);
                switch(tipo){
                	case 1: printf("Ingrese el precio del producto\n");
                        	scanf("%f", &precio);
                        	predes=precio*0.73;
                        	printf("El precio es:\n%.2f",predes);
                        	break;
                	case 2: printf("Ingrese el precio del producto\n");
                        	scanf("%f", &precio);
                        	predes=precio*0.83;
                        	printf("El precio es:\n%.2f",predes);
                        	break;
                	case 3: printf("Ingrese el precio del producto\n");
                        	scanf("%f", &precio);
                        	predes=precio*0.93;
                        	printf("El precio es de:\n%.2f", predes);
                        	break;
                	default: printf("Ingrese un numero correcto");
                        	 scanf("%d", &tipo);
                         	break;
                }
        case 4: printf("\nUsted no tiene descuento\n");
                break;
        default: printf("\nIngrese un numero correcto\n");
                 scanf("%d", &tipo);
                 break;
    }
    getchar();
}
