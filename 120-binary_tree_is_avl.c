#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_height -  function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	return (1 + (l > r ? l : r));
}

/**
 * binary_tree_is_bst_1 - Checks if a binary tree is a valid BST tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The value of the smallest node visited thus far
 * @max: The value of the largest node visited this far
 *
 * Return: If the tree is a valid BST tree, 1, otherwise, 0
 */
int binary_tree_is_bst_1(const binary_tree_t *tree, int min, int max)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		lhgt = binary_tree_height(tree->left);
		rhgt = binary_tree_height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (binary_tree_is_bst_1(tree->left, min, tree->n - 1) &&
				binary_tree_is_bst_1(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_is_bst_1(tree, INT_MIN, INT_MAX));
}
