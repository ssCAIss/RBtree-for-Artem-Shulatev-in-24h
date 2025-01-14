#include "RBtree.h"


Group::Group(char type, int id) : program(type), ID(id) {}

RBNode::RBNode(Group group): group(group), color(R), left(nullptr), right(nullptr), parent(nullptr), ListOfGroups() {}

