#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 5
#define MAX 21
typedef enum{
	FALSE,
	TRUE
}bool_t;

struct s_contador{
    int num;
	int veces;
};

typedef struct s_contador t_cont;

void cargarArrRand(t_cont arr[]);
int cmpfunc(const void * a, const void * b);
void grafBarras(t_cont arr[]);

int main(void){
    t_cont arr[MAX];
	
	
	arr[0].num = 1;
	arr[0].veces = 4;
	arr[1].num = 2;
	arr[1].veces = 2;
	arr[2].num = 3;
	arr[2].veces = 6;
	arr[3].num = 4;
	arr[3].veces = 1;
	
	/*cargarArrRand(arr);*/
	grafBarras(arr);


    return 0;
}

void cargarArrRand(t_cont arr[]){
	int aux,i;
	bool_t ban, isarr;
	clock_t begin;
	
	begin = clock();
	ban = TRUE;
	
	while(ban == TRUE){
		aux = rand() % 20;
		printf("%d\n",aux);
		isarr = FALSE;
		
		for(i = 0; i < MAX && isarr == FALSE; i++){
			if(arr[i].num == aux){
				arr[i].veces += 1;
				printf("%d\n",arr[i].num);
				isarr = TRUE;
			}
		}
		if(isarr == FALSE){
			for(i = 0; arr[i].num != '\0'; i++);
			arr[i].num = aux;
			arr[i].veces += 1;
		}
		if(((int)(clock()-begin)/CLOCKS_PER_SEC) > T){
			ban == FALSE;
		}
		
	}
}
	
int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);	
}

void grafBarras(t_cont arr[]){
	int i,j,c;
	printf("\nCantidad de Apariciones de un INT\n");
	for (i = 0; i < 4; i++){
		c = arr[i].veces;
		printf("%d |", arr[i].num);
		
		for (j = 0; j < c; j++)
		{
			printf("%c", (char)254u);
		}
		printf("\n");
	}
}




