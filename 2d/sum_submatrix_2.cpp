#include<iostream>
using namespace std;

void print_2d(int** a, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void build_prefix_array(int** a, int** b, int r, int c) {
    //sum row wise
    for(int i = 0; i < r; i++) {
        for(int j = 1; j < c; j++) {
            b[i][j] += b[i][j-1];
        }
    }

    //column wise
    for(int i = 0; i < r; i++) {
        for(int j = 1; j < c; j++) {
            b[j][i] += b[j-1][i];
        }
    }
}

int sum_sm(int** a, int**b, int r, int c) {
    int sum = 0;
    cout<<a[0][0]<<endl;
    build_prefix_array(a,b, r, c);
    for(int li = 0; li < r; li++) {
        for(int lj = 0; lj < c; lj++) {
            for(int bi = li; bi < r; bi++) {
                for(int bj = lj; bj < c; bj++) {
                    //if top row and first column
                    if(li == 0 && lj == 0) {
                        sum += b[bi][bj];
                    }
                    // if top row
                    else if(li == 0) {
                        sum += b[bi][bj] - b[bi][lj-1];
                    }
                    //if fisrt column
                    else if(lj == 0) {
                        sum += b[bi][bj] - b[bj][li-1];
                    }
                    else {
                        sum += b[bi][bj] - b[bi][lj-1] - b[li-1][bj] + b[li-1][lj-1];
                    }
                }
            }
        }
    }
    print_2d(b, r, c);
    print_2d(a, r, c);
    return sum;
}



int main() {
    int** a;
    int** b;

    int r,c;
    cin>>r>>c;
    a = new int*[r];
    b = new int*[r];
    for(int i = 0; i < r; i++) {
        a[i] = new int[c];
        b[i] = new int[c];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }

    cout<<sum_sm(a, b, r, c);
    return 0;
}