/*
Realizar una función que reciba como parámetros 4 unsigned char y que coloque cada
uno de ellos en una variable de tipo unsigned int, que devolverá en su valor de retorno.*/

#include <stdio.h>

#define MASK1 2147483648
#define MASK2 1

typedef unsigned char uchar;
typedef unsigned int uint;
uint coder(uchar c1, uchar c2, uchar c3, uchar c4);
void binaryPrint(uint x);

int main (void){
	uchar c1,c2,c3,c4;
	uint cod;
	c1 = 'h';
	c2 = 'o';
	c3 = 'l';
	c4 = 'a';
	cod = chtoi(c1,c2,c3,c4);
	printf("Los 4 uchar codificados son: %d\n",cod);
	binaryPrint(cod);
	
	return 0;
}

uint coder(uchar c1, uchar c2, uchar c3, uchar c4){
	uint res;
	res = 0;
	res = res | c1;
	res = res << 8;
	res = res | c2;
	res = res << 8;
	res = res | c3;
	res = res << 8;
	res = res | c4;
	return res;
}

void binaryPrint(uint x){
	int i;
	
	printf("En binario: ");
	
	for(i = 0; i < 32;i++){
		printf("%d",(((x << i) & MASK1)>> 31)&MASK2);
	}
	printf("\n");
}
