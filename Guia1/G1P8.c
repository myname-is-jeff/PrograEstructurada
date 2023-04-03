/*
Desarrollar la función transponer, que recibe por parámetro una matriz de int de
tamaño F x F y la modifique por su transpuesta.
Desarrollar el programa principal que cargue una matriz, luego la muestre en pantalla. A
continuación invocar a transponer y luego volver a imprimir para verificar su
transpuesta. Utilizar cargarMat, imprimirMat, desarrolladas anteriormente.
*/

#include <stdio.h>
#include <stdlib.h>

#define F 3

void transponer(int mat[][F]);
void imprimirMat(int mat[][F]);

int main(void){
    int mat[F][F] = {{1,2,3},{4,5,6},{7,8,9}};
    
    imprimirMat(mat);
    transponer(mat);
    imprimirMat(mat);

    return 0;
}

void transponer(int mat[][F]){
    int i, j,aux;

    for(i = 0; i < F; i++){
        for(j = i + 1; j < F; j++){
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

void imprimirMat(int mat[][F]){
	int i;
	int j;
				
	for(i = 0; i < F; i++){
		printf("(");
		for(j = 0; j < F; j++){
			printf("%d%c",mat[i][j],';');
		}
		printf(")");
		printf("\n");
	}
}

