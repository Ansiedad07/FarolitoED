#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int valor;
    struct Nodo *siguiente;
};

int menuPrincipal(void){
    int opc;

    printf("\n1.- Agregar nodo\n");
    printf("2.- Funciones\n");
    printf("3.- Mostrar lista\n");
    printf("4.- Eliminar ultimo nodo\n");
    printf("5.- Salir\n");

    scanf("%d", &opc);

    return opc;
}

int menuFunciones(void){
    int opc;

    printf("\n1.- Buscar valor\n");
    printf("2.- Contar nodos\n");
    printf("3.- Modificar valor\n");
    printf("4.- Ordenar lista\n");
    printf("5.- Regresar\n");

    scanf("%d", &opc);

    return opc;
}

struct Nodo *crearNodo(void);
void imprimirLista(struct Nodo *inicio);
void eliminarNodo(struct Nodo **inicio);
void localizarValor(struct Nodo *inicio, int numero);
int totalNodos(struct Nodo *inicio);
void cambiarValor(struct Nodo *inicio, int viejo, int nuevo);
void ordenarLista(struct Nodo **inicio);

int main(){

    struct Nodo *inicio = NULL;
    struct Nodo *nuevoNodo = NULL;
    struct Nodo *recorrer = NULL;
    struct Nodo *aux = NULL;

    int opcion;
    int opcion2;

    do{

        opcion = menuPrincipal();

        switch(opcion){

            case 1:

                nuevoNodo = crearNodo();

                if(nuevoNodo == NULL){

                    printf("\nNo se pudo crear el nodo 💀\n");

                }else{

                    if(inicio == NULL){

                        inicio = nuevoNodo;

                    }else{

                        recorrer = inicio;

                        while(recorrer->siguiente != NULL){

                            recorrer = recorrer->siguiente;
                        }

                        recorrer->siguiente = nuevoNodo;
                    }

                    printf("\nNodo agregado correctamente 😎\n");
                }

            break;

            case 2:

                do{

                    opcion2 = menuFunciones();

                    int datoBuscado, datoNuevo;

                    switch(opcion2){

                        case 1:

                            printf("\nIngresa el valor a buscar: ");
                            scanf("%d", &datoBuscado);

                            localizarValor(inicio, datoBuscado);

                        break;

                        case 2:

                            totalNodos(inicio);

                        break;

                        case 3:

                            printf("\nValor actual: ");
                            scanf("%d", &datoBuscado);

                            printf("Nuevo valor: ");
                            scanf("%d", &datoNuevo);

                            cambiarValor(inicio, datoBuscado, datoNuevo);

                        break;

                        case 4:

                            ordenarLista(&inicio);

                        break;

                        case 5:

                            printf("\nRegresando al menu principal...\n");

                        break;

                        default:

                            printf("\nOpcion invalida 🚨\n");
                    }

                }while(opcion2 != 5);

            break;

            case 3:

                imprimirLista(inicio);

            break;

            case 4:

                eliminarNodo(&inicio);

            break;

            case 5:

                recorrer = inicio;

                while(recorrer != NULL){

                    aux = recorrer;

                    recorrer = recorrer->siguiente;

                    free(aux);
                }

                inicio = NULL;

                printf("\nToda la memoria fue liberada 🪦\n");

            break;

            default:

                printf("\nOpcion incorrecta xd\n");
        }

    }while(opcion != 5);

    return 0;
}

struct Nodo *crearNodo(void){

    struct Nodo *nuevo = NULL;

    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if(nuevo == NULL){

        printf("\nError al reservar memoria\n");

        return NULL;

    }else{

        printf("\nIngresa un numero: ");
        scanf("%d", &nuevo->valor);

        nuevo->siguiente = NULL;

        return nuevo;
    }
}

void imprimirLista(struct Nodo *inicio){

    if(inicio == NULL){

        printf("\nLa lista esta vacia 🥲\n");

    }else{

        printf("\nLISTA:\n");

        while(inicio != NULL){

            printf("%d -> ", inicio->valor);

            inicio = inicio->siguiente;
        }

        printf("NULL\n");
    }
}

void eliminarNodo(struct Nodo **inicio){

    struct Nodo *auxiliar = NULL;

    if(*inicio == NULL){

        printf("\nNo hay nodos para eliminar\n");

    }else{

        if((*inicio)->siguiente == NULL){

            free(*inicio);

            *inicio = NULL;

        }else{

            auxiliar = *inicio;

            while(auxiliar->siguiente->siguiente != NULL){

                auxiliar = auxiliar->siguiente;
            }

            free(auxiliar->siguiente);

            auxiliar->siguiente = NULL;
        }

        printf("\nUltimo nodo eliminado ☠️\n");
    }
}

void localizarValor(struct Nodo *inicio, int numero){

    int posicion = 1;
    int bandera = 0;

    while(inicio != NULL){

        if(inicio->valor == numero){

            printf("\nValor encontrado en la posicion %d 🎯\n", posicion);

            bandera = 1;
        }

        inicio = inicio->siguiente;

        posicion++;
    }

    if(bandera == 0){

        printf("\nNo se encontro el valor 😔\n");
    }
}

int totalNodos(struct Nodo *inicio){

    int contador = 0;

    while(inicio != NULL){

        contador++;

        inicio = inicio->siguiente;
    }

    printf("\nTotal de nodos: %d\n", contador);

    return contador;
}

void cambiarValor(struct Nodo *inicio, int viejo, int nuevo){

    int encontrado = 0;

    while(inicio != NULL){

        if(inicio->valor == viejo){

            inicio->valor = nuevo;

            encontrado = 1;
        }

        inicio = inicio->siguiente;
    }

    if(encontrado){

        printf("\nValor actualizado 😎\n");

    }else{

        printf("\nNo se encontro el valor a modificar 🫠\n");
    }
}

void ordenarLista(struct Nodo **inicio){

    struct Nodo *actual;
    struct Nodo *anterior;
    struct Nodo *temporal;

    int vueltas;

    if(*inicio == NULL){

        printf("\nNo hay datos para ordenar\n");

    }else{

        vueltas = totalNodos(*inicio);

        while(vueltas > 0){

            actual = *inicio;

            anterior = NULL;

            while(actual->siguiente != NULL){

                if(actual->valor > actual->siguiente->valor){

                    temporal = actual->siguiente;

                    actual->siguiente = temporal->siguiente;

                    temporal->siguiente = actual;

                    if(anterior == NULL){

                        *inicio = temporal;

                    }else{

                        anterior->siguiente = temporal;
                    }

                    anterior = temporal;

                }else{

                    anterior = actual;

                    actual = actual->siguiente;
                }
            }

            vueltas--;
        }

        printf("\nLista ordenada 🚀\n");

        imprimirLista(*inicio);
    }
}
