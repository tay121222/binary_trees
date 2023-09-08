#include "binary_trees.h"

/**
 * balance - Calculates the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * update_balance_and_rotate - Update balance factor and rotate if needed.
 * @tree: pointer to the root node of the AVL tree.
 */
void update_balance_and_rotate(avl_t **tree, int value)
{
	int bfactor = balance(*tree);

	if (bfactor > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if (bfactor < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
		return;
	}
	if (bfactor > 1 && (*tree)->left-> n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}


/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively
 * @tree: pointer to the root node of the AVL tree
 * @parent: The parent node of the current working node
 * @new: pointer to store the new node
 * @value: The value to insert into the AVL tree
 *
 * Return: pointer to the new root after insertion
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	update_balance_and_rotate(tree, value);

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
