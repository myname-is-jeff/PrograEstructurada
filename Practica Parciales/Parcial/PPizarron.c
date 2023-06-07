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

void lstPrint(node_t * lst);
void csvParser(char * str, contenido_t * cont);
void oAdd(node_t * lst, contenido_t * aux);
void cargarArch(const char * nomArch, node_t * lst, cabecera_t * cabecera);
void cabeceraParser(char * str, cabecera_t * cab);

int main(void){
    node_t lst = NULL;
    cabecera_t cab;
    char nomArch[] = "datos.txt";

    cargarArch(nomArch,&lst,&cab);
    printf("HOLA\n");
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
        /*fscanf(fp, "%s,%s,%s\n",cabecera->nom,cabecera->p,cabecera->cod);*/
        while(fgets(str,MAX_STR,fp) != NULL){
			if(!ban){
				cabeceraParser(str,cabecera);
				ban++;
			}
			else{
				csvParser(str,&aux);
				printf("AUX CHECK: %-15s%15f%15d\n",aux.prod,aux.precio,aux.cod);
				oAdd(lst,&aux);
			}
        }
    }
}

void oAdd(node_t * lst, contenido_t * aux){
    node_t naux;
    printf("INIT ORDER ADD\n");
    if(*lst != NULL){
		printf("*lst != NULL\n");
		if((*lst)->producto.precio > aux->precio){
			printf("(*lst)->producto.precio > aux->precio\n");
			if((*lst)->next != NULL){
				printf("*lst->next != NULL\n");
				oAdd(&((*lst)->next),aux);
				
			}
			else{
				printf("ELSE: *lst->next != NULL\n");
				if((naux = (node_t)malloc(sizeof(struct node_s))) == NULL){
					printf("ERROR INITIATING NODE\n");
				}
				else{
					naux->producto = *aux;
					naux->next = NULL;
					(*lst)->next = naux;
				}
			}
		}
		else{
			printf("ELSE: (*lst)->producto.precio > aux->precio\n");
			if((naux = (node_t)malloc(sizeof(struct node_s))) == NULL){
				printf("ERROR INITIATING NODE\n");
			}
			else{
				naux->producto = *aux;
				naux->next = (*lst)->next;
				(*lst)->next = naux;
			}
		}
		
	}
    else{
		printf("ELSE: *lst != NULL\n");
        if((naux = (node_t)malloc(sizeof(struct node_s))) == NULL){
             printf("ERROR INITIATING NODE\n");
         }
        else{
            naux->producto = *aux;
            naux->next = NULL;
            (*lst) = naux;
        }
    }

    printf("END ORDER ADD\n");
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
