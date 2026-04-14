/**
 * Una estructura en C es un TDA (Tipo de Dato Abstracto) que permite agrupar diferentes tipos de datos bajo un mismo nombre.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Punto {
    int x, y;
};

void ingresarDatos(struct Punto *ptr, int n);
void mostrarDatos(struct Punto *ptr, int n);
void liberarMemoria(struct Punto **ptr);

int menu() {
    int opcion;
    printf("\nMenú\n");
    printf("1.- Reservar memoria\n");
	printf("2.- Leer datos\n");
    printf("3.- mostrar datos\n");
    printf("4.- Liberar memoria\n");
    printf("5.- Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

struct Punto * reservarMemoria(int *n) {
	struct Punto *ptrTemp; // Se crea una variable temporal (es una memoria estatica, se destruye al salir de la función)
	printf("¿Cuántos enteros deseas almacenar? ");
	scanf("%d", &(*n));
	ptrTemp = (struct Punto *)malloc(sizeof(struct Punto) * (*n)); // Se asigna memoria dinámica para n enteros (este bloque no se destruye)
	if (ptrTemp == NULL)
		printf("Error al asignar memoria.\n");

	return ptrTemp;
}

int main(void) {
    struct Punto *ptr = NULL; // Declaración de un apuntador a entero
	// # punto por si solo es la dirección de memoria del primer elemento del arreglo, por lo que se puede usar como un apuntador a la estructura
	//ptr = punto; // Asignar la dirección de memoria del primer elemento del arreglo a ptr
    int opcion;
    int n = 0;
    srand(time(NULL));

    do {
        // Mandar a traer a menu para desplegar el menú y que el usuario elija una opción
        opcion = menu();
        switch (opcion) {
            case 1:
                if(ptr != NULL){
    				printf("Debes liberar la memoria antes de volver a reservar. (Liberando memoria)\n");
    				liberarMemoria(&ptr);
                    n = 0; // Reiniciar n después de liberar la memoria
				}
                ptr = reservarMemoria(&n);
                break;
			case 2:
                ingresarDatos(ptr, n); // punto es la dirección de memoria del primer elemento del arreglo, por lo que se puede usar como un apuntador a la estructura
				break;
            case 3:
                mostrarDatos(ptr, n);
                break;
            case 4:
                liberarMemoria(&ptr);
				n = 0; // Reiniciar n después de liberar la memoria
                break;
            case 5:
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

void ingresarDatos(struct Punto *ptr, int n) { // Tipo de dato de la variable ptr es un apuntador a una estructura Punto
    for(int i = 0; i < n; i++) {
        ptr[i].x = rand() % 9 + 1;
        ptr[i].y = rand() % 9 + 1;
    }
}

void mostrarDatos(struct Punto *ptr, int n) {
    for(int i = 0; i < n; i++) {
        printf("Punto %d: (%d, %d)\n", i, ptr[i].x, ptr[i].y);
    }

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			double dx = ptr[j].x - ptr[i].x;
			double dy = ptr[j].y - ptr[i].y;
			double distancia = sqrt((dx * dx) + (dy * dy));
			printf("La distancia entre el punto %d y el punto %d es: %.2f\n", i, j, distancia);
		}
	}
}

void  liberarMemoria(struct Punto **ptr) {
    if (*ptr != NULL) {
        free(*ptr); // Liberar la memoria asignada
        *ptr = NULL;
        printf("Memoria liberada.\n");
    } else {
        printf("No hay memoria para liberar.\n");
    }
}