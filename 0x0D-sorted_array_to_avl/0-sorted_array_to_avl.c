#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * create_node - creates new node for tree
 *
 * @parent: parent of new node
 * @n: value of new node
 * Return: created node or NULL on failure
 */
avl_t *create_node(avl_t *parent, int n)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = n;

	return (new_node);
}

/**
 * avl_insert - recursively inserts nodes from sorted array into tree
 *
 * @avl_tree: binary tree
 * @array: array of numbers to be inserted to tree
 * @start: position of array to start at
 * @end: position of array to end at
 * Return: new node or NULL on failure
 */
avl_t *avl_insert(avl_t *avl_tree, int *array, size_t start, size_t end)
{
	avl_t *new;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new = create_node(avl_tree, array[mid]);
	if (mid > start)
		new->left = avl_insert(new, array, start, mid - 1);
	if (mid < end)
		new->right = avl_insert(new, array, mid + 1, end);

	return (new);
}

/**
 * sorted_array_to_avl - creates an AVL binary tree using a sorted array
 *
 * @array: The array to be printed
 * @size: Size of the array
 * Return: head of tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (avl_insert(NULL, array, 0, size - 1));
}
