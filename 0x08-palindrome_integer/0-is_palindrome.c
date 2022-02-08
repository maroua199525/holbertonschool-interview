#include "palindrome.h"

/**
* is_palindrome - checks whether or not a given unsigned integer
* is a palindrome
* @n: the number to be checked
* Return:1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{

	int array[SIZE_MAX];
	int i = 0, length, j;

	while (n >= 1)
	{
		if (n > 10)
		{
			array[i] = (n % 10);
			n = (n / 10);
		}
		else
		{
			array[i] = n;
			break;
		}
		i++;
	}
	length = i;
	for (j = 0; j <= ((length + 1) / 2); j++)
	{
		if (array[j] != array[length - j])
			return (0);
	}
	return (1);
}
