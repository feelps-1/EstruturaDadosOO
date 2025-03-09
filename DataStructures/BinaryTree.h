#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

namespace DataStructures {
    template<typename T> class BST {
        private:
            template<typename E> class TreeNode {
                TreeNode *rightNode;
                TreeNode *leftNode;
                E value;

                public:
                    E getValue() { return value; }
                    TreeNode<T>* getLeft() { return leftNode; }
                    TreeNode<T>* getRight() { return rightNode; }

                    void setLeft(TreeNode<E>* l) { leftNode = l; }
                    void setRight(TreeNode<E>* r) { rightNode = r; }

                    TreeNode(E v, TreeNode<T>* left, TreeNode<T>* right) {value = v; 
                                                                    rightNode = right; 
                                                                    leftNode = left;}
            };
            int nodeCount;
            TreeNode<T>* root;
            TreeNode<T>* insertHelper(TreeNode<T>* root, const T& value){
                if(root == nullptr){
                    return new TreeNode<T> (value, nullptr, nullptr);
                }

                if(value < root->getValue()){
                    root->setLeft(insertHelper(root->getLeft(), value));
                }else{
                    root->setRight(insertHelper(root->getRight(), value));
                }
                return root; 
            };

            void printInOrder(TreeNode<T>* node){
                if(node != nullptr){
                    printInOrder(node->getLeft());
                    cout << node->getValue() << " ";
                    printInOrder(node->getRight());
                }
            }

            void printPreOrder(TreeNode<T>* node){
                if(node != nullptr){
                    cout << node->getValue() << " ";
                    printPreOrder(node->getLeft());
                    printPreOrder(node->getRight());
                }

            }

            void printPostOrder(TreeNode<T>* node){
                if(node != nullptr){
                    printPostOrder(node->getLeft());
                    printPostOrder(node->getRight());
                    cout << node->getValue() << " ";
                }
            }

        public:
            BST() {root = nullptr; nodeCount = 0; }
            ~BST() {}

            void insert(const T& value){
                root = insertHelper(root, value);
                nodeCount++;
            }

            void visitNode();

            void printInOrder(){
                cout << "In order  : ";
                printInOrder(root);
                cout << "\n";
            }

            void printPreOrder(){
                cout << "Pre order : ";
                printPreOrder(root);
                cout << "\n";

            }

            void printPostOrder(){
                cout << "Post order: ";
                printPostOrder(root);
                cout << "\n";
            }
    };


}

#endif
