#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 200

typedef struct{
    char nom[8],cod[6],p[6]; 
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

int main(void){
    node_t lst;
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
    
    if((fp = fopen(nomArch,"r")) == NULL){
        printf("ERROR OPENING FILE\n");
    }
    else{
        /*fscanf(fp, "%s,%s,%s\n",cabecera->nom,cabecera->p,cabecera->cod);*/
        while(fgets(str,MAX_STR,fp) != NULL){
            printf("FGETS: %s\n",str);
            csvParser(str,&aux);
            printf("AUX: %-15s%15f%15d\n",aux.prod,aux.precio,aux.cod);
            oAdd(lst,&aux);

        }
    }
}

void oAdd(node_t * lst, contenido_t * aux){
    node_t naux;
    printf("INIT ORDER ADD\n");
    if(*lst != NULL){
        if((*lst)->next != NULL){
            if((*lst)->producto.precio > aux->precio){
                oAdd(&((*lst)->next),aux);
            }
            else{
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
        if((naux = (node_t)malloc(sizeof(struct node_s))) == NULL){
             printf("ERROR INITIATING NODE\n");
         }
        else{
            naux->producto = *aux;
            naux->next = (*lst)->next;
            (*lst)->next = (node_t) naux;
        }
    }

    printf("END ORDER ADD\n");
}

void csvParser(char * str, contenido_t * cont){
    int i,j,contador;
    char token[50];
    char * aux;

    printf("INIT CSV PARSER\n");

    if((str != NULL) && (cont != NULL)){
        for(i = 0; str[i] != '\n'; i++,contador++){
            for(j = 0; (str[i] != ',') && (str[i] != '\n'); i++,j++){
                token[j] = str[i];
            }
            token[j] = '\0';
            if(str[i] == '\n'){
                i--;
            }
            printf("TOKEN: %s\n",token);
            switch (contador){
                case 0:
                    if((aux = (char*)malloc((sizeof(char)*j)+1)) != NULL){
                        strcpy(aux,token);
                        cont->prod = aux;
                    }
                case 1:
                    cont->precio = atof(token);
                case 2:
                    cont->cod = atoi(token);
            }
        }
    }
}

void lstPrint(node_t * lst){
    if(lst != NULL){
        printf("%-15s%15f%15d\n",(*lst)->producto.prod,(*lst)->producto.precio,(*lst)->producto.cod);
        lstPrint(&((*lst)->next));
    }
}
