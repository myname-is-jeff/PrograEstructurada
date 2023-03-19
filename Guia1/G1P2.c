/* 
Desarrollar la funci�n operacion que reciba por par�metro dos n�meros enteros y un
car�cter: [ + , - , * , / ] el cual determinar� una operaci�n matem�tica. La funci�n
deber� imprimir el resultado de realizar con los n�meros pasados por par�metros la
operaci�n correspondiente tambi�n pasada por par�metro. Por cada operaci�n a realizar
dentro de la funci�n operacion se deber� invocar a la funci�n [suma, resta,
producto, division] (seg�n corresponda), donde se le pasar� por par�metro (los
operandos), y cada funci�n deber� retornar el resultado de la operaci�n.

Desarrollar el programa principal que solicite el ingresos de dos n�meros y un car�cter
que indica la operaci�n, luego llamar a operacion, pas�ndole los par�metros, para que
imprima el resultado.*/

//libs
#include <stdlib.h>
#include <stdio.h>

//proto

int suma(int a, int b){
	return (a + b);
}

int resta(int a, int b){
	return (a - b);
}

int producto(int a, int b){
	return (a * b);
}

float divi(int a, int b){
	float rs;
	
	if (b != 0){
		rs = a/b;
	}
	else{
		rs = 0;
	}
	return rs;
}
void operacion(int a, int b, char op){

	switch (op){
		case '+':
			printf("%d %c %d = %d\n",a,op,b,suma(a,b));
			break;
		case '-':
			printf("%d %c %d = %d\n",a,op,b,resta(a,b));
			break;
		case '*':
			printf("%d %c %d = %d\n",a,op,b,producto(a,b));
			break;
		case '/':
			printf("%d %c %d = %lf\n",a,op,b,divi(a,b));
			break;
		default:
			printf("%s\n","No se reconoce la operacion");
	}

}
int main (void){
	int a;
	int b;
	char op;
	char c;
	
	printf("%s","Ingrese primer numero:");
	scanf("%d",&a);
	while((c = getchar()) != '\n' && c != EOF);//limpio el buffer
	printf("%s","Ingrese segundo numero:");
	scanf("%d",&b);
	while((c = getchar()) != '\n' && c != EOF);
	printf("%s","Ingrese una operacion:");
	scanf("%c",&op);
	
	operacion(a,b,op);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
