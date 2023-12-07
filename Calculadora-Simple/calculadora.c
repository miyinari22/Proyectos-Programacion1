#include <stdio.h>

int main() {
    int op, D1, D2, re;
    float rediv;
    do {
        printf("Que desea hacer\n 1.- Comparar\n 2.- Sumar\n 3.- Restar\n 4.- Dividir\n 5.- Residuo\n 6.- Multiplicar\n");
        scanf("%d", &op);
        printf("Ingrese el primer dato\n");
        scanf("%d", &D1);
        printf("Ingrese el segundo dato\n");
        scanf("%d", &D2);

        switch (op) {
            case 1:
                if (D1 < D2) {
                    printf("El numero %d es menor a %d\n", D1, D2);
                } else if (D1 > D2) {
                    printf("El numero %d es mayor a %d\n", D1, D2);
                } else {
                    printf("El numero %d es igual a %d\n", D1, D2);
                }
                if (D1 != D2) {
                    printf("El numero %d es diferente de %d\n", D1, D2);
                }
                break;
            case 2:
                re = D1 + D2;
                printf("El resultado es %d\n", re);
                break;
            case 3:
                re = D1 - D2;
                printf("El resultado es %d\n", re);
                break;
            case 4:
                if (D2 != 0) {
                    rediv = (float) D1 / D2;
                    printf("El resultado es %f\n", rediv);
                } else {
                    printf("Error: No se puede dividir por cero\n");
                }
                break;
            case 5:
                if (D2 != 0) {
                    rediv = D1 % D2;
                    printf("El resultado es %f\n", rediv);
                } else {
                    printf("Error: No se puede calcular el residuo por cero\n");
                }
                break;
            case 6:
                re = D1 * D2;
                printf("El resultado es %d\n", re);
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (op <= 6); // Se usa "<=" en lugar de ">" para permitir que el usuario salga con la opción 6

    return 0;
}
