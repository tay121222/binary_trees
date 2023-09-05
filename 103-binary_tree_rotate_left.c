#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	tmp = tree->right;
	tree->right = tmp->left;

	if (tmp->left != NULL)
		tmp->left->parent = tree;

	tmp->left = tree;
	tmp->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = tmp;
		else
			tree->parent->right = tmp;
	}

	tree->parent = tmp;
	return (tmp);
}
