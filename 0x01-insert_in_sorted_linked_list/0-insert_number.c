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
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL && new_node->n > ptr->next->n)
		{
			ptr = ptr->next;
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
	return (new_node);
}
