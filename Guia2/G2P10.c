/*
Realizar una función que efectúe el SHIFT A DERECHA completando con 0 desde la
izquierda. Aplicarla en un programa de ejemplo.*/

#include <stdio.h>
#include <stdlib.h>

#define MASK1 2147483648
#define MASK2 1

int aBinario(unsigned int c);

int main(void){
	unsigned int c = 455;
	printf("cantidad de Bits en 1: %d",aBinario(c));
	return 0;
}
	
int aBinario(unsigned int c){
	int i,j;
	j = 0;
	for(i = 0; i < 32;i++){
		if((((c << i) & MASK1)>> (31))&MASK2 == MASK2){
			j++;
		}
		printf("%d",(((c << i) & MASK1)>> 31)&MASK2);
	}
	printf("\n");
	return j;
}
