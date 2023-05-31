#include <stdio.h>

struct num_s{
	int num;
	struct s_num * next;
};

typedef struct num_s num_t;

void recursivePrint(struct num_s * p);

int main(void){
	num_t a,b,c,d,e;
	a.num = 2;b.num = 5;c.num = 7;d.num = 1;e.num = 9;
	a.next = &b;b.next = &c;c.next = &d;d.next = &e;
	e.next = NULL;
	recursivePrint(a);
	return 0;
}

void recursivePrint(struct num_s * p){
	if(p->next != NULL){
		recursivePrint((p->next));
	}
	printf("%d,",(p->num));
}
