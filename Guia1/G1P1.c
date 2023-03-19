/* Desarrollar una función que solicite al usuario el ingreso de un número real y luego
muestre el Redondeo al entero más próximo de dicho número, el Piso y el Techo.
Definiciones:
? Redondeo: Si la parte decimal es mayor o igual a 0,5, se redondea hacia arriba.
Caso contrario, se redondea hacia abajo.
? Piso: El entero más próximo hacia abajo.
? Techo: El entero más próximo hacia arriba.

Desarrollar el programa principal que solicite el ingresos de un número y luego llama a la
función (una por cada uno de los conceptos a mostrar) pasándole el parámetro
correspondiente. El resultado será devuelto por la función y mostrado por terminal desde
el programa principal.*/
#include <stdio.h>
#include <stdlib.h>

int techo(double num){
	int i;
	
	for (i = 0; num > 1; i++){
		num -= 1.0;
	}
	i++;
	return i;
}
int piso(float num){
	int x;
	
	x=0;
	x = x + num;
	return x;	
}
int redondeo(float num){
	int x;
	float dec;
	
	x = num;
	dec = num - x;
	if (dec >= 0.5){
		x++;
	}
	return x;
}

int main(void){
	int redon;
	double num;
	int t;
	int p;
	
	printf("%s\n","Ingrese un numero racional");
	scanf("%lf",&num);
	
	t = techo(num);
	redon = redondeo(num);
	p = piso(num);
	
	printf("%s%d\n", "El techo es: ",t);
	printf("%s%d\n", "El piso es: ",p);
	printf("%s%d\n", "El numero redondeado es: ",redon);
	
	return 0;
}
