/**
 * Una estructura en C es un TDA (Tipo de Dato Abstracto) que permite agrupar diferentes tipos de datos bajo un mismo nombre.
 * En este caso, se define una estructura llamada Dato que contiene un entero y un apuntador el cual se enlazará con el siguiente dato, formando así una lista enlazada.
 */

#include <stdio.h>
#include <stdlib.h>

struct Dato{
	int d;
	struct Dato *ptrSig;
	struct Dato *ptrAnt;
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

struct Dato* crearDato(void);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);
int buscar(struct Dato *ptr, int valor);
void reemplazar(struct Dato *ptr, int viejo, int nuevo);
int contar(struct Dato *ptr);
void ordenar(struct Dato **ptr);

int main (void){
	struct Dato *ptr = NULL, *ptrNew = NULL, *ptrUlt = NULL, *temp = NULL, *ptrAux = NULL;
	int opcion, op2;

	do{
		opcion = menu();
		switch(opcion){
			case 1:
				ptrNew = crearDato();
				if(ptrNew == NULL){
					printf("No se pudo crear el nodo.\n");
				} else {
					printf("Nodo creado exitosamente.\n");
					if(ptr == NULL){
						ptr = ptrNew; // Apunta al primer nodo creado
						ptr -> ptrSig = ptr;
						ptr -> ptrAnt = ptr;
					} else {
						ptrUlt = ptr -> ptrAnt;
						ptrUlt -> ptrSig = ptrNew;
						ptrNew -> ptrAnt = ptrUlt;
						ptr -> ptrAnt = ptrNew;
						ptrNew -> ptrSig = ptr;

						while(ptrUlt->ptrSig != NULL){ // Se recorre la lista enlazada hasta llegar al último nodo, el cual apunta a NULL
							ptrUlt = ptrUlt->ptrSig; // Se actualiza el apuntador auxiliar para que apunte al siguiente nodo, hasta llegar al último nodo de la lista enlazada
						}
						ptrUlt->ptrSig = ptrNew; // Se enlaza el nuevo nodo al final de la lista enlazada, haciendo que el último nodo apunte al nuevo nodo creado
					}
				}
				break;
			case 2:
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

struct Dato * crearDato(void){
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

int contar(struct Dato *ptr){
	int cont = 0;
	while(ptr != NULL){
		ptr = ptr->ptrSig; // Se actualiza el apuntador para que apunte al siguiente nodo de la lista
		cont++; // Se incrementa el contador por cada nodo de la lista enlazada
	}
	printf("\nEl número de nodos es: %d\n", cont); // Se muestra el número total de nodos en la lista enlazada
	return cont;
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

void ordenar(struct Dato **ptr){
	struct Dato *ptrAux, *ptrTemp, *ptrAnt;
	int i;
	if(*ptr == NULL){
		printf("\nNo Hay datos para ordenar\n");
	} else {
		i = contar(*ptr);
		for(; i>0; i--){
			ptrAux = *ptr;
			ptrAnt = NULL;

			for( ;ptrAux -> ptrSig != NULL ; ){
				if(ptrAux -> d > (ptrAux->ptrSig)->d){
					ptrTemp = ptrAux->ptrSig;
					//ptrAnt = ptrAux;
					ptrAux->ptrSig = ptrTemp->ptrSig;
					ptrTemp->ptrSig = ptrAux;
					if(ptrAnt == NULL){
						*ptr = ptrTemp;
					} else {
						ptrAnt -> ptrSig = ptrTemp;
					}
					ptrAnt = ptrTemp;
				} else {
					ptrAnt = ptrAux;
					ptrAux = ptrAux->ptrSig;
				}
			}
		}
		ptrAux = *ptr;
		mostrarDato(*ptr);
	}
}

/**
 * Si ves esto prometo mejorarlo xd
 */