#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "algorithms.h"
#include "ui.h"
#include "dynamic_arrays.h"

int scr_bubble();

int debug = 0;

int main(int argc, char *argv[]) {
	if ( argc > 1 && !strncmp("-d", argv[1], 2))
		debug = 1;

	int key_input;
	int highlight = 4;

	// Initialize ncurses
	ncurse_initialization();
	refresh();

 menu:

	// Create and print to title window
	title_window = create_new_window(title_info.height, title_info.width, title_info.start_y, title_info.start_x);
	mvwprintw(title_window, title_info.height / 2, (title_info.width - 30) / 2, "Welcome to Visual Algorithms.");
	wrefresh(title_window);

	// Create and print to options window
	options_window = create_new_window(options_info.height, options_info.width, options_info.start_y, options_info.start_x);
	keypad(options_window, TRUE);
	print_options_window(options_window, highlight);

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
		case 10: // 10 is enter, for some reason
			if (highlight == option_final_y) goto exit;
			else if (highlight == option_1_y) goto bubble;
                        break;
                /* shortcuts: */
                case '1':
			goto bubble;
			break;
                case '0': case 'q':
			goto exit;
                        break;
		}
		print_options_window(options_window, highlight);
	}

 bubble:
	destroy_window(title_window);
        destroy_window(options_window);
	scr_bubble();
	goto menu;

 exit:
	endwin();
	return 0;
}

/*
 * success: return 1
 * failure: return 0
 */
int scr_bubble() {
	char *user_input = malloc(32);
        char delim[] = ", ";
        char *n;

        dynamic_array nums;

        nums.count = 0;
        nums.capacity = 10;
        nums.number = malloc(nums.capacity * sizeof(int));

	input_window = create_new_window(input_info.height, input_info.width, input_info.start_y, input_info.start_x);

        echo();

	mvwprintw(input_window, 1, 2, "Please input the numbers you wish to sort: ");
	wrefresh(input_window);

        mvwgetnstr(input_window, 1, 45, user_input, 31);
        wrefresh(input_window);

        n = strtok(user_input, delim);

        while (n) {
		append_array(nums, atoi(n));
                n = strtok(NULL, delim);
        }

        free(user_input);

	if (debug) {
		int total = 0;
		for (size_t j = 0; j < nums.count; j++) {
			total += nums.number[j];
		}
		mvwprintw(input_window, 2, 2, "total %i, from %i entries.", total, (int)nums.count);
	}

        wrefresh(input_window);

        noecho();
        getch();
		
		bubble_sort(nums.number, nums.count);
		

        emancipate(&nums);

	return 1; /* successful run */
}
