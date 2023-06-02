#include <stdio.h>

struct num_s{
	int num;
	struct num_s * next;
};

typedef struct num_s * num_t;

void inverseLst(num_t lstB,num_t lst);
void printLst(num_t lst);
void inversePrintLst(num_t lst);

int main(void){
	struct num_s a,b,c,d,e;
	a.num = 2;b.num = 4;c.num = 3;d.num = 8;e.num = 10;
	a.next = &b;b.next = &c;c.next = &d;d.next = &e;e.next = NULL;
	printf("---- PRINT ----\n");
	printf("BEFORE\n");
	printLst(&a);
	printf("\nAFTER\n");
	inversePrintLst(&a);
	printf("\n---- INVERSE ----\n");
	printf("\nBEFORE\n");
	printLst(&a);
	inverseLst(&a,NULL);
	printf("\nAFTER\n");
	printLst(&e);
	
	return 0;
}
	
void printLst(num_t lst){
	if(lst != NULL){
		printf("\n Valor=%4d, Dir. Nodo:<%p>, dirSig:<%p>",lst->num,lst,lst->next);
		printLst(lst->next);
	}
}

void inversePrintLst(num_t lst){
	if(lst != NULL){
		inversePrintLst(lst->next);
		printf("\n Valor=%4d, Dir. Nodo:<%p>, dirSig:<%p>",lst->num,lst,lst->next);
	}
}

void inverseLst(num_t lstB,num_t lst){
	num_t aux;
	if(lstB != NULL){
		aux = lstB->next;
		lstB->next = lst;
		inverseLst(aux,lstB);
	}
}

