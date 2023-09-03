#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return:  return a pointer to the lowest common ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	binary_tree_t *l = binary_trees_ancestor(first, second->parent);
	binary_tree_t *r = binary_trees_ancestor(first->parent, second);

	if (l != NULL && r != NULL)
		return ((binary_tree_t *)first);

	return (l != NULL ? l : r);
}
