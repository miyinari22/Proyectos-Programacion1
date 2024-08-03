#include<stdio.h>
#define MAX 10
int main()
{
int matriz[MAX][MAX], col, reng, i=0, j=0;
  printf("Cuantas columnas quieres ");
  scanf("%d", &col);
  printf("Cuantos renglones quieres ");
  scanf("%d", &reng);
  for(i = 0;i < reng;i++)/*Lee los datos*/
  {
      for(j = 0;j < col;j++){
          printf("ESCRIBE LOS VALORES %d, %d", i+1, j+1);
              scanf("%d", &matriz[i][j]);
      }
  }
  printf("\n\n\t\tMatriz original");/*Imprime la matriz original */
  printf("\n\n");
  for(i = 0;i < reng;i++){
      printf("\n\t\t");
      for(j = 0;j < col;j++){
          printf("%d ", matriz[i][j]);
          }
  }
  printf("\n\n\t\tMatriz transpuesta");/*Imprime la matriz transpuesta*/
  printf("\n\n");
  for(i = 0;i < col;i++){
      printf("\n\t\t");
      for(j = 0;j < reng;j++){
          printf("%d ", matriz[j][i]);
          }
  }
  printf("\n\n\n");
    }
