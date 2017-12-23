#include "rb_trees.h"

/*Resource used : http://bit.ly/2CSHmC0 */

/*void rb_tree_print(const rb_tree_t *tree);*/
void handleDoubleBlack(rb_tree_t **root, rb_tree_t *doubleBlackNode);

/**
 * SetChild -  a function that links the child and parent nodes
 * @parent: a pointer to the parent node
 * @Child: a pointer to the child node
 * @n:  on 1 set rightChild on 0 set leftChild
 **/
void SetChild(rb_tree_t *parent, rb_tree_t *Child, int n)
{
	if (Child != nullptr)
		Child->parent = parent;
	if (n)
		parent->right = Child;
	else
		parent->left = Child;
}

/**
 * transferSubtreePaternship -  a function that performs a  replacement of
 * node to be removed with last smallest or biggest node
 * @root: a double pointer to the root node of the tree
 * @oldRoot: node to be replaced
 * @newRoot: node to be replaced with
 **/
void transferSubtreePaternship(rb_tree_t **root, rb_tree_t *oldRoot,
			       rb_tree_t *newRoot)
{
	rb_tree_t *parent = oldRoot->parent;

	if (parent != nullptr)
	{
		if (oldRoot == parent->left)
			SetChild(parent, newRoot, 0);
		else
			SetChild(parent, newRoot, 1);
	} else
	{
		*root = newRoot;

		if (newRoot != nullptr)
			newRoot->parent = nullptr;
	}
}
/**
 * LeftRotate -  a function that performs a left-rotation
 * on a binary tree
 * @root: a pointer to the root node of the tree to rotate
 * @baseChanged: node ON WHICH left-rotation has to be performed
 **/
void LeftRotate(rb_tree_t **root, rb_tree_t *baseChanged)
{
	rb_tree_t *newBase = baseChanged->right;

	transferSubtreePaternship(root, baseChanged, newBase);

	SetChild(baseChanged, newBase->left, 1);
	SetChild(newBase, baseChanged, 0);
}

/**
 * RightRotate -  a function that performs a right-rotation
 * on a binary tree
 * @root: a pointer to the root node of the tree to rotate
 * @baseChanged: node ON WHICH right-rotation has to be performed
 **/
void RightRotate(rb_tree_t **root, rb_tree_t *baseChanged)
{
	rb_tree_t *newBase = baseChanged->left;

	transferSubtreePaternship(root, baseChanged, newBase);

	SetChild(baseChanged, newBase->right, 0);
	SetChild(newBase, baseChanged, 1);
}

/**
 * GetNodetoBeRemoved - Fetches the node to be removed after perfoorming BST
 * search
 * @nodeToRemove: A pointer to the node to be removed
 * Return: A pointer to the node to be replaced with
 */
rb_tree_t *GetNodetoBeRemoved(rb_tree_t *nodeToRemove)
{
	rb_tree_t *nextSmallest, *nextBiggest;

	if (nodeToRemove->left == nullptr)
	{
		/*Right child will be replacing nodeToRemove. */
		return (nodeToRemove);
	} else if (nodeToRemove->right == nullptr)
	{
		/*Left child will be replacing nodeToRemove. */
		return (nodeToRemove);
	}

	/*Remove the next smallest (or biggest node)and move its value into current */
	nextSmallest = nodeToRemove->left;
	while (nextSmallest->right != nullptr)
		nextSmallest = nextSmallest->right;

	if (IsRed(nextSmallest) || IsRed(nextSmallest->left))
	{
		return (nextSmallest);
	}

	nextBiggest = nodeToRemove->right;
	while (nextBiggest->left != nullptr)
		nextBiggest = nextBiggest->left;

	/*Hope nextBiggest or its right child is red. */
	return (nextBiggest);
}

/**
 * handleDoubleBlack - handles the double black node case
 *
 * @root: A double pointer to the root node of the tree
 * @doubleBlackNode: The double black node
 */
void handleDoubleBlack(rb_tree_t **root, rb_tree_t *doubleBlackNode)
{
	rb_tree_t *p, *sibling, *siblingLeftC, *siblingRightC, *newParent;
	int oneSiblingChildIsRed;

	if (doubleBlackNode->parent == nullptr)
		return;
	p = doubleBlackNode->parent;
	sibling = p ? (p->left == doubleBlackNode ? p->right : p->left) : NULL;
	siblingLeftC = sibling->left;
	siblingRightC = sibling->right;
	oneSiblingChildIsRed = IsRed(siblingLeftC) || IsRed(siblingRightC);
	if (IsRed(sibling))
	{
		(doubleBlackNode == p->left) ? LeftRotate(root, p) : RightRotate(root, p);
		sibling->color = BLACK;
		p->color = RED;
		handleDoubleBlack(root, doubleBlackNode);
	} else if (oneSiblingChildIsRed)
	{
		if (doubleBlackNode == p->left)
		{
			if (IsBlack(siblingRightC))
				RightRotate(root, sibling);
			LeftRotate(root, p);
		} else
		{
			if (IsBlack(siblingLeftC))
				LeftRotate(root, sibling);
			RightRotate(root, p);
		}
		newParent = p->parent;
		newParent->color = p->color;
		newParent->left->color = newParent->right->color = BLACK;
	} else
	{
		sibling->color = RED;
		if (IsBlack(doubleBlackNode->parent))
			handleDoubleBlack(root, doubleBlackNode->parent);
		else
			doubleBlackNode->parent->color = BLACK;
	}
}
/**
 * rb_tree_remove - Removes a node from a Red-Black tree
 *
 * @root: A pointer to the root node of the tree
 * @value: The value to search and remove from the tree
 * Return: The pointer to the new root of the tree after deletion
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int value)
{
	/*Find the node with the value that is being removed. */
	rb_tree_t *node, *nodeBeingRemoved, *nodeToBeReplaced;
	int nodeToBeReplacedWasNull = 0;

	node = root;
	while (node != nullptr && node->n != value)
	{
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}
	/*'n' didn't exist in the tree */
	if (node == nullptr)
		return (root);
	nodeBeingRemoved = GetNodetoBeRemoved(node);
	/*At most one will not be a nullptr */
	nodeToBeReplaced = nodeBeingRemoved->left == nullptr ? nodeBeingRemoved->right
	    : nodeBeingRemoved->left;
	nodeToBeReplacedWasNull = (nodeToBeReplaced == nullptr);
	/*if the node being removed has no children */
	if (nodeToBeReplacedWasNull)
		nodeToBeReplaced = rb_tree_node(nodeBeingRemoved, -1, BLACK);
	if (nodeBeingRemoved != node)
		node->n = nodeBeingRemoved->n;
	transferSubtreePaternship(&root, nodeBeingRemoved, nodeToBeReplaced);
	if (IsRed(nodeToBeReplaced) || IsRed(nodeBeingRemoved))
		nodeToBeReplaced->color = BLACK;
	else
		handleDoubleBlack(&root, nodeToBeReplaced);
	/*Clean up nodeToBeReplaced if it was null */
	if (nodeToBeReplacedWasNull)
	{
		transferSubtreePaternship(&root, nodeToBeReplaced, nullptr);
		free(nodeToBeReplaced);
	}
	free(nodeBeingRemoved);	/*free nodeBeingRemoved */
	return (root);
}
