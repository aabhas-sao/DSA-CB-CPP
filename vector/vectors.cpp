#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> v) {
    for(int x: v) {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> v{2, 1, 3, 4};
    cout<<v.capacity()<<endl;
    v.insert(v.begin() + 3, 4, 10);
    display(v);
    v.erase(v.begin() + 3, v.begin() + 7);
    cout<<v.capacity()<<endl;
    v.reserve(100);
    cout<<v.capacity()<<endl;
    display(v);
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    
    return 0; 
}