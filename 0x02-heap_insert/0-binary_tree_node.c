#include "binary_trees.h"

/**
*binary_tree_node - create a binary tree node
*@parent: Pointer to the parent node
*@value: Integer stored in the node
*Return: a pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_node;

	binary_node = malloc(sizeof(binary_tree_t));
	if (!binary_node)
		return (NULL);
	binary_node->n = value;
	binary_node->parent = parent;
	binary_node->left = NULL;
	binary_node->right = NULL;
	return (binary_node);
}
