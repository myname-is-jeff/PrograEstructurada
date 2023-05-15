#include <stdio.h>
#include <stdlib.h>
/* cuando escribo algo muy largo me tira segmen fault */
char * cargarStrDin();

int main(void){
	char * p = NULL;
	p = cargarStrDin();
	printf("REMITO1: %s\n", p);

	return 0;
}

char * cargarStrDin(){
	char * str;
	char * aux;
	char c;
	int len;
	
	len = 0;
	
	if((str = (char *)malloc(sizeof(char))) == NULL){
		printf("ERROR INICIO DE MEMORIA\n");
	}
	else{
		printf("Ingrese texto y presione enter para terminar:\n");
		while((c = getchar()) != '\n'){
			if((aux = realloc(str,sizeof(char))) == NULL){
				printf("ERROR\n");
				str[len] = '\0';
				return str;
			}
			else{
				str = aux;
				str[len] = c;
				len++;
			}
		}
		str[len] = '\0';
	}
	
	return str;
}

