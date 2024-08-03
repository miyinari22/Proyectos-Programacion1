/*Algoritmo NoDeBytes [El siguiente programa muestra la cantidad de bytes que
puede soportar cada tipo de dato]*/

#include <stdio.h> /*Cabecera*/
#include <limits.h> /*Esta libreria permite mostrar los rangos de los tipos de datos*/
#include <float.h>

int main ()
{
    printf("Tamanio del dato char: %lu bytes \n", sizeof(char) ); 
      printf("Bits en un byte: %d \n", CHAR_BIT);
      printf("su rango minimo es: \n", CHAR_MIN);
      printf("su maximo rango es: %d\n", CHAR_MAX);
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato signed char: %lu bytes \n", sizeof(signed char) );
      printf("su rango minimo es: %d\n", SCHAR_MIN);
      printf("su maximo rango es: %d\n", SCHAR_MAX);
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato unsigned char: %lu bytes \n", sizeof(unsigned char) );
      printf("su maximo rango es: %d\n", UCHAR_MAX);
      printf("su rango minimo es: 0\n");
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato int es: %lu bytes\n", sizeof(int) );
      printf("su rango minimo es: %d\n", INT_MIN);
      printf("su maximo rango es: %d\n", INT_MAX);
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato unsigned int es: %lu bytes\n", sizeof(unsigned int) );
      printf("su maximo rango es: %d\n", UINT_MAX);
      printf("su rango minimo es: 0\n");
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato unsigned short es: %lu bytes\n", sizeof(unsigned short) );
      printf("su maximo rango es: %d\n", USHRT_MAX);
      printf("su rango minimo es: 0\n");
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato short es: %lu bytes\n", sizeof(short) );
      printf("su rango minimo es: %d\n", SHRT_MIN);
      printf("su maximo rango es: %d\n", SHRT_MAX);
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato long es: %lu bytes\n", sizeof(long) );
      printf("su rango minimo es: %lu\n", LONG_MIN);
      printf("su maximo rango es: %lu\n", LONG_MAX);
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato unsigned long es: %lu bytes\n", sizeof(unsigned long) );
      printf("su maximo rango es: %lu\n", ULONG_MAX);
      printf("su rango minimo es: 0\n");
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato float es: %d bytes\n", sizeof(float) );
      printf("su rango minimo es: %e\n", FLT_MIN);
      printf("su maximo rango es: %e\n", FLT_MAX);
         printf("\n"); /*Este printf genera un enter para una mejor lectura*/
    printf("Tamanio del dato double es: %d bytes\n", sizeof(double) );
      printf("su rango minimo es: %e\n", (double) DBL_MIN);
      printf("su maximo rango es: %e\n", (double) DBL_MAX);
    getchar(); /*Mantiene abierto el archivo ejecutable hasta que se detecte un enter*/
}
