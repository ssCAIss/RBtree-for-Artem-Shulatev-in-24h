#include "RBTree.h"



// B = 66 M = 77 S = 83 A = 65

int main() {
    RBTree a;

    a.Insert('M', 1234, 1);
    a.Insert('B', 1234, 1);
    a.Insert('S', 1234, 1);
   a.Insert('A', 1234, 1);
    a.PrintTree(a.root, 0);
    std::cout << "\n";
 //   std::cout << a.find(Group('M', 1234), 1);
   a.deletenode(Group('A', 1234), 1);
    a.PrintTree(a.root, 0);
    std::cout << "\n";
    a.deletenode(Group('M', 1234), 1);
    a.PrintTree(a.root, 0);
    std::cout << "\n";
    a.Insert('M', 1235, 1);
    a.PrintTree(a.root, 0);
    std::cout << "\n";
    a.Insert('B', 1236, 1);
   a.Insert('S', 1237, 1);
    a.Insert('A', 1238, 1);
    a.PrintTree(a.root, 0);
    a.deletenode(Group('B', 1236), 1);
    a.deletenode(Group('S', 1237), 1);
    a.deletenode(Group('A', 1238), 1);
    a.deletenode(Group('M', 1235), 1);
    a.deletenode(Group('M', 1234), 1);
    a.deletenode(Group('M', 1234), 1);
    a.PrintTree(a.root, 0);

    return 0;
}