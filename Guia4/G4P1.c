#include <stdio.h>

int productoR(int a, int b);

int main(void){
	int a,b;
	a = 10; b = 15;
	printf("Multiplicador: %d, Multiplicando: %d\nResultado: %d\n",a,b,productoR(a,b));
	return 0;
}

int productoR(int a, int b){
	int res;
	res = 0;
	if(b != 0){
		res = a + productoR(a,b-1);
	}
	return res;
}
