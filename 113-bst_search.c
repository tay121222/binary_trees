#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: The value to search for in the tree
 *
 * Return: Pointer to the node with the value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return (bst_t *)tree;

	if (value < tree->n)
		return bst_search(tree->left, value);
	else
		return bst_search(tree->right, value);
}
