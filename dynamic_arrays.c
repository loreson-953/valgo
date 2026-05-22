#include "dynamic_arrays.h"

void emancipate(dynamic_array *array) {
	array->count = array->capacity = -1;
	free(array->number);

}
