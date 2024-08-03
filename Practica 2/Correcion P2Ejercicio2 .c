#include <stdio.h>
int main(){
    int op, des;
    float precio, predes;
    
    	printf("\n\tDigite el tipo de descuento segun corresponda:\n\n 1.- Discapacitado/3ra Edad\n"); 
		printf(" 2.- Diabetico/Hipertenso\n 3.- Cliente frecuente\n 4.- Ninguno\n ");
		scanf("%d",&op);
		if (op==1){
			printf("Usted tiene tarjeta de cliente frecuente?\n presione 1 para si y 0 para no\n");
			scanf("%d", &des);
			if (des==0){
				printf("Ingrese el precio del producto\n");
            	scanf("%f", &precio);
            	predes=precio*0.2;
            	printf("El precio es: %.2f", predes);
			}else{
				printf("Ingrese el precio del producto\n");
            	scanf("%f", &precio);
            	predes=precio*0.27;
            	printf("El precio es: %.2f", predes);
			}
			
        }
        else{
        	if(op==2){
        		printf("Usted tiene tarjeta de cliente frecuente?\n presione 1 para si y 0 para no\n");
				scanf("%d", &des);
				if(des==0){
					printf("Ingrese el precio del producto\n");
                	scanf("%f", &precio);
                	predes=precio*0.10;
                	printf("El precio es: %.2f", predes);	
				}else{
					printf("Ingrese el precio del producto\n");
                	scanf("%f", &precio);
                	predes=precio*0.17;
                	printf("El precio es: %.2f", predes);
				}
        	
			}
			else{
				if (op==3){
					printf("¿Cuenta con otro tipo de descuento?\n Digite segun corresponda\n 1.- Discapacitado/3ra Edad\n 2.- Diabetico/Hipertenso\n 3.- Ninguno\n");
                	scanf("%d", &op);
                	if (op==1){
						printf("Ingrese el precio del producto\n");
            			scanf("%f", &precio);
            			predes=precio*0.27;
            			printf("El precio es: %.2f", predes);
       		 		}
        			else{
        				if(op==2){
        					printf("Ingrese el precio del producto\n");
                			scanf("%f", &precio);
               			 	predes=precio*0.17;
                			printf("El precio es: %.2f", predes);
						}
						else{
							if(op==3){
								printf("Ingrese el precio del producto\n");
                        		scanf("%f", &precio);
                        		predes=precio*0.07;
                        		printf("El precio es de:\n%.2f", predes);
							}
						}
					}
				}
			}		
   		}	
   }
    
