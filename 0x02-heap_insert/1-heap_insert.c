#include "binary_trees.h"

/**
*heap_insert - inserts a value into a Max Binary Heap
*@root: a double pointer to the root node of the Heap
*@value: the value to store in the node to be inserted
*Return: a pointer to the inserted node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *insert_node = malloc(sizeof(heap_t));
    heap_t *parent;

    parent = *root;
    if (insert_node == NULL)
        return (NULL);
    

}