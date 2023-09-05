#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to insert into the BST.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *current, *parent;

	if (tree == NULL)
		return (NULL);

	current = *tree;
	parent = NULL;

	while (current != NULL)
	{
		if (value == current->n)
			return (NULL);

		parent = current;

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent == NULL)
		*tree = new;
	else if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;
	return (new);
}

