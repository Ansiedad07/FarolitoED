#include <stdio.h>

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

int main(void){
	struct arbol *raiz = NULL, *ptrTemp = NULL, *ptrAux = NULL;
	int opcion;

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
					if(ptrAux->dato == NULL && ptrTemp > ptrAux->dato){
						ptrAux -> der = ptrTemp;
					} else {
						ptrAux -> izq = ptrTemp;
					}
					while(ptrTemp->der == NULL || ptrTemp->izq == NULL){
						if(ptrTemp->dato > ptrTemp->dato){
							ptrTemp -> der = ptrTemp;
						}
					}
				}
			}
			break;
		default:
			break;
		}
	} while (opcion != 4);

	return 0;
}

int crearNodo(void){
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