/*
Desarrollar las funciones cargarMatText, imprimirMatText, y ordenarMatText.
-cargarMatText: carga desde teclado una matriz de char de F x C pasada por
par�metro. Por cada fila carga un texto el cual debe contener el �\0� al final de los
caracteres �tiles (concepto de string). Para marcar el fin de las filas �tiles deber�
agregar en la siguiente fila (a la �ltima �til) un�\0�( en la columna cero) [nota1].
-imprimirMatText: Imprime la matriz de char de F x C pasada por par�metro.
-ordenarMatText: recibe una matriz de char de F x C . La funci�n deber� ordenar la
matriz en orden alfab�tico ascendente. Tener en cuenta que los contenidos de la matriz
pueden tener tanto letras may�sculas como min�sculas.
Desarrollar el programa principal que cargue una matriz, luego la muestre en pantalla. A
continuaci�n ordenar la matriz y luego volver a imprimirla para verificar el orden.
Nota1: (M�todo). Un �\0� en una fila (y cualquier columna) determinar� el fin de los
caracteres �tiles de dicha fila. Y un �\0� en columna 0 (cero) en una fila cualquiera,
determinar� el fin de las filas �tiles de la matriz.
Este m�todo (ad hoc) adoptado no permite identificar en la matriz cadena de caracteres
vac�as (s�lo la �ltima).
*/

#include <stdio.h>
#include <stdlib.h>
#include "bauti.h"

#define F 10
#define C 100

void cargarMatText(char mat[][C]);
void imprimirMatText(char mat[][C]);
void ordenarMatText(char mat[][C]);

int main(void){
    char mat[F][C];

    cargarMatText(mat);
    imprimirMatText(mat);

    return 0;

}

void cargarMatText(char mat[][C]){
    int i,j;
    char str[110];

    for(i = 0; i < F;i++){
        printf("Escriba texto: ");
        if(fgets(str,C, stdin) != NULL){
            if(str[0] != '0'){
                for(j = 0; str[j] != '\n'; j++){
                    mat[i][j] = str[j];
                }
            }
            mat[i][j++] = '\0'; 
        }
    }
}

void imprimirMatText(char mat[][C]){
    int i,j;

    for(i = 0; i < F; i++){
        for(j = 0; mat[i][j] != '\0'; j++){
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
}
