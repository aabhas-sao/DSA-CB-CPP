#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x = 0;
	int y = 0;
	int z = 0;

	for(int i = 0; i < n; i++) {
		int x1;
		int y1;
		int z1;

		cin >> x1;
		cin >> y1;
		cin >> z1;

		x += x1;
		y += y1;
		z += z1;
	}

	if(x == 0 && y == 0 && z == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}