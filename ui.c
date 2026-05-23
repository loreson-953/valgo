#include "ui.h"
#include <ncurses.h>

WINDOW *title_window;
window_info title_info;
char title_text[] = "Welcome to Visual Algorithms.";

WINDOW *options_window;
window_info options_info;
int option_indent_x;
int option_title_y;
int option_1_y;
int option_final_y;
char option_title_text[] = "Options:";
char *option_text[] = {
	"1. Bubble Sort",
	"0. Exit"
};

WINDOW *input_window;
window_info input_info;

WINDOW *bubble_window;
window_info bubble_info;

void ncurse_initialization(void) { 
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
	
	
	input_info.start_x = title_info.start_x;
	input_info.start_y = title_info.start_y;
	input_info.height = 4;
	input_info.width = 100;

	bubble_info.start_x = title_info.start_x;
	bubble_info.start_y = title_info.start_y;
	bubble_info.height = 8;
	bubble_info.width = 100;
	
	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	
}

WINDOW *create_new_window(int height, int width, int start_y, int start_x) {
	WINDOW *local_window;

	local_window = newwin(height, width, start_y, start_x);
	box(local_window, 0, 0);

	wrefresh(local_window);

	return local_window;
}

void print_options_window(WINDOW *options_window, int highlight) {
	mvwprintw(options_window, option_title_y, option_indent_x, "%s", option_title_text);

	int amount_options = sizeof(option_text) / sizeof(char *);
	int y = option_1_y;

	
	for (int i = 0; i < amount_options; i++) {
		if (highlight == y) {
			wattron(options_window, A_REVERSE);
			mvwprintw(options_window, y, option_indent_x, "%s", option_text[i]);
			wattroff(options_window, A_REVERSE);
		} else mvwprintw(options_window, y, option_indent_x, "%s", option_text[i]);
		y++;
	}
		
	wrefresh(options_window);

}

void input_window_functions(WINDOW *input_window) {
	//
}

void destroy_window(WINDOW *local_window) {
	wborder(local_window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wclear(local_window);
	wrefresh(local_window);
	delwin(local_window);
}
