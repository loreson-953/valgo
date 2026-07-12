#include "algorithms.h"
#include "dynamic_arrays.h"
#include "ui.h"
#include <unistd.h>
#include <string.h>
 
int bubble(int debug) {
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
	destroy_window(input_window);

	create_bubble_window();
	bubble_sort(nums.number, nums.count);		
	getch();
	
	emancipate(&nums);
	destroy_window(bubble_window);
	
	return 1; /* successful run */
}


void bubble_sort(int array[], int length) {
	int progress = 0;

	for (int i = 0; i < length - 1; i++) {
		int temp = 0;

		
		__useconds_t delay = 1 * 1000000;

		print_bubble_array(array, length, progress);
		if (progress != length - 1) progress++;
		else progress = 0;
		usleep(delay);
		
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
 			
			print_bubble_array(array, length, progress);
			if (progress != length - 1) progress++;
			else progress = 0;
			wrefresh(bubble_window);
			usleep(delay);
		}
	}
}

void print_bubble_array(int array[], int length, int progress) {
	char progress_char;
	if (progress % 2 == 0) progress_char = '|';
	else progress_char = '-';

	mvwprintw(bubble_window, bubble_info.start_y + 1, bubble_info.start_x + 1, "Sorting: %c", progress_char);
	
	wmove(bubble_window, bubble_info.start_y + 3, bubble_info.start_x + 1);
	
	for (int k = 0; k < length; k++) {
		if ((k != progress) && (k != progress + 1)) wprintw(bubble_window, "%d ", array[k]);
		else if (k == progress) wprintw(bubble_window, "[%d ", array[k]);
		else if (k == progress + 1 && progress != length + 1) wprintw(bubble_window, "%d] ", array[k]);
		else if (k == progress + 1 && progress == length + 1) wprintw(bubble_window, "[%d] ", array[k]);
	}
	
	wrefresh(bubble_window);
}

