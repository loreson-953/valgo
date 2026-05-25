#include "algorithms.h"
#include "dynamic_arrays.h"
#include "ui.h"
#include <unistd.h>

void bubble_sort(int array[], int length) {
	for (int i = 0; i < length - 1; i++) {
		int temp = 0;

		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

			for(int k = 0; k < length; k++) mvwprintw(bubble_window, bubble_info.start_y + 3, sizeof(array[k]) / sizeof(int), "%d, ", array[k]);
			wrefresh(bubble_window);
			usleep(100000);
		}
	}
}

