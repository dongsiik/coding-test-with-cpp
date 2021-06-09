//99ÂÊ ½ÇÀü ¹®Á¦ 4 : 1ÀÌ µÉ ¶§±îÁö

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
