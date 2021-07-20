#include <iostream>
using namespace std;

bool ratAndCheese(char maze[10][10], int ans[10][10], int i, int j, int m, int n) {
    if(ans[i][j] == 1) {
        return false;
    }
    if(i > n - 1 || i < 0) {
        return false;
    }

    if(j > m - 1 || j < 0) {
        return false;
    }

    if(maze[i][j] == 'X') {
        return false;
    }

    if(i == n - 1 && j == m - 1) {
        ans[i][j] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        
        return true;
    }

    ans[i][j] = 1;

    bool r = ratAndCheese(maze, ans,  i, j + 1, m, n);
    bool d = ratAndCheese(maze, ans,  i + 1, j, m, n);
    bool t = ratAndCheese(maze, ans, i - 1, j, m , n);
    bool l = ratAndCheese(maze, ans, i, j - 1, m , n);
    
    if(r == false && d == false && t == false && l == false) {
        ans[i][j] = 0;
        return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    char maze[10][10];
    int ans[10][10];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>maze[i][j];
        }
    }

	bool found = ratAndCheese(maze, ans, 0, 0, m, n);
    if(!found) {
        cout << "NO PATH FOUND" << endl;
    }
    return 0;
}