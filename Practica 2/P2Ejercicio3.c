//Mostrar el complemento a 1

#include <stdio.h>
#define MAX 32768

	int main(){
	
		int i;
		unsigned int num, cont;
	
		printf("\n//Complemento A1 de un numero entero\n\n");
		printf("//Dame un numero entero entre 0 y 65535: \n");
		scanf("%i",&num);
	
		if(num>65535 || num<0){ /*Valida el numero maximo*/
			printf("Numero no valido\n");
		}
		else{
			printf("\nEl numero en base 2 es: ");
			for(cont=MAX;cont>0;cont>>=1){ /*Corrimiento y Mascara*/
				if(num&cont)
				 printf("1");
				else printf("0");
			}
			cont=MAX;
			for(i=1;i<=cont;i<<=1){ /*Complemento en decimal*/
				if(num&i) num= num^i;
				else  num= num|i;		
			}
			printf("\n \nSu complemento en base 10 es: %i",num);
			printf("\nSu complemento en base 2 es: ");	
			for(cont=MAX;cont>0;cont>>=1){ /*Complemento de a1 en base 2*/
				if(num&cont)
				   	 printf("1");
				else printf("0");
			}		
			printf("\n");
		}
		getchar();
		return 0;
	}	

