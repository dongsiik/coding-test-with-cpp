//344쪽 Q17 : 경쟁적 전염

#include <queue>
#include <iostream>

using namespace std;

int main() {
	int arr[201][201];
	queue<pair<int, int>> virus[1001];
	int k, n, s, x, y;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int t = 0;

	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			arr[i][j] = 0;
		}
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a != 0) {
				arr[i][j] = a;
				virus[a].push({ i,j });
			}
		}
	}
	cin >> s >> x >> y;

	while (t < s) {
		t++;
		for (int i = 1; i <= k; i++) {
			int t_num = virus[i].size();
			if (t_num != 0) {
				for (int j = 0; j < t_num; j++) {
					int cx = virus[i].front().first;
					int cy = virus[i].front().second;
					virus[i].pop();
					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						if (nx > 0 && ny > 0 && nx <= n && ny <= n && arr[nx][ny] == 0) {
							arr[nx][ny] = arr[cx][cy];
							virus[i].push({ nx,ny });
						}
					}
				}
			}
		}
	}

	cout << arr[x][y];
}
