#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * binary_tree_nodes - counds nodes with at least 1 child
 * @tree: binary tree
 *
 * Return: number of nodes
 */
unsigned int binary_tree_nodes(heap_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

/**
 * get_last_node - gets last node of heap
 * @root: binary heap
 *
 * Return: last node
 */
heap_t *get_last_node(heap_t *root)
{
	unsigned int count, mask = 1;

	count = binary_tree_nodes(root);
	while (count / mask > 1)
		mask = mask << 1;
	mask = mask >> 1;

	while (mask)
	{
		if (count & mask)
			root = root->right;
		else
			root = root->left;
		mask = mask >> 1;
	}

	return (root);
}

/**
 * rebuild - balances binary tree
 * @root: Base of tree
 */
void rebuild(heap_t *root)
{
	int tmp;
	heap_t *temp = root;

	if (root->left && root->right)
	{
		if (root->left->n >= root->right->n)
		{
			if (root->left->n > root->n)
				temp = root->left;
		}
		else
		{
			if (root->right->n > root->n)
				temp = root->right;
		}
	}
	else if (root->left && root->left->n > root->n)
		temp = root->left;
	else if (root->right && root->right->n > root->n)
		temp = root->right;

	if (temp != root)
	{
		tmp = root->n;
		root->n = temp->n;
		temp->n = tmp;
		rebuild(temp);
	}
}

/**
 * heap_extract - Extracts root of binary tree and rebalances if neccessary
 * @root: root of binary tree
 * Return: Value of root on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int result;

	if (root == NULL)
		return (0);
	result = (*root)->n;
	last = get_last_node(*root);
	if (last != *root)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		last->parent = NULL;
		if ((*root)->left == last)
			last->left = NULL;
		else
			last->left = (*root)->left;
		if ((*root)->right == last)
			last->right = NULL;
		else
			last->right = (*root)->right;
		if (last->left != NULL)
			last->left->parent = last;
		if (last->right != NULL)
			last->right->parent = last;
		free(*root);
		*root = last;
		rebuild(last);
	}
	else
	{
		free(*root);
		*root = NULL;
	}
	return (result);
}
