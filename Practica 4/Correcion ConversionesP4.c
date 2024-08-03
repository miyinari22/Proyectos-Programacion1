/*Programa de Conversiones
Integrantes:
Paez Lopez Molly Karime
Juan Perez Luis
Castillo Tecocoatzi Armando
Martinez Reyes Octavio Augusto*/
#include <stdio.h>

/*Funcion de Celsius a Fahrenheit*/
 float CelaFahren(float re){
 		re=(re*1.8)+32;
 		printf("Equivalen a %f Grados Fahrenheit\n", re);
 }
 
 /*Funcion de Fahrenheit a Celsius*/
 float FahrenaCel(float re){
 		re=(re-32)*0.55;
 		printf("Equivalen a %f Grados Celsius\n", re);

 }
 
 /*Funcion de Kilometros a Millas*/
  float KmaMi(float re){
 		re=re/1.609;
 		printf("Equivalen a %f millas\n", re);
 }
 /*Funcion de Millas a Kilometros*/
 float MiaKm(float re){
 		re=re*1.609;
 		printf("Equivalen a %f Kilometros\n", re);
 }
/*Funcion de Pies a Metros*/
 float PiesaMetros(float re){
 		re=re/3.281;
 		printf("Equivalen a %f Metros\n", re);
 }
 /*Funcion Metros a Pies*/
  float MetrosaPies(float re){
 		re=re*3.281;
 		printf("Equivalen a %f pies\n", re);
 }
/*Funcion Libras a Kilo*/
  float LibrasaKilos(float re){
 		re=re/3.281;
 		printf("Equivalen a %f Kilos\n", re);
 }
/*Funcion Kilos a Libras*/
  float KilosaLibras(float re){
 		re=re*2.205;
 		printf("Equivalen a %f Libras\n", re);
 }
/*Funcion Galones a Litros*/ 
  float GalonesaL(float re){
 		re=re*3.785;
 		printf("Equivalen a %f Litros\n", re);
 }
/*Funcion Litros a Galones*/
  float LaGalones(float re){
 		re=re/3.785;
 		printf("Equivalen a %f Galones\n", re);
 }
 
	int main(){
	 	int op;
	 	float re;
		do{
		 	printf("\n\t\t///CONVERSOR DE UNIDADES///\n\n");
			printf("Que desea convertir?\n\n");
			printf("1.- Celsius a Fahrenheit\n");
			printf("2.- Fahrenheit a Celsius\n");
			printf("3.- Kilometros a Millas\n");
			printf("4.- Millas a Kilometros\n");
			printf("5.- Pies a Metros\n");
			printf("6.- Metros a Pies\n");
			printf("7.- Libras a Kilogramos\n");
			printf("8.- Kilogramos a Libras\n");
			printf("9.- Galones a Litros\n");
			printf("10.- Litros a Galones\n");
			printf("11.- Salir\n");
			scanf("%d", &op);
			switch(op){
					case 1:
							printf("Dame los grados Celsius a convertir\n"),
 							scanf("%f", &re);
							CelaFahren(re);
							break;
					case 2:
							printf("Dame los grados Fahrenheit a convertir\n");
 							scanf("%f", &re);
							FahrenaCel(re);
							break;
					case 3:	
					 		printf("Dame los Kilometros a convertir\n"),
 							scanf("%f", &re);
							KmaMi(re);
							break;
					case 4:
							printf("Dame las Millas a convertir\n");
 							scanf("%f", &re);
						    MiaKm(re);
							break;
					case 5:
							printf("Dame los Pies a convertir\n");
 							scanf("%f", &re);
							PiesaMetros(re);
							break;
					case 6:	
					 		printf("Dame los Metros a convertir\n");
 							scanf("%f", &re);
							MetrosaPies(re);
							break;
					case 7:
							printf("Dame las Libras a convertir\n");
 							scanf("%f", &re);
							LibrasaKilos(re);
							break;
					case 8:	
							printf("Dame los Kilogramos a convertir\n");
 							scanf("%f", &re);
							KilosaLibras(re);
					 		break;
					case 9:
							printf("Dame los Galones a convertir\n");
 							scanf("%f", &re);
							GalonesaL(re);
							break;
					case 10:
							printf("Dame los Litros a convertir\n");
 							scanf("%f", &re);
							LaGalones(re);
							break;
			}
		}while(op<11);
   }
   
