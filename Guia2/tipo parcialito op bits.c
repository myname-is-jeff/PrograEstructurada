/*
agarrar el dni y extraer los bits 10-14 y almacenarlos en otro numero por medio de una funcion
imprimir todo
*/
#include <stdio.h>

#define MASK 31
#define MASK1 2147483648
#define MASK2 1

typedef unsigned int uint;

uint extraer(uint num);
void binaryPrint(uint x);

int main (void){
	uint num,res;
	
	num = 12345678;
	res = extraer(num);
	printf("Numero original ");
	binaryPrint(num);
	printf("Resultado ");
	binaryPrint(res);
	
	printf("NUMERO ORIGINAL: %d ------ RESULTADO: %d\n",num,res);
	
	return 0;
}

uint extraer(uint num){
	return ((num >> 9)&MASK);
}

void binaryPrint(uint x){
	int i;
	
	printf("en binario: ");
	
	for(i = 0; i < 32;i++){
		printf("%d",(((x << i) & MASK1)>> 31)&MASK2);
	}
	printf("\n");
}
		
		
