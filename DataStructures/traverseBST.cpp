#include "BinaryTree.h"
#include <iostream>

using namespace DataStructures;
using namespace std;

int main(){
    int n;

    BST<int> tree;

    int value;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> value;
        tree.insert(value);
    }

    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();

    return 0;
}
