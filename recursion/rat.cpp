#include <iostream>
#include <string>
using namespace std;

bool ratInAMaze(char maze[1000][1000], bool soln[1000][1000], int i, int j, int m, int n) {
    // base case
    if(i == m && j == n) {
        soln[i][j] = 1;
        // todo display the soln
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    // rec
    if(i > m || j > n) {
        return false;
    }
    if(maze[i][j] == 'X') {
        return false;
    }

    soln[i][j] = 1;
    bool rightSuccess = ratInAMaze(maze, soln, i, j + 1, m, n);
    bool downSuccess = false;
    if(!rightSuccess) {
        downSuccess = ratInAMaze(maze, soln, i + 1, j, m, n);
    }

    // Backtracking
    soln[i][j] = 0;
    if(downSuccess || rightSuccess) {
        return true;
    }
    return false;
}

int main() {
    char maze[1000][1000];
	int rows, cols;
	cin>>rows>>cols;

    for(int i=0; i<rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin>>maze[i][j];
        }
    }

    bool soln[1000][1000] = {0};
    if(!ratInAMaze(maze, soln, 0, 0, rows - 1, cols - 1)) {
        cout<<"-1"<<endl;
    }
	return 0;
}