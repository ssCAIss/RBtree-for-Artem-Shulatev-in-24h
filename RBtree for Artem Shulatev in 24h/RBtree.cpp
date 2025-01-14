#include "RBtree.h"


Group::Group(char type, int id) : program(type), ID(id) {}

RBNode::RBNode(Group group): group(group), color(R), left(nullptr), right(nullptr), parent(nullptr), ListOfGroups() {}

void RBTree::LeftRotate(RBNode*& node) {
	RBNode* y = node->right;
	node->right = y->left;

	if (y->left) 
		y->left->parent = node;

	y->parent = node->parent;

	if (!node->parent)
		root = y;
	else if (node == node->parent->left)
		node->parent->left = y;
	else
		node->parent->right = y;

	y->left = node;
	node->parent = y;
}

void RBTree::RightRotate(RBNode*& node) {
	RBNode* y = node->left;
	node->left = y->right;

	if (y->right)
		y->right->parent = node;

	y->parent = node->parent;

	if (!node->parent)
		root = y;
	else if (node == node->parent->right)
		node->parent->right = y;
	else
		node->parent->left = y;

	y->right = node;
	node->parent = y;
}
