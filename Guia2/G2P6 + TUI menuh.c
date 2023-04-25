#include <ncurse.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
	ITEM *my_items[6];
	int c;				
	MENU *my_menu;
	int i,j;
	ITEM *cur_item;
	char *choices[] = {
		"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
	};

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	for(i = 0; i < 5; ++i)
		my_items[i] = new_item(choices[i], choices[i]);
	my_items[5] = (ITEM *)NULL;

	my_menu = new_menu((ITEM *)my_items);
	mvprintw(LINES - 2, 0, "F1 to Exit");
	
	while(1){
		post_menu(my_menu);
		refresh();
		j = 0;
		while((c = getch()) != KEY_F(1)){
			switch(c){
			case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				if(j < 4)
					j++;
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				if(j > 0)
					j--;
				break;
			}
		}	
		unpost_menu(my_menu);
		while((c = getch()) != KEY_F(1)){
			
		}
	}
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
	endwin();
}
