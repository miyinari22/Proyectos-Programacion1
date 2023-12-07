#include <stdio.h>

int main()
{
   int m10, m5, dev, m2, m1, m50c; // Declaración de las variables para el número de monedas de cada denominación y la cantidad a devolver

   printf("\t\t///BIENVENIDO///\n\n");
   printf("Introduzca cantidad a devolver:\n");
   scanf("%d", &dev); // Se solicita al usuario la cantidad a devolver y se guarda en la variable 'dev'

   if (dev > 0) { // Verificación de que la cantidad a devolver sea mayor que cero
      if (dev >= 10) {  // Verificación para las monedas de 10
         m10 = dev / 10; // Cálculo del número de monedas de 10 pesos
         dev %= 10; // Actualización del monto a devolver restando las monedas de 10 pesos
      } else
         m10 = 0; // Si no se deben devolver monedas de 10 pesos, se establece en cero

      if (dev >= 5) { // Verificación para las monedas de 5
         m5 = dev / 5; // Cálculo del número de monedas de 5 pesos
         dev %= 5; // Actualización del monto a devolver restando las monedas de 5 pesos
      } else
         m5 = 0; // Si no se deben devolver monedas de 5 pesos, se establece en cero

      if (dev >= 2) { // Verificación para las monedas de 2
         m2 = dev / 2; // Cálculo del número de monedas de 2 pesos
         dev %= 2; // Actualización del monto a devolver restando las monedas de 2 pesos
      } else
         m2 = 0; // Si no se deben devolver monedas de 2 pesos, se establece en cero

      if (dev >= 1) { // Verificación para las monedas de 1
         m1 = dev / 1; // Cálculo del número de monedas de 1 peso
         dev %= 1; // Actualización del monto a devolver restando las monedas de 1 peso
      } else
         m1 = dev; // Si no se deben devolver monedas de 1 peso, se establece el valor restante

      m50c = 0; // No hay monedas de 50 centavos, se establece en cero

      // Impresión del número de monedas de cada denominación que se deben devolver
      printf("\nMoneda(s) de 10: %d", m10);
      printf("\nMoneda(s) de 5: %d", m5);
      printf("\nMoneda(s) de 2: %d", m2);
      printf("\nMoneda(s) de 1: %d", m1);
      printf("\nMoneda(s) de 50 centavos: %d", m50c);
   } else
      printf("ERROR: Cantidad incorrecta, debe ser mayor que cero."); // Mensaje de error si la cantidad a devolver es menor o igual a cero

   getchar(); // Espera a la entrada de un carácter adicional antes de finalizar el programa
}
