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

std::ostream& operator<<(std::ostream& os, RBNode* node);

class RBTree {
public:
    RBNode* root;

    RBTree();
    ~RBTree();
    void LeftRotate(RBNode*& root, RBNode*& node);
    void RightRotate(RBNode*& root, RBNode*& node);
    int ProgramToInt(char program);
    void Insert(char program, int id, int number);
    void InsertBalance(RBNode*& root, RBNode*& node);
    void PrintTree(RBNode*& node, int level);
    void TimeToDie(RBNode* node);
};

#endif