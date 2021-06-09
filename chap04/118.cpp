//115쪽 <3> : 게임 개발

#include <iostream>
using namespace std;

int main() {

	int** ma;
	int x, y, d, N, M;
	cin >> N >> M >> x >> y >> d;
	ma = new int* [N];
	for (int i = 0; i < N; i++) {
		ma[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			ma[i][j] = input;
		}
	}

	ma[x][y] = 2;

	int result = 1;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int directionCnt = 0;
	while (true) {
		d = (d + 3) % 4;
		if (ma[x + dx[d]][y + dy[d]] == 0) {
			x += dx[d];
			y += dy[d];
			ma[x][y] = 2;
			directionCnt = 0;
			result++;
		}
		else {
			directionCnt++;
		}
		if (directionCnt == 4) {
			if (ma[x - dx[d]][y - dy[d]] == 1) break;
			else {
				x -= dx[d];
				y -= dy[d];
				directionCnt = 0;
			}
		}
	}
	cout << result;

	for (int i = 0; i < N; i++) {
		delete[] ma[i];
	}
	delete[] ma;
}
