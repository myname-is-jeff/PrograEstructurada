/* pastebin.com/uRYpH9j0 
   pastebin.com/ZZNWKbde
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * txt;
	char * autor;
    int len;
}texto_t;

void cargarTexto(texto_t * texto);
texto_t * cargarSturctTexto();
void escribirArchTex(const char * nomArch, texto_t * texto);

int main(void){
	
    escribirArchTex("fcl.csv", cargarSturctTexto());
	
    return 0;
}

void cargarTexto(texto_t * texto){
    char * auxa = NULL;
	char * auxb = NULL;
	int len = 0;
	char c;
	
	auxa = (char *)malloc(sizeof(char)*2);
	if(auxa == NULL){
		printf("ERROR MEMORIA AUTOR\n");
	}
	else{
		printf("Introduci la frase o presiona ENTER para salir: ");
		
		while((c = getchar()) != '\n'){
			auxb = realloc(auxa,sizeof(char)*(2+len));
			if(auxb != NULL){
				auxa = auxb;
				auxa[len] = c;
				len++;
			}
			else{
				printf("ERROR REALLOC FRASE\n");
			}
		}
		auxa[len] = '\0';
	}
	
	(texto->txt) = auxa;
	(texto->len) = len;
	if(len != 0){
		auxa = NULL;
		auxb = NULL;
		len = 0;
		
		
		auxa = (char *)malloc(sizeof(char)*2);
		if(auxa == NULL){
			printf("ERROR MEMORIA AUTOR\n");
		}
		else{
			printf("Introduci el Autor: ");
			
			
			while((c = getchar()) != '\n'){
				auxb = realloc(auxa,sizeof(char)*(2+len));
				if(auxb != NULL){
					auxa = auxb;
					auxa[len] = c;
					len++;
				}
				else{
					printf("ERROR REALLOC AUTOR\n");
				}
			}
			auxa[len] = '\0';
			
			(texto->autor) = auxa;
		}
	}
	else{
		(texto->txt) = NULL;
		(texto->len) = len;
		free(auxa);
		free(auxb);
	}
}

void escribirArchTex(const char * nomArch, texto_t * texto){
	FILE * fp;
	int len = 0;
	
	fp = fopen(nomArch,"w");
	if(fp == NULL){
		printf("ERROR OPENING FILE\n");
	}
	else{
		while(texto[len].len != 0){
			fprintf(fp,"%d,%s,%s\n",texto[len].len,texto[len].txt,texto[len].autor);
			len++;
		}
	}
	fclose(fp);
}

texto_t * cargarSturctTexto(){
	texto_t * arr;
	texto_t * aux;
	int largo = 0;
	
	arr = (texto_t*)malloc(sizeof(texto_t)*2);
	if(arr == NULL){
		printf("ERROR ARRAY INIT\n");
	}
	else{
		cargarTexto(&(arr[largo]));
		while((arr[largo].txt) != NULL){
			aux = realloc(arr,sizeof(texto_t)*(1+largo));
			if(aux != NULL){
				arr = aux;
				largo++;
				cargarTexto(&(arr[largo]));
			}
			else{
				printf("ERROR REALLOC AUTOR\n");
			}
		}
		
	}
	return arr;
}

