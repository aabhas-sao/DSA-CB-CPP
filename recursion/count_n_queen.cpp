#include <iostream>
using namespace std;

bool canPlaceQueen(int board[11][11], int row, int col, int n) {
    // along col
    for(int i = 0; i <= row; i++) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    // check left diagonal
    int x = row;
    int y = col;

    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    // check right diagonal
    x = row;
    y = col;
    while(x >=0 && y < n) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nqueen(int board[11][11], int row, int n, int& ans) {
    // base case
    if(row == n) {
        ans++;
        return false;
    }
    
    // rec
    for(int i = 0; i < n; i++) {
        if(canPlaceQueen(board, row, i, n)) {
            board[row][i] = 1;
            bool nexQueenRakhPaye = nqueen(board, row + 1, n, ans);
            if(nexQueenRakhPaye) {
                return true;
            }
            board[row][i] = 0; // backtrack
        } 
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    int board[11][11] = {0};
    int ans = 0;
    nqueen(board, 0, n, ans);
    cout<<ans<<endl;
    return 0;
}