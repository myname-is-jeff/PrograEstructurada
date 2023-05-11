#include <stdio.h>

typedef struct{
	int a, b, c;
}t_tres;
void ordenar(int * a, int * b, int * c);
void ordenarV2(t_tres * t);

int main(void){
	t_tres g;
	
	g.a = 10; g.b = 4; g.c = 35;
	
	printf("A: %d\nB: %d\nC: %d\n",g.a,g.b,g.c);
	
	ordenar(&g.a,&g.b,&g.c);
	
	printf("------ORDENAR------\nA: %d\nB: %d\nC: %d\n",g.a,g.b,g.c);
	
	g.a = 10; g.b = 4; g.c = 35;
	
	printf("------DESORDENAR------\n");
	printf("A: %d\nB: %d\nC: %d\n",g.a,g.b,g.c);
	
	ordenarV2(&g);
	
	printf("------ORDENARV2------\nA: %d\nB: %d\nC: %d\n",g.a,g.b,g.c);
	
	return 0;
}

void ordenar(int * a, int * b, int * c){
	int i,j;
	
	for(i = 0; i < 3; i++){
		if(*a > *b){
			j = *a;
			*a = *b;
			*b = j;
		}
		if(*b > *c){
			j = *b;
			*b = *c;
			*c = j;
		}
	}
}

void ordenarV2(t_tres * t){
	int i,j;
	
	for(i = 0; i < 3; i++){
		if((*t).a > (*t).b){
			j = (*t).a;
			(*t).a = (*t).b;
			(*t).b = j;
		}
		if((*t).b > (*t).c){
			j = (*t).b;
			(*t).b = (*t).c;
			(*t).c = j;
		}
	}
}
