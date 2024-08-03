/*Este programa realiza una sumatoria de n numeros*/
#include <stdio.h>

int main(){ /*Programa Principal*/
 int a1, a0, n, ai, i, j;
 float re;
 a0=0;
 a1=1;
 
 printf("Cuantos numeros va a sumar?\n");
 scanf("%d",&n);
 if(n>=1){
   	for(j=0; j<=n-1; j++){
       	printf("Ingrese el valor de ai: %d\n", j);
       	scanf("%d", &ai);
        	if(ai<0) ai*=-1; /*Valor absoluto*/
          		for(i=1;i<ai;i++){ /*Factorial*/
       	     	 	ai*=i;
	        	} 
     re+=((float)a1+(float)a0)/(float)ai;
     a0=a1; /*Swap o cambio de subindice*/
     a1=ai; /*Swap o cambio de subindice*/
   	}
  if(re<0)re*=-1;
  	 printf("El resultado de la sumatoria es:\n %f", re);
 }
 getchar();
}
