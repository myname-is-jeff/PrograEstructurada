#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ILOGICO 123456

typedef struct{
	char eq[30];
	int pts;
	int pj;
	int pg;
	int pe;
	int pp;
	int gf;
	int gc;
	int dif;
}teamstats_t;

void cargarArrDeArch(teamstats_t arr[], char nombre_arch1[], char nombre_arch2[]);
void imprimirTabla(teamstats_t arr[], char nombre_arch3[]);
void csvNumParser(char str[], int aux[]);
int digitos(int num);

int main(void){
	teamstats_t arr[5];
	char nombre_arch3[] = "cabeceras.txt";
	char nombre_arch2[] = "items.txt";
	char nombre_arch1[] = "datos.txt";
	
	cargarArrDeArch(arr, nombre_arch1,nombre_arch2);
	imprimirTabla(arr,nombre_arch3);

	
	return 0;
}
void csvNumParser(char str[], int aux[]){
	int res,i,j,k;
	char token[10];
	char * temp;
	
	k = 0;
	for(i = 0; str[i] != '\n'; i++){
		j = 0;
		for(j = 0; str[i] != ',' && str[i] != '\n'; i++){
			token[j] = str[i];
			j++;
		}
		
		token[j] = '\0';
		res = strtol(token,&temp,10);
		if(*temp == '\0'){
			aux[k] = res;
			k++;		
		}
		if(str[i] == '\n'){
			i--;
		}
	}
	aux[k] = ILOGICO;
}
	
void cargarArrDeArch(teamstats_t arr[], char nombre_arch1[], char nombre_arch2[]){
	FILE *fd,*fi;
	char datos[100];
	char items[100];
	int aux [10];
	int i,j,f;
	
	fd = fopen(nombre_arch1,"r");
	fi = fopen(nombre_arch2,"r");
	
	if((fd == NULL) || (fi == NULL)){
		perror("Error opening a file");
		fclose(fd);
		fclose(fi);
	}
	else{
		for(i = 0; i < 5; i++){
			if((fgets(datos, 50, fd) != NULL) && ( fgets(items, 50, fi) != NULL)){
				
				csvNumParser(datos,aux);
				
				for(j = 0; aux[j] != ILOGICO;j++){
					arr[i].pts = aux[j];
					j++;
					arr[i].pj = aux[j];
					j++;
					arr[i].pg = aux[j];
					j++;
					arr[i].pe = aux[j];
					j++;
					arr[i].pp = aux[j];
					j++;
					arr[i].gf = aux[j];
					j++;
					arr[i].gc = aux[j];
					j++;
					arr[i].dif = aux[j];
					for(f = 0; items[f] != '\n'; f++);
					items[f] = '\0';
					strcpy(arr[i].eq,items);
					
				}
			}
		}
		fclose(fd);
		fclose(fi);
	}
}

void imprimirTabla(teamstats_t arr[], char nombre_arch3[]){
	int i,j,k,f;
	FILE *fc;
	char aux[100];
	char cabecera[10];
	teamstats_t structaux;
	
	fc = fopen(nombre_arch3,"r");
	
	
	if((fc == NULL)){
		perror("Error opening a file");
		fclose(fc);
	}
	else{
		for(i = 0; fgets(cabecera,50,fc) != NULL; i++){
			for(f = 0; cabecera[f] != '\n'; f++);
			cabecera[f] = '\0';
			if(i == 0){
				printf("%s         ",cabecera);
			}
			else{
				printf("%s    ",cabecera);
			}
		}
	}
	fclose(fc);
	printf("\n--------------------------------------------------------------");
	for(i = 0; i < 5; i++){
		printf("\n");
		structaux = arr[i];
		for(j = 0; structaux.eq[j] != '\0'; j++);
		j++;
		printf("%s",structaux.eq);
		for(k = j; k <= 15; k++){
			printf(" ");
		}
		for(k; k <= (18-digitos(structaux.pts)); k++){
			printf(" ");
		}
		printf("%d",structaux.pts);
		for(k; k <= (23-digitos(structaux.pj)); k++){
			printf(" ");
		}
		printf("%d",structaux.pj);
		for(k; k <= (28-digitos(structaux.pg)); k++){
			printf(" ");
		}
		printf("%d",structaux.pg);
		for(k; k <= (33-digitos(structaux.pe)); k++){
			printf(" ");
		}
		printf("%d",structaux.pe);
		for(k; k <= (38-digitos(structaux.pp)); k++){
			printf(" ");
		}
		printf("%d",structaux.pp);
		for(k; k <= (43-digitos(structaux.gf)); k++){
			printf(" ");
		}
		printf("%d",structaux.gf);
		for(k; k <= (48-digitos(structaux.gc)); k++){
			printf(" ");
		}
		printf("%d",structaux.gc);
		for(k; k <= (53-digitos(structaux.dif)); k++){
			printf(" ");
		}
		printf("%d",structaux.dif);
		
		
	}
}

int digitos(int num){
	int res;
	
	if(num == 0){
		res = 1;
	}
	else{
		res = floor(log10(abs(num))) + 1;
		if(num < 0){
			res++;
		}
	}
	
	return res;
}
