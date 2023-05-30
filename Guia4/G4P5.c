#include <stdio.h>

int maxR(int * arr);
int * maxRP(int * arr);

int main(void){
	int arr[] = {1,25,3,4,5,10,7,8,9,1,0};
	printf("Max elemento: %d\n",maxR(arr));
	printf("Direccion Max elemento: %p\n",maxRP(arr));
	
	return 0;
}

int maxR(int * arr){
	int resA = 0;
	int resB = 0;
	int res = 0;
	if(*arr != 0){
		resA = *arr;
		resB = maxR(arr+1);
		if(resA > resB){
			res = resA;
		}
		else{
			res = resB;
		}
	}
	return res;
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
