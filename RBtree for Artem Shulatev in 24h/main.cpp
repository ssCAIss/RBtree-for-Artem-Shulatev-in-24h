#include "RBTree.h"

int main() {
    RBTree a;

    a.Insert('M', 1234, 1);
    a.Insert('B', 1234, 1);
    a.Insert('S', 1234, 1);
   a.Insert('A', 1234, 1);
    a.PrintTree(a.root, 0);
 //   std::cout << a.find(Group('M', 1234), 1);
   a.deletenode(Group('A', 1234), 1);
    a.PrintTree(a.root, 0);
    return 0;
}