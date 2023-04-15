/*
 Crear una estructura que permita guardar información sobre un punto en el plano
(utilizando sus coordenadas en los ejes x e y). Luego realizar un programa que solicite al
usuario que se ingresen los datos de dos puntos e indique cuál de los dos puntos se
encuentra más lejos del origen de coordenadas (0;0)
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_punto{
    int x;
    int y;
    double norma;
    char nombre;
}t_pos;

double norm(int x, int y);

int main(void){
    t_pos A,B;
    
    A.nombre = 'A';
    A.x = 3;
    A.y = 5;
    A.norma = norm(A.x,A.y);

    B.nombre = 'B';
    B.x = 6;
    B.y = 2;
    B.norma = norm(B.x,B.y);
    
    if (A.norma > B.norma){
        printf("A mas lejos");
    }
    else{
        printf("B mas lejos");
    }

    return 0;
}

double norm(int x , int y){
    return(sqrt(pow(x,2) + pow(y,2)));
}
