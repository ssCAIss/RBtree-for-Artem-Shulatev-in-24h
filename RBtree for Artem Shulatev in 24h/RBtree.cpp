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

RBNode::RBNode(Group group): group(group), color(R), left(NULL), right(NULL), parent(NULL), ListOfGroups() {}

std::ostream& operator<<(std::ostream& os, RBNode* node) {
	if (!node)
		return os << "NULL" << "\n";
	if (node->color == B)
		return os << "\x1B[36m" << node->group.program << node->group.ID << "\033[0m" << "\n";
	else
		return os << "\x1B[91m" << node->group.program << node->group.ID << "\033[0m" << "\n";
}

RBTree::RBTree(){
	root = NULL;
	sentinel = new RBNode(Group(NULL, NULL));
	sentinel->color = B;
}

void RBTree::LeftRotate(RBNode*& root, RBNode*& node) {
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

void RBTree::RightRotate(RBNode*& root, RBNode*& node) {
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

	if (!root) {
		RBNode* node = new RBNode(newgroup);
		node->ListOfGroups.add_node(number);
		node->left = sentinel;
		node->right = sentinel;
		root = node;
		root->color = B;
		return;
	}

	RBNode* y = NULL;
	RBNode* x = root;


	while (x != sentinel) {
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
	node->ListOfGroups.add_node(number);
	node->left = sentinel;
	node->right = sentinel;
	if (!y)
		root = node;
	else if (newgroup > y->group)
		y->right = node;
	else
		y->left = node;
	InsertBalance(root, node);
}

void RBTree::InsertBalance(RBNode*& root, RBNode*& node) {
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
					LeftRotate(root, node);
				}
				node->parent->color = B;
				node->parent->parent->color = R;
				RightRotate(root, node->parent->parent);
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
					RightRotate(root, node);
				}
				node->parent->color = B;
				node->parent->parent->color = R;
				LeftRotate(root, node->parent->parent);
			}
		}

	root->color = B;
}

void RBTree::PrintTree(RBNode*& node, int level) {
	if (!node || node == sentinel)
		return;

	PrintTree(node->right, level + 1);

	for (int i = 0; i < level; ++i) 
		std::cout << "     ";

	std::cout << node;
	PrintTree(node->left, level + 1);
}

void RBTree::TimeToDie(RBNode* node) {
	if (node == NULL || node == sentinel)
		return;

	TimeToDie(node->left);
	TimeToDie(node->right);

	delete node;
}

RBTree::~RBTree() {
	std::cout << "FATALITY";
	TimeToDie(root);
}

RBNode* RBTree::tree_minimum(RBNode* node) {
	while (node->left)
		node = node->left;
	return node;
}

RBNode* RBTree::tree_successor(RBNode* node) {
	if (node->right)
		return tree_minimum(node->right);
	RBNode* y = node->parent;
	while (y && node == y->right) {
		node = y;
		y = y->parent;	
	}
	return y;
}

RBNode* RBTree::find(Group group, int value) {
	if (!root)
		return NULL;
	RBNode* root = this->root;
	while (root && !((group == root->group) && root->ListOfGroups.find(value)))
		if (group > root->group)
			root = root->right;
		else
			root = root->left;
	return root;
}
void RBTree::deletenode(Group group, int value) {
	RBNode* toDelete = find(group, value);
	if (!toDelete)
		return;
	toDelete->ListOfGroups.del_node(value);
	if (toDelete->ListOfGroups.isEmpty())
		deleting(toDelete);
	return;
}

void RBTree::deleting(RBNode*& toDelete) {
	RBNode* y;
	RBNode* x;
	if (toDelete->left == sentinel || toDelete->right == sentinel)
		y = toDelete;
	else
		y = tree_successor(toDelete);
	if (y->left != sentinel)
		x = y->left;
	else
		x = y->right;
	x->parent = y->parent;
	if (y->parent == sentinel)
		this->root = x;
	else if (y = y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (y != toDelete) {
		toDelete->group = y->group;
		toDelete->ListOfGroups = y->ListOfGroups;
	}
	//if (y->color == B)
	//	deletefix(root, x);
	delete y;
}