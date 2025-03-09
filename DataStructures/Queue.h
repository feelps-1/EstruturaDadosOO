#ifndef QUEUE_H
#define QUEUE_H

namespace DataStructures {
    template <typename E> class LQueue: public Queue<E> {
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

        ListNode<E>* front; 
        ListNode<E>* rear;
        int size; 
        public:
        LQueue() 
        { front = rear = new ListNode<E>(); size = 0; }
        ~LQueue() { clear(); delete front; } 
        void clear() {
        while(front->next != nullptr) { 
        rear = front;
        delete rear;
        }
        rear = front;
        size = 0;
        }
        void enqueue(const E& it) {
        rear->next = new ListNode<E>(it, nullptr);
        rear = rear->next;
        size++;
        }
        E dequeue() { 
        E it = front->next->element;
        ListNode<E>* ltemp = front->next; 
        front->next = ltemp->next; 
        if (rear == ltemp) rear = front;
        delete ltemp; 
        size --;
        return it; 
        }
        const E& frontValue() const {
        return front->next->element;
        }
        virtual int length() const { return size; }
        };
}

#endif
