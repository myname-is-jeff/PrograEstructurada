#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 200

typedef struct{
    char *nom,*cod,*p; 
}cabecera_t;

typedef struct{
    char * prod;
    int cod;
    float precio;
}contenido_t;

struct node_s{
    contenido_t producto;
    struct node_s * next;
};

typedef struct node_s * node_t;

typedef enum{
    CODE,
    PRICE,
    PRODUCT
}filter_t;

typedef enum{
    TRUE,
    FALSE
}bool_t;

void lstPrint(node_t * lst);//
void csvParser(char * str, contenido_t * cont);//
void oAdd(node_t * lst, contenido_t * aux);//
void cargarArch(const char * nomArch, node_t * lst, cabecera_t * cabecera);//
void cabeceraParser(char * str, cabecera_t * cab);//
void nodeDel(node_t * lst,  contenido_t * dNode, filter_t op);//
bool_t condition(contenido_t nodeA, contenido_t nodeB, filter_t op);//
bool_t conDel(node_t * nodeA, contenido_t * nodeB, filter_t op);//
void ranDel(int start, int stop, node_t * lst, filter_t op);
void ordenar(node_t lst, filter_t op);
void lstDel(node_t * lst);
void push(node_t * lst, contenido_t * node); /*append al principio de la lista*/
void pop(node_t * lst);/*borra el primer elemento de la lista*/
int conRan(int start, int stop);
void eOrd(node_t lst, node_t node, filter_t op);


int main(void){
    node_t lst = NULL;
    cabecera_t cab;
    char nomArch[] = "datos.txt";
    contenido_t del;
	
	del.precio = 4.7;
	del.prod = "Lapiz HB";
	del.cod = 1848;
	
    cargarArch(nomArch,&lst,&cab);
    lstPrint(&lst);
	printf("CARGAR ARCH----------------------------------------------------\n\n");
	
    nodeDel(&lst, &del, CODE);
    lstPrint(&lst);
	printf("NODE DEL-------------------------------------------------------\n\n");
	
	push(&lst, &del);
	lstPrint(&lst);
	printf("PUSH-----------------------------------------------------------\n\n");
	
	ordenar(lst, PRICE);
	lstPrint(&lst);
	printf("ORDENAR--------------------------------------------------------\n\n");
	
	pop(&lst);
	lstPrint(&lst);
	printf("POP------------------------------------------------------------\n\n");

    return 0;
}

void cargarArch(const char * nomArch, node_t * lst, cabecera_t * cabecera){
    FILE * fp;
    char str[MAX_STR];
    contenido_t aux;
	int ban = 0;
    
    if((fp = fopen(nomArch,"r")) == NULL){
        printf("ERROR OPENING FILE\n");
    }
    else{
        while(fgets(str,MAX_STR,fp) != NULL){
			if(!ban){
				cabeceraParser(str,cabecera);
				ban++;
			}
			else{
				csvParser(str,&aux);
				oAdd(lst,&aux);
			}
        }
    }
}

void oAdd(node_t * lst, contenido_t * aux){
    node_t naux;
    if(*lst != NULL){
        if(condition(((*lst)->producto),*aux,PRODUCT) == TRUE){
			if((naux = (node_t)malloc(sizeof(struct node_s))) == NULL){
				printf("ERROR INITIATING NODE\n");
			}
			else{
				naux->producto = *aux;
				naux->next = (*lst);
                (*lst) = naux;
			}
        }
        else{
            oAdd(&((*lst)->next),aux);
        }
    }
    else{
	    if((*lst = (node_t)malloc(sizeof(struct node_s))) == NULL){
			printf("ERROR INITIATING NODE\n");
		}
        else{
			(*lst)->producto = *aux;
			(*lst)->next = NULL;
		}
    }
}
void eOrd(node_t lst, node_t nodo, filter_t op){
	contenido_t aux;
	
	if((lst != NULL) && (nodo != NULL)){
		if(condition((lst)->producto,nodo->producto,op) == TRUE){
			aux = (lst)->producto;
			nodo = (lst)->next;
			(lst)->producto = nodo->producto;
			nodo->producto = aux;
		}
		else{
			eOrd((lst->next),nodo,op);
		}
	}
}
void ordenar(node_t lst, filter_t op){
	node_t nodo = NULL;
	
	if(lst != NULL){
		nodo = (lst)->next;
		eOrd(lst,nodo,op);
		ordenar((lst->next),op);
	}
}

void nodeDel(node_t * lst, contenido_t * dNode,filter_t op){
    node_t aux = NULL;
    if(*lst != NULL){
        if(conDel(lst, dNode,op) == TRUE){
            aux = (*lst)->next;
            free((*lst)->producto.prod);
            free((*lst));
            *lst = aux;
        }
        else{
            nodeDel(&((*lst)->next), dNode,op);
        }
    }
}

void push(node_t * lst, contenido_t * node){
	node_t naux = NULL;
	
	if((naux = (node_t)malloc(sizeof(struct node_s))) == NULL){
		printf("ERROR INITIATING NODE\n");
	}
	else{
		naux->producto = *node;
		naux->next = (*lst);
		(*lst) = naux;
	}
}

void pop(node_t * lst){
	node_t aux;
	if(*lst != NULL){
		aux = *lst;
		*lst = (*lst)->next;
		free(aux);
	}
}
	
bool_t conDel(node_t * nodeA, contenido_t * nodeB,filter_t op){
    bool_t res = FALSE;
    int aux;

    switch (op){
        case CODE:
            if(((*nodeA)->producto.cod) == (nodeB->cod)){
                res = TRUE;
            }
            break;
        case PRICE:
            if(((*nodeA)->producto.precio) == (nodeB->precio)){
                res = TRUE;
            }
            break;
        case PRODUCT:
            aux = strcmp((*nodeA)->producto.prod,(nodeB->prod));
            if(aux == 0){
                res = TRUE;
            }
            break;
        default:
            break;
    }
    return res;
}

bool_t condition(contenido_t nodeA, contenido_t nodeB, filter_t op){
    bool_t res = FALSE;
    int aux;

    switch (op){
        case CODE:
            if((nodeA.cod) < (nodeB.cod)){
                res = TRUE;
            }
            break;
        case PRICE:
            if((nodeA.precio) < (nodeB.precio)){
                res = TRUE;
            }
            break;
        case PRODUCT:
            aux = strcmp(nodeA.prod,(nodeB.prod));
            if( (aux > 0) || (aux < 0)){
                res = TRUE;
            }
            break;
        default:
            break;
    }
    return res;
}

void cabeceraParser(char * str, cabecera_t * cab){
	int i,j,contador;
	char token[50];
	char * aux;
	
	if((str != NULL) && (cab != NULL)){
		for(i = 0; str[i] != '\n'; i++,contador++){
			for(j = 0; (str[i] != ',') && (str[i] != '\n'); i++,j++){
				token[j] = str[i];
			}
			token[j] = '\0';
			if(str[i] == '\n'){
				i--;
			}
			switch (contador){
			case 0:
				if((aux = (char*)malloc((sizeof(char)*j)+1)) != NULL){
					strcpy(aux,token);
					cab->nom = aux;
				}
				else{
					printf("ERROR TOKEN MEMORY ALLOC CABECERAPARSER1\n");
				}
				break;
			case 1:
				if((aux = (char*)malloc((sizeof(char)*j)+1)) != NULL){
					strcpy(aux,token);
					cab->p = aux;
				}
				else{
					printf("ERROR TOKEN MEMORY ALLOC CABECERAPARSER2\n");
				}
				break;
			case 2:
				if((aux = (char*)malloc((sizeof(char)*j)+1)) != NULL){
					strcpy(aux,token);
					cab->cod = aux;
				}
				else{
					printf("ERROR TOKEN MEMORY ALLOC CABECERAPARSER3\n");
				}
				break;
			default:
				break;
			}
		}
	}
}
void csvParser(char * str, contenido_t * cont){
    int i,j,contador;
    char token[50];
    char * aux;
	
	contador = 0;

    if((str != NULL) && (cont != NULL)){
        for(i = 0; str[i] != '\n'; i++,contador++){
            for(j = 0; (str[i] != ',') && (str[i] != '\n'); i++,j++){
                token[j] = str[i];
            }
            token[j] = '\0';
            if(str[i] == '\n'){
                i--;
            }
            switch (contador){
                case 0:
                    if((aux = (char*)malloc((sizeof(char)*j)+1)) != NULL){
                        strcpy(aux,token);
                        cont->prod = aux;
                    }
					else{
						printf("ERROR TOKEN MEMORY ALLOC CSVPARSER\n");
					}
					break;
                case 1:
                    cont->precio = atof(token);
					break;
                case 2:
                    cont->cod = atoi(token);
					break;
			default:
				break;
            }
        }
    }
}

void lstPrint(node_t * lst){
    if(*lst != NULL){
        printf("%-15s%15f%15d\n",(*lst)->producto.prod,(*lst)->producto.precio,(*lst)->producto.cod);
        lstPrint(&((*lst)->next));
    }
}
