/*
Crear un archivo de texto, ”equipos.txt”, utilizando un editor de texto plano, que
contenga nombres de equipos de fútbol, cada uno en una línea diferente (es decir una
abajo del otro).
Desarrollar la función cargarMatTexDeArch qué recibe por parámetro una matriz de F
x C (vacía) y un texto que indica el nombre del archivo. La función deberá cargar en la
matriz pasada por parámetro, los nombres de los equipos que se encuentran guardados
en el archivo de texto. Para cargar los datos en la matriz utilizar el mismo método
descrito en ejercicio anterior.
Desarrollar el programa principal que invocando a las función mencionada, pasándole el
parámetro de la matriz y el nombre del archivo realice la carga. Luego imprimir la matriz
en pantalla (utilizar alguna función realizada anteriormente).
*/
#include <stdio.h>
#include <stdlib.h>

#define F 10
#define C 10

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
            if(fgets(str, 100, fp) != NULL){
                printf("\n%s\n",str);
                for(j = 0; str[j] != '\n'; j++){
                    mat[i][j] = str[j];
                }
            }
            mat[i][j] = '\0';
        }
    }
    fclose(fp);
}

void imprimirMat(char mat[][C]){
    int i,j;

    for(i = 0; mat[i][0] != '\0'; i++){
        for(j = 0; mat[i][j] != '\0'; j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");
    }
}
