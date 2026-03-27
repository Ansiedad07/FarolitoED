/**
 * Memória Dinâmica
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *ptr = NULL; // Declaración de un apuntador a entero

	// Asignar la cantidad de memoria para asignar en bits
	ptr = (int *)malloc(sizeof(int));

	// Asignar un valor a la memoria dinámica
	*ptr = 10;
	printf("Valor almacenado en la memoria dinámica: %d\n", *ptr);
	printf("Dirección de memoria de ptr: %p\n", &ptr);
	printf("Valor de ptr (Dirección de memoria reservada): %p\n", ptr);

	// Liberar la memoria asignada
	free(ptr);

	return 0;
}