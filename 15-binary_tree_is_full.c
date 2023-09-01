#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((!tree->left && !tree->right) ||
			(tree->left && tree->right &&
			 binary_tree_is_full(tree->left) &&
			 binary_tree_is_full(tree->right)));
}
