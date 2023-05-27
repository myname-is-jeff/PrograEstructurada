#include <stdio.h>
#include <math.h>

int cocienteR(int a, int b);

int main(void){
	int a,b;
	a = 10; b = 0;
	printf("Dividendo: %d, Divisor: %d\nCociente: %d\n",a,b,cocienteR(a,b));
	return 0;
}
	
int cocienteR(int a, int b){
	int res,sign;
	
	sign = 1;
	res = 0;
	
	if((a < 0) ^ (b < 0)){
		sign = (-1);
		a = fabs(a);
		b = fabs(b);
	}
	else if((a < 0) && (b < 0)){
		a = fabs(a);
		b = fabs(b);
	}
	
	if((a >= b) && (a != 0)){
		res = 1 + cocienteR(a-b,b);
	}

	return (res*sign);
}
