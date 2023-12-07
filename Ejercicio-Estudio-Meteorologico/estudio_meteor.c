/*Un estudio meteorologico mensual consiste de una medicion promedio diaria para un mes, 
las mediciones promedio son numeros reales mayores que cero. Leer las mediciones diarias 
del mes de mayo y leer un caracter determinando lo que se pide:
-Si el caracter es "M", Indicar la mayor temperatura del mes y el numero del dia a la que corresponde.
-Si el caracter es "m", Indicar la menor temperatura del mes y el nimero del dia a la que corresponde.
-Si el caracter es "p", determinar la temperatura promedio del mes.
-Si el caracter es "a", indicar que dias del mes de mayo hubo temperaturas entre 15 y 27.*/

#include <stdio.h>

int main() {
    int dmay, dmen, d, i;
    float tmay, tmen, suma, t, prom;
    char op;

    tmay = 0;
    suma = 0;
    prom = 0;
    tmen = 1000;
    prom = 0;
    dmay = 0;
    dmen = 0;

    int dias_cumplen[31]; // Un array para almacenar los días que cumplen la condición
    int contador_dias = 0; // Un contador para llevar un registro de cuántos días cumplen la condición

    printf("\t///MES DE MAYO///\n");
    for (i = 1; i < 32; i++) {
        printf("Ingrese temperatura del dia %d: ", i);
        scanf("%f", &t);
        if (t <= 0)
            printf("Ingrese temperaturas mayores a 0\n");
        if (t > 0) {
            suma = suma + t;
            if (t > tmay) {
                tmay = t;
                dmay = i;
            }
            if (t < tmen) {
                tmen = t;
                dmen = i;
            }
            if (t >= 15 && t <= 27) {
                dias_cumplen[contador_dias] = i;
                contador_dias++;
            }
        }
    }

    do {
        printf("\t///Bienvenido///\nQue desea hacer?\n\n");
        printf("\tEscriba la letra correspondiente (Sensible a Mayusculas)\n");
        printf("M.- Mostrar la temperatura mayor y la fecha correspondiente\n");
        printf("m.- Mostrar la temperatura menor y la fecha correspondiente\n");
        printf("p.- Mostrar temperatura promedio del mes\n");
        printf("a.- Mostrar los dias del mes en que hubo temperaturas entre 15 y 27\n");
        printf("s.- Salir\n");
        scanf(" %c", &op);
        switch (op) {
        case 'M':
            printf("-Temperatura Mayor: %.2f\n -Dia: %d\n", tmay, dmay);
            break;
        case 'm':
            printf("-Temperatura Menor: %.2f\n -Dia: %d\n", tmen, dmen);
            break;
        case 'p':
            prom = suma / 31;
            printf("El promedio es: %.2f\n", prom);
            break;
        case 'a':
            if (contador_dias > 0) {
                printf("Días con temperaturas entre 15 y 27 grados:\n");
                for (int j = 0; j < contador_dias; j++) {
                    printf("Día %d\n", dias_cumplen[j]);
                }
            } else {
                printf("No hubo días con temperaturas entre 15 y 27 grados.\n");
            }
            break;
        }
    } while (op != 's');

    return 0;
}
