#include <stdio.h>

int main(){
    float s1, s2, r1, r2, m1, m2, d1, d2, ref;
    int fact, op, i; 
    
    Menu:
    printf("¿Que desea hacer?\n 1.- Sumar\n 2.- Restar\n 3.- Multiplicar\n 4.- Dividir\n 5.- Factorial\n 6.- Salir\n");
    scanf("%d", &op);
    do{
     switch(op){
        case 1: printf("Ingrese el primer numero\n");
                scanf("%f", &s1);
                printf("Ingrese el segundo numero\n");
                scanf("%f", &s2);
                ref=s1+s2;
                printf("El resultado es: %f\n", ref);
                goto Menu;
                break;
        case 2: printf("Ingrese el primer numero\n");
                scanf("%f", &r1);
                printf("Ingrese el segundo numero\n");
                scanf("%f", &r2);
                ref=r1-r2;
                printf("El resultado es: %f\n", ref);
                goto Menu;
                break;
        case 3: printf("Ingrese el primer numero\n");
                scanf("%f", &m1);
                printf("Ingrese el segundo numero\n");
                scanf("%f", &m2);
                ref=m1*m2;
                printf("El resultado es: %f\n", ref);
                goto Menu;
                break;
        case 4: printf("Ingrese el primer numero\n");
                scanf("%f", &d1);
                if (d1==0){
                    printf("Operacion Invalida\n");
                }
                else{
                    printf("Ingrese el segundo numero\n");
                    scanf("%f", &d2);
                    if(d2==0){
                        printf("Operacion Invalida\n");
                    }
                    ref=d1/d2;
                }
                printf("El resultado es: %f\n", ref);
                goto Menu;
                break;
		case 5: printf("Ingrese el numero a calcular su factorial\n");
				scanf("%d", &fact); // Corrección: Agregar "&" antes de fact para obtener la dirección de memoria
		 
				int factorial = 1; // Variable para almacenar el factorial, inicializada en 1
		 
				for (i = 1; i <= fact; i++) { // Corrección: Cambio en la lógica del bucle
					factorial *= i; // Cálculo del factorial
				}
		 
				printf("El factorial de %d es: %d\n", fact, factorial); // Impresión del resultado
				goto Menu;
				break; // Asegurar salir del switch o loop
     }
    }while(op<5);
    getchar();
}

