#include "binary_trees.h"

size_t binary_tree_level(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
unsigned char tree_is_leaf(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node
 *
 * Return: 0 Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaf_depth;

	if (tree == NULL)
		return (0);
	leaf_depth = binary_tree_level(get_leaf(tree));
	return (is_perfect_recursive(tree, leaf_depth, 0));
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (tree_is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * tree_is_leaf - Checks if a node is a leaf
 * @tree: Pointer to the root node of the tree to check
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char tree_is_leaf(const binary_tree_t *tree)
{
	return ((tree->left == NULL && tree->right == NULL) ? 1 : 0);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively
 * @tree: A pointer to the root node
 * @leaf_depth: The depth of one leaf
 * @level: Level of the current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (tree_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_level - Calculates the depth of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The level of the leftmost leaf node
 */
size_t binary_tree_level(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + binary_tree_level(tree->parent) : 0);
}
