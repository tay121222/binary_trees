#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * enqueue - Add a node to the queue
 * @queue: The queue to add
 * @node: The node
 * @rear: A pointer to the rear of the queue
 */
void enqueue(binary_tree_t **queue, binary_tree_t *node, int *rear)
{
	queue[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - Remove and return a node
 * @queue: The queue to remove from
 * @front: A pointer to the front of the queue
 *
 * Return: The dequeued node.
 */
binary_tree_t *dequeue(binary_tree_t **queue, int *front)
{
	binary_tree_t *node = queue[*front];

	(*front)++;
	return (node);
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
 * binary_tree_levelorder - Performs level-order traversal
 * @tree: Pointer to the root node
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue =
		malloc(sizeof(binary_tree_t *) * binary_tree_height(tree));

	if (queue == NULL)
		return;

	int front = 0, rear = 0;

	enqueue(queue, (binary_tree_t *)tree, &rear);

	while (front < rear)
	{
		binary_tree_t *current = dequeue(queue, &front);

		func(current->n);

		if (current->left)
			enqueue(queue, current->left, &rear);

		if (current->right)
			enqueue(queue, current->right, &rear);
	}

	free(queue);
}
