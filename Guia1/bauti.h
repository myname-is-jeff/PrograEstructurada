#include <stdio.h>
#include <stdlib.h>

typedef enum {
	FALSE,
		TRUE
} bool_t;


void limpieza(void){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

void imprimirArr(int arr[]){
	int i;
	
	i = 0;
	
	while(arr[i] != '\0'){
		printf(" ___");
		i++;
	}
	i = 0;
	printf("\n| ");
	while(arr[i] != '\0'){
		printf("%d %s",arr[i],"| ");
		i++;
	}
	i = 0;
	printf("\n");
	while(arr[i] != '\0'){
		printf(" ---");
		i++;
	}
}


bool_t esPos(int aux){
	bool_t res;
	if (aux > 0){
		res = TRUE;
	}
	else {
		res = FALSE;
	}
	return res;
}	

void cargarArrAle(int arr[], int len){
	int i;
	for(i = 0;i < len; i++){
		arr[i] = (rand() % 100);
	}
}
