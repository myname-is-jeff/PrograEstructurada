/* 
Desarrollar la función operacion que reciba por parámetro dos números enteros y un
carácter: [ + , - , * , / ] el cual determinará una operación matemática. La función
deberá imprimir el resultado de realizar con los números pasados por parámetros la
operación correspondiente también pasada por parámetro. Por cada operación a realizar
dentro de la función operacion se deberá invocar a la función [suma, resta,
producto, division] (según corresponda), donde se le pasará por parámetro (los
operandos), y cada función deberá retornar el resultado de la operación.

Desarrollar el programa principal que solicite el ingresos de dos números y un carácter
que indica la operación, luego llamar a operacion, pasándole los parámetros, para que
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
