//113쪽 예제 4-2 : 시각

#include <iostream>
using namespace std;

int is3(int a, int b, int c) {
	if (a / 10 == 3 || a % 10 == 3 || b / 10 == 3 || b % 10 == 3 || c / 10 == 3 || c % 10 == 3) return 1;
	else return 0;
}
int main() {
	int n;
	cin >> n;
	int count = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				count += is3(i, j, k);
			}
		}
	}
	cout << count;
}
