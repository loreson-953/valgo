#include <stdlib.h>
#include <ncurses.h>
#include "algorithms.h"
#include "ui.h"

// Stuff for dynamic arrays

typedef struct {
	int *number;
	size_t count;
	size_t capacity;
} dynamic_array;

#define append_array(array, input)\
do {\
	if (array.count >= array.capacity) {\
		array.capacity += sizeof(int);\
		array.number = realloc(array.number, array.capacity * sizeof(array.number));\
	}\
	array.number[array.count++] = input;\
} while(0)


// Window Information

WINDOW *title_window;
window_info title_info;

WINDOW *options_window;
window_info options_info;
int option_indent_x;
int option_title_y;
int option_1_y;
int option_final_y;

WINDOW *bubble_window;
window_info bubble_info;


int main(void) {

	int key_input;
	int highlight = 4;

	title_info.start_x = 4;
	title_info.start_y = 1;
	title_info.height = 5;
	title_info.width = 100;

	
	options_info.start_x = title_info.start_x;
	options_info.start_y = title_info.height + 2;
	options_info.height = 8;
	options_info.width = 100;
	option_indent_x = 2;
	option_title_y = 2;
	option_1_y = 4;
	option_final_y = 5;

	bubble_info.start_x = title_info.start_x;
	bubble_info.start_y = title_info.height + 2;
	bubble_info.height = 8;
	bubble_info.width = 100;

		
	// User input initialization
	dynamic_array input;
	input.count = 0;
	input.capacity = 10; // 10 is a decent place to start with
	input.number = malloc(input.capacity * sizeof(input.number));

	// Initialize ncurses
	ncurse_initialization();
	refresh();

	// Create and print to title window
	title_window = create_new_window(title_info.height, title_info.width, title_info.start_y, title_info.start_x);
	mvwprintw(title_window, title_info.height / 2, (title_info.width - 30) / 2, "Welcome to Visual Algorithms.");
	wrefresh(title_window);

 menu:
	// Create and print to options window
	options_window = create_new_window(options_info.height, options_info.width, options_info.start_y, options_info.start_x);
	keypad(options_window, TRUE);
	print_options_window(options_window, highlight);

	while(1) {
		key_input = wgetch(options_window);
		switch(key_input) {
		case KEY_UP:
			if (highlight == option_1_y) highlight = option_final_y;
			else highlight--;
			break;
		case KEY_DOWN:
			if (highlight == option_final_y) highlight = option_1_y;
			else highlight++;
			break;
		case 10: // 10 is enter, for some reason
			if (highlight == option_final_y) goto exit;
			else if (highlight == option_1_y) goto bubble;
			break;
		}
		print_options_window(options_window, highlight);
	}

 bubble:
	destroy_window(options_window);
	
	
	getch();
	goto menu;
	
 exit:
	endwin();
	return 0;
}
