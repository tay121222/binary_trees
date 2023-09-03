#include "binary_trees.h"
#include <stdlib.h>

/**
 * is_complete_recursive - function to check if a binary tree is complete
 * @tree: Pointer to the root node
 * @index: Current index in the binary heap
 * @count: Number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree,
		size_t index, size_t count)
{
	if (!tree)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, count) &&
			is_complete_recursive(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	}

	return (is_complete_recursive(tree, 0, count));
}
