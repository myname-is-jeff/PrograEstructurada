#include <stdio.h>

struct num_s{
	int num;
	struct num_s * next;
};

typedef struct num_s * num_t;

/* si yo le paso la lista, y agrego un elemento en el comienzo de la misma, como puedo ubicar a ese elemnto?
esta bien que haya puesto que oAdd devuealva un puntero al primer elemento?
*/

void append(num_t lst, int val);
void add(num_t lst, int val);
void pAdd(num_t lst, int val, int pos);
num_t oAdd(num_t lst, int val);
void printLst(num_t lst);

int main(void){
	struct num_s a,b,c,d,e;
	num_t init;
	a.num = 2;b.num = 4;c.num = 3;d.num = 8;e.num = 10;
	a.next = &b;b.next = &c;c.next = &d;d.next = &e;e.next = NULL;
	init = oAdd();
	return 0;
}

num_t oAdd(num_t * lst, int val){
	num_t aux;
	if(lst != NULL){
		if((aux = (num_t)malloc(sizeof(struct num_s))) == NULL){
			printf("MALLOC ERROR\n");
		}
		else{
			if((lst->num) < val){
				
			}
		}

	}
}

void printLst(num_t lst){
	if(lst != NULL){
		printf("\n Valor=%4d, Dir. Nodo:<%p>, dirSig:<%p>",lst->num,lst,lst->next);
		printLst(lst->next);
	}
}
