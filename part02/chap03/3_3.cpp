//96�� ���� ���� 3 : ���� ī�� ����

#include <iostream>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;
	int x;
	int result = 0;

	for (int i = 0; i < n; i++) {
		int min = 987654321;
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (min > x) min = x;
		}
		if (result < min) result = min;
	}

	cout << result << endl;
}