//327쪽 Q11 : 뱀

#include <queue>
#include <iostream>
using namespace std;

int main() {
	int board[101][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			board[i][j] = 0;
		}
	}
	int t = 0;
	int n, k, l;
	queue<pair<int, int>> snake;
	int headX = 1;
	int headY = 1;
	snake.push({ headX,headY });
	queue<pair<int, char>> rot;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int d = 0;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 2;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		rot.push({ x,c });
	}

	while (true) {
		t++;
		int nx = headX + dx[d];
		int ny = headY + dy[d];

		if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 1) {
			if (board[nx][ny] == 1) cout << "!" << endl;
			
			break;
		}
		cout << "t headXY" << t << " "<<nx <<" "<< ny << endl;
		if (board[nx][ny] == 0) {
			int tailX = snake.front().first;
			int tailY = snake.front().second;
			board[tailX][tailY] = 0;
			cout << "tailXY and result : " << tailX << " " << tailY << " " << board[tailX][tailY]<<endl;
			snake.pop();
		}

		headX = nx;
		headY = ny;
		board[headX][headY] = 1;
		snake.push({ headX,headY });

		if (!rot.empty()) {
			if (t == rot.front().first) {
				if (rot.front().second == 'L') {
					d = (d + 3) % 4;
				}
				else if (rot.front().second == 'D') {
					d = (d + 1) % 4;
				}
				rot.pop();
			}
		}
	}

	cout << t << endl;

}
