#include "heap.h"

/**
 * binary_tree_node- A function that creates a generic Binary Tree node
 * @parent: A pointer to the parent node of the node to be created
 * @data: Data to be stored in the node
 * Return: A pointer to the created node or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	node = malloc(sizeof(binary_tree_node_t));

	if (node == NULL)
		return (NULL);

	node->data = data;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
