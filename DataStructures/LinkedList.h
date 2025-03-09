#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include <iostream>

namespace DataStructures {
    template <typename E> class LinkedList: public List<E> {
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

            ListNode<E>* head;
            ListNode<E>* tail;
            ListNode<E>* curr;  
            int lenght;

            void init(){
                head = tail = curr = new ListNode<E>;
                lenght = 0;
            }

            void removeall() {
                while(head != nullptr){
                    curr = head;
                    head = head->next;
                    delete curr;
                }
            }

            public:
                LinkedList() { init(); } 
                ~LinkedList() { removeall(); } 
                
                void print() const {
                    ListNode<E>* temp = head;
                    while(temp->next != nullptr){
                        std::cout << temp->next->value;
                        temp = temp->next;
                    }
                }; 
                
                void clear() { removeall(); init(); } 
               
                
                void insert(const E& it) {
                    curr->next = new ListNode<E>(it, curr->next);
                    if (tail == curr) tail = curr->next; 
                    lenght++;
                }
                void append(const E& it) { 
                    tail = tail->next = new ListNode<E>(it, nullptr);
                    lenght++;
                }
             
                E remove() {
                    assert(curr->next != nullptr && "No element");
                    E it = curr->next->value; 
                    ListNode<E>* ltemp = curr->next; 
                    if (tail == curr->next) tail = curr; 
                    curr->next = curr->next->next; 
                    delete ltemp; 
                    lenght--; 
                    return it;
            }

            void moveToStart() // Place curr at list start
                { curr = head; }

            void moveToEnd() // Place curr at list end
                { curr = tail; }
            // Move curr one step left; no change if already at front
            void prev() {
                if (curr == head) return; // No previous element
                ListNode<E>* temp = head;
                // March down list until we find the previous element
                while (temp->next!=curr) temp=temp->next;
                curr = temp;
            }
            // Move curr one step right; no change if already at end
            void next()
                { if (curr != tail) curr = curr->next; }
            
            int length() const { return lenght; } // Return length
            // Return the position of the current element
            int currPos() const {
                ListNode<E>* temp = head;
                int i;
                for (i=0; curr != temp; i++)
                temp = temp->next;
                return i;
            }
            // Move down list to "pos" position
            void moveToPos(int pos) {
                assert ((pos>=0)&&(pos<=lenght) && "Position out of range");
                curr = head;
                for(int i=0; i<pos; i++) curr = curr->next;
            }
            const E& getValue() const { // Return current element
                assert(curr->next != nullptr && "No value");
                return curr->next->value;
            }
        };

    };     


#endif
