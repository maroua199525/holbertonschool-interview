#include "binary_trees.h"

/**
 * create_newNode - create a node
 * @n: value of node
 * @parent:te parent node
 * Return: a pointer to the node created.
 */
avl_t *create_newNode(int n, avl_t *parent)
{
	avl_t *new_node = malloc(sizeof(*new_node));

	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * search_add - search where to add node in tree
 * @parent: the parent node
 * @array: array of values
 * @left: left index
 * @right: right index
 * Return: last node or Null
 */
avl_t *search_add(avl_t *parent, int *array, int left, int right)
{
	avl_t *new_node;
	int i;

	if (left > right)
		return (NULL);
	i = (left + right) / 2;
	new_node = create_newNode(array[i], parent);
	if (!new_node)
		return (NULL);
	new_node->left = search_add(new_node, array, left, i - 1);
	new_node->right = search_add(new_node, array, i + 1, right);
	return (new_node);
}

/**
 * sorted_array_to_avl -  builds an AVL tree from an array
 * @array: a pointer to the first element of the array
 * @size: the number of element in the array
 *
 * Return:  root or null
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (search_add(NULL, array, 0, size - 1));
}
