#include <iostream>


using namespace std;

template <typename E> class Queue{
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
    Queue() { front = rear = new ListNode<E>(); size = 0; }
    ~Queue() { clear(); delete front; } 
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
        E it = front->next->value;
        ListNode<E>* ltemp = front->next; 
        front->next = ltemp->next; 
        if (rear == ltemp) rear = front;
        delete ltemp; 
        size --;
        return it; 
    }
};

int main (){
    int tests;

    cin >> tests;

    int students;
    int actualstudent;
    int seconds{1};
    int maxtime;

    Queue<int> tea;

    for(int i = 0; i < tests; i++){
        seconds = 1;
        cin >> students;
        for(int j = 0; j < students; j++){
            cin >> actualstudent;
            tea.enqueue(actualstudent);
            cin >> maxtime;
            if(seconds < actualstudent){
                seconds = actualstudent;
            }

            if(seconds <= maxtime){
                cout << seconds << " ";
                seconds++;
            }else{
                cout << 0 << " ";
            }
            tea.dequeue();

        }
        cout << "\n";

    }

    return 0;
}
