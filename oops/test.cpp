#include <iostream>
using namespace std;

class Test {
private:
    int* a;
public:
    Test() {
        a = new int[5];
        for(int i = 0; i < 5; i++) {
            a[i] = i;
        }
    }

    void display() {
        for(int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << a << endl;
        delete a;
        cout << a << endl;
        for(int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }
    }
};

int main() {
    Test t;
    t.display();
}