#include "search_algos.h"

/**
 * advanced_binary - a function that searches for a value in
 * a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located
 */

int advanced_binary(int *array, size_t size, int value)
{

	size_t left = 0, right = size - 1;
	size_t index_mid;

	if (array == NULL)
		return (-1);
	while (left <= right)
	{
		printf("Searching in array: ");
		print_array(array, left, right);
		printf("\n");
		index_mid = (left + right) / 2;
		if (array[index_mid] == value && array[index_mid - 1] != value)
		{
			return (index_mid);
		}
		else if (array[index_mid] < value)
		{
			left = index_mid + 1;
		}
		else
		{
			right = index_mid;
		}
	}
	return (-1);
}

/**
 * print_array - Prints an array
 * @array: Pointer to the first element in the array
 * @first_index: Index of the printing first
 * @size: Size of the array
 */



void print_array(int *array, size_t first_index, size_t size)
{
	if (first_index > size)
		return;
	printf("%d", array[first_index]);
	if (first_index < size)
		printf(", ");
	print_array(array, first_index + 1, size);
}
