#include <stdio.h>

int main(){
	int numD;
	int bandera = 0;
	printf("Dame el numero de datos a ingresar:  \n");
	scanf("%d", &numD);
	int numArray[numD];
	int numSelected[numD];
	int frecuencias[numD];
	for (int i = 0; i < numD; i++){
	 	printf("Dame el numero en la posicion: %d\n", i);
	 	scanf("%d", &numArray[i]);
	 	numSelected[i] = 0;
	} 

	for (i = 0; i < numD; ++i){
		printf("\t\t%d\n", numArray[i]);
		for (int i = 0; i < numD; ++i){
			if (numArray[i] != numSelected[i])
			{
				bandera = 1;
			}
			else{
				bandera = 0;
			}
		}
		if (bandera == 1)
		{
			frecuencias[i] = 0;
			numSelected[i] = numArray[i];
			for (int j = 0; j < numD; ++j){
				if (numArray[i] == numArray[j])
				{
					frecuencias[i] = frecuencias[i]+1;
				}
			}
		}	
	}	
	for (int i = 0; i <	 numD; ++i){
		printf("%d ", numArray[i]);
		printf("%d ", numSelected[i]);
		printf("%d\n\n", frecuencias[i]);
	}
	int moda = frecuencias[0];
	int pos = 0;
	for (int i = 0; i < numD; ++i){
		if (frecuencias[i] > moda){
			pos = i;
		}
	}
	printf("\n\nLa moda es: %d\n", numArray[pos]);
}
