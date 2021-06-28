//353쪽 Q21 : 인구 이동

#include <iostream>
#include <queue>

using namespace std;

int n, l, r;
int a[50][50];
int u[50][50];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void makeU(int x, int y, int idx) {
	vector<pair<int, int>> uni;
	queue<pair<int, int>> q;
	uni.push_back({ x,y });
	q.push({ x,y });
	u[x][y] = idx;
	int po = a[x][y];
	int num = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && u[nx][ny] == -1) {
				int gap = abs(a[cx][cy] - a[nx][ny]);
				if (gap >= l && gap <= r) {
					u[nx][ny] = idx;
					uni.push_back({ nx,ny });
					q.push({ nx,ny });
					po += a[nx][ny];
					num++;
				}
			}
		}
	}

	int new_po = po / num;
	for (int i = 0; i < uni.size(); i++) {
		int nx = uni[i].first;
		int ny = uni[i].second;
		a[nx][ny] = new_po;
	}
}
int main() {
	cin >> n >> l >> r;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				u[i][j] = -1;
			}
		}

		int idx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (u[i][j] == -1) {
					makeU(i, j, idx);
					idx++;
				}
			}
		}
		if (idx == n * n) break;
		cnt++;
	}

	cout << cnt;
}
