/*
Realizar una funci�n que reciba como par�metro una letra y que la cambie a may�scula
(si est� en min�scula) o que la cambie a min�scula (si est� en may�scula). Dicha
cambio consiste en cambiar un solo bit del char. Determinar cu�l es ese bit, qu�
operador hay que aplicar sobre el char original y con qu� m�scara. La funci�n tendr�
una �nica l�nea:
return letra <OPERADOR> <M�SCARA>
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
