/* pastebin.com/uRYpH9j0 
   pastebin.com/ZZNWKbde
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * txt;
    int len;
}txt_t;

int cargarTexto(txt_t * texto);
void escribirArchTex(const char * nomArch, txt_t * texto);

int main(void){
    txt_t * arr = NULL;
    
    escribirArchTex("fcl.csv", arr);

    return 0;
}

int cargarTexto(txt_t * texto){
    
}

void escribirArchTex(const char * nomArch, txt_t * texto){
        
}


