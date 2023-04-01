/*
Desarrollar las funciones cargarText, imprimirText, y normalizar.
cargarText: carga desde teclado un arreglo de char pasado por par�metro, hasta
ingresar un �enter� (utilizar el car�cter �\r� para detectarlo). El texto debe contener �\0�
como car�cter final.
imprimirText: imprime en pantalla el contenido de un arreglo de char pasado por
par�metro.
normalizar: recibe por par�metro un arreglo de char y debe verificar que:
- La primer letra del texto sea may�scula.
- Que haya un s�lo espacio entre palabras
- Y que el texto termine con un punto (�.�).
En caso de encontrar alguna diferencia deber� ser corregida (modificar arreglo) .
Desarrollar el programa principal que invocando a las funciones mencionadas, cargue el
arreglo, lo imprima, luego lo normalice y por �ltimo lo vuelva a imprimir para verificar el
texto.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef enum {
	TRUE,
	FALSE
} bool_t;


void cargarArr(char arr[], int len){
	printf("Ingrese texto: ");
	while(fgets(arr,len,stdin) == NULL){
		printf("Ingrese texto:");
	}
}

void imprimirArr(char arr[]){
	int i;
	
	printf("Resultado:");
	for(i = 0; arr[i] != '\n';i++){
		printf("%c",arr[i]);
	}
}
	
void normalizar(char arr[], int len){
	bool_t ban = TRUE;
	char aux[len];
	int i,y,j;
	
	//verifico que el primer caracter alfabetico sea mayuscula y lo cambio en caso contrario
	for(i = 0; arr[i] != '\n' && ban == TRUE; i++){
		if(isalpha(arr[i])){
			ban = FALSE;
			if(isupper(arr[i]) == 0){
				arr[i] = toupper(arr[i]);
			}
		}
		
	}
	//elimino los espacios repetidos 
	j = 0;
	for(i = 0; arr[i] != '\n'; i++){
		while(isspace(arr[i])){
			i++;
		}
		y = i + 1;
		if((arr[i] == arr[y]) != 0 && isspace(arr[i])){
		}
		else{
			printf("%c\n",arr[i]);
			aux[j] = arr[i];
			j++;
		}
	}
	aux[j] = '.';
	j++;
	aux[j] = '\n';
	printf("\n%s\n",aux);
	for(i = 0; aux[i] != '\n'; i++){
		arr[i] = aux[i];
	}
	//i++;
	arr[i] = aux[i];
}
	
int main (void){
	int max_str = 100;
	char str[max_str+2];
	if(max_str){
		printf("---\n");
	}
	cargarArr(str, max_str);
	normalizar(str, max_str);
	imprimirArr(str);
	
}
