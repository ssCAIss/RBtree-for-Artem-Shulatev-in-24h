#include "RBtree.h"


Group::Group(char type, int id) : program(type), ID(id) {}

bool Group::operator== (const Group& g) {
	if (program == g.program && ID == g.ID)
		return true;
	return false;
}

bool Group::operator>(const Group& g) {
	if (program > g.program || ID > g.ID)
		return true;
	return false;
}

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

int RBTree::ProgramToInt(char program) {
	if (program == 'B')
		return 1;
	if (program == 'S')
		return 2;
	if (program == 'M')
		return 3;
	if (program == 'A')
		return 4;
	return 0;
}

void RBTree::Insert(char program, int id, int number) {
	Group newgroup(program, id);

	RBNode* y = nullptr;
	RBNode* x = root;

	while (x) {
		y = x;
		if (newgroup == x->group) {
			x->ListOfGroups.add_node(number);
			return;
		}
		if (newgroup > x->group)
			x = x->right;
		else
			x = x->left;
	}

	RBNode* node = new RBNode(newgroup);
	node->parent = y;
	if (!y)
		root = node;
	else if (newgroup > y->group)
		y->right = node;
	else
		y->left = node;
	InsertBalance(node);
}

void RBTree::InsertBalance(RBNode*& node) {
	while (node != root && node->parent->color == R)
		if (node->parent == node->parent->parent->left) {
			RBNode* y = node->parent->parent->right;
			if (y->color == R) {
				node->parent->color = B;
				y->color = B;
				node->parent->parent->color = R;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->right) {
					node = node->parent;
					LeftRotate(node);
				}
				node->parent->color = B;
				node->parent->parent->color = R;
				RightRotate(node->parent->parent);
			}
		}
		else {
			RBNode* y = node->parent->parent->left;
			if (y->color == R) {
				node->parent->color = B;
				y->color = B;
				node->parent->parent->color = R;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->left) {
					node = node->parent;
					RightRotate(node);
				}
				node->parent->color = B;
				node->parent->parent->color = R;
				LeftRotate(node->parent->parent);
			}
		}

	root->color = B;
}
