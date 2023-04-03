/*
Desarrollar las funciones cargarMat, imprimirMat, y promMat.
cargarMat: carga desde teclado una matriz de int de tamaño F x C pasada por
parámetro. La matriz se debe cargar completa.
imprimirMat: imprime en pantalla el contenido una matriz de int de F x C pasada por
parámetro.
promMat: recibe por parámetro una matriz de int de tamaño F x C y retorna un número
real que representa el promedio de los valores de la matriz.
Desarrollar el programa principal que invocando a las funciones mencionadas, cargue
una matriz, imprima la matriz e imprima el promedio de los valores de la matriz.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_X 3
#define MAX_Y 3

void limpieza(void);
void cargarMat(int mat[][MAX_X]);
void imprimirMat(int mat[][MAX_X]);
double promMat(int mat[][MAX_X]);

int main(void){
	int mat[MAX_Y][MAX_X];
	
	cargarMat(mat);
	imprimirMat(mat);
	printf("Promedio: %lf\n", promMat(mat));
	
	return 0;
}

void limpieza(void){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}
		
void cargarMat(int mat[][MAX_X]){
	int i;
	int j;
	int aux;

	for(i = 0; i < MAX_Y; i++){
		for(j = 0; j < MAX_X; j++){
			limpieza();
					
			printf("Ingrese un entero positivo o 0 para terminar: ");
			scanf("%d",&aux);
					
			mat[i][j] = aux;
		}
	}
}
			
void imprimirMat(int mat[][MAX_X]){
	int i;
	int j;
				
	for(i = 0; i < MAX_Y; i++){
		printf("(");
		for(j = 0; j < MAX_X; j++){
			printf("%d%c",mat[i][j],';');
		}
		printf(")");
		printf("\n");
	}
}
				
double promMat(int mat[][MAX_X]){
	int i;
	int j;
	int suma;
	double prom;
	
	for(i = 0; i < MAX_Y; i++){
		for(j = 0; j < MAX_X; j++){
			suma += mat[i][j];
		}
	}
	prom = (suma/(MAX_X * MAX_Y)) + (suma%(MAX_X * MAX_Y));
	return prom;
}
	
