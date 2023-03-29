/*
cargarArrPNR: carga desde teclado un arreglo de números enteros pasado por
parámetro. El cero determina el fin de los valores útiles del arreglo. Sólo cargará
números positivos y no repetidos (no debe haber números repetidos dentro del arreglo).
Llamará a la función estaEnArr para determinar si un número está dentro del arreglo.
Y llamará a la función esPos para determinar si un número es positivo.

estaEnArr: recibe por parámetro un arreglo de números enteros, y un número entero.
La función retorna 1 si el número se encuentra dentro del arreglo, o retorna 0 si el
número no está dentro del arreglo.

esPos: Recibe por parámetro un número entero y retorna 1 si el número es mayor e
igual que 0 (cero) y retorna 1 caso contrario.

Desarrollar el programa principal que utilizando la función cargarArrPNR cargue un
arreglo de números enteros de tamaño T con números enteros positivos. Utilizar la
función imprimirArr del ejercicio 4 para imprimir el arreglo en pantalla y así verificar
que no hay elementos repetidos en el arreglo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TRUE,
    FALSE
} bool_t;

bool_t estaEnArr(int arr[], int aux,int len){
    bool_t res;
    res = TRUE;
	
    for(int i = 0; (i < len) && (res == TRUE); i++){
        if (arr[i] != aux){
            res = FALSE;}
        else {
            res = TRUE;
        }
    }
    return res;
}

bool_t esPos(int aux){
    bool_t res;
    if (aux > 0){
        res = TRUE;
    }
    else {
        res = FALSE;
    }
    return res;
}

void cargarArrPNR(int arr[],int len){
    int aux;
   
    printf("Ingrese un entero positivo o 0 para terminar: ");
    scanf("%d",&aux);

    for (int i = 0; (i < len) && (aux != 0); i++){
    
        if (esPos(aux) == TRUE && estaEnArr(arr, aux, len) == FALSE){
            arr[i] = aux;
        }
        else {
            i--;
        }

        printf("Ingrese un entero positivo o 0 para terminar: ");
        scanf("%d",&aux);
    }
}

void imprimirArr(int arr[],size_t len){
	int i;
	printf("%d\n",(len));
	for(i = 0; i != (len); i++){
		printf(" ___");
	}
	printf("\n| ");
	for(i = 0; i != (len); i++){
		printf("%d %s",arr[i],"| ");
	}
	printf("\n");
	for(i = 0; i != (len); i++){
		printf(" ---");
	}
}

int main(void){
	int T;
	printf("Ingrese el largo del arreglo: ");
	scanf("%d",&T);
	printf("%d\n",T);
    int arr[T];

    cargarArrPNR(arr,T);
    imprimirArr(arr,T);
    return 0;
}


