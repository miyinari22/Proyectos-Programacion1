#include <stdio.h>
#include <string.h>

int main() {
    int dia, mes, anjo;
    char nombre[11]; // Arreglo para almacenar el nombre del mes
    
    // Solicita al usuario que ingrese el día, mes y año
    printf("Por Favor ingrese un dia (numero entero)\n");
    scanf("%d", &dia);
    printf("Por Favor ingrese un mes (numero entero)\n");
    scanf("%d", &mes);
    printf("Por Favor ingrese un anio (numero entero)\n");
    scanf("%d", &anjo);
    
    // Selecciona el nombre del mes según el número ingresado
    switch (mes) {
        case 1: strcpy(nombre, "enero");
            break;
        case 2: strcpy(nombre, "febrero");
            break;
        case 3: strcpy(nombre, "marzo");
            break;
        case 4: strcpy(nombre, "abril");
            break;
        case 5: strcpy(nombre, "mayo");
            break;
        case 6: strcpy(nombre, "junio");
            break;
        case 7: strcpy(nombre, "julio");
            break;
        case 8: strcpy(nombre, "agosto");
            break;
        case 9: strcpy(nombre, "septiembre");
            break;
        case 10: strcpy(nombre, "octubre");
            break;
        case 11: strcpy(nombre, "noviembre");
            break;
        case 12: strcpy(nombre, "diciembre");
            break;
        default:
            printf("Fecha No Valida\n");
    }

    // Verifica la validez de la fecha (día y mes)
    if ((dia > 31 || dia < 1) && (mes > 12 || mes < 1)) {
        printf("Fecha no valida\n");
    } else {
        // Verifica febrero para validar la cantidad de días en ese mes
        if (dia > 29 || dia < 1 && mes == 2) {
            printf("Fecha No Valida\n");
        } else {
            // Muestra la fecha en el formato requerido si es válida
            printf("%d de %s del anio %d", dia, nombre, anjo);
        }
    }

    getchar(); // Espera a que se presione una tecla antes de cerrar la consola
    return 0;
}
