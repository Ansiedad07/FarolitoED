/**
 * Una estructura en C es un TDA (Tipo de Dato Abstracto) que permite agrupar diferentes tipos de datos bajo un mismo nombre.
 * En este caso, se define una estructura llamada Dato que contiene un entero y un apuntador el cual se enlazará con el siguiente dato, formando así una lista enlazada.
 */

#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int d;
	struct Dato *ptrSig;
};

int menu(void){
	int opcion;
	printf("1.- Crear dato\n");
	printf("2.- Mostrar dato\n");
	printf("3.- Liberar dato\n");
	printf("4.- Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);
	return opcion;
}

void crearDato(struct Dato **ptr);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);

int main (void){
	struct Dato *ptr = NULL;
	int opcion;

	do{
		opcion = menu();
		switch(opcion){
			case 1:
				// Crear dato
				break;
			case 2:
				// Mostrar dato
				break;
			case 3:
				// Liberar dato
				break;
			case 4:
				// Salir
				break;
			default:
				printf("Opcion invalida\n");
		}
	} while(opcion != 4);

}
/**
 * Hay dos formas de crear un dato:
 * 1.- La funcion crea el nuevo modulo y retorna la nueva direccion de memoria de ese modulo de tal forma como ptr = crearDato(ptr);
 * 2.- La direccion de la variable ptr e implementa doble apuntador para modificar ptr desde la funcion, es decir, crearDato(&ptr);
 */
void crearDato(struct Dato **ptr){
	struct Dato *ptrTemp; // Se crea una variable temporal (es una memoria estatica, se destruye al salir de la función)
	ptrTemp = (struct Dato *)malloc(sizeof(struct Dato)); // Se asigna memoria dinámica para un dato (este bloque no se destruye)
	if(ptrTemp == NULL){
		printf("Error al asignar memoria.\n");
		return;
	}
	*ptr = ptrTemp; // Se asigna la nueva direccion de memoria al puntero original (ptr)
}

void mostrarDato(struct Dato *ptr){
}

void liberarDato(struct Dato **ptr){
}