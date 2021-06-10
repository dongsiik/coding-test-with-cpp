//223쪽 <4> : 바닥 공사

#include <iostream>
using namespace std;

int main() {
	int floor[1001];
	floor[0] = 1;
	floor[1] = 1;
	floor[2] = 3;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		floor[i] = (floor[i - 1] + 2 * floor[i - 2]) % 796796;
	}
	cout << floor[n];
}
