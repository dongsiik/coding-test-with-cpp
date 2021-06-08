//99쪽 실전 문제 4 : 1이 될 때까지

#include <iostream>
using namespace std;

int main() {
	int n, k;

	cin >> n >> k;
	int count = 0;

	while (true) {
		count += n % k;
		n -= n % k;

		if (n < k) break;
		n /= k;
		count++;
	}
	count += n - 1;

	cout << count;
}