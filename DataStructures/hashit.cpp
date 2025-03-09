#include "HashTable.h"
#include <iostream>

using namespace DataStructures;
using namespace std;

int main(){
    int testCases;

    cin >> testCases;

    int operations;

    string operation;
    string key;

    for(int i = 0; i < testCases; i++){
        cin >> operations;
        HashTable table;

        for(int j = 0; j < operations; j++){
            cin >> operation;

            if(operation.substr(0, 3) == "ADD"){
                table.insert(operation.substr(4));
            }

            
            if(operation.substr(0, 3) == "DEL"){
                table.deleteFromTable(operation.substr(4));
            }
        }

        table.printKeys();
        cout << "\n";
    }

    return 0;
}
