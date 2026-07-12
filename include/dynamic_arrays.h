#ifndef DYNAMIC_ARRAYS_H
#define DYNAMIC_ARRAYS_H
#include <stdlib.h>

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

void emancipate(dynamic_array *array);

#endif
