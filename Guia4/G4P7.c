#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int contar_vocales(char * str);
int isvocal(char c);

int main(void){
	char str[] = "Hola como ESTAS pedAzo de PutIn";
	printf("TIENE %d vocales\n",contar_vocales(str));
	return 0;
}

unsigned int contar_vocales(char * str){
	int res = 0;
	if(*str != '\0'){
		res += isvocal(*str);
		res += contar_vocales(str+1);
	}
	return res;
}

int isvocal(char c){
	int res = 0;
	char arr[] = "aeiouAEIOU";
	if(strchr(arr,c) != NULL){
		res = 1;
	}
	return res;
}
