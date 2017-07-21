#include "binary_trees.h"


/* resource: http://cs.lmu.edu/~ray/notes/binarysearchtrees/ */
/**
* Rotate -  a function that performs a left/right-rotation
* on a binary tree
* @tree: a pointer to the root node of the tree to rotate
* @dir :left or right , dir = 0 -> left, dir = 1->right
* Return: a pointer to the new root node of the tree once rotated
**/
binary_tree_t *Rotate(binary_tree_t *tree, int dir)
{
	binary_tree_t *node, *node2, *node3;

	if (!tree)
		return (NULL);
	if (tree->right && dir == 0)
	{
		node = tree;
		node2 = tree->right;
		if (node->parent->n < node->n)
			node->parent->right = node2;
		if (node->parent->n > node->n)
			node->parent->left = node2;
		node3 = tree->right->left;
		node2->parent = node->parent;
		node2->left = node;
		node->parent = node2;
		node->right = node3;
		if (node3)
			node3->parent = node;
		tree = node2;
	}
	if (tree->left && dir == 1)
	{
		node = tree;
		node2 = tree->left;
		if (node->parent->n < node->n)
			node->parent->right = node2;
		if (node->parent->n > node->n)
			node->parent->left = node2;
		node3 = tree->left->right;
		node2->parent = node->parent;
		node2->right = node;
		node->parent = node2;
		node->left = node3;
		if (node3)
			node3->parent = node;
		tree = node2;
	}
	return (tree);
}


/**
* getHeight - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height of
* Return: height or 0 if root or its children is NULL
**/
size_t getHeight(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = getHeight(tree->left);
	right = getHeight(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);

}


/**
 * getBalace -  a function  that measures the balance factor
 * of a binary tree
 * @node : a pointer to the node to check
 * Return: 1 if node is a root, and 0 otherwise
 */
int getBalace(const binary_tree_t *node)
{
	int left_height = 0, right_height = 0;

	if (node)
	{
		if (node->left)
		{
			left_height = getHeight(node->left) + 1;
		}
		if (node->right)
		{
			right_height = getHeight(node->right) + 1;
		}
	}
	return (left_height - right_height);
}


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
	avl_t *node, *new_node;
	int balance;

	new_node = bst_insert(tree, value);
	node = new_node;
	if (node->parent && node->parent->parent)
		node = node->parent->parent;
	if (node)
	{
		balance = binary_tree_balance(node);
		/* Left Left Case */
		if (balance > 1 && node->left && value < node->left->n)
		{
			return (Rotate(node, 1));
		}
		/* Right Right Case */
		else if (balance < -1 && value > node->right->n)
			return (Rotate(node, 0));
		/* Left Right Case*/
		else if (balance > 1 && value > node->left->n)
		{
			node->left =  Rotate(node->left, 0);
			return (Rotate(node, 1));
		}
		/* Right Left Case */
		else if (balance < -1 && value < node->right->n)
		{
			node->right = Rotate(node->right,  1);
			return (Rotate(node, -1));
		}
	}
	return (new_node);
}
