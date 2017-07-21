#include "binary_trees.h"
/**
 * bst_search -  a function that searches for a value in a Binary Search Tree
 * @tree : a pointer to the root node of the BST to search
 * @value: the value to look for
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	if (tree)
	{
		node = (bst_t *)tree;
		while (node)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				return (node);
		}
	}
	return (node);
}
/**
 * minValueNode -  a function that removes a node from a Binary Search Tree
 * @node : a pointer to the root node of the tree to remove a node of
 * Return: a pointer to the left most node
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove -  a function that removes a node from a Binary Search Tree
 * @root : a pointer to the root node of the tree to remove a node of
 * @value: the value to look for
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min_node, *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (temp);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		min_node = minValueNode(root->right);
		root->n = min_node->n;
		root->right = bst_remove(root->right, min_node->n);
	}
	return (root);
}

/**
 * avl_remove -  a function that removes a node from a AVL  Tree
 * @root : a pointer to the root node of the tree to remove a node of
 * @value: the value to look for
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *new_node;
	int balance;

	node = bst_search(root, value);
	new_node = bst_remove(root, value);
	if (!new_node)
		return (NULL);
	node = node->parent;/* already in tree */
	while (node)
	{
		balance = binary_tree_balance(node);
		/* Left Left Case */
		if (balance > 1 && binary_tree_balance(node->left) >= 0)
		{
			node = binary_tree_rotate_right(node);
		}
		/* Right Right Case */
		else if (balance < -1 && binary_tree_balance(node->right) <= 0)
			node = binary_tree_rotate_left(node);
		/* Left Right Case*/
		else if (balance > 1 && binary_tree_balance(node->left) < 0)
		{
			node->left =  binary_tree_rotate_left(node->left);
			node = binary_tree_rotate_right(node);
		}
		/* Right Left Case */
		else if (balance < -1 && binary_tree_balance(node->right) > 0)
		{
			node->right = binary_tree_rotate_right(node->right);
			node = binary_tree_rotate_left(node);
		}
		node = node->parent;
	}
	return (new_node);
}
