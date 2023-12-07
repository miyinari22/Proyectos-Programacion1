/*Ejercicio 2:	Elabore un programa que a eleccion del usuario:
1.- Calcula producto de dos matrices
2.- Determina si una matriz dada es identidad
3.- Obtenga la traspuesta de una matriz*/

#include <stdio.h>
  
  int main(){
  	
  	int op, j, k, re, i, ri, band, mbf, mbc;

  	
  	do{
  		printf("\t///BIENVENIDO///\n\n\tSeleccione segun corresponda\n\n");
  		printf("\t1.-Calcular producto de 2 matrices\n\t2.-Matriz Identidad\n\t3.-Matriz Transpuesta\n");
  		printf("\t4.-Salir\n");
  		scanf("%d",&op);
  		
  		switch(op){
  			
	  		case 1:
	  				printf("Ingrese Tamanyo de la Matriz A (Primer subindice)\n");
	  				scanf("%d", &re);
	  				printf("Ingrese segundo subindice (Matriz A)\n");
	  				scanf("%d", &ri);
	  				printf("Ingrese Tamanyo de la Matriz B (Primer subindice)\n");
	  				scanf("%d", &mbf);
	  				printf("Ingrese segundo subindice (Matriz B)\n");
	  				scanf("%d", &mbc);
	  				  if(ri!=mbf){
             				printf("No se puede multiplicar\n");
             				}else{
             					int A[re][ri], B[mbf][mbc], C[re][mbf];
  									for(i=0;i<re;i++){
     									 for(j=0;j<ri;j++){
          									printf("Escribe el valor en %d, %d de la Matriz A\n",i, j);
          									scanf("%d", &A[i][j]);
      									 }
  									}
  								printf("\n\n");
  								for(i=0;i<mbf;i++){
     									 for(j=0;j<mbc;j++){
          									printf("Escribe el valor en %d, %d de la Matriz B\n",i, j);
          									scanf("%d", &B[i][j]);
											}
								}
								for(i=0;i<re;i++){ /*Hace La multiplicacion y asigna los nuevos valores a la matriz c*/
	      							for(j=0;j<mbc;j++){
	          							C[i][j]=0;
	          								for(k=0;k<ri;k++){
	              								C[i][j]=(C[i][j]+(A[i][k]*B[k][j]));
	              							}
	              				    }
	              			    }
              			   		printf("Su Resultado es:\n Matriz C:\n"); /*Imprime la matriz resultante*/
								printf("\n");
									for(i=0;i<re;i++){
										printf("\t");
										    for(j=0;j<mbc;j++){
										          printf("%d  ", C[i][j]);
										    }
										    printf("\n");
									}
								printf("\n");
	  						}
	  				    break;
	  				    
	  		case 2:
	  			 	printf("\nIngrese subindice\n");
	  				scanf("%d", &re);
	  				printf("Ingrese segundo subindice\n");
	  				scanf("%d", &ri);
	  				if(re!=ri){
	  					printf("No se puede calcular la matriz identidad\n");
					  }else{
					  	int iden[re][ri]; /*Crea una matriz dada por el usuario*/
	  						for(i=0; i<re; i++){
	  							for(j=0; j<ri;j++){
	  									printf("Ingrese dato (Posicion %d, %d)\n", i, j);
               							scanf("%d", &iden[i][j]); /*Verifica si es identidad o no*/
		               					if( (iden[i][j] !=0 && i!=j) || 
										   (iden[i][j] !=1 && i==j))
		               							band=0;
								 }
							}
               					    for(i = 0; i<re; i++){/*Imprime la matriz*/
         								 for(j=0; j<ri; j++){
         								 		printf("%d ", iden[i][j]);
										  }
										printf("\n");
               						}
     							if(band) printf("Es matriz identidad\n");
     							else printf("No es matriz identidad\n");
                    			band = 0;
					   }
	  				break;
	  				
	  		case 3:
	  			printf("Ingrese subindice de la matriz\n");
	  			scanf("%d", &re);
	  			printf("Ingrese segundo subindice\n");
	  			scanf("%d", &ri);
	  			int Trans[re][ri];
	  			 for(i=0; i<re; i++){
      				for(j=0; j<ri;j++){
          				printf("Ingresa el valor %d, %d\n", i, j);
              			scanf("%d", &Trans[i][j]);
				    }
				 }
  				printf("Matriz original\n");/*Imprime la matriz original*/
  				printf("\n");
  				for(i = 0; i<re; i++){
      				for(j=0; j<ri; j++){
          				printf("%d ", Trans[i][j]);
          			}
          			printf("\n");
  				}
  				printf("\nMatriz transpuesta\n");/*Imprime la matriz transpuesta*/
  				printf("\n");
  				for(i=0; i<ri; i++){
      				for(j=0; j<re; j++){
          				printf("%d ", Trans[j][i]);
          			}
          			printf("\n");
  				}
 				break;
	  	}
	  }while(op<4);
	getchar();
  }

