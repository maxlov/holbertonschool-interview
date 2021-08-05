#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_node - creates binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node or NULL on failure
 */
heap_t *heap_node(heap_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->right = NULL;
	new->left = NULL;
	new->n = value;

	return (new);
}

/**
 * heap_height - measures height of a binary tree
 * @tree: binary tree
 *
 * Return: height of binary tree
 */
size_t heap_height(const heap_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + heap_height(tree->left) : 0;
	height_r = tree->right ? 1 + heap_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: double pointer to root node of heap
 * @value: value to put in the new node
 *
 * Return: pointer to the inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current;
	int val_hold;

	current = *root;

	if (*root == NULL)
		return (heap_node(NULL, value));

	do {
		if (current->left == NULL)
		{
			current->left = heap_node(current->left, value);
			current = current->left;
		}
		else if (current->right == NULL)
		{
			current->right = heap_node(current->right, value);
			current = current->right;
		}
		else
		{
			if (heap_height(current->left) <= heap_height(current->right))
				current = current->left;
			else
				current = current->right;
		}
	} while (current->left != NULL && current->right != NULL);

	if (current == NULL)
		return (NULL);

	while (current->parent != NULL && current->parent->n < current->n)
	{
		val_hold = current->n;
		current->n = current->parent->n;
		current->parent->n = val_hold;
		current = current->parent;
	}
	return (current);
}
