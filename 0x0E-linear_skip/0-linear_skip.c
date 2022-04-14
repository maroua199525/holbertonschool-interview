#include "search.h"


/**
 *linear_skip - a function that searches for a value
 *in a sorted skip list of integers
 *@list:  a pointer to the head of the skip list to search in
 *@value: the value to search for
 *Return: pointer on the first node where value is located, or NULL if list
 * is NULL or value not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = NULL, *stop = NULL;

	if (!list)
		return (NULL);

	tmp = list;
	while (tmp && tmp->express && tmp->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       tmp->express->index, tmp->express->n);
		tmp = tmp->express;
	}
	stop = tmp;
	while (stop && stop->next != stop->express)
		stop = stop->next;
	if (tmp->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       tmp->express->index, tmp->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       tmp->index, tmp->express->index);
	}
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
		       tmp->index, stop->index);

	while (tmp != stop && tmp->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       tmp->index, tmp->n);
		tmp = tmp->next;
	}
	printf("Value checked at index [%lu] = [%i]\n",
	       tmp->index, tmp->n);

	if (tmp == stop)
		return (NULL);
	return (tmp);
}
