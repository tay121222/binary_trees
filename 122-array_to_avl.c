#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_delete_tree - Deletes an entire AVL tree
 * @tree: A pointer to the root node of the AVL tree to delete
 */
void avl_delete_tree(avl_t *tree)
{
	if (tree == NULL)
		return;

	avl_delete_tree(tree->left);
	avl_delete_tree(tree->right);

	free(tree);
}

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size:  number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
		{
			avl_delete_tree(root);
			return (NULL);
		}
	}

	return (root);
}

