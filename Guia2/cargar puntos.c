#include <stdio.h>
#include <stdlib.h>

#define MAX_P 10

int main(void){
	FILE *fp;
	int i;
	
	fp = fopen("puntos.csv","w");
	if(fp == NULL){
		perror("Error opening file");
		fclose(fp);
	}
	else{
		for(i = 0; i < (2*MAX_P)-1;i++){
			fprintf(fp,"%d,",rand()%10);
		}
		fprintf(fp,"%d",rand()%10);
		fclose(fp);
	}
	return 0;
}
