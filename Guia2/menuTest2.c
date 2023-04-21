#include <curses.h>
#include <stdio.h>
#include <ncurses.h>
#include <panel.h>

typedef struct{
    int h;
    int w;
    int startx;
    int starty;
}screen_t;

int main(void){
    screen_t prin,tabla;
    WINDOW *w,*t;
    PANEL *stack[2];
    PANEL *top;
    int choice, highlight,i;
    char *options[5] = {
        "Ver listado ordenado por nombre",
        "Ver listado ordenado por documento",
        "Ver listado ordenado por pais",
        "Exit"
            };

    prin.h = 6;prin.w = 50;prin.startx = 10;prin.starty = 10;
    tabla.h = 6;tabla.w = 100;tabla.startx = 15;tabla.starty = 10;
    
    initscr(); 
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    w = newwin(prin.h,prin.w, prin.starty, prin.startx);
    t = newwin(tabla.h,tabla.w,tabla.starty, tabla.startx);
    box(t,0,0);
    box(w,0,0);
    stack[0] = new_panel(w);
    stack[1] = new_panel(t);
    
    set_panel_userptr(stack[0],stack[1]);
    set_panel_userptr(stack[1],stack[0]);
    update_panels();

    /*
    refresh();
    wrefresh(w);
    wrefresh(t);
    */
   	attron(COLOR_PAIR(4));
	mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
	attroff(COLOR_PAIR(4));
	doupdate();

    /* ----- PANEL TEST ------*/
    
    top = stack[0];
    while((choice = getch()) != 27){
        switch(choice){
            case(13):
                top = (PANEL *)panel_userptr(top);
                top_panel(top);
                break;
        }
        update_panels();
        doupdate();
    }

    /*----MENU----
    highlight = 0;
    
    while(1){
        for(i = 0; i < 4; i++){
            if(i == highlight){
                wattron(w,A_REVERSE);
            }
            mvwprintw(w,i+1,1,options[i]);
            wattroff(w, A_REVERSE);
        }
        choice = wgetch(w);
        switch(choice){
            case KEY_UP:
                highlight--;
                if(highlight == -1){
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 4){
                    highlight = 3;
                }
                break;
            default:
                break;
        }
        if(choice == 10){
            break;
        }
    }
    printw("Your Choice was: %s\n", options[highlight]);
    */
    getch();
    endwin();
    
    return 0;
}
