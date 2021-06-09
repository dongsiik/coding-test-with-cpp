//149쪽 <3> : 음료수 얼려먹기

#include <vector>
#include <iostream>
#include <string>
using namespace std;

int n, m;
vector<string> v;

bool DFS(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) return false;
	if (v[i][j] == '0') {
		v[i][j] = '2';
		DFS(i - 1, j);
		DFS(i + 1, j);
		DFS(i, j - 1);
		DFS(i, j + 1);
		return true;
	}
	return false;
}

int main() {
	int result = 0;
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		v.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (DFS(i, j)) {
				result++; cout << i << j;
			}
		}
	}
	cout << result << '\n';
}
