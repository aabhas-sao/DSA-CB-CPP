#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Student {
public:
	string name;
	int marks;
};

void bucket_sort(Student s[], int n, vector<vector<Student>>& v) {
	for (int i = 0; i < n; i++) {
		v[s[i].marks].push_back(s[i]);
	}
}

void display(vector<vector<Student>> v) {
	for (int i = 100; i >= 0; i--) {
		for (auto x: v[i]) {
			cout << x.name << " " << x.marks << endl;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Student s[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].marks;
	}
	vector<vector<Student>> v(101, vector<Student>());
	bucket_sort(s, n, v);
	display(v);
	return 0;
}

/* 
	input:
	7
	A 56
	B 34
	C 90
	D 34
	E 100
	F 0
	G 100

	
	correct output
	E 100
	G 100
	C 90
	A 56
	B 34
	D 34
	F 0


*/