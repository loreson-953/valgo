#ifndef UI_H
#define UI_H
#include <ncurses.h>

typedef struct {
	int height;
	int width;
	int start_x;
	int start_y;

	char border_vertical;
	char border_horizontal;
	char border_corners;

} window_info;

extern WINDOW *title_window;
extern window_info title_info;
extern char title_text[];

extern WINDOW *options_window;
extern window_info options_info;
extern int option_indent_x;
extern int option_title_y;
extern int option_1_y;
extern int option_final_y;
extern char option_title_text[];
extern char option_1_text[];
extern char option_0_text[];

extern WINDOW *input_window;
extern window_info input_info;

extern WINDOW *bubble_window;
extern window_info bubble_info;

void ncurse_initialization(void);

WINDOW *create_new_window(int height, int width, int start_y, int start_x);
extern int option_indent_x, option_title_y, option_1_y, option_final_y;
void print_options_window(WINDOW *options_window, int highlight);
void input_window_functions(WINDOW *input_window);

void destroy_window(WINDOW *local_window);

#endif
