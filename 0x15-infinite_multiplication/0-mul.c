#include "holberton.h"

/**
 * is_Number - checks if the argument is a diget
 * @c: argument to be checked
 * Return: 0 on success, 1 on fail
 **/
int is_Number(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

/**
 * _strlen - calculate the length of a string
 * @s: a string
 * Return: the length of the string
 **/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * multiply_integer - multiplies two numbers
 * @a: first number to multiply
 * @b: second number to multiply
 * Return: Nothing
 **/
void multiply_integer(char *a, char *b)
{
	int i, length_1, length_2;
	int total, digit_2, digit_1, r = 0, tmp;
	int *ptr;

	length_1 = _strlen(a);
	length_2 = _strlen(b);
	tmp = length_2;
	total = length_1 + length_2;
	ptr = malloc(sizeof(int) * total);
	if (!ptr)
		return;

	for (length_1--; length_1 >= 0; length_1--)
	{
		digit_2 = a[length_1] - '0';
		r = 0;
		length_2 = tmp;
		for (length_2--; length_2 >= 0; length_2--)
		{
			digit_1 = b[length_2] - '0';
			r += ptr[length_2 + length_1 + 1] + (digit_2 * digit_1);
			ptr[length_1 + length_2 + 1] = r % 10;
			r /= 10;
		}
		if (r)
			ptr[length_1 + length_2 + 1] = r % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: list of string
 * Return: 0 on success
 **/
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || !is_Number(num1) || !is_Number(num2))
	{
		printf("Error\n");
		exit(98);
	}
	if (*argv[1] == '0' || *argv[2] == '0')
	{
		printf("0\n");
		return (0);
	}
	multiply_integer(num1, num2);
	return (0);
}
