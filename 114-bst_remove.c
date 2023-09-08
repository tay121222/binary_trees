#include "binary_trees.h"
#include <stdlib.h>

/**
 * inorder_successor - Returns the minimum value of BN tree
 * @root: pointer to the root node
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove_recursive - removes a node from a binary search
 * @root: pointer to the root node of the BST
 * @node: pointer to the current node in the BST
 * @value: value to remove from the BST
 *
 * Return: pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
		{
			bst_t *parent = node->parent, *successor = NULL;

			if (node->left == NULL)
			{
				if (parent != NULL && parent->left == node)
					parent->left = node->right;
				else if (parent != NULL)
					parent->right = node->right;
				if (node->right != NULL)
					node->right->parent = parent;
				free(node);
				return (parent == NULL ? node->right : root);
			}
			if (node->right == NULL)
			{
				if (parent != NULL && parent->left == node)
					parent->left = node->left;
				else if (parent != NULL)
					parent->right = node->left;
				if (node->left != NULL)
					node->left->parent = parent;
				free(node);
				return (parent == NULL ? node->left : root);
			}
			successor = inorder_successor(node->right);
			node->n = successor->n;

			return (bst_remove_recursive(root, successor, successor->n));
		}
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove -  removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: return a pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
