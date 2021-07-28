#include <iostream>
using namespace std;

class Complex {
    int r;
    int i;
public:
    Complex() {
        r = 0;
        i = 0;
    }

    Complex(const int real, const int img) {
        r = real;
        i = img;
    }
    
    int getReal() const {
        return r;
    }

    int getImg() const {
        return i;
    }

    void setReal (const int real) {
        r = real;
    }

    void setImg (const int img) {
        i = img;
    }

    void print() {
        if(i >= 0) {
            cout << r << " + " << i << "i" << endl;
        } else {
            cout << r << " - " << i << "i" << endl;
        }
    }

    void operator+(Complex &c) {
        r += c.r;
        i += c.i;
    }
};

istream& operator>>(istream& is, Complex &x) {
        int r1, i1;
        is >> r1 >> i1;
        x.setReal(r1);
        x.setImg(i1);
        return is;
}

ostream& operator<<(ostream& os, Complex& x) {
    x.print();
    return os;
}

int main() {
    Complex c1;
    Complex c2(6, 4);
    //c1.setReal(4);
    //c1.setImg(6);
    cin >> c1;
    c1 + c2;
    //c1.print();
    cout << c1 << c2;
    

}