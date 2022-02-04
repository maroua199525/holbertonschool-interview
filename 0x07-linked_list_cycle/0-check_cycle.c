#include "lists.h"

/**
 * check_cycle - a function that checks if a singly linked list has a cycle
 * @list: the given list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *first;
	listint_t *tmp;

	if (!list)
		return (0);
	tmp = list;
	first = list->next;
	while (tmp && first && first->next)
	{
		tmp = tmp->next;
		first = first->next->next;
		if (tmp == first)
			return (1);
	}
	return (0);
}
