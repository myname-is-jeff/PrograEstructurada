#include <stdio.h>

int * maxRP(int * arr);
int * minRP(int * arr);
void ordenarAC(int * arr);
void arrPrint(int * arr);
void ordenarDC(int * arr);

int main(void){
	int arr[] = {13,25,3,4,5,10,7,8,9,1,0};
	
	arrPrint(arr);
	ordenarDC(arr);
	arrPrint(arr);
    ordenarAC(arr);
    arrPrint(arr);
	
	return 0;
}
	
int * maxRP(int * arr){
	int * resB = NULL;
	int * res = NULL;
	if(*arr != 0){
		resB = maxRP(arr+1);
		if(resB != NULL){
			if(*arr > *resB){
				res = arr;
			}
			else{
				res = resB;
			}
		}
		else{
			res = arr;
		}
		
	}
	return res;
}

int * minRP(int * arr){
    int * res = NULL;
    int * aux = NULL;
    
    if(*arr != 0){
        aux = minRP(arr+1);
        if(aux != NULL){
            if(*arr>*aux){
                res = aux;
            }
            else{
                res = arr;
            }
        }
        else{
            res = arr;
        }
    }
    return res;
}
void ordenarAC(int * arr){
    int aux;
    int * min;
    min = minRP(arr);
    aux = *arr;
    *arr = *min;
    *min = aux;
    
    if((*arr != 0) && (*(arr+1) != 0)){
        ordenarAC(arr+1);
    }
}

void ordenarDC(int * arr){
	int aux;
    int * max;

    max = maxRP(arr);
    aux = *arr;
    *arr = *max;
    *max = aux;
    if((*arr != 0) && (*(arr+1) != 0)){
        ordenarDC(arr+1);
    }
}
	
void arrPrint(int * arr){
	printf("ARR: ");
	while(*arr != 0){
		printf("%d",*arr);
		if(*(arr+1) != 0){
			printf(",");
		}
		arr++;
	}
	printf("\n");
}
