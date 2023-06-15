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
	char * card;
	char * des;
	operation_t op;
}transaction_t;

struct node_s{
	transaction_t tran;
	struct node_s * next;
};

typedef struct node_s * node_t;

bool_t csv_parser(char * str, transaction_t * aux); //paso del la linea de csv a transaction_t
void tm_parser(char * date); //paso el tiempo de string a time_t
void tda_file_print();//escribo todas mis transacciones ordenadas por usuario en mi archivo
void tda_order_append(); //append en orden en mi array de listas

int main(void){
	
}

bool_t csv_parser(char * str, transaction_t * aux){
	
}
