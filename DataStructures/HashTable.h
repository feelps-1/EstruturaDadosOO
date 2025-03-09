#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

namespace DataStructures {
    class HashTable {
        private:
            const int defaultSize = 101;
            array<string, 101> table;
            int numOfKeys = 0;

            int hash(const string& key) const {
                int hKey{0};
                for (int i = 0; i < key.size(); i++) {
                    hKey += (int(key[i]) * (i + 1));
                }
                hKey *= 19;
                return hKey % 101;
            }

        public:
            HashTable() {
                table.fill("#");  
            }

            void insert(const string& key) {
                int keyIndex = hash(key);

                for (int j = 0; j < 20; j++) {
                    int index = (keyIndex + (j == 0 ? 0 : j * j + 23 * j)) % 101;
                    if (table[index] == key) {
                        return;
                    }
                }
        
                for (int j = 0; j < 20; j++) {
                    int index = (keyIndex + (j == 0 ? 0 : j * j + 23 * j)) % 101;
                    if (table[index] == "#" || table[index] == "*") {
                        table[index] = key;
                        numOfKeys++;
                        return;
                    }
                }
            }

            int find(const string& key) {
                int keyIndex = hash(key);
            
                int index = keyIndex;
                if (table[index] == key) return index;
                if (table[index] == "#") return -1;
            
                for (int j = 1; j < 20; j++) {
                    index = (keyIndex + j * j + 23 * j) % 101;
            
                    if (table[index] == key) return index;
                    if (table[index] == "#") return -1;
                }
                return -1;
            }

            void deleteFromTable(const string& key) {
                int indexToDel = find(key);
                if (indexToDel != -1) {
                    table[indexToDel] = "*";
                    numOfKeys--;  
                }
            }

            void printKeys() {
                cout << numOfKeys << "\n";
            
                vector<pair<int, string>> sortedKeys;
                
                for (int i = 0; i < table.size(); i++) {
                    if (table[i] != "#" && table[i] != "*") {
                        sortedKeys.push_back({i, table[i]});
                    }
                }
            
                sort(sortedKeys.begin(), sortedKeys.end());
            
                for (size_t i = 0; i < sortedKeys.size(); i++) {
                    cout << sortedKeys[i].first << ":" << sortedKeys[i].second;
                    if (i != sortedKeys.size() - 1) {
                        cout << "\n";
                    }
                }
            }
    };
}

#endif
