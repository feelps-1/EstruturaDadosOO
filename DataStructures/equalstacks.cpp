#include <bits/stdc++.h>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

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

    public:
        Stack() { this->top = nullptr; }

        bool isEmpty() { return top == nullptr; }

        void push(E data){
            ListNode<E>* node = new ListNode<E>(data);

            node->next = top;

            top = node;
        }

        void pop(){
            ListNode<E>* temp = top;

            top = top->next;

            delete temp;
        }

        E peek(){
            if(!isEmpty()){
                return top->value;
            }

            return INT_MIN;
        }
        

};


int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    Stack<int> height1, height2, height3;
    long total1 = 0, total2 = 0, total3 = 0;
    
    for(auto it = h1.rbegin(); it != h1.rend(); ++it){
        total1 += *it;
        height1.push(*it);
    }
    for(auto it = h2.rbegin(); it != h2.rend(); ++it){
        total2 += *it;
        height2.push(*it);
    }
    for(auto it = h3.rbegin(); it != h3.rend(); ++it){
        total3 += *it;
        height3.push(*it);
    }
    
    while(true){
        if(total1 == total2 && total2 == total3){
            return total1;
        }
        else if (total1 >= total2 && total1 >= total3){
            total1 -= height1.peek();
            height1.pop();
            
        }
        else if (total2 >= total1 && total2 >= total3){
            total2 -= height2.peek();
            height2.pop();
        }
        else{
            total3 -= height3.peek();
            height3.pop();
        }
    }
    
      
    
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

