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
#include <string.h>

typedef enum {
    FALSE,
    TRUE
} bool_t;

bool_t estaEnArr(int arr[], int aux){
    bool_t res;
	int i;
    
    res = FALSE;

    for(i = 0; (arr[i] != '\0') && (res == FALSE); i++){
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

void limpieza(void){
	char c;
	
	while((c = getchar()) != '\n' && c != EOF);
}

void cargarArrPNR(int arr[]){
    int aux;
	int i;
	int end;
	int y;
	
	end = '\0';
	i = 0;
	arr[i] = end;
	
    printf("Ingrese un entero positivo o 0 para terminar: ");
    scanf("%d",&aux);

	while(aux != 0){
		
		if (esPos(aux) == TRUE && estaEnArr(arr, aux) == FALSE){
			arr[i] = aux;
			y = i + 1;
			arr[y] = end;
		}
		else {
			i--;
		}
		
		limpieza();
		printf("Ingrese un entero positivo o 0 para terminar: ");
		scanf("%d",&aux);
		
		i++;
    }
}

void imprimirArr(int arr[]){
	int i;
	
	i = 0;
	
	while(arr[i] != '\0'){
		printf(" ___");
		i++;
	}
	i = 0;
	printf("\n| ");
	while(arr[i] != '\0'){
		printf("%d %s",arr[i],"| ");
		i++;
	}
	i = 0;
	printf("\n");
	while(arr[i] != '\0'){
		printf(" ---");
		i++;
	}
}

int main(void){
	int arr[100];
	
    cargarArrPNR(arr);
    imprimirArr(arr);
	
    return 0;
}


