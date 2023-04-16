#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  N 5

typedef enum{
	TRUE,
	FALSE
}bool_t;

typedef struct{
	int dni;
	char nombre[50];
	char pais[50];
}person_t;

void cargarArrDeArch(person_t arr[], char nombre_arch[]);
void imprimirTabla(person_t arr[]);

int main(void){
	person_t arr[N];
	char nombre_arch[] = "personas.txt";
	
	cargarArrDeArch(arr,nombre_arch);
	imprimirTabla(arr);
	
	return 0;
}


void cargarArrDeArch(person_t arr[], char nombre_arch[]){
	FILE *fp;
	int i;
	person_t aux;
	char str[100];
	/*csvparser*/
	int res,y,k,z;
	char token[10];
	char * temp;
	
	fp = fopen(nombre_arch,"r");
	
	if(fp == NULL){
		perror("Error opening a file");
		fclose(fp);
	}
	else{
		for(i = 0; i < N; i++){
			if(fgets(str, 100, fp) != NULL){
				z = 0;
				for(y = 0; str[y] != '\n'; y++){
					z++;
					k = 0;
					for(k = 0; str[y] != ',' && str[y] != '\n'; y++){
						token[k] = str[y];
						k++;
					}
					token[k] = '\0';
					switch(z){
						case 1:
							res = strtol(token,&temp,10);
							aux.dni = res;		
							break;
						case 2:
							strcpy(aux.nombre,token);
							break;
						case 3:
							strcpy(aux.pais,token);
							break;
					}
					if(str[y] == '\n'){
						y--;
					}
				}
			}
			arr[i] = aux;
		}
	}
}
	
void imprimirTabla(person_t arr[]){
	int i,j,k;
	person_t structaux;
	
	printf("Nombre              Documento         Pais\n");
	printf("===================================================");
	for(i = 0; i < 5; i++){
		printf("\n");
		structaux = arr[i];
		for(j = 0; structaux.nombre[j] != '\0'; j++);
		j++;
		printf("%s",structaux.nombre);
		for(k = j; k <= 20; k++){
			printf(" ");
		}
		for(k = k; k <= 21; k++){
			printf(" ");
		}
		printf("%d",structaux.dni);
		for(k = k; k <= 30; k++){
			printf(" ");
		}
		printf("%s",structaux.pais);
	}
}
