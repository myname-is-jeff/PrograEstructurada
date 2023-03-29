/*
Desarrollar las funciones cargarArr, imprimirArr y invertirArr.
cargarArr: carga desde teclado un arreglo de n�meros enteros pasado por par�metro.
El cero determina el fin de los valores �tiles del arreglo.
imprimirArr: imprime en pantalla el contenido del arreglo de n�meros enteros pasado
por par�metro.
invertirArr: invierte el arreglo de n�meros enteros pasado por par�metro.
Luego, desarrollar el programa principal declarando dos arreglos (arr1 y arr2) de
n�meros enteros de tama�o T. Uno de los arreglos deber� ser cargado, luego invertirlo y
por �ltimo impreso. El otro arreglo deber� ser cargado, luego ordenado y por �ltimo
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
