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
	binary_tree_t *l, *r;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	l = first->parent, r = second->parent;
	if (first == r || !l || (!l->parent && r))
		return (binary_trees_ancestor(first, r));
	else if (l == second || !r || (!r->parent && l))
		return (binary_trees_ancestor(l, second));
	return (binary_trees_ancestor(l, r));
}
