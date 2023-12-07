#include <stdio.h>
#include <string.h>
#define MAX 10

struct alimento{ /*Estructura de Arreglos*/
	char nombre[10][100];
	float precio[10];
	float calorias [10];
};
void rellenarStruct (struct alimento alim, int contNat, int contPro);
void impresion (struct alimento alim, int contNat, int contPro, float maxCal, float precioEco, int mCal, int pEco);
void ordenamiento(struct alimento alim);
void comparaciones(struct alimento alim, float maxCal, float precioEco);


/* /////////////  MAIN ///////// */
int main(){

	
	int i, contNat, contPro, cont, pEco=0, mCal=0;
	struct alimento alim;
	float maxCal=0, precioEco=0;
	
	contNat=0;
	contPro=0;
	rellenarStruct(alim, contNat, contPro);
	comparaciones(alim, maxCal, precioEco);
	ordenamiento (alim);
	impresion(alim, contNat, contPro, pEco, mCal);

}
/*Ordenamineto*/

void ordenamiento(struct alimento alim){
		int i, min, j;
		char aux[10][100];
		float auxCal=0, auxPrecio=0;
		
	for (i = 0; i< MAX-1; ++i){  
		min = i;
        for (j=i+1;j<MAX; ++j){
            if (strcmp(alim.nombre[min], alim.nombre[j])> 0)
            {
            	strcpy(aux[0], alim.nombre[j]);
                strcpy(alim.nombre[j], alim.nombre[min]);
                strcpy(alim.nombre[min], aux[0]); 

        
                auxPrecio = alim.precio[j];
                alim.precio[j]=alim.precio[min];
                alim.precio[min]=auxPrecio;

                auxCal= alim.calorias[j];
                alim.calorias[j] = alim.calorias[min];
                alim.calorias[min] = auxCal;

            }
      	}
    }
}

void comparaciones(struct alimento alim, float maxCal, float precioEco, int mCal, int pEco){
	int i;

	for (i=0; i< MAX; ++i){
		if (alim.calorias[i]>maxCal)
		{
			maxCal = alim.calorias[i];
			mCal=i;
		}
		if (alim.precio[i]< precioEco)
		{
			precioEco = alim.precio[i];
			pEco=i;
	
		}
	}
}

/*Funcion de impresion*/

void impresion(struct alimento alim, int contNat, int contPro,  int pEco, int mCal){
	int i=0;
	
	printf("El total de alimentos naturales es: %d\n'", contNat);
	printf("El total de alimentos procesados es: %d\n", contPro);
	printf("El alimento mas barato es: %s %f\n", alim.nombre[pEco], alim.precio[pEco]);
	printf("El alimento con mas calorias es: %s con %f cal\n",alim.nombre[mCal], alim.calorias[mCal]);
	
	printf("Listado en orden Alfabetico\n");
	printf("Nombre/tPrecio/tCalorias/t/n");
	
	for(i=0; i<MAX; i++){
		printf("%s /t/t %f /t/t %f\n", alim.nombre[i], alim.precio[i], alim.calorias[i]);
	}
}


/*Funcion Rellenar 
Empieza a Preguntar por el nombre, precio, calorias y si es natural o procesado el alimento*/
void rellenarStruct (struct alimento alim, int contNat, int contPro){
	int cont=0;
	int i;
	
		for(i=0; i<MAX; i++){
		printf("Por favor ingrese el nombre del alimento (Maximo 100 caracteres)\n");
		gets(alim.nombre[i]);
	}
	
	for (i=0; i<MAX; i++){
		printf("Ingrese el precio del alimento: %s\n", alim.nombre[i]);
		scanf("%f", &alim.precio[i]);
	}
	
	for (i=0; i<MAX; i++){
		printf("Ingrese el total de calorias de: %s\n", alim.nombre[i]);
		scanf("%f", &alim.calorias[i]);
	}
	
	for (i=0; i<MAX; i++){
		printf("El alimento %s es natural? (1 para si y 0 para no)\n", alim.nombre[i]);
		/*En caso de Falso se asume que un alimento procesado*/
		scanf("%d", &cont);
		if (cont==0){
			contPro+=1;
		}
		if(cont==1){
			contNat+=1;
		}
	}
}
