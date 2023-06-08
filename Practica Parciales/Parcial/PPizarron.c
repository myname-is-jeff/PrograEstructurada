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

void lstPrint(node_t * lst);
void csvParser(char * str, contenido_t * cont);
void oAdd(node_t * lst, contenido_t * aux);
void cargarArch(const char * nomArch, node_t * lst, cabecera_t * cabecera);
void cabeceraParser(char * str, cabecera_t * cab);
void nodeDel(node_t * lst,  contenido_t * dNode, filter_t op);
bool_t condition(node_t * nodeA, contenido_t * nodeB, filter_t op);
bool_t conDel(node_t * nodeA, contenido_t * nodeB, filter_t op);

int main(void){
    node_t lst = NULL;
    cabecera_t cab;
    char nomArch[] = "datos.txt";
    contenido_t del;

    cargarArch(nomArch,&lst,&cab);
    lstPrint(&lst);
    del.cod = 1848;
    nodeDel(&lst, &del, CODE);
    lstPrint(&lst);

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
        if(condition(lst,aux,PRODUCT) == TRUE){
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

void nodeDel(node_t * lst, contenido_t * dNode,filter_t op){
    node_t aux = NULL;
    printf("INIT NODE DEL\n");
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
    printf("END NODE DEL");
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

bool_t condition(node_t * nodeA, contenido_t * nodeB, filter_t op){
    bool_t res = FALSE;
    int aux;

    switch (op){
        case CODE:
            if(((*nodeA)->producto.cod) > (nodeB->cod)){
                res = TRUE;
            }
            break;
        case PRICE:
            if(((*nodeA)->producto.precio) > (nodeB->precio)){
                res = TRUE;
            }
            break;
        case PRODUCT:
            aux = strcmp((*nodeA)->producto.prod,(nodeB->prod));
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
