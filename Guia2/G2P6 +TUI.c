#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include <menu.h>

#define  N 5

typedef enum{
	NOMBRE,
	DNI,
	PAIS,
	EXIT
}option_t;

typedef struct{
	int dni;
	char nombre[50];
	char pais[50];
}person_t;

typedef struct{
    int height;
    int width;
    int startx;
    int starty;
}screen_t;

void cargarArrDeArch(person_t arr[], char nombre_arch[]);
void imprimirTabla(person_t arr[]);
option_t menu();
void ordenarArr(person_t arr[], option_t op);

int main(void){
	person_t arr[N];
    int i,ch;
    MENU *menu;
	char nombre_arch[] = "personas.txt";
	ITEM *items[5];
    ITEM *selected_item;
    WINDOW *w;
    screen_t principal,tabla;

    principal.height = 5;principal.width = 50; principal.startx = 10; principal.starty = 10; 
    tabla.height = 5;tabla.width = 50; tabla.startx = 10; tabla.starty = 10;
    
    initscr();
    
    w = newwin(principal.height,principal.width,principal.starty, principal.startx);
    refresh();
    box(w,0,0);
    wrefresh(w);
    items[0] = new_item("Option 1","Ver listado ordenado por nombre");
    items[1] = new_item("Option 2","Ver listado ordenado por documento");
    items[2] = new_item("Option 3","Ver listado ordenado por pais");
    items[3] = new_item("Option 4","Salir del programa");

    menu = new_menu(items); 
    keypad(w, TRUE);
    set_menu_win(menu,w); 
    set_menu_sub(menu, derwin(w, 6, 50, 3, 1));
    set_menu_format(menu, 5, 1);
    set_menu_mark(menu, "> ");
    attron(A_BOLD); 
    mvprintw(LINES - 2, 0, "Use arrow keys to navigate, ENTER to select");
    attroff(A_BOLD);
    refresh();
    post_menu(menu);
    wrefresh(w);
	cargarArrDeArch(arr,nombre_arch);
    
    while ((ch = getch()) != 27) {
        switch (ch) {
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
            case 10:
                selected_item = current_item(menu);
                switch (item_index(selected_item)) {
                    case 0:
                        ordenarArr(arr,0);
                        break;
                    case 1:
                        ordenarArr(arr,1);
                        break;
                    case 2:
                        ordenarArr(arr,2);
                        break;
                    case 3:
                        ordenarArr(arr,3);
                        break;
                }
                break;
            default:
                break;
        }
    wrefresh(stdscr);
    }


    
   /*limpiar y cerrar todo*/ 
    unpost_menu(menu); /* remove the menu from the screen*/
    free_menu(menu); /* free the memory used by the menu*/
    for (i = 0; i < 4; i++) {
        free_item(items[i]); /* free the memory used by each menu item*/
    }
    endwin(); /* exit the ncurses environment*/

    imprimirTabla(arr);
	
    return 0;
}
	
	
void cargarArrDeArch(person_t arr[], char nombre_arch[]){
	FILE *fp;
	int i;
	person_t aux;
	char str[100];
	/*csvparser*/
	int res,y,k,z;
	char token[10];
	char * temp;
	
	fp = fopen(nombre_arch,"r");
	
	if(fp == NULL){
		perror("Error opening a file");
		fclose(fp);
	}
	else{
		for(i = 0; i < N; i++){
			if(fgets(str, 100, fp) != NULL){
				z = 0;
				for(y = 0; str[y] != '\n'; y++){
					z++;
					k = 0;
					for(k = 0; str[y] != ',' && str[y] != '\n'; y++){
						token[k] = str[y];
						k++;
					}
					token[k] = '\0';
					switch(z){
						case 1:
							res = strtol(token,&temp,10);
							aux.dni = res;		
							break;
						case 2:
							strcpy(aux.nombre,token);
							break;
						case 3:
							strcpy(aux.pais,token);
							break;
						}
					if(str[y] == '\n'){
						y--;
					}
				}
			}
			arr[i] = aux;
		}
	}
}
	
void imprimirTabla(person_t arr[]){
	int i,j,k;
	person_t structaux;
	
	printw("Nombre              Documento         Pais\n");
	printw("===================================================");
	for(i = 0; i < 5; i++){
		printw("\n");
		structaux = arr[i];
		for(j = 0; structaux.nombre[j] != '\0'; j++);
		j++;
		printw("%s",structaux.nombre);
		for(k = j; k <= 20; k++){
			printw(" ");
		}
		for(k = k; k <= 21; k++){
			printw(" ");
		}
		printw("%d",structaux.dni);
		for(k = k; k <= 30; k++){
			printw(" ");
		}
		printw("%s",structaux.pais);
	}
}

void ordenarArr(person_t arr[], option_t op){
	person_t auxA,auxB;
	int i;
	int j;
	switch (op){
		case NOMBRE:
			for (i = 0; i < N - 1; i++) {
				for (j = i + 1; j < N; j++) {
					auxA = arr[i];
					auxB = arr[j];
					if (auxA.nombre[0] > auxB.nombre[0]) {
						arr[i] = auxB;
						arr[j] = auxA;
					}
				}
			}
			break;
		case DNI:
			for (i = 0; i < N - 1; i++) {
				for (j = i + 1; j < N; j++) {
					auxA = arr[i];
					auxB = arr[j];
					if (auxA.dni > auxB.dni) {
						arr[i] = auxB;
						arr[j] = auxA;
					}
				}
			}
			break;
		case PAIS:
			for (i = 0; i < N - 1; i++) {
				for (j = i + 1; j < N; j++) {
					auxA = arr[i];
					auxB = arr[j];
					if (auxA.pais[0] > auxB.pais[0]) {
						arr[i] = auxB;
						arr[j] = auxA;
					}
				}
			}
			break;
		case EXIT:
			exit(0);
	}
}

