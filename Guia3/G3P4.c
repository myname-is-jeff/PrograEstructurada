/*dada la estructura:
struct s_carta
{
int numero, valor;
char palo;
}
typedef struct s_carta t_carta;
Desarrollar una funcion que modifique el contenido de 3 variables externas de este tipo,
de manera que las cartas almacenadas en estas queden ordenadas segun su valor en el
juego del Trucoù.*/

#include <stdio.h>

typedef struct{
    int numero, valor;
    char palo;
} card_t;

void ordenar(card_t * a, card_t * b, card_t * c);

int main(void){
    card_t a,b,c;
    a.palo = 'b'; a.numero = 1; a.valor = 2;
    b.palo = 'c'; b.numero = 7; b.valor = 10;
    c.palo = 'e'; c.numero = 3; c.valor = 5;

    printf("ORDEN: a: %d; b: %d; c: %d\n",a.valor,b.valor,c.valor);
    ordenar(&a,&b,&c);
    printf("ORDEN: a: %d; b: %d; c: %d\n",a.valor,b.valor,c.valor);

    return 0;
}


void ordenar(card_t * a, card_t * b, card_t * c){
    card_t aux;
    int i;

    for(i = 0; i < 4; i++){
		if((*a).valor > (*b).valor){
			aux = *a;
			*a = *b;
			*b = aux;
		}
		if((*b).valor > (*c).valor){
			aux = *b;
			*b = *c;
			*c = aux;
		}
	}
}
