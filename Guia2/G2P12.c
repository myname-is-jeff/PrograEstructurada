/*
Realizar una función que reciba como parámetro una letra y que la cambie a mayúscula
(si está en minúscula) o que la cambie a minúscula (si está en mayúscula). Dicha
cambio consiste en cambiar un solo bit del char. Determinar cuál es ese bit, qué
operador hay que aplicar sobre el char original y con qué máscara. La función tendrá
una única línea:
return letra <OPERADOR> <MÁSCARA>
*/

#include <stdio.h>

#define MASCARA 32

typedef unsigned char uchar;

uchar tamanio(uchar letra);

int main (void){
	uchar letra = 'H';
	
	printf("Original: %c\n", letra);
	printf("Cambio: %c\n", tamanio(letra));
	
	return 0;
}

uchar tamanio(uchar letra){
	return letra ^ MASCARA;
}
