#include <stdio.h>

#define MASK1 2147483648
#define MASK2 1
#define MASK3 255

typedef unsigned char uchar;
typedef unsigned int uint;

uint coder(uchar cstr[]);
void binaryPrint(uint x);
void decoder(uchar str[], int cod);

int main (void){
	uchar arr[] = "hola";
	uchar str[5];
	uint cod;
	
	cod = coder(arr);
	printf("Los 4 uchar codificados son: %d\n",cod);
	binaryPrint(cod);
	
	decoder(str,cod);
	printf("Los 4 uchar decodificados son: %s\n",str);
	
	return 0;
}
	
uint coder(uchar str[]){
	uint res;
	int i;
	res = 0;
	for(i = 0; str[i] != '\0'; i++){
		res = res | str[i];
		if(str[i+1] != '\0'){
			res = res << 8;
		}
		
	}
	return res;
}
	
void decoder(uchar str[], int cod){
	int i;
	
	for(i = 3; i >= 0; i--){
		str[i] = (cod & MASK3);
		cod = cod >> 8;
		printf("DEBUG STR[I]: %c --- I: %d\n",str[i],i);
	}
	str[4] = '\0';
}
	
void binaryPrint(uint x){
	int i;
	
	printf("En binario: ");
	
	for(i = 0; i < 32;i++){
		printf("%d",(((x << i) & MASK1)>> 31)&MASK2);
	}
	printf("\n");
}
	
