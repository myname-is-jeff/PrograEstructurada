#include <stdlib.h>
#include <stdio.h>

char * subcadena(char * p, int i, int n);
char * leerArch(const char * nomArch);

int main(){
	char* str = NULL;
	char* subStr = NULL;
	int i, n;
	
	i = 8; n = 5;
	
	if((str = leerArch("frase.txt")) == NULL){
		printf("ERROR LEER ARCH\n");
	}
	else{
		if((subStr = subcadena(str, i, n)) == NULL){
			printf("ERROR SUBCADENA\n");
		}
		else{
			printf("Para i = %d y n = %d ,Se encontro el substring:",i,n);
			printf("%s", subStr);
		}
	}

	return 0;
}
char * subcadena(char * p, int i, int n){
	char * str = NULL;
	char * aux = NULL;
	int j,end;
	
	end = i + n;
	for(j = 0; p[j] != '\0'; j++);
	if(j > (i + n)){
		if((str = (char *)malloc(sizeof(char)*2)) == NULL){
			printf("ERROR INICIO DE MEMORIA\n");
		}
		else{
			for(j = 0; i < end; i++){
				if((aux = realloc(str,sizeof(char))) == NULL){
					printf("ERROR\n");
				}
				else{
					str = aux;
					str[j] = p[i];
					j++;
				}
			}
			str[j] = '\0';
		}
	}

	return str;
}

char * leerArch(const char * nomArch){
	char * aux = NULL;
	char * str = NULL;
	char string[2];
	FILE * fp;
	int len;
	
	len = 0;
	
	if((fp = fopen(nomArch, "r")) == NULL){
		printf("ERROR OPENING FILE\n");
	}
	else{
		if(((str) = (char *)malloc(sizeof(char)*2)) == NULL){
			printf("ERROR INICIO DE MEMORIA\n");
		}
		else{
			while(((fgets(string,2,fp)) != NULL)){
				if((aux = realloc(str,sizeof(char))) == NULL){
					printf("ERROR\n");
					break;
				}
				else{
					str = aux;
					str[len] = string[0];
					len++;
				}
			}
			str[len] = '\0';
		}
	}
	
	fclose(fp);
	return str;
}
