#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;
using namespace DataStructures;

int main(){
    string prompt;
    LinkedList<char> finalPrompt;

    while(cin >> prompt){
        for(auto i: prompt){
            if(i == '['){
                finalPrompt.moveToStart();
            }else if(i == ']'){
                finalPrompt.moveToEnd();
            }else{
                finalPrompt.insert(i);
                finalPrompt.next();
            }
        }

        finalPrompt.print();
        finalPrompt.clear();
        cout << "\n";
    }

    return 0;
}
