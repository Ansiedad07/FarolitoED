/**
 * Una estructura en C es un TDA (Tipo de Dato Abstracto) que permite agrupar diferentes tipos de datos bajo un mismo nombre.
 * En este caso, se define una estructura llamada Dato que contiene:
 *
 * Farhid Getsemaní Vázquez García
 */

#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
    struct Dato *ptrAnt;
};

int menu(void);


struct Dato *crearDato(void);
void mostrarDato(struct Dato *ptr);
void liberarDato(struct Dato **ptr);

int main(void){
    struct Dato *ptr = NULL, *ptrNuevo = NULL, *ptrUlt = NULL, *ptrAux = NULL, *ptrTemp = NULL;
    int opcion = 0;

    do{
        opcion = menu();
        switch(opcion){
            case 1:
                ptrNuevo = crearDato();
                if(ptrNuevo == NULL){
                    printf("\nNo se pudo crear el nodo\n");
                } else {
                    /**
                     * Primer caso:
                     * Si la lista esta vacia, el nuevo nodo se convierte en el nodo inicial.
                     */
                    if(ptr == NULL){
                        ptr = ptrNuevo;
                        ptr->ptrSig = ptr;
                        ptr->ptrAnt = ptr;
                    } else {
                        /**
                         * Segundo caso:
                         * Si ya existen nodos, se enlaza el nuevo nodo al inicio de la lista circular.
                         */
                        ptrUlt = ptr->ptrAnt; // El ultimo nodo siempre se encuentra antes del nodo inicial
                        ptrNuevo->ptrSig = ptr; // El nuevo nodo apunta al inicio
                        ptrNuevo->ptrAnt = ptrUlt; // El nuevo nodo apunta hacia atras al ultimo nodo
                        ptrUlt->ptrSig = ptrNuevo; // El ultimo nodo ahora apunta al nuevo nodo
                        ptr->ptrAnt = ptrNuevo; // El nodo inicial apunta hacia atras al nuevo nodo
                        ptr = ptrNuevo; // El nuevo nodo se convierte en el inicio de la lista
                    }

                    printf("\nNodo agregado correctamente\n");
                }
                break;
            case 2:
                mostrarDato(ptr);
                break;
            case 3:
                liberarDato(&ptr);
                break;
            case 4:
                /**
                 * Liberar toda la memoria dinamica antes de salir.
                 */
                if(ptr == NULL){
                    printf("\nNo hay memoria para liberar\n");
                } else {
                    ptrAux = ptr->ptrSig;
                    while(ptrAux != ptr){
                        ptrTemp = ptrAux;
                        ptrAux = ptrAux->ptrSig;
                        free(ptrTemp);
                    }
                    free(ptr);
                    ptr = NULL;
                    printf("\nTodos los nodos fueron liberados\n");
                }
                printf("\nSaliendo\n");
                break;
            default:
                printf("\nOpcion invalida\n");
        }

    } while(opcion != 4);
}

int menu(void){
    int opcion;
    printf("\n1.- Crear dato\n");
    printf("2.- Mostrar dato\n");
    printf("3.- Liberar nodo\n");
    printf("4.- Salir\n");
    scanf("%d", &opcion);
    return opcion;
}

struct Dato *crearDato(void){
    struct Dato *ptrTemp;
    ptrTemp = (struct Dato *)malloc(sizeof(struct Dato));
    if(ptrTemp == NULL){
        printf("\nError al reservar memoria\n");
        return NULL;
    } else {
        printf("\nIngrese un entero: ");
        scanf("%d", &ptrTemp->d);
        ptrTemp->ptrSig = NULL;
        ptrTemp->ptrAnt = NULL;
        return ptrTemp;
    }
}

/**
 * Funcion para mostrar los nodos de la lista doblemente enlazada circular
 */

void mostrarDato(struct Dato *ptr){
    struct Dato *ptrAux;
    if(ptr == NULL){
        printf("\nNo hay nodos para mostrar\n");
    } else {
        ptrAux = ptr;
        do{
            printf("%d -> ", ptrAux->d);
            ptrAux = ptrAux->ptrSig;
        } while(ptrAux != ptr);
        printf("inicio\n");
    }
}


void liberarDato(struct Dato **ptr){
    struct Dato *ptrAux, *ptrTemp;
    if(*ptr == NULL){
        printf("\nNo hay nodos para liberar\n");
    } else {
        /**
         * Si el nodo inicial apunta a si mismo,
         * significa que solo existe un nodo.
         */
        if((*ptr)->ptrSig == *ptr){
            free(*ptr);
            *ptr = NULL;
        } else {
            ptrAux = *ptr;
            /**
             * Se recorre la lista hasta llegar al penultimo nodo.
             */
            while(ptrAux->ptrSig->ptrSig != *ptr){
                ptrAux = ptrAux->ptrSig;
            }
            ptrTemp = ptrAux->ptrSig; // Guardamos el ultimo nodo
            ptrAux->ptrSig = *ptr; // El penultimo nodo apunta al inicio
            (*ptr)->ptrAnt = ptrAux; // El inicio apunta hacia atras al penultimo nodo
            free(ptrTemp); // Se libera el ultimo nodo
        }
        printf("\nNodo liberado correctamente\n");
    }
}

/**
 * Si ves esto prometo mejorarlo xd
 */
