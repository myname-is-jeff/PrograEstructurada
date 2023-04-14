#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 0.0001
#define MAX 21

typedef enum{
	FALSE,
	TRUE
}bool_t;

typedef struct s_contador{
    int num;
	int veces;
}t_cont;


void cargarArrRand(t_cont arr[]);
void grafBarras(t_cont arr[]);
void ordenarArr(t_cont arr[]);

int main(void){
    t_cont arr[MAX];
    int i;

    for(i = 0; i < 21; i++){
        arr[i].num = i;
        arr[i].veces = 0;
    }

    cargarArrRand(arr);
   /* ordenarArr(arr); */
	grafBarras(arr);


    return 0;
}

void cargarArrRand(t_cont arr[]){
	int aux,i,j;
	bool_t ban, isarr;
	clock_t begin;
	
	begin = clock();
	ban = TRUE;
    j = 0;
	
	while(ban == TRUE){
        j++;
		aux = rand() % 20;
	    printf("%d-",aux);
        isarr = FALSE;
		for(i = 0; i < MAX && isarr == FALSE; i++){
			if(arr[i].num == aux){
				arr[i].veces += 1;
                isarr = TRUE;
			}
		}
		if(((double)(clock()-begin)/CLOCKS_PER_SEC) > T){
			ban = FALSE;
		}
		
	}
    printf("GENERO: %d\n", j);
}
	
void grafBarras(t_cont arr[]){
	int i,j,c;
	printf("\nCantidad de Apariciones de un INT\n");
	for (i = 0; i < 21; i++){
		c = arr[i].veces;
		printf("%d |", arr[i].num);
		
		for (j = 0; j < c; j++)
		{
			printf("");
		}
		printf("\n");
	}
}

void ordenarArr(t_cont arr[]){
    t_cont aux;
    int i, j,len;
    
    printf("\n----ANTES ----\n");
    printf("numero - veces\n");
    for(i = 0; i < MAX; i++){
        printf("%d - %d\n", arr[i].num,arr[i].veces);
    }
    printf("\n");

    len = MAX;

    for(i = 0;i < len-1; i++){
        for(j = i + 1; j < len; j++){
            if(arr[i].num > arr[j].num){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    printf("\n---- DESPUES ----\n");
    printf("numero - veces\n");
    for(i = 0; i < len; i++){
        printf("%d - %d\n", arr[i].num,arr[i].veces);
    }
    printf("\n");

}


