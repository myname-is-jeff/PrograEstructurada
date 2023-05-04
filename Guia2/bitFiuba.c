/*
 |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0|
 | xbs|mute| -- |    source    |  eqmode |

 hacer una funcion que obtenga el modo de eq, otra para cambiarlo por uno ingresado por teclado
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EQMASK 3

typedef enum{
	EQUIALIZATION_FLAT = 0,
	EQUIALIZATION_POP = 1,
	EQUIALIZATION_ROCK = 2,
	EQUIALIZATION_CLASSIC = 3
} equalization_t;

typedef unsigned int uint;

equalization_t get_eq_mode(uint registro);
void ch_eq_mode(uint * registro, equalization_t mode);

int main(void){
    uint registro;
    equalization_t mode;
    time_t t;

    srand((unsigned) time(&t));
    registro = (rand() % 255);

    mode = get_eq_mode(registro);
    printf("El modo actual es: %d\n", mode);
    printf("El registro actual es: %d\n", registro);
    printf("Ingrese un modo de eq: ");
    scanf("%d",&mode);
    ch_eq_mode(&registro, mode);
    mode = get_eq_mode(registro);
    printf("El modo actual es: %d\n", mode);
    printf("El registro actual es: %d\n", registro);

    return 0;
}

equalization_t get_eq_mode(uint registro){
    return (registro&EQMASK);
}

void ch_eq_mode(uint * registro, equalization_t mode){
    *registro = *registro >> 2;
    *registro = *registro << 2;
    *registro = *registro | mode;
}
