#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Heap {
public:
    vector<T> v;
    bool minHeap;

    bool compare(T a, T b) {
        if(minHeap) {
            return a < b;
        } 
        return a > b;
    }

    Heap(int default_size = 10, bool type = true) {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    // insert data to the heap
    void insert(T data) {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent =  idx / 2;
        
        while(parent > 1 && compare(v[idx], v[parent])) {
            swap(v[parent], v[idx]);
            idx = parent;
            parent /= 2;
        }
    }

    // get min or max
    T top() {
        return v[1];
    }

    void heapify(int idx) {
        int left = 2 * idx;
        int right = left + 1;

        int last = v.size() - 1;

        int min_idx = idx;

        if(left <= last && compare(v[left], v[idx])) {
            min_idx = left;
        }

        if(right <= last && compare(v[right], v[min_idx])) {
            min_idx = right;
        }

        if(min_idx != idx) {
            swap(v[min_idx], v[idx]);
            heapify(min_idx);
        }
    }

    // pop
    void pop() {
        // swap data of root and last element
        int idx = v.size() - 1;
        swap(v[1], v[idx]);
        v.pop_back();

        heapify(1);    
    }

    // empty
    bool empty() {
        return v.size() == 1;
    }
};