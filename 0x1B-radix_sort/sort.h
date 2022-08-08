#ifndef _SORT_ARRAY_H_
#define _SORT_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int max_array(int *array, size_t size);
void count(int *array, int size, int digit);

#endif /* _SORT_ARRAY_H_ */
