#include "sort.h"

/**
*merge_sort - a function that sorts an array of integers
*in ascending order using the Merge Sort algorithm: (top-down merge)
*@array: the array to be sorted
*@size: the size of the array
*Return: Void
*/
void merge_sort(int *array, size_t size)
{
	int *array_2;

	if (size == 1)
		return;
	array_2 = malloc(size * sizeof(*array));
	if (!array_2)
		return;
	memcpy(array_2, array, size * sizeof(*array_2));
	parse_array(array, array_2, 0, size);
	free(array_2);
}
/**
 * parse_array - parse the  array
 * @array:  array of number to be parsed
 * @array_2: array
 * @low: index of start
 * @high: index of end
 */
void parse_array(int *array, int *array_2, size_t low, size_t high)
{
	size_t n;

	if (high - low <= 1)
		return;
	n = (low + high) / 2;
	parse_array(array_2, array, low, n);
	parse_array(array_2, array, n, high);
	merge_array(array, array_2, low, n, high);
}
/**
 * merge_array - merge the array
 * @array: array of numbers
 * @array_2: an array
 * @low: index of start
 * @n: index of n
 * @high: index of end
 */
void merge_array(int *array, int *array_2, size_t low, size_t n, size_t high)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(array_2 + low, n - low);
	printf("[right]: ");
	print_array(array_2 + n, high - n);
	for (i = l = low, r = n; i < high; ++i)
	{
		if (l < n && (r >= high || array_2[l] <= array_2[r]))
			array[i] = array_2[l++];
		else
			array[i] = array_2[r++];
	}
	printf("[Done]: ");
	print_array(array + low, high - low);
}
