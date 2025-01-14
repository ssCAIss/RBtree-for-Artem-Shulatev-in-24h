#ifndef RBTREE_H
#define RBTREE_H

#include "List.h"

struct Group {
    char program;
    int ID;

    Group(char type, int id);
    bool operator>(const Group& g);
    bool operator==(const Group& g);
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
    int ProgramToInt(char program);
    void Insert(char program, int id, int number);
    void InsertBalance(RBNode*& node);
};

#endif