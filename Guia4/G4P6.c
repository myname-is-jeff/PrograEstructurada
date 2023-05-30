#include <stdio.h>

int * maxRP(int * arr);
void ordenar(int * arr);
void arrPrint(int * arr);

int main(void){
	int arr[] = {13,25,3,4,5,10,7,8,9,1,0};
	
	arrPrint(arr);
	ordenar(arr);
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

void ordenar(int * arr){
	int aux;
	if((*arr != 0) && (*(arr+1) != 0)){
		if(*arr > *(arr+1)){
			aux = *arr;
			*arr = *(arr+1);
			*(arr+1)= aux;
		}
		ordenar(arr+1);
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
