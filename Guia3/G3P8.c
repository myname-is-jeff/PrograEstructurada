#include <stdio.h>
#include <stdlib.h>
/* cuando escribo algo muy largo me tira error  3221225477 (0xC0000005)!!!*/
/* Zinjal tema de permisos? me tira error como que windows lo bloquea pero desde el cmd anda joya*/

void cargarStrDin2(char ** str);
void escribirArch(const char * nomArch, char * cadena);
void imprimirArch(const char * nomArch);
void imprimirArr(char * arr);
int main(void){
	char * str = NULL;
	printf("----INIT CARGARSTRDIN2 ----\n");
	cargarStrDin2(&str);
	printf("----END CARGARSTRDIN2 ----\n");
	printf("----INIT ESCRIBIRARCH ----\n");
	escribirArch("frase.txt", str);
	printf("----END ESCRIBIRARCH ----\n");
	imprimirArch("frase.txt");
	
	return 0;
}

void cargarStrDin2(char ** str){
	char * aux;
	char c;
	int len;
	
	len = 0;
	
	if(((*str) = (char *)malloc(sizeof(char)*2)) == NULL){
		printf("ERROR INICIO DE MEMORIA\n");
	}
	else{
		printf("Ingrese texto y presione enter para terminar:\n");
		while((c = getchar()) != '\n'){
			if((aux = realloc(*str,sizeof(char))) == NULL){
				printf("ERROR\n");
				break;
			}
			else{
				*str = aux;
				(*str)[len] = c;
				len++;
			}
		}
		(*str)[len] = '\0';
	}
}

void escribirArch(const char * nomArch, char * cadena){
	FILE * fp;
	int i;
	printf("hola\n");
	if((fp = fopen(nomArch, "w")) == NULL){
		printf("ERROR OPENING FILE\n");
	}
	else{
		printf("---- INIT FOR ----\n");
		for(i = 0; cadena[i] != '\0'; i++){
			fprintf(fp,"%c",cadena[i]);
			printf("%c\n", cadena[i]);
		}
		printf("---- END FOR ----\n");
		/* verifico que haya salido del ciclo -> encontro el \0*/
		fprintf(fp,"\n");
	}
	
	fclose(fp);
}
void imprimirArch(const char * nomArch){
	FILE * fp;
	char str[100];
	
	if((fp = fopen(nomArch, "r")) == NULL){
		printf("ERROR OPENING FILE");
	}
	else{
		fgets(str,100,fp);
		printf("%s",str);
	}
	
	fclose(fp);
}

void imprimirArr(char * arr){
	int i;
	
	for(i = 0; arr[i] != '\0'; i++){
		printf("%c\n",arr[i]);
	}
	/* verifico que haya salido del ciclo -> encontro el \0*/
	printf("%s\n","0");
}
