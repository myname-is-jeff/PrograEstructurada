#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct num_s{
	int num;
	struct num_s * next;
};

typedef struct num_s * num_t;

void append(num_t lst, int val);
void add(num_t lst, int val);
void pAdd(num_t lst, int val, int pos);
num_t oAdd(num_t lst, int val);
void printLst(num_t lst);
void loadLst(num_t * lst,char * fn);

int main(void){
	num_t init;
	loadLst(&init,"ListNum.txt");
	printf("%-20s%-20s%-20s\n","Valor","Dir Nodo","Dir Next");
	printf("%060d\n",0);
	printLst(init->next);
	oAdd(init->next,2);
	printf("\n%-20s%-20s%-20s\n","Valor","Dir Nodo","Dir Next");
	printf("%060d",0);
	printLst(init->next);
	add(init,0);
	printf("\n%-20s%-20s%-20s\n","Valor","Dir Nodo","Dir Next");
	printf("%060d",0);
	printLst(init->next);
    pAdd(init->next, 4, 11);
    printLst(init->next);
	
	return 0;
}

void loadLst(num_t * lst,char * fn){
	FILE * fp;
	char c[50], *p;
	int aux;
	if((fp = fopen(fn,"r")) == NULL){
		printf("ERROR OPENING FILE LOADLST\n");
	}
	else{
		if(((*lst) = (num_t)malloc(sizeof(struct num_s))) == NULL){
			printf("ERROR INIT MEMORY LOADLST\n");
		}
		else{
			(*lst)->next = NULL;
			while((fgets(c,50,fp)) != NULL){
					if((p = strchr(c,'\n')) != NULL)
						*p = '\0';
					aux = atoi(c);
					append(*lst,aux);
			}	
		}
		
	}
	fclose(fp);
}

num_t oAdd(num_t lst, int val){
	num_t res,aux;
	res = NULL;
	aux = NULL;
	if(lst != NULL){
		if((lst->num) > val){
			if((res = (num_t)malloc(sizeof(struct num_s))) == NULL){
				printf("MALLOC ERROR\n");
			}
			else{
				res->num = val;
				res->next = lst;
			}
		}
		else{
			aux = oAdd(lst->next,val);
			if(aux != NULL){
				lst->next = aux;
			}
		}
	}
	return res;
}

void append(num_t lst, int val){
	num_t aux;
	
	if(lst != NULL){
		if((lst->next) == NULL){
			if((aux = (num_t)malloc(sizeof(struct num_s))) == NULL){
				printf("ERROR INIT NEW NODE MEMORY APPEND\n");
			}
			else{
				aux->num = val;
				aux->next = NULL;
				lst->next = aux;
			}
		}
		else{
			append(lst->next,val);
		}
	}
}

void add(num_t lst, int val){
	num_t aux = NULL;
	if((aux = (num_t)malloc(sizeof(struct num_s))) == NULL){
		printf("ERROR INIT NEW NODE MEMORY ADD\n");
	}
	else{
		aux->num = val;
		aux->next = lst->next;
		lst->next = aux;
	}
}

void pAdd(num_t lst, int val, int pos){
    num_t aux = NULL;

    if(lst != NULL){
        if(pos == 0){
            if((aux = (num_t)malloc(sizeof(struct num_s))) == NULL){
                printf("ERROR MEMORY ALLOC PADD\n");
            }
            else{
                aux->num = val;
                aux->next = lst->next;
                lst->next = aux;
            }

        }
        else{
            pAdd(lst->next,val,pos-1);
        }
    }
    else{
        printf("O te fuiste de cota o hubo un error\n");
    }
}

void printLst(num_t lst){
	if(lst != NULL){
		printf("\n%-20d%-20p%-20p",lst->num,lst,lst->next);
		printLst(lst->next);
	}
}
