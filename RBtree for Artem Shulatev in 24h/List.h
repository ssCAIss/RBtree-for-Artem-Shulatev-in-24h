#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

struct Node {
	int data;
	Node* next;
	Node(int value);
};



class LinkedList {
private:
	Node* head = nullptr;

	void color_print(int value);

public:

	void add_node(int value);
	void del_previous(int value);
	void del_node(int value);
	bool find(int value);
	LinkedList unionn(LinkedList& list2);
	void pprint();
	~LinkedList();
};

#endif