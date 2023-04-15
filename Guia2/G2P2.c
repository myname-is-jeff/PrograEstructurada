#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_POINTS 10

typedef struct s_punto{
	int x;
	int y;
}t_pos;

typedef enum{
	FALSE,
	TRUE
}bool_t;

double distancia(t_pos A, t_pos B);
void cargarArrPunto(t_pos arr[]);
void csvNumParser(t_pos arr[], char str[]);
double minConsDistance(t_pos arr[]);
double minDistance(t_pos arr[]);
void printStruct(t_pos arr[]);
bool_t esPar(int x);

int main(void){
	t_pos arr[MAX_POINTS];
	
	cargarArrPunto(arr);
	printf("La mínima distancia entre dos puntos consecutivos es: %lf\n",minConsDistance(arr));
	printf("La mínima distancia entre dos puntos cualesquiera es: %lf\n",minDistance(arr));
	
	return 0;
}
	


void cargarArrPunto(t_pos arr[]){
	FILE *fp;
	char str[100];
	
	fp = fopen("puntos.csv","r");
	if(fp == NULL){
		perror("Error opening file");
		fclose(fp);
	}
	else{
		if(fgets(str, 100, fp) != NULL){
			csvNumParser(arr,str);
		}
	}
}


double distancia(t_pos A, t_pos B){
	int x,y;
	
	x = A.x - B.x;
	y = A.y - B.y;
	
	return(sqrt(pow(x,2) + pow(y,2)));
}

void csvNumParser(t_pos arr[],char str[]){
	int res,i,j,k,z;
	char token[10];
	char * temp;
	t_pos aux;
	bool_t ban;
	
	z = 1;
	k = 0;

	for(i = 0; str[i] != '\n'; i++){
		j = 0;
		ban = FALSE;
		for(j = 0; str[i] != ',' && str[i] != '\n'; i++){
			token[j] = str[i];
			j++;
		}
		token[j] = '\0';
		
		res = strtol(token,&temp,10);

		if(*temp == '\0'){
			if(esPar(z) == FALSE){
				aux.x = res;
			}
			else{
				aux.y = res;
				ban = TRUE;
			}
		}
		if(ban == TRUE){
			arr[k] = aux;
			k++;		
		}
		if(str[i] == '\n'){
			i--;
		}
		z++;
	}
	printStruct(arr);
}

double minConsDistance(t_pos arr[]){
	int i;
	double min,aux;
	
	min = 123456;
	
	for(i = 0; i < MAX_POINTS; i++){
		aux = distancia(arr[i], arr[i + 1]);
		if(aux < min){
			min = aux;
		}
	}
	return min;
}

double minDistance(t_pos arr[]){
	int i;
	double min,aux;
	
	min = 123456;
	
	for(i = 0; i < MAX_POINTS; i++){
		aux = distancia(arr[i], arr[i + 1]);
			if(aux < min){
			min = aux;
		}
	}
	return min;
}


bool_t esPar(int x){
	bool_t res;
	
	if(x % 2 == 0){
		res = TRUE;
	}
	else{
		res = FALSE;
	}
	return res;
}
	
void printStruct(t_pos arr[]){
	int i;
	i = 0;
	for(i = 0; i < MAX_POINTS; i++){
		printf("punto: %d x: %d -- y: %d\n",i,arr[i].x,arr[i].y);
	}
}
