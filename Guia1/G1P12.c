/*
Crear el archivo ”puntos.txt” cuyo contenido es CSV (del inglés Comma Separated
Values) utilizando un editor de texto plano. Cada línea del archivo contiene un conjunto
de datos correspondientes para cada uno de los equipos del ejercicio
anterior. Este conjunto contiene los siguientes datos:

Puntos, Partidos Jugados, Partidos Ganados, Partidos Empatados, Partidos
Perdidos, Goles a favor, Goles en Contra, Diferencia de Goles.

Desarrollar las funciones:
--cargarMatNumDeArch recibe por parámetro una matriz de números enteros de F x C y
el nombre de un archivo de texto. La función debe cargar en la matriz los valores
numéricos que se encuentran guardados en el archivo.
--imprimirMatNum recibe por parámetro una matriz de enteros y dos valores enteros
(fil y col) que indican el tamaño de la fila y de la columna respectivamente. La función
deberá imprimir los valores de la matriz con el formato que se muestra en el ejemplo.
En el programa principal realizar la carga y la impresión de la matriz, invocando a las
funciones anteriormente descritas.
*/ 

#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 10

void cargarMatNumDeArch(int mat[][C], char nombre_arch[]);
void imprimirMatNum(int mat[][C]);

int main(void){
    int mat[F][C];
    char nombre_arch = "puntos.txt";
    
    cargarMatNumDeArch(mat, nombre_arch);
    imprimirMatNum(mat);

    return 0;
}

void cargarMatNumDeArch(int mat[][C], char nombre_arch[]){
    FILE *fp;
    char str[100];
    int i,j;
    
    fp = fopen("puntos.txt","r");
    if(fp == NULL){
        perror("Error opening file");
        fclose(fp);
    }
    else{
        for(i = 0; i < F; i++){
            if(fgets(str, 50, fp) != NULL){
                for(j = 0; str[j] != '\n'; j++){
                    if(str[j] != ";"){
                        mat[i][j] = (int)str[j];
                    }
                    else{
                       mat[i][j] =" "; 
                    }
                }
				mat[i][j++] = '\0';
            }
			else{
				mat[i][0] = '\0';
			}
        }
        fclose(fp);
    }
}

void imprimirMatNum(int mat[][C]){
	int i,j;
	
	for(i = 0; mat[i][0] != '\0'; i++){
		printf("\n");
		for(j = 0; mat[i][j] != '\0'; j++){
			printf("%c ",mat[i][j]);
		}
		
	}
}
