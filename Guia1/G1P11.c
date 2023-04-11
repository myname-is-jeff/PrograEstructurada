/*
Desarrollar una función cuyo prototipo es ordenarTexto(char[][N]), donde N = 25,
que ordene la matriz de char generada en el ejercicio anterior. Como bien se sabe, cada
fila contiene un string.
Desarrollar el programa principal que cargue una matriz e imprima en pantalla su orden
original, luego invocar a ordenarTexto para que ordene la matriz . Luego imprimir la
matriz ordena. Para cargar e imprimir la matriz utilizar las funciones desarrolladas en
ejercicios anteriores.
Aclaración: Para realizar comparaciones y copia de cadena de caracteres se sugiere
utilizar las funciones strcmp() y strcpy() de la librería string.h
Importante: Una vez terminado el ejercicio, considerar desarrollar usted mismo las
funciones strcmp y strcpy.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 25

void ordenarTexto();
void imprimirMat(char mat[][N]);




void imprimirMat(char mat[][N]){
	int i,j;
	
	for(i = 0; mat[i][0] != '\0'; i++){
		printf("\n");
		for(j = 0; mat[i][j] != '\0'; j++){
			printf("%c ",mat[i][j]);
		}
		
	}
}
