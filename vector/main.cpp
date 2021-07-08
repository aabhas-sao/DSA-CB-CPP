#include <iostream>
using namespace std;
#include "vector.h"

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.pop_back();
    v.display();
    cout<<v.container()<<endl;
    cout<<v.size();
    return 0;
}