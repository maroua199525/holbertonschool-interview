#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>


/********* struct *******************/

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/************ function ********/
int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *);
void max_heap(heap_t *node);
void heap_to_array(heap_t **array, heap_t *root, int index);

#endif /* _BINARY_TREES_H_ */
