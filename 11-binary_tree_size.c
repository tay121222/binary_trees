#include "binary_trees.h"

/**
 * binary_tree_size -  measures the size of a binary tree
 * @tree: Pointer to the node to measure the size
 * Return: f tree is NULL, your function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
		return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));

	return (0);
}
