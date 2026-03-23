#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Alumnos{
	char nombre[100];
	int calificaciones[5][5];
};
int main(void){
	struct Alumnos A[5];
	srand(time(NULL));

	for (int j = 0; j < 5; j++){
		printf("Introduce el nombre del alumno: ");
		fgets(A[j].nombre, sizeof(A[j].nombre), stdin);
		for (int x = 0; x < 5; x++){
			for (int i = 0; i < 5; i++){
				A[j].calificaciones[x][i] = rand() % 10 + 1;
			}
		}
	}

	for (int j = 0; j < 5; j++){
		printf("%s", A[j].nombre);
		for(int x = 0; x < 5; x++){
			printf("Materia %d: ", x+1);
			for (int i = 0; i < 5; i++){
				printf("%d, ", A[j].calificaciones[x][i]);
			}
			printf("\n");
		}
	}

	return 0;
}