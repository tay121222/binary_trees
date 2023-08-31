#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node = malloc(sizeof(binary_tree_t));

	if (!n_node)
		return (NULL);

	n_node->n = value;
	n_node->parent = parent;
	n_node->left = NULL;
	n_node->right = NULL;

	return (n_node);
}
