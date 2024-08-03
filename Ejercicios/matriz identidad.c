#include <stdio.h>

int main() 
{ 
     int mat[50][50];
     int n, i, j, band= 1;
     printf("Tamanio: ");
     scanf("%d", &n);
     for(i = 0; i < n; i++)
          for(j = 0; j < n; j++)
          {
               printf( "Matriz[%d][%d]: ", i, j );
               scanf( "%d", &mat[i][j] );
               if( (mat[i][j] != 0 && i != j) ||
               (mat[i][j] != 1 && i == j))
                    band = 0;
          }
     for(i = 0; i < n; i++)
     {
          for(j = 0; j < n; j++)
               printf("%d ", mat[i][j]);
          printf("\n");
     }
     if(band)
          printf( "Es matriz identidad.\n");
     else
          printf( "No es matriz identidad.\n");
	
     system("pause");
     return 0;
}
