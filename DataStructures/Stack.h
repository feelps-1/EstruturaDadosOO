#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

using namespace DataStructures;

namespace DataStructures {
    template <typename E> class Stack{
        private:
            template <typename T> class ListNode {
                public:
                    T value;
                    ListNode *next;

                    ListNode(const T& v, ListNode* nextnode = nullptr){
                        value = v; next = nextnode;
                    }   

                    ListNode( ListNode* nextnode = nullptr) { next = nextnode; }
            };

            ListNode<E>* top;
            int height;

        public:
            Stack() { this->top = nullptr};

            bool isEmpty(){ return head == nullptr; }

            void push(E data){
                ListNode<E>* node = new ListNode(data);

                node->next = top;

                top = node;
                height++;
            }

            void pop(){
                ListNode* temp = top;

                top = top->next;
                height--;

                delete temp;
            }

            E peek(){
                if(!isEmpty){
                    return top->value;
                }

                return INT_MIN;
            }

            int getHeight(){return height;}

            void print() const {
            ListNode<E>* current = top;
            std::cout << "Elementos da pilha: ";
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << "\n";
        }
            

    };
}

#endif
