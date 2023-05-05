#include <stdio.h>

void redondeo(double * num);

int main(void){
    double num = 123.645;
   
    printf("NUM: %f\n",num);
    
    redondeo(&num);
    
    printf("NUM: %f\n",num);

    return 0;
}

void redondeo(double * num){
    double resto;
    int entero;
    entero = (int) (*num);
    resto = *num - entero;
    if(resto > 0.5){
        *num -= resto;
        *num += 1;
    }
    else{
        *num -= resto;
    }
}

