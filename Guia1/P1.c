/* Desarrollar una funci�n que solicite al usuario el ingreso de un n�mero real y luego
muestre el Redondeo al entero m�s pr�ximo de dicho n�mero, el Piso y el Techo.
Definiciones:
? Redondeo: Si la parte decimal es mayor o igual a 0,5, se redondea hacia arriba.
Caso contrario, se redondea hacia abajo.
? Piso: El entero m�s pr�ximo hacia abajo.
? Techo: El entero m�s pr�ximo hacia arriba.

Desarrollar el programa principal que solicite el ingresos de un n�mero y luego llama a la
funci�n (una por cada uno de los conceptos a mostrar) pas�ndole el par�metro
correspondiente. El resultado ser� devuelto por la funci�n y mostrado por terminal desde
el programa principal.*/
#include <stdio.h>
#include <stdlib.h>

int techo(float num){
	int x;
	x = x + num;
	return x++;
}
int piso(float num){
	int x;
	x = x + num;
	return x;	
}
int redondeo(float num){
	int x;
	x = x + num;
	num = num - x;
	if (num >= 0.5){
		x = techo(num + x);
	}
	return x;
}

int main(void){
	int redon;
	float num;
	int t;
	int p;
	char c;
	
	printf("%s\n","Ingrese un numero racional");
	scanf("%d\n",num);
	while((c = getchar()) != '\n' && c != EOF);
	redon = redondeo(num);
	t = techo(num);
	p = piso(num);
	printf("%s%d\n", "El techo es: ",t);
	printf("%s%d\n", "El piso es: ",p);
	printf("%s%d\n", "El numero redondeado es: ",redon);
	return 0;
}
