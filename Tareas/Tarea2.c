#include <stdio.h>
#include <math.h>

int main() {
	int bin;
	int c;
	int i;
	int x;
	printf("Ingresa tu numero en decimal para convertirlo a binario\n");
	scanf("%d",x);
	if (x>0) {
		c = x;
		i = 1;
		bin = 0;
		while (c!=1) {
			bin = (float)bin+(float)(c%2)*i;
			c = (float)trunc(c/2);
			i = i*10;
		}
		bin = bin+(c%2)*i;
		printf("%f\n",bin);
	}
}

