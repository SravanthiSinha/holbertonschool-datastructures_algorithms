#include "binary_trees.h"

/**
 * bst_insert -  a function that inserts a value in a Binary Search Tree
 * @tree : a double pointer to the root node of the BST to insert the value in
 * @value: the value to store in the node to be inserted
 * Return:  a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL, *prev;
	int r = 0, l = 0;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	else
	{
		node = *tree;
		while (node)
		{
			prev = node;
			r = 0, l = 0;
			if (node->n < value)
			{
				node = node->right;
				r++;
			}
			else if (node->n > value)
			{
				node = node->left;
				l++;
			}
			else
				return (NULL);
		}
		node = binary_tree_node(prev, value);
		if (r > l)
			prev->right = node;
		else
			prev->left = node;
	}
	return (node);
}

/*
 * Implementation details:
 * 1) Perform the normal BST insertion.
 * 2) The current node must be one of the ancestors of the newly inserted node.
 * 3) Get the balance factor of the current node.
 * 4) If balance factor is greater than 1, then the current node is unbalanced
 * and we are either in Left Left case or left Right case. To check whether
 * it is left left case or not, compare the newly inserted key with
 * the key in left subtree root.
 * 5) If balance factor is less than -1, then the current node is unbalanced
 * and we are either in Right Right case or Right Left case. To check whether
 * it is Right Right case or not, compare the newly inserted key with the key
 * in right subtree root.
 */

/**
 * avl_insert-   a function that inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the BST to insert the value in
 * @value: the value to store in the node to be inserted
 * Return:  a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *parent, *new_node;
	int balance;

	new_node = bst_insert(tree, value);
	if (!new_node)
		return (NULL);
	parent = new_node->parent;/* already in tree */
	while (parent)
	{
		balance = binary_tree_balance(parent);
		/* Left Left Case */
		if (balance > 1 && parent->left && value < parent->left->n)
			parent = binary_tree_rotate_right(parent);
		/* Right Right Case */
		else if (balance < -1 && value > parent->right->n)
			parent = binary_tree_rotate_left(parent);
		/* Left Right Case*/
		else if (balance > 1 && value > parent->left->n)
		{
			parent->left =  binary_tree_rotate_left(parent->left);
			parent = binary_tree_rotate_right(parent);
		}
		/* Right Left Case */
		else if (balance < -1 && value < parent->right->n)
		{
			parent->right = binary_tree_rotate_right(parent->right);
			parent = binary_tree_rotate_left(parent);
		}
		parent = parent->parent;
	}
	return (new_node);
}
