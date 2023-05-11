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


