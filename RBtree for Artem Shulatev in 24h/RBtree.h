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
public:
    RBNode* root;

    ~RBTree();
    RBTree();
    void LeftRotate(RBNode*& node);
    void RightRotate(RBNode*& node);

};

#endif