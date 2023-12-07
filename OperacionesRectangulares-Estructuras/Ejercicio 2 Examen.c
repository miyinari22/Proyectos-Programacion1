/*Alumno: Martinez Reyes Octavio*/
#include <stdio.h>

struct rectangulo
{
	float largo;
	float ancho;
};

float perimetro(float largo, float ancho){
	float perimetro;
	perimetro = (largo*2) + (ancho*2);
	return perimetro;
}

float area(float largo, float ancho){
	float area;
	area = largo * ancho;
	return area;
}

float getLargo(struct rectangulo rec){
	return rec.largo;
}

float getAncho(struct rectangulo rec){
	return rec.ancho;
}

void imprimeRectangulo(struct rectangulo r){
	printf("\n\n\t\tRectangulo\n");
	printf("Largo: %.2f\n", r.largo);
	printf("Ancho: %.2f\n", r.ancho);
}

void setRectangulo(struct rectangulo *rec, float largo, float ancho){
	rec->largo = largo;
	rec->ancho = ancho;
}

int main(){
	struct rectangulo rectangulo1;
	setRectangulo(&rectangulo1, 5, 4);
	printf("Perimetro: %.2f -  Area: %.2f\n", perimetro(rectangulo1.largo, rectangulo1.ancho), area(rectangulo1.largo, rectangulo1.ancho));
	printf("Largo: %.2f - Ancho: %.2f \n", getLargo(rectangulo1), getAncho(rectangulo1) );
	imprimeRectangulo(rectangulo1);
}
