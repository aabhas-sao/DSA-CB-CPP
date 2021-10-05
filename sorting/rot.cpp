#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> image(n, vector<int>(n, 0));
	for (int i =0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> image[j][i];
		}
	}
	reverse(image);

	for (int i =0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout >> image[i][j];
		}
	}
	return 0;
}