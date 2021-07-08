#include <iostream>
#include <string>
#include "hashtable.h"
using namespace std;

int main() {
    HashTable<int> H(7);
    H.insert("apple", 12);
    H.insert("banana", 2);
    H.insert("minion", 3);
    H.insert("doge", 4);
    H.insert("doge", 4);


    H.erase("doge");
    H.erase("doge");
    H["momo"] = 10;
    H.print();

    int* res = H.search("apple");
    if(res == NULL) {
        cout << "Not Found";
    } else {
        cout << "price is "<<*res<<endl;
    }
    return 0;
}