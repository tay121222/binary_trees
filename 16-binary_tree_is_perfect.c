#include "binary_trees.h"

int binary_tree_level(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: If tree is NULL, function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);

	l = binary_tree_level(tree->left);
	r = binary_tree_level(tree->right);

	if (l == r && binary_tree_is_full(tree))
		return (1);

	return (0);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 *  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((!tree->left && !tree->right) ||
			(tree->left && tree->right &&
			 binary_tree_is_full(tree->left) &&
			 binary_tree_is_full(tree->right)));
}

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
 * binary_tree_level - Calculates the depth of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The level of the leftmost leaf node
 */
int binary_tree_level(const binary_tree_t *tree)
{
	int level = 0;

	while (tree)
	{
		level++;
		tree = tree->left;
	}

	return (level);
}
