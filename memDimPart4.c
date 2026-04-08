/**
 * Memoria Dinámica parte 4: Menú para reservar memoria, ingresar datos, mostrar datos y liberar memoria
 * En este programa se muestra un menú que permite al usuario reservar memoria dinámica para almacenar una cantidad de enteros, ingresar datos aleatorios, mostrar los datos almacenados y liberar la memoria asignada. El programa utiliza funciones para cada una de estas operaciones, y el usuario puede elegir la opción deseada a través del menú.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ingresarDatos(int *ptr, int n);
void mostrarDatos(int *ptr, int n);
void liberarMemoria(int **ptr);

int menu() {
    int opcion;
    printf("\nMenú\n");
	printf("1.- Reservar memoria\n");
    printf("2.- Ingresar datos\n");
    printf("3.- Mostrar datos\n");
	printf("4.- Liberar memoria\n");
    printf("5.- Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

int * reservarMemoria(int *n) {
	int *ptrTemp; // Se crea una variable temporal (es una memoria estatica, se destruye al salir de la función)
	printf("¿Cuántos enteros deseas almacenar? ");
	scanf("%d", &(*n));
	ptrTemp = (int *)malloc(sizeof(int) * (*n)); // Se asigna memoria dinámica para n enteros (este bloque no se destruye)
	if (ptrTemp == NULL)
		printf("Error al asignar memoria.\n");

	return ptrTemp;
}

int main(void) {
    int *ptr = NULL; // Declaración de un apuntador a entero
	int n = 0;
    int opcion;
    srand(time(NULL));

    do {
        // Mandar a traer a menu para desplegar el menú y que el usuario elija una opción
        opcion = menu();
        switch (opcion) {
			case 1:
				ptr = reservarMemoria(&n);
				break;
            case 2:
                ingresarDatos(ptr, n);
                break;
            case 3:
                mostrarDatos(ptr, n);
                break;
            case 4:
                liberarMemoria(&ptr);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
void liberarMemoria(int **ptr) {
    if (*ptr != NULL) {
        free(*ptr); // Liberar la memoria asignada
        *ptr = NULL;
        printf("Memoria liberada.\n");
    } else {
        printf("No hay memoria para liberar.\n");
    }
}

void ingresarDatos(int *ptr, int n) {
    if(ptr == NULL) {
        printf("No se ha reservado memoria.\n");
        return;
    } else {
        printf("\nDatos asignados\n");
        for (int i = 0; i < n; ++i) {
            *(ptr + i) = rand() % 10 + 1;
        }
    }
}

void mostrarDatos(int *ptr, int n) {
    if(ptr == NULL) {
        printf("No se ha reservado memoria.\n");
        return;
    } else {
        printf("\nValores almacenados en la memoria dinámica:\n");
        for (int i = 0; i < n; ++i) {
            printf("Valor %d: %d\n", i + 1, ptr[i]);
        }
    }
}