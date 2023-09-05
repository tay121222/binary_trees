#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - checks if a tree is a valid BST
 * @tree: Pointer to the current node
 * @prev: Pointer to the previous node
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_util(tree->left, prev) || tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return is_bst_util(tree->right, prev);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN; // Initialize prev with the minimum possible value

	if (tree == NULL)
		return (0);

	return is_bst_util(tree, &prev);
}

