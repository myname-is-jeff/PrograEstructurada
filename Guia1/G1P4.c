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



void cargarArr(int arr[]){
	int i;
	for(i = 0;i != 10 ;i++){
		arr[i] = (rand() % 10);
		printf("%d",arr[i]);
	}
	
}

void imprimirArr(int arr[]){
	size_t len;
	int i;
	len = (sizeof(arr)/sizeof(arr[0]));
	printf("%d\n",((int)len));
	for(i = 0; i != ((int)len); i++){
		printf(" ___ ");
	}
	printf("\n| ");
	for(i = 0; i != ((int)len); i++){
		printf("%d %s",arr[i],"| ");
	}
	printf("\n");
	for(i = 0; i != ((int)len); i++){
		printf(" --- ");
	}
}

void invertirArr(int arr[]){
	
}

void ordenarArr(int arr[]){
	
}


int main(void){
	int arr[11];
	
	cargarArr(arr);
	imprimirArr(arr);
	return 0;
}
