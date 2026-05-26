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

int submenu(void){
	int opcion;
	printf("\nElige una opción para mostrar el arbol: \n");
	printf("\n1.- In-Orden\n");
	printf("2.- Pre-Orden\n");
	printf("3.- Post-Orden\n");
	printf("4.- Salir\n");
	scanf("%d", &opcion);
	return opcion;
}

struct arbol * crearNodo(void);
void InOrden(struct arbol *p);
void PreOrden(struct arbol *p);
void PostOrden(struct arbol *p);

int main(void){
	struct arbol *raiz = NULL, *ptrTemp = NULL, *ptrAux = NULL;
	int opcion, op2, insertado;

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
						if(ptrTemp->dato > ptrAux->dato){
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
			do{
				op2 = submenu();
				int val, nuevo;
				switch (op2){
					case 1:
						printf("\nArbol en InOrden\n");
						InOrden(raiz);
						printf("\n");
						break;
					case 2:
						printf("\nArbol en PreOrden\n");
						PreOrden(raiz);
						printf("\n");
						break;
					case 3:
						printf("\nArbol en PostOrden\n");
						PostOrden(raiz);
						printf("\n");
						break;
					case 4:
						break;
					default:
						printf("Opción incorrecta");
					}
				} while(op2 != 4);
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

void InOrden(struct arbol *p) {
	if (p!=NULL) {
		InOrden(p->izq);
		printf("%4d ",p->dato);
		InOrden(p->der);
	}
}

void PreOrden(struct arbol *p){
	if (p!=NULL) {
		printf("%4d ",p->dato);
		PreOrden(p->izq);
		PreOrden(p->der);
	}
}

void PostOrden(struct arbol *p){
	if (p!=NULL) {
		PostOrden(p->izq);
		PostOrden(p->der);
		printf("%4d ",p->dato);
	}
}