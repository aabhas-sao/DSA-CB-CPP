#include<iostream>
using namespace std;

void display(int a[1000][1000], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<a[i][j]<<" ";
        }
    }
}

void spiral_print(int a[1000][1000], int n, int m) {
    int startRow = 0;
    int startCol = 0;
    int endRow = n - 1;
    int endCol = m - 1;

    while(startRow < endRow && startCol < endCol) {
        // left col
        for(int i = startRow; i <= endRow; i++) {
            cout<<a[i][startCol]<<" ";
        }
        startCol++;
        // bottom
        for(int i = startCol; i <= endCol; i++) {
            cout<<a[endRow][i]<<" ";
        }
        endRow--;
        // right
        for(int i = endRow; i >= startRow; i--) {
            cout<<a[i][endCol]<<" ";
        }
        endCol--;
        // top
        for(int i = endCol; i >= startCol; i--) {
            cout<<a[startRow][i]<<" ";
        }
        startRow++;
    }

    if(m!=2 && n!=2) {
        if(startRow == endRow && startCol == endCol) {
            cout<<a[startRow][endCol];
        }
        else {
            if(startRow < endRow) {
                for(int i = startRow; i <= endRow; i++) {
                    cout<<a[i][startCol]<<" ";
                }
            }
            else if(startCol < endCol) {
                for(int i = startCol; i <= endCol; i++) {
                    cout<<a[startRow][i]<<" ";
                }
            }
        }
    }
    cout<<endl;
}

int main() {
    int n, m;
    cin>>n>>m;
    int a[1000][1000];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }  
    spiral_print(a, n, m);  
    // display(a, m, n);
}