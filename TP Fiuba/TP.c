#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef enum{
	FALSE,
	TRUE
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

bool_t worthParse(char * str, int init, int end);/* verifico si es conveniente parsear toda la linea del archivo --- DONE*/
void csv_parser(char * str, transaction_t * aux); /*paso del la linea de csv a transaction_t --- DONE*/
time_t tm_parser(char * date); /*paso el tiempo de string a time_t --- DONE*/
bool_t timeCheck(int init, int end, int time); /*Verifico que el tiempo parseado este en mi rango --- DONE*/
void tda_file_print();/*escribo todas mis transacciones ordenadas por usuario en mi archivo --- LOADING*/
void tda_order_append(); /*append en orden en mi array de listas --- LOADING*/

int main(void){
    char str[] = "123412,1,05/11/2011 10:00:00,-10,4916288217067475,Compra supermercado\n";
    transaction_t tran;
	time_t init, end;
	char i[] = "05/11/2011 10:00:00";
	char e[] = "07/11/2011 10:00:00";
	init = tm_parser(i); end = tm_parser(e);
    if(worthParse(str,init,end) == TRUE){
		csv_parser(str, &tran);
		printf("USR: %d\n",tran.usr);
		printf("TIME: %d\n", tran.time);
		printf("CASH: %d\n", tran.cash);
		printf("DESCRIPTION: %s\n", tran.des);
		printf("CARD: %s\n", tran.card);
		printf("TRANSACTION: %d\n", tran.tran);
	}
	else{
		printf("NOT WORTH PARSING\n");
	}

    return 0;
}

bool_t worthParse(char * str, int init, int end){
	int i,j,cont = 0;
	bool_t res;
	char token[50];
	
	for(i = 0; cont != 2; i++){
		if(str[i] == ','){
			cont++;
		}
	}
	for(j = 0; (str[i] != ',') && (str[i] != '\n');j++,i++){
		token[j] = str[i];
	}
	token[j] = '\0';
	i = tm_parser(token);
	res = timeCheck(init,end,i);
	return res;
}

bool_t timeCheck(int init, int end, int time){
	bool_t flag = TRUE;
	if((time < init) || (time > end)){
		flag = FALSE;
	}
	return flag;
}

time_t tm_parser(char * date){
    struct tm aux;
    int i, j,res, cont = 0;
    char token[3];
    aux.tm_isdst = 0;
    for(i = 0; date[i] != '\0';i++,cont++){
        for(j = 0; (date[i] != '\0') && (date[i] != '.') && (date[i] != '/') && (date[i] != '-') && (date[i] != ' ') && (date[i] != ':'); j++,i++){
            token[j] = date[i];
        }
		if(date[i] == '\0'){
			i--;
		}
        token[j] = '\0';
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
    res = mktime(&aux);
    return res;
}

void csv_parser(char * str, transaction_t * aux){
	int i, j, cont = 0;
    char token[50];
    char * strAux;

    if(str != NULL){
        for(i = 0; (str[i] != '\n');i++,cont++){
            for(j = 0; (str[i] != ',') && (str[i] != '\n');j++,i++){
                token[j] = str[i];
            }
			if(str[i] == '\n'){
				i--;
			}
            token[j] = '\0';
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
}
