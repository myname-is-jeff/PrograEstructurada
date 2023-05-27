#include <stdio.h>
#include <math.h>

int restoR(int a, int b);

int main(void){
	int a,b;
	a = 10; b = -3;
	printf("Dividendo: %d, Divisor: %d\nResto: %d\n",a,b,restoR(a,b));
	return 0;
}
	
int restoR(int a, int b){
	int res,sign;
	
	sign = 1;
	res = a;
	
	if((a < 0) || (b < 0)){
		if((a < 0) ^ (b < 0)){
			sign = (-1);
		}
		a = fabs(a);
		b = fabs(b);
	}
	
	if((a >= b) && (a != 0)){
		res = restoR(a-b,b);
	}
	
	return (res*sign);
}
