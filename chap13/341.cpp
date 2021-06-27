//341쪽 Q16 : 연구소

#include <iostream>
using namespace std;

int n, m;
int arr[8][8];
int tmp[8][8];
int answer = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void virus(int x, int y) {
	if (tmp[x][y] != 2) return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (tmp[nx][ny] == 0) {
				tmp[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

int getSize() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) result++;
		}
	}
	return result;
}

void DFS(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				virus(i, j);
			}
		}
		answer = max(answer, getSize());
		return;
	}
	if (cnt < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					cnt += 1;
					DFS(cnt);
					arr[i][j] = 0;
					cnt -= 1;
				}
			}
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0);
	cout << answer;
}
