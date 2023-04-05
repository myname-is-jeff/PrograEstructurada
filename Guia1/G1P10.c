/*
Crear un archivo de texto, �equipos.txt�, utilizando un editor de texto plano, que
contenga nombres de equipos de f�tbol, cada uno en una l�nea diferente (es decir una
abajo del otro).
Desarrollar la funci�n cargarMatTexDeArch qu� recibe por par�metro una matriz de F
x C (vac�a) y un texto que indica el nombre del archivo. La funci�n deber� cargar en la
matriz pasada por par�metro, los nombres de los equipos que se encuentran guardados
en el archivo de texto. Para cargar los datos en la matriz utilizar el mismo m�todo
descrito en ejercicio anterior.
Desarrollar el programa principal que invocando a las funci�n mencionada, pas�ndole el
par�metro de la matriz y el nombre del archivo realice la carga. Luego imprimir la matriz
en pantalla (utilizar alguna funci�n realizada anteriormente).
*/
#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 25

void cargarMatTexDeArch(char mat[][C]);
void imprimirMat(char mat[][C]);

int main(void){
    char mat[F][C];

    cargarMatTexDeArch(mat);
    imprimirMat(mat);

    return 0;
}

void cargarMatTexDeArch(char mat[][C]){
    FILE *fp;
    char str[100];
    int i,j;
    
    fp = fopen("equipos.txt","r");
    if(fp == NULL){
        perror("Error opening file");
        fclose(fp);
    }
    else{
        for(i = 0; i < F; i++){
            if(fgets(str, 50, fp) != NULL){
                for(j = 0; str[j] != '\n'; j++){
                    mat[i][j] = str[j];
                }
				mat[i][j++] = '\0';
            }
			else{
				mat[i][0] = '\0';
			}
        }
		
    }
    fclose(fp);
}

void imprimirMat(char mat[][C]){
	int i,j;
	
	for(i = 0; mat[i][0] != '\0'; i++){
		printf("\n");
		for(j = 0; mat[i][j] != '\0'; j++){
			printf("%c ",mat[i][j]);
		}
		
	}
}
