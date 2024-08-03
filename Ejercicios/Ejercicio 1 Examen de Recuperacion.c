/*Alumno: Octavio Augusto Martinez Reyes*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	
   int longitud, i, posP;
   int potencias[5]={1,10,100,1000,10000};
   int valor = 0;
   char cad[20];
   float potenciasD[5]={0.1,0.01,0.001,0.0001,0.00001};
   float valorD = 0;
   
   printf("Ingrese la cadena: \n");
   scanf("%s", cad);
   if (cad[0]== '-'){ /*Verifica que la cadena no tenga decimales*/
   	printf("Cadena Erronea"); 
   }
   
   longitud=strlen(cad);
   
   for( i=longitud-1; i >= 0; i--){
   		valor+=(cad[i]-'0')*potencias[longitud-i-1];
   }
   for (i=0; i<longitud; ++i)
   {
      if (cad[i] == '.') /*Busca el punto en la cadena*/
      {
         posP=i;
      }
   }
   for (i=longitud-1; i>posP; --i)
   {
      valorD += (cad[i]-'0')*potenciasD[longitud-i-1];
   }
    printf("Valor: %d\n", valor);
    printf("Valor Decimal: %f\n", valorD);
    
    
}

   
