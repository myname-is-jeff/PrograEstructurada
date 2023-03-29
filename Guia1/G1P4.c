/*
Desarrollar las funciones cargarArr, imprimirArr y invertirArr.
cargarArr: carga desde teclado un arreglo de números enteros pasado por parámetro.
El cero determina el fin de los valores útiles del arreglo.
imprimirArr: imprime en pantalla el contenido del arreglo de números enteros pasado
por parámetro.
invertirArr: invierte el arreglo de números enteros pasado por parámetro.
Luego, desarrollar el programa principal declarando dos arreglos (arr1 y arr2) de
números enteros de tamaño T. Uno de los arreglos deberá ser cargado, luego invertirlo y
por último impreso. El otro arreglo deberá ser cargado, luego ordenado y por último
impreso. Se debe utilizar las funciones que se solicita desarrollar.
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>



void cargarArr(int arr[], size_t len){
	for(int i = 0;i < ((int)len);i++){
		arr[i] = (rand() % 10);
		printf("%d - %d\n",i,arr[i]);
	}
}

void imprimirArr(int arr[], size_t len){
	printf("\n");
	for(int i = 0; i != ((int)len); i++){
		printf(" ___");
	}
	printf("\n| ");
	for(int i = 0; i != ((int)len); i++){
		printf("%d %s",arr[i],"| ");
	}
	printf("\n");
	for(int i = 0; i != ((int)len); i++){
		printf(" ---");
	}
}

void invertirArr(int arr[],size_t len){
	int aux[len];
	int y = ((int)len);
	y--;
	for(int i = 0; i < ((int)len); i++){
		aux[y] = arr[i];
		y--;
	}
	for(int i = 0; i < ((int)len); i++){
		arr[i] = aux[i];
	}
}

void ordenarArr(int arr[],size_t len){
	int aux;
	for (int i = 0; i < ((int)len) - 1; i++) {
		for (int j = i + 1; j < ((int)len); j++) {
			if (arr[i] > arr[j]) {
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}
}



int main(void){
	int arr[11];
	size_t len;
	len = (sizeof(arr)/sizeof(arr[0]));
	cargarArr(arr,len);
	imprimirArr(arr,len);
	invertirArr(arr,len);
	imprimirArr(arr,len);
	ordenarArr(arr,len);
	imprimirArr(arr,len);
	return 0;
}
