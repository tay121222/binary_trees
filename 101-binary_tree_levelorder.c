#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal
 * @tree: Pointer to the root node
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left != NULL)
			queue[rear++] = (binary_tree_t *)current->left;

		if (current->right != NULL)
			queue[rear++] = (binary_tree_t *)current->right;
	}
}
