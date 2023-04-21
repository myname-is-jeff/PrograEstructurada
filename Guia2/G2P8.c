#include <stdio.h>
#include <stdlib.h>

#define MASK1 10000000
#define MASK2 00000001

void aBinario(char c);

int main(void){
    char c = 'A';
    aBinario(c);
    return 0;
}

void aBinario(char c){
    int i;
    for(i = 0; i < 9;i++){
        printf("%d",((((c << i) & MASK1)>> 7)&MASK2));
    }
}
