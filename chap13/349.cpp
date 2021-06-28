//349쪽 Q19 : 연산자 끼워 넣기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	int An[11];
	int maxV = -1e9;
	int minV = 1e9;
	vector<int> ope;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> An[i];
	}
	for (int i = 1; i <= 4; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) ope.push_back(i);
	}

	do {
		int now = An[0];
		for (int i = 0; i < n - 1; i++) {
			switch (ope[i]) {
			case 1:
				now += An[i + 1];
				break;
			case 2:
				now -= An[i + 1];
				break;
			case 3:
				now *= An[i + 1];
				break;
			case 4:
				now /= An[i + 1];
				break;
			}
		}
		minV = min(minV, now);
		maxV = max(maxV, now);
	} while (next_permutation(ope.begin(),ope.end()));

	cout << maxV << endl;
	cout << minV << endl;
}
