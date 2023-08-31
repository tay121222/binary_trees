#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function that checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise or if node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL && node != NULL)
		return (1);

	return (0);
}
