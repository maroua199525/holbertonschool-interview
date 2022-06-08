#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_array(int *array, int *array_2, size_t low, size_t n, size_t high);
void parse_array(int *array, int *array_2, size_t low, size_t high);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);


#endif /* _SORT_H_  */
