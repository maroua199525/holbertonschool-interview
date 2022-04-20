#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void heapify(int *array, int end, int i, size_t size);
void print_array(const int *array, size_t size);
void swap(int *a, int *b);
#endif
