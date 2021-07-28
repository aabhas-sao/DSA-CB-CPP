#include <iostream>
using namespace std;

template <typename T>
class Vector {
    T* a;
    int size;
    int capacity;
public:
    Vector() {
        capacity = 1;
        size = 0;
        a = new T[capacity];
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void changeSize(const int newSize) {
        int* oldArr = a;
        int* a = new T[newSize];
        for(int i = 0; i < size; i++) {
            a[i] = oldArr[i];
        }
        capacity = newSize;
        delete [] oldArr;
    }

    void push_back(const T x) {
        if (size == capacity) {
            int* oldArr = a;
            a = new int[2 * capacity];
            capacity *= 2;

            for (int i = 0; i < size; i++) {
                a[i] = oldArr[i];
            }

            delete[] oldArr;
        }
        a[size++] = x; 
    }

    void pop_back() {
        if(size <= capacity / 4) {
            
        }
        size--;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector<int> v;
    for(int i = 0; i < 12; i++) {
        v.push_back(i);
    }

    v.print();

    for(int i = 0; i < 12; i++) {
        v.pop_back();
    }
    return 0;
}