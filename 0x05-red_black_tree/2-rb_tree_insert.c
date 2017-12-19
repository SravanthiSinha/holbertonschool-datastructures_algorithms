#include "rb_trees.h"

/**
 * bst_insert -  a function that inserts a value in a Binary Search Tree
 * @tree : a double pointer to the root node of the BST to insert the value in
 * @value: the value to store in the node to be inserted
 * @color : the color to paint the node to be inserted
 * Return:  a pointer to the created node, or NULL on failure
 */
rb_tree_t *bst_insert(rb_tree_t **tree, int value, rb_color_t color)
{
	rb_tree_t *node = NULL, *prev;
	int r = 0, l = 0;

	if (*tree == NULL)
	{
		*tree = rb_tree_node(NULL, value, color);
		return (*tree);
	}
	node = *tree;
	while (node)
	{
		prev = node;
		r = 0, l = 0;
		if (node->n < value)
		{
			node = node->right;
			r++;
		} else if (node->n > value)
		{
			node = node->left;
			l++;
		} else
			return (NULL);
	}
	node = rb_tree_node(prev, value, color);
	if (r > l)
		prev->right = node;
	else
		prev->left = node;

	return (node);
}

/* resource: http://cs.lmu.edu/~ray/notes/binarysearchtrees/ */
/**
 * binary_tree_rotate_left -  a function that performs a left-rotation
 * on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 **/
rb_tree_t *binary_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *node, *node2, *node3;

	if (!tree)
		return (NULL);
	if (tree->right)
	{
		node = tree;
		node2 = tree->right;
		if (node->parent && node->parent->n < node->n)
			node->parent->right = node2;
		if (node->parent && node->parent->n > node->n)
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
	return (tree);
}

/* resource: http://cs.lmu.edu/~ray/notes/binarysearchtrees/ */
/**
 * binary_tree_rotate_right -  a function that performs a right-rotation
 * on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 **/
rb_tree_t *binary_tree_rotate_right(rb_tree_t *tree)
{
	rb_tree_t *node, *node2, *node3;

	if (!tree)
		return (NULL);
	if (tree->left)
	{
		node = tree;
		node2 = tree->left;
		if (node->parent && node->parent->n < node->n)
			node->parent->right = node2;
		if (node->parent && node->parent->n > node->n)
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
 * insert_case4step2 - Repairs the Red-Black Tree
 *
 * @node: A  pointer to the newly added node of the Red-Black tree
 */
void insert_case4step2(rb_tree_t *node)
{
	rb_tree_t *parent = node->parent;
	rb_tree_t *grandparent = parent ? parent->parent : NULL;

	if (node == parent->left)
		binary_tree_rotate_right(grandparent);
	else
		binary_tree_rotate_left(grandparent);
	parent->color = BLACK;
	if (grandparent)
		grandparent->color = RED;
}

/**
 * repair_tree - Repairs the Red-Black Tree
 *
 * @node: A  pointer to the newly added node of the Red-Black tree
 */
void repair_tree(rb_tree_t *node)
{
	rb_tree_t *parent, *uncle, *grandparent;

	parent = node ? node->parent : NULL;
	if (parent)
	{
		grandparent = parent->parent;
		if (grandparent)
		{
			if (grandparent->left != parent)
				uncle = grandparent->left;
			else if (grandparent->right != parent)
				uncle = grandparent->right;
		}
	}
	if (parent == NULL)
		node->color = BLACK;
	else if (parent->color == BLACK)
		return;
	else if (uncle && uncle->color == RED)
	{
		parent->color = BLACK;
		uncle->color = BLACK;
		grandparent->color = RED;
		repair_tree(grandparent);
	} else
	{
		if (grandparent && grandparent->left
		    && node == grandparent->left->right)
		{
			binary_tree_rotate_left(parent);
			node = node->left;
		} else if (grandparent && grandparent->right
			   && node == grandparent->right->left)
		{
			binary_tree_rotate_right(parent);
			node = node->right;
		}
		insert_case4step2(node);
	}
}

/**
 * rb_tree_insert - Inserts a value in a Red-Black Tree
 *
 * @tree: A double pointer to the root node of the Red-Black tree to insert
 * the value in
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new = NULL, *root;

	/*Perform standard BST insertion, with color of newly inserted nodes as RED*/
	new = bst_insert(tree, value, RED);
	if (new == NULL)
		return (NULL);
	repair_tree(new);
	/* find the new root */
	root = new;
	while (root->parent != NULL)
		root = root->parent;
	*tree = root;
	return (new);
}
