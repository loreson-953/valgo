#include "ui.h"
#include <ncurses.h>

void ncurse_initialization(void) {
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
	mvwprintw(options_window, option_title_y, option_indent_x, "Options:");

	switch(highlight) {
	case 4:
		wattron(options_window, A_REVERSE);
		mvwprintw(options_window, option_1_y, option_indent_x, "1. Bubble Sort");
		wattroff(options_window, A_REVERSE);
		mvwprintw(options_window, option_final_y, option_indent_x, "0. Exit");
		break;
	case 5:
		mvwprintw(options_window, option_1_y, option_indent_x, "1. Bubble Sort");
		wattron(options_window, A_REVERSE);
		mvwprintw(options_window, option_final_y, option_indent_x, "0. Exit");
		wattroff(options_window, A_REVERSE);
		break;
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
