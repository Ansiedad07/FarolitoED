/**
 * programa que en el main declaremos una variable entera y hacer una llamada a funcion después en a debe haber un dato
 */

#include <stdio.h>

int mifuncion(int *ptr){
	printf("Introduce el valor nuevo de a: ");
	scanf("%d", &(*ptr));
}

int main(void){
	int a = 5;
	printf("Valor inicial de a: %d\n", a);
	mifuncion(&a); // Mandar la dirección de memoria de 'a' a la función para modificar su valor
	printf("Valor de a después de la llamada: %d\n", a);

	return 0;
}