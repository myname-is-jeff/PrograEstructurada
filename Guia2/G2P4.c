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


void cargarArch(void);

int main(void){
	
	cargarArch();
	
	return 0;
}
	
void cargarArch(void){
	FILE *fp;
	int i,j,num,f;
	bool_t ban;
	person_t arr[N],aux;
	char c;
	
	ban = FALSE;
	if((fp = fopen("personas.txt","w")) == NULL){
		perror("ERROR OPENING FILE");
		fclose(fp);
	}
	else{
		for(i = 0; (i < N) && (ban == FALSE); i++){
			printf("Ingrese DNI: ");
			scanf("%d", &num);
			
			if(num != 0){
				aux.dni = num;
				printf("Ingrese NOMBRE: ");
				while(((c = getchar()) != '\n') && (c != EOF));
				if(fgets(aux.nombre,50,stdin) != NULL){
					printf("NAME CHECK: %s\n",aux.nombre);
					for(f = 0; aux.nombre[f] != '\n'; f++);
					aux.nombre[f] = '\0';
				}
				while(((c = getchar()) != '\n') && (c != EOF));
				printf("Ingrese PAIS: ");
				scanf("%s", aux.pais);
				printf("DNI CHECK: %d\n",aux.dni);
				printf("NAME CHECK: %s\n",aux.nombre);
				printf("FLAG CHECK: %s\n",aux.pais);
				arr[i].dni = aux.dni;
				strcpy(arr[i].nombre,aux.nombre);
				strcpy(arr[i].pais,aux.pais);
			}
			else{
				ban = TRUE;
			}
			
		}
		for(j = 0; (j < i-1); j++){
			printf("ARR DNI CHECK: %d\n",arr[j].dni);
			printf("ARR NAME CHECK: %s\n",arr[j].nombre);
			printf("ARR FLAG CHECK: %s\n",arr[j].pais);
			fprintf(fp,"%d,",arr[j].dni);
			fprintf(fp,"%s,",arr[j].nombre);
			fprintf(fp,"%s\n",arr[j].pais);
		}
		
	}
	
	fclose(fp);
	
	
	
}
