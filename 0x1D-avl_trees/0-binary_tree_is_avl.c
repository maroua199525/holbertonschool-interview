#include "binary_trees.h"

/**
* valid_avl - checks if BST is a valid AVL tree
* @root: root of a tree
* @min: value of min node
* @max: value of max node
* @height: height of the tree
* Return: 1 if it is AVL tree, 0 otherwise
*/
int valid_avl(const binary_tree_t *root, int min, int max, int *height)
{
	int left = 0, right = 0, count = 0;

	if (root == NULL)
		return (1);
	if (root->n < min || root->n > max)
		return (0);
	if (!valid_avl(root->left, min, root->n - 1, &left))
		return (0);
	if (!valid_avl(root->right, root->n + 1, max, &right))
		return (0);
	if (left > right)
		count = left;
	else
	{
		count = right;
	}
	*height = (1 + count);
	if (abs(left - right) > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - function that checks if a
 * binary tree is a valid AVL Tree
 * @tree: binary tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (valid_avl(tree, INT_MIN, INT_MAX, &height));
}
