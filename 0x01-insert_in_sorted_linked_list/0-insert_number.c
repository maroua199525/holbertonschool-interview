#include "lists.h"
/**
 *insert_node - inserts a number into a sorted singly linked list
 *@head:pointer of type list_t;
 *@number:integer;
 *Return: new_node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *ptr;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL || (*head)->n >= new_node->n)
	{
		*head = new_node;
		new_node->next = NULL;
		return (new_node);
	}

	ptr = *head;
	while (ptr->next != NULL && ptr->next->n < new_node->n)
	{
		ptr = ptr->next;
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
	return (new_node);
}
