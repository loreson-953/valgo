#include "dynamic_arrays.h"

// Free an array.
void emancipate(dynamic_array *array) {
	array->count = array->capacity = -1;
	free(array->number);

}
