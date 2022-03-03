#include "binary_trees.h"

/**
* tree_depth - measures the depth of a node in a binary tree
* @tree: node to check
* Return: depth
*/

size_t tree_depth(const binary_tree_t *tree)
{
	int cont = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		cont++;
		tree = tree->parent;
	}
	return (cont);
}
/**
* tree_is_none - checks if a node is a leaf
* @node: parent node
* Return: pointer to the new node
*/

int tree_is_none(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
/**
* _insert - function to insert node
* @tree: pointer to tree
* @level: level to insert node
* @value: value of the new node
* Return: the node inserted
*/

binary_tree_t *_insert(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (tree_depth(tree) == level)
	{
		if (tree_is_none(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left != NULL && tree->right == NULL)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left = _insert(tree->left, level, value);
	if (left == NULL)
		right = _insert(tree->right, level, value);
	else
		return (left);
	return (right);
}

/**
* bianary_height - measures the height of a binary tree
* @tree: node to check
* Return: height
*/

size_t bianary_height(const binary_tree_t *tree)
{
	int lheight;
	int rheight;

	if (tree == NULL || tree_is_none(tree) == 1)
		return (0);
	lheight = bianary_height(tree->left);
	rheight = bianary_height(tree->right);

	if (lheight >= rheight)
		return (1 + lheight);
	return (1 + rheight);
}

/**
* heap_insert - binary tree node
* @root: pointer to the root node
* @value: value store to inserted
* Return: the inserted node
*/

heap_t *heap_insert(heap_t **root, int value)
{
	size_t level, i, tmp = 0;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *)*root, value);
		return (*root);
	}
	level = bianary_height(*root);
	for (i = 0; i <= level; i++)
	{
		node = (heap_t *) _insert((binary_tree_t *)*root, i, value);
		if (node != NULL)
			break;
	}
	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}
