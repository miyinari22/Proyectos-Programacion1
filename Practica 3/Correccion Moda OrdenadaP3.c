#include <stdio.h>

int main(){
	int pos=0, posmay=0, k, i, n,j, aux;
	float prom=0;
	int num=0, may=0;
	int M[25], x[25];
	printf("Cuantos datos va a ingresar? (Maximo 25)\n");
	scanf("%d", &n);
	
	
	for(i=0; i<n;i++){
		printf("Ingrese el numero:\n");
		scanf("%d", &M[i]);
		x[i]=M[i];
		prom+=M[i];
	}
	
	prom=prom/n;
	
	/*Ordenar*/
	for(i=1; i<n; i++) {
		j = i;
		aux = M[i];
		while(j>0 && aux<M[j-1]) {
			M[j] = M[j-1];
			j=j-1;
		}
		M[j] = aux;
	}
	/*Moda*/
	 for(i=0;i<n;i++){
        num= M[i];
        pos=i;
        for(k=i;k<n;k++) {
            if(M[k]==num) x[pos]++;
        }
    }
    
    may=x[0];
    posmay = 0;
    for(i=0;i<n;i++) {
        if(x[i]>may) {
            posmay=i;
            may=x[i];
        }
    }
    
    if(n%2!=0) {
        printf("\nEL valor de la mediana es : %d\n",M[n/2]);
    } else {
        printf("\nEL valor 1 de la mediana es : %d\n",M[n/2]);
        printf("\nEL valor 2 de la mediana es : %d\n",M[(n/2)-1]);
	}
  printf("El promedio es: %.2f\n", prom);
  printf("La moda es: %d\n",M[posmay]);

}

