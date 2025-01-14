#ifndef RBTREE_H
#define RBTREE_H

#include "List.h"

struct Group {
    char program;
    int ID;

    Group(char type, int id);
};

enum Color {R, B};

struct RBNode {
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    Group group;
    Color color;
    LinkedList ListOfGroups;

    RBNode(Group group);
};

class RBTree {
private:
    ~RBTree();
    RBTree();
};

#endif