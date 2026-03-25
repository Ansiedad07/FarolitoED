#include <stdio.h>

int main(void){
	// Declaración: ptr es un puntero a entero
	// ptr2 y ptr3 son punteros a punteros (apuntadores a apuntadores)
	int *ptr, **ptr2, **ptr3, a, b;
	// Asignar a ptr con la dirección de memoria de 'a'
	ptr = &a;
	printf("Valor de ptr usando puntero: %p \n", ptr);

	*ptr = 6; // Modificar indirectamente a a
	printf("%d\n", *ptr);
	// Un apuntador a un apuntador a entero
	ptr2 = &ptr;		 // Apunta a la dirección de ptr
	**ptr2 = **ptr2 + 2; // Acceder a a usando ptr2
	printf("Valor de ptr2 usando puntero: %p\n", ptr2);
	printf("%d\n", **ptr2);

	return 0;
}