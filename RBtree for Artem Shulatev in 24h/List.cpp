#include "List.h"

Node::Node(int val) : data(val), next(nullptr){};


void LinkedList::color_print(int value) {
	std::string c = "\x1B[" + std::to_string(rand() % 100 / 10 + 31) + "m";
	std::cout << c << value << "\033[0m";
}

LinkedList::LinkedList() : head(NULL) {}

void LinkedList::add_node(int value) {
	Node* new_node = new Node(value); 
	if (!head) {
		head = new_node;
		head->next = nullptr;
	}
	else {
		new_node->next = head;
			head = new_node;
		}
	}

void LinkedList::del_previous(int value) {
	if (!head || !(head->next)) {
		return;
	}
	Node* cur = head;
	Node* prev = nullptr;

	do {
		if (cur->next->data == value) {
			if (cur == head) {
				head = cur->next;
				delete cur;
				cur = head;
			}
			else {
				cur = cur->next;
				delete prev->next;
				prev->next = cur;
			}
		}
		else {
			prev = cur;
			cur = cur->next;
		}

	} while (cur->next);
}

void LinkedList::del_node(int value) {
	if (!head) {
		return;
	}
	Node* cur = head;
	Node* prev = nullptr;

	do {
		if (cur->data == value) {
			if (cur == head) {
				head = cur->next;
				delete cur;
				cur = head;
			}
			else {
				cur = cur->next;
				delete prev->next;
				prev->next = cur;
			}
		}
		else {
			prev = cur;
			cur = cur->next;
		}

	} while (cur);
}

bool LinkedList::find(int value) {
	if (!head) {
		return false;
	}
	Node* cur = head;

	do {
		if (cur->data == value) {
			return true;
		}
	} while (cur->next);
	return false;
}

LinkedList LinkedList::unionn(LinkedList& list2) {
	LinkedList nnew;
	if (head) {
		Node* cur = head;
		while (cur) {
			nnew.add_node(cur->data);
			cur = cur->next;
		}
	}
	if (list2.head) {
		Node* cur = list2.head;
		while (cur) {
			nnew.add_node(cur->data);
			cur = cur->next;
		}
	}
	return nnew;
}

void LinkedList::pprint() {
	if (!head) {
		std::cout << "{}" << "\n";
		return;
	}
	Node* tmp = head;
	std::cout << "{";
	do {
		if (tmp->next) {
			color_print(tmp->data);
			std::cout << "\x1B[34m, \033[0m";
			tmp = tmp->next;
		}
		else {
			color_print(tmp->data);
			std::cout << "}";
			tmp = tmp->next;
		}
	} while (tmp);
	std::cout << "\n";
}

LinkedList::~LinkedList() {
	if (!head) return;

	Node* cur = head;
	Node* next_node;

	do {
		next_node = cur->next;
		delete cur;
		cur = next_node;
	} while (cur);
}

bool LinkedList::isEmpty() {
	if (!head)
		return true;
	return false;
}