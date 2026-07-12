#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "algorithms.h"
#include "ui.h"
#include "dynamic_arrays.h"

int debug = 0;
int highlight;

int main(int argc, char *argv[]) {
	if ( argc > 1 && !strncmp("-d", argv[1], 2)) debug = 1;

	int key_input;
	highlight = 4;

	// Creates information for windows and initializes ncurses
	ncurse_initialization();
	refresh();

 menu: main_menu();
	
	while(1) {
		key_input = wgetch(options_window);
		switch(key_input) {
		case KEY_UP: case 'k': case 16:
			if (highlight == option_1_y) highlight = option_final_y;
			else highlight--;
			break;
		case KEY_DOWN: case 'j': case 14:
			if (highlight == option_final_y) highlight = option_1_y;
			else highlight++;
			break;
		case 10: // Enter 
			if (highlight == option_final_y) goto exit;
			else if (highlight == option_1_y) goto bubble;
			break;
			/* shortcuts: */
		case '1':
			goto bubble;
			break;
		case '2':
			goto merge;
			break;
		case '0': case 'q':
			goto exit;
                        break;
		}
		print_options_window();
	}

 bubble:
	destroy_window(title_window);
    destroy_window(options_window);
	bubble(debug);
	goto menu;

 merge:
	destroy_window(title_window);
	destroy_window(options_window);
	goto menu;
	
 exit:
	endwin();
	return 0;
}
