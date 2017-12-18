#include "rb_trees.h"

/**
 * valid_bst - checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: min node
 * @max: max node
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int valid_bst(const rb_tree_t *tree, const rb_tree_t *min,
	      const rb_tree_t *max)
{
	if (!tree)
		return (1);
	if (min && tree->n < min->n)
		return (0);
	if (max && tree->n > max->n)
		return (0);
	return (valid_bst(tree->left, NULL, tree) &&
		valid_bst(tree->right, tree, NULL));
}

/**
 * valid_colors - checks if There are no two adjacent red nodes.
 * ie (A red node cannot have a red parent or red child).
 * Every node has a color either red or black.
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid, and 0 otherwise
 */
int valid_colors(const rb_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!((tree->color == RED) || (tree->color == BLACK)))
		return (0);
	if (tree->color == RED)
	{
		if (tree->left)
			if ((tree->left)->color == RED)
				return (0);
		if (tree->right)
			if ((tree->right)->color == RED)
				return (0);
	}
	return (valid_colors(tree->left) && valid_colors(tree->right));
}

/**
 * black_height - Fetches the black height of a rbbst
 * @tree: Pointer to the root node of the tree to check
 * Return: max number of black nodes between the root and leaf nodes
 */
size_t black_height(const rb_tree_t *tree)
{
	size_t max;

	if (!tree)
		return (0);
	max = MAX(black_height(tree->left), black_height(tree->right));
	if (tree->color == BLACK)
		return (max + 1);
	return (max);
}

/**
 * valid_path - check the black height is the same throughout
 * @tree: Pointer to the root node of the tree to check
 * @height: black height of the tree
 * @count: count of black nodes
 * Return: 1 if tree is a valid, and 0 otherwise
 */
int valid_path(const rb_tree_t *tree, size_t height, size_t count)
{
	if (!tree)
	{
		if (height == count)
			return (1);
		return (0);
	}
	if (tree->color == BLACK)
		++count;
	return (valid_path(tree->left, height, count) &&
		valid_path(tree->right, height, count));
}

/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 *
 * Properties of a Red-Black Tree:
 * 1) A Red-Black Tree is a BST
 * 2) Every node has a color either red or black.
 * 3) Root of tree is always black.
 * 4) There are no two adjacent red nodes
 * ie (A red node cannot have a red parent or red child).
 * 5) Every path from root to a NULL node has same number of black nodes.
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (0);
	if (!valid_bst(tree, NULL, NULL))
		return (0);
	if (tree->color != BLACK)
		return (0);
	if (!valid_colors(tree))
		return (0);
	h = black_height(tree);
	if (!valid_path(tree, h, 0))
		return (0);
	return (1);
}
