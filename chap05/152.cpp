//152쪽 <4> : 미로 탈출

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<string> v;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int BFS(int a, int b) {
	queue<int> qx;
	queue<int> qy;
	qx.push(a);
	qy.push(b);

	while (!qx.empty()) {
		int x = qx.front();
		int y = qy.front();
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (v[nx][ny] == '0') continue;
			if (v[nx][ny] == '1') {
				v[nx][ny] = v[x][y] + 1;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
	return v[n - 1][m - 1] - '0';
}

int main() {
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		v.push_back(s);
	}
	cout << BFS(0, 0);
}
