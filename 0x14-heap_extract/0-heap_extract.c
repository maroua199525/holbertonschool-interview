#include "binary_trees.h"


/**
 * get_size - calculate the size of binary tree
 * @node: pointer to root node of binary tree
 *
 * Return: the size of binary tree
 */
int get_size(heap_t *node)
{
	if (!node)
		return (0);
	return (1 + get_size(node->left) + get_size(node->right));
}

/**
 * heap_to_array - sort a heap in an array
 * @array: the array in wich the heap be sorted
 * @root: the first node of the heap
 * @index: the index of the array to fill
 */
void heap_to_array(heap_t **array, heap_t *root, int index)
{
	array[index] = root;
	if (root)
	{
		heap_to_array(array, root->left, (index * 2) + 1);
		heap_to_array(array, root->right, (index * 2) + 2);
	}
}

/**
 * max_heap - max the heap
 * @node: root of the heap
 */
void max_heap(heap_t *node)
{
	int ptr;

	if (!node->left)
	{
		return;
	}
	else if (!node->right || node->left->n >= node->right->n)
	{
		if (node->n < node->left->n)
		{
			ptr = node->n;
			node->n = node->left->n;
			node->left->n = ptr;
		}
		max_heap(node->left);
	}
	else if (node->left->n < node->right->n)
	{
		if (node->n < node->right->n)
		{
			ptr = node->n;
			node->n = node->right->n;
			node->right->n = ptr;
		}
		max_heap(node->right);
	}
}
/**
* heap_extract - a function that extracts the root node of a Max Binary Heap
* @root: a double pointer to the root node of the heap
*Return: the value stored in the root node or if failed
*/
int heap_extract(heap_t **root)
{
	int i, n, size;
	heap_t **arr;

	if (!root || !*root)
		return (0);
	n = (*root)->n;
	size = get_size(*root);
	arr = malloc(1024 * sizeof(heap_t *));
	if (!arr)
		return (0);
	for (i = 0; i < size; i++)
		arr[i] = NULL;
	heap_to_array(arr, *root, 0);
	if (arr[size - 1] == (*root))
	{
		free(arr);
		free(*root);
		*root = NULL;
		return (n);
	}
	(*root)->n = arr[size - 1]->n;
	if (arr[size - 1]->parent->left == arr[size - 1])
		arr[size - 1]->parent->left = NULL;
	else
		arr[size - 1]->parent->right = NULL;
	free(arr[size - 1]);
	free(arr);
	max_heap(*root);
	return (n);
}
