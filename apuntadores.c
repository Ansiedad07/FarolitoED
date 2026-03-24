#include <stdio.h>

int main(void){
	int *ptr, **ptr2, **ptr3, a, b;

	ptr = &a; // Asignar la dirección de memoria de a a ptr
	printf("Valor de ptr usando puntero: %p \n", ptr);

	*ptr = 6; // Modificar indirectamente a a
	printf("%d\n", *ptr);
	// Un apuntador a un apuntador a entero
	ptr2 = &ptr; // Asignar la dirección de memoria de ptr a ptr2
	**ptr2 = **ptr2 +2; // Acceder a a usando ptr2

	printf("Valor de ptr2 usando puntero: %p\n", ptr2);
	printf("%d\n", **ptr2);

	return 0;
}