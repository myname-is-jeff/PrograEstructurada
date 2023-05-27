#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char * txt;
	char * autor;
	int len;
}texto_t;

void cargarTexto(texto_t * texto);
texto_t * cargarSturctTexto();
void escribirArchTex(const char * nomArch, texto_t * texto);
void ordenarTexto(texto_t * arr);
void textPrint(texto_t text);

int main(void){
	texto_t * arr = NULL;
	int len = 0;
	arr = cargarSturctTexto();
	while(arr[len].txt != NULL){
		textPrint(arr[len]);
		len++;
	}
	ordenarTexto(arr);
	len = 0;
	printf("-------------------------------\n");
	while(arr[len].txt != NULL){
		textPrint(arr[len]);
		len++;
	}
	escribirArchTex("fcl.csv", arr);
	
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
				break;
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
					break;
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
	
	fp = fopen(nomArch,"a");
	if(fp == NULL){
		printf("ERROR OPENING FILE\n");
	}
	else{
		while(texto[len].txt != NULL){
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
			aux = realloc(arr,sizeof(texto_t)*(2+largo));
			if(aux != NULL){
				arr = aux;
				largo++;
				cargarTexto(&(arr[largo]));
				}
			else{
				printf("ERROR REALLOC ARR\n");
				break;
			}
		}
	
	}
	return arr;
}
	
void ordenarTexto(texto_t * arr){
	texto_t aux;
	int i,len,j;
	
	for(i = 0; i < 4; i++){
		len = 0;
		while((arr[len].txt != NULL) && (arr[len+1].txt != NULL)){
			j = strcmp(arr[len].txt,arr[len+1].txt);
			if(j > 0){
				aux = arr[len];
				arr[len] = arr[len+1];
				arr[len+1] = aux;
				len++;
			}
			else{
				len++;
			}
		}
	}
}

void textPrint(texto_t text){
	printf("Largo: %d\nFrase: %s\nAutor: %s\n",text.len,text.txt,text.autor);
}
