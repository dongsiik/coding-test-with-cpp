//351쪽 Q20 : 감시 피하기

#include <iostream>
using namespace std;

char arr[6][6];
int n;
bool possible = false;

bool oversee(int x, int y) {
	for (int i = 0; i < x; i++) {
		if (arr[i][y] == 'S') {
			bool block = false;
			for (int j = i + 1; j < x; j++) {
				if (arr[j][y] == 'O') {
					block = true;
					break;
				}
			}
			if (block == false) return false;
		}
	}
	for (int i = x + 1; i < n; i++) {
		if (arr[i][y] == 'S') {
			bool block = false;
			for (int j = x+1; j <i; j++) {
				if (arr[j][y] == 'O') {
					block = true;
					break;
				}
			}
			if (block == false) return false;
		}
	}
	for (int i = 0; i < y; i++) {
		if (arr[x][i] == 'S') {
			bool block = false;
			for (int j = i + 1; j < y; j++) {
				if (arr[x][j] == 'O') {
					block = true;
					break;
				}
			}
			if (block == false) return false;
		}
	}
	for (int i = y + 1; i < n; i++) {
		if (arr[x][i] == 'S') {
			bool block = false;
			for (int j = y+1; j <i; j++) {
				if (arr[x][j] == 'O') {
					block = true;
					break;
				}
			}
			if (block == false) return false;
		}
	}
	return true;
}

void DFS(int cnt) {
	if (cnt == 3) {
		bool AllTcheck = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'T') AllTcheck = AllTcheck && oversee(i, j);
			}
		}
		if (AllTcheck) possible = true;
	}
	if (cnt < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'X') {
					arr[i][j] = 'O';
					cnt += 1;
					DFS(cnt);
					arr[i][j] = 'X';
					cnt -= 1;
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0);
	if (possible) cout << "YES";
	else cout << "NO";

}
