#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  N 5

typedef enum{
	NOMBRE,
	DNI,
	PAIS,
	EXIT
}option_t;

typedef struct{
	int dni;
	char nombre[50];
	char pais[50];
}person_t;

void cargarArrDeArch(person_t arr[], char nombre_arch[]);
void imprimirTabla(person_t arr[]);
option_t menu();
void ordenarArr(person_t arr[], option_t op);

int main(void){
	person_t arr[N];
	char nombre_arch[] = "personas.txt";
	
	cargarArrDeArch(arr,nombre_arch);
	ordenarArr(arr,menu());
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
		printf("%-20s",structaux.nombre);
		printf("%-18d",structaux.dni);
		printf("%s",structaux.pais);
	}
}

option_t menu(){
	option_t op;
	printf("1- Ver listado ordenado por nombre\n2- Ver listado ordenado por documento\n3- Ver listado ordenado por país\n4- Salir del programa\n");
	printf("Opcion (1-4): ");
	scanf("%d",&op);
	op--;
	return op;
}

void ordenarArr(person_t arr[], option_t op){
	person_t auxA,auxB;
	int i;
	int j;
	switch (op){
		case NOMBRE:
			for (i = 0; i < N - 1; i++) {
				for (j = i + 1; j < N; j++) {
					auxA = arr[i];
					auxB = arr[j];
					if (auxA.nombre[0] > auxB.nombre[0]) {
						arr[i] = auxB;
						arr[j] = auxA;
					}
				}
			}
			break;
		case DNI:
			for (i = 0; i < N - 1; i++) {
				for (j = i + 1; j < N; j++) {
					auxA = arr[i];
					auxB = arr[j];
					if (auxA.dni > auxB.dni) {
						arr[i] = auxB;
						arr[j] = auxA;
					}
				}
			}
			break;
		case PAIS:
			for (i = 0; i < N - 1; i++) {
				for (j = i + 1; j < N; j++) {
					auxA = arr[i];
					auxB = arr[j];
					if (auxA.pais[0] > auxB.pais[0]) {
						arr[i] = auxB;
						arr[j] = auxA;
					}
				}
			}
			break;
		case EXIT:
			exit(0);
	}
}

