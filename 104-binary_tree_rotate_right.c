#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	tmp = tree->left;
	tree->left = tmp->right;

	if (tmp->right != NULL)
		tmp->right->parent = tree;

	tmp->right = tree;
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
