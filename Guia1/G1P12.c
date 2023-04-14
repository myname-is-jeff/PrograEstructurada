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
#define ILOGICO 123456


void cargarMatNumDeArch(int mat[][C], char nombre_arch[]);
void imprimirMatNum(int mat[][C]);
void csvNumParser(char str[], int aux[]);

int main(void){
    int mat[F][C];
    char nombre_arch[] = "puntos.txt";
    
    cargarMatNumDeArch(mat, nombre_arch);
    imprimirMatNum(mat);

    return 0;
}
void csvNumParser(char str[], int aux[]){
	int res,i,j,k;
	char token[10];
	char * temp;
	
	k = 0;
	printf("STR: %s\n", str);
	for(i = 0; str[i] != '\n'; i++){
		j = 0;
		for(j = 0; str[i] != ';' && str[i] != '\n'; i++){
			token[j] = str[i];
			j++;
		}
		
		token[j] = '\0';
		printf("TOKEN: %s\n", token);
		res = strtol(token,&temp,10);
		printf("RES: %d\n", res);
		if(*temp == '\0'){
			aux[k] = res;
			printf("AUX: pos: %d -- value: %d\n", k, aux[k]);
			k++;		
		}
		if(str[i] == '\n'){
			i--;
		}
	}
	printf("K-END-CSVPAR: %d\n", k);
	aux[k] = ILOGICO;
}
	
void cargarMatNumDeArch(int mat[][C], char nombre_arch[]){
    FILE *fp;
    char str[100];
	int aux [10];
    int i,j,k;
    
    fp = fopen(nombre_arch,"r");
    if(fp == NULL){
        perror("Error opening file");
        fclose(fp);
    }
    else{
        for(i = 0; i < F; i++){
            if(fgets(str, 50, fp) != NULL){
				printf("\n---- INIT csvNumParser ----\n");
				csvNumParser(str,aux);
				printf("\n---- END csvNumParser ----\n\n");

				printf("\n---- INIT aux check ----\n");
				for(k = 0; aux[k] != ILOGICO; k++){
					printf("aux; pos: %d -- value: %d\n", k, aux[k]);
				}
				printf("---- END aux check ----\n\n");
				for(j = 0; aux[j] != ILOGICO;j++){
					mat[i][j] = aux[j];
					printf("matcpy; posF: %d posC: %d  num: %d\n", i, j, mat[i][j]);
                }
				mat[i][j++] = ILOGICO;
            }
			else{
				mat[i][0] = ILOGICO;
			}
        }
        fclose(fp);
    }
}

void imprimirMatNum(int mat[][C]){
	int i,j;
	
	for(i = 0; i < F; i++){
		printf("\n");
		for(j = 0; mat[i][j] != ILOGICO; j++){
			printf("%d ",mat[i][j]);
		}
		
	}
}
