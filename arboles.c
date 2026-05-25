#include <stdio.h>
#include <stdlib.h>

struct arbol{
	int dato;
	struct arbol *izq, *der;
};

int menu() {
    int opcion;
    printf("\nMenú\n");
	printf("1.- Insertar\n");
    printf("2.- Mostrar\n");
    printf("3.- Eliminar\n");
	printf("4.- Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

struct arbol * crearNodo(void);

int main(void){
	struct arbol *raiz = NULL, *ptrTemp = NULL, *ptrAux = NULL;
	int opcion, insertado;

	do{
		opcion = menu();
		switch (opcion){
		case 1:
			ptrTemp = crearNodo();
			if(ptrTemp == NULL){
				printf("\nNo se pudo crear el nodo\n");
			} else {
				if(raiz == NULL){
					raiz = ptrTemp;
				} else {
					ptrAux = raiz;
					insertado = 0;
					while (insertado == 0){
						if(ptrTemp->dato < ptrAux->dato){
							if(ptrAux->der == NULL){
								ptrAux->der = ptrTemp;
								insertado = 1;
							} else {
								ptrAux = ptrAux->der;
							}
						} else {
							if(ptrAux->izq == NULL){
								ptrAux->izq = ptrTemp;
								insertado = 1;
							} else {
								ptrAux = ptrAux->izq;
							}
						}
					}
				}
			}
			break;
		case 2:
			break;
		default:
			break;
		}
	} while (opcion != 4);

	return 0;
}

struct arbol * crearNodo(void){
	struct arbol *ptrTemp;
	ptrTemp = (struct arbol *)malloc(sizeof(struct arbol));
	if(ptrTemp == NULL){
		printf("Error al asignar memoria.\n");
		return NULL;
	} else {
		printf("Ingrese un entero: ");
		scanf("%d", &ptrTemp->dato);
		ptrTemp -> der = NULL;
		ptrTemp -> izq = NULL;
		return ptrTemp;
	}
}