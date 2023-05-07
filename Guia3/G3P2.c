#include <stdio.h>
#include <stdlib.h>

int memPos(int * arr, int i);

int main(void){
    int arr[5] = {1,2,3,4,5};
    int i;
    i = 3;
    printf("Posicion: %x\n",memPos(arr,i));
    return 0;

}

int memPos(int * arr, int i){
    return arr[i];
}
