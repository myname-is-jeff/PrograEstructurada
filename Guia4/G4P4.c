#include <stdio.h>

void invertir(int * arr, unsigned int len);
void arrPrint(int * arr, int len);

int main(void){
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	
	arrPrint(arr,10);
	invertir(arr,10);
	arrPrint(arr,10);
	
	return 0;
}

void invertir(int * arr, unsigned int len){
	int aux;
	if(len >= 1){
		aux = *arr;
		*arr = *(arr+len-1);
		*(arr+len-1) = aux;
		invertir(arr + 1, len - 2);
	}
}
	
void arrPrint(int * arr, int len){
	int i;
	printf("ARR: ");
	for(i = 0; i < len; i++){
		printf("%d,",arr[i]);
	}
	printf("\n");
}
