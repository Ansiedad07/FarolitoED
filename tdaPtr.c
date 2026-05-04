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
	printf("\n1.- Crear dato\n");
	printf("2.- Funciones\n");
	printf("3.- Mostrar dato\n");
	printf("4.- Liberar nodo\n");
	printf("5.- Salir\n");
	scanf("%d", &opcion);
	return opcion;
}

int submenu(void){
	int opcion;
	printf("\n1.- Buscar\n");
	printf("2.- Contar\n");
	printf("3.- Remplazar\n");
	printf("4.- Ordenar\n");
	printf("5.- Salir\n");
	scanf("%d", &opcion);
	return opcion;
}

struct Dato* crearDato(void);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
int buscar(struct Dato *ptr, int valor);
void reemplazar(struct Dato *ptr, int viejo, int nuevo);
void contar(struct Dato *ptr);

int main (void){
	struct Dato *ptr = NULL, *ptrTemp = NULL, *ptrAux = NULL, *temp = NULL;
	int opcion, op2;

	do{
		opcion = menu();
		switch(opcion){
			case 1:
				ptrTemp = crearDato();
				if(ptrTemp == NULL){
					printf("No se pudo crear el dato.\n");
				} else {
					printf("Dato creado exitosamente.\n");
					if(ptr == NULL){
						ptr = ptrTemp;
					} else {
						ptrAux = ptr; // Se crea un apuntador auxiliar para recorrer la lista enlazada
						while(ptrAux->ptrSig != NULL){ // Se recorre la lista enlazada hasta llegar al último nodo, el cual apunta a NULL
							ptrAux = ptrAux->ptrSig; // Se actualiza el apuntador auxiliar para que apunte al siguiente nodo, hasta llegar al último nodo de la lista enlazada
						}
						ptrAux->ptrSig = ptrTemp; // Se enlaza el nuevo nodo al final de la lista enlazada, haciendo que el último nodo apunte al nuevo nodo creado
					}
				}
				break;
			case 2:
				do{
					op2 = submenu();
					int val, nuevo;
					switch (op2)
					{
					case 1:
						printf("\nValor a buscar: ");
						scanf("%d", &val);
						buscar(ptr, val);

						break;
					case 2:
						printf("Contar");
						contar(ptr);
						break;
					case 3:
						printf("\nValor a reemplazar: ");
						scanf("%d", &val);
						printf("Nuevo valor: ");
						scanf("%d", &nuevo);
						reemplazar(ptr, val, nuevo);
						break;
					case 4:
						break;
					case 5:
						break;
					default:
						printf("Opción incorrecta");
					}
				} while(op2 != 5);
				break;
			case 3:
				mostrarDato(ptr);
				break;
			case 4:
				liberarDato(&ptr);
				break;
			case 5:
				if(ptr == NULL){
					printf("\nNo hay memoria para liberar");
				}

				ptrAux = ptr;
				while(ptrAux != NULL){
					temp = ptrAux; // Gurdo el nodo actual
					ptrAux = ptrAux->ptrSig; // Avanzo al siguiente
					free(temp); // Libero el anterior
				}
				ptr = NULL; // La lista queda vacia
				printf("\nSe liberaron todos los nodos");


				break;
			default:
				printf("Opcion invalida\n");
		}
	} while(opcion != 5);

}
/**
 * Hay dos formas de crear un dato:
 * 1.- La funcion crea el nuevo modulo y retorna la nueva direccion de memoria de ese modulo de tal forma como ptr = crearDato(ptr);
 * 2.- La direccion de la variable ptr e implementa doble apuntador para modificar ptr desde la funcion, es decir, crearDato(&ptr);
 */
struct Dato * crearDato(void){
	/**
	 * Pasos para crear un nuevo dato(nodo):
	 * 1.- Crear de forma dinamica el nuevo nodo con la funcion malloc y guardar su referencia en un apuntador temporal.
	 * 2.- Buscar la posición de este nuevo nodo dentro de la estructura tipo pila
	 * 2.1.- Primer caso: Si la pila esta vacia, el nuevo nodo se convierte en el nodo inicial de la pila, y hacemos que el apuntador principal guarde su referencia.
	 */
	struct Dato *ptrTemp; // Se crea una variable temporal (es una memoria estatica, se destruye al salir de la función)
	ptrTemp = (struct Dato *)malloc(sizeof(struct Dato)); // Se asigna memoria dinámica para un dato (este bloque no se destruye)
	if(ptrTemp == NULL){
		printf("Error al asignar memoria.\n");
		return NULL;
	} else {
		printf("Ingrese un entero: ");
		scanf("%d", &ptrTemp->d); // El operador -> se utiliza para acceder a los miembros de una estructura a través de un apuntador
		ptrTemp->ptrSig = NULL; // El siguiente dato apunta a NULL, indicando que es el último dato de la lista
		return ptrTemp; // Retorna la dirección del nuevo dato creado
	}
}

void mostrarDato(struct Dato *ptr){
	if(ptr == NULL){
		printf("\nNo hay datos para mostrar\n");
	} else {
		while(ptr != NULL){
			printf("%d -> ", ptr->d); // Se muestra el valor del dato actual
			ptr = ptr->ptrSig; // Se actualiza el apuntador para que apunte al siguiente nodo de la lista
	}
	}
}

/**
 * Pasos para liberar un dato(nodo):
 * 1.- Verificar el penultimo nodo de la estructura tipo pila
 */
void liberarDato(struct Dato **ptr){
	struct Dato *ptrAux; // Se crea un apuntador auxiliar para recorrer la lista enlazada
	if(*ptr == NULL){
		printf("\nNo hay datos para liberar.\n");
	} else {
		if((*ptr)->ptrSig == NULL){ // Si el nodo inicial de la lista enlazada no apunta a ningún otro nodo, es decir, si es el único nodo de la lista
			free(*ptr); // Se libera la memoria del nodo inicial de la lista enlazada
			*ptr = NULL; // Se asigna NULL al apuntador principal para indicar que la lista enlazada está vacía
		} else {
			ptrAux = *ptr; // Se asigna el valor del apuntador principal al apuntador auxiliar para recorrer la lista enlazada
			while(ptrAux->ptrSig->ptrSig != NULL){ // Se recorre la lista enlazada hasta llegar al penúltimo nodo, el cual apunta a un nodo que a su vez apunta a NULL
				ptrAux = ptrAux->ptrSig; // Se actualiza el apuntador auxiliar para que apunte al siguiente nodo, hasta llegar al penúltimo nodo de la lista enlazada
			}
			free(ptrAux->ptrSig); // Se libera la memoria del último nodo de la lista enlazada
			ptrAux->ptrSig = NULL; // Se asigna NULL al apuntador del penúltimo nodo para indicar que es el último nodo de la lista
		}
	}
}

int buscar(struct Dato *ptr, int valor){
	int posicion = 1;
	while(ptr != NULL){
		if(ptr->d == valor){
			printf("\nValor encontrado en la posición %d\n", posicion);
		} else {
			printf("\nNo se encontro el valor\n");
		}
		ptr = ptr->ptrSig;
		posicion++;
	}
}

void contar(struct Dato *ptr){
	int cont = 0;
	while(ptr != NULL){
		ptr = ptr->ptrSig; // Se actualiza el apuntador para que apunte al siguiente nodo de la lista
		cont++; // Se incrementa el contador por cada nodo de la lista enlazada
	}
	printf("\nEl número de nodos es: %d\n", cont); // Se muestra el número total de nodos en la lista enlazada
}

void reemplazar(struct Dato *ptr, int viejo, int nuevo){
	int encontrado = 0;
	while(ptr != NULL){
		if(ptr->d == viejo){
			ptr->d = nuevo;
			encontrado = 1;
		}
		ptr = ptr->ptrSig;
	}
	if(encontrado){
		printf("\nValor reemplazado\n");
	} else {
		printf("\nNo se encontro el valor a reemplazar\n");
	}
}
/**
 * Si ves esto prometo mejorarlo xd
 */