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
