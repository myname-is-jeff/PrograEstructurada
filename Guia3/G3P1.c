#include <stdio.h>

void intercambio(int * x, int * y);

int main(void){
    int x,y;
    
    x = 5;
    y = 2;

    printf("Valores: (%d,%d)\n",x,y);
    intercambio(&x,&y);
    printf("Valores: (%d,%d)\n",x,y);
    
    return 0;
}

void intercambio(int * x, int * y){
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}
