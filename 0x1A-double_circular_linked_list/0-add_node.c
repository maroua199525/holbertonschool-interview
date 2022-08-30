#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: The list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *ptr;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = NULL;
	new->prev = NULL;
	if (*list == NULL)
	{
		*list = new;
		new->next = new;
		new->prev = new;
		return (new);
	}
	ptr = *list;
	while (ptr->next != *list)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
	new->next = *list;
	(*list)->prev = new;
	return (new);
}
/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new = add_node_end(list, str);

	if (new == NULL)
		return (NULL);
	*list = new;
	return (new);
}
