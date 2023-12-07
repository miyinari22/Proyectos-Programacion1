#include <stdio.h>
#include <string.h>

int main() {
    // Declaración de arreglos para almacenar información de productos
    char nombre[10][10]; // Arreglo bidimensional para almacenar nombres de productos
    float precio[10];    // Arreglo para almacenar precios de productos
    int cantidad[10];    // Arreglo para almacenar existencias de productos
    int pos[10];         // Arreglo para mantener las posiciones originales de los productos
    int num, i, can, band, n; // Variables auxiliares
    
    band = 0; // Variable de control
    
    // Solicita al usuario la cantidad de artículos a ingresar (hasta un máximo de 10)
    printf("Cuantos articulos va a ingresar (Maximo 10)\n");
    scanf("%d", &num);
    
    // Bucle para ingresar los nombres de los productos
    for (i = 0; i < num; i++) {
        printf("Ingrese el articulo (10 caracteres)\n");
        scanf("%s", nombre[i]); // Captura el nombre del producto
        getchar(); // Captura el salto de línea residual
    }
    
    // Bucle para ingresar las existencias de los productos
    for (i = 0; i < num; i++) {
        printf("Ingrese las existencias del articulo %s\n", nombre[i]);
        scanf("%d", &can); // Captura la cantidad de existencias del producto
        cantidad[i] = can; // Almacena la cantidad en el arreglo correspondiente
    }
    
    // Bucle para ingresar los precios de los productos
    for (i = 0; i < num; i++) {
        printf("Ingrese el precio del articulo %s\n", nombre[i]);
        scanf("%f", &precio[i]); // Captura el precio del producto
    }
    
    // Almacena las posiciones originales de los productos en el arreglo 'pos'
    for (i = 0; i < num; i++) {
        pos[i] = i; // Guarda las posiciones originales
    }
    
    // Ordena las posiciones usando el método de la burbuja según el nombre del producto
    for (i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (strcmp(nombre[pos[j]], nombre[pos[j + 1]]) > 0) {
                int tempPos = pos[j];
                pos[j] = pos[j + 1];
                pos[j + 1] = tempPos;
            }
        }
    }
    
    // Imprime los datos ordenados por nombre
    printf("Los datos son (En orden alfabetico): \n Producto\t Existencia\t Precio\t\n");
    for (i = 0; i < num; i++) {
        printf("%-10s\t %d\t %.2f\n", nombre[pos[i]], cantidad[pos[i]], precio[pos[i]]);
    }
    
    // Imprime los datos originales
    printf("Los datos son (Como entraron): \nProducto\t Existencia\t Precio\t \n");
    for (i = 0; i < num; i++) {
        printf("%s\t %d\t %.2f\t\n", nombre[i], cantidad[i], precio[i]);
    }
    
    return 0;
}
