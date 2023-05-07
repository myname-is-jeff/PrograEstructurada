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
#define NFIL 3

void ordenarTexto(char mat[][N]);
void imprimirMat(char mat[][N]);
void matParser(char str1[], char str2[],char mat[][N], int fila);
void strToMat(char mat[][N],char str1[],int fila);

int main(void){
	char mat[NFIL][N] = { {'h','o','l','a','\0'}, {'c','o','m','o','\0'}, {'e','s','t','a','\0'}};
	
	imprimirMat(mat);
	ordenarTexto(mat);
	imprimirMat(mat);
	
	return 0;	
}

void imprimirMat(char mat[][N]){
	int i,j;
	for(i = 0; mat[i][0] != '\0'; i++){
		printf("\n");
		for(j = 0; mat[i][j] != '\0'; j++){
			printf("%c ",mat[i][j]);
		}
	}
	printf("\n");
}

void ordenarTexto(char mat[][N]){
	char aux1[N+1];
	char aux2[N+1];
	int i,j;
	//for(i = 0; i < NFIL-1;i++){
		for(j = 0; j < NFIL;j++){
			printf("J-%d\n",j);
			matParser(aux1,aux2,mat,j);
			printf("STRING1: %s\n",aux1);
			printf("STRING2: %s\n",aux2);
			printf("J-%d\n",j);
			printf("STRCMP: %d\n",strcmp(aux1,aux2));
			/*if(strcmp(aux1,aux2) < 0){
				strToMat(mat,aux2,j);
				strToMat(mat,aux1,j+1);
			}*/
		}
	//}
}
	
void matParser(char str1[], char str2[],char mat[][N], int fila){
	int i;
	printf("\n------ INIT MATPARSER ------\n");
	for(i = 0; (i < N) || (mat[fila][i] != '\0'); i++){
		str1[i] = mat[fila][i];
	}
	
	//str1[i] = '\0';
	printf("STRING1: %s\n", str1);
	for(i = 0; (i < N) || (mat[fila+1][i] != '\0'); i++){
		str2[i] = mat[fila+1][i];
	}
	
	str2[i] = '\0';
	printf("STRING2: %s\n", str2);
	printf("------ END MATPARSER ------\n");
}

void strToMat(char mat[][N],char str[],int fila){
	int i;
	for(i = 0; str[i] != '\0'; i++){
		mat[fila][i] = str[i];
	}
	mat[fila][i] = '\0';
	imprimirMat(mat);
}
	
