/*
Desarrollar las funciones cargarText, imprimirText, y normalizar.
cargarText: carga desde teclado un arreglo de char pasado por parámetro, hasta
ingresar un “enter” (utilizar el carácter ‘\r’ para detectarlo). El texto debe contener ‘\0’
como carácter final.
imprimirText: imprime en pantalla el contenido de un arreglo de char pasado por
parámetro.
normalizar: recibe por parámetro un arreglo de char y debe verificar que:
- La primer letra del texto sea mayúscula.
- Que haya un sólo espacio entre palabras
- Y que el texto termine con un punto (“.”).
En caso de encontrar alguna diferencia deberá ser corregida (modificar arreglo) .
Desarrollar el programa principal que invocando a las funciones mencionadas, cargue el
arreglo, lo imprima, luego lo normalice y por último lo vuelva a imprimir para verificar el
texto.*/

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
		printf("Ingrese texto: ");
	}
}

void imprimirArr(char arr[]){
	printf("Resultado: %s",arr);
}
	
void normalizar(char arr[], int len){
	bool_t ban = TRUE;
	char aux[len];
	int esp = (int)" ";
	//verifico que el primer caracter alfabetico sea mayuscula y lo cambio en caso contrario
	for(int i = 0; (i < len) && ban == TRUE; i++){
		if(isalpha((int)arr[i])){
			ban = FALSE;
			if(isupper((int)arr[i])){
				toupper((int)arr[i]);
			}
		}
		printf("%d",i);
	}
	//elimino los espacios repetidos 
	for(int i = 0; (i < len); i++){
		aux[i] = arr[i];
		while(((arr[i]) == esp) && (arr[i] == esp)){
			i++;
		}
		
	}
	for(int i = 0; (i < len); i++){
		arr[i] = aux[i];
	}
}
	
int main (void){
	int max_str = 100;
	char str[max_str+2];
	if(max_str){
		printf("---\n");
	}
	cargarArr(str, max_str);
	imprimirArr(str);
	normalizar(str, max_str);
	imprimirArr(str);
	
}
