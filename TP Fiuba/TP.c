#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef enum{
	TRUE,
	FALSE
}bool_t;

typedef enum{
	CREDIT,
	DEBIT
}operation_t;

typedef unsigned int uint;

typedef struct{
	uint usr;
	uint tran;
    int time;
	char * card;
	char * des;
    int cash;
	operation_t op;
}transaction_t;

struct node_s{
	transaction_t tran;
	struct node_s * next;
};

typedef struct node_s * node_t;

bool_t csv_parser(char * str, transaction_t * aux); /*paso del la linea de csv a transaction_t*/
time_t tm_parser(char * date); /*paso el tiempo de string a time_t*/
void tda_file_print();/*escribo todas mis transacciones ordenadas por usuario en mi archivo*/
void tda_order_append(); /*append en orden en mi array de listas*/

int main(void){
    char str[] = "123412,1,05/11/2011 10:00:00,-10,4916288217067475,Compra supermercado\n";
    transaction_t tran;

    csv_parser(str, &tran);
    printf("USR: %d\n",tran.usr);
    printf("TIME: %ld\n", tran.time);
    printf("CASH: %d\n", tran.cash);
    printf("DESCRIPTION: %s\n", tran.des);
    printf("CARD: %s\n", tran.card);
    printf("TRANSACTION: %d\n", tran.tran);

    return 0;
}

time_t tm_parser(char * date){
    struct tm aux;
    int i, j,res, cont = 0;
    char token[3];

    printf("HOLA\n");
    aux.tm_isdst = 0;
    for(i = 0; date[i] != '\0';i++,cont++){
        for(j = 0; (date[i] != '\0') && (date[i] != '.') && (date[i] != '/') && (date[i] != '-') && (date[i] != ' ') && (date[i] != ':'); j++,i++){
            token[j] = date[i];
        }

        token[j] = '\0';
        printf("TM TOKEN: %s\n",token);
        switch(cont){
            case 0:
                aux.tm_mday = atoi(token);
                break;
            case 1:
                aux.tm_mon = (atoi(token)-1);
                break;
            case 2:
                aux.tm_year = (atoi(token)-1900);
                break;
            case 3:
                aux.tm_hour = atoi(token);
                break;
            case 4:
                aux.tm_min = atoi(token);
                break;
            case 5:
                aux.tm_sec = atoi(token);
                break;
            default:
                break;
        }
    }
    printf("HOLA2\n");
    res = mktime(&aux);
    printf("RES: %d", res);
    return res;
}

bool_t csv_parser(char * str, transaction_t * aux){
	int i, j, cont = 0;
    char token[50];
    char * strAux;
    bool_t ban = TRUE;

    if(str != NULL){
        for(i = 0; (str[i] != '\n') && (ban == TRUE);i++,cont++){
            for(j = 0; (str[i] != ',') && (str[i] != '\n');j++,i++){
                token[j] = str[i];
            }
            token[j] = '\0';
            printf("TOKEN: %s\n",token);
            switch(cont){
                case 0:
                    aux->tran = (uint)atoi(token);
                    break;
                case 1:
                    aux->usr = (uint)atoi(token);
                    break;
                case 2:
                    aux->time = tm_parser(token);
                    break;
                case 3:
                    printf("HOLA2\n");
                    aux->cash = atoi(token);
                    break;
                case 4:
                    if((strAux = (char*)malloc(sizeof(char)*(j+1))) == NULL){
                        printf("ERROR MEMORY ALLOC CSVPARSER\n");
                    }
                    else{
                        aux->card = strAux;
                        strcpy(aux->card,token);
                    }
                    break;
                case 5:
                    if((strAux = (char*)malloc(sizeof(char)*(j+1))) == NULL){
                        printf("ERROR MEMORY ALLOC CSVPARSER\n");
                    }
                    else{
                        aux->des = strAux;
                        strcpy(aux->des,token);
                    }
                    break;
                default:
                    break;

            }
        }
    }
    return ban;
}
