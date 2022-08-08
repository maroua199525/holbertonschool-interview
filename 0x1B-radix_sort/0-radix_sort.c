#include "sort.h"



/**
 * max_array - finds the maximun value in an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: the maximum value in the array
 */
int max_array(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count - counts the number of digits in the max_array
 * @array: array to be sorted
 * @size: size of the array
 * @digit: the digit
 * Return: Void
 */
void count(int *array, int size, int digit)
{
	int i, *arr;
	int count[10] = {0};

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		arr[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = arr[i];
	free(arr);
}

/**
 * radix_sort - sorts an array of integers in ascending order using radix sort
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int i;

	for (i = 1; i < 100; i *= 10)
	{
		count(array, size, i);
		print_array(array, size);
	}
}

