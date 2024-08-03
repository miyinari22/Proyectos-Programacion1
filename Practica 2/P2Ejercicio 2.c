#include <stdio.h>
int main(){
    int op;
    float precio, predes;
    
    	printf("\n\tDigite el tipo de descuento segun corresponda:\n\n 1.- Discapacitado/3ra Edad\n"); 
		printf(" 2.- Diabetico/Hipertenso\n 3.- Cliente frecuente\n 4.- Ninguno\n ");
		scanf("%d",&op);
		if (op==1){
			printf("Ingrese el precio del producto\n");
            scanf("%f", &precio);
            predes=precio*0.80;
            printf("El precio es: %.2f", predes);
        }
        else{
        	if(op==2){
        		printf("Ingrese el precio del producto\n");
                scanf("%f", &precio);
                predes=precio*0.90;
                printf("El precio es: %.2f", predes);
			}
			else{
				if (op==3){
					printf("¿Cuenta con otro tipo de descuento?\n Digite segun corresponda\n 1.- Discapacitado/3ra Edad\n 2.- Diabetico/Hipertenso\n 3.- Ninguno\n");
                	scanf("%d", &op);
                	if (op=1){
						printf("Ingrese el precio del producto\n");
            			scanf("%f", &precio);
            			predes=precio*0.80;
            			printf("El precio es: %.2f", predes);
       		 		}
        			else{
        				if(op==2){
        					printf("Ingrese el precio del producto\n");
                			scanf("%f", &precio);
               			 	predes=precio*0.90;
                			printf("El precio es: %.2f", predes);
						}
						else{
							if(op==3){
								printf("Ingrese el precio del producto\n");
                        		scanf("%f", &precio);
                        		predes=precio*0.93;
                        		printf("El precio es de:\n%.2f", predes);
							}
						}
					}
				}
			}		
   		}	
   }
    
