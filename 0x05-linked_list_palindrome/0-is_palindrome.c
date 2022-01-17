#include "lists.h"

/**
* is_palindrome -  checks if a singly linked list is a palindrome.
* @head: pointer to pointer of first node of listint_t list
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/

int is_palindrome(listint_t **head)
{
	const listint_t *current;
	unsigned int i; /* number of nodes */
	unsigned int j, length;
	int array[MAX];

	current = *head;
	i = 0;
	while (current != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}
	if (i == 0)
		return (1);
	length = i - 1;
	for (j = 0; j < (length / 2); j++)
	{
		if (array[j] == array[length - j])
			return (1);
	}
	return (0);
}
