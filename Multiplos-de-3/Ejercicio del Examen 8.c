#include <stdio.h>

int main() {
    // Declaración e inicialización de variables
    int i, suma, contmul, contnum;
    
    contnum = -1; // Inicialización del contador de números (se inicia en -1 para no contar el -1 inicial)
    contmul = 0; // Inicialización del contador de múltiplos de 3
    suma = 0; // Inicialización de la suma de múltiplos de 3

    // Bucle que se ejecuta mientras el valor ingresado no sea -1
    for (i = 0; i != -1;) {
        printf("Ingresa un numero (-1 Salida):\n"); // Se solicita al usuario que ingrese un número
        scanf("%d", &i); // Se lee el número ingresado por el usuario
        contnum = contnum + 1; // Se incrementa el contador de números ingresados

        // Si el número ingresado es múltiplo de 3
        if (i % 3 == 0) {
            suma = suma + i; // Se suma el número a la suma total de múltiplos de 3
            contmul = contmul + 1; // Se incrementa el contador de múltiplos de 3
        }
    }

    // Una vez que se ingresa -1, se imprime el resultado
    printf("La suma de los multiplos de 3 es: %d\n", suma);
    printf("Total de multiplos de 3: %d\n", contmul);
    printf("Total de datos leidos: %d (no se ha contado el -1)\n", contnum);
    
    getchar(); // Espera a que se presione una tecla antes de cerrar la consola
    return 0;
}
