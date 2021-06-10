//226쪽 <5> : 효율적인 화폐 구성

#include <iostream>
using namespace std;

int main() {
	int coins[100];
	int cases[10001];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		coins[i] = x;
	}

	cases[0] = 0;
	for (int i = 1; i <= m; i++) {
		cases[i] = -1;
	}
	for (int i = 1; i <= m; i++) {
		int minValue = 10001;
		for (int j = 0; j < n; j++) {
			if (coins[j] <= i) {
				if (cases[i - coins[j]] != -1) {
					minValue = min(minValue, cases[i - coins[j]] + 1);
				}
			}
		}
		if (minValue == 10001) cases[i] = -1;
		else cases[i] = minValue;
	}
	cout << cases[m];
}
