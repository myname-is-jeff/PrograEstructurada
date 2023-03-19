/*
Desarrollar un programa en el que se ingrese un texto de hasta 100 caracteres
finalizando con “ENTER” (utilizar ‘\r’ para detectar el ingreso de “ENTER”). Luego, el
usuario deberá elegir un caracter al cual reemplazar y otro caracter con el cual
reemplazará al anterior. El programa finalmente mostrará por pantalla el string
modificado.
Para esto el programa principal deberá hacer uso de dos funciones, la función leer que
guardará en un arreglo el string ingresado y la función reemplazar que reemplazará
todas las ocurrencias del caracter indicado en el el string
*/

#include <stdlib.h>
#include <stdio.h>

void reemplazar(char cad[], char remp, char obj,int max){
	int i;
	for (i = 0; i != max; i++){
		if (cad[i] == obj){
			cad[i] = remp;
		}
	}
}

int main (void){
	int max_str = 100;
	char str[max_str+2];
	char remp;
	char obj;
	char c;
	
	printf("Ingrese texto: ");
	while(fgets(str,max_str+2,stdin) == NULL){
		printf("Ingrese texto: ");
	}
	printf("Ingrese carácter a reemplazar: ");
	scanf("%c",&obj);
	while((c = getchar()) != '\n' && c != EOF);
	printf("Ingrese carácter reemplazo: ");
	scanf("%c",&remp);
	reemplazar(str,remp,obj,max_str+2);
	printf("Resultado: %s",str);
}


















