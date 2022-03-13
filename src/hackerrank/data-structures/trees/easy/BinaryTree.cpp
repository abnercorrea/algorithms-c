//
// Created by Abner Correa on 3/7/22.
//

#include <iostream>

#include "BinaryTree.h"
#include "commonutils.h"

using namespace std;

int main() {
    vector<int> data = {5, 3, 2, 4, 8, 7, 9, 1, 10};
    BinaryTree<int> tree(data);

    cout << "Tree height: " << tree.height() << "\n";

    cout << "PreOrder:" << join(tree.preOrder()) << "\n";
    cout << "InOrder:" << join(tree.inOrder()) << "\n";
    cout << "PostOrder:" << join(tree.postOrder()) << "\n";
    cout << "LevelOrder:" << join(tree.levelOrder()) << "\n";

    cout << "LowestCommonAncestor (1, 10): " << tree.lowestCommonAncestor(1, 10)->data << "\n";
    cout << "LowestCommonAncestor (2, 4): " << tree.lowestCommonAncestor(2, 4)->data << "\n";
    cout << "LowestCommonAncestor (7, 9): " << tree.lowestCommonAncestor(7, 9)->data << "\n";
}
